#pragma once
#include <iostream>
class Programmer
{
public:
	enum class Title
	{
		Junior,
		Middle,
		Senior
	};
	const static double juniorRate;
	const static double middleRate;
	const static double seniorRate;
protected:
	Title title;
	unsigned hoursWorked;
public:
	Programmer(const Title& _title, unsigned _hoursWorked);
	Programmer() = default;
	virtual ~Programmer() = default;

	virtual double Salary() const;
	double Rate() const;
	virtual void Print(std::ostream& os) const;
	virtual void Read(std::istream& is);
	unsigned& Hours();
	unsigned Hours() const;
	Title Title_() const;
	class CompareBySalary
	{
	public:
		bool operator()(const Programmer& P1, const Programmer& P2) const;
	};

	template<typename Cmp = CompareBySalary>
	bool Compare(const Programmer& other, Cmp cmp = Cmp()) const
	{
		return cmp(*this, other);
	}
};

std::ostream& operator<<(std::ostream& os, const Programmer::Title& T);
std::ostream& operator<<(std::ostream& os, const Programmer& P);
std::istream& operator>>(std::istream& is, Programmer& P);