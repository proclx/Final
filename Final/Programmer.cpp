#include "Programmer.h"

std::ostream& operator<<(std::ostream& os, const Programmer::Title& T)
{
	switch (T)
	{
	case Programmer::Title::Junior:
		os << "junior";
		break;
	case Programmer::Title::Middle:
		os << "middle";
		break;
	case Programmer::Title::Senior:
		os << "senior";
		break;
	default:
		break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const Programmer& P)
{
	P.Print(os);
	return os;
}

std::istream& operator>>(std::istream& is, Programmer& P)
{
	P.Read(is);
	return is;
}

Programmer::Programmer(const Title& _title, unsigned _hoursWorked)
	: title(_title), hoursWorked(_hoursWorked)
{
}

double Programmer::Salary() const
{
	return hoursWorked * Rate();
}

double Programmer::Rate() const
{
	double result;
	switch (title)
	{
	case Programmer::Title::Junior:
		return juniorRate;
	case Programmer::Title::Middle:
		return middleRate;
	case Programmer::Title::Senior:
		return seniorRate;
	default:
		return 0.0;
	}
}

void Programmer::Print(std::ostream& os) const
{
	os << title << " developer, worked " << hoursWorked << " this week (" << Salary() << "$)\n";
}

void Programmer::Read(std::istream& is)
{
	int _title;
	is >> _title >> hoursWorked;
	title = Title(_title);
}

unsigned& Programmer::Hours()
{
	return hoursWorked;
}

unsigned Programmer::Hours() const
{
	return hoursWorked;
}

Programmer::Title Programmer::Title_() const
{
	return title;
}

bool Programmer::CompareBySalary::operator()(const Programmer& P1, const Programmer& P2) const
{
	return P1.Salary() < P2.Salary();
}

const double Programmer::juniorRate = 1.1;
const double Programmer::middleRate = 2.0;
const double Programmer::seniorRate = 2.5;