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

Graphic::Graphic(int frameCount, std::string path) : numFrames(frameCount), path(path) {
    timer = Timer();

}

Graphic::Graphic(const Graphic& orig) {
}

Graphic::~Graphic() {
    delete &timer;
}

void Graphic::setFrameTime(double time) { frameTime = time; }

void Graphic::loadTextures() {
    Texture tex = Texture();
    for (int i = 0; i<numFrames; i++ ) {
        std::string _path;
        _path = path + std::to_string(i) + ".png";
        
        if (&tex == nullptr ) printf("texture failed to loasd: \n");
        else {
            tex.loadFromFile(_path);
            textures.push_back(&tex);
        }
        _path.clear();
    } 
    tex.free();
    start();
}


void Graphic::start() {
    timer.start();    
    currentFrame = 0;
}

bool Graphic::hasFinished() {
    return (timer.getSeconds() > frameTime*(double)numFrames);
}

void Graphic::render(Canvas* canvas, double x, double y, int z, double scale, double rotation) {
    if(timer.getSeconds() > frameTime) {
        incFrame();
        timer.refresh();
    }
    
    //currentTexture = textures[currentFrame];
    currentTexture = textures[0];
    
    canvas->addTexture(currentTexture,x,y,z,scale,rotation);
    
}

void Graphic::incFrame() {

    currentFrame++;
    if (currentFrame >= numFrames) currentFrame = 0;
}



