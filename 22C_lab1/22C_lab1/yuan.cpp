#include "Currency.h"
#include "Yuan.h"
#include <iostream>
#include <string>

//Constructor
Yuan::Yuan()
{
	note = "Yuans";
	whole = 0;
	fraction = 0;
	coin = "Fens";
}

Yuan::Yuan(int wh, int fr)
{
	note = "Dollars";
	whole = wh;
	fraction = fr;
	coin = "Cents";
}

//Destructor
Yuan::~Yuan()
{

}

//Getter Functions
std::string Yuan::getNote()
{
	return note;
}

int Yuan::getWhole()
{
	return whole;
}

int Yuan::getFraction()
{
	return fraction;
}

std::string Yuan::getCoin()
{
	return coin;
}

//Mutator Functions
void Yuan::setWhole(int mo)
{
	whole = mo;
}

void Yuan::setFraction(int ce)
{
	fraction = ce;
	simplify();
}

/*		Overloaded (+) & (-) Operators

*/

Yuan Yuan::operator + (const Yuan & right)
{
	Yuan temp;

	temp.fraction = fraction + right.fraction;
	temp.whole = whole + right.whole;
	temp.simplify();

	return temp;
}

Yuan Yuan::operator - (const Yuan & right)
{
	Yuan temp;
	Yuan n_size;

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

bool Yuan::operator > (const Yuan &right)
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

bool Yuan::operator < (const Yuan &right)
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

bool Yuan::operator == (const Yuan &right)
{
	bool status;

	if (whole == right.whole && fraction == right.fraction)
		status = true;
	else
		status = false;

	return status;
}

std::ostream &operator << (std::ostream &strm, const Yuan &obj)
{
	strm << obj.note << ", " << obj.whole << ", " << obj.fraction << ", " << obj.coin;
	return strm;
}