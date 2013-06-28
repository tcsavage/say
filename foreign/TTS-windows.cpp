#include <stdio.h>
#include "TTS.h"
#include "TTSWinWrapper.h"

TTS::TTS()
{
	wwInit();
}

TTS::~TTS()
{
	wwDestroy();
}

void TTS::say(const char * words)
{
	wwSay(words);
}

void TTS::setVolume(int v)
{
	wwSetVolume(v);
}
