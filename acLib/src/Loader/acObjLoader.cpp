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

                vector<string> values;
                StrUtil::Split(line, ' ', values);
                for (string str : values)
                {
                   m_faces.push_back( atoi( str.c_str() )-1 );
                }
            }
        }

        file.close();

        return true;
    }
}