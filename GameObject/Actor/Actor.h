/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Actor.h
 * Author: sam
 *
 * Created on 3 February 2016, 10:33 AM
 */

#ifndef ACTOR_H
#define ACTOR_H

#include "../GameObject.h"

class StatsComp;

class Actor : public GameObject {
public:
    Actor();
    Actor(const Actor& orig);
    virtual ~Actor();
    
    StatsComp* statsComp;
    
private:

};

#endif /* ACTOR_H */

