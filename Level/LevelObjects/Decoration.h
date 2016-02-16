/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Decoration.h
 * Author: sam
 *
 * Created on 9 February 2016, 2:56 PM
 */

#ifndef DECORATION_H
#define DECORATION_H

#include "../../GameObject/Vec2.h"
#include "../../Graphics/Graphic.h"

class Decoration {
public:
    Decoration();
    Decoration(Vec2 pos, int z, double w, double h);
    Decoration(double x, double y, int z, double w, double h);
    Decoration(const Decoration& orig);
    virtual ~Decoration();
    
    void init();
    void render();
    
    void setGraphic(Graphic* gr);
    virtual void setGraphicDimensions(double x, double y, double _w, double _h);
    
    Vec2 pos;
    int z;
    
    Graphic* graphic;
    
private:
    double w;
    double h;
    double graphX;
    double graphY;
    double graphW;
    double graphH;
    
};

#endif /* DECORATION_H */

