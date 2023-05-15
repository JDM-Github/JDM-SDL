#pragma once
#ifndef JDM_ANIMATION_HPP
#define JDM_ANIMATION_HPP

#include "defines.hpp"

JNAMESPACE JDM {
    JCLASS AnimationBase {
    JPUBLIC:
        JVIRTUAL ~AnimationBase() {}
        JVIRTUAL JCVOID SetDuration(JCDOUBLE duration) = 0;
        JVIRTUAL JCVOID SetAutoRemove(JCBOOL autoRemove) = 0;
        JVIRTUAL JCBOOL GetAutoRemove() = 0;
        JVIRTUAL JCVOID start() = 0;
        JVIRTUAL JCBOOL update() = 0;
        JVIRTUAL JCVOID stop() = 0;
        JVIRTUAL JCVOID cont() = 0;
        JVIRTUAL JCVOID cancel() = 0;
    };

    JTEMPLATE<JCLASS T>
    JCLASS Animation : JPUBLIC AnimationBase {
    JPRIVATE:
        JBOOL started = JFALSE;
        JBOOL stopped = JFALSE;
        JBOOL autoremove = JFALSE;
        JDOUBLE Duration = 1;
        T Target = 0;
        T *targetAnimating;
        JDOUBLE distance = 0;
        JDOUBLE adder = 0;
        JFUNCCALL function = []() {};
        JCVOID setVariables();

    JPUBLIC:
        Animation(
            T *ref,
            JCONST T target,
            JCDOUBLE duration = 1,
            JCBOOL autoRemove = JTRUE,
            JFUNCCALL func = [](){}
        );
        JCVOID setReference(T * ref);
        JCVOID setDuration(JCDOUBLE duration);
        JCVOID setAutoRemove(JCBOOL autoRemove);
        JCBOOL getAutoRemove();

        JCVOID setTarget(T target);
        JCVOID start();
        JCBOOL update();
        JCVOID stop();
        JCVOID cont();
        JCVOID cancel();
    };

    JCLASS Clock {
    JPRIVATE:
        JBOOL autoremove = JFALSE;
        JBOOL started = JFALSE;

        JDOUBLE Duration = 1;
        JDOUBLE CurrentDuration = 1;
        JFUNCCALL function = []() {};

    JPUBLIC:
        Clock(
            JCDOUBLE duration = 1,
            JCBOOL autoRemove = JTRUE,
            JFUNCCALL func = [](){}
        );
        JCVOID SetAutoRemove(JCBOOL autoRemove);
        JCBOOL GetAutoRemove();
        JCVOID start();
        JCVOID reset();
        JCBOOL update();
    };
};

#endif
