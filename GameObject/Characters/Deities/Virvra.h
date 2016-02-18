/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virvra.h
 * Author: sam
 *
 * Created on 16 February 2016, 4:29 PM
 */

#ifndef VIRVRA_H
#define VIRVRA_H

#include "../Deity.h"

class Virvra : public Deity {
public:
    Virvra();
    Virvra(const Virvra& orig);
    virtual ~Virvra();
    
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

#endif /* VIRVRA_H */

