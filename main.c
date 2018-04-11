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
		// record 1s sound into file "test.wav"
		ret = system("arecord -q -r16000 -c1 -f S16_LE -d1 test.wav");
		// if pressing CTRL + C while running arecord
		if(WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT))
		{
			clearScreen();	// clear the screen
			gotoxy(1,1);	// move the cursor to the top-left corner
			break;			// break the while loop
			// the program ends
		}

		/*
			Clear the old informations displayed on the screen to replace with
			new informations.
		*/
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
