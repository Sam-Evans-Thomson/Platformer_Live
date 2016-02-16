/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SlopePlatform.cpp
 * Author: sam
 * 
 * Created on 14 February 2016, 10:46 AM
 */

#include "SlopePlatform.h"

SlopePlatform::SlopePlatform(Vec2 _pos, int _z, double _w, double _h, double _ratio) {
    ratio = _ratio;
    pos = _pos;
    w =_w;
    h =_h;
    z =_z;
}

SlopePlatform::SlopePlatform(double x, double y, int _z, double _w, double _h, double _ratio) {
    ratio = _ratio;
    pos = Vec2(x,y);
    w = _w;
    h = _h;
    z = _z;
}

SlopePlatform::SlopePlatform(const SlopePlatform& orig) { }

SlopePlatform::~SlopePlatform() {
}

void SlopePlatform::setGraphicDimensions(double x, double y, double _w, double _h) {
    graphX = pos.getX() + x; 
    graphY = pos.getY() + y;
    if (ratio < 0) {
        graphY += hb->getW()*ratio;
    }
    graphW = w + _w; 
    graphH = h + _h - hb->getW()*ratio;
    graphic->setClip(0, 0, graphW, graphH);
}

void SlopePlatform::render() {
    graphic->render(graphX, graphY, z, 1.0, 0.0);    
}



void SlopePlatform::init() { hb = new RectHitbox(pos, w, h, ratio); }

double SlopePlatform::getYatX(double x) { hb->getYatX(x); }

double SlopePlatform::getRatio() { return ratio; }
