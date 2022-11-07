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
    const int screen_width  = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "Physics2D");

    v2 ball_position     = {(r32)screen_width/2, (r32)screen_height/2};
    v2 velocity          = {};

    SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // Need to set the acceleration inside the loop so that it initialises to 0 at the beginning
        // of every frame.
        v2 acceleration = {};
        if(IsKeyDown(KEY_RIGHT)) acceleration.x =  1.0f;
        if(IsKeyDown(KEY_LEFT)) acceleration.x  = -1.0f;
        if(IsKeyDown(KEY_UP)) acceleration.y    = -1.0f;
        if(IsKeyDown(KEY_DOWN)) acceleration.y  =  1.0f;

        if((acceleration.x != 0.0f) && (acceleration.y != 0.0f))
        {
            acceleration *= 0.707106781187f;
        }

        r32 speed     = 8800;
        acceleration *= speed;

        acceleration -= velocity * 10.0f;

        ball_position = (0.5f*acceleration*Square(GetFrameTime()) +
                         velocity*GetFrameTime() +
                         ball_position);
        velocity = acceleration*GetFrameTime() + velocity;

        Vector2 new_position;
        new_position.x = ball_position.x;
        new_position.y = ball_position.y;

        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(new_position, 50, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
