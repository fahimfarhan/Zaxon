#include <stdio.h>
#include "iGraphics.h"
#include <math.h>
int position=1,direction_of_fly=2;
double v1=70,fly_1_x,fly_1_y,fly_1_degree=0,initial_fly_1_x=1300,initial_fly_1_y=580,boom_x_ball_1=0,boom_y_ball_1=0;//950 500
double initial_fly_2_x=1500,initial_fly_2_y=500,fly_2_degree=0,fly_2_x,fly_2_y;//1 for going up 800 200
double initial_fly_3_x=1600,initial_fly_3_y=600,fly_3_y_condition=2,fly_3_y,fly_3_x,fly_3_t_y=0,fly_3_t_x=0;
double fly_4_x,fly_4_y,initial_fly_4_x=1200,initial_fly_4_y=400,fly_4_y_condition=1,fly_4_y_subcondition,fly_4_degree=0,fly_4_v=70,fly_4_a=1.5,fly_4_t=0,initial_fly_4_y_2=470,initial_fly_4_x_2=700,initial_fly_y_4_3,initial_fly_x_4_3;
double initial_ball_1_x=350,initial_ball_1_y=360,ball_1_x,ball_1_y,time_for_ball_1,start_for_ball_1=0;
double initial_ball_2_x=330,initial_ball_2_y=370,ball_2_x,ball_2_y,time_for_ball_2,start_for_ball_2=0,boom_x_ball_2;
double initial_ball_3_x=318,initial_ball_3_y=380,ball_3_x,ball_3_y,time_for_ball_3,start_for_ball_3=0,boom_x_ball_3;
double initial_ball_4_x=295,initial_ball_4_y=394,ball_4_x,ball_4_y,time_for_ball_4,start_for_ball_4=0,boom_x_ball_4;
double g1,f1,g2,f2,g3,f3,g4,f4,boom_for_target_for_fly_1_for_ball_1,boom_for_target_for_fly_2_for_ball_1,boom_for_target_for_fly_3_for_ball_1,boom_for_target_for_fly_4_for_ball_1;
double boom_for_target_for_fly_1_for_ball_2,boom_for_target_for_fly_2_for_ball_2,boom_for_target_for_fly_3_for_ball_2,boom_for_target_for_fly_4_for_ball_2;
double boom_for_target_for_fly_1_for_ball_3,boom_for_target_for_fly_2_for_ball_3,boom_for_target_for_fly_3_for_ball_3,boom_for_target_for_fly_4_for_ball_3;
double boom_for_target_for_fly_1_for_ball_4,boom_for_target_for_fly_2_for_ball_4,boom_for_target_for_fly_3_for_ball_4,boom_for_target_for_fly_4_for_ball_4;
char time2[100];
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	iClear();
	iSetColor(255,0,0);
	
	switch(position){
	case 1:
		iShowBMP(0,0,"image//04.bmp");
		break;
	case 2:
		iShowBMP(0,0,"image//03.bmp");
		break;
	case 3:
		iShowBMP(0,0,"image//02.bmp");
		break;
	case 4:
		iShowBMP(0,0,"image//01.bmp");
		break;
	}
	iShowBMP(fly_1_x,fly_1_y,"image//Fly2.bmp");
	iShowBMP(fly_2_x,fly_2_y,"image//Fly2.bmp");
	iShowBMP(fly_3_x,fly_3_y,"image//Fly2.bmp");
	iShowBMP(fly_4_x,fly_4_y,"image//Fly2.bmp");
	g1=fly_1_x+32,f1=fly_1_y+26,g2=fly_2_x+32,f2=fly_2_y+26,g3=fly_3_x+32,f3=fly_3_y+26,g4=fly_4_x+32,f4=fly_4_y+26;
	if(start_for_ball_1==1){
		iFilledCircle(ball_1_x,ball_1_y,10);
		boom_for_target_for_fly_1_for_ball_1=pow(ball_1_x-g1,2)+pow(ball_1_y-f1,2);
		boom_for_target_for_fly_1_for_ball_1=sqrt(boom_for_target_for_fly_1_for_ball_1);
		boom_for_target_for_fly_2_for_ball_1=pow(ball_1_x-g2,2)+pow(ball_1_y-f2,2);
		boom_for_target_for_fly_2_for_ball_1=sqrt(boom_for_target_for_fly_2_for_ball_1);
		boom_for_target_for_fly_3_for_ball_1=pow(ball_1_x-g3,2)+pow(ball_1_y-f3,2);
		boom_for_target_for_fly_3_for_ball_1=sqrt(boom_for_target_for_fly_3_for_ball_1);
		boom_for_target_for_fly_4_for_ball_1=pow(ball_1_x-g4,2)+pow(ball_1_y-f4,2);
		boom_for_target_for_fly_4_for_ball_1=sqrt(boom_for_target_for_fly_4_for_ball_1);
		if(ball_1_y>=680){
			start_for_ball_1=0;
			time_for_ball_1=0;
		}
		else if(boom_for_target_for_fly_1_for_ball_1<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g1,f1,"image//Boom.bmp");
			start_for_ball_1=0,time_for_ball_1=0;
			fly_1_degree=0;

		}
		else if(boom_for_target_for_fly_2_for_ball_1<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g2,f2,"image//Boom.bmp");
			start_for_ball_1=0,time_for_ball_1=0;
			fly_2_degree=0;
		}
		else if(boom_for_target_for_fly_3_for_ball_1<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g3,f3,"image//Boom.bmp");
			start_for_ball_1=0,time_for_ball_1=0;
			fly_3_t_x=0,fly_3_t_y=0,fly_3_y_condition=2;
		}
	    else if(boom_for_target_for_fly_4_for_ball_1<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g4,f4,"image//Boom.bmp");
			start_for_ball_1=0,time_for_ball_1=0;
			fly_4_y_condition=1,fly_4_degree=0,fly_4_t=0;
		}
	}
	if(start_for_ball_2==1){
		iFilledCircle(ball_2_x,ball_2_y,10);
		boom_for_target_for_fly_1_for_ball_2=pow(ball_2_x-g1,2)+pow(ball_2_y-f1,2);
		boom_for_target_for_fly_1_for_ball_2=sqrt(boom_for_target_for_fly_1_for_ball_2);
		boom_for_target_for_fly_2_for_ball_2=pow(ball_2_x-g2,2)+pow(ball_2_y-f2,2);
		boom_for_target_for_fly_2_for_ball_2=sqrt(boom_for_target_for_fly_2_for_ball_2);
		boom_for_target_for_fly_3_for_ball_2=pow(ball_2_x-g3,2)+pow(ball_2_y-f3,2);
		boom_for_target_for_fly_3_for_ball_2=sqrt(boom_for_target_for_fly_3_for_ball_2);
		boom_for_target_for_fly_4_for_ball_2=pow(ball_2_x-g4,2)+pow(ball_2_y-f4,2);
		boom_for_target_for_fly_4_for_ball_2=sqrt(boom_for_target_for_fly_4_for_ball_2);
		if(ball_2_y>=680){
			start_for_ball_2=0;
			time_for_ball_2=0;
		}
		else if(boom_for_target_for_fly_1_for_ball_2<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g1,f1,"image//Boom.bmp");
			start_for_ball_2=0,time_for_ball_2=0;
			fly_1_degree=0;

		}
		else if(boom_for_target_for_fly_2_for_ball_2<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g2,f2,"image//Boom.bmp");
			start_for_ball_2=0,time_for_ball_2=0;
			fly_2_degree=0;
		}
		else if(boom_for_target_for_fly_3_for_ball_2<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g3,f3,"image//Boom.bmp");
			start_for_ball_2=0,time_for_ball_2=0;
			fly_3_t_x=0,fly_3_t_y=0,fly_3_y_condition=2;
		}
	    else if(boom_for_target_for_fly_4_for_ball_2<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g4,f4,"image//Boom.bmp");
			start_for_ball_2=0,time_for_ball_2=0;
			fly_4_y_condition=1,fly_4_degree=0,fly_4_t=0;
		}
	}
	
	if(start_for_ball_3==1){
		iFilledCircle(ball_3_x,ball_3_y,10);
		
		boom_for_target_for_fly_1_for_ball_3=pow(ball_3_x-g1,2)+pow(ball_3_y-f1,2);
		boom_for_target_for_fly_1_for_ball_3=sqrt(boom_for_target_for_fly_1_for_ball_3);
		boom_for_target_for_fly_2_for_ball_3=pow(ball_3_x-g2,2)+pow(ball_3_y-f2,2);
		boom_for_target_for_fly_2_for_ball_3=sqrt(boom_for_target_for_fly_2_for_ball_3);
		boom_for_target_for_fly_3_for_ball_3=pow(ball_3_x-g3,2)+pow(ball_3_y-f3,2);
		boom_for_target_for_fly_3_for_ball_3=sqrt(boom_for_target_for_fly_3_for_ball_3);
		boom_for_target_for_fly_4_for_ball_3=pow(ball_3_x-g4,2)+pow(ball_3_y-f4,2);
		boom_for_target_for_fly_4_for_ball_3=sqrt(boom_for_target_for_fly_4_for_ball_3);
		if(ball_3_y>=690){
			start_for_ball_3=0;
			time_for_ball_3=0;
		}
		else if(boom_for_target_for_fly_1_for_ball_3<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g1,f1,"image//Boom.bmp");
			start_for_ball_3=0,time_for_ball_3=0;
			fly_1_degree=0;

		}
		else if(boom_for_target_for_fly_2_for_ball_3<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g2,f2,"image//Boom.bmp");
			start_for_ball_3=0,time_for_ball_3=0;
			fly_2_degree=0;
		}
		else if(boom_for_target_for_fly_3_for_ball_3<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g3,f3,"image//Boom.bmp");
			start_for_ball_3=0,time_for_ball_3=0;
			fly_3_t_x=0,fly_3_t_y=0,fly_3_y_condition=2;
		}
	    else if(boom_for_target_for_fly_4_for_ball_3<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g4,f4,"image//Boom.bmp");
			start_for_ball_3=0,time_for_ball_3=0;
			fly_4_y_condition=1,fly_4_degree=0,fly_4_t=0;
		}
	}
	if(start_for_ball_4==1){
		iFilledCircle(ball_4_x,ball_4_y,10);
		
		boom_for_target_for_fly_1_for_ball_4=pow(ball_4_x-g1,2)+pow(ball_4_y-f1,2);
		boom_for_target_for_fly_1_for_ball_4=sqrt(boom_for_target_for_fly_1_for_ball_4);
		boom_for_target_for_fly_2_for_ball_4=pow(ball_4_x-g2,2)+pow(ball_4_y-f2,2);
		boom_for_target_for_fly_2_for_ball_4=sqrt(boom_for_target_for_fly_2_for_ball_4);
		boom_for_target_for_fly_3_for_ball_4=pow(ball_4_x-g3,2)+pow(ball_4_y-f3,2);
		boom_for_target_for_fly_3_for_ball_4=sqrt(boom_for_target_for_fly_3_for_ball_4);
		boom_for_target_for_fly_4_for_ball_4=pow(ball_4_x-g4,2)+pow(ball_4_y-f4,2);
		boom_for_target_for_fly_4_for_ball_4=sqrt(boom_for_target_for_fly_4_for_ball_4);
		if(ball_4_y>=690){
			start_for_ball_4=0;
			time_for_ball_4=0;
		}
		else if(boom_for_target_for_fly_1_for_ball_4<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g1,f1,"image//Boom.bmp");
			start_for_ball_4=0,time_for_ball_4=0;
			fly_1_degree=0;

		}
		else if(boom_for_target_for_fly_2_for_ball_4<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g2,f2,"image//Boom.bmp");
			start_for_ball_4=0,time_for_ball_4=0;
			fly_2_degree=0;
		}
		else if(boom_for_target_for_fly_3_for_ball_4<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g3,f3,"image//Boom.bmp");
			start_for_ball_4=0,time_for_ball_4=0;
			fly_3_t_x=0,fly_3_t_y=0,fly_3_y_condition=2;
		}
	    else if(boom_for_target_for_fly_4_for_ball_4<=30){
			PlaySound("sound//Boomsound",NULL,SND_ASYNC);
			iShowBMP(g4,f4,"image//Boom.bmp");
			start_for_ball_4=0,time_for_ball_4=0;
			fly_4_y_condition=1,fly_4_degree=0,fly_4_t=0;
		}
	}
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
	if(key=='s'&&position==1&&start_for_ball_1==0){
		time_for_ball_1=0;
		start_for_ball_1=1;
	}
	if(key=='s'&&position==2&&start_for_ball_2==0){
		time_for_ball_2=0;
		start_for_ball_2=1;
	}
	if(key=='s'&&position==3&&start_for_ball_3==0){
		time_for_ball_3=0;
		start_for_ball_3=1;
	}
	if(key=='s'&&position==4&&start_for_ball_4==0){
		time_for_ball_4=0;
		start_for_ball_4=1;
	}

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

	if(key==GLUT_KEY_RIGHT){
		switch(position){
		case 4:
			position=3;
			break;
		case 3:
			position=2;
			break;
		case 2:
			position=1;
			break;
		}
	}
	if(key==GLUT_KEY_LEFT){
		switch(position){
		case 1:
			position=2;
			break;
		case 2:
			position=3;
			break;
		case 3:
			position=4;
			break;
		}
	}
	//place your codes for other keys here
}

void fly()
{
	
	fly_1_degree+=20;
	fly_1_x=initial_fly_1_x-fly_1_degree;
	fly_1_y=initial_fly_1_y-20*sin(fly_1_degree);
	if(fly_1_x<=-100){
		fly_1_degree=0;
	}
	
}
void secondfly()
{
	fly_2_x=initial_fly_2_x-fly_2_degree;
	fly_2_y=initial_fly_2_y-40*sin(fly_2_degree);
	fly_2_degree+=40;
	if(fly_2_x<=-100){
		fly_2_degree=0;
	}
}



void thirdfly()
{
	if(fly_3_x<=-300){
		fly_3_t_x=0;
		fly_3_t_y=0;
		fly_3_y_condition=2;
	}
	fly_3_x=initial_fly_3_x-fly_3_t_x*20;
	fly_3_t_x++;
	if(fly_3_y_condition==2){
		if(fly_3_y!=500){
		fly_3_y=initial_fly_3_y-fly_3_t_y*20;
		fly_3_t_y++;
		}
		else{
			fly_3_t_y=0;
			fly_3_y_condition=1;
		}
	}
	if(fly_3_y_condition==1){
		if(fly_3_y!=600){
		fly_3_y=initial_fly_3_y+fly_3_t_y*20;
		fly_3_t_y++;
		}
		else{
			fly_3_y_condition=2;
			fly_3_t_y=0;
		}
	}
}

void fourthfly()
{
	if(fly_4_y_condition==1){
		fly_4_x=initial_fly_4_x-fly_4_v*cos(45.0)*fly_4_t;
		fly_4_y=initial_fly_4_y+fly_4_v*sin(45.0)*fly_4_t-.5*fly_4_a*fly_4_t*fly_4_t;
		fly_4_t++;
	}
	if(fly_4_y>600&&fly_4_y_condition==1){
		fly_4_y_condition=2;
		fly_4_y_subcondition=7;
		fly_4_t=0;
	}
	if(fly_4_y_condition==2){
		if(fly_4_y_subcondition==7){
			fly_4_y=fly_4_y-20;
			fly_4_x=fly_4_x-20;
			if(fly_4_y<=400){
				fly_4_y_subcondition=8;
			}
		}
		if(fly_4_y_subcondition==8){
			fly_4_y=fly_4_y+10;
			fly_4_x=fly_4_x-10;
			if(fly_4_y>=500){
				fly_4_y_condition=3;
			}
		}
	}
	if(fly_4_y_condition==3){
		fly_4_y=initial_fly_4_y_2+20*cos(fly_4_degree);
		fly_4_x=initial_fly_4_x_2-fly_4_degree;
		fly_4_degree+=40;
		if(fly_4_x<=270){
			fly_4_y_condition=5;
			initial_fly_y_4_3=fly_4_y;
			initial_fly_x_4_3=fly_4_x;
			fly_4_degree=0;
		}
	}
	if(fly_4_y_condition==5){
		fly_4_y=initial_fly_y_4_3+fly_4_v*sin(45.0)*fly_4_t+.5*fly_4_v*fly_4_t*fly_4_t;
		fly_4_x=initial_fly_x_4_3-fly_4_v*cos(45.0)*fly_4_t;
		fly_4_t++;
		if(fly_4_x<=250){
			fly_4_y_condition=6;
			fly_4_t=0;
		}
	}
	if(fly_4_y_condition==6){
		fly_4_y=fly_4_y+10;
		fly_4_x=fly_4_x-30;
		if(fly_4_x<=-200){
			fly_4_y_condition=1;
		}
	}


}
void ball_1_func()
{
	if(start_for_ball_1==1){
		ball_1_x=initial_ball_1_x+time_for_ball_1*35;
		ball_1_y=initial_ball_1_y+time_for_ball_1*20;
		time_for_ball_1+=2;
	}
}
void ball_2_func()
{
	if(start_for_ball_2==1){
		ball_2_x=initial_ball_2_x+time_for_ball_2*25;
		ball_2_y=initial_ball_2_y+time_for_ball_2*20;
		time_for_ball_2+=2;
	}
}
void ball_3_func()
{
	if(start_for_ball_3==1){
		ball_3_x=initial_ball_3_x+time_for_ball_3*30;
		ball_3_y=initial_ball_3_y+time_for_ball_3*30;
		time_for_ball_3+=2;
	}
}
void ball_4_func()
{
	if(start_for_ball_4==1){
		ball_4_x=initial_ball_4_x+time_for_ball_4*17;
		ball_4_y=initial_ball_4_y+time_for_ball_4*24;
		time_for_ball_4+=2;
	}
}
int main()
{
	iSetTimer(30,fly);
	
	iSetTimer(200,secondfly);
	iSetTimer(300,thirdfly);
	iSetTimer(200,fourthfly);
	iSetTimer(3,ball_1_func);
	iSetTimer(3,ball_2_func);
	iSetTimer(1,ball_3_func);
	iSetTimer(3,ball_4_func);
	iInitialize(1300,650, "demooo");
	return 0;
}	