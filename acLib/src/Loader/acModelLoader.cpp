﻿
namespace acLib
{
    using namespace util;

    acModelLoader::acModelLoader()
    {
        m_vertices.clear();
        m_faces.clear();
        m_texCoords.clear();
        m_normals.clear();
        m_polygons.clear();
    }

    acModelLoader::~acModelLoader()
    {}
}