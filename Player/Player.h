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



#define JUMP_FORCE 28

#define FALL_DELTA_STAGGER 100

class GraphicsComponent;
class StateComponent;
class PhysicsComponent;
class PrimaryState;

class Player {
public:
    Player();
    Player(const Player& orig);
    ~Player();
    
    void init();
    
    void render();
    void update(double time);
    
        
    void changeState(PrimaryState* state);
    
    double getX();
    double getY();
    int getZ();

    // ACTIONS 
    
    void run(int dir);
    void stopRun();
    
    void jumpFirst();
    void jump(int i);
    void falling();
    
    void land(double xDelta);
    void landStagger(double xDelta);
    
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
    PhysicsComponent* physicsComp;
    

    
    // Platform* platform;
    // ClimbBox* climbBox;
    // GrabBox* grabBox;
    // TerrainBox* terrainBox;

};

#endif /* PLAYER_H */

