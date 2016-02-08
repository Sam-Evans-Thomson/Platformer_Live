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

class Texture;
class Window;

#define NUM_LAYERS 10

class Canvas {
public:
    Canvas();
    Canvas(const Canvas& orig);
    virtual ~Canvas();
    
    void init();
    
    void render();
    
    void clearBackground();
    void clearForeground();
    void clearLayer(int i);
    void clearLayers();
    void clearAll();
    
    void addTexture(Texture* tex, double x, double y, int z, double scale, double rot);
    void addTexture(Texture* tex, double x, double y, int z, double scale, double rot, SDL_RendererFlip flip);
    void addBackgroundTexture(Texture* tex, double x, double y, double scale, double rot);
    void addForegroundTexture(Texture* tex, double x, double y, double scale, double rot);
    
    Texture* foreground;
    Texture* background;
    
private:

    
    
    Texture* layers[NUM_LAYERS];

};

#endif /* CANVAS_H */

