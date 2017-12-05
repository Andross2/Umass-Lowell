//
//  Body.cpp
//  ps3b
//
//  Created by ChuongVu on 10/7/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//
//  Prof. Yelena Rykalova
//
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Body.hpp"


//default constructor
Body::Body() : xpos(0), ypos(0), xvel(0), yvel(0), mass(0)
{
}


//non-default constructor
Body::Body(int _windowSize, double _universeSize) : xpos(0), ypos(0), xvel(0), yvel(0), mass(0)
{
    windowSize = _windowSize;
    universeSize = _universeSize;
}

double Body::getxPos()
{
    return xpos;
}

double Body::getyPos()
{
    return ypos;
}

double Body::getMass()
{
    return mass;
}

void Body::updateXVel(double AxT)
{
    xvel -= AxT;
}

void Body::updateYVel(double AxT)
{
    yvel -= AxT;
}

void Body::step(double time)
{
    xpos = xpos - time * xvel;
    ypos = ypos - time * yvel;
}

//de-constructor
Body::~Body() {}

//set windows size
void Body::setWindowSize(int _size)
{
    windowSize = _size;
}

//set universe size
void Body::setUniverseSize(double _size)
{
    universeSize = _size;
}

//draw planets based on position
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite sprite_temp = sprite;
    double ratio = (windowSize / 2) / universeSize;
    double rxpos = xpos * ratio + (windowSize / 2);
    double rypos = ypos * ratio + (windowSize / 2);
    
    sprite_temp.setPosition(rxpos, rypos);
    
    target.draw(sprite_temp);
}

//Get position and file name from file
std::istream &operator>>(std::istream &input, Body &arg)
{
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

std::ostream &operator<<(std::ostream &output, Body &arg) {
    output << std::setw(14) << arg.xpos;
    output << std::setw(14) << arg.ypos;
    output << std::setw(14) << arg.xvel;
    output << std::setw(14) << arg.yvel;
    output << std::setw(14) << arg.mass;
    output << std::setw(14) << arg.fname;
    
    return output;
}
