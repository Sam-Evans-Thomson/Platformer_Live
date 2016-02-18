/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MeleeAttack.h
 * Author: sam
 *
 * Created on 17 February 2016, 2:29 PM
 */

#ifndef MELEEATTACK_H
#define MELEEATTACK_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>


class Graphic;
class RectHitbox;
class Actor;
class StatsComp;

class MeleeAttack {
public:
    MeleeAttack();
    MeleeAttack(const MeleeAttack& orig);
    virtual ~MeleeAttack();
    
    void init();
    void loadAttack(std::string path);
    
    RectHitbox* getHitbox(double _time);
    
    void applyHit(StatsComp* holder,StatsComp* target);
    
    void render();
    
    Graphic* graphic;
    RectHitbox* hb;
    
    std::vector<int> effectID;
    std::vector<float> effectAmount;
    
    float attackStartX;
    float attackStartY;
    float attackPathX;
    float attackPathY;
    bool  attackPathCurve;

    float stagger;
    float stamina;
    float damage;
    float time;
    
    float timeHBStart;
    float timeHBEnd;
    
private:
    
    
};

#endif /* MELEEATTACK_H */

