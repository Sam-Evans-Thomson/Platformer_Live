/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Walabon.h
 * Author: sam
 *
 * Created on 16 February 2016, 4:40 PM
 */

#ifndef WALABON_H
#define WALABON_H

#include "../Deity.h"

class Walabon : public Deity {
public:
    Walabon();
    Walabon(const Walabon& orig);
    virtual ~Walabon();
    
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

#endif /* WALABON_H */

