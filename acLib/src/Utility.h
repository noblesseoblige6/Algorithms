#pragma once

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

            static double Max(const double& a, const double& b)
            {
                return a < b ? b : a;
            }

            static double Min(const double& a, const double& b)
            {
                return a < b ? a : b;
            }

            static double Clamp(const double& val, const double& min, const double& max)
            {
                return Min(Max(min, val), max);
            }
        };
    }
}