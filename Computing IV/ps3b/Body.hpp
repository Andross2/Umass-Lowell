//
//  Body.hpp
//  ps3b
//
//  Created by ChuongVu on 10/7/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//  Xcode
//  Prof. Yelena Rykalova

#ifndef Body_hpp
#define Body_hpp

#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable {

public:
    Body();
    Body(int _windowSize, double _universeSize);
    ~Body();
    void setWindowSize(int _size);
    void setUniverseSize(double _size);
    friend std::istream &operator>>(std::istream &input, Body &arg);
    friend std::ostream &operator<<(std::ostream &output, Body &arg);
    double getxPos();
    double getyPos();
    double getMass();
    void updateXVel(double AxT);
    void updateYVel(double AxT);
    void step(double time);
    
private:
    double xpos, ypos, xvel, yvel, mass, universeSize;
    int windowSize;
    sf::Sprite sprite;
    sf::Texture texture;
    std::string fname;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* Body_hpp */
