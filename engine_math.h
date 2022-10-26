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
    real32 e[2];
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
        real32 ignored0_;
    };
    struct
    {
        real32 ignored1_;
        Vec2 yz;
    };
    struct
    {
        Vec2 uv;
        real32 ignored2_;
    };
    struct
    {
        real32 ignored3_;
        Vec2 vw;
    };
    real32 e[3];
};

//
// Vec2 OPERATIONS
//

inline Vec2
Perp(Vec2 a)
{
    Vec2 result = {-a.y, a.x};

    return result;
}

inline Vec2
operator*(real32 a, Vec2 b)
{
    Vec2 result;

    result.x = a * b.x;
    result.y = a * b.y;

    return result;
}

inline Vec2
operator*(Vec2 b, real32 a)
{
    Vec2 result = a * b;

    return result;
}

inline Vec2 &
operator*=(Vec2 &b, real32 a)
{
    b = a * b;

    return b;
}

inline Vec2
operator-(Vec2 a)
{
    Vec2 result;

    result.x = -a.x;
    result.y = -a.y;

    return result;
}

inline Vec2
operator+(Vec2 a, Vec2 b)
{
    Vec2 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

inline Vec2 &
operator+=(Vec2 &a, Vec2 b)
{
    a = a + b;

    return a;
}

inline Vec2
operator-(Vec2 a, Vec2 b)
{
    Vec2 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;

    return result;
}

//
// Vec3 OPERATIONS
//

inline Vec3
operator*(real32 a, Vec3 b)
{
    Vec3 result;

    result.x = a * b.x;
    result.y = a * b.y;
    result.z = a * b.z;

    return result;
}

inline Vec3
operator*(Vec3 b, real32 a)
{
    Vec3 result = a * b;

    return result;
}

inline Vec3 &
operator*=(Vec3 &b, real32 a)
{
    b = a * b;

    return b;
}

inline Vec3
operator-(Vec3 a)
{
    Vec3 result;

    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;

    return result;
}

inline Vec3
operator+(Vec3 a, Vec3 b)
{
    Vec3 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

inline Vec3 &
operator+=(Vec3 &a, Vec3 b)
{
    a = a + b;

    return a;
}

inline Vec3
operator-(Vec3 a, Vec3 b)
{
    Vec3 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

#define ENGINE_MATH_H
#endif
