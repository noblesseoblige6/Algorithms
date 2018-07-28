namespace acLib
{
    namespace util
    {
#ifdef _DEBUG
        Log::LOG_LEVEL Log::g_logLevel = Log::LOG_LEVEL_DEBUG;
#else
        Log::LOG_LEVEL Log::g_logLevel = Log::LOG_LEVEL_INFO;
#endif
    }
}