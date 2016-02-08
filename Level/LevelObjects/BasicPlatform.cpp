/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasicPlatform.cpp
 * Author: sam
 * 
 * Created on 6 February 2016, 3:14 PM
 */

#include "BasicPlatform.h"

BasicPlatform::BasicPlatform(Vec2 pos, double w, double h) 
: pos(pos), w(w), h(h) {
}

BasicPlatform::BasicPlatform(double x, double y, double w, double h) 
: w(w), h(h) {
    pos = Vec2(x,y);
}

// init is called until it returns -1
// if 0 is the input it is the first initalize in the sequence.
int BasicPlatform::init(int i) {
    switch (i) {
        case 1 : return initLast();
        case 0 : return initFirst();
    }
}

int BasicPlatform::initFirst() {
    loadHitbox();
    return 1;
}

int BasicPlatform::initLast() {
    loadGraphic();
    return -1;
}

BasicPlatform::BasicPlatform(const BasicPlatform& orig) {
}

BasicPlatform::~BasicPlatform() {
    delete hb;
    delete graphic;
}

void BasicPlatform::setGraphicPath(std::string _path) { 
    path = _path; 
    numFrames = 1;
}

void BasicPlatform::setGraphicPath(int frameCount, std::string _path) {
    path = _path; 
    numFrames = frameCount;
}

Vec2 BasicPlatform::getPos() { return pos; }
double BasicPlatform::getX() { return pos.getX(); }
double BasicPlatform::getH() { return h; }
double BasicPlatform::getW() { return w; }
double BasicPlatform::getY() { return pos.getY(); }

void BasicPlatform::loadHitbox() {
    hb = new RectHitbox(pos,w,h);
}

void BasicPlatform::loadGraphic() {
    if(numFrames > 0) {
        graphic = new Graphic(numFrames,path);
    }
}






