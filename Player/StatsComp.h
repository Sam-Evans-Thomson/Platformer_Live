/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatsComp.h
 * Author: sam
 *
 * Created on 12 February 2016, 3:56 PM
 */

#ifndef STATSCOMP_H
#define STATSCOMP_H

#include "../Utilities/Timer.h"
#include <math.h>

//#define STATS_PATH "statsPath.txt"
#define STAMINA_DELAY 1
#define POWER_DAMAGE_FACTOR 1.0
#define POWER_FLAP_FACTOR 0.5
#define CONTROL_DEFENSE_FACTOR 1.0

#define CONTROL_DAMAGE_FACTOR 1.0

class Deity;
     


class StatsComp {
public:
    StatsComp();
    StatsComp(const StatsComp& orig);
    virtual ~StatsComp();
    
    void init();
    void loadStats();
    void refresh();
    
    void update();
    void updateLevelStats();
    
    void incPower(int i);
    void incControl(int i);
    
    bool useStamina(float i);
    
    bool takeDamage(float i);
    bool takePhysDamage(float i);
    bool takePoisonDamage(float i);
    bool takeCurseDamage(float i);
    bool takeStaggerDamage(float i);
    
    void healFood(float i);
    void heal(int i);
    
    void gainFavour(int i);
    
    
    
    /// values
    float stamina;
    float staminaMax;
    float staminaRegen;
    Timer* staminaTimer;
    
    float health;
    float healthMax;
    float healthRegen;
    float healthFoodMult;
    float healthOnHit;
    bool foodPoisons;
    
    float poison;             // poison build up
    float poisonRes;          // resistance to buildup
    float poisonMax;          // poisoned when poison exceeds this.
    bool isPoisoned;
    
    float curse;              // curse build up
    float curseRes;           // resistance to buildup
    float curseMax;           // cursed when curse exceeds this.
    bool isCursed;
    
    float stagger;            // stagger buildup    
    float staggerRes;         // resistance to stagger
    float staggerMax;         // staggered when stagger exceeds this.
    
    float defenseBase;        // defense based on level and stats.
    float defense;            // defense with equipment factored.

    float damageBasePower;    // damage based on Power.
    float damageBaseControl;  // damage based on Control;
    
    float damagePoison;
    
    float distanceRange;      // How far range attacks go.

    float flapPower;          // Force of flapping;
    float flapMult;
    
    
    
    /// stats
    int level;
    float expMult;
    
    /* POWER:   Power weapons do more damage.
     *          Range attacks go further.
     *          Wing flaps are more powerful.
     * 
     * CONTROL  Everything uses less stamina.
     *          Range Attacks do more damage.
     *          
     */
    int power;
    int control;
    
    int favour;
    int wealth;
    
    int lastCamp;
    int currCamp;
    
    Deity* alignment;
    
    
private:

};

#endif /* STATSCOMP_H */

