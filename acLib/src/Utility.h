#pragma once
#include <limits>

namespace acLib
{
    namespace utility
    {
        class MathUtility
        {
        public:
            static double Lerp(const double x, const double x0, const double x1)
            {
                return (x - x0) / (x1 - x0);
            }
        };
    }
}