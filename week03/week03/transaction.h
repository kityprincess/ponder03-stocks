#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "dollars.h"

class Transaction
{
public:
   Transaction(int in_shareCount = 1, Dollars in_sharePrice = 1.0);

   // Gets the count of remaining shares bought in this transaction; 
   // this can't be added to, but shares can be sold
   int getShareCount() const { return m_shareCount; }

   // Get share price (share price can't be changed once set at creation time
   // only read
   Dollars getSharePrice() const { return m_sharePrice; }

   // Sells a subset of the shares, reducing the share count by the 
   // amount sold; returns the number of shares sold - in case
   // a caller tries to sell more shares than available
   int sellShares(int in_sellCount);

   // Sells all shares from this transaction
   int sellAllShares();

private:
   int m_shareCount;
   Dollars m_sharePrice;
};

#endif // !TRANSACTION_H