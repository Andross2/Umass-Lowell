//
//  Body.cpp
//  ps3a
//
//  Created by ChuongVu on 10/7/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//
//  Prof. Yelena Rykalova
//
#include <iostream>
#include <sstream>
#include "Body.hpp"


//default constructor
Body::Body() : xpos(0), ypos(0), xvel(0), yvel(0), mass(0){
}


//non-default constructor
Body::Body(double _xpos, double _ypos, double _xvel, double _yvel, double _mass, std::string _fname) : xpos(_xpos), ypos(_ypos), xvel(_xvel), yvel(_yvel), mass(_mass) {
    texture.loadFromFile(_fname);
    sprite.setTexture(texture);
}


//de-constructor
Body::~Body() {}


//set windows size
void Body::setWindowSize(int _size) {
    windowSize = _size;
}

//set universe size
void Body::setUniverseSize(double _size) {
    universeSize = _size;
}

//draw planets based on position
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::Sprite sprite_temp = sprite;
    double ratio = (windowSize / 2) / universeSize;
    double rxpos = xpos * ratio + (windowSize / 2);
    double rypos = ypos * ratio + (windowSize / 2);
    
    sprite_temp.setPosition(rxpos, rypos);
    
    target.draw(sprite_temp);
}

//Get position and file name from file
std::istream &operator>>(std::istream &input, Body &arg) {
    std::string fname;
    input >> arg.xpos;
    input >> arg.ypos;
    input >> arg.xvel;
    input >> arg.yvel;
    input >> arg.mass;
    input >> fname;
    arg.texture.loadFromFile(fname);
    arg.sprite.setTexture(arg.texture);
    
    return input;
}
