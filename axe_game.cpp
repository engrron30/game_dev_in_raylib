#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"

int main()
{
    printf("This is the AXE GAME!\n");

    int length = 1350;
    int width = 700;
    InitWindow(length, width, "AXE GAME");

    while (!WindowShouldClose()) {
        BeginDrawing();                 // we can move and minimize the window around
        ClearBackground(RED);           // adds red background in canvas

        DrawCircle(175, 100, 25, BLUE);
        EndDrawing();
    }
    return 0;
}