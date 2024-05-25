#include "TechLead.h"

TechLead::TechLead(const Title& _title, unsigned _hoursWorked, unsigned _teamSize)
	: Programmer(title, hoursWorked), teamSize(_teamSize)
{
	if (title == Title::Junior)
	{
		title = Title::Middle;
	}
}

double TechLead::Salary() const
{
	return Programmer::Salary() * Bonus();
}

void TechLead::Print(std::ostream& os) const
{
	os << "TechLead(" << title << ") has " << teamSize << " employers and worked " << hoursWorked << " (" << Salary() << "$)\n";
}

void TechLead::Read(std::istream& is)
{
	int _title;
	is >> _title >> hoursWorked >> teamSize;
	title = Title(_title);
}

double TechLead::Bonus() const
{
	return 1.0 + (0.01 * teamSize);
}
