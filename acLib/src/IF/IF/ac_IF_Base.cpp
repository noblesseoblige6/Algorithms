namespace acLib
{
    ac_IF_Base::ac_IF_Base()
        : m_hasSpecialProps(false)
    {
        m_propertyMap.clear();
    }

    ac_IF_Base::~ac_IF_Base()
    {
        m_propertyMap.clear();
    }

    bool ac_IF_Base::Export(ac_IF_Serializer& serializer)
    {
        if (!ExportSelf(serializer))
            return false;

        ExportSelfChildren(serializer);

        serializer.DoneNodeProcess(false);

        return true;
    }

    bool ac_IF_Base::ExportSelf(ac_IF_Serializer& serializer)
    {
        return serializer.Serialize(this);
    }

    bool ac_IF_Base::ExportSelfChildren(ac_IF_Serializer& serializer)
    {
        if (HasSpecialProps())
            serializer.SerializeNode("Children");

        for (const auto& key : GetPropertyOrder())
        {
            const acIFProperty& prop = m_propertyMap[key];

            if (prop.type == AC_PROPERTY_TYPE_CLASS)
            {
                ExportChildren(serializer, key);
            }
            else if (prop.type == AC_PROPERTY_TYPE_ARRAY)
            {
                serializer.SerializeNode(key);

                int count = ExportArray(serializer, key);

                string countStr;
                acIFConvertNumberDataToStr<int>(AC_PROPERTY_TYPE_INT, count, countStr);
                serializer.SerializeAttribute("Count", countStr);

                serializer.DoneNodeProcess(false);
            }
        }

        if (HasSpecialProps())
            serializer.DoneNodeProcess(false);

        return true;
    }

    void ac_IF_Base::ExportChildren(ac_IF_Serializer& serializer, const string& prop)
    {
        // do nothing
        AC_USE_VAR(serializer);
        AC_USE_VAR(prop);
    }

    int ac_IF_Base::ExportArray(ac_IF_Serializer& serializer, const string& prop)
    {
        // do nothing
        AC_USE_VAR(serializer);
        AC_USE_VAR(prop);

        return 0;
    }

    bool ac_IF_Base::Import(ac_IF_Serializer& serializer)
    {
        if (!ImportSelf(serializer))
            return false;

        ImportSelfChildren(serializer);

        serializer.DoneNodeProcess(true);

        return true;
    }

    bool ac_IF_Base::ImportSelf(ac_IF_Serializer& serializer)
    {
        return serializer.Deserialize(this);
    }

    bool ac_IF_Base::ImportSelfChildren(ac_IF_Serializer& serializer)
    {
        bool hasChildren = serializer.DeserializeNode("Children");

        for (const auto& key : GetPropertyOrder())
        {
            const acIFProperty& prop = m_propertyMap[key];
            if (prop.type == AC_PROPERTY_TYPE_CLASS)
            {
                ImportChildren(serializer);
            }
            else if (prop.type == AC_PROPERTY_TYPE_ARRAY)
            {
                if (!serializer.DeserializeNode(key))
                    continue;

                string countStr;
                if (!serializer.DeserializeAttribute("Count", countStr))
                    continue;

                int count = acIFConvertStrToNumberData<int>(AC_PROPERTY_TYPE_INT, countStr);
                ImportArray(serializer, key, count);

                serializer.DoneNodeProcess(true);
            }
        }

        if (hasChildren)
            serializer.DoneNodeProcess(false);

        return true;
    }

    void ac_IF_Base::ImportChildren(ac_IF_Serializer& serializer)
    {
        // do nothing
        AC_USE_VAR(serializer);
    }

    void ac_IF_Base::ImportArray(ac_IF_Serializer& serializer, const string& prop, const int count)
    {
        // do nothing
        AC_USE_VAR(serializer);
        AC_USE_VAR(prop);
        AC_USE_VAR(count);
    }

    void ac_IF_Base::InsertProperties(const vector<acIFProperty>& properties)
    {
        vector<string>& propertyOrder = GetPropertyOrder();

        bool shouldOrdered = (propertyOrder.size() == 0);
        for (auto itr : properties)
        {
            if (shouldOrdered)
                propertyOrder.push_back(itr.attr);

            m_propertyMap[itr.attr] = itr;

            if (itr.type == AC_PROPERTY_TYPE_ARRAY ||
                itr.type == AC_PROPERTY_TYPE_CLASS)
            {
                m_hasSpecialProps = true;
            }
        }
    }

    bool ac_IF_Base::SetAttribute(const string& attr, const string& val)
    {
        auto itr = m_propertyMap.find(attr);
        if (itr == m_propertyMap.end())
            return false;

        istringstream iss;

        const acIFProperty& prop = itr->second;
        switch (prop.type)
        {
        case AC_PROPERTY_TYPE_BOOL:
            *(bool*)(prop.pValue) = acIFConvertStrToNumberData<bool>(AC_PROPERTY_TYPE_BOOL, val);
            break;
        case AC_PROPERTY_TYPE_INT:
            *(int*)(prop.pValue) = acIFConvertStrToNumberData<int>(AC_PROPERTY_TYPE_INT, val);
            break;
        case AC_PROPERTY_TYPE_FLOAT:
            *(float*)(prop.pValue) = acIFConvertStrToNumberData<float>(AC_PROPERTY_TYPE_FLOAT, val);
            break;
        case AC_PROPERTY_TYPE_DOUBLE:
            *(double*)(prop.pValue) = acIFConvertStrToNumberData<double>(AC_PROPERTY_TYPE_DOUBLE, val);
            break;
        case AC_PROPERTY_TYPE_STRING:
            *(string*)(prop.pValue) = val;
            break;
        case AC_PROPERTY_TYPE_ENUM:
            if (prop.funcEnumStrToVal != nullptr)
                * (int*)(prop.pValue) = prop.funcEnumStrToVal(val.c_str());
            break;
        case AC_PROPERTY_TYPE_UNKNOWN:
        case AC_PROPERTY_TYPE_ARRAY:
        case AC_PROPERTY_TYPE_CLASS:
        default:
            return false;
        }

        return true;
    }

    bool  ac_IF_Base::GetAttribute(int offset, string& attr, string& val)
    {
        const vector<string>& propertyOrder = GetPropertyOrder();

        if (offset >= propertyOrder.size())
            return false;

        const string& key = propertyOrder[offset];

        auto itr = m_propertyMap.find(key);
        if (itr == m_propertyMap.end())
            return false;

        const acIFProperty& prop = m_propertyMap[key];

        string res;
        switch (prop.type)
        {
        case AC_PROPERTY_TYPE_BOOL:
            acIFConvertNumberDataToStr<bool>(AC_PROPERTY_TYPE_BOOL, *(bool*)(prop.pValue), res);
            break;
        case AC_PROPERTY_TYPE_INT:
            acIFConvertNumberDataToStr<int>(AC_PROPERTY_TYPE_INT, *(int*)(prop.pValue), res);
            break;
        case AC_PROPERTY_TYPE_FLOAT:
            acIFConvertNumberDataToStr<float>(AC_PROPERTY_TYPE_INT, *(float*)(prop.pValue), res);
            break;
        case AC_PROPERTY_TYPE_DOUBLE:
            acIFConvertNumberDataToStr<double>(AC_PROPERTY_TYPE_DOUBLE, *(double*)(prop.pValue), res);
            break;
        case AC_PROPERTY_TYPE_STRING:
            res = *(string*)(prop.pValue);
            break;
        case AC_PROPERTY_TYPE_ENUM:
            if (prop.funcEnumValToStr != nullptr)
                res = prop.funcEnumValToStr(*(int*)(prop.pValue));
            break;
        case AC_PROPERTY_TYPE_UNKNOWN:
        case AC_PROPERTY_TYPE_ARRAY:
        case AC_PROPERTY_TYPE_CLASS:
        default:
            return false;
        }

        attr = key;
        val = res;

        return true;
    }
}