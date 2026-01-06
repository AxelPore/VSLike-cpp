#pragma once
#include "common_export.h"

struct COMMON_EXPORT Transform
{
    float x = 0.f;
    float y = 0.f;

    float rotation = 0.f; // optionnel

    void move(float dx, float dy)
    {
        x += dx;
        y += dy;
    }
};
