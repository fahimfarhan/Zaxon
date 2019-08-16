#include<stdio.h>
#include<conio.h>
# include "iGraphics.h"
# include "gl.h"

int t[3]={}, c=0,i=0, v[3] = {}, fx[3] = {200,200,200}, fy[3] = {} , mig_x=200, mig_y= 50 ;
int zero[3] = {1,1,1}, score=0, weaponStatus=0, h[3] = {};


void iDraw()
{
	iClear();
	iSetColor(0,0,250);
	iFilledCircle(mig_x, mig_y,6,4);
	iSetColor(250,250,0);
	iLine(0,50,400,50);
	iLine(0,300,400,300);
	iSetColor(255,50,0);
	iFilledCircle(fx[0],fy[0],6,4);
	if(fy[0]>=300){
		fy[0] = mig_y+50;
		v[0] = 0;
		fx[0] = mig_x+50;
		score+=5;
	} 
	iFilledCircle(fx[1],fy[1],6,4);
	if(fy[1]>=300){
		fy[1] = mig_y+50;
		v[1] = 0;
		fx[1] = mig_x+50;
		score+=5;
	}
	iFilledCircle(fx[2],fy[2],6,4);
	if(fy[2]>=300){
		fy[2] = mig_y+50;
		fx[2] = mig_x+50;
		v[2] = 0;
		score+=5;
	}
	iSetColor(250,250,0);
	iFilledRectangle(0,0,120, 25);
	iSetColor(250,0,0);
	iFilledRectangle(0,0,weaponStatus, 25);

	iSetColor(0,250,0);
	iFilledRectangle(0,300,score,25);
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
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}
	//place your codes for other keys here
	
	if((key == 'a') && (mig_x>=10) )
	{
		
		
		mig_x-=3;
	}
	if((key == 'd') && (mig_x<=1200) )
	{
		 mig_x+=3;
	}
	if((key == 'w') ) 
	{
		 mig_y+=3;
	}
	if((key == 's') )
	{
		 mig_y-=3;
	}
	if(key == 'q' )
	{
		 mig_x-=3;
		 mig_y+=3;
	}
	if(key == 'c' )
	{
		 mig_x+=3;
		 mig_y-=3;
	}
	if(key =='e' )
	{
		 mig_x+=3;
		 mig_y+=3;
	}
	if(key == 'z' )
	{
		 mig_x-=3;
		 mig_y-=3;
	}


}


void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_UP && h[i]==0)
	{
		v[i]=4;
		h[i]=2;
		t[i]=6;
		//zero[i]=0;
		i = (i+1)%3;
		
	}


}


void weaponCoolingSystem_0()
{
	if(t[0]>0) t[0]--;		
	if(t[1]>0) t[1]--;
	if(t[2]>0) t[2]--;
	if( t[0] ==0) h[0]=0;
	if( t[1] ==0) h[1]=0;
	if( t[2] ==0) h[2]=0;
	
}



void missle()
{
	if(v[0]==4 && h[0] != 0) fy[0] += v[0];
	else
	{	fy[0] = mig_y+50;
		fx[0] = mig_x+50;
	}
	if(v[1]==4 && h[1] != 0) fy[1] += v[1];
	else
	{	fy[1] = mig_y+50;
		fx[1] = mig_x+50;
	}
	if(v[2]==4 && h[2] != 0) fy[2] += v[2];
	else
	{	fy[2] = mig_y+50;
		fx[2] = mig_x+50;
	}

	 weaponStatus =(int)(h[0]+h[1]+h[2])*20;// weapon cooling system
	//fy[1] += v[1];
	//fy[2] += v[2];
}


int main()
{
	iSetTimer(100,missle);
	iSetTimer(1000, weaponCoolingSystem_0);
	//iSetTimer(100,control_r);
	iInitialize(1300,690,"weapon system test prototype");
}