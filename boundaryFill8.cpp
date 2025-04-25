#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;
void boundaryFill8(int x,int y,int fill_color,int boundary_color){
	int current_color=getpixel(x,y);
	if(current_color!=boundary_color && current_color!=fill_color){
		putpixel(x,y,fill_color);
		boundaryFill8(x+1,y,fill_color,boundary_color);
		boundaryFill8(x-1,y,fill_color,boundary_color);
		boundaryFill8(x,y+1,fill_color,boundary_color);
		boundaryFill8(x,y-1,fill_color,boundary_color);
		boundaryFill8(x+1,y+1,fill_color,boundary_color);
		boundaryFill8(x-1,y+1,fill_color,boundary_color);
		boundaryFill8(x+1,y-1,fill_color,boundary_color);
		boundaryFill8(x-1,y-1,fill_color,boundary_color);
	}
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	rectangle(100,100,200,200);
	boundaryFill8(150,150,GREEN,WHITE);
	delay(10000);
	closegraph();
	return 0;
}
