/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"

int pic_x, pic_y;

/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	

	iClear();

	iShowBMP(pic_x, pic_y, "mig29.bmp");

	iText(10, 10, "Use cursors to move the picture.");
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
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

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'b')
	{
		//do something with 'x'
		exit(0);
	}
	//while(((pic_x>=10) && (pic_x=<875)))&&((pic_y>=10)&&(pic_y=<595)))
	//{
		//place your codes for other keys here
	if(key == 'a')
	{
		pic_x-=3;
	}
	if(key == 'd' )
	{
		pic_x+=3;
	}
	if(key == 'w')
	{
		pic_y+=3;
	}
	if(key == 'x')
	{
		pic_y-=3;
	}
	if(key == 'q')
	{
		pic_x-=3;
		pic_y+=3;
	}
	if(key == 'c')
	{
		pic_x+=3;
		pic_y-=3;
	}
	if(key =='e')
	{
		pic_x+=3;
		pic_y+=3;
	}
	if(key == 'z')
	{
		pic_x-=3;
		pic_y-=3;
	}
	//}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_LEFT)
	{
		pic_x-=3;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		pic_x+=3;
	}
	if(key == GLUT_KEY_UP)
	{
		pic_y+=3;
	}
	if(key == GLUT_KEY_DOWN)
	{
		pic_y-=3;
	}
	//place your codes for other keys here
	/*if(key == ((GLUT_KEY_LEFT) && (GLUT_KEY_UP)))
	{
		pic_x-=3;
		pic_y+=3;
	}
	if(key == ((GLUT_KEY_RIGHT) && (GLUT_KEY_DOWN)))
	{
		pic_x+=3;
		pic_y-=3;
	}
	/*if(key == (GLUT_KEY_RIGHT)&&(GLUT_KEY_UP))
	{
		pic_x+=3;
		pic_y+=3;
	}
	if(key == (GLUT_KEY_LEFT)&&(GLUT_KEY_DOWN))
	{
		pic_x-=3;
		pic_y-=3;
	}*/
	
}

int main()
{
	//place your own initialization codes here. 
	pic_x = 100;
	pic_y = 100;
	iInitialize(1000, 720, "PictureDemo");
	return 0;
}	