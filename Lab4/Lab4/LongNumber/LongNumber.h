#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
	bool const operator == (CLongNumber const & other) const;
	bool const operator != (CLongNumber const & other) const;
	bool const operator <= (CLongNumber const & other) const;
	bool const operator > (CLongNumber const & other) const;
	bool const operator >= (CLongNumber const & other) const;
	bool const operator < (CLongNumber const & other) const;
private:
	unsigned GetLevel(const size_t arg) const;
	std::string RefillByZero(const size_t arg) const;
	void DeleteExtraLevel();
	void IncreaseLevel();
	static const unsigned m_base = 1000;
	const unsigned m_baseLength = static_cast<unsigned>(log10(m_base));
	std::vector<unsigned> m_number;
};

CLongNumber Sqr(CLongNumber const & value);
CLongNumber Sqrt(CLongNumber const & value);
