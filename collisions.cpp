
#include "engine_math.h"
#include "shapes.h"
#include <math.h>

real32 Distance(v2 a, v2 b)
{
    return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}

b32 CircleVsCircle(circle a, circle b)
{
    b32 result = false;
    real32 radius = a.radius + b.radius;
    radius *= radius;
    if(radius < ((a.position.x + b.position.x)*(a.position.x + b.position.x)) + ((a.position.y + b.position.y)*(a.position.y + b.position.y)))
    {
        result = true;
    }

    return result;
}

