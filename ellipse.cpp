#include <stdio.h>
#include <graphics.h>

// Function to plot points considering the 4-way symmetry of the ellipse
void plotPoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, BLACK); // Quadrant 1
    putpixel(xc - x, yc + y, BLACK); // Quadrant 2
    putpixel(xc + x, yc - y, BLACK); // Quadrant 3
    putpixel(xc - x, yc - y, BLACK); // Quadrant 4

} // Function to draw an ellipse using the Midpoint Ellipse Drawing Algorithm
void drawEllipse(int xc, int yc, int rx, int ry)
{
    int x, y;
    float dx, dy, d1, d2;
    x = 0;
    y = ry;

    // initial decision paramenter of region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
    // For region 1
    for (x = 0; dx < dy; x++)
    {
        plotPoints(xc, yc, x, y);

        // checking and updating decision paramenterbased on algorithm
        if (d1 < 0)
        {
            // dx==2*ry*ry*x+2*ry*ry=2*ry*ry*(x+1)
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
            y--;
        }
    }

    // Decision parameter of region 2
    d2 = (ry * ry) * ((x + 0.5) * (x + 0.5)) + (rx * rx) * ((y - 1) * (y - 1))- (rx * rx * ry * ry);;

    // plotting points of region 2
    for (; y >= 0; y--)
    {
        // initialization: (empty) means nothing happens before the loop start. i>e y=last
        plotPoints(xc, yc, x, y);

        // checking and updating decision paramenter based on algorithm
        if (d2 > 0)
        {
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
            x++;
        }
    }
}
int main()
{
    int xc, yc, rx, ry;
    // input the center and the radius of the ellipse
    printf("\tImplementation of Ellipse using Mid-Point Method\n");
    printf("Enter the center of the ellipse(xc,yc):");
    scanf("%d%d", &xc, &yc);
    printf("Enter the x-radius(rx) and y-radius(ry) of the ellipse:");
    scanf("%d%d", &rx, &ry);

    // initialize the graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Set the background color to WHITE
    setbkcolor(WHITE);
    // Draw the ellipse

    cleardevice();
    drawEllipse(xc, yc, rx, ry);

    delay(100000);
    // close the graphics mode
    closegraph();
}
