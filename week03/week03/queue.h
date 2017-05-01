//
//  queue.h
//  queue
//
//  Created by Bryan Lopez on 4/29/17.
//  Copyright � 2017 Lopez Bryan. All rights reserved.
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
   Queue(int in_capacity = 0) throw (const char *)

   // copy constructor
   Queue(const Queue<T> & source) throw (const char *);

   // destructor
   ~Queue() { if (m_capacity > 0) // If this is true, we have an allocated buffer
            delete[] m_data; }

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
   T & front() const;

   // gets the value from the back
   T & back() const throw (const char *);

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

/***********************************************************************
* QUEUE :: DEFAULT / NON_DEFAULT CONSTRUCTOR
* Creates an instance of the queue. If the caller provides a capacity
* we create a Queue with enough storage to hold that capacity
************************************************************************/
template <class T>
Queue<T> :: Queue(int in_capacity) throw (const char *)
   : m_capacity(0), m_front(0), m_back(0), m_data(NULL)
{
   assert(in_capacity >= 0);
   // First, assure the user specified a valid capacity; if capacity
   // is < 0, we just exit, we've already initialized our values
   // to defaults
   if (in_capacity <= 0)
      return;

   // If we've reached this point, we have an input capacity > 0
   // so we'll try allocating our array
   m_capacity = in_capacity;
   m_data = new (std::nothrow) T[m_capacity];

   // Check to see if we failed to allocate, and if so, throw
   // an error
   if (NULL == m_data)
      throw "ERROR: Unable to allocate a new buffer for Queue";
}

/**********************************************************************
* QUEUE :: COPY CONSTRUCTOR
* Creates a new Queue by copying the contents of another
**********************************************************************/
template <class T>
Queue<T> :: Queue(const Queue<T> & source) throw (const char *)
   : m_capacity(source.m_capacity), m_front(source.m_front), m_back(source.m_back)
{

   // Now we try to allocate our array
   m_data = new (std::nothrow) T[m_capacity];

   // If we failed, we throw an error
   if (NULL == m_data)
      throw "ERROR: Unable to allocate a new buffer for Queue";

   // If we reach this point, we've successfully allocated
   // our buffer, so let's copy the data
   for (int i = m_front; i <= m_back; i++)
      m_data[i] = source.m_data[i];

}

/**********************************************************************
* QUEUE :: ASSIGNMENT
* Assigns one Queue to another, creating a copy of the source
**********************************************************************/
template <class T>
Queue<T> & Queue<T> :: operator =
   (const Queue<T> & rhs) throw (const char *)
{
   // Check to see if we're self-assigning and quit the operation if we
   // are
   if (this == &rhs)
      return *this;

   // Now, check to see if our capacities are the same; if they aren't
   // then we need to delete our existing buffer and (potentially)
   // copy in the new one
   if (m_capacity != rhs.m_capacity)
   {
      // We only delete our data array if we have data
      // note that we're assuming that m_data is not null if m_capacity
      // is not zero.
      if (m_capacity)
         delete[] m_data;

      m_capacity = rhs.m_capacity;

      // We only create a new array if our source had one (i.e.
      // it had capacity)
      if (m_capacity)
      {
         m_data = new (std::nothrow) T[m_capacity];

         if (NULL == m_data)
            throw "ERROR: Unable to allocate a new buffer for Queue.";
      }
   }

   // And now we copy over the data
   m_front = rhs.m_front;
   m_back = rhs.m_back;
   for (int i = m_front; i <= m_back; i++)
      m_data[i] = rhs.m_data[i];

   return *this;
}

/****************************************************************
* QUEUE :: BACK
* Will check what value is at the back of the queue
****************************************************************/
template <class T>
T & Queue <T> :: back() const throw (const char *)
{
   if (!empty())
      return (m_data[m_back]);
   else
   {
      throw "ERROR: attempting to access an item in an empty queue";
   }
}

#endif /* Queue_h */
