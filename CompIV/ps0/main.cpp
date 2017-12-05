//-------------------------------
//Name: Chuong Vu
//Assigment 0, ps0
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Due Date: 9/12/2016
//-------------------------------

// This program is a simple movement of SFML. Use key Up, Down, Left, Right to move
// Son Goku flying sprite. Also, a Blue Dot will random moving inside the red wall.
// No object can pass through the wall.

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//Return random number from [-9, 9]
int getRandom() {
    return std::rand() % 19 + (-9);
}

int main(int argc, char ** argv) {
    int x, y, z, bx, by;
    x = 0;
    y = 0;
    z = 0;
    
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;
    
    sf::RenderWindow window(sf::VideoMode(300, 300),"HW0 - Chuong Vu", sf::Style::Default, settings);
    window.setFramerateLimit(30);
    
    //creta red box
    sf::VertexArray lines(sf::LinesStrip, 5);
    lines[0].position = sf::Vector2f(10, 10);
    lines[0].color = sf::Color::Red;
    lines[1].position = sf::Vector2f(10, 290);
    lines[1].color = sf::Color::Red;
    lines[2].position = sf::Vector2f(290, 290);
    lines[2].color = sf::Color::Red;
    lines[3].position = sf::Vector2f(290, 10);
    lines[3].color = sf::Color::Red;
    lines[4].position = sf::Vector2f(10, 10);
    lines[4].color = sf::Color::Red;
    
    // Declare and load a texture
    sf::Texture texture;
    if(!texture.loadFromFile("./sprite.png")) {
        std::cout << "Error Loading Image!";
        return -1;
    }
    texture.setSmooth(true);
    
    // Create a sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(325, 50, 20, 35));
    sprite.setPosition(100,100);
    
    // Create a blue dot
    sf::CircleShape circle;
    circle.setRadius(10);
    circle.setPosition(30,30);
    circle.setFillColor(sf::Color::Blue);
    

    // It seem like the grader can't complie this music play code.
    // I tried complie this with Xcode and it works fine
    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile("./500.ogg")) {
//        return EXIT_FAILURE;
//    }
//    music.setVolume(20);
//    music.play();
    
    bool play = true;
    bool ball = true;
    
    
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
        }
        
        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up)) {
            sprite.setTextureRect(sf::IntRect(325, 50, 20, 35));
            //sprite.move(0, -5);
            sprite.getPosition().y < 25 ? sprite.move(0, 0) : sprite.move(0, -5);
        }
        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down)) {
            sprite.setTextureRect(sf::IntRect(245, 40, 25, 35));
            //sprite.move(0, 5);
            sprite.getPosition().y > 225 ? sprite.move(0, 0) : sprite.move(0, 5);
        }
        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left)) {
            sprite.setTextureRect(sf::IntRect(265, 50, 45, 25));
            sprite.setScale(1.0f,1.0f);
            //sprite.move(-5, 0);
            sprite.getPosition().x < 25 ? sprite.move(0, 0) : sprite.move(-5, 0);
        }
        if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right)) {
            sprite.setTextureRect(sf::IntRect(265, 50, 45, 25));
            sprite.setScale(-1.0f,1.0f);
            // sprite.move(5, 0);
            sprite.getPosition().x > 255 ? sprite.move(0, 0) : sprite.move(5, 0);
        }
        
        if(play) {
            for( int j = 0; j < 50; j++) {
                x++;
                y += 2;
                z += 3;
                (x > 255) ? x = 0 : x;
                (y > 255) ? x = 0 : y;
                (z > 255) ? x = 0 : z;
                lines[0].color = sf::Color(x , y , z);
                lines[1].color = sf::Color(x , y , z);
                lines[2].color = sf::Color(x , y , z);
                lines[3].color = sf::Color(x , y , z);
                lines[4].color = sf::Color(x , y , z);
            }
        }
        
        //moving ball
        if(ball) {
            bx = getRandom();
            by = getRandom();
            
            if(circle.getPosition().x < 20) {
                circle.move(20, 0);
            }
            else if(circle.getPosition().x > 250) {
                circle.move(-20, 0);
            }
            else if(circle.getPosition().y < 20) {
                circle.move(0, 20);
            }
            else if(circle.getPosition().y > 250) {
                circle.move(0, -20);
            }
            else{
                circle.move(bx, by);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::White);
        
        //window.draw(circle);
        //window.draw(line, 5, sf::LinesStrip);
        window.draw(sprite);
        window.draw(lines);
        window.draw(circle);
        
        // end the current frame
        window.display();
    }
    
    return EXIT_SUCCESS;
}
