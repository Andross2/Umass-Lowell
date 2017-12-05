//-------------------------------
//Name: Chuong Vu
//Assigment 1, ps1 - Draw Squres
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Due Date: 9/18/2016
//Filename: original.cpp
//-------------------------------

// Simmlar to Sierpinski's Triangle, this draw square

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "original.hpp"

using namespace std;

int main(int argc, char*argv[]) {
    if(argc<3){
        cout << "sierpinski [recursion-depth] [side-length]" << endl;
        return -1;
    }
    
    int depth = atoi(argv[1]);
    int side = atoi(argv[2]);
    
    Original s(side, depth);
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(side, side), "Squares - Chuong Vu", sf::Style::Default, settings);
    window.setFramerateLimit(1);
    
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
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
