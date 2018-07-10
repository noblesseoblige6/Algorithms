#pragma once

namespace acLib
{
    namespace util
    {
        using namespace std;

        class MathUtil
        {
        public:
            template<typename T>
            static T Lerp(const T x, const T x0, const T x1)
            {
                return (x - x0) / (x1 - x0);
            }
            
            template<typename T>
            static T Max(const T& a, const T& b)
            {
                return a < b ? b : a;
            }

            template<typename T>
            static T Min(const T& a, const T& b)
            {
                return a < b ? a : b;
            }

            template<typename T>
            static T Clamp(const T& val, const T& min, const T& max)
            {
                return Min(Max(min, val), max);
            }
        };

        class Util
        {
        protected:
            template<typename T>
            static vector<T> ParseAndMerge( vector<T>& in, int l, int r )
            {
                if (l >= r)
                {
                    return vector<T>( 1, in[r] );
                }

                int m = (l + r) / 2;

                //@comment Parse vector
                vector<T> lVec = parseAndMerge( in, l, m );
                vector<T> rVec = parseAndMerge( in, m + 1, r );

                //@comment Merge parsed vectors
                int size = lVec.size() + rVec.size();
                vector<T> res;
                for (int lCount = 0, rCount = 0; lCount + rCount < size;)
                {
                    if (rCount >= rVec.size())
                    {
                        res.push_back( lVec[lCount] );
                        lCount++;
                    }
                    else if (lCount >= lVec.size())
                    {
                        res.push_back( rVec[rCount] );
                        rCount++;
                    }
                    else if (lVec[lCount] < rVec[rCount])
                    {
                        res.push_back( lVec[lCount] );
                        lCount++;
                    }
                    else
                    {
                        res.push_back( rVec[rCount] );
                        rCount++;
                    }
                }
                return res;
            }

            template <typename T>
            void Partition( vector<T> &arr, int& lAxis, int& rAxis )
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
                        Swap( arr[lAxis], arr[rAxis] );
                        ++lAxis;
                        --rAxis;
                    }
                }
            }

        public:
            template<typename T>
            static void Swap( T& a, T& b )
            {
                T tmp = a;
                a = b;
                b = tmp;
            }

            template<typename T>
            static vector<T> MergeSort( vector<T>& in )
            {
                //@comment To avoid refering to out of the index, 
                //the size of vector should be size-1
                return ParseAndMerge( in, 0, in.size() - 1 );
            }

            template <typename T>
            void QuickSort( vector<T> &arr, const int l, const int r )
            {
                if (l >= r)
                {
                    return;
                }

                int lIdx = l, rIdx = r;
                partition( arr, lIdx, rIdx );

                //@comment continue sorting if there is searching area
                if (l < lIdx - 1)
                {
                    quickSort( arr, l, lIdx - 1 );
                }
                if (rIdx + 1 < r)
                {
                    quickSort( arr, rIdx + 1, r );
                }
            }
        };
    }
}