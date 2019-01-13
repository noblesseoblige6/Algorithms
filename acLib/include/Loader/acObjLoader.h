#pragma once

namespace acLib
{
    using namespace std;

    class acObjLoader : public acModelLoader
    {
        struct FaceInfo
        {
            vector<int> vertex;
            vector<int> texCoord;
            vector<int> normal;
            Vec3f       faceNormal;
        };

    public:
        acObjLoader();
        acObjLoader( const LoadOption& option );
        acObjLoader( const std::string& );

        ~acObjLoader();

        virtual bool Load( const std::string& ) override;

        int GetFaceCount()const { return static_cast<int>(m_faces.size()); }
        FaceInfo& GetFace( int index ) { return m_faces[index]; }
        const FaceInfo& GetFace( int index ) const { return m_faces[index]; }

    protected:
        void CreateNormal();

    private:
        vector<FaceInfo>       m_faces;
        map<int, vector<int> > m_vertexFaceMap;
        int                    m_vertexPerFaceCount;
    };
}