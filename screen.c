// contains screen manipulation functions, such as clearScreen(), gotoxy(), setColor(), etc

#include "screen.h"
#include <stdio.h>

void setColor(int color)
{
	printf("%c[1;%dm", ESC, color);
	fflush(stdout);
}

void clearScreen(void)
{
	printf("%c[2J", ESC);
	fflush(stdout);
}

void gotoxy(int row, int col)
{
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

void bar(double dB, int col)
{
	int i;
	for(i=0; i<dB/RES; i++)
	{
		gotoxy(25-i, col+1);	// the first bar start from col=1
#ifdef UNICODE		// if not defined
		printf("%c", '*');
#else
		if(i<60/RES)setColor(GREEN);
		else if(i<80/RES)setColor(YELLOW);
		else setColor(RED);
		printf("%s", BAR);
#endif
	}
	gotoxy(27, 1);
}
