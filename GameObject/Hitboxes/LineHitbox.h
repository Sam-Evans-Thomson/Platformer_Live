/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LineHitbox.h
 * Author: sam
 *
 * Created on 7 February 2016, 9:49 AM
 */

#ifndef LINEHITBOX_H
#define LINEHITBOX_H

#include "Hitbox.h"

class HorizontalLineHitbox : public Hitbox {
public:
    HorizontalLineHitbox(double x, double y);
    HorizontalLineHitbox(Vec2 _pos);
    virtual ~HorizontalLineHitbox();
    
    bool collision(Vec2& point) override;
    bool collision(CircleHitbox& cirlce) override;
    bool collision(LineHitbox& line) override;
    bool collision(RectHitbox& rect) override;
    
private:

};

class LineHitbox : public Hitbox {
public:
    LineHitbox(double x, double y, double angle);
    LineHitbox(Vec2 _pos, double angle);
    LineHitbox(const LineHitbox& orig);
    virtual ~LineHitbox();
    
    double getAngle();
    
    bool collision(Vec2& point) override;
    bool collision(CircleHitbox& circle) override;
    bool collision(LineHitbox& line) override;
    bool collision(RectHitbox& rect) override;
    
    
    HorizontalLineHitbox hLine = HorizontalLineHitbox(0,0);
private:

    double angle;

};



#endif /* LINEHITBOX_H */

