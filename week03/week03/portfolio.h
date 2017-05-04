#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "queue.h"
#include "transaction.h"
#include "dollars.h"

class Portfolio
{
public:
   Portfolio();
   ~Portfolio();
   void buy(int number, Dollars price);
   void sell(int number, Dollars price);
   void display();

private:
   Queue<Transaction> m_transactions;
   Queue<Transaction> m_history;
   Dollars proceeds;
};

#endif
