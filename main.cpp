#include "src/raylib.h"
#include "engine_math.h"

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

    Vector2 ball_position = {(r32)screenWidth/2, (r32)screenHeight/2};
    v2 velocity = {};
    v2 acceleration = {};

    SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(IsKeyDown(KEY_RIGHT)) acceleration.x =  1.0f;
        if(IsKeyDown(KEY_LEFT)) acceleration.x  = -1.0f;
        if(IsKeyDown(KEY_UP)) acceleration.y    = -1.0f;
        if(IsKeyDown(KEY_DOWN)) acceleration.y  =  1.0f;

        if((acceleration.x != 0.0f) && (acceleration.y != 0.0f))
        {
            acceleration *= 0.707106781187f;
        }

        r32 speed = 1.5f;
        acceleration *= speed;

        v2 new_position = {};
        v2 position_offset = {};
        position_offset = (0.5f*acceleration*Square(GetFrameTime()) +
                           velocity*GetFrameTime() +
                           position_offset);
        velocity = acceleration*GetFrameTime() + velocity;

        ball_position.x = position_offset.x;
        ball_position.y = position_offset.y;

        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawCircleV(ball_position, 50, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
