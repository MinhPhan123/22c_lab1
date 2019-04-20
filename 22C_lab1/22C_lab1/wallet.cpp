#include "Wallet.h"
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Yen.h"
#include "Rupee.h"
#include "Yuan.h"
#include <iostream>
#include <string>

Wallet::Wallet()
{
	myCurr[0] = new Dollar;
	myCurr[1] = new Euro;
	myCurr[2] = new Yen;
	myCurr[3] = new Rupee;
	myCurr[4] = new Yuan;
}

Wallet::~Wallet()
{
	delete []myCurr;
}

//Still need to code to ensure that we don't write out of bounds.
Currency *Wallet::operator [] (const int sub)
{
	return myCurr[sub];
}

//This function checks how many non-zero currencies are in the wallet
int Wallet::non_zero()
{
	int counter = 0;

	for (int i = 0; i < 5; i++)
	{
		if ( *(myCurr+i) == 0)
			counter++;
	}
	counter = 5 - counter;

	return counter;
}

bool Wallet::emptyCurr(const int num)
{
	bool test;

	if (myCurr[num] == 0)
		test = false;
	else
		test = true;

	return test;
}

void Wallet::add(int wh, int fr, int cu)
{
	Dollar temp0(wh, fr);
	Euro temp1(wh, fr);
	Yen temp2(wh, fr);
	Rupee temp3(wh, fr);
	Yuan temp4(wh, fr);

	switch (cu)
	{
		case 0:
			*myCurr[0] = *myCurr[0] + temp0;
			break;
		case 1:
			*myCurr[1] = *myCurr[1] + temp1;
			break;
		case 2:
			*myCurr[2] = *myCurr[2] + temp2;
			break;
		case 3:
			*myCurr[3] = *myCurr[3] + temp3;
			break;
		case 4:
			*myCurr[4] = *myCurr[4] + temp4;
			break;
	}
}

void Wallet::subtract(int wh, int fr, int cu)
{
	Dollar temp0(wh, fr);
	Euro temp1(wh, fr);
	Yen temp2(wh, fr);
	Rupee temp3(wh, fr);
	Yuan temp4(wh, fr);

	try
	{
		switch (cu)
		{
		case 0:
			*myCurr[0] = *myCurr[0] - temp0;
			break;
		case 1:
			*myCurr[1] = *myCurr[1] - temp1;
			break;
		case 2:
			*myCurr[2] = *myCurr[2] - temp2;
			break;
		case 3:
			*myCurr[3] = *myCurr[3] - temp3;
			break;
		case 4:
			*myCurr[4] = *myCurr[4] - temp4;
			break;
		}
	}
	catch (Currency::NegativeSize)
	{
		throw NegativeSize();
	}
}