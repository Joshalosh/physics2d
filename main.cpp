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

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                mouse_position = GetMousePosition();
                //DrawCircle(GetMouseX(), GetMouseY(), 25.0f, BLUE);
            }

            DrawCircle(mouse_position.x, mouse_position.y, 25.0f, BLUE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
