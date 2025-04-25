#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;
void floodFill4(int x,int y,int fill_color,int old_color){
	int current_color=getpixel(x,y);
	if(current_color==old_color){
		putpixel(x,y,fill_color);
		floodFill4(x+1,y,fill_color,old_color);
		floodFill4(x-1,y,fill_color,old_color);
		floodFill4(x,y+1,fill_color,old_color);
		floodFill4(x,y-1,fill_color,old_color);
	}
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int points[]={200,100,
				250,200,
				225,200,
				175,200,
				150,150,
				200,100
				};
	drawpoly(6,points);
	floodFill4(200,150,YELLOW,BLACK);
	delay(10000);
	closegraph();
	return 0;
}
