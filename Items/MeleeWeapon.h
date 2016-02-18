/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MeleeWeapon.h
 * Author: sam
 *
 * Created on 17 February 2016, 1:22 PM
 */

#ifndef MELEEWEAPON_H
#define MELEEWEAPON_H

#include "MeleeAttack.h"
#include "../Utilities/Timer.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define STAT player.statsComp

class Actor;

enum attack_state {
    ATTACK_NONE,
    ATTACK_WEAK,
    ATTACK_STRONG,
    ATTACK_DROP
};

enum weapon_type {
    W_FIST,
    W_DAGGER,
    W_SWORD,
    W_CLUB,
    W_AXE,
    W_STAFF
};

class MeleeWeapon {
public:
    MeleeWeapon();
    MeleeWeapon(const MeleeWeapon& orig);
    virtual ~MeleeWeapon();
    
    void init();
    void loadWeapon(std::string path);
    
    void update();
    void updateValues();
    void render();

    void attackWeak(Actor* target);
    void attackStrong(Actor* target);
    void attackDrop(Actor* target);
    void applyHit(StatsComp* target);
    
    // This is in charge of working out where the hitbox 
    // is in the attack animation.
    RectHitbox* getHitbox();
    
    void applyStats();  // Change stats when equipping weapon.
    void removeStats(); // Undo change when equipping weapon.
    
    // This is the current Graphic. it is one of the four states.
    Graphic* graphic;
    MeleeAttack* attack;
    
    attack_state attackState;
    weapon_type weaponType;
    
    Actor* holder;
    
    float damage;
    
    float powerScale;
    float controlScale;
    
    MeleeAttack* attack_Strong;
    MeleeAttack* attack_Weak;
    MeleeAttack* attack_Drop;
private:
    
    std::vector<int> effectID;
    std::vector<float> effectAmount;
    
    Timer timer;

    Graphic* carrying;
    
    std::string weaponName;
  
};

#endif /* MELEEWEAPON_H */

