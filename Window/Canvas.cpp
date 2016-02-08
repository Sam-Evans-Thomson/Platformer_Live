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

Canvas::Canvas() {

}

Canvas::Canvas(const Canvas& orig) {
}

Canvas::~Canvas() { 
    delete foreground;
    delete background;
    for (Texture* tex: layers) delete tex;
}

void Canvas::init() {
    foreground = new Texture();
    foreground->createBlank(DEFAULT_W, DEFAULT_H);
    background = new Texture();
    background->createBlank(DEFAULT_W, DEFAULT_H);
    
    for (int i = 0; i < NUM_LAYERS; i++) {
        layers[i] = new Texture();
        layers[i]->createBlank(DEFAULT_W, DEFAULT_H);
    }
}

void Canvas::render() {
    background->render(0,0,NULL,0.0,1.0, NULL,SDL_FLIP_NONE);
    for (Texture* tex: layers) tex->render(0,0,NULL,0.0,1.0, NULL,SDL_FLIP_NONE);
    foreground->render(0,0,NULL,0.0,1.0, NULL,SDL_FLIP_NONE);
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

void Canvas::addTexture(Texture* tex, double x, double y, int z, double scale, double rot) {
    if (z > -1 && z < NUM_LAYERS) {
        tex->renderToTexture(layers[z],x,y,NULL,rot,scale,NULL,SDL_FLIP_NONE);
    }
}

void Canvas::addTexture(Texture* tex, double x, double y, int z, double scale, double rot, SDL_RendererFlip flip) {
    if (z > -1 && z < NUM_LAYERS) {
        tex->renderToTexture(layers[z],x,y,NULL,rot,scale,NULL,flip);
    }
}

void Canvas::addBackgroundTexture(Texture* tex, double x, double y, double scale, double rot) {
    tex->renderToTexture(background,x,y,NULL,rot,scale,NULL,SDL_FLIP_NONE);
}

void Canvas::addForegroundTexture(Texture* tex, double x, double y, double scale, double rot) {
    tex->renderToTexture(foreground,x,y,NULL,rot,scale,NULL,SDL_FLIP_NONE);
}

