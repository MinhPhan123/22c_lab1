#include "Currency.h"
#include "Rupee.h"
#include <iostream>
#include <string>

//Constructor
Rupee::Rupee()
{
	note = "Rupees";
	whole = 0;
	fraction = 0;
	coin = "Paises";
}

Rupee::Rupee(int wh, int fr)
{
	note = "Rupees";
	whole = wh;
	fraction = fr;
	coin = "Paises";
}

//Destructor
Rupee::~Rupee()
{

}

//Getter Functions
std::string Rupee::getNote()
{
	return note;
}

int Rupee::getWhole()
{
	return whole;
}

int Rupee::getFraction()
{
	return fraction;
}

std::string Rupee::getCoin()
{
	return coin;
}

//Mutator Functions
void Rupee::setWhole(int mo)
{
	whole = mo;
}

void Rupee::setFraction(int ce)
{
	fraction = ce;
	simplify();
}


/*		Overloaded (+) & (-) Operators

*/

Rupee Rupee::operator + (const Rupee & right)
{
	Rupee temp;

	temp.fraction = fraction + right.fraction;
	temp.whole = whole + right.whole;
	temp.simplify();

	return temp;
}

Rupee Rupee::operator - (const Rupee & right)
{
	Rupee temp;
	Rupee n_size;

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

bool Rupee::operator > (const Rupee &right)
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

bool Rupee::operator < (const Rupee &right)
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

bool Rupee::operator == (const Rupee &right)
{
	bool status;

	if (whole == right.whole && fraction == right.fraction)
		status = true;
	else
		status = false;

	return status;
}

std::ostream &operator << (std::ostream &strm, const Rupee &obj)
{
	strm << obj.note << ", " << obj.whole << ", " << obj.fraction << ", " << obj.coin;
	return strm;
}