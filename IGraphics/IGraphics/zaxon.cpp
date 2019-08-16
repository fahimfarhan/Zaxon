#include<stdio.h>
#include<conio.h>
#include<string.h>
# include "iGraphics.h"
# include "gl.h"
/*
typedef struct 
{
	char *NAME;
	int SCORE;
}scoring;
*/
#define MissileNum 5
#define alienShotUsed 3
FILE *s;
int t[5]={}, c=0,i=0, v[5] = {}, fx[5] = {200,200,200,200,200}, fy[5] = {} , mig_x=400, mig_y= 20,es_x=600,  dx=3,display=5;
int alienLife=1300,score=0, weaponStatus=0, h[5] = {};
char welcome1[]="Start New Survival Test";
char welcome2[]="Top Fighters-Hall of Fame";
char welcome3[]="Enter with a new identity";
int mox=0,moy=1,mo=0,wing=5;
float es_y = 550, dy = .5;
//name input er jnno
char str[100], str2[100];
//data saving er jonno
char kang[1000][100];
char st[100];
int x;
char z;
//scoring scores;
int len=0,mode=0;
void drawTextBox() //name input er jonno
{
	iSetColor(150, 150, 150);
	iRectangle(500, 450, 250, 50);
}

void iDraw()
{
	iClear();
	if (display == 1)
	{
		//iSetColor(250,25,250);
		//iFilledRectangle(0,0,1300,690);

		//iShowBMP(0,0,"battlefield-1942-wallpaper-hdthe-battlefield-blog-celebrate-the-battlefield-10th-anniversary-2sbaxmmx.bmp");
		iShowBMP(0,0,"back.bmp");
		//iSetColor(0,0,250);
		//iFilledCircle(mig_x, mig_y,6,4);
		//iSetColor(250,250,0);
		//iLine(0,50,400,50);
		//iLine(0,300,400,300);
		iShowBMP2(es_x, es_y, "st6.bmp",0);//the alien XD
		//iSetColor(0,0,250);
		//iFilledRectangle(es_x,es_y,337,10);
		//static int bi = es_y+90;
		//iFilledCircle(es_x,bi,6,4);
		//iSetColor(0,0,0); // attempt to hide missiles failed :(
		//iFilledCircle(hide_x,hide_y,6,4);
		//iShowBMP(mig_x, mig_y, "mig29.bmp");
		// mig29 missile codes
		iSetColor(255,0,0);
		iFilledCircle(fx[0],fy[0],6,4);
		
		if(fy[0]>=610){
		
			fy[0] = mig_y+50;
			v[0] = 0;
			fx[0] = mig_x+50;
			//score+=5;
		} 
		//iSetColor(250,0,0);
		iFilledCircle(fx[1],fy[1],6,4);
		if(fy[1]>=610){
			fy[1] = mig_y+50;
			v[1] = 0;
			fx[1] = mig_x+50;
			//score+=5;
		}
		//iSetColor(0,0,250);
		iFilledCircle(fx[2],fy[2],6,4);
		if(fy[2]>=610){
			fy[2] = mig_y+50;
			fx[2] = mig_x+50;
			v[2] = 0;
			//score+=5;
		}

		iFilledCircle(fx[3],fy[3],6,4);
		if(fy[3]>=610){
			fy[3] = mig_y+50;
			fx[3] = mig_x+50;
			v[3] = 0;
			//score+=5;
		}
		iFilledCircle(fx[4],fy[4],6,4);
		if(fy[4]>=610){
			fy[4] = mig_y+50;
			fx[4] = mig_x+50;
			v[4] = 0;
			//score+=5;
		}
		//iSetColor(0,0,0); // attempt to hide missiles failed :(
		//iFilledCircle(hide_x,hide_y,6,4);


		iSetColor(250,250,0);
		static int permanentRec = 40*MissileNum; //if 4 any reason the 
		iFilledRectangle(0,0,permanentRec, 25); //4 weapon heating indicator
		iSetColor(250,0,0);
		iFilledRectangle(0,0,weaponStatus, 25);
		//the score code or lifes drawing codes
		iSetColor(255,0,0);
		iFilledRectangle(0,660,1300,25);
		iSetColor(0,250,0);
		iFilledRectangle(0,660,alienLife,25);
		iShowBMP2(mig_x, mig_y, "mig29.bmp",0);
		iSetColor(0,0,0);
		iText(375,10,"Use Left QWERTY for your movement , UP ARROW for firing , DOWN ARROW for skipping the test",GLUT_BITMAP_HELVETICA_18);
	// paki urano jonno code :3 
		/*if(mox% wing==0){
			//iShowBMP(0,0,"images//final building.bmp");
			iShowBMP2(mo,332,"bird_1.bmp",0);
			moy++;
			//mo++;
			if(moy%wing==0) mox++;
			mo+=5;
			if(mo>1300) mo = 0;
		}
		else //if (moy% wing==0) 
		{
			//printf("dhukse\n");
			iShowBMP2(mo,332,"bird_2.bmp",0);
			mox++;
			mo+=5;
			if(mox%wing==0) moy++;
			if(mo>1300) mo = 0;
		}
		*/
//pakhi uranor jonno code
		printf("%d\n",score);
	}
	
	else if (display==0)
	{
		iShowBMP(0,0,"openscreen.bmp");
		iSetColor(200,80,200);
		iFilledRectangle(300,500,700,100);
		iSetColor(255,255,255);
		iText(530,535,welcome1,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(20,100,20);
		iFilledRectangle(300,300,700,100);
		iSetColor(250,230,250);
		iText(530,335,welcome2,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(100,150,250);
		iFilledRectangle(300,100,700,100);
		iSetColor(0,23,0);
		iText(530,135,welcome3,GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if (display==5)
	{
		iShowBMP(0,0,"survivescreen.bmp");
		drawTextBox();
		if (mode==1)
		{
			iSetColor(255, 255, 255);
			iText(545, 465, str,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		iText(520, 430, "ENTER YOUR NAME TO SURVIVE");
	}
	else if (display==2) //hall of fame
	{
		iShowBMP(0,0,"hof.bmp");
		//iSetColor(0,0,0);
		//iText(530,635,welcome2,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,600,kang[0],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,540,kang[1],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,480,kang[2],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,420,kang[3],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,360,kang[4],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,300,kang[5],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,240,kang[6],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,180,kang[7],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,120,kang[8],GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(100,60,kang[9],GLUT_BITMAP_TIMES_ROMAN_24);

	}
	else if (display==3) //hall of shame
	{
		iShowBMP(0,0,"back.bmp");
	}
	else if (display=4) //game jite gele
	{	
		iShowBMP(0,0,"survived.bmp");
		
	}
	
	
}

void iUserScore()
{
	if((fy[0] >= (es_y+25)) && (es_x<=fx[0]) && (fx[0]<=(es_x+337)) ) 
	{	
		score+=4;
		alienLife -=52;
		fy[0] = mig_y+50;
		v[0] = 0;
		fx[0] = mig_x+50;
		if (alienLife==-52)
		{
			display=4;
			//scores.SCORE=score;
			fprintf(s,"%d %s\n",score,str2);
			fclose(s);
		}
	}

	if((fy[1] >= (es_y+25)) && (es_x<=fx[1] && fx[1]<=(es_x+337)) ) 
	{
		score+=4;
		fy[1] = mig_y+50;
		v[1] = 0;
		fx[1] = mig_x+50;
		alienLife -=52;
		if (alienLife==-52)
		{
			display=4;
			//scores.SCORE=score;
			//fprintf(s,"%s%d",scores.NAME,scores.SCORE);
			fprintf(s,"%d %s\n",score,str2);
			fclose(s);
		}
	}
	if((fy[2] >= (es_y+25)) && (es_x<=fx[2] && fx[2]<=(es_x+337))) 
	{
		score+=4;
		alienLife -=52;
		fy[2] = mig_y+50;
		fx[2] = mig_x+50;
		v[2] = 0;
		if (alienLife==-52)
		{
			display=4;
			//scores.SCORE=score;
			//fprintf(s,"%s%d",scores.NAME,scores.SCORE);
			fprintf(s,"%d %s\n",score,str2);
			fclose(s);
		}
	}
	if((fy[3] >= (es_y+25)) && (es_x<=fx[3] && fx[3]<=(es_x+337))) 
	{
		score+=4;
		alienLife -=52;
		fy[3] = mig_y+50;
		fx[3] = mig_x+50;
		v[3] = 0;
		if (alienLife==-52)
		{
			display=4;
			//scores.SCORE=score;
			//fprintf(s,"%s%d",scores.NAME,scores.SCORE);
			fprintf(s,"%d %s\n",score,str2);
			fclose(s);
		}
	}
	if((fy[4] >= (es_y+25)) && (es_x<=fx[4] && fx[4]<=(es_x+337))) 
	{
		score+=4;
		alienLife -=52;
		fy[4] = mig_y+50;
		fx[4] = mig_x+50;
		v[4] = 0;
		if (alienLife==-52)
		{
			display=4;
			//scores.SCORE=score;
			//fprintf(s,"%s%d",scores.NAME,scores.SCORE);
			fprintf(s,"%d %s\n",score,str2);
			fclose(s);
		}
	}
	//else if((fy[3] >= es_y) && (es_x<=fx[3] && fx[3]<=(es_x+330))) score+=5;
	//alienLife -=score;	
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
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  )
	{
		if (display==0)
		{

		if (mx>=300 && mx<=1000 && my>=500 &&my<=600)
		{
			display=1;
			s=fopen("files\\user_scores.txt","a");
		}
		else if (mx>=300 && mx<=1000 && my>=300 &&my<=400)
		{
		display=2;	
		s=fopen("files\\user_scores.txt","r");
		while(fgets(st,60,s)!=NULL)
		{
			strcpy(*(kang+x),st);
			x++;
		}
		fclose(s);
		//printf("%s",kang);
		}
		else if (mx>=300 && mx<=1000 && my>=100 &&my<=200)
			display=5;
		}
		else if (display==5) //name input newar jonne
		{	
		if(mx >= 500 && mx <= 750 && my >= 450 && my <= 500 && mode == 0)
		{
			mode = 1;
		}
		}
	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && display==0)
	{
		
	}
}

void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//pr = 0;
		//do something with 'q'
		//iPauseTimer(0);
	}
	if(key == 'r')
	{
		//pr = 1;
		//iResumeTimer(0);
	}
	if(key == 'b')
	{
		//do something with 'x'
		//exit(0);
	}
	//while(((pic_x>=10) && (pic_x=<875)))&&((pic_y>=10)&&(pic_y=<595)))
	//{
		//place your codes for other keys here
	if((key == 'a') && (mig_x>=10) )
	{		
		mig_x-=6;
	}
	if((key == 'd') && (mig_x<=1200) )
	{
		 mig_x+=6;
	}
	if((key == 'w') && (mig_y<(es_y-175)) ) // need to fix later
	{
		 mig_y+=6;
	}
	if((key == 's') && (mig_y>=10))
	{
		 mig_y-=6;
	}
	if(key == 'q' && (mig_x>=10) && (mig_y<(es_y-175)) )
	{
		 mig_x-=6;
		 mig_y+=6;
	}
	if(key == 'c' && (mig_x<=1200) && (mig_y>=10))
	{
		 mig_x+=6;
		 mig_y-=6;
	}
	if(key =='e' && (mig_x<=1200) && (mig_y<(es_y-175)) )
	{
		 mig_x+=6;
		 mig_y+=6;
	}
	if(key == 'z' && (mig_x>=10) && (mig_y>=10) )
	{
		 mig_x-=6;
		 mig_y-=6;
	}
	//display 5 er jonno egula
		int i;
	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			//structuer er moddhe nam nia jabo
		//	strcpy(scores.NAME,str2);
			//
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
			display=0;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}
	//display 5 ends
}

void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_UP && h[i]==0)
	{
		v[i]=10;
		h[i]=2;
		t[i]=7;
		//zero[i]=0;
		i = (i+1)%MissileNum; //
		
	}
	if(key == GLUT_KEY_DOWN && (display!=0))
	{
		if (display==1)
		{
			fprintf(s,"%d %s\n",score,str2);
			fclose(s);
		}
		display=0;
		c=0,i=0, mig_x=400, mig_y= 20,es_x=600,  dx=3;
		alienLife=1300,score=0, weaponStatus=0;
		es_y = 550, dy = .5;
	}


}


void weaponCoolingSystem_0()
{
	if(t[0]>0) t[0]--;		
	if(t[1]>0) t[1]--;
	if(t[2]>0) t[2]--;
	if(t[3]>0) t[3]--;
	if(t[4]>0) t[4]--;
	if( t[0] ==0) h[0]=0;
	if( t[1] ==0) h[1]=0;
	if( t[2] ==0) h[2]=0;
	if( t[3] ==0) h[3]=0;
	if( t[4] ==0) h[4]=0;
}



void missle()
{
	if(v[0]==10 && h[0] != 0) fy[0] += v[0];
	else
	{	fy[0] = mig_y+50;
		fx[0] = mig_x+50;
	}
	if(v[1]==10 && h[1] != 0) fy[1] += v[1];
	else
	{	fy[1] = mig_y+50;
		fx[1] = mig_x+50;
	}
	if(v[2]==10 && h[2] != 0) fy[2] += v[2];
	else
	{	fy[2] = mig_y+50;
		fx[2] = mig_x+50;
	}
	if(v[3]==10 && h[3] != 0) fy[3] += v[3];
	else
	{	fy[3] = mig_y+50;
		fx[3] = mig_x+50;
	}
	if(v[4]==10 && h[4] != 0) fy[4] += v[4];
	else
	{	fy[4] = mig_y+50;
		fx[4] = mig_x+50;
	}

	 weaponStatus = (h[0]+h[1]+h[2]+h[3]+h[4])*20;// weapon cooling system
	//fy[1] += v[1];
	//fy[2] += v[2];
}

void enemyShipChange_x() // random movement of x axis is generated from here
{
	if (display!=1)
	{
		static int rn=0, degree=0;
	rn = (rn+1)%7;
	degree=(degree+10)%360;
	}

	else{
	static int rn=0, degree=0;
	rn = (rn+1)%7;
	degree=(degree+10)%360;
	
	if(es_x > 900 || es_x < 50) dx = dx*(-1);
	
	es_x = es_x+rn*dx+3*sin(degree/57.29)-5*cos(degree*2/57.29);
	}
}

void enemyShipChange_y() // enemy ship moves down y axis at a const speed
{
	if (display!=1)
	{
	int static degree = 0;
	degree = (degree+10)%360;
	
	
	//es_y = es_y-dy+2*sin(degree*2/57.29);
	//if(es_y<=400 && es_y>375) es_y = es_y-dy;// increases speed
	//if(es_y<=375 ) es_y = es_y-dy; // not dependent on time, need to change later :'(
	}
	else {
	int static degree = 0;
	degree = (degree+10)%360;
	
	
	es_y = es_y-dy+2*sin(degree*2/57.29);
	if(es_y<=400 && es_y>375) es_y = es_y-dy;// increases speed
	if(es_y<=375 ) es_y = es_y-dy; // not dependent on time, need to change later :'(
	}
	
}





int main()
{
	
	
	//if(display == 1 ||display==0 ||display==5){                // 
		iSetTimer(100,missle);
		iSetTimer(1000, weaponCoolingSystem_0);
		//iSetTimer(100,control_r);
	
		//{
		iSetTimer(90,enemyShipChange_x);
		iSetTimer(200,enemyShipChange_y);
		//}
		iSetTimer(50, iUserScore);
	//}
	
	iInitialize(1300,690,"Jaxon-The Survivor");
	//getch();
	return 0;
}