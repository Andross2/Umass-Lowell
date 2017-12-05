//-------------------------------
//Name: Chuong Vu
//Assigment 5a
//Class: Computing IV
//Professor: Dr. Yelena Rykalova
//Filename: RB.cpp
//-------------------------------

#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include "RB.hpp"

//static_cast<int>
RB::RB(int capacity) {
	try {
		if (capacity < 1)
			throw std::invalid_argument("Capacity must be greater than zero");
	} catch(std::invalid_argument& ia) {	//ia is invalid_argument type
		std::cerr << "RB constructor: capacity must be greater than zero.";
		std::cerr << std::endl;
		throw ia;
	}

	//researve capacity for buffer
	buffer.reserve(capacity);

	//initial value 0 for every element in buffer

	// for (int i = 0; i < capacity; i++)
		// buffer.push_back(0);

	_first = 0;
	_last = 0;
	_size = 0;
	_capacity = capacity;
}

//return size of buffer
int RB::size() const {
	return _size;
}

//if _size >0 then RB is not empty
bool RB::isEmpty() const {
	return _size > 0 ? false : true;
}

// is the buffer full  (size equals capacity)?
bool RB::isFull() const {
  return _size == _capacity ? true : false;
}

//add item x to the end
void RB::enqueue(int16_t x) {
	try {
		if (isFull())
			throw std::runtime_error("Buffer is full");
	} catch(std::runtime_error& re) {	//re is runtime_error type
		std::cerr << "Enqueue Error: Buffer is full" << std::endl;
		throw re;
	}
	
	//assgin value x to location _last
	buffer.push_back(0);
	buffer[_last] = x;

	//When either index equals capacity, make it wrap-around by changing the index to 0.
	if (_last == _capacity - 1)
		_last = 0;
	else
		_last++;

	//update _size
	_size++;
}

RB::~RB(){
	
}

// delete and return item from the front
int16_t RB::dequeue() {
	try {
		if (isEmpty())
			throw std::runtime_error("Buffer is empty");
	} catch(std::runtime_error& re) { //re is runtime_error type
		std::cerr << "Dequeue Error: Buffer is empty" << std::endl;
		throw re;
	}

	//create temp variable = peek
	int16_t temp = peek();

	//move _first index
	if (_first == _capacity - 1)
		_first = 0;
	else
		_first++;

	//update _size
	_size--;

	return temp;
}

// return (but do not delete) item from the front
int16_t RB::peek() const {
	try {
		if (isEmpty())
		throw std::runtime_error("Buffer is empty");
	} catch(std::runtime_error& re) {	//re is runtime_error type
		std::cerr << "Peek Error: Buffer is empty" << std::endl;
		throw re;
	}
	return buffer[_first];
}
