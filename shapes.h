#if !defined(SHAPES_H)

#include "engine_math.h"

struct aabb
{
    v2 Min;
    v2 Max;
};

struct circle 
{
    real32 radius;
    v2 position;
};

#define SHAPES_H
#endif
