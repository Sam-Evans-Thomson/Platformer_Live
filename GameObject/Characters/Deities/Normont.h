/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Normont.h
 * Author: sam
 *
 * Created on 16 February 2016, 3:10 PM
 */

#ifndef NORMONT_H
#define NORMONT_H

#include "../Deity.h"

class Normont : public Deity {
public:
    Normont();
    Normont(const Normont& orig);
    virtual ~Normont();
    
    void init() override;
    void applyStartEffects() override;
    void applyBribeEffects() override;
    void applyPunishment() override;
    
    void updateValues() override;
    
    Item* getItem() override;
    Perc* getPerc() override;
    
    void levelStat(stat_choices stat) override;
    
    void renderSpecifics() override;
    

private:

};

#endif /* NORMONT_H */

