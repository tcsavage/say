#include <stdlib.h>
#include <libspeechd.h>
#include "TTS.h"

static SPDConnection * spd;

TTS::TTS()
{
	if (!spd)
	{
		spd = spd_open("libHSsay", NULL, NULL, SPD_MODE_THREADED);
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
}

void TTS::setVolume(int v)
{
	if (spd)
	{
		spd_set_volume(spd, v * 2 - 100);
	}
}
