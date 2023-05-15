#include "JDM/Header/JDManimation.hpp"

JTEMPLATE<JCLASS T>
JDM::Animation<T>::Animation(
    T *ref,
    JCONST T target,
    JCDOUBLE duration,
    JCBOOL autoRemove,
    JFUNCCALL func
) : Duration(duration), targetAnimating(ref), Target(target), autoremove(autoRemove), function(func) { }

JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::setVariables() {
    JTHIS->distance = JTHIS->Target - *JTHIS->targetAnimating;
    JTHIS->adder = distance * (1.0 / (JTHIS->Duration * 80));
}

JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::setReference(T *ref) {
    JIF (!JTHIS->started) {
        JTHIS->targetAnimating = ref;
        JTHIS->setVariables();
    }
}
JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::setDuration(JCDOUBLE duration) {
    JIF (!JTHIS->started) {
        JTHIS->Duration = duration;
        JTHIS->setVariables();
    }
}
JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::setAutoRemove(JCBOOL autoRemove) { JIF (!JTHIS->started) JTHIS->autoremove = autoRemove; }

JTEMPLATE<JCLASS T>
JCBOOL JDM::Animation<T>::getAutoRemove() { JRETURN JTHIS->autoremove; }

JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::setTarget(T target) {
    JIF (!JTHIS->started) {
        JTHIS->Target = target;
        JTHIS->setVariables();
    }
}
JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::start() {
    JIF(!JTHIS->started) {
        JTHIS->setVariables();
        JTHIS->started = JTRUE;
    }
}
JTEMPLATE<JCLASS T>
JCBOOL JDM::Animation<T>::update() {
    JIF (JTHIS->started && !JTHIS->stopped) {
        JIF ((JTHIS->Target <= *JTHIS->targetAnimating && JTHIS->adder >= 0)
          || (JTHIS->Target >= *JTHIS->targetAnimating && JTHIS->adder <= 0)) {
            *JTHIS->targetAnimating = JTHIS->Target;
            JTHIS->started = JFALSE;
            JRETURN JTRUE;
        } JELSE {
            *JTHIS->targetAnimating = JSTATICC<T>(*JTHIS->targetAnimating + JTHIS->adder);
            JTHIS->function();
        }
    }
    JRETURN JFALSE;
}
JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::stop() { JIF(JTHIS->started) JTHIS->stopped = JTRUE; }

JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::cont() { JIF(JTHIS->started) JTHIS->stopped = JFALSE; }

JTEMPLATE<JCLASS T>
JCVOID JDM::Animation<T>::cancel() { JTHIS->started = JFALSE; }


JDM::Clock::Clock(
    JCDOUBLE duration,
    JCBOOL autoRemove,
    JFUNCCALL func
) : Duration(duration), CurrentDuration(Duration), autoremove(autoRemove), function(func) {}
        
JCVOID JDM::Clock::SetAutoRemove(JCBOOL autoRemove) { JIF (!JTHIS->started) JTHIS->autoremove = autoRemove; }
JCBOOL JDM::Clock::GetAutoRemove() { JRETURN JTHIS->autoremove; }
JCVOID JDM::Clock::start() {
    JIF(!JTHIS->started) {
        JTHIS->CurrentDuration = JTHIS->Duration;
        JTHIS->started = JTRUE;
    }
}
JCVOID JDM::Clock::reset() {
    JTHIS->started = JFALSE;
    JTHIS->CurrentDuration = JTHIS->Duration;
}
JCBOOL JDM::Clock::update() {
    JIF(!JTHIS->started) JRETURN JFALSE;
    JTHIS->CurrentDuration -= (1.0 / 80);
    JIF (JTHIS->CurrentDuration <= 0) {
        JTHIS->function();
        JTHIS->started = JFALSE;
        JTHIS->CurrentDuration = JTHIS->Duration;
        JRETURN JTRUE;
    }
    JRETURN JFALSE;
}