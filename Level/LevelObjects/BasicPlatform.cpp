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

BasicPlatform::BasicPlatform(Vec2 pos, int z, double w, double h) 
: pos(pos), w(w), h(h), z(z) {
}

BasicPlatform::BasicPlatform(double x, double y, int z, double w, double h) 
: w(w), h(h), z(z) {
    pos = Vec2(x,y);
}

BasicPlatform::BasicPlatform(const BasicPlatform& orig) {
}

BasicPlatform::~BasicPlatform() {
    if(hb != nullptr) delete hb;
    if (graphic != nullptr) delete graphic;
}

Vec2 BasicPlatform::getPos() { return pos; }
double BasicPlatform::getX() { return pos.getX(); }
double BasicPlatform::getH() { return h; }
double BasicPlatform::getW() { return w; }
double BasicPlatform::getY() { return pos.getY(); }

void BasicPlatform::setGraphicPath(std::string _path) { 
    path = _path; 
    numFrames = 1;
}

void BasicPlatform::setGraphicPath(int frameCount, std::string _path) {
    path = _path; 
    numFrames = frameCount;
}

void BasicPlatform::setGraphicDimensions(double x, double y, double _w, double _h) {
    graphX = pos.getX() + x; 
    graphY = pos.getY() + y;
    graphW = w + _w; 
    graphH = h + _h;
    graphic->setClip(0, 0, graphW, graphH);
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

void BasicPlatform::render() {
    graphic->render(graphX, graphY, z, 1.0, 0.0);    
}

void BasicPlatform::loadHitbox() { hb = new RectHitbox(pos,w,h); }

void BasicPlatform::loadGraphic() {
    if(numFrames > 0) {
        graphic = new Graphic(numFrames,path);
        graphic->loadTextures();
    }
}






