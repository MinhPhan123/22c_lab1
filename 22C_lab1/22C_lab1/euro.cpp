#include "Currency.h"
#include "Euro.h"
#include <iostream>
#include <string>

//Constructor
Euro::Euro()
{
	note = "Euros";
	whole = 0;
	fraction = 0;
	coin = "Cents";
}

Euro::Euro(int wh, int fr)
{
	note = "Euros";
	whole = wh;
	fraction = fr;
	coin = "Cents";
}

//Destructor
Euro::~Euro()
{

}

//Getter Functions
std::string Euro::getNote()
{
	return note;
}

int Euro::getWhole()
{
	return whole;
}

int Euro::getFraction()
{
	return fraction;
}

std::string Euro::getCoin()
{
	return coin;
}

//Mutator Functions
void Euro::setWhole(int mo)
{
	whole = mo;
}

void Euro::setFraction(int ce)
{
	fraction = ce;
	simplify();
}

/*		Overloaded (+) & (-) Operators

*/

Euro Euro::operator + (const Euro & right)
{
	Euro temp;

	temp.fraction = fraction + right.fraction;
	temp.whole = whole + right.whole;
	temp.simplify();

	return temp;
}

Euro Euro::operator - (const  Euro & right)
{
	Euro temp;
	Euro n_size;

	temp.fraction = fraction - right.fraction;
	temp.whole = whole - right.whole;
	temp.simplify();
	if (temp > n_size)
		return temp;
	if (temp == n_size)
		return temp;
	else
		throw NegativeSize();

	return temp;
}

bool  Euro::operator > (const  Euro &right)
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

bool  Euro::operator < (const  Euro &right)
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

bool  Euro::operator == (const  Euro &right)
{
	bool status;

	if (whole == right.whole && fraction == right.fraction)
		status = true;
	else
		status = false;

	return status;
}

std::ostream &operator << (std::ostream &strm, const Euro &obj)
{
	strm << obj.note << ", " << obj.whole << ", " << obj.fraction << ", " << obj.coin;
	return strm;
}