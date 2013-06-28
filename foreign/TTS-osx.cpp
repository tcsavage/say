#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TTS.h"

#include <Carbon/Carbon.h>
#include <CoreFoundation/CoreFoundation.h>
#include <ApplicationServices/ApplicationServices.h>

static SpeechChannel sc;
static bool speaking;
static Fixed volume;

static void speechDone(SpeechChannel sc2, void *refcon) {
	if (sc2 == sc)
	{
		DisposeSpeechChannel(sc);
		speaking = false;
	}
}

TTS::TTS()
{
	speaking = false;
	setVolume(100);
}

TTS::~TTS()
{
}

void TTS::say(const char * words)
{
	if (!speaking)
	{
		NewSpeechChannel(NULL, &sc);
		SetSpeechInfo(sc, soVolume, &volume);
		SetSpeechInfo(sc, soSpeechDoneCallBack, reinterpret_cast<void *>(speechDone));
		CFStringRef cfstr = CFStringCreateWithCString(NULL, words, kCFStringEncodingUTF8);
		OSErr err = SpeakCFString(sc, cfstr, NULL);
		speaking = true;
	}
}

void TTS::setVolume(int v)
{
	volume = FixRatio(v, 100);
}
