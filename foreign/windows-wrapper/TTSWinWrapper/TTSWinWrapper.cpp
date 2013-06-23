#define __TTSWINWRAPPER_DLL_EXPORT
#include "TTSWinWrapper.h"
#include <iostream>
#include <sapi.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	return TRUE;
}

static ISpVoice * pVoice;

#ifdef __cplusplus
extern "C" {
#endif

TTSWINWRAPPER_API void wwInit(void)
{
	pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
	{
		std::cout << "Failed to initialize COM" << std::endl;
	}

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (FAILED(hr))
	{
		std::cout << "Failed to initialize TTS." << std::endl;
	}
}

TTSWINWRAPPER_API void wwDestroy(void)
{
	if (pVoice)
	{
		pVoice->Release();
	}
	::CoUninitialize();
}

TTSWINWRAPPER_API void wwSay(const char * words)
{
	if (pVoice)
	{
		std::cout << "Saying: " << words << std::endl;
		size_t words_len = strlen(words);
		wchar_t * words_w = (wchar_t *)malloc(words_len*sizeof(wchar_t));
		mbstowcs(words_w, words, words_len);
		if (FAILED(pVoice->Speak(words_w, SPF_DEFAULT, NULL)))
		{
			std::cout << "FAILED." << std::endl;
		}
		else
		{
			std::cout << "Done." << std::endl;
		}
	}
	else
	{
		std::cout << "TTS voice not set." << std::endl;
	}
}

#ifdef __cplusplus
}
#endif
