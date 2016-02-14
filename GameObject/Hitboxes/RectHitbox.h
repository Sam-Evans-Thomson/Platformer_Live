/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RectHitbox.h
 * Author: sam
 *
 * Created on 6 February 2016, 3:45 PM
 */

#ifndef RECTHITBOX_H
#define RECTHITBOX_H

#include "Hitbox.h"
#include <iostream>
#include <math.h>

class LineHitbox;

class RectHitbox : public Hitbox {
public:
    RectHitbox(Vec2 _pos, double w, double h);
    RectHitbox(double x, double y, double w, double h);
    
    RectHitbox(Vec2 _pos, double w, double h, double angle);
    RectHitbox(double x, double y, double w, double h, double angle);

    bool collision(Vec2& point) override;
    bool collision(LineHitbox& line) override;
    bool collision(RectHitbox& rect) override;
    bool collision(CircleHitbox& circle) override;
    
    int getCollisionFace(RectHitbox& rect, Vec2& prevPos);

    double bounceAngle(Vec2& prevPos, double angle, CircleHitbox& circle) override;
    double bounceAngle(Vec2& prevPos, double angle, LineHitbox& line) override;
    double bounceAngle(Vec2& prevPos, double angle, RectHitbox& rect) override;

    RectHitbox(const RectHitbox& orig);
    virtual ~RectHitbox();
    
    LineHitbox getLine(int i);
    Vec2 getCorner(int i);
    Vec2 getCentre();
    
    double getW();
    double getH();
    double getYatX(double _x);
    double getAngle();
    
    LineHitbox* left;
    LineHitbox* right;
    LineHitbox* up;
    LineHitbox* down;
    
    bool isAA;
    
protected:   
    
    
    
    void makeLines();
        
    double angle;
    double w;
    double h;
};

#endif /* RECTHITBOX_H */

