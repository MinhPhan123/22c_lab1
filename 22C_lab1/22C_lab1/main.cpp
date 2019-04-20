#include "Wallet.h"
#include "Currency.h"
#include "Dollar.h"
#include "Euro.h"
#include "Yen.h"
#include "Rupee.h"
#include "Yuan.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Wallet test;

	try
	{
		test.subtract(2, 2, 0);
	}
	catch (Wallet::NegativeSize)
	{
		cout << "You subtracted beyond range of currency" << endl;
	}


	system("pause");
	return 0;
}