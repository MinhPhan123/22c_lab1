#include "Currency.h"
#include "Yen.h"
#include <iostream>
#include <string>

//Constructor
Yen::Yen()
{
	note = "Yens";
	whole = 0;
	fraction = 0;
	coin = "Sens";
}

Yen::Yen(int wh, int fr)
{
	note = "Yens";
	whole = wh;
	fraction = fr;
	coin = "Sens";
}

//Destructor
Yen::~Yen()
{

}

//Getter Functions
std::string Yen::getNote()
{
	return note;
}

int Yen::getWhole()
{
	return whole;
}

int Yen::getFraction()
{
	return fraction;
}

std::string Yen::getCoin()
{
	return coin;
}

//Mutator Functions
void Yen::setWhole(int mo)
{
	whole = mo;
}

void Yen::setFraction(int ce)
{
	fraction = ce;
	simplify();
}

/*		Overloaded (+) & (-) Operators

*/

Yen Yen::operator + (const Yen & right)
{
	Yen temp;

	temp.fraction = fraction + right.fraction;
	temp.whole = whole + right.whole;
	temp.simplify();

	return temp;
}

Yen Yen::operator - (const Yen & right)
{
	Yen temp;
	Yen n_size;

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

bool Yen::operator > (const Yen &right)
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

bool Yen::operator < (const Yen &right)
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

bool Yen::operator == (const Yen &right)
{
	bool status;

	if (whole == right.whole && fraction == right.fraction)
		status = true;
	else
		status = false;

	return status;
}

std::ostream &operator << (std::ostream &strm, const Yen &obj)
{
	strm << obj.note << ", " << obj.whole << ", " << obj.fraction << ", " << obj.coin;
	return strm;
}