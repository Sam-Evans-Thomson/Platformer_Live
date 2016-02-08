/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LineHitbox.cpp
 * Author: sam
 * 
 * Created on 7 February 2016, 9:49 AM
 */

#include "LineHitbox.h"

LineHitbox::LineHitbox(double x, double y, double angle) : angle(angle) {
    pos = Vec2(x,y);
}

LineHitbox::LineHitbox(Vec2 _pos, double angle) :  angle(angle) {
    pos = _pos;
}

LineHitbox::LineHitbox(const LineHitbox& orig) { }

LineHitbox::~LineHitbox() {
}

double LineHitbox::getAngle() { return angle; }

bool LineHitbox::collision(Vec2& point) {
    Vec2 test(pos);
    test.changeReference(angle, pos);
    return hLine.collision(test);
}

bool LineHitbox::collision(CircleHitbox& circle) {
    Hitbox::collision(circle, *this);
}

bool LineHitbox::collision(LineHitbox& line) {
    Hitbox::collision(line, *this);
}

bool LineHitbox::collision(RectHitbox& rect) {
    Hitbox::collision(rect, *this);
}


/////////////////////////////////////////////////////////////////////////////
///////////     HORIZONTAL LINE HITBOX

HorizontalLineHitbox::HorizontalLineHitbox(double x, double y) {
    pos = Vec2(0.0,y);
}

HorizontalLineHitbox::HorizontalLineHitbox(Vec2 _pos) {
    pos = Vec2(0.0, _pos.getY());
}

HorizontalLineHitbox::~HorizontalLineHitbox() { }

bool HorizontalLineHitbox::collision(Vec2& point) { 
    return (point.getY() < getY());
}

bool HorizontalLineHitbox::collision(CircleHitbox& circle) {
    return Hitbox::collision(*this, circle);
}

bool HorizontalLineHitbox::collision(LineHitbox& line) {
    return Hitbox::collision(*this, line);
}

bool HorizontalLineHitbox::collision(RectHitbox& rect) {
    return false;
}


