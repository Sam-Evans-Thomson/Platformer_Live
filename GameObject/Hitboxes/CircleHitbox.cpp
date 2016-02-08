/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircleHitbox.cpp
 * Author: sam
 * 
 * Created on 7 February 2016, 9:53 AM
 */

#include "CircleHitbox.h"

CircleHitbox::CircleHitbox(double x, double y, double radius) : radius(radius) {
    pos = Vec2(x,y);
}

CircleHitbox::CircleHitbox(Vec2 _pos, double radius) : radius(radius) {
    pos = _pos;
}

CircleHitbox::CircleHitbox(const CircleHitbox& orig) {
}

CircleHitbox::~CircleHitbox() {
}

bool CircleHitbox::collision(Vec2& point) { 
    return (pos.length(point) < radius);
}

bool CircleHitbox::collision(RectHitbox& rect) { 
    return Hitbox::collision(*this, rect);
}

bool CircleHitbox::collision(CircleHitbox& circle) { 
    return Hitbox::collision(*this,circle);
}

bool CircleHitbox::collision(LineHitbox& line) { 
    return Hitbox::collision(*this,line);
}

double CircleHitbox::bounceAngle(Vec2& prevPos, double angle, CircleHitbox& circle) {
    printf("Circle bounce angle has not yet been implemented: \n");
}

double CircleHitbox::bounceAngle(Vec2& prevPos, double angle, LineHitbox& line) {
    printf("Circle bounce angle has not yet been implemented: \n");
}

double CircleHitbox::bounceAngle(Vec2& prevPos, double angle, RectHitbox& rect) {
    printf("Circle bounce angle has not yet been implemented: \n");
}

double CircleHitbox::getRadius() { return radius; }




