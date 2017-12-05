// Copyright Chuong Vu
// Filename: RingBuffer.cpp

#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include "RingBuffer.hpp"

// static_cast<int>
RingBuffer::RingBuffer(int capacity) {
    try {
        if (capacity < 1)
            throw std::invalid_argument("Capacity need bigger than zero");
    } catch(std::invalid_argument& invalid_arg) {
        // catch invalid_argument type.
        std::cerr << "RB constructor: Capacity need bigger than zero.\n";
        throw invalid_arg;
    }

    // researve capacity for buffer
    buffer.reserve(capacity);
    // initial value 0 for every element in buffer
    // so later on first and last just move around
    // the size of vector will stay the same
    for (int i = 0; i < capacity; i++)
        buffer.push_back(0);

    _first = 0;
    _last = 0;
    _size = 0;
    _capacity = capacity;
}

// return size of buffer
int RingBuffer::size() const {
    return _size;
}

// if _size >0 then RingBuffer is not empty
bool RingBuffer::isEmpty() const {
    return _size > 0 ? false : true;
}

// is the buffer full  (size equals capacity)?
bool RingBuffer::isFull() const {
  return _size == _capacity ? true : false;
}

// add item x to the end
void RingBuffer::enqueue(int16_t x) {
    try {
        if (isFull())
            throw std::runtime_error("Buffer is full");
    } catch(std::runtime_error& run_err) {
        // catch run time error type
        std::cerr << "Enqueue Error: Buffer is full\n";
        throw run_err;
    }

    // assgin value x to location _last
    buffer[_last] = x;

    // When either index equals capacity
    // make it wrap-around by changing the index to 0.
    if (_last == _capacity - 1)
        _last = 0;
    else
        _last++;

    // update _size
    _size++;
}

RingBuffer::~RingBuffer() {}

// delete and return item from the front
int16_t RingBuffer::dequeue() {
    try {
        if (isEmpty())
            throw std::runtime_error("Buffer is empty");
    } catch(std::runtime_error& run_err) {
        // catch run time error type
        std::cerr << "Dequeue Error: Buffer is empty\n";
        throw run_err;
    }

    // create temp variable = peek
    int16_t temp = peek();

    // move _first index
    if (_first == _capacity - 1)
        _first = 0;
    else
        _first++;

    // update _size
    _size--;

    return temp;
}

// return (but do not delete) item from the front
int16_t RingBuffer::peek() const {
    try {
        if (isEmpty())
        throw std::runtime_error("Buffer is empty");
    } catch(std::runtime_error& run_err) {
        // catch run time error type
        std::cerr << "Peek Error: Buffer is empty\n";
        throw run_err;
    }
    return buffer[_first];
}
