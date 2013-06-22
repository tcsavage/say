#include <stdio.h>
#include "TTS.h"
// #include "TTSWinWrapper.h"

TTS::TTS()
{
	// wwInit();
	printf("TTS Init\n");
}

TTS::~TTS()
{
	// wwDestroy();
	printf("TTS Destroy\n");
}

void TTS::say(const char * words)
{
	// wwSay(words);
	printf("SAY: %s\n", words);
}

void TTS::setVolume(int v)
{
	printf("TTS Set Volume: %d\n", v);
}
