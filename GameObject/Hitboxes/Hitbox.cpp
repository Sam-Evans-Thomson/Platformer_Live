/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hitbox.cpp
 * Author: sam
 * 
 * Created on 7 February 2016, 10:00 AM
 */

#include "Hitbox.h"
#include "CircleHitbox.h"
#include "RectHitbox.h"
#include "LineHitbox.h"

#include <iostream>

Hitbox::Hitbox() {
}

Hitbox::Hitbox(const Hitbox& orig) {
}

Hitbox::~Hitbox() {
}

void Hitbox::move(double x, double y) {
    Vec2 mv(x,y);
    pos+=mv;
}

void Hitbox::move(Vec2& vector) {
    pos+=vector;
}

void Hitbox::moveTo(Vec2& vector) {
    pos = vector;
}

void Hitbox::moveTo(double x, double y) {
    pos = Vec2(x,y);
}

double Hitbox::getX() { return pos.getX();

}

double Hitbox::getY() { return pos.getY();

}

void Hitbox::rotate(double angle) {

}

void Hitbox::rotate(Vec2 orig, double angle) {

}

void Hitbox::scale(double scale) {

}

void Hitbox::scaleX(double scale) {

}

void Hitbox::scaleY(double scale) {

}

bool Hitbox::collision(Vec2& point) {

}
bool Hitbox::collision(CircleHitbox& point) {

}

bool Hitbox::collision(RectHitbox& point) {

}

bool Hitbox::collision(LineHitbox& point) {

}


double Hitbox::bounceAngle(Vec2& prevPos, double angle, CircleHitbox& circle) {

}

double Hitbox::bounceAngle(Vec2& prevPos, double angle, LineHitbox& circle) {

}

double Hitbox::bounceAngle(Vec2& prevPos, double angle, RectHitbox& rect) {

}

/////////////////////////////////////////////////////////////////////////////////
////////////    Collisions

bool Hitbox::collision(CircleHitbox& circle, CircleHitbox& circle2) {
    return (circle.pos.length(circle2.pos) < circle.getRadius() + circle2.getRadius());
}

bool Hitbox::collision(CircleHitbox& circle, RectHitbox& rect){
    return (    rect.left->collision(circle)  &&
                rect.right->collision(circle) &&
                rect.up->collision(circle)    &&
                rect.down->collision(circle)
                );
}

bool Hitbox::collision(CircleHitbox& circle, LineHitbox& line){
    Vec2 test(line.pos);
    test.changeReference(line.getAngle(), line.pos);
    CircleHitbox testCirc(test, circle.getRadius());
    return line.hLine.collision(test);
}

bool Hitbox::collision(RectHitbox& rect, RectHitbox& rect2){
    if (rect.isAA && rect2.isAA) {
        
        bool boolx, booly;
        
        if (rect.getX() < rect2.getX()) {
                boolx = rect.getX() + rect.getW() > rect2.getX();
        } else  boolx = rect2.getX() + rect2.getW() > rect.getX();
        
        if (rect.getY() < rect2.getY()) {
                booly = rect.getY() + rect.getH() > rect2.getY();
        } else  booly = rect2.getY() + rect2.getH() > rect.getY();

        return booly&&boolx;
        
    }
    else if (rect.isAA){
        bool boolx, booly;
        
        if (rect.getX() < rect2.getX()) {
                boolx = rect.getX() + rect.getW() > rect2.getX();
        } else  boolx = rect2.getX() + rect2.getW() > rect.getX();
        
        if (rect.getY() < rect2.getYatX(rect.getX())) {
                booly = ( rect.getY() + rect.getH() > rect2.getYatX(rect.getX()) ) 
                        || ( rect.getY() + rect.getH() > rect2.getYatX(rect.getX()+rect.getW()));
        } else  booly = ( rect.getY() > rect2.getYatX(rect.getX()) + rect2.getH())
                        || ( rect.getY() > rect2.getYatX(rect.getX() + rect.getW()) + rect2.getH());
        
        return booly&&boolx;
    }
    
    else if (rect2.isAA) return Hitbox::collision(rect2, rect);
}

bool Hitbox::collision(RectHitbox& rect, LineHitbox& line){
    printf("Rect - Line collision not yet implemented: \n");
}

bool Hitbox::collision(LineHitbox& line, LineHitbox& line2){
    return ( (line.getAngle() == line2.getAngle() + PI/2.0 || 
            line.getAngle() == line2.getAngle() - 3.0*PI/2.0) &&
            line.getY() < line2.getY() );
}

bool Hitbox::collision(HorizontalLineHitbox& hLine, LineHitbox& line){
    return (line.getAngle() == PI/2 && line.getY() < hLine.getY() );
}

bool Hitbox::collision(HorizontalLineHitbox& hLine, CircleHitbox& circle) {
    return ( circle.getY() - circle.getRadius() < hLine.getY() );
}







