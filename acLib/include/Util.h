#pragma once
#include <vector>

namespace acLib
{
    namespace util
    {
        using namespace std;

        class MathUtil
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

        class Util
        {
        public:
            template<typename T>
            static void Swap(T& a, T& b);

            template<typename T>
            static vector<T> MergeSort(vector<T>& in);

            template <typename T>
            void QuickSort(vector<T> &arr, const int l, const int r);

        private:
            template<typename T>
            static vector<T> ParseAndMerge(vector<T>& in, int l, int r);

            template <typename T>
            void Partition(vector<T> &arr, int& lAxis, int& rAxis);
        };
    }
}