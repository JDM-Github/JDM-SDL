#pragma once
#ifndef JDM_STRUCT_HPP
#define JDM_STRUCT_HPP
#include "defines.hpp"

JNAMESPACE JDM {

    JSTRUCT Position { JDOUBLE x, y; };
    JSTRUCT Size { JDOUBLE width, height; };
    JSTRUCT PositionSize{ JUNION {
        JSTRUCT { JDOUBLE x, y, width, height; };
        JSTRUCT { JDM::Position pos; JDM::Size size; }; }; };

    JSTRUCT ColorRGB { JUINT8 r, g, b, a; };
    JSTRUCT ColorRGBA { JUNION {
        JSTRUCT { JUINT8 r, g, b, a; };
        JSTRUCT { JDM::ColorRGB rgb; JUINT8 opacity; }; }; };
    JSTRUCT Region { JINT x, y, w, h; };
    JSTRUCT RegionF { JFLOAT x, y, w, h; };
    JSTRUCT LinePoints { JDOUBLE x1, y1, x2, y2; };
    JSTRUCT FourArc { JUINT8 topLeft, topRight, bottomLeft, bottomRight; };
    JSTRUCT TwoLRArc { JUINT8 leftArc, rightArc; };
    JSTRUCT TwoTBArc { JUINT8 topArc, bottomArc; };
};
#endif