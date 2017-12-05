// Copyright Chuong Vu
// Filename: GuitarString.cpp
#include <iostream>
#include <stdint.h>  //NOLINT
#include <vector>
#include <cmath>    // for ceil function which use for rounding integer number
#include <cstdlib>
#include "GuitarString.hpp"
#include "RingBuffer.hpp"

// create a guitar string of the given frequency
// using a sampling rate of 44,100
GuitarString::GuitarString(double frequency) : buffer(ceil(44100/frequency)) {
    // std::cout << ceil(44100/frequency) << std::endl;
    count = 0;
}

// create a guitar string with
// size and initial values are given by the vector
GuitarString::GuitarString(std::vector<int16_t> init) : buffer(init.size()) {
    for (size_t i = 0; i < init.size(); i++) {
        buffer.enqueue(init[i]);
    }
    count = 0;
}

// pluck the guitar string by replacing the buffer
// with random values, representing white noise
void GuitarString::pluck() {
    // epmpy the buffer for replacing value
    buffer.emptyBuffer();

    // check if the buffer is not full for make sure before enqueue
    while (!buffer.isFull()) {
        buffer.enqueue((int16_t)(rand()) & 0xFFFF);  //NOLINT
    }
}

// advance the simulation one time step
void GuitarString::tic() {
    int n1 = buffer.dequeue();
    int n2 = buffer.peek();
    // std::cout << n2 << std::endl;
    buffer.enqueue(0.5 * 0.996 * (n1 + n2));
    count++;
}

// return the current sample
int16_t GuitarString::sample() const {
    return buffer.peek();
}

// return number of times tic was called so far
int GuitarString::time() const {
    return count;
}
