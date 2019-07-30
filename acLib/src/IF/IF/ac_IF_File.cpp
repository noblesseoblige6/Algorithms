namespace acLib
{
    using namespace std;

    const string ac_IF_File::CLASS_IF_NAME = "fw_IF_File";
    const string ac_IF_File::CLASS_IF_VERSION = "0.0.1";

    vector<string> ac_IF_File::s_propertyOrder;

    ac_IF_File::ac_IF_File()
        : m_testBool(true)
        , m_testInt(0)
        , m_testFloat(0.0f)
        , m_testDouble(0.0)
        , m_testString("")
        , m_testEnum(AC_PROPERTY_TYPE_INT)
        , m_testArray()
        , m_pIFScene(nullptr)
    {
        InsertProperties({
            StandardIFProperty("Bool"  , AC_PROPERTY_TYPE_BOOL  , &m_testBool),
            StandardIFProperty("Int"   , AC_PROPERTY_TYPE_INT   , &m_testInt),
            StandardIFProperty("Float" , AC_PROPERTY_TYPE_FLOAT , &m_testFloat),
            StandardIFProperty("Double", AC_PROPERTY_TYPE_DOUBLE, &m_testDouble),
            StandardIFProperty("String", AC_PROPERTY_TYPE_STRING, &m_testString),

            EnumIFProperty("Enum", &m_testEnum, acEnumPropertyTypeValToStr, acEnumPropertyTypeStrToVal),

            SpecialIFProperty("Scene"    , AC_PROPERTY_TYPE_CLASS),

            SpecialIFProperty("Array"    , AC_PROPERTY_TYPE_ARRAY),
            SpecialIFProperty("SceneList", AC_PROPERTY_TYPE_ARRAY),
            });
    }

    ac_IF_File::~ac_IF_File()
    {}

    void ac_IF_File::ExportChildren(ac_IF_Serializer& serializer, const string& prop)
    {
        if (prop == "Scene")
        {
            if (m_pIFScene != nullptr)
                m_pIFScene->Export(serializer);
        }
    }

    int ac_IF_File::ExportArray(ac_IF_Serializer& serializer, const string& prop)
    {

        int count = 0;
#if 0
        if (prop == "Scenes")
        {
            count = (int)m_pIFScenes.size();
            for (auto itr : m_pIFScenes)
            {
                itr->Export(serializer);
            }
        }
        else if (prop == "Array")
        {
            count = (int)m_testArray.size();
            for (auto itr : m_testArray)
            {
                string val;
                ConvertNumberDataToStr<int>(FW_PROPERTY_TYPE_INT, itr, val);
                serializer.SetNumberArrayData(val);
            }
        }
#else
        if (prop == "SceneList")
        {
            function<void(ac_IF_Scene*)> func = [&](ac_IF_Scene* pScene)
            {
                pScene->Export(serializer);
            };

            ExportArrayData(func, m_pIFScenes, count);
        }
        else if (prop == "Array")
        {
            function<void(int)> func = [&](int val)
            {
                string res;
                acIFConvertNumberDataToStr<int>(AC_PROPERTY_TYPE_INT, val, res);
                serializer.SetNumberArrayData(res);
            };

            ExportArrayData(func, m_testArray, count);
        }
#endif
        return count;
    }

    void ac_IF_File::ImportChildren(ac_IF_Serializer& serializer)
    {
        if (m_pIFScene == nullptr)
            m_pIFScene = new ac_IF_Scene();
        m_pIFScene->Import(serializer);
    }

    void ac_IF_File::ImportArray(ac_IF_Serializer& serializer, const string& prop, const int count)
    {
#if 0
        if (prop == "Scenes")
        {
            m_pIFScenes.clear();
            m_pIFScenes.reserve(count);

            for (int i = 0; i < count; ++i)
            {
                fw_IF_Scene* pScene = new fw_IF_Scene();
                pScene->Import(serializer);

                m_pIFScenes.push_back(pScene);
            }
        }
        else if (prop == "Array")
        {
            m_testArray.clear();
            m_testArray.reserve(count);

            for (int i = 0; i < count; ++i)
            {
                string val;
                serializer.GetNumberArrayData(val);

                int tmp = ConvertStrToNumberData<int>(FW_PROPERTY_TYPE_INT, val);
                m_testArray.push_back(tmp);
            }
        }
#else
        if (prop == "SceneList")
        {
            function<ac_IF_Scene* ()> func = [&]()
            {
                ac_IF_Scene* pScene = new ac_IF_Scene();
                pScene->Import(serializer);

                return pScene;
            };

            ImportArrayData(func, m_pIFScenes, count);
        }
        else if (prop == "Array")
        {
            function<int()> func = [&]()
            {
                string val;
                serializer.GetNumberArrayData(val);

                int res = acIFConvertStrToNumberData<int>(AC_PROPERTY_TYPE_INT, val);

                return res;
            };

            ImportArrayData(func, m_testArray, count);
        }
#endif
    }
}