/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameObject.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 10:27 AM
 */

#include "GameObject.h"

GameObject::GameObject() { }

GameObject::GameObject(const GameObject& orig) { }

GameObject::~GameObject() { }



    //_________________________________________________________//
    //////////////////// GETTERS AND SETTERS ////////////////////

void GameObject::setPos(double x, double y) { pos = Vec2(x,y); }

void GameObject::setPos(Vec2 _pos) { pos = _pos; }

void GameObject::setPos_P(double x, double y) { pos_P = Vec2(x,y); }

void GameObject::setPos_P(Vec2 _pos) { pos_P = _pos; }

void GameObject::setHitbox(Hitbox* hb) { hitbox = hb; }

void GameObject::setZ(int _z) { z = _z; }

void GameObject::setAngle(double _angle) { 
    while (_angle>2*PI) { _angle -= 2*PI; }
    while (_angle<0) { _angle += 2*PI; }
    angle = _angle; 
}

void GameObject::setAngle_P(double _angle) { 
    while (_angle>2*PI) { _angle -= 2*PI; }
    while (_angle<0) { _angle += 2*PI; }
    angle_P = _angle;
}


////////

Vec2 GameObject::getPos() { return pos; }

double GameObject::getX() { return pos.getX(); }

double GameObject::getY() { return pos.getY(); }

Vec2 GameObject::getPos_P() { return pos_P; }

double GameObject::getX_P() { return pos_P.getX(); }

double GameObject::getY_P() { return pos_P.getY(); }

int GameObject::getZ() { return z; }

double GameObject::getAngle() { return angle; }

double GameObject::getAngle_P() { return angle_P; }



Hitbox* GameObject::getHitbox() { return hitbox; }

double GameObject::getDelta() { return timeDelta; }

double GameObject::getDelta_P() { return timeDelta_P; }

    
    //_________________________________________________________//
    //////////////////// ACTIONS /////////////////////////////////
    //      These will apply to children

void GameObject::move(Vec2 move) { 
    pos+=move; 
    hitbox->move(move);
    
    if(numChildren > 0) {
        for (GameObject* child : childObjects) {
            child->move(move, this);
        }
    } 
}

void GameObject::move(double x, double y) { move(Vec2(x,y)); }

void GameObject::scale(double scale) { 
    pos*=scale; 
    hitbox->scale(scale);
    
    if(numChildren > 0) {
        for (GameObject* child : childObjects) {
            child->scale(scale, this);
        }
    }  
}

void GameObject::scaleX(double scale) { 
    pos.setX(scale*pos.getX()); 
    hitbox->scaleX(scale);
    
    if(numChildren > 0) {
        for (GameObject* child : childObjects) {
            child->scaleX(scale, this);
        }
    }
}

void GameObject::scaleY(double scale) { 
    pos.setY(scale*pos.getY()); 
    hitbox->scaleY(scale);
    
    if(numChildren > 0) {
        for (GameObject* child : childObjects) {
            child->scaleY(scale, this);
        }
    }
} 

void GameObject::rotate(double rad) { 
    setAngle(angle+rad);
    
    hitbox->rotate(rad);

    if(numChildren > 0) {
        for (GameObject* child : childObjects) {
            child->rotate(pos, rad, this);
        }
    }
}

void GameObject::rotate(Vec2 orig, double rad) {
    setAngle(angle+rad);
    Vec2 copy = Vec2(pos);
    copy.rotate(rad);
    move(copy - pos);
    
    hitbox->rotate(orig, rad);
    
    if(numChildren > 0) {
        for (GameObject* child : childObjects) {
            child->rotate(orig, rad, this);
        }
    }
}

//// INHERITED ACTIONS FROM PARENT MOVEMENT

void GameObject::move(Vec2 _move, GameObject* parent) {
    move(_move);
    hitbox->move(_move);
}

void GameObject::scale(double _scale, GameObject* parent) {
    move( (parent->getPos() - pos)*(_scale-1.0) );
    scale(_scale);
    hitbox->scale(_scale);
}

void GameObject::scaleX(double scale, GameObject* parent) {
    move( (parent->getX() - pos.getX())*(scale-1), 0 );
    scaleX(scale);
}

void GameObject::scaleY(double scale, GameObject* parent) {
    move( 0, (parent->getY() - pos.getY())*(scale-1));
    scaleY(scale);
}

void GameObject::rotate(double rad, GameObject* parent) { rotate(rad); }

void GameObject::rotate(Vec2 orig, double rad, GameObject* parent) {
    rotate(orig, rad);
}



    //_________________________________________________________//
    //////////////////// PARENT /////////////////////////////////
    //      Each Object except the Level will have a parent object. Most things
    //      will be parented to the level.

void GameObject::setParent(GameObject* parent) { parentObject = parent; }

GameObject* GameObject::getParent() { return parentObject; }



    //_________________________________________________________//
    //////////////////// CHILDREN ///////////////////////////////
    //      Objects can have any number of children. Certain operations done
    //      to the parents will effect the child. These may include translations
    //      rotations and scaling.

void GameObject::addChild(GameObject* child) { childObjects.push_back(child);
}

GameObject* GameObject::getChild() { return childObjects.at(0);
}

GameObject* GameObject::getChild(int i) { return childObjects.at(i);
}

void GameObject::replaceChild(int i, GameObject* child) {
    deleteChild(i);
    addChild(child);
}

void GameObject::deleteChild(int i) {
    childObjects.erase(childObjects.begin() + i);
}

void GameObject::deleteChild(GameObject* child) {
    for(int i = 0; i < childObjects.size(); i++) {
        if (childObjects.at(i) == child) deleteChild(i);
    }
}

    
    //_________________________________________________________//
    //////////////////// GAMELOOP FUNCTIONS /////////////////////
    //      These will be called by the game loop manager.

void GameObject::update(double delta) {

}

void GameObject::render() {

}









