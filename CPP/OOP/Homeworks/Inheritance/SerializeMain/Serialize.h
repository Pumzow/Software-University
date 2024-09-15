#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

byte* serializeToMemory(string input, size_t& size)
{
	vector<Company> companies;

	std::istringstream companiesIn(input);

	Company company;

	while (companiesIn >> company) 
	{
		companies.push_back(company);
	}
	std::uint8_t numCompanies = companies.size();
	stringstream ss;
	ss.write((char*)&numCompanies, 1);
	for (auto c : companies)
	{
		uint8_t id = c.getId();
		ss.write((char*)&id, 1);
		ss << c.getName();
		ss << (char)0;
		auto employees = c.getEmployees();
		uint8_t numEmployees = employees.size();
		ss.write((char*)&numEmployees, 1);

		for (auto e : employees)
		{
			ss << e.first;
			ss << e.second;
		}
	}
	string output = ss.str();
	size = output.size();
	byte* buffer = new byte[size];
	memcpy(buffer, output.data(), size);
	return buffer;
}