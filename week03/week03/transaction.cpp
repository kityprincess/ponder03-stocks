#include "transaction.h"
#include <cassert>

/***********************************************************************
* TRANSACTION :: CONSTRUCTOR
* "Buys" a number of shares at a given price by creating a new Transaction
* to represent the purchase
************************************************************************/
Transaction::Transaction(int in_shareCount, Dollars in_sharePrice)
   : m_shareCount(in_shareCount), m_sharePrice(in_sharePrice)
{
}

/***********************************************************************
* TRANSACTION :: SELLSHARES
* Sells a number of shares, reducing the transaction by that amount
************************************************************************/
int Transaction::sellShares(int in_sellCount)
{
   assert(in_sellCount >= 0);
   if (in_sellCount < 0)
      in_sellCount = 0;

   if (in_sellCount > m_shareCount)
      in_sellCount = m_shareCount;

   m_shareCount -= in_sellCount;

   assert(m_shareCount >= 0);
   assert(in_sellCount >= 0);

   return in_sellCount;
}

/***********************************************************************
* TRANSACTION :: SELLALLSHARES
* Sells all the shares contained in this transaction
************************************************************************/
int Transaction::sellAllShares()
{
   assert(m_shareCount >= 0);
   int soldShares = m_shareCount;
   m_shareCount = 0;
   
   return soldShares;
}