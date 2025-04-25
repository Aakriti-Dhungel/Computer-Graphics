#include <stdio.h>
#include <graphics.h>
#include <math.h>

//Function to calculaye a point on the Bezier curve
void drawBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3)
{
	float t;
	int x,y;
	
	//Loop through values of t from 0 to 1 in small steps
	for (t = 0.0; t <= 1.0; t += 0.002)
	{
		float B0 = pow(1 - t, 3);
		float B1 = 3 * t * (1 - t) * (1 - t);
		float B2 = 3 * t * t * (1 - t);
		float B3 =  t * t * t;
		
		//Compute x and y using blending functions
		x = (int)(B0 * x0 + B1 * x1 + B2 * x2 + B3 * x3);
		y = (int)(B0 * y0 + B1 * y1 + B2 * y2 + B3 * y3);
		
		putpixel(x, y, WHITE); //Draw the point
	}
}
int main()
{
	int gd = DETECT, gm;
	
	//Initialize graphics mode
	initgraph(&gd, &gm, "");
	
	//Define control points
	int x0 = 100, y0 = 300;
	int x1 = 200, y1 = 100;
	int x2 = 300, y2 = 400;
	int x3 = 400, y3 = 200;
	
	//Draw the control polygon
	setcolor(YELLOW);
	line(x0, y0, x1, y1);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	
	//Draw the Bezier curve
	setcolor(WHITE);
	drawBezierCurve(x0, y0, x1, y1, x2, y2, x3, y3);
	
	getch(); //Wait for user input
	closegraph(); //Close graphics mode
	return 0;
}
