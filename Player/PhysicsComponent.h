/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PhysicsComponent.h
 * Author: sam
 *
 * Created on 6 February 2016, 9:58 AM
 */

#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "../GameObject/Vec2.h"


class RectHitbox;
class BasicPlatform;

class PhysicsComponent {
public:
    PhysicsComponent();
    PhysicsComponent(const PhysicsComponent& orig);
    virtual ~PhysicsComponent();
    
    void init();
    void update(double delta);
    
    double X();
    double Y();
    double prevX();
    double prevY();
    int    Z();
    double getAngle();
    void previousPos();
    
    void setForce(Vec2 frc);
    void setFrictionX(double fric);
    void setFrictionY(double fric);
    void setGravity(double grav);
    void setTimeDelta(double delta);

    void useFric(bool on);
    void useGrav(bool on);
    
    void addForce(Vec2 frc);
    void addForce(double x, double y);
    void addImpulse(Vec2 _impulse);
    
    void applyMove(Vec2 mvmnt, bool collCheck);
    void applyMoveTo(Vec2 _pos, bool collCheck);
    
    void correctPosY();

    void applyGravity();
    void applyFriction();
    Vec2 checkForce(Vec2 frc);
    void addImpulse();
    
    
    // HEAP
    RectHitbox* bodyHB;
    RectHitbox* underFeetHB;
    Vec2* pos;
    Vec2* prevPos;
    
    
    // STACK
    double timeDelta;
 
    int z;
    
    double angle;
    
    Vec2 movement;
    Vec2 impulse;
    Vec2 force;
    
    double frictionX;
    double frictionY;
    double gravity;
    
    bool useGravity;
    bool useFriction;
    
    const double maxRunSpeed = 20;
    
    const double maxForceX = 20000;
    const double maxForceYDown = 600;
    const double maxForceYUp = -400;

private:    
    
    

};

#endif /* PHYSICSCOMPONENT_H */

