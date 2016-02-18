/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ResourceManager.h
 * Author: sam
 *
 * Created on 11 February 2016, 3:31 PM
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#define NUM_BACKGROUND_X 10
#define NUM_BACKGROUND_Y 10

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Items/ItemEffects.h"

class Graphic;
class MeleeWeapon;
class MeleeAttack;


class ResourceManager {
public:
    ResourceManager();
    ResourceManager(const ResourceManager& orig);
    virtual ~ResourceManager();
    
    void init();
    void initGraphics();
    void initSounds();
    void initAttacks();
    void initWeapons();
    
    
    /******************************* GRAPHICS *********************************/
    
    Graphic* background;
    std::vector<Graphic*> platforms;
    std::vector<Graphic*> decorations;
    Graphic* running;
    Graphic* dodge;
    
    Graphic* column;
    Graphic* stamina;
    Graphic* health;
    
    Graphic* stair;
    
    std::vector<Graphic*> meleeCarryGraphic;
    std::vector<Graphic*> meleeAttackGraphic;
    
    std::vector<Graphic*> rangeCarryGraphic;
    std::vector<Graphic*> rangeAttackGraphic;
    
    /**************************************************************************/
    
    std::vector<MeleeWeapon*> meleeWeapons;
    std::vector<MeleeAttack*> meleeAttacks;
    
    ItemEffects itemEffects;
    
private:

    
};

#endif /* RESOURCEMANAGER_H */

