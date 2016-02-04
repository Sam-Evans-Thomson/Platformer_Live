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

Graphic::Graphic() {
}

Graphic::Graphic(const Graphic& orig) {
}

Graphic::~Graphic() {
}

void Graphic::loadTextures() {
    Texture tex;
    for (int i = 0; i<numFrames; i++ ) {
        std::string _path;
        _path = path + std::to_string(i) + ".png";
        tex.loadFromFile(_path);
        textures.push_back(&tex);
    } 
}


void Graphic::start() {
    timer.start();
}

bool Graphic::hasFinished() {
    return (timer.getSeconds() > frameTime*(double)numFrames);
}

void Graphic::render(Canvas* canvas, double x, double y, int z, double scale, double rotation) {
    if(timer.getSeconds() > frameTime) {
        incFrame();
        timer.refresh();
    }
    currentTexture = textures.at(currentFrame);
    
    canvas->addTexture(currentTexture,x,y,z,scale,rotation);
    
}

void Graphic::incFrame() {
    currentFrame++;
    if (currentFrame == numFrames) currentFrame = 0;
}



