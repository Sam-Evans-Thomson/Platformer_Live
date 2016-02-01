/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Window.h
 * Author: sam
 *
 * Created on 31 January 2016, 11:56 AM
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <sstream>

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    
class Window {
public:
    
    
    Window();
    Window(const Window& orig);
    virtual ~Window();

    bool open();
    void close();
    void render();
    void clearScreen();
    
    int getWidth();
    int getHeight();
    SDL_Renderer* getRenderer();
    
    SDL_Renderer* createRenderer();
    void handleEvent(SDL_Event &event);
    
    bool hasMouseFocus();
    bool hasKeyboardFocus();
    bool isMinimized();
    
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    int winWidth;
    int winHeight;
    
    int getScreenWidth();
    int getScreenHeight();
    
    bool mouseFocus;
    bool keyboardFocus;
    bool fullScreen;
    bool minimized;

};

#endif /* WINDOW_H */

