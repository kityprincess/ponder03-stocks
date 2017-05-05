#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "dollars.h"
#include <iostream>

class Transaction
{
public:
   Transaction(int in_shareCount = 1, Dollars in_sharePrice = 1.0,
      Dollars in_soldPrice = 0.0);

   // Gets the count of remaining shares bought in this transaction; 
   // this can't be added to, but shares can be sold
   int getShareCount() const { return m_shareCount; }

   // Get share price (share price can't be changed once set at creation time
   // only read
   Dollars getSharePrice() const { return m_buyPrice; }

   // Get sold price (sold price can't be changed once set)
   // only read
   Dollars getSoldPrice() const { return m_soldPrice; }

   // Gets the profit for this transaction
   Dollars getProfit() const;

   // Sells a subset of the shares, reducing the share count by the 
   // amount sold; returns the number of shares sold - in case
   // a caller tries to sell more shares than available
   Transaction sellShares(int in_sellCount, Dollars in_salePrice);

   // Displays the transaction
   void display(std::ostream & out) const;

private:
   int m_shareCount;
   bool m_sold;
   Dollars m_buyPrice;
   Dollars m_soldPrice;
};

std::ostream & operator << (std::ostream & out, const Transaction & rhs);

#endif // !TRANSACTION_H