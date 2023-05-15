#pragma once
#ifndef JDM_WINDOW_HPP
#define JDM_WINDOW_HPP

#include "JDMinclude.hpp"
#include "JDMfunctions.hpp"
#include "JDManimation.hpp"
#include "JDMstructs.hpp"
#include "JDMcomponents.hpp"
#include "JDMkeycodes.hpp"
#include "logger.hpp"


JNAMESPACE JDM {
    JEXTERN JLIST<JSP<AnimationBase>> allAnimations;
    JEXTERN JLIST<JSP<Clock>> allClock;
    JEXTERN JLIST<JSP<Comp::Components>> allComponents;
    JEXTERN Comp::FocusedTextComponent *focusedTextComponent;

    JCLASS Window {
    JPRIVATE:
        ColorRGB winColor;
        PositionSize positionSize;
        JBOOL started = JFALSE;
        JBOOL isKeyDown = JFALSE;
        JBOOL isCursorChangeable = JFALSE;
        JSTR Title;

        SDL_bool running;
        SDL_Window *window;
        SDL_Event event;

        SDL_Surface *iconSurface;
        SDL_Texture *cursorTexture;
        SDL_Rect cursorRect;

        JUINT32 firstTime = 0;
        JUINT32 prevTime = 0;
        JUINT32 secondTime = 0;

    JPUBLIC:
        Window(JSTRVIEW title = "WindowTitle",
            JCONST PositionSize &posSize = {10, 10, 500, 500},
            JCONST ColorRGB& windowColor = {0, 0, 0}
        );
        ~Window();

        JCVOID run();
        JVIRTUAL JCVOID update();
        JVIRTUAL JCVOID initAllObjects();
        JVIRTUAL JCVOID mouseDown();
        JVIRTUAL JCVOID mouseUp();
        JVIRTUAL JCVOID mouseMotion();
        JVIRTUAL JCVOID keyDown(JCBOOL * Key);
        JVIRTUAL JCVOID keyHold(JCBOOL * Key);
        JVIRTUAL JCVOID keyUp(JCBOOL * Key);

        JCVOID setTitle(JCSTR & title);
        JCVOID setIcon(JCSTR & path);
        JCVOID setCursor(JCSTR &path);

    JPUBLIC: // Static Functions
        JSTATIC JCVOID addComponents(JCONST JSP<Comp::Components> & comp);
        JSTATIC JCVOID removeComponents(JCONST JSP<Comp::Components> & comp);
        JSTATIC JCVOID addClock(JCONST JSP<Clock> & timer);
        JSTATIC JCVOID addStartClock(JCONST JSP<Clock> & timer);
        JSTATIC JCVOID removeClock(JCONST JSP<Clock> & timer);
        JTEMPLATE<JCLASS T> JSTATIC JCVOID addAnimation(JCONST JSP<Animation<T>> & anim);
        JTEMPLATE<JCLASS T> JSTATIC JCVOID addStartAnimation(JCONST JSP<Animation<T>> & anim);
        JTEMPLATE<JCLASS T> JSTATIC JCVOID removeAnimation(JCONST JSP<Animation<T>> & anim);

    JPRIVATE: 
        JCVOID handleError();
        JCBOOL initializeAll();
        JCBOOL createWindow();
        JCBOOL createRenderer();
        JCVOID setFocusedTextComponent(Comp::FocusedTextComponent * focusedText);

        JCVOID animationUpdate();
        JCVOID winUpdate();
        JCVOID winRender();

        JCVOID pollEvent();
        JCVOID mouseWinDown(SDL_MouseButtonEvent & mouse);
        JCVOID mouseWinUp(SDL_MouseButtonEvent &mouse);
        JCVOID mouseWinMotion(SDL_MouseMotionEvent & mouse);

        JCBOOL *keyBoardDown(SDL_KeyboardEvent & key);
        JCBOOL *keyBoardUp(SDL_KeyboardEvent & key);
        JCVOID enterKey(JCSTR &small, JCSTR &big);
        JCVOID deletekey();
    };

    JNAMESPACE Layout {
    // JCLASS BaseLayout : JPUBLIC Comp::Components{
    // JPUBLIC:
    //     JBOOL isAccessible = JTRUE;
    //     JLIST<JSP<Comp::Components>> childrens;
    //     JINLINE JCVOID moveAllX(JCDOUBLE x) {
    //         JFOR (JAUTO &child : JTHIS->childrens)
    //             child->setX(child->getX() + x);
    //     }
    //     JINLINE JCBOOL mouseDownComp(SDL_MouseButtonEvent &mouse) {
    //         JIF (!JTHIS->isAccessible) JRETURN JTRUE;
    //         JTHIS->getmouseDownFunction()(mouse);
    //         JFOR (JAUTO &comp : JTHIS->childrens) {
    //             JIF (comp->mouseDownComp(mouse) && comp->getName() == "FocusedTextComponent") {
    //                 focusedTextComponent = JDYNAMICC<Comp::FocusedTextComponent*>(&(*comp));
    //                 focusedTextComponent->isFocused = JTRUE;
    //             }
    //         }
    //         JRETURN JTRUE;
    //     }
    //     JINLINE JCVOID mouseMotionComp(SDL_MouseMotionEvent & mouse) {
    //         JIF (!JTHIS->isAccessible) JRETURN
    //         JTHIS->getmouseMotionFunction()(mouse);
    //         JFOR(JAUTO &comp : JTHIS->childrens) comp->mouseMotionComp(mouse); }
    //     JINLINE JCVOID mouseUpComp(SDL_MouseButtonEvent &mouse)  {
    //         JIF (!JTHIS->isAccessible) JRETURN
    //         JTHIS->getmouseUpFunction()(mouse);
    //         JFOR(JAUTO &comp : JTHIS->childrens) comp->mouseUpComp(mouse); }

    //     JINLINE JVIRTUAL JCSTR getName() JCONST { JRETURN "BaseLayout"; }

    //     JINLINE JCVOID moveAllXSmooth(JCDOUBLE x, JCDOUBLE duration) {
    //         JFOR (JAUTO &child : JTHIS->childrens) {
    //             Window::addStartAnimation(
    //                 JMS<Animation<JDOUBLE>>(child->getPointerX(), (child->getX() + x), duration, true)); 
    //         }
    //     }
    //     JINLINE JCVOID moveAllY(JCDOUBLE y) {
    //         JFOR (JAUTO &child : JTHIS->childrens)
    //             child->setY(child->getY() + y);
    //     }
    //     JINLINE JCVOID setAllY(JCDOUBLE y) {
    //         JFOR (JAUTO &child : JTHIS->childrens)
    //             child->setY(y);
    //     }
    //     JINLINE JCVOID moveAllYSmooth(JCDOUBLE y, JCDOUBLE duration) {
    //         JFOR (JAUTO &child : JTHIS->childrens) {
    //             Window::addStartAnimation(
    //                 JMS<Animation<JDOUBLE>>(child->getPointerY(), (child->getY() + y), duration, true)); 
    //         }
    //     }
    //     JINLINE JCVOID setAllOpacity(JUINT8 a) {
    //         JFOR (JAUTO &child : JTHIS->childrens)
    //             child->setAForeGround(a);
    //     }
    //     JINLINE JCVOID setAllOpacitySmooth(JUINT8 a, JCDOUBLE duration) {
    //         JFOR (JAUTO &child : JTHIS->childrens) {
    //             JIF (child->getPointerAImage() != JNULLPTR) 
    //                 Window::addStartAnimation(JMS<Animation<JUINT8>>(child->getPointerAImage(), a, duration, true)); 
    //             JIF (child->getPointerAForeGround() != JNULLPTR) 
    //                 Window::addStartAnimation(JMS<Animation<JUINT8>>(child->getPointerAForeGround(), a, duration, true)); 
    //         }
    //     }
    //     JINLINE JCVOID addComponents(JCONST JSP<Comp::Components> &comp) { JTHIS->childrens.push_back(comp); }
    //     JINLINE JCVOID removeComponents(JCONST JSP<Comp::Components> &comp) { JTHIS->childrens.remove(comp); }

    //     JINLINE JCVOID update() { JFOR (JAUTO &child : JTHIS->childrens) { child->updateComp(); } }
    //     JINLINE JCVOID renderComp() { JFOR (JAUTO &child : JTHIS->childrens) { child->renderComp(); } }
    //     };
    };
};
#endif