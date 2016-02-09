/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RectHitbox.cpp
 * Author: sam
 * 
 * Created on 6 February 2016, 3:45 PM
 */

#include "RectHitbox.h"
#include "LineHitbox.h"

RectHitbox::RectHitbox(Vec2 _pos, double w, double h) :  w(w), h(h) { 
    pos = _pos;
    angle = 0.0;
    isAA = true;
    makeLines();
}

RectHitbox::RectHitbox(double x, double y, double w, double h) : w(w), h(h){
    pos = Vec2(x,y);
    angle = 0.0;
    isAA = true;
    makeLines();
}

RectHitbox::RectHitbox(double x, double y, double w, double h, double angle) 
: w(w), h(h), angle(angle) {
    pos = Vec2(x,y);
    isAA = false;
    makeLines();
}

RectHitbox::RectHitbox(Vec2 _pos, double w, double h, double angle) 
: w(w), h(h), angle(angle) {
    pos = _pos;
    isAA = false;
    makeLines();
}

RectHitbox::RectHitbox(const RectHitbox& orig) {
}

RectHitbox::~RectHitbox() {
    delete left;
    delete right;
    delete up;
    delete down;
}

void RectHitbox::makeLines() {
    if (isAA) {
        left  = new LineHitbox(getX()    , getY()       ,  PI/2.0);
        up    = new LineHitbox(getX()    , getY()       ,  -PI);

        right = new LineHitbox(getX()+w  , getY() +h    , -PI/2.0);
        down  = new LineHitbox(getX()+w  , getY() +h    ,  0);
    }
    else {
        Vec2 oc(getX(), getY());
        oc.rotate(angle, pos);

        left  = new LineHitbox(getX()    , getY()       ,  PI/2.0 + angle);
        up    = new LineHitbox(getX()    , getY()       ,  -PI + angle);

        right = new LineHitbox(oc.getX() , oc.getY()    , -PI/2.0 + angle);
        down  = new LineHitbox(0.0       , getY() + h   ,  0 + angle);
    }
}

LineHitbox RectHitbox::getLine(int i) {
    if (i < 0 || i > 3) printf("getLine() : outside of range [0 - 3]: \n");
    else {
        switch (i) {
            case 0 : return *up;
            case 1 : return *right;
            case 2 : return *down;
            case 3 : return *left;
        }
    }
}

Vec2 RectHitbox::getCorner(int i) {
    if (i < 0 || i > 3) printf("getCorner() : outside of range [0 - 3]: \n");
    else {
        switch (i) {
            case 0 : return pos;
            case 1 : {
                Vec2 test(getX()+w   ,getY());
                return test.rotate(angle, pos);
            }
            case 2 : {
                Vec2 test(getX()+w   ,getY()+h);
                return test.rotate(angle, pos);
            }
            case 3 : {
                Vec2 test(getX()   ,getY()+h);
                return test.rotate(angle, pos);
            }
        }
    }
}

Vec2 RectHitbox::getCentre() { return (getCorner(2)-getCorner(0))/2.0; }

double RectHitbox::getAngle() { return angle; }

double RectHitbox::getH() { return h; }

double RectHitbox::getW() { return w;
}

bool RectHitbox::collision(Vec2& point) {
    return (    
            left->collision(point)  &&
            right->collision(point) &&
            up->collision(point)    &&
            down->collision(point)
            );
}

bool RectHitbox::collision(LineHitbox& line) {
    return Hitbox::collision(*this,line);
}

bool RectHitbox::collision(CircleHitbox& circle) {
     return Hitbox::collision(circle, *this);
}

bool RectHitbox::collision(RectHitbox& rect) {
    return Hitbox::collision(rect,*this);
}

/*
 
 * 0 is the left face
 * 1 is the top face
 * 2 is the right face
 * 3 is the bottom face
 * -1 is error.
 
 */
int RectHitbox::getCollisionFace(RectHitbox& rect, Vec2& prevPos) {
    if (isAA && rect.isAA) {
        
        std::cout << "rect getFace(): ";
        
        // previous pos hitbox.
        RectHitbox rect2(prevPos.getX(), prevPos.getY(), rect.w, rect.h);
    
        bool boolx, booly;
        
        if (rect2.getX() < getX()) {
                boolx = ( rect2.getX() + rect2.getW() ) > getX();
        } else  boolx = getX() + getW() > rect2.getX();
        
        if (rect2.getY() < getY()) {
                booly = rect2.getY() + rect2.getH() > getY();
        } else  booly = getY() + getH() > rect2.getY();
        
        
    
        //it has hit on a side face.
        if (!boolx && booly) {
            // it has hit left.
            if (rect2.getX() > getX()) return 0;
            // it has hit right.
            else if (rect2.getX() < getX()) return 2;            
            
        // it has hit on a horizontal face.    
        } else if (!booly && boolx) {
            // it has hit top.
            if (rect2.getY() > getY()) return 1;
            // it has hit bottom.
            else if (rect2.getY() < getY()) return 3;
        }
        else return -1;
    
    
    
    } else {
        printf("getCollisionFace has not been implemented for none AA rect: \n");
        return -1;
    } 
}


double RectHitbox::bounceAngle(Vec2& prevPos, double angle, CircleHitbox& circle) {

}

double RectHitbox::bounceAngle(Vec2& prevPos, double angle, LineHitbox& line) {

}

double RectHitbox::bounceAngle(Vec2& prevPos, double angle, RectHitbox& rect) {

}
