#pragma once

namespace acLib
{
    using namespace std;

    class ac_IF_File : public ac_IF_Base
    {
    public:
        static const string CLASS_IF_NAME;
        static const string CLASS_IF_VERSION;

    private:
        static vector<string> s_propertyOrder;

    public:
        ac_IF_File();
        ~ac_IF_File();

    public:
        virtual const string& GetIFClassName() const { return CLASS_IF_NAME; }
        virtual const string& GetVersionInfo() const { return CLASS_IF_VERSION; }

    protected:
        virtual vector<string>& GetPropertyOrder() const { return s_propertyOrder; }

    protected:
        virtual void ExportChildren(ac_IF_Serializer& serializer, const string& prop);
        virtual int ExportArray(ac_IF_Serializer& serializer, const string& prop);

        virtual void ImportChildren(ac_IF_Serializer& serializer);
        virtual void ImportArray(ac_IF_Serializer& serializer, const string& prop, const int count);

    private:
        bool   m_testBool;
        int    m_testInt;
        float  m_testFloat;
        double m_testDouble;
        string m_testString;
        AC_PROPERTY_TYPE m_testEnum;
        vector<int> m_testArray;

    private:
        ac_IF_Scene* m_pIFScene;
        vector<ac_IF_Scene*> m_pIFScenes;
    };
} // namespace acLib
