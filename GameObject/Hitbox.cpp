/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hitbox.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 10:27 AM
 */

#include "Hitbox.h"



/*
 *  HITBOX SUPERCLASS
 */

Hitbox::Hitbox() { pos = Vec2(0,0); }

Hitbox::Hitbox(const Hitbox& orig) { pos = orig.pos; }

Hitbox::~Hitbox() { }

Hitbox::Hitbox(double x, double y) { pos = Vec2(x,y); }

Hitbox::Hitbox(Vec2 v) { pos = Vec2(v); }


    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////

double Hitbox::getX() { return pos.getX(); }

double Hitbox::getY() { return pos.getY(); }

Vec2 Hitbox::getPos() { return pos; }

void Hitbox::setX(double x) { pos.setX(x); }

void Hitbox::setY(double y) { pos.setY(y); }

void Hitbox::setPos(Vec2 _pos) { pos = _pos; }
    
    
    //_________________________________________________________//
    //////////////////// ALTERATIONS //////////////////////////// 

void Hitbox::move(Vec2 v) { pos+=v; }

void Hitbox::move(double x, double y) { pos + Vec2(x,y);
}

double Hitbox::deg(double rad) {
    return rad * 180 / PI;
}

double Hitbox::rad(double deg) {
    return deg * PI / 180;
}

void Hitbox::rotate(double rad) {

}

void Hitbox::rotate(Vec2 orig, double rad) {

}

void Hitbox::scale(double scale) {

}

void Hitbox::scaleX(double scale) {

}

void Hitbox::scaleY(double scale) {

}


    //_________________________________________________________//
    //////////////////// COLLISION DETECTION ////////////////////

bool Hitbox::collision_Circle_Circle(HitboxCircle& hbc, HitboxCircle& hbc2) {
    double radius1 = hbc.getRadius();
    double radius2 = hbc2.getRadius();
    double distance = hbc.getPos().length(hbc2.getPos());
    return distance < radius1+radius2;
}

bool Hitbox::collision_Circle_Line(HitboxCircle& hbc, HitboxLine& hbl) {
    
}

bool Hitbox::collision_Circle_Multi(HitboxCircle& hbc, HitboxMulti& hbm) {

}

bool Hitbox::collision_Circle_Poly(HitboxCircle& hbc, HitboxPoly& hbp) {

}

bool Hitbox::collision_Circle_Point(HitboxCircle& hbc, Vec2& p) {

}

bool Hitbox::collision_Line_Line(HitboxLine& hbl, HitboxLine& hbl2) {

}

bool Hitbox::collision_Line_Multi(HitboxLine& hbl, HitboxMulti& hbm) {

}

bool Hitbox::collision_Line_Poly(HitboxLine& hbl, HitboxPoly& hbp) {

}

bool Hitbox::collision_Line_Point(HitboxLine& hbl, Vec2& p) {

}

bool Hitbox::collision_Multi_Multi(HitboxMulti& hbm, HitboxMulti& hbm2) {

}

bool Hitbox::collision_Multi_Poly(HitboxMulti& hbm, HitboxPoly& hbp) {

}

bool Hitbox::collision_Multi_Point(HitboxMulti& hbm, Vec2& p) {

}

bool Hitbox::collision_Poly_Poly(HitboxPoly& hp, HitboxPoly& hbp2) {

}

bool Hitbox::collision_Poly_Point(HitboxPoly& hp, Vec2& p) {

}



////////////////////////////////////////////////////////////////////////////
/*
 *  CIRCLE CLASS
 */

HitboxCircle::HitboxCircle() { pos = Vec2(0,0); }

HitboxCircle::HitboxCircle(Vec2 _pos, double rad) : radius(rad) { pos = _pos; }

HitboxCircle::HitboxCircle(double x, double y, double rad) : radius(rad) {
    pos = Vec2(x,y);
}


    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////

double HitboxCircle::getRadius() { return radius; }

void HitboxCircle::setRadius(double rad) { radius = rad; }


    //_________________________________________________________//
    //////////////////// ALTERATIONS ////////////////////////////  

void HitboxCircle::scale(double scale) { radius *= scale; }






////////////////////////////////////////////////////////////////////////////
/*
 *  LINE CLASS
 */

HitboxLine::HitboxLine() { pos = Vec2(0,0); }

HitboxLine::HitboxLine(Vec2 _pos, double _angle) : angle(_angle) {pos = _pos; }

HitboxLine::HitboxLine(double x, double y, double _angle) : angle(_angle) {
    pos = Vec2(x,y); 
}

HitboxLine::HitboxLine(Vec2 _pos1, Vec2 _pos2) {
    pos = _pos1;
    angle = _pos1.angle(_pos2) + PI/4;
}

    
    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////

double HitboxLine::getAngle() { return HitboxLine::angle; }

double HitboxLine::getAngleDeg() { return deg(HitboxLine::angle); }

void HitboxLine::setAngle(double _angle) {
    while (_angle > PI) _angle -= 2*PI;
    while (_angle < -PI) _angle += 2*PI;
    HitboxLine::angle = _angle;
}

void HitboxLine::setAngleDeg(double _angle) { setAngle(rad(_angle)); }


    //_________________________________________________________//
    //////////////////// ALTERATIONS         ////////////////////
    
void HitboxLine::move(double amount) { pos += Vec2(angle, amount, 1); }    

void HitboxLine::rotate(double _angle) { angle += _angle; }

void HitboxLine::rotateDeg(double _angle) { angle += rad(_angle); }

    
    

////////////////////////////////////////////////////////////////////////////
/*
 *  MULTI CLASS
 */

HitboxMulti::HitboxMulti() { 
    numHitboxes = 0;
    pos = Vec2(0,0); 
}

HitboxMulti::HitboxMulti(Hitbox* hbp) {
    numHitboxes = 1;
    pos = hbp->getPos();
    hitboxes.push_back(hbp);
}

HitboxMulti::HitboxMulti(std::vector<Hitbox*> hitboxes) {
    
}


    
    
    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////

Hitbox* HitboxMulti::getHitbox(int i) { return hitboxes.at(i); }    

std::vector<Hitbox*> HitboxMulti::getHitboxes(int i, int j) {
    std::vector<Hitbox*> temp;
    for (int k = i; k < j; k++) temp.push_back(getHitbox(k));
    return temp;
}

void HitboxMulti::setHitbox(int i, Hitbox* hbp) {
    removeHitbox(i);
    addHitbox(hbp);
}

void HitboxMulti::setHitboxes(int i, int j, std::vector<Hitbox*> hitboxes) {
    for (int k = i; k < j; k++) setHitbox(k,hitboxes.at(k));
}

int HitboxMulti::getNumHitboxes() { return numHitboxes; }

void HitboxMulti::addHitbox(Hitbox* hbp) {
    numHitboxes++;
    hitboxes.push_back(hbp);
}

void HitboxMulti::addHitboxes(std::vector<Hitbox*> hitboxes) {
    for(int i = 0; i < hitboxes.size(); i++)  addHitbox(hitboxes[i]);
}

void HitboxMulti::removeHitbox(Hitbox* hbp) {
    for(int i = 0; i < hitboxes.size(); i++) if (hitboxes.at(i) == hbp) removeHitbox(i);
}

void HitboxMulti::removeHitbox(int i) {
    if(i < numHitboxes && i > -1 && numHitboxes > 0) {
        numHitboxes--;
        hitboxes.erase(hitboxes.begin()+i);
    }
}

void HitboxMulti::removeHitboxes(int i, int j) {
    for (int k = i; k < j; k++) removeHitbox(k);
}

void HitboxMulti::removeHitboxes(std::vector<Hitbox*> hitboxes) {
    for (int i = 0; i < hitboxes.size(); i++) removeHitbox(hitboxes.at(i));
}

    
    //_________________________________________________________//
    //////////////////// ALTERATIONS //////////////////////////// 

void HitboxMulti::move(Vec2 v) {
    for (Hitbox* hb : hitboxes) hb->move(v);
}

void HitboxMulti::move(double x, double y) {
    for (Hitbox* hb : hitboxes) hb->move(Vec2(x,y));
}

void HitboxMulti::moveHitbox(Hitbox* hbp, Vec2 v) { hbp->move(v); }

void HitboxMulti::moveHitbox(Hitbox* hbp, double x, double y) { hbp->move(Vec2(x,y)); }

void HitboxMulti::moveHitboxes(std::vector<Hitbox*> hitboxes, Vec2 v) {
    for (Hitbox* hb : hitboxes) hb->move(Vec2(v));
}

void HitboxMulti::moveHitboxes(std::vector<Hitbox*> hitboxes, double x, double y) {
    for (Hitbox* hb : hitboxes) hb->move(Vec2(Vec2(x,y)));
}




////////////////////////////////////////////////////////////////////////////
/*
 *  POLYGON CLASS
 */

HitboxPoly::HitboxPoly() { 
    numSides = 0;
    pos = Vec2(0,0); 
    HitboxPoly::createHitboxLines();
}

HitboxPoly::HitboxPoly(Vec2 v[], const int size) {
    numSides = size-1;
    for (int i = 0; i < size; i++) vectors.push_back(v[i]);
}

HitboxPoly::HitboxPoly(std::vector<Vec2*> vec2s) {
    numSides = vec2s.size() - 1;
    for (int i = 0; i < vec2s.size(); i++) {
        Vec2 temp = *vec2s[i];
        vectors.push_back(temp);
    }
}


    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////

HitboxLine* HitboxPoly::getLine(int i) { return &lines.at(i); }

void HitboxPoly::setLine(int i, HitboxLine hbl) { 
    if ( i < numSides && i > 0)lines.at(i) = hbl;
}

void HitboxPoly::addLine(HitboxLine hbl) {
    numSides++;
    HitboxPoly::lines.push_back(hbl);
}

void HitboxPoly::addLines(HitboxLine hbls[], const int size) {
    for(int i = 0; i < size; i++) addLine(hbls[i]);
}

void HitboxPoly::removeLine(int i) { lines.erase(lines.begin() + i); }

void HitboxPoly::removeLines(int i, int j) {
    std::vector<HitboxLine>::iterator it;
    for (it = lines.begin() + i; it < lines.begin()+j; it++) {
        lines.erase(it);
    } 
}

int HitboxPoly::getNumSides() { return numSides; }

    
    //_________________________________________________________//
    //////////////////// ALTERATIONS ////////////////////////////  

void HitboxPoly::move(Vec2 v) {
    for(int i = 0 ; i < lines.size(); i++) lines.at(i).super::move(v);
}

void HitboxPoly::move(double x, double y) {
    for(int i = 0 ; i < lines.size(); i++) lines.at(i).super::move(Vec2(x,y));
}

void HitboxPoly::moveLine(int i, double v) { lines.at(i).move(v); }

void HitboxPoly::moveLines(int i, int j, double v) {
    for(int k = i ; k < j; k++) lines.at(k).move(v);
}

void HitboxPoly::moveVertex(int i, Vec2 v) {
    vectors.at(i)+=v;
    createHitboxLines();
}

void HitboxPoly::moveVertex(int i, double x, double y) {
    vectors.at(i)+=Vec2(x,y);
    createHitboxLines();
}

void HitboxPoly::moveVertexes(int i, int j, double x, double y) {
    for(int k = i ; k < j; k++) vectors.at(k)+=Vec2(x,y);
    createHitboxLines();
}

void HitboxPoly::moveVertexes(int i, int j, Vec2 v) {
    for(int k = i ; k < j; k++) vectors.at(k)+=v;
    createHitboxLines();
}

void HitboxPoly::rotate(double angle) {
    if (vectors.size() > 1) {
        Vec2 origin = vectors[0];
        
        for(int i = 1; i < vectors.size(); i++) {
            vectors[i].rotate(angle, origin);
        }
    }
    createHitboxLines();
}

void HitboxPoly::scale(double scale) {
    if (vectors.size() > 1) {
        Vec2 origin = vectors[0];
        
        for(int i = 1; i < vectors.size(); i++) {
            vectors[i]-=origin;
            vectors[i]*=scale;
            vectors[i]+=origin;
        }
    }
    createHitboxLines();
}

void HitboxPoly::createHitboxLines() {
    int numVecs = vectors.size();
    
    if (numVecs > 1) {
    
        //remove HitboxLines from lines.
        lines.clear();  

        // Find a point guaranteed to be inside the shape.
        double xTot, yTot = 0;

        std::vector<Vec2> vecs;
        double angles[numVecs];

        for (int i = 0; i < numVecs; i++) {
            vecs[i] = vectors[i];
            xTot+=vectors[i].getX();
            yTot+=vectors[i].getY();
        }

        Vec2 centre = Vec2(xTot,yTot)/numVecs; 


        // Put the angles between the centre and the vec2 in a vector.
        // Find the lowest angle.
        // Find the array position of the lowest angle.
        double leastAngle = PI;
        int leastAnglePos = -1;
        for( int i = 0; i < numVecs; i++) {
            angles[i] = centre.angle(vecs[i]);
            if(angles[i] < leastAngle) {
                leastAngle = angles[i];
                leastAnglePos = i;
            }
        }

        Vec2 firstVec = vecs[leastAnglePos]; // need to keep this for wrap-around.
        Vec2 currVec = vecs[leastAnglePos]; // this is the current focus vector.
        Vec2 nextVec;
        vecs.erase(vecs.begin() + leastAnglePos); // remove currVec from list.

        while (vecs.size() != 0) {

            // find the next lowest angle.
            // find it's array position.
            double leastAngle = PI;
            int leastAnglePos = -1;
            for( int i = 0; i < vecs.size(); i++) {
                if(angles[i] < leastAngle) {
                    leastAngle = angles[i];
                    leastAnglePos = i;
                }
            }

            nextVec = vecs[leastAnglePos];

            // since we are moving from negative to positive the HitboxLine needs
            // to be made with it's angle pointing towards the inner of the circle.
            // this is why nextVec comes before currVec in HitboxLine creation.
            lines.push_back(HitboxLine(nextVec,currVec)); //
            currVec = nextVec;

            vecs.erase(vecs.begin() + leastAnglePos);

        }

        lines.push_back(HitboxLine(currVec,firstVec));

    }

}





















