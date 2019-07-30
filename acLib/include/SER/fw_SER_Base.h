#ifndef __FW_SER_BASE_H__
#define __FW_SER_BASE_H__

namespace fw
{
    //using namespace std;

    template<class T>
    class fw_SER_Base
    {
    public:
        fw_SER_Base() {}
        ~fw_SER_Base() {}

    //public:
    //    virtual T* Serialize( fw_IF_Base* pIFData );
    //    virtual void SerializeSelf();

    //protected:
    //    void InsertProperties(const vector<fw_IF_Base::Property>& properties);
    //    virtual void CreatePropertyMap() {}

    private:
        //fw_IF_Base* m_pIFData;
        T*          m_pRTData;
        //map<string, fw_IF_Base::Property> m_propertyMap;
    };

    //template<typename T>
    //fw_SER_Base<T>::fw_SER_Base()
    //{
    //}

    //template<typename T>
    //fw_SER_Base<T>::~fw_SER_Base()
    //{
    //}

    //template<typename T>
    //T fw_SER_Base<T>::Serialize<>( fw_IF_Base* pIFData )
    //{
    //    T* m_pData = new T*();
    //    m_pIFData = pIFData;

    //    CreatePropertyMap();
    //    SerializeSelf();

    //    return move( pData );
    //}

    //template<typename T>
    //void fw_SER_Base<T>::SerializeSelf()
    //{
    //    for (auto itr : m_propertyMap)
    //    {
    //        const string& key = itr.first;

    //        const fw_IF_Base::Property& IFProp = m_pIFData->m_propertyMap[key];
    //        switch (IFProp.type)
    //        {
    //        case FW_PROPERTY_TYPE_INT:
    //            *(int*)(m_propertyMap[key].pValue) = *(int*)(IFProp.pValue);
    //            break;
    //        case FW_PROPERTY_TYPE_ARRAY:
    //            SerializeArray( key );
    //            break;
    //        case FW_PROPERTY_TYPE_CLASS:
    //            SerializeChildren( key );
    //            break;
    //        default:
    //            break;
    //        }
    //    }
    //}

    //template<typename T>
    //void fw_SER_Base<T>::InsertProperties( const vector<fw_IF_Base::Property>& properties )
    //{
    //    for (auto itr : properties)
    //    {
    //        m_propertyMap[itr.attr] = itr;
    //    }
    //}
} // namespace fw
#endif // __FW_SER_BASE_H__
