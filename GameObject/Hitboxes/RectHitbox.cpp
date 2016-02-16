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
    ratio = 0.0;
    isAA = true;
}

RectHitbox::RectHitbox(double x, double y, double w, double h) : w(w), h(h){
    pos = Vec2(x,y);
    ratio = 0.0;
    isAA = true;
}

RectHitbox::RectHitbox(double x, double y, double w, double h, double angle) 
: w(w), h(h), ratio(angle) {
    pos = Vec2(x,y);
    isAA = false;
}

RectHitbox::RectHitbox(Vec2 _pos, double w, double h, double angle) 
: w(w), h(h), ratio(angle) {
    pos = _pos;
    isAA = false;
}

RectHitbox::RectHitbox(const RectHitbox& orig) {
}

RectHitbox::~RectHitbox() {

}

Vec2 RectHitbox::getCorner(int i) {
    if (i < 0 || i > 3) printf("getCorner() : outside of range [0 - 3]: \n");
    else {
        switch (i) {
            case 0 : return pos;
            case 1 : {
                Vec2 test(getX()+w   ,getY());
                return test.rotate(ratio, pos);
            }
            case 2 : {
                Vec2 test(getX()+w   ,getY()+h);
                return test.rotate(ratio, pos);
            }
            case 3 : {
                Vec2 test(getX()   ,getY()+h);
                return test.rotate(ratio, pos);
            }
        }
    }
}

Vec2 RectHitbox::getCentre() { return (getCorner(2)-getCorner(0))/2.0; }

double RectHitbox::getRatio() { return ratio; }

double RectHitbox::getH() { return h; }

double RectHitbox::getW() { return w; }

double RectHitbox::getYatX(double _x) {
    if (isAA) return getY();
    if (_x < pos.getX() || _x > pos.getX()+w ) return 100000000000000000.0;
    else return getY() + (_x-getX())*ratio;
}


bool RectHitbox::collision(Vec2& point) {
    bool boolx = point.getX() >= pos.getX() && point.getX() <= pos.getX() + w;
    bool booly = point.getY() >= getYatX(point.getX()) && 
                    point.getY() <= getYatX(point.getX()) + h;
    
    return booly && boolx;
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
 
 * 0 is the right face
 * 1 is the bottom face
 * 2 is the left face
 * 3 is the top face
 * -1 is error.
 
 */
int RectHitbox::getCollisionFace(RectHitbox& rect, Vec2& prevPos) {
    
    // previous pos hitbox.
    RectHitbox rect2(prevPos.getX(), prevPos.getY(), rect.w, rect.h);
    
    bool boolx, booly;  // whether there was a hit in this axis last frame.
    
    if (!collision(rect2)) { //if it did not collide last frame.
    
        if (!isAA && rect.isAA) {

            if (rect2.getX() < getX()) {
                    boolx = ( rect2.getX() + rect2.getW() ) > getX();
            } else  boolx = getX() + getW() > rect2.getX();

            if (rect2.getY() < getYatX(rect2.getX())) {
                    booly = ( rect2.getY() + rect2.getH() > getYatX(rect.getX()) ) 
                            || ( rect2.getY() + rect2.getH() > getYatX(rect.getX()+rect2.getW()));
            } else  booly = ( rect2.getY() > getYatX(rect2.getX()) + getH())
                            || ( rect2.getY() > getYatX(rect2.getX() + rect2.getW()) + getH());


            //it has hit on a side face.
            if (!boolx && booly) {
                // it has hit right.
                if (rect2.getX() > getX()) return 0;
                // it has hit left.
                else if (rect2.getX() < getX()) return 2;            

            // it has hit on a horizontal face.    
            } else if (boolx) {
                // it has hit bottom.
                if (rect2.getY() > getYatX(rect2.getX()) + getH()) return 1;
                // it has hit top.
                else if (rect2.getY() < getYatX(rect2.getX())) return 3;
            }
            else return -1;

        } else if (isAA && rect.isAA) {    

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

        } 
    }
    
    else {
        return -1;
    } 
}


double RectHitbox::bounceAngle(Vec2& prevPos, double angle, CircleHitbox& circle) {

}

double RectHitbox::bounceAngle(Vec2& prevPos, double angle, LineHitbox& line) {

}

double RectHitbox::bounceAngle(Vec2& prevPos, double angle, RectHitbox& rect) {

}
