// Copyright Chuong Vu
// GuitarString.hpp

#ifndef _GUITARSSTRING_HPP
#define _GUITARSSTRING_HPP

#include <stdint.h>
#include <vector>
#include "RingBuffer.hpp"

class GuitarString {
 private:
    // create ringbuffer
    RingBuffer buffer;

    // for counting
    int count;

 public:
    // create a guitar string of the given frequency
    // using a sampling rate of 44,100
    explicit GuitarString(double frequency);

    // create a guitar string with
    // size and initial values are given by the vector
    explicit GuitarString(std::vector<int16_t> init);

    // pluck the guitar string by replacing the buffer
    // with random values, representing white noise
    void pluck();

    // advance the simulation one time step
    void tic();

    // return the current sample
    int16_t sample() const;

    // return number of times tic was called so far
    int time() const;
};


#endif
