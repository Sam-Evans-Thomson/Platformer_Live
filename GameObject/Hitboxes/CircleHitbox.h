/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircleHitbox.h
 * Author: sam
 *
 * Created on 7 February 2016, 9:53 AM
 */

#ifndef CIRCLEHITBOX_H
#define CIRCLEHITBOX_H

#include "Hitbox.h"

class CircleHitbox : public Hitbox {
public:
    CircleHitbox(Vec2 _pos, double radius);
    CircleHitbox(double x, double y, double radius);
    
    CircleHitbox(const CircleHitbox& orig);
    virtual ~CircleHitbox();
    
    bool collision(Vec2& point) override;
    bool collision(RectHitbox& rect) override;
    bool collision(LineHitbox& line) override;
    bool collision(CircleHitbox& circle) override;
    
    double bounceAngle(Vec2& prevPos, double angle, CircleHitbox& circle) override;
    double bounceAngle(Vec2& prevPos, double angle, LineHitbox& line) override;
    double bounceAngle(Vec2& prevPos, double angle, RectHitbox& rect) override;
    
    double getRadius();
    
private:
    double radius;
};

#endif /* CIRCLEHITBOX_H */

