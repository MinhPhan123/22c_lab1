/*
CIS 22C 01Y
Lab 1:
Author: Minh Phan, Samuel Ruiz Cervantes
Date: 04/20/2019
*/

#include "Dollar.h"
#include "Euro.h"
#include "Yen.h"
#include "Rupee.h"
#include "Yuan.h"
#include "Wallet.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
     int choice, number = 0;

     Wallet wallet;

     Currency *currency = NULL;

     do
     {
          cout << "Main menu." << endl;
          cout << "1. Add money\n2.Remove money\n3.Check currencies you have in the wallet\n4.Empty wallet\n";
          cout << "5.Check wallet status and print\n6.Quit\n" << endl;
          cout << "Please enter your choice" << endl;
          cin >> number;
  
          if (number == 1 || number == 2 || number == 3)
          {
               do
               {
                    cout << "\n1.Dollar\n2.Euro\n3.Yen\n4.Rupee\n5.Yuan\n6.Return to the main menu\n" << endl;
                    cout << "Please choose the currency." << endl;
                    cin >> choice;
                    cout << endl;

                    if (choice == 1)
                    {
                         currency = new Dollar;
                    }
                    else if (choice == 2)
                    {
                         currency = new Euro;
                    }
                    else if (choice == 3)
                    {
                         currency = new Yen;
                    }
                    else if (choice == 4)
                    {
                         currency = new Rupee;
                    }
                    else if (choice == 5)
                    {
                         currency = new Yuan;
                    }
                    else if (choice == 6)
                         break;

                    if (number != 3)
                    {
                         cout << "Please enter the " << currency->getNote() << " and " << currency->getCoin() << endl;
                         cin >> *currency;

                         cout << endl;

                         switch (number)
                         {
                         case 1: //number == 1
                         {
                              if (currency->getWhole() < 0 || currency->getFraction() < 0)
                              {
                                   cout << "Please use the remove section to remove money.\n" << endl;
                                   break;
                              }
                              else                         
                                   wallet.add(currency->getWhole(), currency->getFraction(), choice);    
                         }
                         break;
                         case 2: //number == 2
                         {
                              if (currency > wallet.myCurr[choice - 1])
                              {
                                   cout << "You don't have enough money to remove.\n" << endl;
                                   break;
                              }
                              else
                                   wallet.subtract(currency->getWhole(), currency->getFraction(), choice);
                              break;
                         }
                         }
                    }
                    else //number == 3
                    {
                         if (wallet.emptyCurr(choice - 1))
                              cout << "You don't have any " << currency->getNote() << endl;
                         else
                              cout << "You have " << *wallet.myCurr[choice - 1] << endl;
                         cout << endl;
                    }
                    
                    if (choice < 1 || choice > 6)
                         cout << "Invalid input.Please re-enter your choice." << endl;
                    
               } while (choice < 1 || choice > 6);

          }
          else if (number == 4)
          {
               wallet.empty();
               cout << "\nFinish empty your wallet.\n" << endl;
          }
          else if (number == 5)
          {
               if (wallet.non_zero() == 0)
                    cout << "\nYour wallet is empty." << endl;
               else
               {
                    cout << "\nYour wallet has: " << endl;
                    for (int i = 0; i < 5; i++)
                         cout << *wallet.myCurr[i] << endl;
               }
               cout << endl;
          }
          else if (number < 1 || number >6)
               cout << "Invalid input. Please re-enter your choice.\n" << endl;

     } while (number != 6);

     system("pause");
     return 0;
}
