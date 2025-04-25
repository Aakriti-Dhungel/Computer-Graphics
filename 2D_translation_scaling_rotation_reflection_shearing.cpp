#include <stdio.h>
#include <graphics.h>
#include <math.h>
// function to convert degrees to radians
float degrees_to_radians(float degrees)
{
	return degrees * (M_PI / 180.0);
}
// Main function
int main()
{
	// initialize graphics variables
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
// Set the background color to WHITE
    setbkcolor(WHITE);
    
      // Clear the screen to apply the background color
    cleardevice();
	// Variables for the initial coordinates of the triangle
	int x1, y1, x2, y2, x3, y3;
	printf("\t Implementation of 2D Geometric Transformation \n \n");
	// Get the initial coordinates from the user
	printf("Enter the coordinates of the first point (x1,y1):");
	scanf("%d%d", &x1, &y1);
	printf("Enter the coordinates of the second point (x2,y2):");
	scanf("%d%d", &x2, &y2);
	printf("Enter the coordinates of the third point (x3,y3):");
	scanf("%d%d", &x3, &y3);

	// Draw the initial triangle
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x2, y2, x1, y1);
	delay(1000);

	// Display menu for the user
	int choice;
	printf("Choose the transformation: \n");
	printf("1. Translation\n");
	printf("2. Scaling\n");
	printf("3. Rotation\n");
	printf("4. Reflection\n");
	printf("5. Shearing\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
	{
		// variables for the translation factors
		int tx, ty;

		// Get the translation factors from the user
		printf("Enter the translation factors (tx,ty): ");
		scanf("%d%d", &tx, &ty);

		// Translate the triangle
		x1 += tx;
		y1 += ty;
		x2 += tx;
		y2 += ty;
		x3 += tx;
		y3 += ty;

		// Draw the translated triangle
		setcolor(RED);
		line(x1, y1, x2, y2);
		line(x2, y2, x3, y3);
		line(x3, y3, x1, y1);
		break;
	}
	case 2:
	{
		// Variables for the scaling factors
		float sx, sy;
		// Get the scaling factors from the user
		printf("Enter the scaling factors (sx,sy): ");
		scanf("%f%f", &sx, &sy);

		// Scale teh triangle (assuming the origin is the pivot int)

		x1 = (int)(x1 * sx);
		y1 = (int)(y1 * sy);
		x2 = (int)(x2 * sx);
		y2 = (int)(y2 * sy);
		x3 = (int)(x3 * sx);
		y3 = (int)(y3 * sy);

		// Draw the scaled triangle
		setcolor(BLACK);
		line(x1, y1, x2, y2);
		line(x2, y2, x3, y3);
		line(x3, y3, x1, y1);
		break;
	}
	case 3:
	{
		// Variables for the rotation angle
		float angle;
		// Get the rotation angle from user
		printf("Enter the rotation angle (in degrees): ");
		scanf("%f", &angle);

		// convert the angle to radians
		float radian = degrees_to_radians(angle);
		// Rotate the triangle around the origin
		int new_x1 = (int)(x1 * cos(radian) - y1 * sin(radian));
		int new_y1 = (int)(x1 * sin(radian) + y1 * cos(radian));
		int new_x2 = (int)(x2 * cos(radian) - y2 * sin(radian));
		int new_y2 = (int)(x2 * sin(radian) + y2 * cos(radian));
		int new_x3 = (int)(x3 * cos(radian) - y3 * sin(radian));
		int new_y3 = (int)(x3 * sin(radian) + y3 * cos(radian));

		// Draw the rotated triangle
		setcolor(GREEN);
		line(new_x1, new_y1, new_x2, new_y2);
		line(new_x2, new_y2, new_x3, new_y3);
		line(new_x3, new_y3, new_x1, new_y1);
		break;
	}
	case 4:
	{
		// Variables for the reflection choice
		int axis;

		// Get the reflection axis from the user
		printf("Choose the reflection axis: \n");
		printf("1. X-axis \n");
		printf("2. Y-axis \n");
		printf("3. Origin \n");
		printf("4. Line Y = X \n");
		printf("Enter your choice: ");
		scanf("%d", &axis);

		switch (axis)
		{
		case 1: // Reflection across X-axis
			y1 = -y1;
			y2 = -y2;
			y3 = -y3;
			break;

		case 2: // Reflection across Y-axis
			x1 = -x1;
			x2 = -x2;
			x3 = -x3;
			break;

		case 3: // Reflection across the origin (both X and Y inverted)
			x1 = -x1;
			y1 = -y1;
			x2 = -x2;
			y2 = -y2;
			x3 = -x3;
			y3 = -y3;
			break;

		case 4: // Reflection across the line Y = X (swap X and Y)
			x1 = x1 + y1 - (y1 = x1);
			x2 = x2 + y2 - (y2 = x2);
			x3 = x3 + y3 - (y3 = x3);
			break;

		default:
			printf("Invalid choice\n");
			break;
		}

		// Draw the reflected triangle
		setcolor(RED);
		line(x1, y1, x2, y2);
		line(x2, y2, x3, y3);
		line(x3, y3, x1, y1);
		break;
	}
	case 5:
	{
		// xy-shear
		// Variables for the shearing factors
		float shx, shy;
		// Get the shearing factors from teh user
		printf("enter the shearing factors (shx,shy):");
		scanf("%f%f", &shx, &shy);

		// Shear the triangle
		int new_x1 = x1 + shx * y1;
		int new_y1 = shy * x1 + y1;
		int new_x2 = x2 + shx * y2;
		int new_y2 = shy * x2 + y2;
		int new_x3 = x3 + shx * y3;
		int new_y3 = shy * x3 + y3;

		// Draw the sheared triangle
		setcolor(RED);
		line(new_x1, new_y1, new_x2, new_y2);
		line(new_x2, new_y2, new_x3, new_y3);
		line(new_x3, new_y3, new_x1, new_y1);
		break;
	}
	default:
		printf("Invalid Choice \\n");
	}
	delay(1000000);
	closegraph();
	return 0;
}
