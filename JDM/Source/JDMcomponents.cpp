#include "JDM/Header/JDMcomponents.hpp"

/////////////////////////////////////////////////////////////////////////////////////
// COMPONENTS
/////////////////////////////////////////////////////////////////////////////;///////
JDM::Comp::Components::Components(
    JCDOUBLE xPos,
    JCDOUBLE yPos,
    JCDOUBLE Width,
    JCDOUBLE Height
) : sizePos({xPos, yPos, Width, Height}) {}
JCBOOL JDM::Comp::Components::contains(JCDOUBLE xPos, JCDOUBLE yPos) JCONST {
    JRETURN ((JTHIS->getX() <= xPos && (JTHIS->getX() + JTHIS->getWidth()) >= xPos)
        && (JTHIS->getY() <= yPos && (JTHIS->getY() + JTHIS->getHeight()) >= yPos));
}
JCVOID JDM::Comp::Components::setSizePos(JCONST JDM::PositionSize &sPos) { JTHIS->sizePos = sPos; }
JCVOID JDM::Comp::Components::setPos(JCONST JDM::Position &pos) { JTHIS->sizePos.pos = pos; }
JCVOID JDM::Comp::Components::setSize(JCONST JDM::Size &size) { JTHIS->sizePos.size = size; }
JCVOID JDM::Comp::Components::setX(JCDOUBLE xPos) { JTHIS->sizePos.x = xPos; }
JCVOID JDM::Comp::Components::setY(JCDOUBLE yPos) { JTHIS->sizePos.y = yPos; }
JCVOID JDM::Comp::Components::setWidth(JCDOUBLE Width) { JTHIS->sizePos.width = Width; }
JCVOID JDM::Comp::Components::setHeight(JCDOUBLE Height) { JTHIS->sizePos.height = Height; }

JCVOID JDM::Comp::Components::setPickOnBounds(JCBOOL bounds) { JTHIS->pickOnBounds = bounds; }
JCVOID JDM::Comp::Components::setPickOnTop(JCBOOL top) { JTHIS->pickOnTop = top; }
JCVOID JDM::Comp::Components::setRendering(JCBOOL isRendering) { JTHIS->stopRendering = !isRendering; }
JCVOID JDM::Comp::Components::setUpdateFunction(JCONST JFUNCCALL function) { JTHIS->updateFunction = function; }
JCVOID JDM::Comp::Components::setmouseDownFunction(JCONST JFUNCTION<JCVOID(SDL_MouseButtonEvent& mouse)> function) { JTHIS->mouseDownFunction = function; }
JCVOID JDM::Comp::Components::setmouseMotionFunction(JCONST JFUNCTION<JCVOID(SDL_MouseMotionEvent& mouse)> function) { JTHIS->mouseMotionFunction = function; }
JCVOID JDM::Comp::Components::setmouseUpFunction(JCONST JFUNCTION<JCVOID(SDL_MouseButtonEvent& mouse)> function) { JTHIS->mouseUpFunction = function; }

JCONST JDM::PositionSize JDM::Comp::Components::getSizePos() JCONST { JRETURN JTHIS->sizePos; }
JCONST JDM::Position JDM::Comp::Components::getPos() JCONST { JRETURN JTHIS->sizePos.pos; }
JCONST JDM::Size JDM::Comp::Components::getSize() JCONST { JRETURN JTHIS->sizePos.size; }
JCDOUBLE JDM::Comp::Components::getX() JCONST { JRETURN JTHIS->sizePos.x; }
JCDOUBLE JDM::Comp::Components::getY() JCONST { JRETURN JTHIS->sizePos.y; }
JCDOUBLE JDM::Comp::Components::getWidth() JCONST { JRETURN JTHIS->sizePos.width; }
JCDOUBLE JDM::Comp::Components::getHeight() JCONST { JRETURN JTHIS->sizePos.height; }
JCBOOL JDM::Comp::Components::getRendering() JCONST { JRETURN !JTHIS->stopRendering; }
JCBOOL JDM::Comp::Components::getPickOnBounds() JCONST { JRETURN JTHIS->pickOnBounds; }
JCBOOL JDM::Comp::Components::getPickOnTop() JCONST { JRETURN JTHIS->pickOnTop; }
JCBOOL JDM::Comp::Components::getMouseClick() JCONST { JRETURN JTHIS->mouseClicked; }
JCSTR JDM::Comp::Components::getName() JCONST { JRETURN "Components"; }

JDOUBLE *JDM::Comp::Components::getPointerX() { JRETURN &JTHIS->sizePos.x; }
JDOUBLE *JDM::Comp::Components::getPointerY() { JRETURN &JTHIS->sizePos.y; }
JDOUBLE *JDM::Comp::Components::getPointerWidth() { JRETURN &JTHIS->sizePos.width; }
JDOUBLE *JDM::Comp::Components::getPointerHeight() { JRETURN &JTHIS->sizePos.height; }

JUINT8 *JDM::Comp::Components::getPointerRImage() { JRETURN JNULLPTR; }
JUINT8 *JDM::Comp::Components::getPointerGImage() { JRETURN JNULLPTR; }
JUINT8 *JDM::Comp::Components::getPointerBImage() { JRETURN JNULLPTR; }
JUINT8 *JDM::Comp::Components::getPointerAImage() { JRETURN JNULLPTR; }

JUINT8 *JDM::Comp::Components::getPointerRText() { JRETURN JNULLPTR; }
JUINT8 *JDM::Comp::Components::getPointerGText() { JRETURN JNULLPTR; }
JUINT8 *JDM::Comp::Components::getPointerBText() { JRETURN JNULLPTR; }
JUINT8 *JDM::Comp::Components::getPointerAText() { JRETURN JNULLPTR; }

JCONST JFUNCCALL JDM::Comp::Components::getUpdateFunction() JCONST { JRETURN JTHIS->updateFunction; }
JCONST JFUNCTION<JVOID(SDL_MouseButtonEvent& mouse)> JDM::Comp::Components::getmouseDownFunction() JCONST { JRETURN JTHIS->mouseDownFunction; }
JCONST JFUNCTION<JVOID(SDL_MouseMotionEvent& mouse)> JDM::Comp::Components::getmouseMotionFunction() JCONST { JRETURN JTHIS->mouseMotionFunction; }
JCONST JFUNCTION<JVOID(SDL_MouseButtonEvent& mouse)> JDM::Comp::Components::getmouseUpFunction() JCONST { JRETURN JTHIS->mouseUpFunction; }

JCVOID JDM::Comp::Components::updateComp() { JTHIS->update(); JTHIS->updateFunction(); }
JCBOOL JDM::Comp::Components::mouseDownComp(SDL_MouseButtonEvent &mouse) {
    JIF (JTHIS->pickOnBounds) {
        JIF(JTHIS->pickOnTop && JDM::alreadyTouched) JRETURN JFALSE;
        JIF (JTHIS->contains(mouse.x, mouse.y)) {
            JTHIS->mouseDownFunction(mouse);
            JTHIS->mouseClicked = JTRUE;
            JDM::alreadyTouched = JTRUE;
            JRETURN JTRUE;
        }
    } JRETURN JFALSE;
}
JCVOID JDM::Comp::Components::mouseMotionComp(SDL_MouseMotionEvent &mouse) { JIF (JTHIS->mouseClicked) JTHIS->mouseMotionFunction(mouse); }
JCVOID JDM::Comp::Components::mouseUpComp(SDL_MouseButtonEvent &mouse) { JIF (JTHIS->mouseClicked) { JTHIS->mouseClicked = JFALSE; JTHIS->mouseUpFunction(mouse);  }}
JCVOID JDM::Comp::Components::renderComp() {}
JCVOID JDM::Comp::Components::update() {}
JCVOID JDM::Comp::Components::setMouseClick(JCBOOL set) { JTHIS->mouseClicked = set;  }
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //







/////////////////////////////////////////////////////////////////////////////;///////
// BASE GRADIENT
/////////////////////////////////////////////////////////////////////////////;///////
JCONST JUINT8 JDM::Comp::BaseGradient::interpolateColorComponent(JUINT8 startComponent, JUINT8 endComponent, JINT y, JINT height) JCONST {
    JRETURN startComponent + ((endComponent - startComponent) * y) / height;
}
JCVOID JDM::Comp::BaseGradient::renderGradient(JCONST JDM::PositionSize &posSize) {
    JAUTO drawLine = [&](JCINT index, JCINT size, JCONST JDM::LinePoints &points) {
        JUINT8 r = JTHIS->interpolateColorComponent(JTHIS->gradientStartColor.r, JTHIS->gradientEndColor.r, index, size);
        JUINT8 g = JTHIS->interpolateColorComponent(JTHIS->gradientStartColor.g, JTHIS->gradientEndColor.g, index, size);
        JUINT8 b = JTHIS->interpolateColorComponent(JTHIS->gradientStartColor.b, JTHIS->gradientEndColor.b, index, size);
        JUINT8 a = JTHIS->interpolateColorComponent(JTHIS->gradientStartColor.a, JTHIS->gradientEndColor.a, index, size);
        SDL_SetRenderDrawBlendMode(JDM::renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(JDM::renderer, r, g, b, a);
        SDL_RenderDrawLine(JDM::renderer, points.x1, points.y1, points.x2, points.y2);
        SDL_SetRenderDrawBlendMode(JDM::renderer, SDL_BLENDMODE_NONE);
    };
    JIF (JTHIS->gradientAlignment == JDM::GRADIENT_VERTICAL)
        JFOR (JINT y = 0; y < posSize.height; y++)
            drawLine(y, posSize.height, {posSize.x, posSize.y + y, posSize.x + posSize.width, posSize.y + y});
    JELSE JIF (JTHIS->gradientAlignment == JDM::GRADIENT_HORIZONTAL)
        JFOR (JINT x = 0; x < posSize.width; x++)
            drawLine(x, posSize.width, {posSize.x + x, posSize.y, posSize.x + x, posSize.y + posSize.y});
}
JCVOID JDM::Comp::BaseGradient::setGradientAlignment(JCONST JDM::Gradient &gradentAlignment) { JTHIS->gradientAlignment = gradentAlignment; }
JCVOID JDM::Comp::BaseGradient::setGradiendColor(JCONST ColorRGBA &first, JCONST ColorRGBA &second) {
    JTHIS->gradientStartColor = first;
    JTHIS->gradientEndColor = second;
}
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //





/////////////////////////////////////////////////////////////////////////////;///////
// BASE IMAGE
/////////////////////////////////////////////////////////////////////////////;///////
JCVOID JDM::Comp::BaseImage::setImageRectDestination(JCONST JDM::PositionSize &posSize) {
    JTHIS->imageDestination.w = posSize.width;
    JTHIS->imageDestination.h = posSize.height;
    JTHIS->imageDestination.x = posSize.x;
    JTHIS->imageDestination.y = posSize.y;
}
JCVOID JDM::Comp::BaseImage::setImageTexture(JCONST JDM::Size &size) {
    JTHIS->willUpdateImageTexture = JFALSE;
    JTHIS->imageTexture = JDM::loadRoundedTexture(size, JTHIS->sourceFiles.c_str(),
        JTHIS->arc, JTHIS->lineWidth);
    JTHIS->imageSource.x = 0;
    JTHIS->imageSource.y = 0;
    SDL_QueryTexture(JTHIS->imageTexture, NULL, NULL, &JTHIS->imageSource.w, &JTHIS->imageSource.h);
    SDL_SetTextureBlendMode(JTHIS->imageTexture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureScaleMode(JTHIS->imageTexture, SDL_ScaleMode::SDL_ScaleModeLinear);
    JTHIS->updateImageColor();
    JTHIS->updateImageOpacity();
}
JCVOID JDM::Comp::BaseImage::updateImageColor() {
    JTHIS->willUpdateImageColor = JFALSE;
    SDL_SetTextureColorMod(JTHIS->imageTexture, JTHIS->imageColor.r, JTHIS->imageColor.g, JTHIS->imageColor.b);
}
JCVOID JDM::Comp::BaseImage::updateImageOpacity() {
    JTHIS->willUpdateImageOpacity = JFALSE;
    SDL_SetTextureAlphaMod(JTHIS->imageTexture, JTHIS->imageColor.a);
}
JCVOID JDM::Comp::BaseImage::updateImage(JCONST JDM::PositionSize &posSize) {
    JTHIS->setImageRectDestination(posSize);
    JIF(JTHIS->willUpdateImageTexture) JTHIS->setImageTexture(posSize.size);
    JIF(JTHIS->willUpdateImageColor) JTHIS->updateImageColor();
    JIF(JTHIS->willUpdateImageOpacity) JTHIS->updateImageOpacity();
}
JCVOID JDM::Comp::BaseImage::renderImage() { SDL_RenderCopyF(JDM::renderer, JTHIS->imageTexture, &JTHIS->imageSource, &JTHIS->imageDestination); }
JCVOID JDM::Comp::BaseImage::setImageSource(JCSTR &source) {
    JIF (JTHIS->sourceFiles == source) JRETURN;
    JTHIS->sourceFiles = ((JDM::isFileExist(source)) ? source : DefaultImage);
    JTHIS->willUpdateImageTexture = JTRUE;
}
JCVOID JDM::Comp::BaseImage::setImageAndOpacityColor(JCONST JDM::ColorRGBA &color) {
    JIF (color.r != JTHIS->imageColor.r
      && color.g != JTHIS->imageColor.g
      && color.b != JTHIS->imageColor.b
      && color.a != JTHIS->imageColor.a
    ) {
        JTHIS->imageColor = color;
        JTHIS->willUpdateImageColor = JTRUE;
        JTHIS->willUpdateImageOpacity = JTRUE;
    }
}
JCVOID JDM::Comp::BaseImage::setImageColor(JCONST JDM::ColorRGB &color) {
    JIF (color.r != JTHIS->imageColor.r
      && color.g != JTHIS->imageColor.g
      && color.b != JTHIS->imageColor.b
    ) {
        JTHIS->imageColor.rgb = color;
        JTHIS->willUpdateImageColor = JTRUE;
    }
}
JCVOID JDM::Comp::BaseImage::setImageOpacity(JCONST JUINT8 opacity) {
    JIF (JTHIS->imageColor.a != opacity) {
        JTHIS->willUpdateImageOpacity = JTRUE;
        JTHIS->imageColor.a = opacity;
    }
}
JCVOID JDM::Comp::BaseImage::setImageColorR(JUINT8 rColor) {
    JIF (JTHIS->imageColor.r != rColor) {
        JTHIS->willUpdateImageColor = JTRUE;
        JTHIS->imageColor.r = rColor;
    }
}
JCVOID JDM::Comp::BaseImage::setImageColorG(JUINT8 gColor) {
    JIF (JTHIS->imageColor.g != gColor) {
        JTHIS->willUpdateImageColor = JTRUE;
        JTHIS->imageColor.g = gColor;
    }
}
JCVOID JDM::Comp::BaseImage::setImageColorB(JUINT8 bColor) {
    JIF (JTHIS->imageColor.b != bColor) {
        JTHIS->willUpdateImageColor = JTRUE;
        JTHIS->imageColor.b = bColor;
    }
}
JCVOID JDM::Comp::BaseImage::setImageFourArc(JCONST JDM::FourArc &arc) {
    JIF (!(arc.topLeft != JTHIS->arc.topLeft
      && arc.topRight != JTHIS->arc.topRight
      && arc.bottomLeft != JTHIS->arc.bottomLeft
      && arc.bottomRight != JTHIS->arc.bottomRight
    )) JRETURN;
    JTHIS->arc = arc;
    JTHIS->willUpdateImageTexture = JTRUE;
}
JCVOID JDM::Comp::BaseImage::setImageTwoLRArc(JCONST JDM::TwoLRArc &arcLR) {
    JIF (!(arcLR.leftArc != JTHIS->arc.topLeft
      && arcLR.rightArc != JTHIS->arc.topRight
      && arcLR.leftArc != JTHIS->arc.bottomLeft
      && arcLR.rightArc != JTHIS->arc.bottomRight
    )) JRETURN;
    JTHIS->arc.topLeft = JTHIS->arc.bottomLeft = arcLR.leftArc;
    JTHIS->arc.topRight = JTHIS->arc.bottomRight = arcLR.rightArc;
    JTHIS->willUpdateImageTexture = JTRUE;
}
JCVOID JDM::Comp::BaseImage::setImageTwoTBArc(JCONST JDM::TwoTBArc &arcTB) {
    JIF (!(arcTB.topArc != JTHIS->arc.topLeft
      && arcTB.topArc != JTHIS->arc.topRight
      && arcTB.bottomArc != JTHIS->arc.bottomLeft
      && arcTB.bottomArc != JTHIS->arc.bottomRight
    )) JRETURN;
    JTHIS->arc.topLeft = JTHIS->arc.topRight = arcTB.topArc;
    JTHIS->arc.bottomLeft = JTHIS->arc.bottomRight = arcTB.bottomArc;
    JTHIS->willUpdateImageTexture = JTRUE;
}
JCVOID JDM::Comp::BaseImage::setImageLineWidth(JUINT8 lineWidth) {
     JIF (JTHIS->imageColor.b != lineWidth) {
        JTHIS->willUpdateImageTexture = JTRUE;
        JTHIS->lineWidth = lineWidth;
     }
}
JCVOID JDM::Comp::BaseImage::setImageRegion(JCONST JDM::Region &region) { JTHIS->imageSource = { region.x, region.y, region.w, region.h }; }
JDM::ColorRGBA JDM::Comp::BaseImage::getImageAndOpacityColor() JCONST { JRETURN JTHIS->imageColor; }
JDM::ColorRGB JDM::Comp::BaseImage::getImageColor() JCONST { JRETURN JTHIS->imageColor.rgb; }
JUINT8 JDM::Comp::BaseImage::getImageOpacity() JCONST { JRETURN JTHIS->imageColor.a; }
JUINT8 JDM::Comp::BaseImage::getImageColorR() JCONST { JRETURN JTHIS->imageColor.r; }
JUINT8 JDM::Comp::BaseImage::getImageColorG() JCONST { JRETURN JTHIS->imageColor.g; }
JUINT8 JDM::Comp::BaseImage::getImageColorB() JCONST { JRETURN JTHIS->imageColor.b; }
JDM::Region JDM::Comp::BaseImage::getImageRegion() JCONST { JRETURN { JTHIS->imageSource.x, JTHIS->imageSource.y, JTHIS->imageSource.w, JTHIS->imageSource.h }; }
JDM::RegionF JDM::Comp::BaseImage::getImageDestination() JCONST { JRETURN { JTHIS->imageDestination.x, JTHIS->imageDestination.y, JTHIS->imageDestination.w, JTHIS->imageDestination.h }; }
JDM::FourArc JDM::Comp::BaseImage::getImageFourArc() JCONST { JRETURN JTHIS->arc; }
JUINT8 JDM::Comp::BaseImage::getImageLineWidth() JCONST { JRETURN JTHIS->lineWidth; }
SDL_Texture *JDM::Comp::BaseImage::getImageTexture() { JRETURN JTHIS->imageTexture; }
JCSTR JDM::Comp::BaseImage::getImageSource() { JRETURN JTHIS->sourceFiles; }
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //






/////////////////////////////////////////////////////////////////////////////;///////
// BASE TEXT
/////////////////////////////////////////////////////////////////////////////;///////
JCVOID JDM::Comp::BaseText::setTextRectDestination(JCONST JDM::PositionSize &posSize) {
    // Calculate Text Size with FontSize
    JTHIS->textDestination.w = JSTATICC<JFLOAT>(JTHIS->textMessage.length() * JTHIS->fontSize);
    JIF (posSize.width - (JTHIS->paddingWidth*2) < JTHIS->textDestination.w) {
        JTHIS->textDestination.w = (posSize.width - (JTHIS->paddingWidth * 2));
        JTHIS->copyFontSize = JTHIS->textDestination.w / JTHIS->textMessage.length();
    } JELSE JTHIS->copyFontSize = JTHIS->fontSize;
    JTHIS->textDestination.h = JSTATICC<JFLOAT>(JTHIS->fontSize + (JTHIS->fontSize));
    // Set X, Y of the text in the Rect Size Box
    JSWITCH (JTHIS->halign) {
        JCASE JDM::Font::Halign::LEFT: JTHIS->textDestination.x = posSize.x + JTHIS->paddingWidth; JBREAK;
        JCASE JDM::Font::Halign::HCENTER: JTHIS->textDestination.x = posSize.x + ((posSize.width - JTHIS->textDestination.w) / 2.f); JBREAK;
        JCASE JDM::Font::Halign::RIGHT: JTHIS->textDestination.x = posSize.x + (posSize.width - JTHIS->textDestination.w) - JTHIS->paddingWidth; JBREAK;
    }
    JSWITCH (JTHIS->valign) {
        JCASE JDM::Font::Valign::TOP: JTHIS->textDestination.y = posSize.y - JTHIS->paddingHeight; JBREAK;
        JCASE JDM::Font::Valign::VCENTER: JTHIS->textDestination.y = posSize.y + ((posSize.height - JTHIS->textDestination.h) / 2.f); JBREAK;
        JCASE JDM::Font::Valign::BOTTOM: JTHIS->textDestination.y = posSize.y + (posSize.height - JTHIS->textDestination.h) + JTHIS->paddingHeight; JBREAK;
    }
}
JCVOID JDM::Comp::BaseText::setTextTexture() {
   JTHIS->textTexture = loadTextTexture(
        ((JTHIS->isBold && JTHIS->isItalic) ?     
            JTHIS->font.ItalicBold.c_str() : ((JTHIS->isBold) ? 
            JTHIS->font.Bold.c_str() : ((JTHIS->isItalic) ?
            JTHIS->font.Italic.c_str() : JTHIS->font.Normal.c_str()))),
        JTHIS->textMessage.c_str(), JTHIS->textColor);
    JTHIS->textSource.x = 0;
    JTHIS->textSource.y = 0;
    SDL_QueryTexture(JTHIS->textTexture, NULL, NULL, &JTHIS->textSource.w, &JTHIS->textSource.h);
    SDL_SetTextureBlendMode(JTHIS->textTexture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureScaleMode(JTHIS->textTexture, SDL_ScaleMode::SDL_ScaleModeLinear);
    JTHIS->updateTextColor();
    JTHIS->updateTextOpacity();
}
JCVOID JDM::Comp::BaseText::updateTextColor() {
    JTHIS->willUpdateTextColor = JFALSE;
    SDL_SetTextureColorMod(JTHIS->textTexture, JTHIS->textColor.r, JTHIS->textColor.g, JTHIS->textColor.b);
}
JCVOID JDM::Comp::BaseText::updateTextOpacity() {
    JTHIS->willUpdateTextOpacity = JFALSE;
    SDL_SetTextureAlphaMod(JTHIS->textTexture, JTHIS->textColor.a);
}
JCVOID JDM::Comp::BaseText::updateText(JCONST JDM::PositionSize &posSize) {
    JTHIS->setTextRectDestination(posSize);
    JIF(JTHIS->willUpdateTextTexture) JTHIS->setTextTexture();
    JIF(JTHIS->willUpdateTextColor) JTHIS->updateTextColor();
   JIF(JTHIS->willUpdateTextOpacity) JTHIS->updateTextOpacity();
}
JCVOID JDM::Comp::BaseText::renderText() { SDL_RenderCopyF(JDM::renderer, JTHIS->textTexture, &JTHIS->textSource, &JTHIS->textDestination); }
JCVOID JDM::Comp::BaseText::setTextMessage(JCSTR &text) {
    JIF (JTHIS->textMessage == text) JRETURN;
    JTHIS->textMessage = text;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setTextAndOpacityColor(JCONST JDM::ColorRGBA &color) {
    JIF (color.r != JTHIS->textColor.r
      && color.g != JTHIS->textColor.g
      && color.b != JTHIS->textColor.b
      && color.a != JTHIS->textColor.a
    ) {
        JTHIS->textColor = color;
        JTHIS->willUpdateTextColor = JTRUE;
        JTHIS->willUpdateTextOpacity = JTRUE;
    }
}
JCVOID JDM::Comp::BaseText::setTextColor(JCONST JDM::ColorRGB &color) {
    JIF (color.r != JTHIS->textColor.r
      && color.g != JTHIS->textColor.g
      && color.b != JTHIS->textColor.b
    ) {
        JTHIS->textColor.rgb = color;
        JTHIS->willUpdateTextColor = JTRUE;
    }
}
JCVOID JDM::Comp::BaseText::setTextOpacity(JCONST JUINT8 opacity) {
    JIF (JTHIS->textColor.a != opacity) {
        JTHIS->willUpdateTextOpacity = JTRUE;
        JTHIS->textColor.a = opacity;
    }
}
JCVOID JDM::Comp::BaseText::setTextColorR(JUINT8 rColor) {
    JIF (JTHIS->textColor.r != rColor) {
        JTHIS->willUpdateTextColor = JTRUE;
        JTHIS->textColor.r = rColor;
    }
}
JCVOID JDM::Comp::BaseText::setTextColorG(JUINT8 gColor) {
    JIF (JTHIS->textColor.g != gColor) {
        JTHIS->willUpdateTextColor = JTRUE;
        JTHIS->textColor.g = gColor;
    }
}
JCVOID JDM::Comp::BaseText::setTextColorB(JUINT8 bColor) {
    JIF (JTHIS->textColor.b != bColor) {
        JTHIS->willUpdateTextColor = JTRUE;
        JTHIS->textColor.b = bColor;
    }
}
JCVOID JDM::Comp::BaseText::setTextRegion(JCONST JDM::Region &region) { JTHIS->textSource = { region.x, region.y, region.w, region.h }; }
JCVOID JDM::Comp::BaseText::setFontSize(JCUINT size) { JTHIS->fontSize = size; }
JCVOID JDM::Comp::BaseText::setBold(JCBOOL bold) {
    JIF (JTHIS->isBold == bold) JRETURN;
    JTHIS->isBold = bold;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setItalic(JCBOOL italic) {
    JIF (JTHIS->isItalic == italic) JRETURN;
    JTHIS->isItalic = italic;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setFont(JCONST JDM::Font::Font &font) {
    JIF ((JTHIS->font.Normal == font.Normal
       && JTHIS->font.Bold == font.Bold
       && JTHIS->font.Italic == font.Italic
       && JTHIS->font.ItalicBold == font.ItalicBold
    )) JRETURN;
    JTHIS->font = font;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setFontRegular(JCSTR &str) {
    JIF (JTHIS->font.Normal == str) JRETURN;
    JTHIS->font.Normal = str;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setFontBold(JCSTR &str) {
    JIF (JTHIS->font.Bold == str) JRETURN;
    JTHIS->font.Bold = str;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setFontItalic(JCSTR &str) {
    JIF (JTHIS->font.Italic == str) JRETURN;
    JTHIS->font.Italic = str;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setFontBoldItalic(JCSTR &str) {
    JIF (JTHIS->font.ItalicBold == str) JRETURN;
    JTHIS->font.ItalicBold = str;
    JTHIS->willUpdateTextTexture = JTRUE;
}
JCVOID JDM::Comp::BaseText::setValign(JDM::Font::Valign valign) { JTHIS->valign = valign; }
JCVOID JDM::Comp::BaseText::setHalign(JDM::Font::Halign halign) { JTHIS->halign = halign; }
JCVOID JDM::Comp::BaseText::setPaddingWidth(JCDOUBLE padWidth) { JTHIS->paddingWidth = padWidth; }
JCVOID JDM::Comp::BaseText::setPaddingHeight(JCDOUBLE padHeight) { JTHIS->paddingHeight = padHeight; }
JCUINT JDM::Comp::BaseText::getFontSize() JCONST { JRETURN JTHIS->fontSize; }
JCDOUBLE JDM::Comp::BaseText::getCopyFontSize() JCONST { JRETURN JTHIS->copyFontSize; }
JCBOOL JDM::Comp::BaseText::getBold() JCONST { JRETURN JTHIS->isBold; }
JCBOOL JDM::Comp::BaseText::getItalic() JCONST { JRETURN JTHIS->isItalic; }
JDM::Font::Valign JDM::Comp::BaseText::getValign() JCONST { JRETURN JTHIS->valign; }
JDM::Font::Halign JDM::Comp::BaseText::getHalign() JCONST { JRETURN JTHIS->halign; }
JCDOUBLE JDM::Comp::BaseText::getPaddingWidth() JCONST { JRETURN JTHIS->paddingWidth; }
JCDOUBLE JDM::Comp::BaseText::getPaddingHeight() JCONST { JRETURN JTHIS->paddingHeight; }
JDM::ColorRGBA JDM::Comp::BaseText::getTextAndOpacityColor() JCONST { JRETURN JTHIS->textColor; }
JDM::ColorRGB JDM::Comp::BaseText::getTextColor() JCONST { JRETURN JTHIS->textColor.rgb; }
JUINT8 JDM::Comp::BaseText::getTextOpacity() JCONST { JRETURN JTHIS->textColor.a; }
JUINT8 JDM::Comp::BaseText::getTextColorR() JCONST { JRETURN JTHIS->textColor.r; }
JUINT8 JDM::Comp::BaseText::getTextColorG() JCONST { JRETURN JTHIS->textColor.g; }
JUINT8 JDM::Comp::BaseText::getTextColorB() JCONST { JRETURN JTHIS->textColor.b; }
JDM::Region JDM::Comp::BaseText::getTextRegion() JCONST { JRETURN { JTHIS->textSource.x, JTHIS->textSource.y, JTHIS->textSource.w, JTHIS->textSource.h }; }
JDM::RegionF JDM::Comp::BaseText::getTextDestination() JCONST { JRETURN { JTHIS->textDestination.x, JTHIS->textDestination.y, JTHIS->textDestination.w, JTHIS->textDestination.h }; }
SDL_Texture *JDM::Comp::BaseText::getTextTexture() { JRETURN JTHIS->textTexture; }
JCSTR JDM::Comp::BaseText::getText() { JRETURN JTHIS->textMessage; }
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //





/////////////////////////////////////////////////////////////////////////////;///////
// TEXT
/////////////////////////////////////////////////////////////////////////////;///////
JDM::Comp::Text::Text(
    JCSTR &text,
    JCDOUBLE xPos,
    JCDOUBLE yPos,
    JCDOUBLE Width,
    JCDOUBLE Height,
    JCONST JDM::ColorRGBA &color,
    JCINT fontSize,
    JDM::Font::Halign hAlign,
    JDM::Font::Valign vAlign
) : JDM::Comp::Components(xPos, yPos, Width, Height) {
    JTHIS->setTextMessage(text);
    JTHIS->textColor = color;
    JTHIS->fontSize = fontSize;
    JTHIS->halign = hAlign;
    JTHIS->valign = vAlign;
    JTHIS->setTextTexture();
}
JUINT8 *JDM::Comp::Text::getPointerRText() { JRETURN &JTHIS->textColor.r; }
JUINT8 *JDM::Comp::Text::getPointerGText() { JRETURN &JTHIS->textColor.g; }
JUINT8 *JDM::Comp::Text::getPointerBText() { JRETURN &JTHIS->textColor.b; }
JUINT8 *JDM::Comp::Text::getPointerAText() { JRETURN &JTHIS->textColor.a; }
JCSTR JDM::Comp::Text::getName() JCONST { JRETURN "Text"; }
JCVOID JDM::Comp::Text::update() {
    JTHIS->updateText(JTHIS->getSizePos());
}
JCVOID JDM::Comp::Text::renderComp() {
    JIF (IsTextureInWindow(JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight())) {
        JTHIS->renderText();
    }
}
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //





/////////////////////////////////////////////////////////////////////////////;///////
// IMAGE
/////////////////////////////////////////////////////////////////////////////;///////
JDM::Comp::Image::Image(
    JCSTR &source,
    JCDOUBLE xPos,
    JCDOUBLE yPos,
    JCDOUBLE Width,
    JCDOUBLE Height,
    JCONST JDM::ColorRGBA &color,
    FourArc arc
) : JDM::Comp::Components(xPos, yPos, Width, Height) {
    JTHIS->setImageSource(source);
    JTHIS->imageColor = color;
    JTHIS->arc = arc;
    JTHIS->setImageTexture(JTHIS->getSize());
}
JUINT8 *JDM::Comp::Image::getPointerRImage() { JRETURN &JTHIS->imageColor.r; }
JUINT8 *JDM::Comp::Image::getPointerGImage() { JRETURN &JTHIS->imageColor.g; }
JUINT8 *JDM::Comp::Image::getPointerBImage() { JRETURN &JTHIS->imageColor.b; }
JUINT8 *JDM::Comp::Image::getPointerAImage() { JRETURN &JTHIS->imageColor.a; }
JCSTR JDM::Comp::Image::getName() JCONST { JRETURN "Image"; }
JCVOID JDM::Comp::Image::update() {
    JTHIS->updateImage(JTHIS->getSizePos());
}
JCVOID JDM::Comp::Image::renderComp() {
    JIF (JDM::IsTextureInWindow(JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight())) {
        JTHIS->renderImage();
        JTHIS->renderGradient(JTHIS->getSizePos());
    }
}
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //






/////////////////////////////////////////////////////////////////////////////;///////
// LABEL
/////////////////////////////////////////////////////////////////////////////;///////
JDM::Comp::Label::Label(
    JCSTR &text,
    JCSTR &source,
    JCDOUBLE xPos,
    JCDOUBLE yPos,
    JCDOUBLE Width,
    JCDOUBLE Height,
    JCONST ColorRGBA &color,
    JCONST ColorRGBA &colorImage,
    JCONST JDM::FourArc &arc,
    JCINT fontSize,
    JDM::Font::Halign hAlign,
    JDM::Font::Valign vAlign
) : JDM::Comp::Components(xPos, yPos, Width, Height) {
    JTHIS->setTextMessage(text);
    JTHIS->setImageSource(source);
    JTHIS->textColor = color;
    JTHIS->imageColor = colorImage;
    JTHIS->arc = arc;
    JTHIS->fontSize = fontSize;
    JTHIS->halign = hAlign;
    JTHIS->valign = vAlign;
    JTHIS->setTextTexture();
    JTHIS->setImageTexture(JTHIS->getSize());
}
JUINT8 *JDM::Comp::Label::getPointerRText() { JRETURN &JTHIS->textColor.r; }
JUINT8 *JDM::Comp::Label::getPointerGText() { JRETURN &JTHIS->textColor.g; }
JUINT8 *JDM::Comp::Label::getPointerBText() { JRETURN &JTHIS->textColor.b; }
JUINT8 *JDM::Comp::Label::getPointerAText() { JRETURN &JTHIS->textColor.a; }
JUINT8 *JDM::Comp::Label::getPointerRImage() { JRETURN &JTHIS->imageColor.r; }
JUINT8 *JDM::Comp::Label::getPointerGImage() { JRETURN &JTHIS->imageColor.g; }
JUINT8 *JDM::Comp::Label::getPointerBImage() { JRETURN &JTHIS->imageColor.b; }
JUINT8 *JDM::Comp::Label::getPointerAImage() { JRETURN &JTHIS->imageColor.a; }
JCVOID JDM::Comp::Label::update() {
    JTHIS->updateImage(JTHIS->getSizePos());
    JTHIS->updateText(JTHIS->getSizePos());
}
JCVOID JDM::Comp::Label::renderComp() {
    JIF (JDM::IsTextureInWindow(JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight())) {
        JTHIS->renderImage();
        JTHIS->renderGradient(JTHIS->getSizePos());
        JTHIS->renderText();
    }
}
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //






/////////////////////////////////////////////////////////////////////////////;///////
// BUTTON
/////////////////////////////////////////////////////////////////////////////;///////
JDM::Comp::Button::Button(
    JCSTR &text,
    JCSTR &source,
    JCDOUBLE xPos,
    JCDOUBLE yPos,
    JCDOUBLE Width,
    JCDOUBLE Height,
    JCONST ColorRGBA &color,
    JCONST ColorRGBA &colorImage,
    JCONST JDM::FourArc &arc,
    JCINT fontSize,
    JDM::Font::Halign hAlign,
    JDM::Font::Valign vAlign,
    JCONST ColorRGBA &colorClick,
    JCONST ColorRGBA &colorHover
) : JDM::Comp::Label(text, source, xPos, yPos, Width, Height, color, colorImage, arc, fontSize, hAlign, vAlign) {
    JTHIS->clickedColor = colorClick;
    JTHIS->hoverColor = colorHover;
}
JCBOOL JDM::Comp::Button::mouseDownComp(SDL_MouseButtonEvent &mouse) {
    JIF (JTHIS->getPickOnBounds()) {
        JIF(JTHIS->getPickOnTop() && JDM::alreadyTouched) JRETURN JFALSE;
        JIF (JTHIS->contains(mouse.x, mouse.y)) {
            JTHIS->getmouseDownFunction()(mouse);
            JTHIS->setImageAndOpacityColor(JTHIS->clickedColor);
            JTHIS->setMouseClick(JTRUE);
            JDM::alreadyTouched = JTRUE;
            JRETURN JTRUE;
        }
    } JRETURN JFALSE;
}
JCVOID JDM::Comp::Button::setOriginalColor(JCONST ColorRGBA &color) {
    JTHIS->originalColor = color;
    JTHIS->setImageAndOpacityColor(JTHIS->originalColor);
}
JCVOID JDM::Comp::Button::setClickedColor(JCONST ColorRGBA &color) { JTHIS->clickedColor = color; }
JCVOID JDM::Comp::Button::setHoverColor(JCONST ColorRGBA &color) { JTHIS->hoverColor = color; }
JCVOID JDM::Comp::Button::mouseUpComp(SDL_MouseButtonEvent &mouse) {
    JIF (JTHIS->getMouseClick()) JTHIS->setImageAndOpacityColor(JTHIS->originalColor);
    Label::mouseUpComp(mouse);
}
JCVOID JDM::Comp::Button::update() {
    Label::update();
    JTHIS->setImageAndOpacityColor(JTHIS->originalColor);
    JIF (!JTHIS->getMouseClick() && JTHIS->isHoverable)
        JIF (JTHIS->contains(JDM::Mouse::MouseX, JDM::Mouse::MouseY)) {
            JTHIS->setImageAndOpacityColor(JTHIS->hoverColor);
    }
}
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //






/////////////////////////////////////////////////////////////////////////////;///////
// TEXTINPUT
/////////////////////////////////////////////////////////////////////////////;///////
JDM::Comp::FocusedTextComponent::FocusedTextComponent(
    JCSTR &text,
    JCSTR &source,
    JCDOUBLE xPos,
    JCDOUBLE yPos,
    JCDOUBLE Width,
    JCDOUBLE Height,
    JCONST JDM::ColorRGBA &color,
    JCONST JDM::ColorRGBA &colorImage,
    JCONST JDM::FourArc &arc,
    JCINT fontSize,
    JDM::Font::Halign hAlign,
    JDM::Font::Valign vAlign
) : JDM::Comp::Label(text, source, xPos, yPos, Width, Height, color, colorImage, arc, fontSize, hAlign, vAlign) { }
JCSTR getName() { JRETURN "FocusedTextComponent"; }
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //






/////////////////////////////////////////////////////////////////////////////;///////
// TEXTINPUT
/////////////////////////////////////////////////////////////////////////////;///////
JDM::Comp::TextInput::TextInput(
    JCSTR &text,
    JCSTR &source,
    JCDOUBLE xPos,
    JCDOUBLE yPos,
    JCDOUBLE Width,
    JCDOUBLE Height,
    JCONST JDM::ColorRGBA &color,
    JCONST JDM::ColorRGBA &colorImage,
    JCONST JDM::FourArc &arc,
    JCINT fontSize,
    JDM::Font::Halign hAlign,
    JDM::Font::Valign vAlign
) : JDM::Comp::FocusedTextComponent(text, source, xPos, yPos, Width, Height, color, colorImage, arc, fontSize, hAlign, vAlign) { }
JCVOID JDM::Comp::TextInput::setCursorColor(JCONST ColorRGBA &color) { JTHIS->colorCursor = color; }
JCVOID JDM::Comp::TextInput::renderComp() {
    JIF (IsTextureInWindow(JTHIS->getX(), JTHIS->getY(), JTHIS->getWidth(), JTHIS->getHeight())) {
        Label::renderComp();
        JTHIS->currentBlink -= JDM::TimeFrame;
        JIF (JTHIS->isFocused)
            JIF (JTHIS->currentBlink > 0) {
                JIF (JTHIS->blinked) {
                    SDL_SetRenderDrawColor(JDM::renderer, JTHIS->colorCursor.r, JTHIS->colorCursor.g, JTHIS->colorCursor.b, JTHIS->colorCursor.a);
                    SDL_RenderDrawLineF(JDM::renderer,
                        JTHIS->getTextDestination().x+((JTHIS->index+1) * JTHIS->getCopyFontSize()), JTHIS->getTextDestination().y + 15,
                        JTHIS->getTextDestination().x+((JTHIS->index+1) * JTHIS->getCopyFontSize()), JTHIS->getTextDestination().y + JTHIS->getCopyFontSize() + 5);
                    SDL_RenderDrawLineF(JDM::renderer,
                        JTHIS->getTextDestination().x+((JTHIS->index+1) * JTHIS->getCopyFontSize()) + 1, JTHIS->getTextDestination().y,
                        JTHIS->getTextDestination().x+((JTHIS->index+1) * JTHIS->getCopyFontSize()) + 1, JTHIS->getTextDestination().y + JTHIS->getCopyFontSize() + 5);
                }
            } JELSE {
                JTHIS->currentBlink = JTHIS->blinkDuration;
                JTHIS->blinked = !JTHIS->blinked;
            }
    }
}
/////////////////////////////////////////////////////////////////////////////;///////
// ------------------------------------------------------------------------------- //