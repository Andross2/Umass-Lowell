// Copyright Chuong Vu
// Filename: GuitarHero.cpp
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>
#include <stdint.h>
#include <sstream>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<int16_t> makeSamplesFromString(GuitarString gs) {
    std::vector<int16_t> samples;

    gs.pluck();
    int duration = 8;  // seconds
    int i;
    for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
        gs.tic();
        samples.push_back(gs.sample());
    }

    return samples;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(450, 100), "SFML Guitar Hero Lite");
    sf::Event event;

    double freq;
    // keyboard layout
    std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
    std::string str;
    std::stringstream ss;
    std::vector<std::string> frequency;

    std::vector<std::vector<int16_t> > samples(37);
    std::vector<sf::Sound> sounds(37);
    std::vector<sf::SoundBuffer> soundBuffers(37);

    // calculate and store frequency to the sound vector
    for (int i = 0; i < 37; i++) {
        freq = (CONCERT_A * 2) * pow(2, (i - 24) / 12.0);

        str = "";
        ss << ceil(freq * 100) / 100;
        str = ss.str();
        str.erase(str.begin()+6, str.end());
        str = str + " Hz";
        frequency.push_back(str);
        ss.clear();

        GuitarString gs(freq);
        samples[i] = makeSamplesFromString(gs);

        if (!soundBuffers[i].loadFromSamples(&samples[i][0], samples[i].size(),
            2, SAMPLES_PER_SEC))
     throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");

        sounds[i].setBuffer(soundBuffers[i]);
    }

    sf::Font font;
    font.loadFromFile("cour.ttf");
    sf::Text text1("Guitar Frequency:", font, 24);
    sf::Text text("", font, 24);
    text.setStyle(sf::Text::Bold);
    text.setPosition(240, 2);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode < 128) {
                    std::string keypress;
                    keypress += static_cast<char>(event.text.unicode);
                    std::cout << "Playing sound associated with " << keypress;
                    std::cout << std::endl;
                    int index = keyboard.find(keypress);
                    sounds[index].play();
                    std::cout << "frequency: " << frequency[index] << std::endl;
                    text.setString(frequency[index]);
                    window.draw(text);
                }
                break;
            default:
                break;
            }

            window.clear();
            window.draw(text1);
            window.draw(text);
            window.display();
        }
    }

    return 0;
}
