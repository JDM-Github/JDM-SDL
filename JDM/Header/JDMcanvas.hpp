#pragma once
#ifndef JDM_CANVAS_HPP
#define JDM_CANVAS_HPP
#include "defines.hpp"

JNAMESPACE JDM{
    // JNAMESPACE Canvas {
    // JCLASS Rectangle : JPUBLIC Components {
    // JPRIVATE:
    //     ColorRGBA rectColor;
    //     SDL_FRect rect;
    //     ColorRGBA startColor = {0, 0, 0, 0};
    //     ColorRGBA endColor = {0, 0, 0, 0};
    //     Gradient gradientAlignment = NONE;

    //     JINLINE JCVOID setRect() {
    //         JTHIS->rect.w = JTHIS->getWidth();
    //         JTHIS->rect.h = JTHIS->getHeight();
    //         JTHIS->rect.x = JTHIS->getX();
    //         JTHIS->rect.y = JTHIS->getY();
    //     }

    // JPUBLIC:
    //     Rectangle(JCDOUBLE xPos = 0, JCDOUBLE yPos = 0,
    //       JCDOUBLE Width = 100, JCDOUBLE Height = 100, ColorRGBA color = {255, 255, 255, 255})
    //       : Components(xPos, yPos, Width, Height), rectColor(color) { }

    //     JINLINE JUINT8 interpolateColorComponent(JUINT8 startComponent, JUINT8 endComponent, JINT y, JINT height) {
    //         JRETURN startComponent + ((endComponent - startComponent) * y) / height;
    //     }
    //     JINLINE JCVOID setGradient(Gradient grad) { JTHIS->gradientAlignment = grad; }
    //     JINLINE JCVOID setGradiendColor(ColorRGBA first, ColorRGBA second) {
    //         JTHIS->startColor = first;
    //         JTHIS->endColor = second;
    //     }
    //     JINLINE JCVOID setColor(ColorRGBA color) { JTHIS->rectColor = color; }
    //     JCONSTEXPR ColorRGBA getColor() JCONST { JRETURN JTHIS->rectColor; }

    //     JINLINE JCVOID update() JOVERRIDE { JTHIS->setRect(); }
    //     JINLINE JCVOID renderComp() JOVERRIDE {
    //         JIF (IsTextureInWindow(JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight(), JDM::WinWidth, JDM::WinHeight)) {
    //         SDL_SetRenderDrawColor(JDM::renderer, JTHIS->rectColor.r, JTHIS->rectColor.g, JTHIS->rectColor.b, JTHIS->rectColor.a);
    //         SDL_RenderFillRectF(JDM::renderer, &JTHIS->rect);
    //         JIF (JTHIS->gradientAlignment == VERTICAL) {
    //             JFOR (JINT y = 0; y < JTHIS->getHeight(); y++) {
    //                 JUINT8 r = JTHIS->interpolateColorComponent(JTHIS->startColor.r, JTHIS->endColor.r, y, JTHIS->getHeight());
    //                 JUINT8 g = JTHIS->interpolateColorComponent(JTHIS->startColor.g, JTHIS->endColor.g, y, JTHIS->getHeight());
    //                 JUINT8 b = JTHIS->interpolateColorComponent(JTHIS->startColor.b, JTHIS->endColor.b, y, JTHIS->getHeight());
    //                 JUINT8 a = JTHIS->interpolateColorComponent(JTHIS->startColor.a, JTHIS->endColor.a, y, JTHIS->getHeight());

    //                 SDL_SetRenderDrawBlendMode(JDM::renderer, SDL_BLENDMODE_BLEND);
    //                 SDL_SetRenderDrawColor(JDM::renderer, r, g, b, a);
    //                 SDL_RenderDrawLine(JDM::renderer, JTHIS->getX(), JTHIS->getY() + y, JTHIS->getX() + JTHIS->getWidth(), JTHIS->getY() + y);
    //                 SDL_SetRenderDrawBlendMode(JDM::renderer, SDL_BLENDMODE_NONE);
    //             }
    //         } JELSE JIF (JTHIS->gradientAlignment == HORIZONTAL) {
    //             JFOR (JINT x = 0; x < JTHIS->getWidth(); x++) {
    //                 JUINT8 r = JTHIS->interpolateColorComponent(JTHIS->startColor.r, JTHIS->endColor.r, x, JTHIS->getHeight());
    //                 JUINT8 g = JTHIS->interpolateColorComponent(JTHIS->startColor.g, JTHIS->endColor.g, x, JTHIS->getHeight());
    //                 JUINT8 b = JTHIS->interpolateColorComponent(JTHIS->startColor.b, JTHIS->endColor.b, x, JTHIS->getHeight());
    //                 JUINT8 a = JTHIS->interpolateColorComponent(JTHIS->startColor.a, JTHIS->endColor.a, x, JTHIS->getHeight());

    //                 SDL_SetRenderDrawBlendMode(JDM::renderer, SDL_BLENDMODE_BLEND);
    //                 SDL_SetRenderDrawColor(JDM::renderer, r, g, b, a);
    //                 SDL_RenderDrawLine(JDM::renderer, JTHIS->getX() + x, JTHIS->getY(), JTHIS->getX() + x, JTHIS->getY() + JTHIS->getHeight());
    //                 SDL_SetRenderDrawBlendMode(JDM::renderer, SDL_BLENDMODE_NONE);
    //             }
    //         }}
    //     }
    // };

    // JCLASS Circle : JPUBLIC Components {

    // JPRIVATE:
    //     SDL_Texture *circleTexture;
    //     SDL_FRect rect;
    //     ColorRGBA rectColor;
    //     ColorRGBA startColor = {0, 0, 0, 0};
    //     ColorRGBA endColor = {0, 0, 0, 0};

    //     Gradient gradientAlignment = NONE;

    // JPUBLIC:
    //     JINLINE JCVOID setRect() {
    //         JTHIS->rect.x = JTHIS->getX();
    //         JTHIS->rect.y = JTHIS->getY();
    //         JTHIS->rect.w = JTHIS->getWidth();
    //         JTHIS->rect.h = JTHIS->getHeight();
    //     }
    //     Circle(JCDOUBLE xPos = 0, JCDOUBLE yPos = 0,
    //       JCDOUBLE xPos2 = 100, JCDOUBLE yPos2 = 100, ColorRGBA color = {255, 255, 255, 255})
    //       : Components(xPos, yPos, xPos2, yPos2), rectColor(color) {
    //         JTHIS->circleTexture = IMG_LoadTexture(JDM::renderer, CircleImage.c_str());
    //         SDL_SetTextureBlendMode(JTHIS->circleTexture, SDL_BLENDMODE_BLEND);
    //         SDL_SetTextureScaleMode(JTHIS->circleTexture, SDL_ScaleModeLinear);
    //         JTHIS->setColor();
    //     }
    //     JINLINE JUINT8 interpolateColorComponent(JUINT8 startComponent, JUINT8 endComponent, JINT y, JINT height) {
    //         JRETURN startComponent + ((endComponent - startComponent) * y) / height;
    //     }
    //     JINLINE JCVOID setGradient(Gradient grad) { JTHIS->gradientAlignment = grad; }
    //     JINLINE JCVOID setGradiendColor(ColorRGBA first, ColorRGBA second) {
    //         JTHIS->startColor = first;
    //         JTHIS->endColor = second;
    //     }
    //     JINLINE JCVOID setColor() {
    //         SDL_SetTextureColorMod(JTHIS->circleTexture, JTHIS->rectColor.r, JTHIS->rectColor.g, JTHIS->rectColor.b);
    //         SDL_SetTextureAlphaMod(JTHIS->circleTexture, JTHIS->rectColor.a);
    //     }
    //     JINLINE JCVOID update() { JTHIS->setRect(); }
    //     JINLINE JCVOID renderComp() {
    //         JIF (IsTextureInWindow(JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight(), JDM::WinWidth, JDM::WinHeight))
    //             SDL_RenderCopyF(JDM::renderer, JTHIS->circleTexture, JNULLPTR, &JTHIS->rect);
    //     }
    // };

    // JCLASS Line : JPUBLIC Components {
    // JPRIVATE:
    //     ColorRGBA rectColor;

    // JPUBLIC:
    //     Line(JCDOUBLE xPos = 0, JCDOUBLE yPos = 0,
    //       JCDOUBLE xPos2 = 100, JCDOUBLE yPos2 = 100, ColorRGBA color = {255, 255, 255, 255})
    //       : Components(xPos, yPos, xPos2, yPos2), rectColor(color) { }

    //     JINLINE JCVOID setColor(ColorRGBA color) { JTHIS->rectColor = color; }
    //     JCONSTEXPR ColorRGBA getColor() JCONST { JRETURN JTHIS->rectColor; }

    //     JINLINE JCVOID renderComp() JOVERRIDE {
    //         JIF (IsTextureInWindow(JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight(), JDM::WinWidth, JDM::WinHeight)) {
    //             SDL_SetRenderDrawColor(JDM::renderer, JTHIS->rectColor.r, JTHIS->rectColor.g, JTHIS->rectColor.b, JTHIS->rectColor.a);
    //             SDL_RenderDrawLineF(JDM::renderer, JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight());
    //         }
    //     }
    // };
};
#endif