#include <stdio.h>
#include <stdbool.h>
#include "raylib.h"

int main()
{
    printf("This is the AXE GAME!\n");

    int length = 1350;
    int width = 700;
    InitWindow(length, width, "AXE GAME");

    while (true) {
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
    }
    return 0;
}