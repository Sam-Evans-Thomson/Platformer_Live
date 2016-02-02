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

#include "StateComponent.h"

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
private:
    static StateComponent* stateComp;

};

#endif /* PLAYER_H */

