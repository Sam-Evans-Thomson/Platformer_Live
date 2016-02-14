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

SlopePlatform::SlopePlatform(Vec2 _pos, int _z, double _w, double _h, double _angle) {
    angle = _angle;
    pos = _pos;
    w =_w;
    h =_h;
    z =_z;
}

SlopePlatform::SlopePlatform(double x, double y, int _z, double _w, double _h, double _angle) {
    angle = _angle;
    pos = Vec2(x,y);
    w = _w;
    h = _h;
    z = _z;
}


SlopePlatform::SlopePlatform(const SlopePlatform& orig) { }

SlopePlatform::~SlopePlatform() { }

void SlopePlatform::init() { hb = new RectHitbox(pos, w, h, angle); }

double SlopePlatform::getYatX(double x) { hb->getYatX(x); }

double SlopePlatform::getAngle() { return angle; }
