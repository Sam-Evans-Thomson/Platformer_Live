/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BasicPlatform.h
 * Author: sam
 *
 * Created on 6 February 2016, 3:14 PM
 */

#ifndef BASICPLATFORM_H
#define BASICPLATFORM_H

#include "../../GameObject/Hitboxes/RectHitbox.h"
#include "../../Graphics/Graphic.h"

/*
 * This is a Axis ALigned Rectangular object that the player will
 * Collide with at each side.
 */

class BasicPlatform {
public:
    BasicPlatform();
    BasicPlatform(Vec2 pos, int z, double w, double h);
    BasicPlatform(double x, double y, int z, double w, double h);
    BasicPlatform(const BasicPlatform& orig);
    virtual ~BasicPlatform();
    
    void setGraphic(Graphic* gr);
    void setGraphicDimensions(double x, double y, double _w, double _h);
    
    virtual void init();
    void render();
    
    Vec2 getPos();
    double getX();
    double getW();
    double getY();
    double getH();
    
    virtual double getYatX(double x);
    virtual double getAngle();
    
    // HEAP
    RectHitbox* hb = nullptr; // RectHitbox owned by this class.
    Graphic* graphic; // ptr to Graphic owned by ResourceManager.
    
protected: 

    Vec2 pos;
    double w;
    double h;
    int z;
    
    double graphX;
    double graphY;
    double graphW;
    double graphH;
    
private:

};

#endif /* BASICPLATFORM_H */

