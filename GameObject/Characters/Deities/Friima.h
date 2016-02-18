/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Friima.h
 * Author: sam
 *
 * Created on 16 February 2016, 4:11 PM
 */

#ifndef FRIIMA_H
#define FRIIMA_H

#include "../Deity.h"

class Friima : public Deity {
public:
    Friima();
    Friima(const Friima& orig);
    virtual ~Friima();
    
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

#endif /* FRIIMA_H */

