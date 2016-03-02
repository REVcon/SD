#include "LongNumber.h"

using namespace std;

CLongNumber::CLongNumber()
{
}

CLongNumber::CLongNumber(unsigned arg)
{
	unsigned number = arg;
	do
	{		
		m_number.push_back(number % m_base);
		number /= m_base;
	} while (number);
}

CLongNumber::CLongNumber(const string & arg)
{
	string number = arg;
	while (number.length() > m_baseLength)
	{
		m_number.push_back(stoi(number.substr(number.length() - m_baseLength, number.length())));
		number = number.substr(0, number.length() - m_baseLength);
	}
	m_number.push_back(stoi(number));
}

string CLongNumber::ToString()
{
	string result;
	if (m_number.size() == 0)
	{
		return "0";
	}
	for (size_t i = 0; i < m_number.size(); ++i)
	{
		if (i == m_number.size() - 1)
		{
			result = to_string(m_number[i]) + result;
		}
		else
		{
			result = RefillByZero(i) + result;
		}
	}
	return result;
}

CLongNumber& CLongNumber::operator = (const CLongNumber &other)
{
	if (addressof(other) != this)
	{
		vector<unsigned> tmp;
		tmp = other.m_number;
		swap(m_number, tmp);
	}
	return *this;
}

unsigned CLongNumber::GetLevel(const size_t arg) const
{
	if (m_number.size() > arg)
	{
		return m_number[arg];
	}
	return 0;
}

void CLongNumber::DeleteExtraLevel()
{
	bool toRepeatCycle = true;
	while ((m_number.size() > 0) && toRepeatCycle)
	{
		toRepeatCycle = false;
		if (m_number[m_number.size() - 1] == 0)
		{
			m_number.pop_back();
			toRepeatCycle = true;
		}		
	}
}

CLongNumber const CLongNumber::operator + (CLongNumber const & other) const
{
	CLongNumber result;
	size_t length;
	if (m_number.size() > other.m_number.size())
	{
		length = m_number.size();
	}		
	else
	{
		length = other.m_number.size();
	}		

	unsigned part, overBase;
	overBase = 0;
	part = 0;

	for (size_t i = 0; i < length; i++)
	{
		part = 0;
		part = GetLevel(i) + other.GetLevel(i) + overBase;
		result.m_number.push_back(part % m_base);
		overBase = part / m_base;
	}

	if (overBase > 0)
	{
		result.m_number.push_back(overBase);
	}
	return result;
}


CLongNumber const CLongNumber::operator - (CLongNumber const & other) const
{
	if (*this <= other)
	{
		return CLongNumber();
	}
	CLongNumber result = *this;
	size_t len = m_number.size();
	for (size_t i = 0; i < len; i++)
	{
		if (i < (len - 1))
		{
			result.m_number[i + 1] --;
			result.m_number[i] += m_base;
		}
		result.m_number[i] -= other.GetLevel(i);
		if (result.m_number[i] / m_base > 0)
		{
			result.m_number[i + 1]++;
			result.m_number[i] %= m_base;
		}
	}
	result.DeleteExtraLevel();
	return result;
}

CLongNumber const CLongNumber::operator * (CLongNumber const & other) const
{
	CLongNumber result;
	size_t len = m_number.size() + other.m_number.size() + 1;
	result.m_number.resize(len, 0);
	for (size_t i = 0; i < m_number.size(); ++i)
	{
		for (size_t j = 0; j < other.m_number.size(); j++)
		{
			result.m_number[i + j] += m_number[i] * other.m_number[j];			
		}
	}
	for (size_t i = 0; i < len - 1; i++)
	{
		result.m_number[i + 1] += result.m_number[i] / m_base;
		result.m_number[i] %= m_base;
	}
	result.DeleteExtraLevel();
	return result;
}

CLongNumber const  CLongNumber :: operator / (CLongNumber const & other) const
{
	if (other == 0)
	{
		throw runtime_error("Division by zero");
	}
	if (*this < other)
	{
		return 0;
	}
	CLongNumber result;
	CLongNumber curValue;
	result.m_number.resize(m_number.size(), 0);
	for (int i = m_number.size() - 1; i >= 0; i--)
	{
		curValue.IncreaseLevel();
		curValue.m_number[0] = m_number[i];
		int multiplier = 0;
		int lowerBound = 0;
		int upperBound = m_base;
		while (lowerBound <= upperBound)
		{
			int m = (lowerBound + upperBound) / 2;
			CLongNumber cur = other * m;
			if (cur <= curValue)
			{
				multiplier = m;
				lowerBound = m + 1;
			}
			else
				upperBound = m - 1;
		}
		result.m_number[i] = multiplier;
		curValue = curValue - other * multiplier;
	}
	result.DeleteExtraLevel();
	return result;
}


bool const CLongNumber::operator > (CLongNumber const & other) const
{
	if (m_number.size() > other.m_number.size())
	{
		return true;
	}
	if (m_number.size() < other.m_number.size())
	{
		return false;
	}
	if (m_number.size() == other.m_number.size())
	{
		for (int i = static_cast<int>(m_number.size() - 1); i >= 0; --i)
		{
			if (m_number[i] > other.m_number[i])
			{
				return true;
			}
			if (m_number[i] < other.m_number[i])
			{
				return false;
			}
		}
	}
	return false;
}


bool const CLongNumber::operator < (CLongNumber const & other) const
{
	if (m_number.size() < other.m_number.size())
	{
		return true;
	}
	if (m_number.size() > other.m_number.size())
	{
		return false;
	}
	if (m_number.size() == other.m_number.size())
	{
		for (int i = static_cast<int>(m_number.size() - 1); i >= 0; --i)
		{
			if (m_number[i] < other.m_number[i])
			{
				return true;
			}
			if (m_number[i] > other.m_number[i])
			{
				return false;
			}
		}
	}
	return false;
}

bool const CLongNumber::operator >= (CLongNumber const & other) const
{
	return !(*this < other);
}

bool const CLongNumber::operator <= (CLongNumber const & other) const
{
	return !(*this > other);
}

bool const CLongNumber::operator == (CLongNumber const & other) const
{
	if (m_number.size() == other.m_number.size())
	{
		return equal(m_number.begin(), m_number.end(), other.m_number.begin(), equal_to<unsigned>());
	}
	return false;	
}

bool const CLongNumber::operator != (CLongNumber const & other) const
{
	return !(*this == other);
}

void CLongNumber::IncreaseLevel()
{
	m_number.resize(m_number.size() + 1);
	for (int i = m_number.size() - 1; i >= 1; i--)
	{
		m_number[i] = m_number[i - 1];
	}
}

string CLongNumber::RefillByZero(const size_t arg) const
{
	string result = to_string(m_number[arg]);
	while (result.size() < m_baseLength)
	{
		result = '0' + result;
	}
	return move(result);
}

CLongNumber::~CLongNumber()
{
}
