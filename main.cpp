#include "src/raylib.h"

#define MAX_COLUMNS 20

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Physics2D");

    SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Vector2 mouse_position;
    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
//        ShowCursor();
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            Rectangle rec_one = {400, 225, 40, 40};
            Rectangle rec_two = {300, 225, 40, 40};
            DrawRectangleRec(rec_one, RED);
            DrawRectangleRec(rec_two, BLUE);

            if(CheckCollisionRecs(rec_one, rec_two))
            {
                int x = 1;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
