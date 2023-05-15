#pragma once
#ifndef JDM_FUNCTIONS_HPP
#define JDM_FUNCTIONS_HPP
#include "defines.hpp"
#include "JDMstructs.hpp"

JNAMESPACE JDM {
    JEXTERN JCVOID subtractCharAtIndex(JSTR &str, JCINT index);
    JEXTERN JCVOID addCharAtIndex(JSTR &str, JCINT index, JCSTR &ch);
    JEXTERN JCSTR retSubtractCharAtIndex(JSTR str, JCINT index);
    JEXTERN JCSTR retAddCharAtIndex(JSTR str, JCINT index, JCSTR &ch);
    JEXTERN JCBOOL isFileExist(JSTRVIEW file);
    JEXTERN JCONST JDM::ColorRGB getColorFromHex(JSTRVIEW hexColor);
    JEXTERN JCONST JDM::ColorRGBA getColorFromHexA(JSTRVIEW hexColor);
    JEXTERN JCBOOL IsTextureInWindow(
        JCDOUBLE x,
        JCDOUBLE y,
        JCDOUBLE width,
        JCDOUBLE height
    );
    JEXTERN SDL_Texture *loadRoundedTexture(
        JCONST JDM::Size &size,
        JCCHAR *path,
        JCONST JDM::FourArc &arc,
        JCUINT8 lineWidth
    );
    JEXTERN SDL_Texture *loadTextTexture(
        JCCHAR * path,
        JCCHAR * text,
        JCONST ColorRGBA &color
    );
};

#endif