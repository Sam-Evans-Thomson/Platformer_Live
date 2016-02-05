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

#include "../GameObject/GameObject.h"

#define FACING_L 0
#define FACING_R 1

class GraphicsComponent;
class StateComponent;
class Canvas;

class Player : public GameObject {
public:
    Player();
    Player(const Player& orig);
    ~Player();
    
    void init();
    
    void render(Canvas* canvas);
    
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
    StateComponent* stateComp;
    GraphicsComponent* graphicsComp;
    
    int facing;

    
    // Platform* platform;
    // ClimbBox* climbBox;
    // GrabBox* grabBox;
    // TerrainBox* terrainBox;

};

#endif /* PLAYER_H */

