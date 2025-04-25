#include<stdio.h>
#include<graphics.h>
#include<dos.h>
 void bla(int x0, int y0, int x1, int y1){
 	int dx,dy,p,x,y,i;
 	dx=abs(x1-x0);
 	dy=abs(y1-y0);
 	
 	p=2*dy-dx;
 	x=x0;
 	y=y0;
 	
 	int gd=DETECT, gm;
 	initgraph(&gd, &gm, NULL);
 	// Set the background color to WHITE
    setbkcolor(WHITE);

    // Clear the screen to apply the background color
    cleardevice();
 	
 	putpixel(x,y,BLUE);
 	
 	for(i=0;i<dx;i++){
 		if(p<0){
 			p=p+2*dy;
		 } else {
		 	p= p+2*dy-2*dx;
		 	y++;
		 }
		 x++;
		 putpixel(x,y,GREEN);
	 }
	 
	 delay(10000);
	 closegraph();
 }
 
 int main(){
 	int x0,x1,y0,y1;
 	printf("\t Implementation of Bresenham's Line Algorithm \n");
 	printf("Enter the coordinates of the first point(x0,y0):");
 	scanf("%d%d",&x0,&y0);
 	printf("Enter the coordinates of the second point(x1,y1):");
 	scanf("%d%d",&x1,&y1);
 	
 	bla(x0,y0,x1,y1);
 	 return 0;
 }
