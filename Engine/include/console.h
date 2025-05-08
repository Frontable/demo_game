







#include <iostream>
#include "SDL.h"
#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif


class ENGINE_API Console
{
    public:

    static void print(const char* text);
};

