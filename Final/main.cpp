#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <fstream>
#include <map>
#include "TechLead.h"
#include "Programmer.h"

typedef std::unique_ptr<Programmer> ProgrammerPtr;

namespace std
{
	template<typename T1, typename T2>
	std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pair)
	{
		os << pair.first << ' ' << pair.second << std::endl;
		return os;
	}
}

int main()
{
	std::vector<ProgrammerPtr> programmers;
	std::ifstream fin("Programmers.txt");
	if (!fin.good())
	{
		std::cout << "Something happened with fstream";
		abort();
	}
	while (fin.is_open() && fin.good())
	{
		Programmer temp;
		fin >> temp;
		programmers.emplace_back(std::make_unique<Programmer>(temp));
	}
	fin.close();
	fin.open("TechLeads.txt");
	if (!fin.good())
	{
		std::cout << "Something happened with fstream";
		abort();
	}
	while (fin.is_open() && fin.good())
	{
		TechLead temp;
		fin >> temp;
		programmers.emplace_back(std::make_unique<TechLead>(temp));
	}
	std::cout << "Programmers sorted by hours worked:\n";
	std::sort(programmers.begin(), programmers.end(), [](const ProgrammerPtr& P1, const ProgrammerPtr& P2) { return (*P1).Hours() < (*P2).Hours(); });
	std::for_each(programmers.begin(), programmers.end(), [](const ProgrammerPtr& P) { std::cout << *P; });
	std::for_each(programmers.begin(), programmers.end(), [](ProgrammerPtr& P) { (*P).Hours() *= 2; });
	std::cout << "Programmers sorted by salary:\n";
	std::sort(programmers.begin(), programmers.end(), [](const ProgrammerPtr& P1, const ProgrammerPtr& P2) { return (*P1).Salary() < (*P2).Salary(); });
	std::for_each(programmers.begin(), programmers.end(), [](const ProgrammerPtr& P) { std::cout << *P; });

	std::map<Programmer::Title, double> title_salary;
	std::for_each(programmers.begin(), programmers.end(), [&title_salary](const ProgrammerPtr& P) { title_salary[(*P).Title_()] += (*P).Salary(); });
	std::cout << "Title and salary paid:\n";
	std::for_each(title_salary.begin(), title_salary.end(), [](auto keyVal) {std::cout << keyVal; });

	return 0;
}