#pragma once

namespace acLib
{
    using namespace std;

    class ac_IF_Base
    {
    public:
        friend class fw_SER_Base;

    private:
        static vector<string> s_propertyOrder;

    public:
        ac_IF_Base();
        ~ac_IF_Base();

    public:
        bool Export(ac_IF_Serializer& serializer);
        bool Import(ac_IF_Serializer& serializer);

        virtual const string& GetIFClassName() const = 0;
        virtual const string& GetVersionInfo() const = 0;

    protected:
        virtual vector<string>& GetPropertyOrder() const = 0;

    public:
        bool SetAttribute(const string& attr, const string& val);
        bool GetAttribute(int index, string& attr, string& val);

        template <typename T>
        void ExportArrayData(function<void(T)> func, vector<T>& vec, int& count);

        template <typename T>
        void ImportArrayData(function<T()> func, vector<T>& vec, int count);

        int GetAttributeCount() const { return (int)m_propertyMap.size(); }

        virtual bool ValidateVersion(const string& version) { (void)(version); return true; }

    protected:
        bool ExportSelf(ac_IF_Serializer& serializer);
        bool ExportSelfChildren(ac_IF_Serializer& serializer);

        virtual void ExportChildren(ac_IF_Serializer& serializer, const string& prop);
        virtual int ExportArray(ac_IF_Serializer& serializer, const string& prop);

        bool ImportSelf(ac_IF_Serializer& serializer);
        bool ImportSelfChildren(ac_IF_Serializer& serializer);

        virtual void ImportChildren(ac_IF_Serializer& serializer);
        virtual void ImportArray(ac_IF_Serializer& serializer, const string& prop, const int count);

        void InsertProperties(const vector<acIFProperty>& properties);

        bool HasSpecialProps() const { return m_hasSpecialProps; };

    protected:
        map<string, acIFProperty> m_propertyMap;
        bool m_hasSpecialProps;
    };

    template <typename T>
    void ac_IF_Base::ExportArrayData(function<void(T)> func, vector<T>& vec, int& count)
    {
        count = (int)vec.size();
        for (auto itr : vec)
        {
            func(itr);
        }
    }

    template <typename T>
    void ac_IF_Base::ImportArrayData(function<T()> func, vector<T>& vec, int count)
    {
        vec.clear();
        vec.reserve(count);
        for (int i = 0; i < count; ++i)
        {
            T res = func();
            vec.push_back(res);
        }
    }
} // namespace acLib
