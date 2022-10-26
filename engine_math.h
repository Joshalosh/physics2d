#include "src/raylib.h"
#if !defined(ENGINE_MATH_H)

#include <stdint.h>

typedef int8_t  s08;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u08;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int32_t b32;
typedef float real32;

#define PI32 = 3.141592741f;
#define EPSILON = 0.0001f;

union Vec2
{
    struct
    {
        real32 x, y;
    };
    struct
    {
        real32 u, v;
    };
    real32 E[2];
};

union Vec3 
{
    struct
    {
        real32 x, y, z;
    };
    struct
    {
        real32 u, v, w;
    };
    struct
    {
        Vec2 xy;
        real32 Ignored0_;
    };
    struct
    {
        real32 Ignored1_;
        Vec2 yz;
    };
    struct
    {
        Vec2 uv;
        real32 Ignored2_;
    };
    struct
    {
        real32 Ignored3_;
        Vec2 vw;
    };
    real32 E[3];
};

//
// Vec2 OPERATIONS
//

inline Vec2
Perp(Vec2 A)
{
    Vec2 Result = {-A.y, A.x};

    return(Result);
}

inline Vec2
operator*(real32 A, Vec2 B)
{
    Vec2 Result;

    Result.x = A*B.x;
    Result.y = A*B.y;

    return(Result);
}

inline Vec2
operator*(Vec2 B, real32 A)
{
    Vec2 Result = A*B;

    return(Result);
}

inline Vec2 &
operator*=(Vec2&B, real32 A)
{
    B = A * B;

    return(B);
}

#define ENGINE_MATH_H
#endif
