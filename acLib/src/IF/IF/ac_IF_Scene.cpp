namespace acLib
{
    const string ac_IF_Scene::CLASS_IF_NAME = "fw_IF_Scene";
    const string ac_IF_Scene::CLASS_IF_VERSION = "0.0.1";

    vector<string> ac_IF_Scene::s_propertyOrder;

    ac_IF_Scene::ac_IF_Scene()
    {
        InsertProperties({ acIFProperty("Name", AC_PROPERTY_TYPE_STRING, &m_name) });
    }

    ac_IF_Scene::~ac_IF_Scene()
    {}
}