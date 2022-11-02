#include "src/raylib.h"
#include "collisions.cpp"

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

    Vector2 ball1_position = {((r32)screenWidth*0.25), (r32)screenHeight/2};
    Vector2 ball2_position = {((r32)screenWidth*0.75), (r32)screenHeight/2};
    Vector2 ball3_position = {((r32)screenWidth*0.50), (r32)screenHeight*0.25};
    Vector2 ball4_position = {((r32)screenWidth*0.50), (r32)screenHeight*0.75};

    SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(ball1_position.x < screenWidth)
        {
            ball1_position.x += 5.0f;
        }
        else 
        {
            ball1_position = {((r32)screenWidth*0.25), ((r32)screenHeight/2)}; 
        }

        if(ball2_position.x > 0)
        {
            ball2_position.x -= 5.0f;
        }
        else 
        {
            ball2_position = {((r32)screenWidth*0.75), ((r32)screenHeight/2)}; 
        }

        if(ball3_position.y < screenHeight)
        {
            ball3_position.y += 5.0f;
        }
        else 
        {
            ball3_position = {((r32)screenWidth*0.50), ((r32)screenHeight*0.25)}; 
        }

        if(ball4_position.y > 0)
        {
            ball4_position.y -= 5.0f;
        }
        else 
        {
            ball4_position = {((r32)screenWidth*0.50), ((r32)screenHeight*0.75)}; 
        }




        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircleV(ball1_position, 50, RED);
            DrawCircleV(ball2_position, 50, BLUE);
            DrawCircleV(ball3_position, 50, GREEN);
            DrawCircleV(ball4_position, 50, YELLOW);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
