//-------------------------------
//Name: Chuong Vu
//Assigment 1, ps1 - Sierpinski's Triangle
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Due Date: 9/18/2016
//Filename: main.cpp
//-------------------------------

// This program use recursive graphics to draw a Sierpinski's Triangle


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "sierpinski.hpp"

using namespace std;

int main(int argc, char*argv[])
{
    if(argc<3)
    {
        cout << "sierpinski [recursion-depth] [side-length]" << endl;
        return -1;
    }
    
    //store the dide and how many time recurisve triangle call
    int depth = atoi(argv[1]);
    int side = atoi(argv[2]);
    
    Sierpinski s(side, depth);
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(side,(int)(.5*sqrt(3.)*(float)side)), "Sierpinski triangle - Chuong Vu", sf::Style::Default, settings);
    window.setFramerateLimit(1);
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

        }
        window.clear(sf::Color::White);
        window.draw(s);
        window.display();
    }
    return 0;
}
