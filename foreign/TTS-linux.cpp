#include <stdlib.h>
#include <libspeechd.h>
#include "TTS.h"

static SPDConnection * spd;

TTS::TTS()
{
	printf("TTS Init\n");
	if (!spd)
	{
		spd = spd_open("libHsay", NULL, NULL, SPD_MODE_THREADED);
		if (!spd)
		{
			printf("SPD init failed\n");
		}
		else
		{
			spd_set_punctuation(spd, SPD_PUNCT_NONE);
			spd_set_spelling(spd, SPD_SPELL_ON);
		}
	}
}

TTS::~TTS()
{
	printf("TTS Destroy\n");
	if (spd)
	{
		spd_close(spd);
	}
}

void TTS::say(const char * words)
{
	if (spd)
	{
		spd_say(spd, SPD_MESSAGE, words);
	}
	printf("SAY: %s\n", words);
}

void TTS::setVolume(int v)
{
	if (spd)
	{
		spd_set_volume(spd, SPD_MESSAGE, v * 2 - 100);
	}
	printf("TTS Set Volume: %d\n", v);
}
