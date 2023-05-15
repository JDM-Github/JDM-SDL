#pragma once
#ifndef JDM_COMPONENTS_HPP
#define JDM_COMPONENTS_HPP
#include "JDMinclude.hpp"
#include "JDMfonts.hpp"
#include "logger.hpp"
#include "JDMstructs.hpp"
#include "JDMenum.hpp"
#include "JDMfunctions.hpp"

JNAMESPACE JDM{JNAMESPACE Comp{
    JCLASS Components{
    JPRIVATE:
        JFUNCCALL updateFunction = []() {};
        JFUNCTION<JCVOID(SDL_MouseButtonEvent& mouse)> mouseDownFunction = [](SDL_MouseButtonEvent &mouse) {};
        JFUNCTION<JCVOID(SDL_MouseMotionEvent& mouse)> mouseMotionFunction = [](SDL_MouseMotionEvent &mouse) {};
        JFUNCTION<JCVOID(SDL_MouseButtonEvent& mouse)> mouseUpFunction = [](SDL_MouseButtonEvent &mouse) {};
        JBOOL mouseClicked = JFALSE;
        JBOOL pickOnTop = JFALSE;
        JBOOL pickOnBounds = JTRUE;
        JBOOL stopRendering = JFALSE;
        PositionSize sizePos = {};
        
    JPUBLIC:
        Components(
            JCDOUBLE xPos = 0,
            JCDOUBLE yPos = 0,
            JCDOUBLE Width = 100,
            JCDOUBLE Height = 100
        );
        JCBOOL contains(JCDOUBLE xPos, JCDOUBLE yPos) JCONST;

        JCVOID setSizePos(JCONST PositionSize &sPos);
        JCVOID setPos(JCONST Position &pos);
        JCVOID setSize(JCONST Size &size);
        JCVOID setX(JCDOUBLE xPos);
        JCVOID setY(JCDOUBLE yPos);
        JCVOID setWidth(JCDOUBLE Width);
        JCVOID setHeight(JCDOUBLE Height);

        JCVOID setPickOnBounds(JCBOOL bounds);
        JCVOID setPickOnTop(JCBOOL top);
        JCVOID setRendering(JCBOOL isRendering);

        JCVOID setUpdateFunction(JCONST JFUNCCALL function);
        JCVOID setmouseDownFunction(JCONST JFUNCTION<JCVOID(SDL_MouseButtonEvent& mouse)> function);
        JCVOID setmouseMotionFunction(JCONST JFUNCTION<JCVOID(SDL_MouseMotionEvent& mouse)> function);
        JCVOID setmouseUpFunction(JCONST JFUNCTION<JCVOID(SDL_MouseButtonEvent& mouse)> function);

        JCONST PositionSize getSizePos() JCONST;
        JCONST Position getPos() JCONST;
        JCONST Size getSize() JCONST;

        JCDOUBLE getX() JCONST;
        JCDOUBLE getY() JCONST;
        JCDOUBLE getWidth() JCONST;
        JCDOUBLE getHeight() JCONST;
        JCBOOL getRendering() JCONST;
        JCBOOL getPickOnBounds() JCONST;
        JCBOOL getPickOnTop() JCONST;
        JCBOOL getMouseClick() JCONST;
        JDOUBLE *getPointerX();
        JDOUBLE *getPointerY();
        JDOUBLE *getPointerWidth();
        JDOUBLE *getPointerHeight();

        JVIRTUAL JUINT8 *getPointerRImage();
        JVIRTUAL JUINT8 *getPointerGImage();
        JVIRTUAL JUINT8 *getPointerBImage();
        JVIRTUAL JUINT8 *getPointerAImage();
        JVIRTUAL JUINT8 *getPointerRText();
        JVIRTUAL JUINT8 *getPointerGText();
        JVIRTUAL JUINT8 *getPointerBText();
        JVIRTUAL JUINT8 *getPointerAText();
        JVIRTUAL JCSTR getName() JCONST;

        JCONST JFUNCCALL getUpdateFunction() JCONST;
        JCONST JFUNCTION<JVOID(SDL_MouseButtonEvent &mouse)> getmouseDownFunction() JCONST;
        JCONST JFUNCTION<JVOID(SDL_MouseMotionEvent &mouse)> getmouseMotionFunction() JCONST;
        JCONST JFUNCTION<JVOID(SDL_MouseButtonEvent& mouse)> getmouseUpFunction() JCONST;

        JVIRTUAL JCBOOL mouseDownComp(SDL_MouseButtonEvent &mouse);
        JVIRTUAL JCVOID mouseMotionComp(SDL_MouseMotionEvent &mouse);
        JVIRTUAL JCVOID mouseUpComp(SDL_MouseButtonEvent &mouse);
        JVIRTUAL JCVOID renderComp();

        JCVOID updateComp();

    JPROTECTED:
        JVIRTUAL JCVOID update();
        JCVOID setMouseClick(JCBOOL set);
    };

    JCLASS BaseGradient {
    JPRIVATE:
        JDM::Gradient gradientAlignment = JDM::GRADIENT_NONE;
        ColorRGBA gradientStartColor = {0, 0, 0, 0};
        ColorRGBA gradientEndColor = {0, 0, 0, 0};

    JPRIVATE:
        JCONST JUINT8 interpolateColorComponent(JUINT8 startComponent, JUINT8 endComponent, JINT y, JINT height) JCONST;
        JCVOID renderGradient(JCONST JDM::PositionSize &posSize);
    JPUBLIC:
        JCVOID setGradientAlignment(JCONST JDM::Gradient & gradentAlignment);
        JCVOID setGradiendColor(JCONST ColorRGBA &first, JCONST ColorRGBA &second);
        JFRIEND JCLASS Image;
        JFRIEND JCLASS Label;
    };

    JCLASS BaseImage {
    JPUBLIC:
        ~BaseImage() { SDL_DestroyTexture(JTHIS->imageTexture); }

    JPRIVATE:
        JBOOL willUpdateImageTexture = JFALSE;
        JBOOL willUpdateImageColor = JFALSE;
        JBOOL willUpdateImageOpacity = JFALSE;
        JSTR sourceFiles = "";
        SDL_Texture *imageTexture;

        SDL_FRect imageDestination;
        SDL_Rect imageSource;
        ColorRGBA imageColor;

        JDM::FourArc arc;
        JINT lineWidth = 0;

    JPRIVATE:
        JCVOID setImageRectDestination(JCONST JDM::PositionSize & posSize);
        JCVOID setImageTexture(JCONST JDM::Size &size);
        JCVOID updateImageColor();
        JCVOID updateImageOpacity();
        JCVOID updateImage(JCONST JDM::PositionSize & posSize);
        JCVOID renderImage();

    JPUBLIC:
        JCVOID setImageSource(JCSTR & source);
        JCVOID setImageAndOpacityColor(JCONST JDM::ColorRGBA & color);
        JCVOID setImageColor(JCONST JDM::ColorRGB & color);
        JCVOID setImageOpacity(JCONST JUINT8 opacity);
        JCVOID setImageColorR(JUINT8 rColor);
        JCVOID setImageColorG(JUINT8 gColor);
        JCVOID setImageColorB(JUINT8 bColor);
        JCVOID setImageFourArc(JCONST JDM::FourArc & arc);
        JCVOID setImageTwoLRArc(JCONST JDM::TwoLRArc & arcLR);
        JCVOID setImageTwoTBArc(JCONST JDM::TwoTBArc &arcTB);
        JCVOID setImageLineWidth(JUINT8 lineWidth);
        JCVOID setImageRegion(JCONST JDM::Region &region);

        JDM::ColorRGBA getImageAndOpacityColor() JCONST;
        JDM::ColorRGB getImageColor() JCONST;
        JUINT8 getImageOpacity() JCONST;
        JUINT8 getImageColorR() JCONST;
        JUINT8 getImageColorG() JCONST;
        JUINT8 getImageColorB() JCONST;

        Region getImageRegion() JCONST;
        RegionF getImageDestination() JCONST;
        JDM::FourArc getImageFourArc() JCONST;
        JUINT8 getImageLineWidth() JCONST;

        SDL_Texture *getImageTexture();
        JCSTR getImageSource();

        JFRIEND JCLASS Image;
        JFRIEND JCLASS Label;
    };

    JCLASS BaseText {
    JPUBLIC: ~BaseText() { SDL_DestroyTexture(JTHIS->textTexture); }
    JPRIVATE:
        BaseText() {}

    JPRIVATE:
        JBOOL willUpdateTextTexture = JFALSE;
        JBOOL willUpdateTextColor = JFALSE;
        JBOOL willUpdateTextOpacity = JFALSE;

        JSTR textMessage;
        ColorRGBA textColor;
        SDL_Rect textSource;
        SDL_FRect textDestination;
        SDL_Texture *textTexture;

        JUINT fontSize = 15;
        JDOUBLE copyFontSize = 15;
        JDM::Font::Valign valign = JDM::Font::Valign::VCENTER;
        JDM::Font::Halign halign = JDM::Font::Halign::HCENTER;
        JDM::Font::Font font = JDM::Font::Consolas();
        JDOUBLE paddingWidth = 0;
        JDOUBLE paddingHeight = 0;

        JBOOL isBold = JFALSE;
        JBOOL isItalic = JFALSE;
        JBOOL isLimit = JFALSE;

    JPRIVATE:
        JINLINE JCVOID setTextRectDestination(JCONST JDM::PositionSize &posSize);
        JINLINE JCVOID setTextTexture();
        JINLINE JCVOID updateTextColor();
        JINLINE JCVOID updateTextOpacity();
        JINLINE JCVOID updateText(JCONST JDM::PositionSize &posSize);
        JINLINE JCVOID renderText();

    JPUBLIC:
        JCVOID setTextMessage(JCSTR & text);
        JCVOID setTextAndOpacityColor(JCONST JDM::ColorRGBA &color);
        JCVOID setTextColor(JCONST JDM::ColorRGB &color);
        JCVOID setTextOpacity(JCONST JUINT8 opacity);
        JCVOID setTextColorR(JUINT8 rColor);
        JCVOID setTextColorG(JUINT8 gColor);
        JCVOID setTextColorB(JUINT8 bColor);
        JCVOID setTextRegion(JCONST JDM::Region &region);
        JCVOID setFontSize(JCUINT size);
        JCVOID setBold(JCBOOL bold);
        JCVOID setItalic(JCBOOL italic);
        JCVOID setFont(JCONST JDM::Font::Font &font);
        JCVOID setFontRegular(JCSTR &str);
        JCVOID setFontBold(JCSTR &str);
        JCVOID setFontItalic(JCSTR &str);
        JCVOID setFontBoldItalic(JCSTR &str);
        JCVOID setValign(JDM::Font::Valign valign);
        JCVOID setHalign(JDM::Font::Halign halign);
        JCVOID setPaddingWidth(JCDOUBLE padWidth);
        JCVOID setPaddingHeight(JCDOUBLE padHeight);

        JCUINT getFontSize() JCONST;
        JCDOUBLE getCopyFontSize() JCONST;
        JCBOOL getBold() JCONST;
        JCBOOL getItalic() JCONST;
        JDM::Font::Valign getValign() JCONST;
        JDM::Font::Halign getHalign() JCONST;
        JCDOUBLE getPaddingWidth() JCONST;
        JCDOUBLE getPaddingHeight() JCONST;

        JDM::ColorRGBA getTextAndOpacityColor() JCONST;
        JDM::ColorRGB getTextColor() JCONST;
        JUINT8 getTextOpacity() JCONST;
        JUINT8 getTextColorR() JCONST;
        JUINT8 getTextColorG() JCONST;
        JUINT8 getTextColorB() JCONST;
        Region getTextRegion() JCONST;
        RegionF getTextDestination() JCONST;

        SDL_Texture *getTextTexture();
        JCSTR getText();
        JFRIEND JCLASS Text;
        JFRIEND JCLASS Label;
    };

    JCLASS Text : JPUBLIC Components, JPUBLIC BaseText {
    JPUBLIC:
        Text(
            JCSTR &text = "",
            JCDOUBLE xPos = 0,
            JCDOUBLE yPos = 0,
            JCDOUBLE Width = 100,
            JCDOUBLE Height = 100,
            JCONST JDM::ColorRGBA &color = {255, 255, 255, 255},
            JCINT fontSize = 15,
            JDM::Font::Halign hAlign = JDM::Font::HCENTER,
            JDM::Font::Valign vAlign = JDM::Font::VCENTER
        );
        JUINT8 *getPointerRText();
        JUINT8 *getPointerGText();
        JUINT8 *getPointerBText();
        JUINT8 *getPointerAText();
        JVIRTUAL JCSTR getName() JCONST;

        JCVOID update() JOVERRIDE;
        JCVOID renderComp() JOVERRIDE;
    };

    JCLASS Image : JPUBLIC Components, JPUBLIC BaseGradient, JPUBLIC BaseImage {
    JPUBLIC:
        Image(
            JCSTR &source = DefaultImage,
            JCDOUBLE xPos = 0,
            JCDOUBLE yPos = 0,
            JCDOUBLE Width = 100,
            JCDOUBLE Height = 100,
            JCONST JDM::ColorRGBA &color = {255, 255, 255, 255},
            FourArc arc = {0, 0, 0, 0}
        );
        JUINT8 *getPointerRImage();
        JUINT8 *getPointerGImage();
        JUINT8 *getPointerBImage();
        JUINT8 *getPointerAImage();
        JVIRTUAL JCSTR getName() JCONST;

        JCVOID update() JOVERRIDE;
        JCVOID renderComp() JOVERRIDE;
    };

    JCLASS Label : JPUBLIC Components, JPUBLIC BaseImage, JPUBLIC BaseText, JPUBLIC BaseGradient {
    JPUBLIC:
        Label(
            JCSTR &text = "",
            JCSTR &source = DefaultImage,
            JCDOUBLE xPos = 0,
            JCDOUBLE yPos = 0,
            JCDOUBLE Width = 100,
            JCDOUBLE Height = 100,
            JCONST ColorRGBA &color = {255, 255, 255, 255},
            JCONST ColorRGBA &colorImage = {100, 100, 100, 255},
            JCONST JDM::FourArc &arc = {0, 0, 0, 0},
            JCINT fontSize = 15,
            JDM::Font::Halign hAlign = JDM::Font::HCENTER,
            JDM::Font::Valign vAlign = JDM::Font::VCENTER
        );
        JUINT8 *getPointerRText();
        JUINT8 *getPointerGText();
        JUINT8 *getPointerBText();
        JUINT8 *getPointerAText();
        JUINT8 *getPointerRImage();
        JUINT8 *getPointerGImage();
        JUINT8 *getPointerBImage();
        JUINT8 *getPointerAImage();
        JCVOID update() JOVERRIDE;
        JCVOID renderComp() JOVERRIDE;
    };
    JCLASS Button : JPUBLIC Label {
    JPRIVATE:
        ColorRGBA originalColor;
        ColorRGBA clickedColor;
        ColorRGBA hoverColor;
        JBOOL clicked = JFALSE;
        JBOOL isHoverable = JFALSE;

    JPUBLIC:
        Button(
            JCSTR &text = "",
            JCSTR &source = DefaultImage,
            JCDOUBLE xPos = 0,
            JCDOUBLE yPos = 0,
            JCDOUBLE Width = 100,
            JCDOUBLE Height = 100,
            JCONST ColorRGBA &color = {255, 255, 255, 255},
            JCONST ColorRGBA &colorImage = {100, 100, 100, 255},
            JCONST JDM::FourArc &arc = {0, 0, 0, 0},
            JCINT fontSize = 15,
            JDM::Font::Halign hAlign = JDM::Font::HCENTER,
            JDM::Font::Valign vAlign = JDM::Font::VCENTER,
            JCONST ColorRGBA &colorClick = {50, 50, 50, 255},
            JCONST ColorRGBA &colorHover = {255, 255, 255, 255}
        );
        JCBOOL mouseDownComp(SDL_MouseButtonEvent &mouse);
        JCVOID setOriginalColor(JCONST ColorRGBA &color);
        JCVOID setClickedColor(JCONST ColorRGBA &color);
        JCVOID setHoverColor(JCONST ColorRGBA &color);
        JCVOID mouseUpComp(SDL_MouseButtonEvent &mouse);
        JCVOID update();
    };
    JCLASS FocusedTextComponent : JPUBLIC Label {
    JPROTECTED:
        FocusedTextComponent(
            JCSTR &text = "DefaultText",
            JCSTR &source = DefaultImage,
            JCDOUBLE xPos = 0,
            JCDOUBLE yPos = 0,
            JCDOUBLE Width = 100,
            JCDOUBLE Height = 100,
            JCONST JDM::ColorRGBA &color = JDM::getColorFromHexA("111111ff"),
            JCONST JDM::ColorRGBA &colorImage = JDM::getColorFromHexA("ccccccff"),
            JCONST JDM::FourArc &arc = {30, 30, 30, 30},
            JCINT fontSize = 15,
            JDM::Font::Halign hAlign = JDM::Font::LEFT,
            JDM::Font::Valign vAlign = JDM::Font::VCENTER
        );
    JPUBLIC:
        JBOOL isFocused = JFALSE;
        JINT index = -1;
        JFUNCCALL functionEnter = []() {};
        JVIRTUAL JCSTR getName() { JRETURN "FocusedTextComponent"; }
    };
    JCLASS TextInput : JPUBLIC FocusedTextComponent {
    JPRIVATE:
        JBOOL blinked = JFALSE;
        JDOUBLE blinkDuration = 0.3;
        JDOUBLE currentBlink = blinkDuration;
        ColorRGBA colorCursor = {180, 180, 180, 255};
    JPUBLIC:
        TextInput(
            JCSTR &text = "DefaultText",
            JCSTR &source = DefaultImage,
            JCDOUBLE xPos = 0,
            JCDOUBLE yPos = 0,
            JCDOUBLE Width = 100,
            JCDOUBLE Height = 100,
            JCONST JDM::ColorRGBA &color = JDM::getColorFromHexA("111111ff"),
            JCONST JDM::ColorRGBA &colorImage = JDM::getColorFromHexA("ccccccff"),
            JCONST JDM::FourArc &arc = {30, 30, 30, 30},
            JCINT fontSize = 15,
            JDM::Font::Halign hAlign = JDM::Font::LEFT,
            JDM::Font::Valign vAlign = JDM::Font::VCENTER
        );
        JCVOID setCursorColor(JCONST ColorRGBA &color);
        JCVOID renderComp() JOVERRIDE;
    };
}};

#endif