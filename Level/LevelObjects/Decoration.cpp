/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decoration.cpp
 * Author: sam
 * 
 * Created on 9 February 2016, 2:56 PM
 */

#include "Decoration.h"

Decoration::Decoration() {
}

Decoration::Decoration(Vec2 pos, int z, double w, double h) : pos(pos), z(z), w(w), h(h) {
    
}

Decoration::Decoration(double x, double y, int z, double w, double h) 
: w(w), h(h), z(z) {
    pos = Vec2(x,y);
}


Decoration::Decoration(const Decoration& orig) {
}

Decoration::~Decoration() {
}

void Decoration::init() { if (graphic != nullptr) graphic->start(); }

void Decoration::setGraphic(Graphic* gr) { graphic = gr; }

void Decoration::setGraphicDimensions(double x, double y, double _w, double _h) {
    graphX = pos.getX() + x; 
    graphY = pos.getY() + y;
    graphW = w + _w; 
    graphH = h + _h;
    graphic->setClip(0, 0, graphW, graphH);
}

void Decoration::render() { graphic->render(graphX, graphY, z, 1.0, 0.0); }

