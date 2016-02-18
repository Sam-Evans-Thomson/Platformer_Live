/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Item.h
 * Author: sam
 *
 * Created on 17 February 2016, 9:22 AM
 */

#ifndef ITEM_H
#define ITEM_H

class Graphic;

class Item {
public:
    Item();
    Item(const Item& orig);
    virtual ~Item();
    
    Graphic* menuGraphic;
    
    // Description
private:

};

#endif /* ITEM_H */

