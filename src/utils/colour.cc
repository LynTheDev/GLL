#include "GLL/colour.hh"

Colour GLL::to_normalised_RGBA(int r, int g, int b, int a)
{
    Colour normalised
    {
        r / 255.0f,
        g / 255.0f,
        b / 255.0f,
        a / 255.0f
    };

    return normalised;
}