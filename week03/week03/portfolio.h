#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "queue.h"
#include "transaction.h"

class Portfolio
{
public:
   Portfolio();
   ~Portfolio();
   
private:
   Queue<Transaction> m_transactions;

};

#endif
