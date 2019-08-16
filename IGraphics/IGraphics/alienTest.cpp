#include"iGraphics.h"

void iDraw()
{
	iClear();
	iShowBMP(10,10,"spaceship,bmp");
	iSetColor(0,255,0);
	iLine(10,10,85,10);

}
int main()
{
	iInitialize(400,400);
	return 0;

}