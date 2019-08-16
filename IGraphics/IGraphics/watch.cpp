# include "iGraphics.h"
#include<math.h>
#include<time.h>

double o,x=500,y=360+250,sx,sy,p;
double xm=500,ym=360+220,mx,my,pm;
double xh=500,yh=360+200,hx,hy,ph,H,M,S;
int i;
//below lies my parameters, sir used y, i, p, must not use them to avoid problems
//double xh1=185,y1=297.5,xh2=270,xm1=420,xm2=505,xs1=655,xs2=740;
double dx1=75,dy1=125,dx2=70,dy2=55,dx3=65,dy3=60,dx4=60,dy4=120,dy5=115;
int h1,h2,Hour,m1,m2,Minute,s1,s2,Second;
double hx1=185,Y1=297.5,hx2=270,mx1=420,mx2=505,sx1=655,sx2=740,mx1_1=mx1+5, mx2_1=mx2+5,y5=Y1+5,y60=Y1+60,y65=Y1+65,sx1_1=sx1+5, sx2_1=sx2+5;
char f;
void iAnalog_clock()
{
	
	iClear();
	iSetColor(10,10,10);
	iFilledCircle(500,360,300);//Large
	iSetColor(0,255,0);
	iCircle(500,360,305);//out
	iSetColor(0,0,255);
	iCircle(500,360,275);//nextout
	iSetColor(255,0,0);
	for (i=1,o=(6/57.29);i<=60;i++,o+=(6/57.29))
	{   if(i%5!=0)
			iFilledCircle(500+295*cos(o),360+295*sin(o),4);
		if (i%5==0)
			iFilledCircle(0,0,0);
	}


	iSetColor(255,0,0);
	iLine(500,360,x,y);///second
	iSetColor(0,120,120);
	iLine(500,360,xm,ym);///minit
	iSetColor(20,200,40);
	iLine(500,360,xh,yh);//HR
	iSetColor(255,0,0);
	iText(500+244,360-150,"IV");//4(500+259,360-150)point
    iText(500+145,360-256,"V");//	iFilledCircle(500+150,360-260,5);//60
	iText(495,60,"VI");//iFilledCircle(500,65,5);//lower
	iText(500-155,360-257,"VII");//iFilledCircle(500-150,360-260,5);//120
	iText(200,360,"IX");//iFilledCircle(205,360,5);//left
	iText(500-255,360+145,"X");//iFilledCircle(500-260,360+150,5);//150
	iText(500+240,360+150,"II");//iFilledCircle(500+259,360+150,5);//330
	iText(500+140,360+252,"I");//	iFilledCircle(500+150,360+260,5);//300
	iText(490,650,"XII");//	iFilledCircle(500,655,5);//upper
	iText(777,360,"III");//	iFilledCircle(795,360,5);//right
	iText(500-150,360+250,"XI");//	iFilledCircle(500-150,360+260,5);//240
	iText(500-260,360-150,"VIII");//	iFilledCircle(500-260,360-150,5);//210
    iSetColor(20,50,210);
	iFilledCircle(500,360,20);//small

}
void iDigital_clock()
{

	iClear();
	iSetColor(0,0,0);
	//iText(50, 50, "Press p for pause, r for resume, END for exit.");
	iFilledRectangle(0,0,1000,720);
	//iText(10,10,"Please press 'a' for analog clock or 'd' for digital clock");
	iSetColor(50,100,255); //100, 255, 50
	//iSetColor(255, 255, 255);
	iText(50, 50,"Please press 'a' for analog clock or 'd' for digital clock." );
	iText(50,20,"Homework by Qazi Fahim Farhan, 1405052.");
	iFilledRectangle(375,322.5,15,25);
	iFilledRectangle(375,372.5,15,25);
	iFilledRectangle(610,322.5,15,25);
	iFilledRectangle(610,372.5,15,25);
	iFilledRectangle(185,297.5,75,125);   
	iFilledRectangle(270,297.5,75,125);
    iFilledRectangle(420,297.5,75,125);
	iFilledRectangle(505,297.5,75,125);
	iFilledRectangle(655,297.5,75,125);
	iFilledRectangle(740,297.5,75,125);
	iSetColor(0,0,0);
	h1=Hour/10;
	h2=Hour%10;
	
	if(h1==0)
	{
		iFilledRectangle(190,302.5,dx3,dy5);
	}
	else if(h1==1)
	{
		iFilledRectangle(185,297.5,dx2,dy1);
	}
	else if(h1==2)
	{
		iFilledRectangle(190,302.5,dx2,dy2);
		iFilledRectangle(185,362.5,dx2,dy2);
	}
	if(h2==0)
	{
		iFilledRectangle(275,302.5,dx3,dy5);
	}
	else if(h2==1 )
	{
		iFilledRectangle(270,297.5,dx2,dy1);
	}
	else if(h2==2 )
	{
		
		iFilledRectangle(275,302.5,dx2,dy2);
		iFilledRectangle(270,362.5,dx2,dy2);
	}

	else if(h2== 3)
	{
		iFilledRectangle(270,362.5,dx2,dy2);
		iFilledRectangle(270,302.5,dx2,dy2);
	}

	else if(h2==4 )
	{
		iFilledRectangle(270,297.5,dx2,dy3);
		iFilledRectangle(275,362.5,dx3,dy3);
	}

	else if(h2== 5)
	{
		iFilledRectangle(270,302.5,dx2,dy2);
		iFilledRectangle(275,362.5,dx2,dy2);
	}

	else if(h2==6 )
	{
		iFilledRectangle(275,357.5,dx2,dy2);
		iFilledRectangle(275,302.5,dx3,dy2);

	}

	else if(h2== 7)
	{
		iFilledRectangle(270,297.5,dx2,dy4);
	}

	else if(h2== 8)
	{
		iFilledRectangle(275,302.5,dx3,dy2);
		iFilledRectangle(275,362.5,dx3,dy2);
	}

	else if(h2== 9)
	{
		iFilledRectangle(270,302.5,dx2,dy2);
		iFilledRectangle(275,362.5,dx3,dy2);
	}
	// minute code
	m1=Minute/10;
	m2=Minute%10;
	if(m2==0 )
	{
		iFilledRectangle(mx2_1,y5,dx3,dy5);
	}
	
	else if(m2== 1)
	{
		iFilledRectangle(mx2,Y1,dx2,dy1);
	}
	else if(m2== 2)
	{
		iFilledRectangle(mx2_1,y5,dx2,dy2);
		iFilledRectangle(mx2,y65,dx2,dy2);
	}
	else if(m2== 3)
	{
		iFilledRectangle(mx2,y65,dx2,dy2);
		iFilledRectangle(mx2,y5,dx2,dy2);
	}
	else if(m2== 4)
	{
		iFilledRectangle(mx2,Y1,dx2,dy2);
		iFilledRectangle(mx2_1,y65,dx3,dy3);
	}
	else if(m2== 5)
	{
		iFilledRectangle(mx2,y5,dx2,dy2);
		iFilledRectangle(mx2_1,y65,dx2,dy2);
	}
	else if(m2== 6)
	{
		iFilledRectangle(mx2_1,y65,dx2,dy2);
		iFilledRectangle(mx2_1,y5,dx3,dy2);
	}
	else if(m2== 7)
	{
		iFilledRectangle(mx2,Y1,dx2,dy4);
	}
	else if(m2== 8)
	{
		iFilledRectangle(mx2_1,y5,dx3,dy2);
		iFilledRectangle(mx2_1,y65,dx3,dy2);
	}
	else if(m2== 9)
	{
		iFilledRectangle(mx2,y5,dx2,dy2);
		iFilledRectangle(mx2_1,y65,dx3,dy2);
	}
	if(m1==0 )
	{
		iFilledRectangle(mx1_1,y5,dx3,dy5);
	}
	
	else if(m1== 1)
	{
		iFilledRectangle(mx1,Y1,dx2,dy1);
	}
	else if(m1== 2)
	{
		iFilledRectangle(mx1_1,y5,dx2,dy2);
		iFilledRectangle(mx1,y65,dx2,dy2);
	}
	else if(m1== 3)
	{
		iFilledRectangle(mx1,y65,dx2,dy2);
		iFilledRectangle(mx1,y5,dx2,dy2);
	}
	else if(m1== 4)
	{
		iFilledRectangle(mx1,Y1,dx2,dy2);
		iFilledRectangle(mx1_1,y65,dx3,dy3);
	}
	else if(m1== 5)
	{
		iFilledRectangle(mx1,y5,dx2,dy2);
		iFilledRectangle(mx1_1,y65,dx2,dy2);
	}
	
		//second code
		s1=Second/10;
		s2=Second%10;
	if(s2==0 )
	{
		iFilledRectangle(sx2_1,y5,dx3,dy5);
	}
	
	else if(s2== 1)
	{
		iFilledRectangle(sx2,Y1,dx2,dy1);
	}
	else if(s2== 2)
	{
		iFilledRectangle(sx2_1,y5,dx2,dy2);
		iFilledRectangle(sx2,y65,dx2,dy2);
	}
	else if(s2== 3)
	{
		iFilledRectangle(sx2,y65,dx2,dy2);
		iFilledRectangle(sx2,y5,dx2,dy2);
	}
	else if(s2== 4)
	{
		
		iFilledRectangle(sx2,Y1,dx2,dy2);
		iFilledRectangle(sx2_1,y65,dx3,dy3);
	}
	else if(s2== 5)
	{
		iFilledRectangle(sx2,y5,dx2,dy2);
		iFilledRectangle(sx2_1,y65,dx2,dy2);
	}
	else if(s2== 6)
	{
		iFilledRectangle(sx2_1,y65,dx2,dy2);
		iFilledRectangle(sx2_1,y5,dx3,dy2);
	}
	else if(s2== 7)
	{
		iFilledRectangle(sx2,Y1,dx2,dy4);
	}
	else if(s2== 8)
	{
		iFilledRectangle(sx2_1,y5,dx3,dy2);
		iFilledRectangle(sx2_1,y65,dx3,dy2);
	}
	else if(s2== 9)
	{
		iFilledRectangle(sx2,y5,dx2,dy2);
		iFilledRectangle(sx2_1,y65,dx3,dy2);
	}
	if(s1==0 )
	{
		iFilledRectangle(sx1_1,y5,dx3,dy5);
	}
	
	else if(s1== 1)
	{
		iFilledRectangle(sx1,Y1,dx2,dy1);
	}
	else if(s1== 2)
	{
		iFilledRectangle(sx1_1,y5,dx2,dy2);
		iFilledRectangle(sx1,y65,dx2,dy2);
	}
	else if(s1== 3)
	{
		iFilledRectangle(sx1,y65,dx2,dy2);
		iFilledRectangle(sx1,y5,dx2,dy2);
	}
	else if(s1== 4)
	{
		iFilledRectangle(sx1,Y1,dx2,dy2);
		iFilledRectangle(sx1_1,y65,dx3,dy3);
	}
	else if(s1== 5)
	{
		iFilledRectangle(sx1,y5,dx2,dy2);
		iFilledRectangle(sx1_1,y65,dx2,dy2);
	}
	

}

void iDraw()
{
	if (f=='a')
	{
		iAnalog_clock();
	}
	else if(f=='d')
	{
		iDigital_clock();
	}
	else
	{
		iDigital_clock();
	}
}


void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iKeyboard(unsigned char key)
{
	if(key == 'a' || key == 'A')
	{
		f='a';
	}
	else if (key == 'd' || key == 'D')
	{
		f='d';
	}
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}

void second()
 
{
	  sx=250*cos(p/57.29);
	  sy=250*sin(p/57.29);
	  x=500+sx;
	  y=360+sy;
      p=p-6;
}
void minute()
{
      mx=220*cos(pm/57.29);
	  my=220*sin(pm/57.29);
	  xm=500+mx;
	  ym=360+my;
	  pm=pm-.1;
}
void hour()
{
	hx=200*cos(ph/57.29);
	hy=200*sin(ph/57.29);
	xh=500+hx;
	yh=360+hy;
	ph=ph-1/600;
}


void DigitalClock()

{
	Second++;
	if(Second==60){
		Second=0;
		Minute++;
		if(Minute==60){
			Minute=0;
			Hour++;
			if(Hour==24){
				Hour=0;
			}

		}
	}
}

int main()
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)%24;
	M=ptm->tm_min;
	S=(ptm->tm_sec)+2;


	ph =(3-H)*30.0-30*M/60.0-30*S/3600.0+.1/600+270+90;
     
	pm= (15-M)*6.0-S/60.0+.1+270+90;

	p = (15-S)*6.0+6+270+90;

    second();
    minute();
    hour();

   
	
    iSetTimer(1000,second);
	iSetTimer(1000,minute);
	iSetTimer(1000,hour);//
	//iInitialize(1000, 720, "demo");
	
	// my code
	struct tm*currentTime;
	time(&rawtime);
	currentTime=localtime(&rawtime);
	Hour=currentTime->tm_hour,
		
	Minute=currentTime->tm_min;
	Second=currentTime->tm_sec;
	iSetTimer(1000,DigitalClock);
	iInitialize(1000, 720, "Digital clock by Qazi Fahim Farhan , 1405052");
	//getch();
	return 0;
}	

