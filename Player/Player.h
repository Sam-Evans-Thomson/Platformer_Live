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

#include "../GameObject/Actor/Actor.h"



#define FACING_L 0
#define FACING_R 1

class GraphicsComponent;
class StateComponent;
class InputComponent;

class Player : public Actor {
public:
    Player(InputComponent* ic);
    Player(const Player& orig);
    ~Player();
    
    void init();
    
    
    // ACTIONS 
    void run(int dir);
    
    void jump();
    void dropThrough();
    void climb();
    void dodge();
    void activate();
    
    
    void melee1();
    void melee2();
    void range();
    void block();
    void useItem();
    
    void flap();
    
    //Change Items
    void changeMelee();
    void changeRange();
    void changeConsumable();
    
    
private:
    static StateComponent* stateComp;
    static GraphicsComponent* graphicsComp;
    
    int facing;
    
    
    
    
    // Game owns this.
    InputComponent* inputComp;
    
    
    
    
    
    // Platform* platform;
    // ClimbBox* climbBox;
    // GrabBox* grabBox;
    // TerrainBox* terrainBox;

};

#endif /* PLAYER_H */

