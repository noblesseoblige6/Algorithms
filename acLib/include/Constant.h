#pragma once

namespace acLib
{
    namespace constant
    {
        static const double kEps = 1e-6;

        static const double kPI = 3.14159265358979323846;
        static const double k2PI = kPI * 2.0;
        static const double kHPI = kPI * 0.5;
        static const double kQPI = kPI * 0.25;
        
        static const double kMaxFloat = FLT_MAX;
        static const double kMinFloat = FLT_MIN;

        static const double kInf = std::numeric_limits<double>::infinity();
        
        static const int kEnvMap = 0;
        
        #define DEG2RAD(a)   ((a) / (180 / kPI))
        #define RAD2DEG(a)   ((a) * (180 / kPI))
    }
}