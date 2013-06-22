#include "cTTS.h"
#include "TTS.h"

static TTS * tts;

void maybeInit()
{
	if (tts == 0)
	{
		tts = new TTS();
	}
}

extern "C" void csay(const char * words)
{
	maybeInit();
	tts->say(words);
}

extern "C" void csetVolume(int vol)
{
	maybeInit();
	tts->setVolume(vol);
}
