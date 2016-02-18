/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graphic.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 1:16 PM
 */

#include "Graphic.h"

extern Canvas canvas;

Graphic::Graphic(int frameCount, std::string path) : numFrames(frameCount), path(path) {
    timer = new Timer(); 
    doesReverse = true;
    paused = (numFrames == 1);
    direction = true;
}

Graphic::Graphic(const Graphic& orig) {
}

Graphic::~Graphic() {
    delete timer;
    for (Texture* texptr : textures) delete texptr;
}

void Graphic::loadTextures() {
    
    for (int i = 0; i<numFrames; i++ ) {
        std::string _path;
        _path = path + std::to_string(i) + ".png";
        
        textures.push_back(new Texture());
        textures.at(i)->loadFromFile(_path);
        
        _path.clear();
    } 
    
    clip.x = 0;
    clip.y = 0;
    clip.w = textures.at(0)->getWidth();
    clip.h = textures.at(0)->getHeight();
}

void Graphic::setFrameTime(double time) { frameTime = time; }

void Graphic::setReversing(bool rev) { doesReverse = rev; }

void Graphic::setDirection(bool dir) { direction = dir; }

void Graphic::setClip(int x, int y, int w, int h) { clip = {x,y,w,h}; }

void Graphic::setFrame(int i) { currentFrame = i; }

void Graphic::setFirst() { 
    paused = true;
    currentFrame = 0;  
}

void Graphic::flip() { direction = !direction; }



void Graphic::start() { timer->start(); currentFrame = 0; }

void Graphic::pause() { paused = true;}

void Graphic::resume() { paused = false;}


bool Graphic::isReversing() { return doesReverse;}

bool Graphic::hasFinished() {
    return (timer->getSeconds() > frameTime*(double)numFrames);
}


void Graphic::render(double x, double y, int z, double scale, double rotation) {
    
    renderToCanvas(textures.at(currentFrame),x+clip.x,y+clip.y,z, scale,rotation);
    
    if (!paused && numFrames > 1) {
        if(timer->getSeconds() > frameTime) {
            incFrame();
            timer->refresh();
        }
    }  
}

void Graphic::renderAsOverlay(double x, double y, double scale, double rot) {
    if (!paused && numFrames > 1) {
        if(timer->getSeconds() > frameTime) {
            incFrame();
            timer->refresh();
        }
    }
    
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (!direction) { flip = SDL_FLIP_HORIZONTAL; }
    
    SDL_Rect temp = {(int)x+clip.x,(int)y+clip.y,clip.w,clip.h};
    canvas.addOverlay(textures.at(currentFrame), &temp, &clip, scale, rot, flip);
}



//////////// PRIVATE /////////////////////////////


void Graphic::renderToCanvas(Texture* tex, double x, double y, int z, double scale, double rotation) {
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    
    if (!direction) {
        flip = SDL_FLIP_HORIZONTAL; 
    }
    
    SDL_Rect temp = {(int)x,(int)y,clip.w,clip.h};
    canvas.addTexture(tex, &temp, &clip, z ,1.0, rotation, flip);
}

void Graphic::incFrame() {
    
    if (numFrames > 1) {
        if (doesReverse) {
            if (reversing == false) {
                currentFrame++;
                if (currentFrame >= numFrames) {
                    currentFrame-=2;
                    reversing = true;
                }
            }
            else if (reversing == true) {
                currentFrame--;
                if (currentFrame < 0) {
                    currentFrame+=2;
                    reversing = false;
                }
            }
        }
        else {
            currentFrame++;
            if (currentFrame >= numFrames) currentFrame = 0;
        }
    }
}



