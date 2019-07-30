namespace acLib
{
    using namespace std;

    const char* ac_IF_Serializer::VERSION = "1.0";
    const char* ac_IF_Serializer::ENCODING = "UTF-8";

    ac_IF_Serializer::ac_IF_Serializer()
        : m_pBuffer(nullptr)
    {
        Clear();
    }

    ac_IF_Serializer::~ac_IF_Serializer()
    {
        delete[] m_pBuffer;
    }

    void ac_IF_Serializer::Load(const string& filePath)
    {
        ifstream ifs(filePath);
        if (ifs.fail())
        {
            cerr << "File Open Error!" << endl;
            return;
        }

        istreambuf_iterator<char> it(ifs);
        istreambuf_iterator<char> last;
        string str(it, last);

        m_pBuffer = new char[str.size() + 1];
        char_traits<char>::copy(m_pBuffer, str.c_str(), str.size() + 1);

        m_document.parse<parse_default>(m_pBuffer);
    }

    void ac_IF_Serializer::Save(const string& filePath)
    {
        SetupXMLDeclaration();

        ofstream ofs(filePath);
        if (ofs.fail())
        {
            cerr << "File Open Error!" << endl;
            return;
        }

        ofs << m_document;
    }

    void  ac_IF_Serializer::Clear()
    {
        m_document.clear();
        m_nodeStack.clear();
    }

    bool ac_IF_Serializer::Serialize(ac_IF_Base* pNode)
    {
        const string& name = pNode->GetIFClassName();

        xml_node<>* pXMLNode = m_document.allocate_node(node_element, name.c_str());

        if (m_nodeStack.size() == 0)
        {
            m_document.append_node(pXMLNode);
        }
        else
        {
            xml_node<>* pParentXMLNode = m_nodeStack.back();
            pParentXMLNode->append_node(pXMLNode);
        }

        m_nodeStack.push_back(pXMLNode);

        // Version info
        char* versionInfo = m_document.allocate_string(pNode->GetVersionInfo().c_str());
        xml_attribute<>* pVersionAttr = m_document.allocate_attribute("Version", versionInfo);
        pXMLNode->append_attribute(pVersionAttr);

        // Serialize attributes
        for (int i = 0; i < pNode->GetAttributeCount(); ++i)
        {
            string attr, val;
            if (!pNode->GetAttribute(i, attr, val))
                continue;

            AddAttribute(pXMLNode, attr, val);
        }

        return true;
    }

    bool ac_IF_Serializer::DeserializeNode(const string& prop)
    {
        xml_node<>* pXMLNode = nullptr;
        if (m_nodeStack.size() == 0)
        {
            pXMLNode = m_document.first_node(prop.c_str());
        }
        else
        {
            xml_node<>* pParentXMLNode = m_nodeStack.back();
            pXMLNode = pParentXMLNode->first_node(prop.c_str());
        }

        if (pXMLNode == nullptr)
            return false;

        m_nodeStack.push_back(pXMLNode);

        return true;
    }

    bool ac_IF_Serializer::SerializeNode(const string& prop)
    {
        char* nodeName = m_document.allocate_string(prop.c_str());
        xml_node<>* pXMLNode = m_document.allocate_node(node_element, nodeName);
        if (m_nodeStack.size() == 0)
        {
            m_document.append_node(pXMLNode);
        }
        else
        {
            xml_node<>* pParentXMLNode = m_nodeStack.back();
            pParentXMLNode->append_node(pXMLNode);
        }

        if (pXMLNode == nullptr)
            return false;

        m_nodeStack.push_back(pXMLNode);

        return true;
    }

    bool ac_IF_Serializer::SerializeAttribute(const string& attr, const string& val)
    {
        xml_node<>* pXMLNode = nullptr;
        if (m_nodeStack.size() == 0)
        {
            pXMLNode = m_document.first_node();
        }
        else
        {
            pXMLNode = m_nodeStack.back();
        }

        if (pXMLNode == nullptr)
            return false;

        AddAttribute(pXMLNode, attr, val);

        return true;
    }

    bool ac_IF_Serializer::Deserialize(ac_IF_Base* pNode)
    {
        const string& name = pNode->GetIFClassName();

        xml_node<>* pXMLNode = nullptr;
        if (m_nodeStack.size() == 0)
        {
            pXMLNode = m_document.first_node(name.c_str());
        }
        else
        {
            xml_node<>* pParentXMLNode = m_nodeStack.back();
            pXMLNode = pParentXMLNode->first_node(name.c_str());
        }

        if (pXMLNode == nullptr || !CheckVeresion(pNode, pXMLNode))
            return false;

        m_nodeStack.push_back(pXMLNode);

        // Deserialize attributes
        for (xml_attribute<>* attr = pXMLNode->first_attribute(); attr; attr = attr->next_attribute())
        {
            pNode->SetAttribute(attr->name(), attr->value());
        }

        return true;
    }

    bool ac_IF_Serializer::DeserializeAttribute(const string& attr, string& val)
    {
        xml_node<>* pXMLNode = nullptr;
        if (m_nodeStack.size() == 0)
        {
            pXMLNode = m_document.first_node();
        }
        else
        {
            pXMLNode = m_nodeStack.back();
        }

        if (pXMLNode == nullptr)
            return false;

        xml_attribute<>* pAttr = pXMLNode->first_attribute(attr.c_str());
        if (pAttr == nullptr)
            return false;

        val = pAttr->value();

        return true;
    }

    void ac_IF_Serializer::SetNumberArrayData(const string& val)
    {
        xml_node<>* pXMLNode = nullptr;
        if (m_nodeStack.size() == 0)
        {
            pXMLNode = m_document.first_node();
        }
        else
        {
            pXMLNode = m_nodeStack.back();
        }

        if (pXMLNode == nullptr)
            return;

        char* nodeName = m_document.allocate_string("Element");
        xml_node<>* pXMLNewNode = m_document.allocate_node(node_element, nodeName);

        AddAttribute(pXMLNewNode, "Value", val);

        pXMLNode->append_node(pXMLNewNode);
    }

    void ac_IF_Serializer::GetNumberArrayData(string& val)
    {
        xml_node<>* pXMLNode = nullptr;
        if (m_nodeStack.size() == 0)
        {
            pXMLNode = m_document.first_node();
        }
        else
        {
            pXMLNode = m_nodeStack.back();
        }

        if (pXMLNode == nullptr)
            return;

        xml_node<>* pXMLCurNode = pXMLNode->first_node("Element");
        xml_attribute<>* pXMLAttribute = pXMLCurNode->first_attribute("Value");
        val = pXMLAttribute->value();

        pXMLNode->remove_node(pXMLCurNode);
    }

    void ac_IF_Serializer::DoneNodeProcess(bool isRemovedDoc)
    {
        xml_node<>* pNode = m_nodeStack.back();

        m_nodeStack.pop_back();

        if (!isRemovedDoc)
            return;

        // Remove node from document
        if (m_nodeStack.size() > 0)
            m_nodeStack.back()->remove_node( pNode );
        else
            Clear();
    }

    void ac_IF_Serializer::AddAttribute(xml_node<>* pXMLNode, const string& attr, const string& value)
    {
        // Allocate string on rapidXML
        char* attrName = m_document.allocate_string(attr.c_str());
        char* valueName = m_document.allocate_string(value.c_str());

        xml_attribute<>* pXMLAttr = m_document.allocate_attribute(attrName, valueName);
        pXMLNode->append_attribute(pXMLAttr);
    }

    void ac_IF_Serializer::SetupXMLDeclaration()
    {
        // xml declaration
        xml_node<>* decl = m_document.allocate_node(node_declaration);
        decl->append_attribute(m_document.allocate_attribute("version", VERSION));
        decl->append_attribute(m_document.allocate_attribute("encoding", ENCODING));
        m_document.prepend_node(decl);
    }

    bool ac_IF_Serializer::SetupVersion(ac_IF_Base* pNode, xml_node<>* pXMLNode)
    {
        AddAttribute(pXMLNode, "Version", pNode->GetVersionInfo());

        return true;
    }

    bool ac_IF_Serializer::CheckVeresion(ac_IF_Base* pNode, xml_node<>* pXMLNode)
    {
        xml_attribute<>* pVersionAttr = pXMLNode->first_attribute("Version");
        if (pVersionAttr != nullptr)
        {
            if (!pNode->ValidateVersion(pVersionAttr->value()))
                return false;
        }

        return true;
    }

    int ac_IF_Serializer::CalcDocumentSize() const
    {
        return GetNodeSize((void*)&m_document);
    }

    int ac_IF_Serializer::GetNodeSize(void* pNode) const
    {
        size_t size = 0;

        xml_node<>* pXMLNode = static_cast<xml_node<>*>(pNode);
        if (pXMLNode == nullptr)
            return 0;

        // Calc self size
        size += pXMLNode->name_size() + pXMLNode->value_size();
        for (xml_attribute<>* attr = pXMLNode->first_attribute(); attr; attr = attr->next_attribute())
        {
           size += attr->name_size() + attr->value_size();
        }

        // Calc children size
        for (xml_node<>* node = pXMLNode->first_node(); node; node = node->next_sibling())
        {
            size += GetNodeSize(node);
        }

        return (int)size;
    }
}
