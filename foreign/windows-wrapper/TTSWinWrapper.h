#ifndef __TTSWINWRAPPER_H
#define __TTSWINWRAPPER_H

// This header needs to be understood by VC++ and GCC
// When included in the source for building the DLL,
// __TTSWINWRAPPER_DLL_EXPORT must be defined

#ifdef __TTSWINWRAPPER_DLL_EXPORT
#define TTSWINWRAPPER_API __declspec(dllexport)
#else
#define TTSWINWRAPPER_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

TTSWINWRAPPER_API void wwInit(void);
TTSWINWRAPPER_API void wwDestroy(void);
TTSWINWRAPPER_API void wwSay(const char *);
TTSWINWRAPPER_API void wwSetVolume(int);

#ifdef __cplusplus
}
#endif
#endif // __TTSWINWRAPPER_H
