namespace acLib
{
    using namespace util;

    acObjLoader::acObjLoader() : acModelLoader()
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
                vector<int> values;
                for (int face_i = 0; face_i < faceStr.size(); ++face_i)
                {
                    vector<string> elements;
                    StrUtil::Split( faceStr[face_i], '/', elements );

                    FaceInfo face;
                    for (int element_i = 0; element_i < elements.size(); ++element_i)
                    {
                        string& str = elements[element_i];
                        int value = atoi( str.c_str() ) - 1;
                        if (element_i == 0)
                        {
                            values.push_back( value );
                            face.vertex = value;
                        }
                        else if (element_i == 1)
                        {
                            face.texCoord = value;
                        }
                        else
                        {
                            face.normal = value;
                        }
                    }
                    m_faces.push_back( face );
                }

                int i = 1;
                while(1)
                {
                    m_indices.push_back( values[0] );

                    for (int j = i; j < i + 2; ++j)
                    {
                        m_indices.push_back(values[j]);
                    }

                    i++;

                    if (i >= n-1)
                        break;
                }

                m_vertexPerFaceCount = n;
            }
        }

        file.close();

        return true;
    }
}