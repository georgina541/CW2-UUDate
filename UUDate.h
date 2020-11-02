/*
* UUDate.h
*
* Version information
* Author: TODO - Add your name here
* Date: TODO - Add date you started working on the code
* Description: This file is the header file for the UUDate class and declares the class interface
* NOTE: Do not change the signatures of the functions provided. You may add your own support functions
*
* Copyright notice -
*/

#pragma once

#include <string>
// You can include addition non-date/time related headers if necessary

class UUDate
{

private:
	int day_; 
	int month_; 
	int year_;

public:
	// Constructors
	UUDate(); // Default constructor sets date to 1/1/2000
	UUDate(int day, int month, int year); // You should validate the input parameter
	UUDate(std::string date); // Should accept "2/8/2018" or "02/08/2018" **length of string

	// Getters and Setters
	// Remember to validate input to setters
	int GetDay() const;
	void SetDay(int day);
	int GetMonth() const;
	void SetMonth(int month);
	int GetYear() const;
	void SetYear(int year);

	// Utility functions
	void IncrementDate(); // Increment the current date by one day.
	int Between(UUDate date); // Return # days between object date and the set date
	std::string GetDate(); // Return date as a string in correct format
	int CalculateDay(int day, int month, int year);
	bool VaildDate(int day, int month, int year);
};

