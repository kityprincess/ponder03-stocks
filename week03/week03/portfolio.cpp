#include "portfolio.h"
#include <iostream>    // for CIN and COUT
using namespace std;

/***********************************************************************
* PORTFOLIO :: CONSTRUCTOR
* Creates a new Queue to keep track of the buy/sell transactions
************************************************************************/
Portfolio::Portfolio()
    : proceeds(0)
{
}

/***********************************************************************
* PORTFOLIO :: DESTRUCTOR
* Destructs the portfolio
************************************************************************/
Portfolio::~Portfolio()
{
}

/***********************************************************************
* PORTFOLIO :: BUY
* 
************************************************************************/
void Portfolio::buy(int number, Dollars price)
{
    Transaction t = Transaction(number, price);
    m_transactions.push(t);
}

/***********************************************************************
* PORTFOLIO :: SELL
* 
************************************************************************/
void Portfolio::sell(int number, Dollars price)
{
   if (number < m_transactions.front().getShareCount())
   {
      m_transactions.front().sellShares(number);
   }
   //m_transactions.pop();
   
}

/***********************************************************************
* PORTFOLIO :: DISPLAY
* 
************************************************************************/
void Portfolio::display()
{
   // TODO: make this according to spec
   Queue <Transaction> q = m_transactions;
   cout << "{ ";
   while (!q.empty())
   {
      cout << "(" << q.front().getShareCount() << ' ' << q.front().getSharePrice() << ") ";
      q.pop();
   }
   cout << '}';
}