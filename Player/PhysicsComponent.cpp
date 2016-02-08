/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhysicsComponent.cpp
 * Author: sam
 * 
 * Created on 6 February 2016, 9:58 AM
 */

#include "PhysicsComponent.h"
#include <string>
#include <iostream>
#include <stdio.h>

#include "../Level/LevelManager.h"

extern LevelManager levelManager;

PhysicsComponent::PhysicsComponent() {
    init();
}

PhysicsComponent::PhysicsComponent(const PhysicsComponent& orig) {
}

PhysicsComponent::~PhysicsComponent() {
    delete pos;
    delete prevPos;
    delete bodyHB;
}

void PhysicsComponent::init() {
    useGravity = false;
    useFriction = true;
    friction = BASE_FRICTION;
    gravity = BASE_GRAVITY;
    angle = 0.0;
    z=1;
    pos = new Vec2(200,860);
    bodyHB = new RectHitbox(*pos, 100.0 ,140.0);
    impulse = Vec2(0,0);
}

void PhysicsComponent::update(double delta) {
    timeDelta = delta;
    if (useGravity) applyGravity();
    if (useFriction) applyFriction();
    
    force = checkForce(force);
    
    movement = (impulse+force)*timeDelta;

    applyMove(movement);
    impulse = Vec2(0,0);
}

void PhysicsComponent::addForce(Vec2 frc) { force+=frc;}

void PhysicsComponent::addForce(double x, double y) {
    force+=Vec2(x,y);
}


void PhysicsComponent::applyFriction() { force = force/(1.0+friction); }

void PhysicsComponent::applyGravity() {  
    Vec2 grav(0.0, gravity);
    force += grav; 
}

void PhysicsComponent::addImpulse(Vec2 _impulse) { impulse = _impulse*timeDelta; }

Vec2 PhysicsComponent::checkForce(Vec2 frc) {
    //check X force;
         if (frc.getX() >  MAX_X_FORCE)       frc.setX( MAX_X_FORCE);
    else if (frc.getX() < -MAX_X_FORCE)       frc.setX(-MAX_X_FORCE);
    
    //check Y force;
         if (frc.getY() >  MAX_Y_FORCE)       frc.setY( MAX_Y_FORCE);
    else if (frc.getY() < -MAX_Y_FORCE)       frc.setY(-MAX_Y_FORCE);
         
    return frc;
}


void PhysicsComponent::applyMove(Vec2 mvmnt) {

    *pos += mvmnt;
    bodyHB->move(mvmnt);
    
    resolveCollisions();
}

void PhysicsComponent::resolveCollisions() { 
    
    for (int i = 0; i<levelManager.platformCount(); i++) {
        resolveCollision(levelManager.getPlayerPlatformHitbox(i));
    }
}

void PhysicsComponent::resolveCollision(RectHitbox* hitbox) {
    std::cout << "Hit" << std::endl;
    if(hitbox->collision(*bodyHB)) {
        std::cout << "Hit" << std::endl;
    }
}

void PhysicsComponent::setForce(Vec2 frc) { force = checkForce(frc); }

void PhysicsComponent::setFriction(double fric) { friction = fric; }

void PhysicsComponent::setGravity(double grav) { gravity = grav; }

void PhysicsComponent::setTimeDelta(double delta) { timeDelta = delta; }

double PhysicsComponent::X() { return pos->getX(); }

double PhysicsComponent::Y() { return pos->getY();}

int PhysicsComponent::Z() { return z; }

double PhysicsComponent::getAngle() { return angle; }

void PhysicsComponent::useFric(bool on) {useFriction = on;}

void PhysicsComponent::useGrav(bool on) {useGravity = on;}





