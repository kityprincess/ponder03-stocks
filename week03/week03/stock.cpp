/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include <sstream>     // for STRINGSTREAM
#include "stock.h"     // for STOCK_TRANSACTION
#include "portfolio.h" // for PORTFOLIO
#include "dollars.h"   // for DOLLARS
using namespace std;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   // your code here...
   Portfolio portfolio;

   string line;
   while (getline(cin, line))
   {
      // load the line into a stringstream
      stringstream ss;
      ss.str(line);

      // declare variables
      string option;
      int shares;
      Dollars price;

      // read in the data
      ss >> option >> shares >> price;

      if (option == "buy")
      {
         portfolio.buy(shares, price);
         portfolio.display(); // remove when function working
      }
      else if (option == "sell")
      {

      }
      else if (option == "display")
      {

      }
      else if (option == "quit")
      {
         break;
      }
      else if (option != "")
         cout << "Unrecognized command, try again.\n";
   }

}


