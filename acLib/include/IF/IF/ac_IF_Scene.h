#pragma once

namespace acLib
{
    using namespace std;
    class ac_IF_Scene : public ac_IF_Base
    {
    public:
        static const string CLASS_IF_NAME;
        static const string CLASS_IF_VERSION;

    private:
        static vector<string> s_propertyOrder;

    public:
        ac_IF_Scene();
        ~ac_IF_Scene();

    public:
        virtual const string& GetIFClassName() const { return CLASS_IF_NAME; }
        virtual const string& GetVersionInfo() const { return CLASS_IF_VERSION; }

    protected:
        virtual vector<string>& GetPropertyOrder() const { return s_propertyOrder; }

    private:
        string m_name;
    };
} // namespace acLib
