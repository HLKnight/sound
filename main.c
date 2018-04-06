// main file
#include <stdlib.h>
#include <signal.h>
#include "sound.h"
#include "screen.h"
#include "comm.h"

int main(void)
{
	int ret;
	while(1)
	{
		// record 1s of sound into test.wav
		ret = system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav");
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT)) break;

		clearScreen();
		// open the wav file and read samples
		// display necessary information (duration, WAV header)
		displayWAVheader("test.wav");
		// calculate fast dBs
		displayBar("test.wav");
		// send fast dBs to web (PHP program on www.cc.puv.fi)
		//break;	// for testing, just run the loop once
	}
	return 0;
}
