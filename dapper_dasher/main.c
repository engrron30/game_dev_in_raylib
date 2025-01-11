#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "raylib.h"

int main()
{
    // Windows Dimensions
    const int window_len = 1300;
    const int window_wid = 700;
    InitWindow(window_len, window_wid, "DAPPER DASHER");

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        // Start Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Add game logic here

        // End Drawing
        EndDrawing();
    }

    // End the program
    CloseWindow();
    return 0;
}
