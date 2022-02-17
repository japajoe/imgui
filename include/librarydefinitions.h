#ifndef LIBRARYDEFINITIONS_HPP
#define LIBRARYDEFINITIONS_HPP

#if defined(_MSC_VER)
    //  Microsoft 
    #define IMGUI_API_EXPORT __declspec(dllexport)
    #define IMGUI_API_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
    //  GCC
    #define IMGUI_API_EXPORT __attribute__((visibility("default")))
    #define IMGUI_API_IMPORT
#else
    //  do nothing and hope for the best?
    #define IMGUI_API_EXPORT
    #define IMGUI_API_IMPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#endif