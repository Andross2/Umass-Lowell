// Copyright Chuong Vu

#ifndef _RingBuffer_HPP
#define _RingBuffer_HPP
#include <stdint.h>
#include <vector>

class RingBuffer {
 public:
    explicit RingBuffer(int capacity);
    ~RingBuffer();
    // add item x to the end
    void enqueue(int16_t x);
    // delete and return item from the front
    int16_t dequeue();
    // return (but do not delete) item from the front
    int16_t peek() const;
    // return number of items currently in the buffer
    int size() const;
    // check empty
    bool isEmpty() const;
    // is the buffer full  (size equals capacity)?
    bool isFull() const;
    // empty buffer
    void emptyBuffer();

 private:
    std::vector<int16_t> buffer;
    // keep track number of items currently in buffer
    int _size;
    // capacity
    int _capacity;
    // first index
    int _first;
    // last index
    int _last;
};

#endif
