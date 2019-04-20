#pragma once
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Yen.h"
#include "Rupee.h"
#include "Yuan.h"
#include <iostream>
#include <string>

class Wallet
{
protected:
	Currency *myCurr[5];

public:
	//Constructor
	Wallet();
	//We need a copy constructor
	//Wallet(const Wallet&);

	//Destructor
	~Wallet();

	//Sentinel Functions
	bool emptyCurr(const int);
	int non_zero();

	//Mutator Functions
	void add(int wh, int fr, int cu);  
	void subtract(int wh, int fr, int cu);

	//Exception Handling
	class NegativeSize {};

	//Operator Overloading ( [] )
	Currency *operator[](const int);  //Overloaded [] operator
};