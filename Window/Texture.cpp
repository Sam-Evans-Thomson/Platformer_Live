/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Texture.cpp
 * Author: sam
 * 
 * Created on 31 January 2016, 1:05 PM
 */

#include "Texture.h"

extern Window gameWindow;

Texture::Texture() {
    texture = NULL;
    width = height = 0;
}

Texture::Texture(const Texture& orig) {
    
}

Texture::~Texture() {
    free();
}

bool Texture::createBlank(int w, int h) {
    
    texture = SDL_CreateTexture(gameWindow.getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
    
    if( texture == NULL ) { 
        printf( "Unable to create blank texture! SDL Error: %s\n", SDL_GetError() );
    } 
    else { 
        width = w; 
        height = h; 
        wipe();
    } 
    return texture != NULL;
}

#ifdef _SDL_TTF_H
bool Texture::loadFromRendererText(std::string textureText, SDL_Color textColor) {
    freeTexture();
    
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    if ( textSurface != NULL ) {
        texture = SDL_CreateTextureFromSurface( window.getRenderer(), textSurface );
        if (texture == NULL ) {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", 
                    SDL_GetError() );
        }
        else {
            width = textSurface->w;
            height = textSurface->h;
        }
        
        SDL_FreeSurface( textSurface );
    }
    else {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    
    return texture != NULL;
}
#endif

bool Texture::loadFromFile(std::string path) {
    freeTexture();
    
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    
    if ( loadedSurface == NULL ) { printf( "Unable to load image %s! SDL_image Error: %s\n",  path.c_str(),  IMG_GetError() ); }
    
    else {
        
        SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat( loadedSurface, SDL_PIXELFORMAT_RGBA8888, 0 );
        if (formattedSurface == NULL) { printf( "Unable to convert loaded surface to display format! %s\n", SDL_GetError() ); }
        
        else {
            if (&gameWindow == nullptr) printf("window is null: \n");
            else {
            newTexture = SDL_CreateTexture(gameWindow.getRenderer(), 
                SDL_PIXELFORMAT_RGBA8888, 
                SDL_TEXTUREACCESS_STREAMING,
                formattedSurface->w,
                formattedSurface->h );
            }
            
            if ( newTexture == NULL ) { printf( "Unable to create blank texture: \n" ); }
            else {
                SDL_SetTextureBlendMode( newTexture, SDL_BLENDMODE_BLEND );
                SDL_LockTexture( newTexture, &formattedSurface->clip_rect, &pixels, &pitch);
                memcpy( pixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);
                
                width  = formattedSurface -> w;
                height = formattedSurface -> h;
                
                Uint32* pixels = (Uint32*)pixels;
                int pixelCount = (pitch/4)*height;
                       
                Uint32 colorKey = SDL_MapRGB( formattedSurface->format, 0, 0xFF, 0xFF );
		Uint32 transparent = SDL_MapRGBA( formattedSurface->format, 0x00, 0xFF, 0xFF, 0x00 );
                
                // Using color to set pixels as transparent
                for( int i = 0; i < pixelCount; i++) {
                    if( pixels[i] == colorKey) {
                        //pixels[i] = transparent;
                    }
                }
                
                SDL_UnlockTexture( newTexture );
                pixels = NULL;
            }
            
            SDL_FreeSurface( formattedSurface);
        }
        
        SDL_FreeSurface( loadedSurface);

    }

    texture = newTexture;
    return texture != NULL;
    
}

void Texture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode( texture, blending );
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod( texture, red, green, blue );
}

void Texture::setAsRenderTarget() {
    SDL_SetRenderTarget( gameWindow.getRenderer() , texture );
}

void Texture::resetRenderTarget() {
    SDL_SetRenderTarget( gameWindow.getRenderer() , NULL );
}

void Texture::wipe() {
    SDL_SetRenderTarget( gameWindow.getRenderer() , texture );
    SDL_SetRenderDrawColor(gameWindow.getRenderer(), 255, 0, 0, 0);
    SDL_RenderClear(gameWindow.getRenderer());
    SDL_SetRenderTarget( gameWindow.getRenderer() , NULL );
    SDL_SetTextureAlphaMod(texture, 255);
    SDL_SetTextureBlendMode( texture, SDL_BLENDMODE_BLEND );
}

bool Texture::lockTexture() {
    bool success = true;
    if (pixels != NULL) {
        printf( "Texture is already locked! \n");
        success = false;
    }
    
    else {
        if(SDL_LockTexture( texture, NULL, &pixels, &pitch) != 0) {
            printf( "Unable to lock texture! %s\n", SDL_GetError() );
            success = false;
        }
    }
    
    return success;
}

bool Texture::unlockTexture() {
    bool success = true;

    //Texture is not locked
    if( pixels == NULL )
    {
            printf( "Texture is not locked!\n" );
            success = false;
    }
    //Unlock texture
    else
    {
            SDL_UnlockTexture( texture );
            pixels = NULL;
            pitch = 0;
    }

    return success;
}

void Texture::copyPixels(void* _pixels) {
    //Texture is locked
    if( pixels != NULL )
    {
        //Copy to locked pixels
        memcpy( pixels, _pixels, pitch * height );
    }
}

Uint32 Texture::getPixel32(unsigned int x, unsigned int y) {
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32*)pixels;

    //Get the pixel requested
    return pixels[ ( y * ( pitch / 4 ) ) + x ];
}

void Texture::setAngle(double _angle) { angle = _angle; }

void Texture::setClip(SDL_Rect* _clip) { clip = _clip; }

void Texture::setFlip(SDL_RendererFlip _flip) { flip = _flip; }

void Texture::setScale(double _scaleX, double _scaleY) { 
    scaleX = _scaleX;
    scaleY = _scaleY;
}

void Texture::setRenderSettings(SDL_Rect* _clip, double _angle, double _scaleX, double _scaleY, SDL_RendererFlip _flip) {
    angle = _angle;
    clip = _clip;
    flip = _flip;
    scaleX = _scaleX;
    scaleY = _scaleY;
}

void Texture::render(int x, int y) {
    SDL_Rect renderQuad = { x, y, (int)(scaleX*width), (int)(scaleY*height) };
    
    if ( gameWindow.getRenderer() != NULL ) {
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
        SDL_RenderCopyEx( gameWindow.getRenderer(), texture, clip, &renderQuad, angle, NULL, flip);
    }
    else { printf( "Window does not have a valid renderer"); }
}

void Texture::render(int x, int y, int w, int h) {
    SDL_Rect renderQuad = { x, y, w, h };
    
    if ( gameWindow.getRenderer() != NULL ) {
        SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
        SDL_RenderCopyEx( gameWindow.getRenderer(), texture, clip, &renderQuad, angle, NULL, flip);
    }
    else { printf( "Window does not have a valid renderer"); }
}

void Texture::renderToTexture(Texture* _texture, int x, int y) {
    _texture->setAsRenderTarget();
    render(x,y);
    _texture->resetRenderTarget();
}

void Texture::renderToTexture(Texture* _texture, int x, int y, int w, int h) {
    _texture->setAsRenderTarget();
    render(x,y,w ,h);
    _texture->resetRenderTarget();
}

void Texture::free() { freeTexture(); }

void Texture::freeTexture() {
    if ( texture != NULL ) {
        
        SDL_DestroyTexture( texture );
        texture = NULL;
        width = height = 0;
    }
}

int Texture::getWidth() { return width; }
int Texture::getHeight() { return height; }
void* Texture::getPixels() { return pixels; }
int Texture::getPitch() { return pitch;}





