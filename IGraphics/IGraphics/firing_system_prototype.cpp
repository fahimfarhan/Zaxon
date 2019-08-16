#include<stdio.h>
#include<conio.h>
#include<math.h>
# include "iGraphics.h"

int f[2] ;

int fx=200, fy[2] ={50,50}, c=0;

void iDraw()
{
	iClear();
	iSetColor(250,250,0);
	if(c==1) f[0] = 1;
	
	if(f[0] == 1) iFilledCircle(fx,fy[0],6,4);

	if(c==2) f[1] = 1;
	iSetColor(250,0,0);
	if(f[1] == 1) iFilledCircle(fx,fy[1],6,4);
	iLine(0,50,400,50);
	iLine(0,300,400,300);
}


void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}


void iKeyboard(unsigned char key)
{
	
}

void iSpecialKeyboard(unsigned char key)
{
	static int ml =0;

	if(key == GLUT_KEY_UP)
	{	
		c=(c+1)%3;
		
		//f[(++ml)%2]=1;
		
		
	}
}

void fireChange0()
{
	fy[0]+=3;
	if(fy[0]>=300)
	{
		fy[0] = 50;
		f[0]=0;

	}
}
void fireChange1()
{
	fy[1]+=3;
	if(fy[1]>=300)
	{
		fy[1] = 50;
		f[1]=0;

	}
	
	
	
	//if(f==1)
		
			
}


int main()
{
	
	if(c>=1) iSetTimer(50, fireChange0);
	if(c==2) iSetTimer(50, fireChange1);
	iInitialize(400, 400, "Ball Demo");
	
	return 0;
}