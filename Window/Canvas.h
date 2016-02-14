/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Canvas.h
 * Author: sam
 *
 * Created on 3 February 2016, 3:26 PM
 */

#ifndef CANVAS_H
#define CANVAS_H

#include <string>
#include <vector>
#include <SDL.h>

#include "Camera.h"

class Texture;
class Window;

#define NUM_LAYERS 10

#define CANVAS_SIZE_W 3840
#define CANVAS_SIZE_H 2160

#define Z_BACKGROUND -1
#define Z_FOREGROUND -2

class Canvas {
public:
    Canvas();
    Canvas(const Canvas& orig);
    virtual ~Canvas();
    
    void init();
    void update();
    void render();
    
    void clearBackground();
    void clearForeground();
    void clearOverlay();
    void clearLayer(int i);
    void clearLayers();
    void clearAll();
    
    void addTexture(Texture* tex, double x, double y, int z, SDL_Rect* clip, double scale, double rot, SDL_RendererFlip flip);
    void addTexture(Texture* tex, SDL_Rect* dest, SDL_Rect* clip, int z, double scale, double rot, SDL_RendererFlip flip);
    
    void addOverlay(Texture* tex, SDL_Rect* dest, SDL_Rect* clip, double scale, double rot, SDL_RendererFlip flip);
    Texture* foreground;
    Texture* background;
    Texture* overlay;
    
private:
    
    void renewOffsets();
    
    int xOffset = 0;
    int yOffset = 0;
    
    SDL_Rect viewport;
    SDL_Rect backgroundViewport;
    SDL_Rect foregroundViewport;
    
    double zoom;
    
    Camera* camera;
    
    
    Texture* layers[NUM_LAYERS];

};

#endif /* CANVAS_H */

