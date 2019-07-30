#pragma once

namespace acLib
{
    using namespace std;

    enum AC_PROPERTY_TYPE
    {
        AC_PROPERTY_TYPE_UNKNOWN = 0,
        AC_PROPERTY_TYPE_BOOL,
        AC_PROPERTY_TYPE_INT,
        AC_PROPERTY_TYPE_FLOAT,
        AC_PROPERTY_TYPE_DOUBLE,
        AC_PROPERTY_TYPE_STRING,
        AC_PROPERTY_TYPE_ENUM,
        AC_PROPERTY_TYPE_ARRAY,
        AC_PROPERTY_TYPE_CLASS,
        //AC_PROPERTY_TYPE_VEC2,
        //AC_PROPERTY_TYPE_VEC3,
        //AC_PROPERTY_TYPE_VEC4,
        //AC_PROPERTY_TYPE_MAT3,
        //AC_PROPERTY_TYPE_MAT4,
    };

    std::string acEnumPropertyTypeValToStr(int val);
    int acEnumPropertyTypeStrToVal(const string& str);

    struct acIFProperty
    {
        acIFProperty()
            : attr( "" )
            , type( AC_PROPERTY_TYPE_UNKNOWN )
            , pValue( nullptr )
            , funcEnumValToStr( nullptr )
            , funcEnumStrToVal( nullptr )
        {
        }

        // NOTE:
        // You should set property name, property type, and object pointer.
        // to serialize/deserialize nurmeric data
        acIFProperty( const string& _prop, AC_PROPERTY_TYPE _type, void* _pValue )
            : attr( _prop )
            , type( _type )
            , pValue( _pValue )
            , funcEnumValToStr( nullptr )
            , funcEnumStrToVal( nullptr )
        {
        }

        // NOTE:
        // You should denfine fucntions to convert enumerator,
        // then set them to function objects.
        acIFProperty( const string& _prop, void* _pValue, function< string( int ) > funcValToStr, function< int( const string& ) > funcStrToVal )
            : attr( _prop )
            , type( AC_PROPERTY_TYPE_ENUM )
            , pValue( _pValue )
        {
            funcEnumValToStr = funcValToStr;
            funcEnumStrToVal = funcStrToVal;
        }

        // NOTE:
        // You should override function "ImportArray" and "ExportArray"
        // to serialize/deserialize array data.
        acIFProperty( const string& _prop, AC_PROPERTY_TYPE _type )
            : attr( _prop )
            , type( _type )
            , pValue( nullptr )
            , funcEnumValToStr( nullptr )
            , funcEnumStrToVal( nullptr )
        {
        }

        acIFProperty& operator=( const acIFProperty& src )
        {
            type = src.type;
            pValue = src.pValue;
            attr = src.attr;

            if (type == AC_PROPERTY_TYPE_ENUM)
            {
                funcEnumValToStr = src.funcEnumValToStr;
                funcEnumStrToVal = src.funcEnumStrToVal;
            }

            return *this;
        }

        string           attr;

        AC_PROPERTY_TYPE type;
        void* pValue; // インスタンスのメンバ変数の参照を渡す

        function< string( int ) >        funcEnumValToStr;
        function< int( const string& ) > funcEnumStrToVal;
    };

    typedef acIFProperty StandardIFProperty;
    typedef acIFProperty SpecialIFProperty;
    typedef acIFProperty EnumIFProperty;
}
