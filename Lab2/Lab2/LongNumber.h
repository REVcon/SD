#pragma once
#include <string>
#include <vector>

class CLongNumber
{
public:
	CLongNumber();
	CLongNumber(unsigned arg);
	CLongNumber(const std::string & arg);
	~CLongNumber();
	std::string ToString();
	CLongNumber& operator = (const CLongNumber &other);
	CLongNumber const operator + (CLongNumber const & other) const;
	CLongNumber const operator - (CLongNumber const & other) const;
	CLongNumber const operator * (CLongNumber const & other) const;
	CLongNumber const operator / (CLongNumber const & other) const;
	bool const operator <= (CLongNumber const & other) const;
	bool const operator > (CLongNumber const & other) const;
private:
	unsigned GetPart(const size_t arg) const;
	void DeleteEqualZeroParts();
	void LevelUp();
	const int m_base = 1000;
	const unsigned m_baseLength = static_cast<unsigned>(log10(m_base));
	std::vector<unsigned> m_number;
};

