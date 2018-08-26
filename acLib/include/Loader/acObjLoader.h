#pragma once

namespace acLib
{
    class acObjLoader : public acModelLoader
    {
    public:
        acObjLoader();

        acObjLoader( const std::string& );

        ~acObjLoader();

        virtual bool Load( const std::string& ) override;
    };
}