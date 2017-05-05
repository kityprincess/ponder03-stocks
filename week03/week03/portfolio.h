#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "queue.h"
#include "transaction.h"
#include "dollars.h"
#include <iostream>

class Portfolio
{
public:
   Portfolio();
   ~Portfolio();
   void buy(int number, Dollars price);
   void sell(int number, Dollars price);
   void display(std::ostream & out) const;

private:
   Queue<Transaction> m_holdings;
   Queue<Transaction> m_saleHistory;
   Dollars m_proceeds;
};

std::ostream & operator << (std::ostream & out, const Portfolio & rhs);
#endif
