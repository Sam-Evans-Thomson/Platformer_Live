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

#include "../Level/LevelManager.h"
#include "Player.h"
#include "PlayerStates/PrimaryState.h"
#include "../GameObject/Hitboxes/RectHitbox.h"
#include "../Level/LevelObjects/BasicPlatform.h"

extern LevelManager levelManager;
extern Player player;

PhysicsComponent::PhysicsComponent() {
    init();
}

PhysicsComponent::PhysicsComponent(const PhysicsComponent& orig) {
}

PhysicsComponent::~PhysicsComponent() {
    delete pos;
    delete prevPos;
    delete bodyHB;
    delete underFeetHB;
}

void PhysicsComponent::init() {
    useGravity = false;
    useFriction = true;
    frictionX = BASE_FRICTION;
    frictionY = BASE_FRICTION;
    gravity = BASE_GRAVITY;
    angle = 0.0;
    z = 5;
    pos = new Vec2(4000,2700);
    prevPos = new Vec2(4000,2700);
    bodyHB = new RectHitbox(*pos, PLAYR_W ,PLAYR_H);
    underFeetHB = new RectHitbox(
            pos->getX(), 
            pos->getY() + PLAYR_H, 
            PLAYR_W,
            2);
    
    impulse = Vec2(0,0);
}

void PhysicsComponent::update(double delta) {
    prevPos->setX(pos->getX());
    prevPos->setY(pos->getY());
    
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


void PhysicsComponent::applyFriction() { 
    force = Vec2( force.getX()/(1.0+frictionX),
            force.getY()/(1.0+frictionY) ); 
}

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
    else if (frc.getY() <  MAX_Y_FORCE_UP)    frc.setY( MAX_Y_FORCE_UP);
         
    return frc;
}


void PhysicsComponent::applyMove(Vec2 mvmnt) {

    *pos += mvmnt;
    
    bodyHB->moveTo(*pos);
    underFeetHB->move(mvmnt);
    
    player.primary->resolvePlatformCollisions();
    
}

void PhysicsComponent::previousPos() {
    pos->setX(prevPos->getX());
    pos->setY(prevPos->getY());
    bodyHB->moveTo(*pos);
    underFeetHB->moveTo(pos->getX(), pos->getY() + PLAYR_H);
}


void PhysicsComponent::applyMoveTo(Vec2 _pos) {

    *pos = _pos;
    
    bodyHB->moveTo(_pos);
    underFeetHB->moveTo(pos->getX() + 15, pos->getY() + PLAYR_H);
    
    //resolveEnemyCollisions();
    player.primary->resolvePlatformCollisions();
    
}


void PhysicsComponent::setForce(Vec2 frc) { force = checkForce(frc); }

void PhysicsComponent::setFrictionX(double fric) { frictionX = fric; }

void PhysicsComponent::setFrictionY(double fric) { frictionY = fric; }

void PhysicsComponent::setGravity(double grav) { gravity = grav; }

void PhysicsComponent::setTimeDelta(double delta) { timeDelta = delta; }

double PhysicsComponent::X() { return pos->getX(); }

double PhysicsComponent::Y() { return pos->getY(); }

double PhysicsComponent::prevX() { return prevPos->getX(); }

double PhysicsComponent::prevY() { return prevPos->getY(); }

int PhysicsComponent::Z() { return z; }

double PhysicsComponent::getAngle() { return angle; }

void PhysicsComponent::useFric(bool on) {useFriction = on;}

void PhysicsComponent::useGrav(bool on) {useGravity = on;}





