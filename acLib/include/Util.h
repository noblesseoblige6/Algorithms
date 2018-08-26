#pragma once
namespace acLib
{
    namespace util
    {
        using namespace std;
        class StrUtil
        {
        public:
            static void Split( const string& src, char delim , vector<string>& res )
            {
                stringstream ss( src );
                string item;

                while (getline( ss, item, delim ))
                {
                    if (!item.empty()) 
                    {
                        res.push_back( item );
                    }
                }
            }

        };

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

        class Log
        {
        public:
            enum LOG_LEVEL
            {
                LOG_LEVEL_DEBUG = 0,
                LOG_LEVEL_INFO,
                LOG_LEVEL_WARNING,
                LOG_LEVEL_ERROR,
            };

        public:
            template<typename First, typename... Rest>
            static void OutputWithPrefix( LOG_LEVEL logLevel, const char* format, const First& first, const Rest&... rest )
            {
                if (logLevel < g_logLevel)
                    return;

                PrefixOut( logLevel );

                Output(logLevel, format, first, rest...);
            }

            template<typename First, typename... Rest>
            static void Output( LOG_LEVEL logLevel, const char* format, const First& first, const Rest&... rest)
            {
                if (logLevel < g_logLevel)
                    return;

                while (*format) 
                {
                    if (*format == '%' && *(++format) != '%')
                    {
                        ConsoleOut( logLevel, first, false );
                        Output( logLevel, *format ? ++format : format, rest...);
                        return;
                    }

                    char a[2];
                    strncpy_s( a, sizeof(a), format, 1 );
                    ConsoleOut( logLevel, a, false );

                    ++format;
                }
            }

            static void OutputWithPrefix( LOG_LEVEL logLevel, const char* format )
            {
                if (logLevel < g_logLevel)
                    return;

                PrefixOut( logLevel );

                Output( logLevel, format );
            }

            static void Output( LOG_LEVEL logLevel, const char* format )
            {
                if (logLevel < g_logLevel)
                    return;

                ConsoleOut( logLevel, format, true);
            }

            static void Output( LOG_LEVEL logLevel )
            {
                (void)logLevel;
            }

        protected:
            static void PrefixOut( LOG_LEVEL logLevel )
            {
                switch (logLevel)
                {
                case acLib::util::Log::LOG_LEVEL_DEBUG:
                    cout << "DEBUG: ";
                    break;
                case acLib::util::Log::LOG_LEVEL_INFO:
                    cout << "INFO: ";
                    break;
                case acLib::util::Log::LOG_LEVEL_WARNING:
                    cerr << "WARNING: ";
                    break;
                case acLib::util::Log::LOG_LEVEL_ERROR:
                    cerr << "ERROR: ";
                    break;
                default:
                    break;
                }
            }

            template<class T>
            static void ConsoleOut( LOG_LEVEL logLevel, T message, bool bNewLine = true )
            {
                switch (logLevel)
                {
                case LOG_LEVEL_DEBUG:
                case LOG_LEVEL_INFO:
                    cout << message;
                    if (bNewLine)
                        cerr << endl;
                    break;
                case LOG_LEVEL_WARNING:
                case LOG_LEVEL_ERROR:
                    cerr << message;
                    if (bNewLine)
                        cerr << endl;
                    break;
                default:
                    break;
                };
                
            }

        private:
            static LOG_LEVEL g_logLevel;
        };
    }
}