#include<stdio.h>
#include<conio.h>
#include<math.h>
# include "iGraphics.h"
#define fire_n 4

int mig_x=600, mig_y=10,i=0, es_x=600,  dx=3, display=1, user_score=25, enemy_life = 200;
 // flags, v = velocity 

int fx[3]={}, fy[3]={}, h[3] = {}, t[3] = {}, v[3] = {}, score=0, weaponStatus ;
float dy =.5, es_y=550;



void iDraw()
{
	if(display ==1)
	{
		

		//
		iClear();
		iShowBMP(0,0,"battlefield-1942-wallpaper-hdthe-battlefield-blog-celebrate-the-battlefield-10th-anniversary-2sbaxmmx.bmp");
		//iSetColor(255,255,255);
		//iFilledRectangle(0,0,1300,690);
		//enemy Lifes drawing
		iSetColor(255,50,50);
		iFilledRectangle(100,650,400,25);
		iSetColor(50,255,50);
		iFilledRectangle(100,650,enemy_life,25);
		//enemy life done


		//spaceship draw
		iShowBMP(es_x, es_y, "spaceship.bmp");
		//iFilledRectangle(es_x,es_y,10);
		//fire drawing codes
		iSetColor(255,50,0);
		iFilledCircle(fx[0],fy[0],6,4);
		if(fy[0]>=650){
			fy[0] = mig_y+145;
			v[0] = 0;
			fx[0] = mig_x+50;
			score+=5;
		} 
		iFilledCircle(fx[1],fy[1],6,4);
		if(fy[1]>=650){
			fy[1] = mig_y+145;
			v[1] = 0;
			fx[1] = mig_x+50;
			score+=5;
		}
		iFilledCircle(fx[2],fy[2],6,4);
		if(fy[2]>=650){
			fy[2] = mig_y+145;
			fx[2] = mig_x+50;
			v[2] = 0;
			score+=5;
		}
		iSetColor(250,250,0);
		iFilledRectangle(0,0,120, 25);
		iSetColor(250,0,0);
		iFilledRectangle(0,0,weaponStatus, 25);
		//draw mig 29 
		iShowBMP(mig_x, mig_y, "mig29.bmp");
		//iLine(550,0,550,150);
		iText(10, 10, "DEFEND EARTH");
	}
}

void weaponCoolingSystem_0()
{
	if(t[0]>0) t[0]-=18;		
	if(t[1]>0) t[1]-=18;
	if(t[2]>0) t[2]-=18;
	if( t[0] ==0) h[0]=0;
	if( t[1] ==0) h[1]=0;
	if( t[2] ==0) h[2]=0;
	
}



void missle()
{
	if(v[0]==6 && h[0] != 0) fy[0] += v[0];
	else
	{	fy[0] = mig_y+145;
		fx[0] = mig_x+50;
	}
	if(v[1]==6 && h[1] != 0) fy[1] += v[1];
	else
	{	fy[1] = mig_y+145;
		fx[1] = mig_x+50;
	}
	if(v[2]==6 && h[2] != 0) fy[2] += v[2];
	else
	{	fy[2] = mig_y+145;
		fx[2] = mig_x+50;
	}

	 weaponStatus =(h[0]+h[1]+h[2])*2/9;// weapon cooling system
	//fy[1] += v[1];
	//fy[2] += v[2];
}



void enemyShipChange_x() // random movement of x axis is generated from here
{
	
	static int rn=0, degree=0;
	rn = (rn+1)%7;
	degree=(degree+10)%360;
	
	if(es_x > 900 || es_x < 50) dx = dx*(-1);
	
	es_x = es_x+rn*dx+3*sin(degree/57.29)-5*cos(degree*2/57.29);
	
}

void enemyShipChange_y() // enemy ship moves down y axis at a const speed
{
	int static degree = 0;
	degree = (degree+10)%360;
	
	
	es_y = es_y-dy+2*sin(degree*2/57.29);
	if(es_y<=400 && es_y>375) es_y = es_y-dy;// increases speed
	if(es_y<=375 ) es_y = es_y-dy; // not dependent on time, need to change later :'(
	
}

/*void iUserScore()
{
	if((fire_y[0] >= es_y) && (es_x<=fire_x[0]) && (fire_x[0]<=(es_x+100))) user_score++;
	else if((fire_y[1] >= es_y) && (es_x<=fire_x[1] && fire_x[1]<=(es_x+100))) user_score++;
	else if((fire_y[2] >= es_y) && (es_x<=fire_x[2] && fire_x[2]<=(es_x+100))) user_score++;
	else if((fire_y[3] >= es_y) && (es_x<=fire_x[3] && fire_x[3]<=(es_x+100))) user_score++;
}*/

void iLifes()
{
	// changes of enemy life being calculated below
	//static int __x = user_score*4;
	enemy_life = 400- user_score*4;
	//changes of player life calculated below

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
		//pr = 0;
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		//pr = 1;
		iResumeTimer(0);
	}
	if(key == 'b')
	{
		//do something with 'x'
		exit(0);
	}
	//while(((pic_x>=10) && (pic_x=<875)))&&((pic_y>=10)&&(pic_y=<595)))
	//{
		//place your codes for other keys here
	if((key == 'a') && (mig_x>=10) )
	{		
		mig_x-=3;
	}
	if((key == 'd') && (mig_x<=1200) )
	{
		 mig_x+=3;
	}
	if((key == 'w') && (mig_y<(es_y-175)) ) // need to fix later
	{
		 mig_y+=3;
	}
	if((key == 's') && (mig_y>=10))
	{
		 mig_y-=3;
	}
	if(key == 'q' && (mig_x>=10) && (mig_y<(es_y-175)) )
	{
		 mig_x-=3;
		 mig_y+=3;
	}
	if(key == 'c' && (mig_x<=1200) && (mig_y>=10))
	{
		 mig_x+=3;
		 mig_y-=3;
	}
	if(key =='e' && (mig_x<=1200) && (mig_y<(es_y-175)) )
	{
		 mig_x+=3;
		 mig_y+=3;
	}
	if(key == 'z' && (mig_x>=10) && (mig_y>=10) )
	{
		 mig_x-=3;
		 mig_y-=3;
	}

}

void iSpecialKeyboard(unsigned char key)
{
	
	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_UP && h[i]==0)
	{
		v[i]=4;
		h[i]=108;
		t[i]=6;
		//zero[i]=0;
		i = (i+1)%3;
		
	}
}



int main()
{
	//iSetTimer(50,iUserScore);
	//iSetTimer(50,iLifes);
	
	iSetTimer(100,missle);
	iSetTimer(1000, weaponCoolingSystem_0);
	
	iSetTimer(90,enemyShipChange_x);
	iSetTimer(200,enemyShipChange_y);// to check speed, change here, put 50 or say 20 instead of 100 :)
	iInitialize(1300,690);
	return 0;
}


