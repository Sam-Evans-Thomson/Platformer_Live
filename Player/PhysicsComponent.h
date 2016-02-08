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

#include "../GameObject/Hitboxes/CircleHitbox.h"

#define BASE_GRAVITY 25
#define BASE_FRICTION 1
#define MAX_X_FORCE 500
#define MAX_Y_FORCE 1500

class PhysicsComponent {
public:
    PhysicsComponent();
    PhysicsComponent(const PhysicsComponent& orig);
    virtual ~PhysicsComponent();
    
    void init();
    void update(double delta);
    
    double X();
    double Y();
    int    Z();
    double getAngle();

    void setForce(Vec2 frc);
    void setFriction(double fric);
    void setGravity(double grav);
    void setTimeDelta(double delta);
    
    void useFric(bool on);
    void useGrav(bool on);
    
    void addForce(Vec2 frc);
    void addForce(double x, double y);
    void addImpulse(Vec2 _impulse);
    
    RectHitbox* bodyHB;
    
private:
    
    double timeDelta;
 
    Vec2* pos;
    Vec2* prevPos;
    int z;
    
    double angle;
    
    Vec2 movement;
    Vec2 impulse;
    Vec2 force;
    
    double friction;
    double gravity;
    
    bool useGravity;
    bool useFriction;
    
    const double maxRunSpeed = 20;
    
    const double maxForceX = 20000;
    const double maxForceY = 600;
    
    void applyMove(Vec2 mvmnt);
    void resolveCollisions();
    void resolveCollision(RectHitbox* hitbox);
    void applyGravity();
    void applyFriction();
    Vec2 checkForce(Vec2 frc);
    void addImpulse();
};

#endif /* PHYSICSCOMPONENT_H */

