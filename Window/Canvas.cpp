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

void Canvas::update() {
    renewOffsets();
}


void Canvas::render() {
    camera->updateViewport();
    
    viewport = camera->getViewport();
    backgroundViewport = camera->getParallaxViewport(BACKGROUND_DIST);
    foregroundViewport = camera->getParallaxViewport(FOREGROUND_DIST);
    
    backgroundViewport.x -= BACKGROUND_DIST*xOffset;
    backgroundViewport.y -= BACKGROUND_DIST*yOffset;
    foregroundViewport.x -= FOREGROUND_DIST*xOffset;
    foregroundViewport.y -= FOREGROUND_DIST*yOffset;
    viewport.x -= xOffset;
    viewport.y -= yOffset;
    
    background->render(&backgroundViewport);
    for (Texture* tex: layers) texRender(tex);
    foreground->render(&foregroundViewport);
}

void Canvas::texRender(Texture* tex) {
    tex->render(&viewport);
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
    tex->renderToTexture(background,
                BACKGROUND_DIST*(x-xOffset),
                BACKGROUND_DIST*(y-yOffset),
                clip,rot,scale,NULL,SDL_FLIP_NONE);
}

void Canvas::addForegroundTexture(Texture* tex, double x, double y, SDL_Rect* clip, double scale, double rot) {
    tex->renderToTexture(foreground,
                FOREGROUND_DIST*(x-xOffset),
                FOREGROUND_DIST*(y-yOffset),
                clip,rot,scale,NULL,SDL_FLIP_NONE);
}

void Canvas::renewOffsets() {
    xOffset = levelManager.getCameraXOffset();
    yOffset = levelManager.getCameraYOffset();  
}



