/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.h
 * Author: sam
 *
 * Created on 31 January 2016, 1:05 PM
 */

#ifndef TEXTURE_H
#define TEXTURE_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Window.h"



class Texture {
public:
    Texture();
    Texture(const Texture& orig);
    virtual ~Texture();
    
    int getWidth();
    int getHeight();
    
    void setColor( Uint8 red, Uint8 green, Uint8 blue );
    void setBlendMode( SDL_BlendMode blending );
    void setAlpha( Uint8 alpha );
    
    void wipe();
    
    void setAsRenderTarget();
    void resetRenderTarget();
    
    // These function will initialize this texture.
    bool createBlank(int w, int h);
    bool loadFromFile( std::string path );
    bool loadFromRendererText( std::string textureText, SDL_Color textColor );
    
    void setRenderSettings(SDL_Rect* _clip, double _angle, double _scaleX, 
                                    double _scaleY, SDL_RendererFlip _flip);
    void setClip(SDL_Rect* _clip);
    void setAngle(double _angle);
    void setScale(double _scaleX, double _scaleY);
    void setFlip(SDL_RendererFlip _flip);
    
    // This renders the texture to the window.
    void render(int x, int y);
    void render(int x, int y, int w, int h);
    void renderToTexture(Texture* _texture, int x, int y);
    void renderToTexture(Texture* _texture, int x, int y, int w, int h);
    
    bool lockTexture();
    bool unlockTexture();
    void* getPixels();
    void copyPixels( void* _pixels );
    int getPitch();
    Uint32 getPixel32( unsigned int x, unsigned int y);

    void free();
    
private:
    SDL_Texture* texture;
    
    void* pixels;
    int pitch;
    
    int width;
    int height;
    
    
    SDL_Rect* clip = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    double angle = 0.0;
    double scaleX = 1.0;
    double scaleY = 1.0;
    
    void freeTexture();
};

#endif /* TEXTURE_H */

