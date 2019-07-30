#pragma once

namespace acLib
{
    using namespace rapidxml;
    using namespace std;

    class ac_IF_Base;

    class ac_IF_Serializer
    {
    public:
        static const char* VERSION;
        static const char* ENCODING;

    public:
        ac_IF_Serializer();
        ~ac_IF_Serializer();

    public:
        void Load(const string& filePath);
        void Save(const string& filePath);

        void Clear();

        bool Serialize(ac_IF_Base* pNode);
        bool Deserialize(ac_IF_Base* pNode);

        bool SerializeNode(const string& prop);
        bool DeserializeNode(const string& prop);

        bool SerializeAttribute(const string& attr, const string& val);
        bool DeserializeAttribute(const string& attr, string& val);

        void SetNumberArrayData(const string& val);
        void GetNumberArrayData(string& val);

        void DoneNodeProcess(bool isRemovedDoc);

        int CalcDocumentSize() const;

    protected:
        void AddAttribute(xml_node<>* pXMLNode, const string& attr, const string& value);

        void SetupXMLDeclaration();
        bool SetupVersion(ac_IF_Base* pNode, xml_node<>* pXMLNode);
        bool CheckVeresion(ac_IF_Base* pNode, xml_node<>* pXMLNode);

        int GetNodeSize(void* pNode) const;

    protected:
        char* m_pBuffer;

        xml_document<> m_document;
        vector<xml_node<>*> m_nodeStack;
    };
} // namespace acLib
