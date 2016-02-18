/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deity.h
 * Author: sam
 *
 * Created on 16 February 2016, 2:23 PM
 */

#ifndef DEITY_H
#define DEITY_H

#include "../../Player/Player.h"

#define STAT player.statsComp

enum stat_choices {
    STAT_POWER,
    STAT_CONTROL,
    STAT_HEALTH,
    STAT_STAMINA,
    STAT_RESIST,
    STAT_NONE
};

extern Player player;
class Item;
class Perc;
class Graphic;

//  NORMONT,        // General Deity
//  MALLOC,         // VIOLENT - Damage - power control stamina
//  FRIIMA,         // FLYING - stamina power health
//  VIRVRA,         // POISON/Secondaries
//  WALABON,        // VAMPIRE  -Health/control
//  NO_DEITY,       // nothing
//  DEMON_DEITY,    // everythig is harder, gets harder as you level

class Deity {
public:
    Deity();
    Deity(const Deity& orig);
    virtual ~Deity();
    
    virtual void init();
    virtual void applyStartEffects();
    virtual void applyBribeEffects();
    virtual void applyPunishment();
    
    virtual void updateValues();
    
    virtual void storeFavour(int fav);
    
    virtual void levelStat(stat_choices stat);
    virtual Item* getItem();
    virtual Perc* getPerc();
    
    virtual void changeHappiness(int hap);

    void render();
    virtual void renderSpecifics();
    
    int storedFavour;
    
    int nextLevelCost;
    
    int nextItemCost;
    int numItemsTaken = 0;
    
    int nextPercCost;
    int numPercsTaken = 0;
    
    Graphic* graphic;
    
protected:
    
    int happiness;
    
    
    
    //std::vector<Item*> items;
    //std::vector<Perc*> percs;
    
    stat_choices statOptions[4];
    
    // Store dialogue information;
    

};

#endif /* DEITY_H */

