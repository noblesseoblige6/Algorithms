#pragma once
#include <limits>

namespace acLib
{
    namespace constant
    {
        static double kEps = 1e-6;
        static double kPI = 3.14159265358979323846;
        static const double k2PI = kPI * 2.0;
        static const double kHalfPI = kPI * 0.5;
        static const double kMaxFloat = 3.402823466e+38F; // FLT_MAX
        static const double kMinFloat = 1.175494351e-38F; // FLT_MIN
        static const double kInf = std::numeric_limits<double>::infinity();
        static const int kEnvMap = 0;
        #define DEG2RAD(a)   ((a) / (180 / kPI))
        #define RAD2DEG(a)   ((a) * (180 / kPI))
    }
}