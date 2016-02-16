/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SlopePlatform.h
 * Author: sam
 *
 * Created on 14 February 2016, 10:46 AM
 */

#ifndef SLOPEPLATFORM_H
#define SLOPEPLATFORM_H

#include "BasicPlatform.h"

class SlopePlatform : public BasicPlatform {
public:
    SlopePlatform(Vec2 _pos, int _z, double _w, double _h, double _ratio);
    SlopePlatform(double x, double y, int _z, double _w, double _h, double _ratio);
    SlopePlatform(const SlopePlatform& orig);
    virtual ~SlopePlatform();

    void setGraphicDimensions(double x, double y, double _w, double _h) override;
    void render() override;

    
    double getYatX(double x) override;
    double getRatio() override;
    
    void init() override;
    
private:

    double ratio;
};

#endif /* SLOPEPLATFORM_H */

