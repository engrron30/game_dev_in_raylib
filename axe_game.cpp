#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"

int main()
{
    printf("This is the AXE GAME!\n");

    // Window dimensions
    int length = 1350;
    int width = 700;
    InitWindow(length, width, "AXE GAME");

    // Circle coordinates
    int circle_x = 175;
    int circle_y = 100;

    while (!WindowShouldClose()) {
        BeginDrawing();                 // we can move and minimize the window around
        ClearBackground(RED);           // adds red background in canvas

        SetTargetFPS(60);               // Without this, the circle will just move so fast
        // Game logic starts here:
        DrawCircle(circle_x, circle_y, 25, BLUE);
        if (IsKeyDown(KEY_D)) {
            circle_x += 10;
        } else if (IsKeyDown(KEY_A)) {
            circle_x -= 10;
        } 


        // Game logic ends here!

        EndDrawing();
    }
    return 0;
}