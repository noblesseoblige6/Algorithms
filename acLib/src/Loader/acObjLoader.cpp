namespace acLib
{
    using namespace util;

    acObjLoader::acObjLoader() : acModelLoader()
    {
    }

    acObjLoader::acObjLoader( const LoadOption& option ) : acModelLoader( option )
    {
    }

    acObjLoader::acObjLoader( const std::string& path )
    {
        if (!Load( path ))
        {
            Log::Output( Log::LOG_LEVEL_ERROR, "Fail to load file!" );
        }
    }

    acObjLoader::~acObjLoader()
    {
        m_faces.clear();
    }

    bool acObjLoader::Load( const std::string& filename )
    {
        std::ifstream file;
        file.open( filename.c_str(), std::ios::in );
        if (!file.is_open())
        {
            Log::Output( Log::LOG_LEVEL_ERROR, "Fail to open file" );
            return false;
        }
        std::string buf;

        while (1) 
        {
            file >> buf;

            if (!file)
                break;

            if (buf == "#")
            {
                string line;
                getline( file, line );
                continue;
            }

            if (buf == "v")
            {
                float x, y, z;
                file >> x >> y >> z;
                m_vertices.push_back( Vec3f( x, y, z ) );
                m_vertexFaceMap.insert( make_pair( m_vertices.size() - 1, vector<int>() ) );
            }
            else if (buf == "vt")
            {
                float x, y;
                file >> x >> y;
                m_texCoords.push_back( Vec2f( x, y ) );
            }
            else if (buf == "vn")
            {
                float x, y, z;
                file >> x >> y >> z;
                m_normals.push_back( Vec3f( x, y, z ) );
            }
            else if (buf == "f")
            {
                string line;
                getline( file, line );
                if (!file) 
                {
                    Log::Output( Log::LOG_LEVEL_ERROR, "Fail to read line from file" );
                }

                vector<string> faceStr;
                StrUtil::Split(line, ' ', faceStr );

                int n = static_cast<int>(faceStr.size());

                FaceInfo face;
                for (int face_i = 0; face_i < faceStr.size(); ++face_i)
                {
                    vector<string> elements;
                    StrUtil::Split( faceStr[face_i], '/', elements );

                    for (int element_i = 0; element_i < elements.size(); ++element_i)
                    {
                        string& str = elements[element_i];
                        int value = atoi( str.c_str() ) - 1;
                        if (element_i == 0)
                        {
                            m_indices.push_back( value );
                            face.vertex.push_back( value );

                            m_vertexFaceMap[value].push_back( m_faces.size() );
                        }
                        else if (element_i == 1)
                        {
                            face.texCoord.push_back( value );
                        }
                        else
                        {
                            face.normal.push_back( value );
                        }
                    }
                }

                m_faces.push_back( face );
            }
        }

        if(m_option.bCreateNormal)
            CreateNormal();

        file.close();

        return true;
    }

    void acObjLoader::CreateNormal()
    {
        m_normals.clear();
        m_normals.resize( m_vertices.size() );

        for (FaceInfo& face : m_faces)
        {
            vector<Vec3f> vertices;
            for (int v_i : face.vertex)
            {
                vertices.push_back( m_vertices[v_i] );
            }

            Vec3f a = vertices[1] - vertices[0];
            Vec3f b = vertices[2] - vertices[1];

            Vec3f normal = Vec3f::cross( a, b );
            normal.normalized();

            face.faceNormal = normal;

            if (m_option.normalType == NORMAL_TYPE_FACE)
            {
                for (int index : face.vertex)
                    m_normals[index] = face.faceNormal;
            }
        }

        if (m_option.normalType == NORMAL_TYPE_FACE)
            return;

        for (int v_i = 0; v_i < m_vertices.size(); ++v_i)
        {
            Vec3f& normal = m_normals[v_i];
            normal = Vec3f::ZERO;

            for (int face_i : m_vertexFaceMap[v_i])
            {
                normal += m_faces[face_i].faceNormal;
            }

            normal /= static_cast<float>(m_vertexFaceMap[v_i].size());
        }
    }
}