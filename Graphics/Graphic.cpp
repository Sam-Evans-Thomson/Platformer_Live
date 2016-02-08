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
    timer = Timer(); 
    doesReverse = true;
    paused = (numFrames == 1);
    direction = true;
}

Graphic::Graphic(const Graphic& orig) {
}

Graphic::~Graphic() {
    delete &timer;
    delete &textures;
}

void Graphic::setFrameTime(double time) { frameTime = time; }

void Graphic::loadTextures() {
    for (int i = 0; i<numFrames; i++ ) {
        std::string _path;
        _path = path + std::to_string(i) + ".png";
        textures[i].loadFromFile(_path);
        _path.clear();
    } 

}

bool Graphic::isReversing() { return doesReverse;}

void Graphic::setReversing(bool rev) { doesReverse = rev; }

void Graphic::start() {
    timer.start();    
    currentFrame = 0;
    paused = false;
}

void Graphic::pauseAnimation() { paused = true;}

void Graphic::setFirst() { 
    paused = true;
    currentFrame = 0;  
}

void Graphic::contAnimation() { paused = false;}

void Graphic::flip() { 
    std::cout << "flip" << std::endl;
    direction = !direction; }


bool Graphic::hasFinished() {
    return (timer.getSeconds() > frameTime*(double)numFrames);
}

void Graphic::render(double x, double y, int z, double scale, double rotation) {
    if (!paused) {
        if(timer.getSeconds() > frameTime) {
            incFrame();
            timer.refresh();
        }
    }
    if (!direction) {
        canvas.addTexture(&textures[currentFrame],x,y,z,scale,rotation,SDL_FLIP_HORIZONTAL);
    }
    else canvas.addTexture(&textures[currentFrame],x,y,z,scale,rotation);

}

void Graphic::incFrame() {
    if (numFrames > 1) {
        if (doesReverse) {
            if (reversing == false) {
                currentFrame++;
                if (currentFrame >= numFrames) {
                    currentFrame-=2;
                    reversing =true;
                }
            }
            else if (reversing == true) {
                currentFrame--;
                if (currentFrame <= 0) {
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



