/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Canvas.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 3:26 PM
 */

#include "Canvas.h"
#include "Texture.h"
#include "Window.h"
#include "../Level/LevelManager.h"

extern LevelManager levelManager;

Canvas::Canvas() {

}

Canvas::Canvas(const Canvas& orig) {
}

Canvas::~Canvas() { 
    delete camera;
    delete foreground;
    delete background;
    for (Texture* tex: layers) delete tex;
}

void Canvas::init() {
    camera = new Camera();
    
    foreground = new Texture();
    foreground->createBlank(CANVAS_SIZE_W, CANVAS_SIZE_H);
    background = new Texture();
    background->createBlank(CANVAS_SIZE_W, CANVAS_SIZE_H);
    
    for (int i = 0; i < NUM_LAYERS; i++) {
        layers[i] = new Texture();
        layers[i]->createBlank(CANVAS_SIZE_W, CANVAS_SIZE_H);
    }
}

void Canvas::render() {
    renewOffsets();
    
    SDL_Rect viewport = camera->getViewport();
    int zoom = camera->getZoom();
    
    background->render(
                -viewport.x+xOffset,-viewport.y+yOffset,
                NULL,0.0, zoom, NULL,SDL_FLIP_NONE);
    for (Texture* tex: layers) tex->render(
                -viewport.x+xOffset,-viewport.y+yOffset,
                NULL,0.0, zoom, NULL,SDL_FLIP_NONE);
    foreground->render(
                -viewport.x+xOffset,-viewport.y+yOffset,
                NULL,0.0,zoom, NULL,SDL_FLIP_NONE);
}

void Canvas::clearBackground() {
    background->wipe();
}

void Canvas::clearForeground() {
    foreground->wipe();
}

void Canvas::clearLayer(int i) {
    if (i > -1 && i < NUM_LAYERS) {
        layers[i]->wipe();
    }
}

void Canvas::clearLayers() {
    for (int i = 0; i < NUM_LAYERS; i++) {
        layers[i]->wipe();
    }
}

void Canvas::clearAll() {
    background->wipe();
    foreground->wipe();
    for (int i = 0; i < NUM_LAYERS; i++) {
        layers[i]->wipe();
    }
}

void Canvas::addTexture(Texture* tex, double x, double y, int z, SDL_Rect* clip, double scale, double rot) {
    if (z > -1 && z < NUM_LAYERS) {
        tex->renderToTexture(layers[z],x-xOffset,y-yOffset,clip,rot,scale,NULL,SDL_FLIP_NONE);
    }
}

void Canvas::addTexture(Texture* tex, double x, double y, int z, SDL_Rect* clip, double scale, double rot, SDL_RendererFlip flip) {
    if (z > -1 && z < NUM_LAYERS) {
        tex->renderToTexture(layers[z],x-xOffset,y-yOffset,clip,rot,scale,NULL,flip);
    }
}

void Canvas::addBackgroundTexture(Texture* tex, double x, double y, SDL_Rect* clip, double scale, double rot) {
    tex->renderToTexture(background,x-xOffset,y-yOffset,clip,rot,scale,NULL,SDL_FLIP_NONE);
}

void Canvas::addForegroundTexture(Texture* tex, double x, double y, SDL_Rect* clip, double scale, double rot) {
    tex->renderToTexture(foreground,x-xOffset,y-yOffset,clip,rot,scale,NULL,SDL_FLIP_NONE);
}

void Canvas::renewOffsets() {
    xOffset = levelManager.getCameraXOffset();
    yOffset = levelManager.getCameraYOffset();  
}



