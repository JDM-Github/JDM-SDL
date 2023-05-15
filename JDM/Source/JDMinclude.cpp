#include "JDM/Header/JDMinclude.hpp"

JNAMESPACE JDM {
    SDL_Renderer *renderer = JNULLPTR;
    JDOUBLE TimeFrame = 0;
    JDOUBLE FPS = 60;
    JDOUBLE ElapseTime = 0;
    JINT WindowX = 0;
    JINT WindowY = 0;
    JINT WindowWidth = 0;
    JINT WindowHeight = 0;
    JBOOL alreadyTouched = JFALSE;
    JNAMESPACE Mouse {
        JBOOL LeftMouseDown = JFALSE;
        JBOOL RightMouseDown = JFALSE;
        JINT MouseX = 0;
        JINT MouseY = 0;
        JINT GlobalMouseX = 0;
        JINT GlobalMouseY = 0;
    };

    // Soon will be implemented
    // JNAMESPACE Cache {
    //     JMAP<JCSTR, JPAIR<JINT, JINT>> textureSourceRect;
    // };
};