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
    delete overlay;
    for (Texture* tex: layers) delete tex;
}

void Canvas::init() {
    camera = new Camera();
    
    foreground = new Texture();
    foreground->createBlank(CANVAS_SIZE_W, CANVAS_SIZE_H);
    background = new Texture();
    background->createBlank(BACKGROUND_SIZE_W, BACKGROUND_SIZE_H);
    overlay = new Texture();
    overlay->createBlank(CANVAS_SIZE_W, CANVAS_SIZE_H);
    
    for (int i = 0; i < NUM_LAYERS; i++) {
        layers[i] = new Texture();
        layers[i]->createBlank(CANVAS_SIZE_W, CANVAS_SIZE_H);
    }
}

void Canvas::update() {
    renewOffsets();
    camera->update();
}


void Canvas::render() {

    viewport = camera->getViewport(xOffset, yOffset);
    backgroundViewport = camera->getParallaxViewport(BACKGROUND_DIST, backgroundXOffset, backgroundYOffset);
    foregroundViewport = camera->getParallaxViewport(FOREGROUND_DIST, xOffset, yOffset);
    
    background->setClip(&backgroundViewport);
    background->render(0.0,0.0, 1920, 1080);
    
    for (Texture* tex: layers) {
        tex->setClip(&viewport);
        tex->render(0.0,0.0, 1920, 1080);
    }
    
    foreground->setClip(&foregroundViewport);
    foreground->render(0.0, 0.0, 1920, 1080);
    
    double zoom = camera->getZoom();
    if (zoom > 1.4) zoom = 1.4;
    SDL_Rect temp = {
        (int)((1.4 - zoom) * 500.0),
        0,
        (int)(1920 - (1.4-zoom) * 1000.0),
        1080};
    
    overlay->setClip(&temp);
    overlay->render(0.0,0.0,1920,1080);
}

void Canvas::clearBackground() { background->wipe(); }

void Canvas::clearForeground() { foreground->wipe(); }

void Canvas::clearOverlay() { overlay->wipe(); }

void Canvas::clearLayer(int i) { 
    if (i > -1 && i < NUM_LAYERS) layers[i]->wipe();
}

void Canvas::clearLayers() {
    for (int i = 0; i < NUM_LAYERS; i++) layers[i]->wipe();
}

void Canvas::clearAll() {
    background->wipe();
    foreground->wipe();
    overlay->wipe();
    for (int i = 0; i < NUM_LAYERS; i++) {
        layers[i]->wipe();
    }
}

void Canvas::addTexture(Texture* tex, double x, double y, int z, SDL_Rect* clip, double scale, double rot, SDL_RendererFlip flip) {
    if (z > -1 && z < NUM_LAYERS) {
        tex->setRenderSettings(clip, rot, scale, scale,flip);
        tex->renderToTexture(layers[z], x-xOffset, y-yOffset);
    } else if (z == Z_BACKGROUND) {
        tex->setRenderSettings(clip, rot, scale, scale,flip);
        tex->renderToTexture(background,
                (x-xOffset),
                (y-yOffset));
    } else if (z == Z_FOREGROUND) {
        tex->setRenderSettings(clip, rot, scale, scale,flip);
        tex->renderToTexture(foreground,
                (x-xOffset),
                (y-yOffset));
    }
}

void Canvas::addTexture(Texture* tex, SDL_Rect* dest, SDL_Rect* clip, int z, double scale, double rot, SDL_RendererFlip flip) {
    int x = dest->x;
    int y = dest->y;
    int w = dest->w;
    int h = dest->h;
    if (z > -1 && z < NUM_LAYERS) {
        tex->setRenderSettings(clip, rot, scale, scale,flip);
        tex->renderToTexture(layers[z], x-xOffset, y-yOffset, w, h);
    } else if (z == Z_BACKGROUND) {
        tex->setRenderSettings(clip, rot, scale, scale,flip);
        tex->renderToTexture(background, x-backgroundXOffset, y-backgroundYOffset,w ,h);
    } else if (z == Z_FOREGROUND) {
        tex->setRenderSettings(clip, rot, scale, scale,flip);
        tex->renderToTexture(foreground, x-xOffset, y-yOffset, w ,h);
    }
}

void Canvas::addOverlay(Texture* tex, SDL_Rect* dest, SDL_Rect* clip, double scale, double rot, SDL_RendererFlip flip) {
    tex->setRenderSettings(clip, rot, scale, scale, flip);
    tex->renderToTexture(overlay, dest->x, dest->y, dest->w, dest->h);
}


void Canvas::renewOffsets() {
    xOffset = levelManager.getCameraXOffset();
    yOffset = levelManager.getCameraYOffset();  
    backgroundXOffset = levelManager.getBackgroundXOffset();
    backgroundYOffset = levelManager.getBackgroundYOffset();  
}



