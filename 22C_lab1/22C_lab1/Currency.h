#pragma once
#include <string>
#include <iostream>

class Currency
{
protected:
	std::string note;
	int whole;
	int fraction;
	std::string coin;
	void simplify();
	//Exception class
public:
	//Constructor
	Currency();
	//Constructor with initialization list
	Currency(int wh, int fr) : note("N/A"), whole(wh), fraction(fr), coin("N/A") {}
	//Destructor
	~Currency();

	//operator Overloading
	virtual Currency operator + (const Currency&);
	virtual Currency operator - (const Currency&);
	virtual bool operator > (const Currency&);
	virtual bool operator < (const Currency&);
	virtual bool operator == (const Currency&);
	bool operator == (const int&);

	//Exception Handling Class
	class NegativeSize {};

	friend std::ostream &operator << (std::ostream &, Currency &);
	friend std::istream &operator >> (std::istream &strm, Currency &obj);

	//Getter functions that derived classes use
	std::string getNote() { return note; }
	int getWhole() { return whole; }
	int getFraction() { return fraction; }
	std::string getCoin() { return coin; }
};