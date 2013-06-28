#define __TTSWINWRAPPER_DLL_EXPORT
#include "TTSWinWrapper.h"
#include <iostream>
#include <sapi.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <string>

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
		std::cerr << "Failed to initialize COM" << std::endl;
	}

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (FAILED(hr))
	{
		std::cerr << "Failed to initialize TTS." << std::endl;
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
		// Converts from char to wchar.
		std::string words_s = std::string(words);
		std::wstring words_w(words_s.begin(), words_s.end());

		if (FAILED(pVoice->Speak(words_w.c_str(), SPF_DEFAULT, NULL)))
		{
			std::cerr << "FAILED." << std::endl;
		}
	}
	else
	{
		std::cerr << "TTS voice not set." << std::endl;
	}
}

TTSWINWRAPPER_API void wwSetVolume(int v)
{
	if (pVoice)
	{
		if (FAILED(pVoice->SetVolume(v)))
		{
			std::cerr << "FAILED." << std::endl;
		}
	}
	else
	{
		std::cerr << "TTS voice not set." << std::endl;
	}
}

#ifdef __cplusplus
}
#endif
