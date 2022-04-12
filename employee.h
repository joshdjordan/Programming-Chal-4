#pragma once
#include <iostream>

class employee
{
public:
	employee()
	{
		m_EmpID = 0;
		m_EmpName = "John Doe";
	}

	employee(int EmpID, std::string EmpName)
	{
		set_EmpID(EmpID);
		set_EmpName(EmpName);
	}

	// SETTERS //
	void set_EmpID(int EmpID)
	{
		EmpID = m_EmpID;
	}

	void set_EmpName(std::string EmpName)
	{
		EmpName = m_EmpName;
	}

	// GETTERS //
	int get_EmpID()
	{
		return m_EmpID;
	}

	std::string get_EmpName()
	{
		return m_EmpName;
	}

	// OVERLOADING //
	bool operator <(const employee& data)
	{
		if (m_EmpID < data.m_EmpID)
		{
			return true;
		}
		return false;
	}

	bool operator >(const employee& data)
	{
		if (m_EmpID > data.m_EmpID)
		{
			return true;
		}
		return false;
	}

private:
	int m_EmpID;
	std::string m_EmpName;
};