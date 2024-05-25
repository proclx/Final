#pragma once
#include "Programmer.h"
class TechLead :
    public Programmer
{
private:
    unsigned teamSize;
public:
    TechLead() = default;
    virtual ~TechLead() = default;
    TechLead(const Title& _title, unsigned _hoursWorked, unsigned _teamSize);
    virtual double Salary() const override;
    virtual void Print(std::ostream& os) const override;
    virtual void Read(std::istream& is) override;
    double Bonus() const;
};

