
namespace acLib
{
    using namespace util;

    acModelLoader::acModelLoader()
    {
        m_vertices.clear();
        m_indices.clear();
        m_texCoords.clear();
        m_normals.clear();
        m_polygons.clear();
    }

    acModelLoader::acModelLoader( const LoadOption& option )
        : acModelLoader()
    {
        m_option = option;
    }

    acModelLoader::~acModelLoader()
    {}
}