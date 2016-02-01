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
    
    winWidth = 0;
    winHeight = 0;
}

Window::Window(const Window& orig) {
}

Window::~Window() {
    close();
}

bool Window::open() {

    window = SDL_CreateWindow( 
            "Game - Sam Evans-Thomson",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    
    bool success = window!=NULL;
    
    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
        if( renderer == NULL ) {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else {
            //Initialize renderer color
            SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

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
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear( renderer );
}


void Window::render() {
    SDL_RenderPresent( renderer );
}

void Window::close() {
    if (window != NULL) SDL_DestroyWindow ( window );
    mouseFocus = false;
    keyboardFocus = false;
    winWidth = 0;
    winHeight = 0;
}

SDL_Renderer* Window::getRenderer() { return renderer; }
int Window::getWidth() { return winWidth; }
int Window::getHeight() { return winHeight; }

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
                winWidth = event.window.data1;
                winHeight = event.window.data2;
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
