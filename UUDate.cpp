/*
* UUDate.cpp
*
* Version information
* Author: TODO - Add your name here
* Date: TODO - Add date you started working on the code
* Description: This file is the implementation file for the UUDate class and defines (implements) the functions of the class
*
* Copyright notice -
*/

#include "UUDate.h"
#include <iostream>
#include <string>

UUDate::UUDate() {
	// Initialise the date to 01/01/2000
	day_ = 01;
	month_ = 01;
	year_ = 2000;
}
bool UUDate::VaildDate(int day, int month, int year)
{
	if (year == 0) {
		return false;
	}
	if (month > 12 || month < 1) {
		return false;
	}
	if (day > 31 || day < 1) {
		return false;
	}
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		return false;
	}
	if (day > 29 && month == 2) {
		return false;
	}
	if (day > 28 && month == 2 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
		return false;
	}
	return true;
};


UUDate::UUDate(int day, int month, int year) : day_{ day }, month_{ month }, year_{ year }
	
	// TODO - Add your implementation here
{
	if (VaildDate(day, month, year)) {
		day_ = day;
		month_ = month;
		year_ = year;
	}
	else {
		day_ = 1;
		month_ = 1;
		year_ = 2000;
	}
}
UUDate::UUDate(std::string date) {
	// TODO - Add your implementation here
	int day, month, year;
	int countSlash = 0;
	int tempPos = 0;

	if (date.length() >= 8 && date.length() <= 10)
	{
		for (int i = 0; i < (int)date.length(); i++)
		{
			if (date.at(i) == '/')
			{
				if (countSlash == 0)
					day_ = std::stoi(date.substr(tempPos,
						i));
				tempPos = i + 1;
				countSlash++;
				if (countSlash == 1)
					month_ = std::stoi(date.substr(tempPos,
						2));
				else if (countSlash == 2)
					year_ = std::stoi(date.substr(tempPos));
			}
		}
	}

	if (!VaildDate(day_, month_, year_)) 
	{
		day_ = 1;
		month_ = 1;
		year_ = 2000;
	}
}
int UUDate::GetDay() const {
	return day_;
}

void UUDate::SetDay(int day) {
	// TODO - Add your implementation here
	if (VaildDate(day, month_, year_)) {
		day_ = day;
	}
}
int UUDate::GetMonth() const {
	return month_;
}

void UUDate::SetMonth(int month) {
	// TODO - Add your implementation here
	if ((0 < month) && (month < 13)){
		month_ = month;
	}
}

int UUDate::GetYear() const {
	return year_;
}

void UUDate::SetYear(int year) {
	// TODO - Add your implementation here
	if (year != 0) {
		year_ = year;
	}
}

void UUDate::IncrementDate() {
	// TODO - Add your implementation here
	// The function will add 1 day to the date you set when initialising object UUDate
	// Example: UUDate dummy("01-02-1999");  your date is set to 01-02-1999
	//			dummy.IncrementDate(); should change the date to 02-02-1999
	if ((month_ == 1) || (month_ == 3) || (month_ == 5) || (month_ == 7) || (month_ == 10) || (month_ == 12)) {
		day_ <= 31;
		day_ = 0;
		++month_;
		if (month_ == 13) {
			month_ = 1;
			++year_;
		}
	}
	else if ((month_ == 4) || (month_ == 6) || (month_ == 9) || (month_ == 11)) {
		day_ <= 30;
		day_ = 0;
		++month_;
	}
	else if ((month_ == 2) && (year_ % 4 == 0)) {
		day_ <= 29;
		day_ = 0;
		++month_;
	}
	else if ((month_ == 2)) {
		if (year_ % 100 != 0 || year_ % 400 != 0) {
			if (day_ == 29) {
				day_ = 0;
				++month_;

			}
		}
	}
	++day_;
}

int UUDate::CalculateDay(int day, int month, int year) {
	int DaysCount[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int leapDayCount[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
	int totalDays{ 0 };
	if (year_ % 4 == 0) {
		totalDays = ((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + leapDayCount[month - 1] + day;
	}
	else {
		totalDays = ((year - 1) * 366) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400) + DaysCount[month - 1] + day;
	}
	return totalDays;

};


int UUDate::Between(UUDate date) {
	// TODO - Add your implementation here.
	// The function will return the no of days between the object UUDate and the date pass to the function
	// Example: UUDate dummy("01-02-1999");  your date is set to 01-02-1999
	//			UUDate xmas("25-12-1999"); your "to" date
//			dummy.Between(xmas); will generate the no of days between 01-02-1999 to 25-12-1999

	int thedatefrom = CalculateDay(day_, month_, year_);
	int datetoo = CalculateDay (date.GetDay(), date.GetMonth(), date.GetYear());
	int datebetween = thedatefrom- datetoo;
	if (thedatefrom > datetoo) {
		datebetween = thedatefrom - datetoo;
	}
	else {
		datebetween = datetoo - thedatefrom;
	}
	return datebetween;	// you should return no. of days
}

std::string UUDate::GetDate() {
	std::string strTmp{ "" };
	if (day_ < 10) {
		strTmp = "0" + std::to_string(day_);
	}
	else {
		strTmp = std::to_string(day_);
	}

	if (month_ < 10) {
		strTmp += "/0" + std::to_string(month_);
	}
	else {
		strTmp += "/" + std::to_string(month_);
	}

	strTmp += "/" + std::to_string(year_);
	return strTmp;
}
