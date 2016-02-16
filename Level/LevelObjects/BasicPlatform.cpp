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

BasicPlatform::BasicPlatform() {

}


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
    if (hb != nullptr) delete hb;
}

Vec2 BasicPlatform::getPos() { return pos; }
double BasicPlatform::getX() { return pos.getX(); }
double BasicPlatform::getH() { return h; }
double BasicPlatform::getW() { return w; }
double BasicPlatform::getY() { return pos.getY();
}

void BasicPlatform::setGraphic(Graphic* gr) { graphic = gr; }

void BasicPlatform::setGraphicDimensions(double x, double y, double _w, double _h) {
    graphX = pos.getX() + x; 
    graphY = pos.getY() + y;
    graphW = w + _w; 
    graphH = h + _h;
    graphic->setClip(0, 0, graphW, graphH);
}

void BasicPlatform::init() {
    hb = new RectHitbox(pos,w,h);
    if (graphic != nullptr) graphic->start();
}

void BasicPlatform::render() {
    graphic->render(graphX, graphY, z, 1.0, 0.0);    
}

double BasicPlatform::getRatio() { return hb->getRatio(); }

double BasicPlatform::getYatX(double x) { return pos.getY(); }

int BasicPlatform::getZ() { return z; }

void BasicPlatform::setDropThrough(bool drop) { isDropThrough = drop; }








