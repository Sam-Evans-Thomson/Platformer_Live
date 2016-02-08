/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vec2.cpp
 * Author: sam
 * 
 * Created on 3 February 2016, 10:28 AM
 */

#include <stdlib.h>
#include "Vec2.h"
#include <iostream>
#include <math.h>

Vec2::Vec2() {
    x = 0.0;
    y = 0.0;
}

Vec2::Vec2(const Vec2& orig) {
    x = orig.x;
    y = orig.y;
}

Vec2::~Vec2() {
    
}

Vec2::Vec2(double x, double y) : x(x), y(y) {}

Vec2::Vec2(float x, float y) : x(double(x)), y(double(y)) {}

Vec2::Vec2(int x, int y) : x(double(x)), y(double(y)) {}

Vec2::Vec2(double angle, double magnitude, bool b) {
    x = magnitude*cos(angle);
    y = magnitude*sin(angle);
}

//
//  --- Getters and Setters ---
//

void Vec2::setX(double _x) { x=_x; }

void Vec2::setY(double _y) { y=_y; }

double Vec2::getX() { return x; }

double Vec2::getY() { return y; }

//
//  --- Modifying Arithmetic Operators ---
//

Vec2 Vec2::operator- () const {
    double _x = -x; double _y = -y; return Vec2( _x, _y);
}

Vec2 Vec2::operator+( const Vec2& v ) {
    double _x = x+v.x; double _y = y+v.y; return Vec2( _x, _y);
}

Vec2 Vec2::operator-( const Vec2& v ) {
    double _x = x-v.x; double _y = y-v.y; return Vec2( _x, _y);
}

Vec2 Vec2::operator*(const Vec2& v) {
    double _x = x*v.x; double _y = y*v.y; return Vec2( _x, _y);
}

Vec2 Vec2::operator*(const double d) {
    double _x = x*d; double _y = y*d; return Vec2( _x, _y);
}

Vec2 Vec2::operator/(const Vec2& v) {
    double _x = x/v.x; double _y = y/v.y; return Vec2( _x, _y);
}

Vec2 Vec2::operator/(const double d) {
    double _x = x/d; double _y = y/d; return Vec2( _x, _y);
}

Vec2& Vec2::operator+=( const Vec2& v ) {
    x+=v.x; y+=v.y; return *this;
}

Vec2& Vec2::operator-=( const Vec2& v ) {
    x-=v.x; y-=v.y; return *this;
}

Vec2& Vec2::operator*=( const Vec2& v ) {
    x*=v.x; y*=v.y; return *this;
}

Vec2& Vec2::operator/=( const Vec2& v ) {
    x/=v.x; y/=v.y; return *this;
}

Vec2& Vec2::operator*=( const double d ) {
    x*=d; y*=d; return *this;
}

Vec2& Vec2::operator/=( const double d ) {
    x/=d; y/=d; return *this;
}

//
//  --- Functions on this Vec2 ---
//

double Vec2::length() {
    return sqrt(x*x + y*y);
}

double Vec2::angle() {
    if(x==0 && y==0) return 0.0;
    else return atan2(y,x);
}

Vec2 Vec2::normalize() {
    double len = length();
    double _x = x/len;
    double _y = y/len;
    return Vec2(_x,_y);
}

Vec2 Vec2:: invert() {
    return Vec2(y,x);
}

Vec2 Vec2::rotate(double angle) {
    double ca = cos(angle);
    double sa = sin(angle);
    double _x = x*ca - y*sa;
    double _y = x*sa + y*ca;
    return Vec2(_x,_y);
}

//
//  --- Functions on two Vec2s ---
//

double Vec2::dot(const Vec2& v) const{
    return x*v.x + y*v.y;
}

double Vec2::length(const Vec2& v) const{
    double _x = v.x-x;
    double _y = v.y-y;
    return sqrt(_x*_x + _y*_y);
}

double Vec2::angle(const Vec2& v) const{
    double _x = v.x - x;
    double _y = v.y - y;
    if(_x==0 && _y==0) return 0.0;
    else return atan2(_y,_x);
}

Vec2 Vec2::rotate(double angle, const Vec2& v) const{
    double _x = x - v.x;
    double _y = y - v.y;
    Vec2 vec = Vec2(_x,_y);
    vec = vec.rotate(angle);
    return vec+v;
}

Vec2 Vec2::changeReference(double angle, const Vec2& v) const {
    Vec2 thisVec = Vec2(x,y);
    double mag = length(v);
    double ang = v.angle(thisVec) - angle;
    return Vec2(ang, mag, 1);
}


