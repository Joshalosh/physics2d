#if !defined(ENGINE_MATH_H)

#include <stdint.h>

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int32_t b32;
typedef float r32;

#define PI32 = 3.141592741f;
#define EPSILON = 0.0001f;

union v2
{
    struct
    {
        r32 x, y;
    };
    struct
    {
        r32 u, v;
    };
    r32 e[2];
};

union v3 
{
    struct
    {
        r32 x, y, z;
    };
    struct
    {
        r32 u, v, w;
    };
    struct
    {
        v2 xy;
        r32 ignored0_;
    };
    struct
    {
        r32 ignored1_;
        v2 yz;
    };
    struct
    {
        v2 uv;
        r32 ignored2_;
    };
    struct
    {
        r32 ignored3_;
        v2 vw;
    };
    r32 e[3];
};

inline v2
Vec2(r32 x, r32 y)
{
    v2 result;

    result.x = x;
    result.y = y;
    
    return result;
}

inline v3
Vec3(r32 x, r32 y, r32 z)
{
    v3 result;

    result.x = x;
    result.y = y;
    result.z = z;
    
    return result;
}

inline v3
Vec3(v2 xy, r32 z)
{
    v3 result;

    result.x = xy.x;
    result.y = xy.y;
    result.z = z;

    return result;
}

//
// Vec2 OPERATIONS
//

inline v2
Perp(v2 a)
{
    v2 result = {-a.y, a.x};

    return result;
}

inline v2
operator*(r32 a, v2 b)
{
    v2 result;

    result.x = a * b.x;
    result.y = a * b.y;

    return result;
}

inline v2
operator*(v2 b, r32 a)
{
    v2 result = a * b;

    return result;
}

inline v2 &
operator*=(v2 &b, r32 a)
{
    b = a * b;

    return b;
}

inline v2
operator-(v2 a)
{
    v2 result;

    result.x = -a.x;
    result.y = -a.y;

    return result;
}

inline v2
operator+(v2 a, v2 b)
{
    v2 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;

    return result;
}

inline v2 &
operator+=(v2 &a, v2 b)
{
    a = a + b;

    return a;
}

inline v2
operator-(v2 a, v2 b)
{
    v2 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;

    return result;
}

inline v2 &
operator-=(v2 &a, v2 b)
{
    a = a - b;

    return a;
}

//
// Vec3 OPERATIONS
//

inline v3
operator*(r32 a, v3 b)
{
    v3 result;

    result.x = a * b.x;
    result.y = a * b.y;
    result.z = a * b.z;

    return result;
}

inline v3
operator*(v3 b, r32 a)
{
    v3 result = a * b;

    return result;
}

inline v3 &
operator*=(v3 &b, r32 a)
{
    b = a * b;

    return b;
}

inline v3
operator-(v3 a)
{
    v3 result;

    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;

    return result;
}

inline v3
operator+(v3 a, v3 b)
{
    v3 result;

    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;

    return result;
}

inline v3 &
operator+=(v3 &a, v3 b)
{
    a = a + b;

    return a;
}

inline v3
operator-(v3 a, v3 b)
{
    v3 result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return result;
}

//
// SCALAR OPERATIONS
//

inline r32
Square(r32 a)
{
    r32 result = a*a;

    return result;
}

#define ENGINE_MATH_H
#endif
