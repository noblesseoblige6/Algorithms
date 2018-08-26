#pragma once

namespace acLib
{
    class acModelLoader
    {
    public:
        acModelLoader();

        ~acModelLoader();

        virtual bool Load( const std::string& ) = 0;

        int GetVertexCount()const { return static_cast<int>(m_vertices.size()); }
        Vec3f& GetVertex( int index ) { return m_vertices[index]; }
        const Vec3f& GetVertex( int index ) const { return m_vertices[index]; }

        int GetFaceCount()const { return static_cast<int>(m_faces.size()); }
        int GetFace( int index ) { return m_faces[index]; }
        const int GetFace( int index ) const { return m_faces[index]; }

        int GetNormalCount()const { return static_cast<int>(m_normals.size()); }
        Vec3f& GetNormal( int index ) { return m_normals[index]; }
        const Vec3f& GetNormal( int index ) const { return m_normals[index]; }

        int GetTexCoordCount()const { return static_cast<int>(m_texCoords.size()); }
        Vec2f& GetTexCoord( int index ) { return m_texCoords[index]; }
        const Vec2f& GetTexCoord( int index ) const { return m_texCoords[index]; }

    protected:
        std::vector<Vec3f> m_vertices;
        std::vector<int>   m_faces;
        std::vector<Vec3f> m_normals;
        std::vector<Vec2f> m_texCoords;
        std::vector<TriangleF> m_polygons;
    };
}