#include<stdio.h>
#include<graphics.h>
 void plotPoints(int xc, int yc, int x, int y){
 	putpixel(xc+x,yc+y,BLACK);
	putpixel(xc-x, yc+y,BLACK);
	putpixel(xc+x, yc-y,BLACK);
	putpixel(xc-x, yc-y,BLACK);
	putpixel(xc+y,yc+x,BLACK);
	putpixel(xc-y, yc+x,BLACK);
	putpixel(xc+y, yc-x,BLACK);
	putpixel(xc-y, yc-x,BLACK);
 }

 void drawCircle(int xc, int yc ,int r){
	int x=0,y=r;
	int p=1-r;
	plotPoints(xc,yc,x,y);

	while(x<=y){
		x++;
		if(p< 0){
			p+=2*x+1;
		}else{
			y--;
			p+=2*(x-y)+1;
		}
		plotPoints(xc,yc,x,y);
	}
 }
 int main(){
	int xc,yc,r;
	printf("ENter the center of the circle:\n");
	scanf("%d%d",&xc,&yc);
	printf("Enter the radius:");
	scanf("%d",&r);

	int gd = DETECT , gm;
	initgraph(&gd,&gm,NULL);
	// Set the background color to WHITE
    setbkcolor(WHITE);
    
      // Clear the screen to apply the background color
    cleardevice();
 	
	drawCircle(xc,yc,r);
	delay(10000);
	closegraph();
	return 0;
 }
