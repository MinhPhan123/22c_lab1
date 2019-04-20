#include "Currency.h"
#include <iostream>

//Constructor
Currency::Currency()
{
	note = "N/A";
	whole = 0;
	fraction = 0;
	coin = "N/A";
}

//Destructor
Currency::~Currency()
{

}


/*	Simplify function
*
*/
void Currency::simplify()
{
	if (fraction >= 100)
	{
		whole += (fraction / 100);
		fraction = (fraction % 100);
	}
}

Currency Currency::operator + (const Currency & right)
{
	Currency temp;
	temp.note = right.note;
	temp.coin = right.coin;
	temp.fraction = fraction + right.fraction;
	temp.whole = whole + right.whole;
	temp.simplify();

	return temp;
}

Currency Currency::operator - (const Currency & right)
{
	Currency temp;
	Currency n_size;
	temp.note = right.note;
	temp.coin = right.coin;
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

bool Currency::operator > (const Currency &right)
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

bool Currency::operator < (const Currency &right)
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

bool Currency::operator == (const Currency &right)
{
	bool status;

	if (whole == right.whole && fraction == right.fraction)
		status = true;
	else
		status = false;

	return status;
}

bool Currency::operator == (const int &right)
{
	bool status;

	if (whole == right && fraction == 0)
		status = true;
	else
		status = false;

	return status;
}

std::ostream &operator << (std::ostream &strm, Currency &obj)
{
	strm << obj.getNote() << ", " << obj.whole << ", " << obj.fraction << ", " << obj.getCoin();
	return strm;
}

std::istream &operator >> (std::istream &strm, Currency &obj)
{
    strm >> obj.whole >> obj.fraction; 
    obj.simplify(); 
   return strm;  
}  