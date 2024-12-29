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
    int radius   = 25;

    // Axe coordinates
    int axe_x    = 400;
    int axe_y    = 0;
    int axe_len  = 50;
    int axe_wid  = 50;
    int direction = 10;

    SetTargetFPS(60);                   // Without this, the circle will just move so fast
    while (!WindowShouldClose()) {
        BeginDrawing();                 // we can move and minimize the window around
        ClearBackground(RED);           // adds red background in canvas

        // Circle logic starts here:
        DrawCircle(circle_x, circle_y, radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_len, axe_wid, VIOLET);

        if (IsKeyDown(KEY_D) && circle_x < length - radius) {
            circle_x += 10;
        } else if (IsKeyDown(KEY_A) && circle_x > radius) {
            circle_x -= 10;
        } else if (IsKeyDown(KEY_W) && circle_y > radius) {
            circle_y -= 10;
        } else if (IsKeyDown(KEY_S) && circle_y < width - radius) {
            circle_y += 10;
        }

        if (axe_y > width - axe_wid || axe_y < 0) {
            direction = -direction;
        }
        axe_y += direction;

        // Game logic ends here!

        EndDrawing();
    }
    return 0;
}
