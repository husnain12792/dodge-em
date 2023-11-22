#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include<string>
#include <string.h>
#include<cmath>	


#include <iostream>// for basic math functions such as cos, sin, sqrt

using namespace std;
/******************************************************************************drawing the parts of oppnent inglobal**********************************************************************************
*
*
********************************************************************************//////////////////////////////////****************************************************************************/	
	float a =310;
	float b =20; 
	float w = 10; 
	float h = 5;
	float* color = colors[BLUE_VIOLET];
	float r = 5.0;
/******************************************************************************drawing the parts of owm car in global*******************************************************************************
*
*
********************************************************************************//////////////////////////////////****************************************************************************/	
	// own car   
	float x=470; 
	float y=50; 
	float width = 10; 
	float height = 5;
	float* colour = colors[YELLOW];   
	float radius = 5.0;
/**********************************************DECLARING BOOOLEAN,INTEGER AND CHARACTER VARIABLES DUNESSACITY**************************************************************************************
*																								  *
*																								  *
***************************************************************************************************************************************************************************************************/
bool b1=false,b2=false,b3=false,b4,menu=true,back=false,HELP=false;
int number,q=1,lives=3,level=1,key,run,speed=5,W=1,E=1050;

char option;
string name,scores,quit,help,j;
/*************************************************************THIS FUNCTION DETERMINES THE SIZE OF CANVAS**************************************************************************************
*																							      *
***********************************************************************************************************************************************************************************************	*/
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*******************************************************************THIS FUNCTIONS DISPLAY THE COMPONENTS OF GAME*********************************************************************************
*
****************************************************************************************************************************************************************************************************/
void GameDisplay()/**/{

/**************************************************************************DRAWING ARRAY FOR FOOD*************************************************************************************************/
bool score[800][800];


/*****************************************************************************MAKING LEVELS******************************************************************************************/
if(run==64)
{


	for(int i=0;i<800;i++)
	{
		for(int y=0;y<800;y++)
		{
			score[i][y]=false;
		}
	}
}
if(run==128)
{


	for(int i=0;i<800;i++)
	{
		for(int y=0;y<800;y++)
		{
			score[i][y]=false;
		}
	}
}

/*********************************************************************************************************************************************************************************************/



		// set the backgrond color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.



/***************************************************************************KAING BACKGROUND COLOUR********************************************************************************************/

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// calling some functions from util.cpp file to help students

	//Square at 400,20 position
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Square at 250,250 position
	//Display Scorehow to make pacman gamhow to make pacman game in c++e in c++
	DrawString( 140, 900,name, colors[MISTY_ROSE]);
	DrawString( 50, 900,"hellow : ", colors[MISTY_ROSE]);
	
	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 820 , 790, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(450,450,400,colors[MISTY_ROSE]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	
/******************************************************************************************DRAWING MENU*******************************************************************************
*																						     *
**************************************************************************************************************************************************************************************/
if(menu==true)
{
	DrawString( 350,  490,"START GAME", colors[WHITE]); 
	DrawString( 390,  430,"HELP" , colors[WHITE]);
	//DrawString(400,480,"pause" ,colors[WHITE]);
	DrawString( 390,  390,"quite" , colors[WHITE]);
	DrawRectangle(10,10,20,1020,colors[WHITE]);
	DrawRectangle(800,10,20,1020,colors[PURPLE]);

	//DrawRectangle(10,1020,20,1020,colors[WHITE]);	
}

/**********************************************************************************help menu instructions for opponent car*************************************************************
*																						      *
**************************************************************************************************************************************************************************************/
else if (HELP==true)
{
DrawString( 700,  90,"BACK" , colors[WHITE]);
DrawString( 140, 1000,"INSTRUCTIONS", colors[MISTY_ROSE]);
DrawString( 40, 700,"YELLOW CAR IS OF", colors[MISTY_ROSE]);
DrawString( 80, 650,"OPPONENT", colors[MISTY_ROSE]);
	float a =100;
	float b= 770; 
	float w = 10; 
	float h = 5;
	float* color = colors[BLUE_VIOLET];
	float r = 5.0;

	DrawRoundRect(a,b,w,h,colour,r); // bottom left tyre
	DrawRoundRect(a+w*3,y,w,h,colour,r); // bottom right tyre
	DrawRoundRect(a+w*3,b+h*4,w,h,colour,r); // top right tyre
	DrawRoundRect(a,b+h*4,w,h,colour,r); // top left tyre
	DrawRoundRect(a, a+h*2, w, h, colour, r/2); // body left rect
	DrawRoundRect(a+w, b+h, w*2, h*3, colour, r/2); // body center rect
	DrawRoundRect(a+w*3, b+h*2, w, h, colour, r/2); // body right rect



	int gap_t = 0;   
	int na = 80;
	int nb = 730;
	int nw = 100/2 - gap_t/2; // half width
	int nh = 10;
	float *ncolour = colors[YELLOW];
	DrawRectangle(na, nb, nw, nh, ncolour); // bottom left
	DrawRectangle(na + nw + gap_t, nb, nw, nh, ncolour); // bottom right
	DrawRectangle(na+nw*2+gap_t, nb+nh, nh*2, nw, ncolour); // right down
	DrawRectangle(na+nw*2+gap_t, nb+nh+nw+gap_t, nh*2, nw, ncolour); // right up
	DrawRectangle(na + nw + gap_t, nb+110, nw, nh, ncolour); // top left
	DrawRectangle(na, nb+110, nw , nh, ncolour); // top right
	DrawRectangle(na-nh*2, nb+nh+nw+gap_t, nh*2, nw, ncolour); // left up
	DrawRectangle(na-nh*2, nb+nh, nh*2, nw, ncolour); // left down
/*************************************************help menu instructions for own car******************************************************
*																	   *
*******************************************************************************************************************************************/




DrawString( 580, 700,"PURPLE CAR IS YOUR", colors[MISTY_ROSE]);
DrawString( 660, 650,"OWN", colors[MISTY_ROSE]);



	float x=720; 
	float y=770; 
	float width = 10; 
	float height = 5;
	float* colour = colors[YELLOW];   
	float radius = 5.0;


	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect




	int gap_turn = 0;
	int sx = 680;
	int sy = 730;
	int swidth = 100/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BLUE_VIOLET];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+110, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+110, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down




DrawString( 10, 500,"LIVES:", colors[MISTY_ROSE]);
DrawString( 120, 470,"THERE ARE THREE LIVES", colors[MISTY_ROSE]);
DrawString( 450, 470,"YOU HAVE TO SAVE YOURSELF", colors[MISTY_ROSE]);
DrawString( 50, 440,"FROM STRIKING.ONE TIME YOU STRIKE YOU LOSE ONE LIFE", colors[MISTY_ROSE]);
DrawString( 50, 410,"YOUR UP ,DOWN ,LEFT AND RIGHT ARE WORKING ONLY IN GAP", colors[MISTY_ROSE]);
DrawString( 380, 380,"TURNS", colors[MISTY_ROSE]);
DrawString( 10, 330,"LEVELS:", colors[MISTY_ROSE]);
DrawString( 130, 290,"THERE ARE THREE LEVELS", colors[MISTY_ROSE]);
DrawString( 470, 290,"WHEN YOU COLLECT ALL THE  ", colors[MISTY_ROSE]);
DrawString( 130, 250,"FRUITS YOU REACH NEXT LEVEL", colors[MISTY_ROSE]);
DrawString( 10, 210,"GREETINGS :", colors[MISTY_ROSE]);
DrawString( 230, 190,"BEST OF LUCK :", colors[MISTY_ROSE]);
}

//***********************************************************MENU END*******************************************************************************************************	
	
/******************************************************************DRAWING ARENA FOR THE TRACKS***********************************************************************/



else{// Drawing Arena
	int gap_turn = 120;
	int sx = 20;
	int sy = 10;
	int swidth = 800/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[BROWN];
	float radius = 5.0;
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+810, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+810, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth, scolor); // left up
	DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
	
	// Drawing Arena
	int gaptun = 120;   
	int qa = 120;
	int qb = 110;
	int qw = 600/2 - gaptun/2; // half width
	int qh = 10;
	float *qcolor = colors[BROWN];
	DrawRectangle(qa, qb, qw, qh, qcolor); // bottom left
	DrawRectangle(qa + qw + gaptun, qb, qw, qh, qcolor); // bottom right
	DrawRectangle(qa+qw*2+gaptun, qb+qh, qh*2, qw, qcolor); // right down
	DrawRectangle(qa+qw*2+gaptun, qb+qh+qw+gaptun, qh*2, qw, qcolor); // right up
	DrawRectangle(qa + qw + gaptun, qb+610, qw, qh, qcolor); // top left
	DrawRectangle(qa, qb+610, qw , qh, qcolor); // top right
	DrawRectangle(qa-qh*2, qb+qh+qw+gaptun, qh*2, qw, qcolor); // left up
	DrawRectangle(qa-qh*2, qb+qh, qh*2, qw, qcolor); // left down

// Drawing Arena
	int gp_tun = 120;   
	int ua = 220;
	int ub = 210;
	int uw = 400/2 - gp_tun/2; // half width
	int uh = 10;
	float *ucolour = colors[BROWN];
	DrawRectangle(ua, ub, uw, uh, ucolour); // bottom left
	DrawRectangle(ua + uw + gp_tun, ub, uw, uh, ucolour); // bottom right
	DrawRectangle(ua+uw*2+gp_tun, ub+uh, uh*2, uw, ucolour); // right down
	DrawRectangle(ua+uw*2+gp_tun, ub+uh+uw+gp_tun, uh*2, uw, ucolour); // right up
	DrawRectangle(ua + uw + gp_tun, ub+410, uw, uh, ucolour); // top left
	DrawRectangle(ua, ub+410, uw , uh, ucolour); // top right
	DrawRectangle(ua-uh*2, ub+uh+uw+gp_tun, uh*2, uw, ucolour); // left up
	DrawRectangle(ua-uh*2, ub+uh, uh*2, uw, ucolour); // left down
	

// Drawing Arena
	int gap_trn = 120;   
	int ea = 330;
	int eb = 315;
	int ew = 200/2 - gap_trn/2; // half width
	int eh = 10;
	float *ecolour = colors[BROWN];
	DrawRectangle(ea, eb, ew, eh, ecolour); // bottom left
	DrawRectangle(ea +ew + gap_trn, eb, ew, eh, ecolour); // bottom right
	DrawRectangle(ea+ew*2+gap_trn, eb+eh, eh*2, ew, ecolour); // right down
	DrawRectangle(ea+ew*2+gap_trn, eb+eh+ew+gap_trn, eh*2, ew, ecolour); // right up
	DrawRectangle(ea + ew + gap_trn, eb+210, ew, eh, ecolour); // top left
	DrawRectangle(ea,eb+210, ew , eh, ecolour); // top right
	DrawRectangle(ea-eh*2, eb+eh+ew+gap_trn, eh*2, ew, ecolour); // left up
	DrawRectangle(ea-eh*2, eb+eh, eh*2, ew, ecolour); // left down
//Drawing Arena
	/*int gap_t = 0;   
	int na = 370;
	int nb = 360;
	int nw = 100/2 - gap_t/2; // half width
	int nh = 10;
	float *ncolour = colors[BROWN];
	DrawRectangle(na, nb, nw, nh, ncolour); // bottom left
DrawRectangle(na + nw + gap_t, nb, nw, nh, ncolour); // bottom right
	DrawRectangle(na+nw*2+gap_t, nb+nh, nh*2, nw, ncolour); // right down
	DrawRectangle(na+nw*2+gap_t, nb+nh+nw+gap_t, nh*2, nw, ncolour); // right up
	DrawRectangle(na + nw + gap_t, nb+110, nw, nh, ncolour); // top left
	DrawRectangle(na, nb+110, nw , nh, ncolour); // top right
	DrawRectangle(na-nh*2, nb+nh+nw+gap_t, nh*2, nw, ncolour); // left up
	DrawRectangle(na-nh*2, nb+nh, nh*2, nw, ncolour); // left down*/

	

	//drawing opponent car other is in upper side
/******************************************************THE ARENA IS TILL UPWARD FROM IT*******************************************************/



/*********************************************************DRAWING THE CARS OF OPPONENT AND OWN UPPER PART IS IN GLOBAL*********************************************/
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect	


	// drawing own car upper part is in global scope

	DrawRoundRect(a,b,w,h,colour,r); // bottom left tyre
	DrawRoundRect(a+w*3,b,w,h,colour,r);
	DrawRoundRect(a+w*3,b+h*4,w,h,colour,r); // top right tyre
	DrawRoundRect(a,b+h*4,w,h,colour,r);
	DrawRoundRect(a, b+h*2, w, h, colour, r/2); // body left rect; // body left rect
	DrawRoundRect(a+w, b+h, w*2, h*3, colour, r/2); // body center rect
	DrawRoundRect(a+w*3, b+h*2, w, h, colour, r/2); // body right rect
/**************************************************************************************************************************************************************************/

/******************************************************************************************drawing food*************************************************************************/
	for(int row=60;row<=780;row+=100)
	{
		for(int column=60;column<=780;column+=100)
		{
			if(row>=400 && row<=450)
			{
			row+=10;
			}
				if((row>=x-15 &&row<=x+35) && (column>=y-23 &&column<=y+35))
				{
					if (score[row][column]!=true)
						{
						run++;
						score[row][column]=true;
						}
						}
							if(score[row][column]!=true)
								{
								DrawSquare(row,column,10,colors[PURPLE]);
								}


								}
								string points;
								points=to_string(run);
								DrawString(390,900,"score="+points,colors[MISTY_ROSE]);
								}
									if (run==64)
									{
									DrawString( 350,  490," CONGRATULATIONS...!! YOU WON", colors[MISTY_ROSE]); 
									}
/**************************************************************************************************************************************************************************
/*******************************************MATCHING COORDINATES for opponent car**************************************************************************************/

	if(a<=310&&a>30&&b<=30&&b<=70)
	{

		a=a-4;
	}

		else if(a>=30&&a<70&&b>=20&&b<=785)
		{
			b=b+4;
		}

		else if(a>=30&&a<=150&&b>=350&&b<490) //it is not the final condition(arbitrary)
		{
		a=a-4;
		}
		else if(a>=380&&a<=470&&b<=790&&b>=640)
		{
		b=b-4;
		}		//just trying
																
		else if(a>=23&&a<780&&b>=750&&b<=792)
		{
		a=a+4;
		}
		else if(b<=790&&b>=22&&a>750&&a<785)
		{
		b=b-4;
		}
		else if(a>=400&&a<=785&&b<=22&&b<=70)
		{
		a=a-4;
		}
		else if (a>=320&&a<=400&&b>=20&&b<=120)
		{
		b=b+4;//aaaaaa
		}	
		else if(a<=400&&a>120&&b>=120&&b<210)
		{
		a=a-4;
		}
		else if(a>=120&&a<130&&b<=670&&b>=20)
		{
		b=b+4;
		}
				
		else if(a>=90&&a<=648&&b>620&&b<=680)
		{
		a=a+4;
		}
		else if(a>=540&&a<=680&&b<=680&&b>=140)
		{
		b=b-4;
		}

		else if(a<=790&&a>=440&&b>=120&&b<=200)	
		{
		a=a-4;
		}
		else if (a<=440&&a<=590&&b>=30&&b<=220)
		{
		b=b-4;
		}
		else if(a<=440&&a>=310&&b>=22&&b<=140)
		{

		a=a-4;
		}
		else if(a>=400&&a<=440&&b>=30&&b<=120)
		{

		a=a-4;
		}
/***************************************************************** SHOWING STRING LIVES*******************************************************************************************************/
string hope;
hope=to_string(lives);
DrawString(590,900,"lives="+hope,colors[MISTY_ROSE]);


//*****************************************************************.......LEVEL......*********************************************************************......................****************
//for level
string stage;
stage=to_string(level);
DrawString(750,900,"level="+stage,colors[MISTY_ROSE]);
/***********************************************************************FOR COLLISION*********************************************************************************************************/

	if (x==a)
	{
	x=470;
	a=310;
	y=50;
	b=20;
	lives=lives-1;
	}
			if(lives==2)
			{
			DrawString( 350,  490," be careful", colors[MISTY_ROSE]); 
			}
				else if(lives==1)
				{
				DrawString( 350,  490," LAST chance", colors[MISTY_ROSE]);
				}
					if(lives==0)
					{

					DrawString( 350,  490," TRY AGAIN..!! BEST OF LUCK", colors[MISTY_ROSE]); 
					exit(1);
					}
/*****************************************************************************LEVEL2******************************************************************************************/
	if (run==64)
	{
	level=2;
	lives=3;
	}
/*************************************************************************************LEVEL 3***********************************************************************************/
		if(run==128)
		{	
			level=3;
		}
		if(level==3)
		{


			if(a<=310&&a>30&&b<=30&&b<=70)
			{

				a=a-6;
			}

				else if(a>=30&&a<70&&b>=20&&b<=785)
				{
					b=b+6;
				}

				else if(a>=30&&a<=150&&b>=350&&b<490) //it is not the final condition(arbitrary)
				{
					a=a-6;
				}
				else if(a>=380&&a<=470&&b<=790&&b>=640)
				{
				b=b-6;
				}		//just trying
																
				else if(a>=23&&a<780&&b>=750&&b<=792)
				{
				a=a+6;
				}
				else if(b<=790&&b>=22&&a>750&&a<785)
				{
				b=b-6;
				}
				else if(a>=400&&a<=785&&b<=22&&b<=70)
				{
				a=a-6;
				}
				else if (a>=320&&a<=400&&b>=20&&b<=120)
				{
				b=b+6;//aaaaaa
				}
											
				else if(a<=400&&a>120&&b>=120&&b<210)
				{
				a=a-6;
				}
				else if(a>=120&&a<130&&b<=670&&b>=20)
				{
				b=b+6;
				}	
				
				else if(a>=90&&a<=648&&b>620&&b<=680)
				{
				a=a+6;
				}
				else if(a>=540&&a<=680&&b<=680&&b>=140)
				{
				b=b-6;
				}

				else if(a<=790&&a>=440&&b>=120&&b<=200)
				{
				a=a-6;
				}
				else if (a<=440&&a<=590&&b>=30&&b<=220)
				{
				b=b-6;
				}
				else if(a<=440&&a>=310&&b>=22&&b<=140)
				{

				a=a-6;
				}
				else if(a>=400&&a<=440&&b>=30&&b<=120)
				{

				a=a-6;
				}

}

}	
	glutPostRedisplay();	
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
	
}



void NonPrintableKeys(int key, int x, int y) {
/*******************************************MAKING THE CONDITIONS OF CAR ACCORDING TO THE CONDITIONS OF MOUSE*********************************************************
*																				     *
**********************************************************************************************************************************************************************/

	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
	        b1=true;
	// what to do when left key is pressed...
	}
else
{
b1=false;
}







if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
b2=true;	//x=x+100;
		

	}
else
{
 b2=false;
}






if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			b3=true;	//x=x+100;

}
else
{
	b3=false;
}

	 if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		   b4=true;
	}
	else
{
b4=false;
}



	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	glutPostRedisplay();
}
/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
/********************************************IF P PRESSED THEN PAUSE THE MENU******************************************************
*																  *
**********************************************************************************************************************************/

if(key=='p'||key=='P')
{
sleep(q);
menu=true;
}
	if (key == 27/* Escape key ASCII*/) {
		exit(1);
}
	

	if (key == 'b' || key == 'B')
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
} 

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
/*****************************************************************************************<>for own car<>*********************************************************************************************
*
*
*
*****************************************************************************************************************************************************************************************************/
	if(x>=470&&x<760&&y<=50)
	{
	x=x+5;
	}
		else if(x>=700&&x<=780&&y>=40&&y<=360)
		{
		y=y+5;
		}
		else if(b1==true&&x<=780&&x>=680&&y>=360&&y<=480)
		{
		x=x-5;
		}

	
		else if(b1==true&&x<=680&&x>=580&&y>=360&&y<=480)
		{
		x=x-5;
		}

		else if(x<=660&&x>=600&&y>=360&&y<=660)
		{
		y=y+5;
		}


		else if(b3==true&&x>=430&&x<=470&&y>=40&&y<=250)
		{
		y=y+5;
		}
		else if(x>=400&&x<=560&&y>200&&y<=300)
		{
		x=x+5;
		}
		else if(x>=560&&x<=600&&y>=200&&y<=570)
		{
		y=y+5;
		}

		else if(x>=390&&x<=440&&y>=150&&y<=370)
		{	
		y=y-5;
		}
		else if(b4==true&&x>=390&&x<=440&&y<150&&y>=50)
		{
		y=y-5;
		}

		else if(x<=600&&x>=450&&y>=550&&y<=580)
		{
		x=x-5;
		}
		else if(b3==true&&x>=360&&x<=450&&y>=550&&y<=680)
		{
		y=y+5;
		}
		else if(x<=450&&x>=250&&y>=550&&y<=580)
		{
		x=x-5;
		}

		else if(b1==true&&x>=50&&x<230&&y>=360&&y<=450)	
		{
		x=x-5;
		}
		else if(b2==true&&x<=740&&x<780&&y>=360&&y<=490)
		{
		x=x+5;
		}
		else if(b1==true&&x>=50&&x<330&&y>=360&&y<=450)
		{
		x=x-5;
		}

		else if(x<=660&&x>=400&&y>=630&&y<670)
		{
		x=x-5;
		}
		else if(b3==true&&x>=310&&x<=450&&y>600&&y<=760)
		{
		y=y+5;
		}
		else if(b4==true&&x>=310&&x<=410&&y<=680&&y>=570)
		{
		y=y-5;
		}
		else if(b2==true&&x>=340&&x<=670&&y>=640&&y<=680)	
		{
		x=x+5;
		}
		else if(x>=600&&x<=680&&y>=150&&y<=680)
		{
		y=y-5;
		}
		else if(b1==true&&x<=680&&x>=150&&y>=100&&y<=230)
		{
		x=x-5;
		}
		else if(x>=100&&x<=200&&y>=100&&y<380)
		{
		y=y+5;
		}
		else if(x>=100&&x<=200&&y>=380&&y<680)
		{
		y=y+5;
		}

		else if(x<=600&&x>=100&&y<=680&&y>=600)
		{
		x=x+5;
		}


		else if(x>=200&&x<=250&&y>=250&&y<=600)
		{
		y=y-5;
		}
		 else if(x>=200&&x<=400&&y>=200&&y<=300)
		{
		x=x+5;
		}


		else if(x<=380&&x>=50&&y<780&&y>=730)
		{
		x=x-5;
		}
		else if(x<=400&&x>=140&&y>=630&&y<670) 
		{
		x=x-5;
		}
		else if(x>=135&&x<=140&&y<700&&y>=160)
		{
		y=y-5;
		}
		else if(b4==true&&x>=330&&x<=400&&y<=780&&y>=680)
		{
		y=y-5;
		}
		else if(x>=100&&x<=640&&y<=230&&y>=150)
		{
		x=x+5;
		}

		else if(x>730&&x<=780&&y>=360&&y<=760)
		{
		y=y+5;
		}
		else if(x>=50&&x<=780&&y<=780&&y>=720)
		{
		x=x-5;
		}
		else if(x>=30&&x<=100&&y>=440&&y<=780)
		{
		y=y-5;
		}
		else if(x>=30&&x<=100&&y<=440&&y>=50)
		{
		y=y-5;
		}
		if(x>40&&x<470&&y<=50)
		{
		x=x+5;
		}
		else if(b3==true&&x>=305&&x<=400&&y<=40&&y<=120)
		{
		y=y+5;
		}
		else if(b1==true&&y>=360&&y<=460&&x>=360&&y<=420)
		{
		x=x-5;
		}
		else if(x>=300&&x<=400&&y>=360&&y<=480)
		{
		y=y+5;	
		}
		else if(x>=290&&x<=440&&y>=460&&y<=500)
		{
		x=x+5;
		}
		else if(x>=400&&x<=500&&y>=360&&y<520)
		{
		y=y-5;
		}
		else if(x>=300&&x<=500&&y<=356&&y>=350)
		{
		x=x-5;
		}
		else if(b2==true&&y>=360&&x<=750&&x>=320&&y<=460)
		{
		x=x+5;
		}





	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(10.0, Timer, 0);
glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */


void MousePressedAndMoved(int x, int y) {


	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.

 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 **/



void MouseClicked(int button, int state, int x, int y) {
     /************************************MOVING MOUSE ACCORDING TO THE CONDITIONS OF MOUSE********************************************************
*																		  *
***************************************************************************************************************************************************/

			if (button == GLUT_LEFT_BUTTON&&x>=350&&x<=500&&y>=450&&y<=540){
cout << GLUT_DOWN << " " << GLUT_UP << endl;
menu=false;
}
if(button == GLUT_LEFT_BUTTON&&x>=385&&x<=450&&y>540&&y<=600){
menu=false;
HELP=true;

}
else if(x>=390&&x<=495&&y>=615&&y<=650){
exit(1);
}
if(button == GLUT_LEFT_BUTTON&&x>=700&&x<=770)
{
menu=true;
back=false;
}
	
		

	 else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{

	}
//DrawString( 350,  490,"Press1. START GAME", colors[WHITE]); 

	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {


	/*******************************************ASKING THE USER TO ENTER HIS NAME**********************************************************
	 *																      *
	 **************************************************************************************************************************************/
	cout<<"enter your name"<<endl;
	cin>>name;





/*******************************i have changed the height of board from840 to 1040 to adjust the screen********************************************
*																		  *
***************************************************************************************************************************************************/




	int width = 840, height = 1040;// // i have set my window size to be 800 x 600 idhr 840 tha
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("HELLOW USER"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(10.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();

	return 1;
}
#endif /* AsteroidS_CPP_ */

