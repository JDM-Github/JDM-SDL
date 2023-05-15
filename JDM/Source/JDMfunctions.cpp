#include "JDM/Header/JDMfunctions.hpp"
#include "JDM/Header/JDMinclude.hpp"

JNAMESPACE JDM {
    JCVOID subtractCharAtIndex(JSTR &str, JCINT index) {
        JIF (index >= 0 && index < str.length())
            str.erase(index, 1);
    }
    JCVOID addCharAtIndex(JSTR &str, JCINT index, JCSTR &ch) {
        JIF (index >= 0 && index <= str.size())
            str.insert(index, ch);
    }
    JCSTR retSubtractCharAtIndex(JSTR str, JCINT index) {
        JIF (index >= 0 && index < str.length())
            str.erase(index, 1);
        JRETURN str;
    }
    JCSTR retAddCharAtIndex(JSTR str, JCINT index, JCSTR &ch) {
        JIF (index >= 0 && index <= str.size())
            str.insert(index, ch);
        JRETURN str;
    }
    JCBOOL isFileExist(JSTRVIEW file) { JRETURN std::filesystem::exists(file); }

    JCONST JDM::ColorRGB getColorFromHex(JSTRVIEW hexColor) {
        ColorRGB color;
        JCSTR colorString = (hexColor.at(0) == '#') ?
            JSTR(hexColor.substr(1)) : JSTR(hexColor);

        std::istringstream iss(colorString);
        JUINT hexValue; iss >> std::hex >> hexValue;
        color.r = (hexValue >> 16) & 0xFF;
        color.g = (hexValue >> 8) & 0xFF;
        color.b = hexValue & 0xFF;

        JRETURN color;
    }
    JCONST JDM::ColorRGBA getColorFromHexA(JSTRVIEW hexColor) {
        ColorRGBA color;
        JCSTR colorString = (hexColor.at(0) == '#') ?
            JSTR(hexColor.substr(1)) : JSTR(hexColor);
        std::istringstream iss(colorString);
        JUINT hexValue; iss >> std::hex >> hexValue;
        JIF (colorString.length() > 6) {
            color.r = (hexValue >> 16) & 0xFF;
            color.g = (hexValue >> 8) & 0xFF;
            color.b = hexValue & 0xFF;
            color.a = 255;
        } JELSE {
            color.r = (hexValue >> 24) & 0xFF;
            color.g = (hexValue >> 16) & 0xFF;
            color.b = (hexValue >> 8) & 0xFF;
            color.a = hexValue & 0xFF;
        }
        JRETURN color;
    }
    JCBOOL IsTextureInWindow(
        JCDOUBLE x,
        JCDOUBLE y,
        JCDOUBLE width,
        JCDOUBLE height
    ) { JRETURN !(x > JDM::WindowWidth || x + width < 0 || y > JDM::WindowHeight || y + height < 0); }

    SDL_Texture *loadRoundedTexture(
        JCONST JDM::Size &size,
        JCCHAR *path,
        JCONST JDM::FourArc &arc,
        JCUINT8 lineWidth
    ) {
        SDL_Surface* originalSurface = IMG_Load(path);
        JIF (arc.topLeft == 0 && arc.topRight == 0 && arc.topLeft == 0 && arc.topRight == 0 && lineWidth == 0) {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(JDM::renderer, originalSurface);
            SDL_FreeSurface(originalSurface);
            JRETURN texture;
        }
        SDL_Surface* resizedSurface = SDL_CreateRGBSurfaceWithFormat(0, size.width, size.height, 32, SDL_PIXELFORMAT_RGBA32);
        SDL_BlitScaled(originalSurface, JNULLPTR, resizedSurface, JNULLPTR);

        JUINT32 transparentColor = SDL_MapRGBA(resizedSurface->format, 0, 0, 0, 0);
        SDL_SetSurfaceBlendMode(resizedSurface, SDL_BLENDMODE_BLEND);

        // Corner Modifier
        JAUTO modifyCorner = [&resizedSurface, lineWidth, transparentColor](
            JINT addX, JINT addY, JINT size, JINT startX, JINT startY, JINT endX, JINT endY) {
            JFOR (JINT y = startY; y < endY; ++y) {
                JFOR (JINT x = startX; x < endX; ++x) {
                    JINT dx = x - size;
                    JINT dy = y - size;
                    JINT distance = std::sqrt(dx * dx + dy * dy);
                    JIF (distance > size || ((lineWidth > 0) ? (distance < size - lineWidth) : false)) {
                        JUINT32* pixel = JREINTERPRETC<JUINT32*>(
                            JREINTERPRETC<JUINT8*>(resizedSurface->pixels)
                            + (addY + y) * resizedSurface->pitch
                            + (addX + x) * resizedSurface->format->BytesPerPixel);
                        *pixel = transparentColor;
                    }
                }
            }
        };

        if (lineWidth > 0) { // Draw Line depends on the Width
            JFOR (JINT x = arc.topLeft; x < resizedSurface->w - arc.topRight; ++x) {
                JFOR (JINT y = lineWidth; y < resizedSurface->h - lineWidth; ++y) {
                    JUINT32* pixel = JREINTERPRETC<JUINT32*>(
                        JREINTERPRETC<JUINT8*>(resizedSurface->pixels)
                        + y * resizedSurface->pitch
                        + x * resizedSurface->format->BytesPerPixel);
                        *pixel = transparentColor;
                }
            }
            JFOR (JINT x = lineWidth; x < resizedSurface->w - lineWidth; ++x) {
                JFOR (JINT y = arc.bottomLeft; y < resizedSurface->h - arc.bottomRight; ++y) {
                    JUINT32* pixel = JREINTERPRETC<JUINT32*>(
                        JREINTERPRETC<JUINT8*>(resizedSurface->pixels)
                        + y * resizedSurface->pitch
                        + x * resizedSurface->format->BytesPerPixel);
                        *pixel = transparentColor;
                }
            }
        }
        // Make all the corner rounder
        JIF (arc.topLeft) modifyCorner(
            0, 0,
            arc.topLeft, 0,
            0, // Size
            arc.topLeft, arc.topLeft);
        JIF (arc.topRight) modifyCorner(
            resizedSurface->w - arc.topRight * 2, 0,
            arc.topRight, arc.topRight,
            0, // Size
            arc.topRight * 2, arc.topRight);
        JIF (arc.bottomLeft) modifyCorner(
            0, resizedSurface->h - arc.bottomLeft * 2,
            arc.bottomLeft, 0,
            arc.bottomLeft, // Size
            arc.bottomLeft, arc.bottomLeft * 2);
        JIF (arc.bottomRight) modifyCorner(
            resizedSurface->w - arc.bottomRight * 2,
            resizedSurface->h - arc.bottomRight * 2,
            arc.bottomRight, // Size
            arc.bottomRight, arc.bottomRight,
            arc.bottomRight * 2, arc.bottomRight * 2);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(JDM::renderer, resizedSurface);
        SDL_FreeSurface(originalSurface);
        SDL_FreeSurface(resizedSurface);
        JRETURN texture;
    }

    SDL_Texture *loadTextTexture(JCCHAR * path, JCCHAR * text, JCONST ColorRGBA &color) {
        TTF_Font *tempFont = TTF_OpenFont(path, 256);
        SDL_Surface *tempsurface = TTF_RenderText_Blended(tempFont, text, SDL_Color{color.r, color.g, color.b});
        SDL_Texture *texture = SDL_CreateTextureFromSurface(JDM::renderer, tempsurface);
        SDL_FreeSurface(tempsurface);
        TTF_CloseFont(tempFont);
        JRETURN texture;
    }
};