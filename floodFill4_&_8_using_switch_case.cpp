#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

// 4-Connected Flood Fill
void floodFill4(int x, int y, int fillColor, int oldColor) {
    int current = getpixel(x, y);  // Get the current color of the pixel

    // If the current pixel is the same as the old color (inside the area to fill)
    if (current == oldColor) {
        delay(5);  // Delay to allow the fill to appear slowly
        putpixel(x, y, fillColor);  // Change the pixel to the fill color

        // Recursively call flood fill for the 4 connected neighbors
        floodFill4(x + 1, y, fillColor, oldColor);  // Right
        floodFill4(x - 1, y, fillColor, oldColor);  // Left
        floodFill4(x, y + 1, fillColor, oldColor);  // Down
        floodFill4(x, y - 1, fillColor, oldColor);  // Up
    }
}

// 8-Connected Flood Fill
void floodFill8(int x, int y, int fillColor, int oldColor) {
    int current = getpixel(x, y);  // Get the current color of the pixel

    // If the current pixel is the same as the old color (inside the area to fill)
    if (current == oldColor) {
        delay(5);  // Delay to allow the fill to appear slowly
        putpixel(x, y, fillColor);  // Change the pixel to the fill color

        // Recursively call flood fill for the 8 connected neighbors
        floodFill8(x + 1, y, fillColor, oldColor);  // Right
        floodFill8(x - 1, y, fillColor, oldColor);  // Left
        floodFill8(x, y + 1, fillColor, oldColor);  // Down
        floodFill8(x, y - 1, fillColor, oldColor);  // Up
        floodFill8(x + 1, y + 1, fillColor, oldColor);  // Down-right (diagonal)
        floodFill8(x - 1, y + 1, fillColor, oldColor);  // Down-left (diagonal)
        floodFill8(x + 1, y - 1, fillColor, oldColor);  // Up-right (diagonal)
        floodFill8(x - 1, y - 1, fillColor, oldColor);  // Up-left (diagonal)
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize graphics mode

    int points[]={200,100,
				250,200,
				225,200,
				175,200,
				150,150,
				200,100
				};
	drawpoly(6,points);
    // Choose flood fill method
    int choice;
    printf("Choose Flood Fill Method:\n");
    printf("1. 4-Connected Flood Fill\n");
    printf("2. 8-Connected Flood Fill\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    int oldColor = getpixel(200, 150);  // Get the color at a point inside the polygon
    int fillColor = YELLOW;  // Set the fill color to yellow

    switch (choice) {
        case 1:
            floodFill4(200, 150, fillColor, oldColor);  // Apply 4-connected flood fill
            break;
        case 2:
            floodFill8(200, 150, fillColor, oldColor);  // Apply 8-connected flood fill
            break;
        default:
            printf("Invalid choice! Exiting...\n");
    }

    getch();  // Wait for a key press
    closegraph();  // Close the graphics mode
    return 0;
}

