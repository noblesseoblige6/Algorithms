#include "Util.h"

namespace acLib
{
    namespace util
    {
        template<typename T>
        static void Util::Swap(T& a, T& b)
        {
            T tmp = a;
            a = b;
            b = tmp;
        }

        template<typename T>
        static vector<T> Util::MergeSort(vector<T>& in)
        {
            //@comment To avoid refering to out of the index, 
            //the size of vector should be size-1
            return ParseAndMerge(in, 0, in.size() - 1);
        }

        template<typename T>
        static vector<T> Util::ParseAndMerge(vector<T>& in, int l, int r)
        {
            if (l >= r)
            {
                return vector<T>(1, in[r]);
            }

            int m = (l + r) / 2;

            //@comment Parse vector
            vector<T> lVec = parseAndMerge(in, l, m);
            vector<T> rVec = parseAndMerge(in, m + 1, r);

            //@comment Merge parsed vectors
            int size = lVec.size() + rVec.size();
            vector<T> res;
            for (int lCount = 0, rCount = 0; lCount + rCount < size;)
            {
                if (rCount >= rVec.size())
                {
                    res.push_back(lVec[lCount]);
                    lCount++;
                }
                else if (lCount >= lVec.size())
                {
                    res.push_back(rVec[rCount]);
                    rCount++;
                }
                else if (lVec[lCount] < rVec[rCount])
                {
                    res.push_back(lVec[lCount]);
                    lCount++;
                }
                else
                {
                    res.push_back(rVec[rCount]);
                    rCount++;
                }
            }
            return res;
        }

        template <typename T>
        void Util::Partition(vector<T> &arr, int& lAxis, int& rAxis)
        {
            const int m = (lAxis + rAxis) / 2;
            const T p = arr[m];

            while (1)
            {
                //@comment search the value less/more than the pivot
                while (arr[lAxis] < p) { ++lAxis; }
                while (arr[rAxis] > p) { --rAxis; }

                if (lAxis >= rAxis)
                {
                    break;
                }

                // swap
                if (arr[lAxis] >= p && arr[rAxis] <= p)
                {
                    Swap(arr[lAxis], arr[rAxis]);
                    ++lAxis;
                    --rAxis;
                }
            }
        }

        template <typename T>
        void Util::QuickSort(vector<T> &arr, const int l, const int r)
        {
            if (l >= r)
            {
                return;
            }

            int lIdx = l, rIdx = r;
            partition(arr, lIdx, rIdx);

            //@comment continue sorting if there is searching area
            if (l < lIdx - 1)
            {
                quickSort(arr, l, lIdx - 1);
            }
            if (rIdx + 1 < r)
            {
                quickSort(arr, rIdx + 1, r);
            }
        }
    }
}