#include "Currency.h"
#include "Dollar.h"
#include <iostream>
#include <string>

//Constructor
Dollar::Dollar()
{
	note = "Dollars";
	whole = 0;
	fraction = 0;
	coin = "Cents";
}

Dollar::Dollar(int wh, int fr)
{
	note = "Dollars";
	whole = wh;
	fraction = fr;
	coin = "Cents";
}

//Destructor
Dollar::~Dollar()
{

}

//Getter Functions
std::string Dollar::getNote() 
{ 
	return note; 
}

int Dollar::getWhole() 
{ 
	return whole; 
}

int Dollar::getFraction()
{ 
	return fraction; 
}

std::string Dollar::getCoin() 
{ 
	return coin; 
}

//Mutator Functions
void Dollar::setWhole(int mo) 
{ 
	whole = mo; 
}

void Dollar::setFraction(int ce) 
{ 
	fraction = ce; 
	simplify(); 
}

/*		Overloaded (+) & (-) Operators

*/

Dollar Dollar::operator + (const Dollar & right)
{
	Dollar temp;

	temp.fraction = fraction + right.fraction;
	temp.whole = whole + right.whole;
	temp.simplify();

	return temp;
}

Dollar Dollar::operator - (const Dollar & right)
{
	Dollar temp;
	Dollar n_size;

	temp.fraction = fraction - right.fraction;
	temp.whole = whole - right.whole;
	temp.simplify();

	if (temp > n_size)
		return temp;
	if (temp == n_size)
		return temp;
	else
		throw NegativeSize();
}

//Overloaded > Operator
bool Dollar::operator > (const Dollar &right)
{
	bool status;

	if (whole > right.whole)
		status = true;
	else if (whole == right.whole && fraction > right.fraction)
		status = true;
	else
		status = false;

	return status;
}

//Overloaded < Operator
bool Dollar::operator < (const Dollar &right)
{
	bool status;

	if (whole < right.whole)
		status = true;
	else if (whole == right.whole && fraction < right.fraction)
		status = true;
	else
		status = false;

	return status;
}

//Overloaded == Operator
bool Dollar::operator == (const Dollar &right)
{
	bool status;

	if (whole == right.whole && fraction == right.fraction)
		status = true;
	else
		status = false;

	return status;
}

//Overloaded << Operator
/*std::ostream &operator << (std::ostream &strm, const Dollar &obj) 
{
	strm << obj.note << ", " << obj.whole << ", " << obj.fraction << ", " << obj.coin;
	return strm;
}*/
