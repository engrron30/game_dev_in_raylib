#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "raylib.h"

int main()
{
    printf("This is the AXE GAME!\n");

    // Window dimensions
    int window_length = 1350;
    int window_width = 700;
    InitWindow(window_length, window_width, "AXE GAME");

    // Circle coordinates
    int circle_x = 175;
    int circle_y = 100;
    int radius   = 25;
    char circle_coor[50];

    // Axe coordinates
    int axe_x    = 400;
    int axe_y    = 0;
    int axe_len  = 50;
    int axe_wid  = 50;
    int direction = 10;
    char axe_coor[50];

    // Coordinates text
    int text_length_offset = 150 + 120;
    int text_width_offset  = 100 + 20;

    // Game over defines
    bool collision_with_axe = false;

    SetTargetFPS(60);                   // Without this, the circle will just move so fast
    while (!WindowShouldClose()) {
        BeginDrawing();                 // we can move and minimize the window around
        ClearBackground(RAYWHITE);      // adds red background in canvas

        if (!collision_with_axe)
        {
            // Initialize objects
            DrawCircle(circle_x, circle_y, radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_len, axe_wid, VIOLET);
            
            // Initialize circle edges
            int circle_x_right = circle_x + radius;
            int circle_x_left  = circle_x - radius;
            int circle_y_top   = circle_y - radius;
            int circle_y_down  = circle_y + radius;

            // Initialize axe edges
            int axe_x_left     = axe_x;
            int axe_x_right    = axe_x + axe_len;
            int axe_y_top      = axe_y;
            int axe_y_down     = axe_y + axe_len;

            // Print coordinates of circle and axe in lower left
            DrawText("Coordinates:", window_length - text_length_offset - 120, window_width - text_width_offset - 20, 40, BLACK);
            sprintf(circle_coor, "circle:   x = %4d   y = %d", circle_x, circle_y);
            sprintf(axe_coor,    "axe:      x = %4d   y = %d", axe_x,    axe_y);
            DrawText(circle_coor, window_length - text_length_offset, window_width - text_width_offset + 40, 20, DARKGRAY);
            DrawText(axe_coor,    window_length - text_length_offset, window_width - text_width_offset + 60, 20, DARKGRAY);

            // Circle movement
            if (IsKeyDown(KEY_D) && circle_x_right < window_length) {                   // Always subtract or add with radius to avoid the circle overlapping with borders
                circle_x += 10;
            } else if (IsKeyDown(KEY_A) && circle_x_left > 0) {
                circle_x -= 10;
            } else if (IsKeyDown(KEY_W) && circle_y_top > 5) {                      // offset to avoid upper and lower borders of window = 5
                circle_y -= 10;
            } else if (IsKeyDown(KEY_S) && circle_y_down < window_width - 5) {
                circle_y += 10;
            }

            // Obstacle movement
            if (axe_y >= window_width - axe_wid || axe_y < 0) {                               // Always subtract or add with axe width to avoid overlapping with window borders
                direction = -direction;
            }
            axe_y += direction;

            collision_with_axe = 
                (circle_x_right >= axe_x_left)  &&
                (circle_x_left  <= axe_x_right) &&
                (circle_y_top   <= axe_y_down)  &&
                (circle_y_down  >= axe_y_top);

        } else {
            DrawText("GAME OVER!", window_length / 2 - 150, window_width / 2 - 100, 40, RED);
        }

        // Game logic ends here!
        EndDrawing();
    }
    return 0;
}
