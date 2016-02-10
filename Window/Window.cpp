/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Window.cpp
 * Author: sam
 * 
 * Created on 31 January 2016, 11:56 AM
 */

#include "Window.h"



Window::Window() {
    window = NULL;
    renderer = NULL;
    
    mouseFocus = false;
    keyboardFocus = false;
    fullScreen = false;
    minimized = false;
    
    windowW = 0;
    windowH = 0;
}

Window::Window(const Window& orig) {
}

Window::~Window() {
    close();
}

bool Window::open() {

    window = SDL_CreateWindow( 
            "Game - Sam Evans-Thomson",
            1920,
            0,
            0,
            0,
            SDL_WINDOW_SHOWN );
    

    applyScreenDim(DIM_1440_900);
    
    //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    
    
    bool success = window!=NULL;
    
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | 
            SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
        if( renderer == NULL ) {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            //Initialize renderer color
            SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
                printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                success = false;
            }
        }

    return success;
}

void Window::clearScreen() {
    SDL_SetRenderDrawColor( renderer, 0,0,0,255);    
    SDL_RenderClear( renderer );
    
    SDL_RenderSetScale(renderer, scale, scale);
    
    SDL_RenderSetViewport(renderer, &renderArea);
    SDL_SetRenderDrawColor( renderer, 255,255,255,255);
    SDL_RenderFillRect(renderer, &screenRect);
}

void Window::applyScreenDim(ScreenDimensions scDim) {
    currDim = &scDim;
    
    windowW = currDim->w;
    windowH = currDim->h;
    
    int renderX = 0;
    int renderY = 0;
    int renderW = windowW;
    int renderH = windowH;

    SDL_SetWindowSize(window, windowW, windowH); // windows size on monitor.
    
    double ratio = (double)windowW/(double)windowH;
        
    // Area needs to reduce height
    if(ratio < DEFAULT_RATIO) { 
        renderH = (double)renderW/DEFAULT_RATIO;
        scale = (double)renderH/(double)DEFAULT_H;
        renderY = (double)(windowH - renderH)/2.0;
    } 
    // Area needs to reduce width
    else {
        renderW = (double)renderH*DEFAULT_RATIO;
        scale = (double)renderW/(double)DEFAULT_W;
        renderX = (double)(windowW - renderW)/2.0;
    }
    

    renderArea.x = renderX/scale;
    renderArea.y = renderY/scale;
    renderArea.w = DEFAULT_W;
    renderArea.h = DEFAULT_H;
    
    clearScreen();

}

void Window::render() {

    SDL_RenderPresent( renderer );
    clearScreen();
}

void Window::close() {
    if (window != NULL) SDL_DestroyWindow ( window );
    mouseFocus = false;
    keyboardFocus = false;
    windowW = 0;
    windowH = 0;
}

SDL_Renderer* Window::getRenderer() { return renderer; }

SDL_Rect* Window::getRenderArea() { return &renderArea; }

int Window::getWidth() { return windowW; }
int Window::getHeight() { return windowH; }

bool Window::hasKeyboardFocus() { return keyboardFocus; }
bool Window::hasMouseFocus() { return mouseFocus; }
bool Window::isMinimized() { return minimized; }

SDL_Renderer* Window::createRenderer() {
    return SDL_CreateRenderer( window, 
            -1, 
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
}

void Window::handleEvent(SDL_Event& event) {
    if ( event.type == SDL_WINDOWEVENT ) {
        bool updateCaption = false;
        
        switch( event.window.event ) {
            
            case SDL_WINDOWEVENT_SIZE_CHANGED: 
                windowW = event.window.data1;
                windowH = event.window.data2;
                SDL_RenderPresent( renderer );
                break;
            
            case SDL_WINDOWEVENT_EXPOSED: 
                SDL_RenderPresent ( renderer );
                break;
                
            case SDL_WINDOWEVENT_ENTER:
                mouseFocus = true;
                updateCaption = true;
                break;
                
            case SDL_WINDOWEVENT_LEAVE:
                mouseFocus = false;
                updateCaption = true;
                break;
                
            case SDL_WINDOWEVENT_FOCUS_LOST:
                keyboardFocus = false;
                updateCaption = true;
                break;
                
            case SDL_WINDOWEVENT_FOCUS_GAINED:
                keyboardFocus = true;
                updateCaption = true;
                break;
                
            case SDL_WINDOWEVENT_MINIMIZED:
                minimized = true;
                break;
                
            case SDL_WINDOWEVENT_MAXIMIZED:
                minimized = false;
                break;
                
            case SDL_WINDOWEVENT_RESTORED:
                minimized = false;
                break;    
                
        }
        
        if (updateCaption) {
            std::stringstream caption;
            caption << "MouseFocus: " << ((mouseFocus) ? "ON" : "OFF" ) 
                    << "KeyboardFocus: " << ((keyboardFocus) ? "ON" : "OFF" ); 
            SDL_SetWindowTitle( window, caption.str().c_str() );
        }
        
        else if( event.type == SDL_KEYDOWN && 
                 event.key.keysym.sym == SDLK_RETURN) {
            if(fullScreen) {
                SDL_SetWindowFullscreen( window, SDL_FALSE);
                fullScreen = false;
            } 
            else {
                SDL_SetWindowFullscreen( window, SDL_TRUE );
                fullScreen = true;
                minimized= false;
            }
        }
    }
}
