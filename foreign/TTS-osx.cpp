#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TTS.h"

TTS::TTS()
{
}

TTS::~TTS()
{
}

void TTS::say(const char * words)
{
	int n = strlen(words);
	char * command = new char[n+4];
	strcat(command, "say ");
	strcat(command, words);
	system(command);
	printf("SAY: %s\n", words);
}

void TTS::setVolume(int v)
{
}
