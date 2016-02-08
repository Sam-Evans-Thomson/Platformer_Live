/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hitbox.h
 * Author: sam
 *
 * Created on 7 February 2016, 10:00 AM
 */

#ifndef HITBOX_H
#define HITBOX_H

#include "../Vec2.h"
#include <stdlib.h>
#include <stdio.h>

class CircleHitbox;
class RectHitbox;
class LineHitbox;
class HorizontalLineHitbox;

class Hitbox {
public:
    Hitbox();
    Hitbox(const Hitbox& orig);
    virtual ~Hitbox();
    
    void move(double x, double y);
    void move(Vec2& vector);
    void moveTo(Vec2& vector);
    void moveTo(double x, double y);
    
    double getX();
    double getY();
    
    virtual void scale(double scale);
    virtual void scaleX(double scale);
    virtual void scaleY(double scale);
    
    virtual void rotate(double angle);
    virtual void rotate(Vec2 orig, double angle);
    
    virtual bool collision(Vec2& point);
    virtual bool collision(CircleHitbox& circle);
    virtual bool collision(RectHitbox& rect);
    virtual bool collision(LineHitbox& line);
    
    virtual double bounceAngle(Vec2& prevPos, double angle, CircleHitbox& circle);
    virtual double bounceAngle(Vec2& prevPos, double angle, RectHitbox& rect);
    virtual double bounceAngle(Vec2& prevPos, double angle, LineHitbox& line);
    
    bool collision(CircleHitbox& circle, CircleHitbox& circle2);
    bool collision(CircleHitbox& circle, RectHitbox& rect);
    bool collision(CircleHitbox& circle, LineHitbox& line);
    bool collision(RectHitbox& rect, RectHitbox& rect2);
    bool collision(RectHitbox& rect, LineHitbox& line);
    bool collision(LineHitbox& line, LineHitbox& line2);
    
    bool collision(HorizontalLineHitbox& hLine, LineHitbox& line);
    bool collision(HorizontalLineHitbox& hLine, CircleHitbox& circle);
    
    Vec2 pos;

private: 
    
};

#endif /* HITBOX_H */

