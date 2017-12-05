//
//  Body.hpp
//  ps3a
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
    Body(double _xpos, double _ypos, double _xvel, double _yvel, double _mass, std::string _fname);
    ~Body();
    void setWindowSize(int _size);
    void setUniverseSize(double _size);
    friend std::istream &operator>>(std::istream &input, Body &arg);

private:
    double xpos, ypos, xvel, yvel, mass, universeSize;
    int windowSize;
    sf::Sprite sprite;
    sf::Texture texture;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
};

#endif /* Body_hpp */
