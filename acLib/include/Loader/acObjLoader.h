#pragma once

namespace acLib
{
    class acObjLoader : public acModelLoader
    {
        struct FaceInfo
        {
            int vertex;
            int texCoord;
            int normal;
        };

    public:
        acObjLoader();

        acObjLoader( const std::string& );

        ~acObjLoader();

        virtual bool Load( const std::string& ) override;

        int GetFaceCount()const { return static_cast<int>(m_faces.size()); }
        FaceInfo& GetFace( int index ) { return m_faces[index]; }
        const FaceInfo& GetFace( int index ) const { return m_faces[index]; }

    private:
        std::vector<FaceInfo>   m_faces;
        int                m_vertexPerFaceCount;
    };
}