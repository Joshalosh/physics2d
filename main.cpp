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

    v2 ball_position  = {(r32)screen_width*0.25f, (r32)screen_height/2};
    v2 ball2_position = {(r32)screen_width*0.75f, (r32)screen_height/2};
    v2 velocity       = {};
    int isForce       = 10;

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
        
        // This is necessary for user input to control the ball
#if 0
        if(IsKeyDown(KEY_RIGHT)) acceleration.x =  1.0f;
        if(IsKeyDown(KEY_LEFT)) acceleration.x  = -1.0f;
        if(IsKeyDown(KEY_UP)) acceleration.y    = -1.0f;
        if(IsKeyDown(KEY_DOWN)) acceleration.y  =  1.0f;

        if((acceleration.x != 0.0f) && (acceleration.y != 0.0f))
        {
            acceleration *= 0.707106781187f;
        }
#endif

        if(isForce > 0)
        {
            acceleration.x = 1.0f;
            isForce--;
        }


        r32 speed     = 8800;
        acceleration *= speed;

        acceleration -= velocity * 5.0f;

        ball_position = (0.5f*acceleration*Square(GetFrameTime()) +
                         velocity*GetFrameTime() +
                         ball_position);
        ball2_position = (0.5f*(-acceleration)*Square(GetFrameTime()) +
                          (-velocity)*GetFrameTime() +
                          ball2_position);
        velocity = acceleration*GetFrameTime() + velocity;

        Vector2 new_position1;
        new_position1.x = ball_position.x;
        new_position1.y = ball_position.y;

        Vector2 new_position2;
        new_position2.x = ball2_position.x;
        new_position2.y = ball2_position.y;

        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(new_position1, 50, RED);
        DrawCircleV(new_position2, 50, BLUE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
