/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: sam
 *
 * Created on 2 February 2016, 2:19 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerConsts.h"
#include "StatsComp.h"


class InputComponent;
class GraphicsComponent;
class PhysicsComponent;

class PrimaryState;
class SecondaryState;
class RunningState;
class JumpingState;
class DodgeState;

class BasicPlatform;

class MeleeWeapon;


class Player {
public:
    Player();
    Player(const Player& orig);
    ~Player();
    
    void init();
    
    void handleInputs();
    void update(double time);
    void render();
    
    double getX();
    double getY();
    double getPrevX();
    double getPrevY();
    int getZ();

    /// HEAP
    PhysicsComponent* physicsComp;
    GraphicsComponent* graphicsComp;
    StatsComp* statsComp;
    
    
    /// STATES ///////////////////////////////
    
    
    /// 1ST STATE
    
    void changePrimaryState(PrimaryState* primeState);
    PrimaryState* primary;

    // HEAP
    PrimaryState*        running;
    PrimaryState*        jumping;
    DodgeState*          dodge;
//    DropAttackState     dropAttack;
//    StunState           stun;
//    ClimbingState       climbing;
//    GrabbingState       grabbing;
//    ActivateState       activate;
//    SwimmingState       swimming;
    
    
    ///2ND STATE
      
    void changeSecondaryState(SecondaryState* secondState); 
    SecondaryState* secondary;

    // HEAP
//    NullState           null;
//    EatingState         eating;
//    Melee1State         melee1;
//    Melee2State         melee2;
//    RangeState          range;
//    BlockState          block;
    
    
      
    //// OTHERS ///////////////////////////      
    int direction;
    int jumpCount; 
    int flapCount;
    double runRatio;
    
    ///// FLAGS ///////
    int fallFlag;
    int restrictedMovement;
    bool droppingThrough = false;
    
    ///// CURRENT PLATFORM ///////
    BasicPlatform* currPlatform;
    BasicPlatform* dropPlatform;
    
    ///// INVENTORY //////////////////////
    
    MeleeWeapon* meleeWeapon;
    
    ///// ACTIONS //////////////
    void move(int dir);
    void changePlatform(BasicPlatform* platform);
    
    void run(int dir);
    void stopRun();
    
    void hitWall(int dir);
    void hitRoof();
    
    void setJumpCount(int i);
    void setFlapCount(int i);
    
    void jumpFirst();
    void jump();
    
    void falling();
    
    void land(BasicPlatform* platform);
    void landStagger(double xDelta);
    
    void dropThrough();
    void climb();
    void performDodge();
    void activate();
    
    
    void melee1();
    void melee2();
    void range();
    void block();
    void useItem();
    
    void flap();
    
    void dies();
    
    //Change Items
    void changeMelee();
    void changeRange();
    void changeConsumable();

    
private:
    
    
};

#endif /* PLAYER_H */

