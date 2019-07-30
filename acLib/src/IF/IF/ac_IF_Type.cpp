namespace acLib
{
    using namespace std;

    string acEnumPropertyTypeValToStr(int val)
    {
        switch (val)
        {
        case AC_PROPERTY_TYPE_INT:
            return "Int";
        case AC_PROPERTY_TYPE_FLOAT:
            return "Float";
        case AC_PROPERTY_TYPE_DOUBLE:
            return "Double";
        case AC_PROPERTY_TYPE_STRING:
            return "String";
        case AC_PROPERTY_TYPE_ENUM:
            return "Enum";
        }

        return "Unknown";
    }

    int acEnumPropertyTypeStrToVal(const string& str)
    {
        if (str == "Int")
        {
            return AC_PROPERTY_TYPE_INT;
        }
        else if (str == "Float")
        {
            return AC_PROPERTY_TYPE_FLOAT;
        }
        else if (str == "Double")
        {
            return AC_PROPERTY_TYPE_DOUBLE;
        }
        else if (str == "Double")
        {
            return AC_PROPERTY_TYPE_STRING;
        }
        else if (str == "Double")
        {
            return AC_PROPERTY_TYPE_ENUM;
        }

        return AC_PROPERTY_TYPE_UNKNOWN;
    }
}
