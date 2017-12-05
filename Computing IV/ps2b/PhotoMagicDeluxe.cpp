//
//  PhotoMagicDeluxe.cpp
//  ps2b
//
//  Created by ChuongVu on 9/28/16.
//  Copyright © 2016 ChuongVu. All rights reserved.
//  Using Xcode
//
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include "LFSR.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//Use to convert string to Binary 6N-bit string
std::string string_convert(std::string str)
{
    std::string temp;
    std::string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    for(int i = 0; i < str.size(); i++)
    {
        char c =  str.at(i);
        std::size_t check = base64.find(c);
        if(check==std::string::npos)
        {
            std::cout << "Cant find char" << c << "in base64";
            return 0;
        }
        std::bitset<6> b(check);
        //std::cout << b
        temp += b.to_string();
    }
    return temp;
}


int main(int argc, char* argv[])
{
    int pos = 200;
    
    if(argc < 5) {
        std::cout << "Not enough command-line arguments." << std::endl;
        return -1;
    }
    if(argc > 5) {
        std::cout << "Too many command-line arguments." << std::endl;
        return -1;
    }
    
    
    // Initialize LFSR with command-line arguments
    LFSR lfsr(std::string(string_convert(argv[3])), atoi(argv[4]));
    
    // Initialize images
    sf::Image image1;
    sf::Image image2;
    
    // Load inputted image
    if(!image1.loadFromFile(argv[1]))
        return -1;
    
    //output image
    if(!image2.loadFromFile(argv[1]))
        return -1;
    
    // p is a pixel
    sf::Color p;
    
    sf::Vector2u size = image2.getSize();
    
    // create photographic negative image of upper-left 200 px square
    //the biger of generate number, the slower of encoding picture is so I set it to 8
    for (unsigned int x = 0; x < size.x; x++) {
        for (unsigned int y = 0; y < size.y; y++) {
            p = image2.getPixel(x, y);
            p.r = (p.r ^ lfsr.generate(8));
            p.g = (p.g ^ lfsr.generate(8));
            p.b = (p.b ^ lfsr.generate(8));
            image2.setPixel(x, y, p);
        }
    }
    
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "Input");
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "Output");
    
    sf::Texture texture1;   //input
    sf::Texture texture2;   //ouput
    texture1.loadFromImage(image1);
    texture2.loadFromImage(image2);
    
    sf::Sprite sprite1;     //input
    sf::Sprite sprite2;     //output
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    
    while (window1.isOpen() && window2.isOpen())
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        
        window1.clear(sf::Color::White);
        window1.setPosition(sf::Vector2i(pos,size.y));
        window1.draw(sprite1);
        window1.display();
        
        window2.clear(sf::Color::White);
        window2.setPosition(sf::Vector2i(pos + size.x,size.y));
        window2.draw(sprite2);
        window2.display();
    }
    
    // fredm: saving a PNG segfaults for me, though it does properly
    //   write the file
    if(!image2.saveToFile(argv[2]))
        return -1;
    
    return 0;
}
