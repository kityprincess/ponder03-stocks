//
//  queue.h
//  queue
//
//  Created by Bryan Lopez on 4/29/17.
//  Copyright © 2017 Lopez Bryan. All rights reserved.
//
/***********************************************************************
 * Header:
 *    Queue
 * Summary:
 *    This class contains the notion of a queue.
 *
 *    This will contain the class definition of Queue
 * Authors
 *    Bryan Lopez, Kimberly Stowe, Matthew Burr & Shayla Nelson
 ************************************************************************/
#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <new>
#include <cassert>

/*****************************************
 * Queue
 * This class will add and take away data
 ****************************************/
template <class T>
class Queue
{
public:

// Default constructor and non-default constructor
 Queue(int m_capacity = 0) throw (const char *)

// copy constructor
    Queue (const Queue<T> & source) throw (const char *);

// destructor
    ~Queue();

// assignment operator
    Queue<T> & operator = (const Queue<T> & rhs) throw (const char *);

// check and see if empty
    bool empty() const;

// returns the size
    int size() const;

// gives us the capacity
    int capacity() const;

// will clear the board
    void clear();

// add a value to the top
    void push(const T & value) throw (const char *);

// pull a value from the top
    void pop() throw (const char*);

// gets the value from the front
    Queue & front() const;

// gets the value from the back
    Queue & back() const throw (const char *);

// resize the capacity of queue
    void resize() throw (const char *);

private:

    int m_capacity;                     // capacity of queue
    T * m_data;                         // array to store element
    int m_front;                        // front of queue
    int m_back;                         // back of queue
    void resize() throw (const char *); // resize the stack

class Transaction
    {
        
    };

class Portfolio
    {
        
    };
};


#endif /* Queue_h */
