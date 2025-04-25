#include <graphics.h>
#include <stdio.h>

// 4-Connected Boundary Fill Algorithm
void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);
    
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

// 8-Connected Boundary Fill Algorithm
void boundaryFill8(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);
    
    if (current_color != boundary_color && current_color != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill8(x + 1, y, fill_color, boundary_color);
        boundaryFill8(x - 1, y, fill_color, boundary_color);
        boundaryFill8(x, y + 1, fill_color, boundary_color);
        boundaryFill8(x, y - 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm, choice;
    initgraph(&gd, &gm, NULL);

	// Set the background color to WHITE
    setbkcolor(LIGHTGRAY);

    // Clear the screen to apply the background color
    cleardevice();
    
    // Draw a rectangle boundary
    rectangle(100, 100, 200, 200);

	printf("\t Boundary Fill Algorithm\n");
    // Menu for user selection
    printf("Select Boundary Fill Algorithm:\n");
    printf("1. 4-Connected Fill\n");
    printf("2. 8-Connected Fill\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            boundaryFill4(150, 150, GREEN, WHITE);
            break;
        case 2:
            boundaryFill8(150, 150, GREEN, WHITE);
            break;
        default:
            printf("Invalid choice! Exiting program.\n");
            closegraph();
            return 0;
    }

    delay(50000);
    closegraph();
    return 0;
}

