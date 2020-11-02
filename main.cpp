/*
* main.cpp
*
* Version information
* Author: TODO - Add your name here
* Date : TODO - Add date you started working on the code
* Description : This file is the driver for the project, use it to test your code.
*
* Copyright notice -
*/

#pragma once 

using namespace std;
#include "UUDate.h";
#include "UUDate.cpp"

int main() {

	std::cout << "\Testing Increment Functions";
	UUDate date16(20, 11, 2010);
	date16.IncrementDate();
	cout << "\nExpected: 21/11/2010";
	cout << "\nActual: " << date16.GetDate() << endl << endl;

	std::cout << "\Testing Increment Functions";
	UUDate date17(30, 11, 2010);
	date17.IncrementDate();
	cout << "\nExpected: 01/12/2010";
	cout << "\nActual: " << date17.GetDate() << endl << endl;

	std::cout << "\Testing Increment Functions";
	UUDate date18(31, 12, 2010);
	date18.IncrementDate();
	cout << "\nExpected: 01/01/2011";
	cout << "\nActual: " << date18.GetDate() << endl << endl;

	std::cout << "\Testing Between Functions";
	UUDate date21(31, 12, 2010);
	UUDate date22(31, 12, 2015);
	cout << "\nExpected: 1826";
	cout << "\nActual: " << date21.Between(date22) << endl << endl;

	std::cout << "\Testing Between Functions";
	UUDate date23(01, 01, 2011);
	UUDate date24(31, 12, 2010);
	cout << "\nExpected: 1";
	cout << "\nActual: " << date23.Between(date24) << endl << endl;

	std::cout << "\Testing Between Functions";
	UUDate date25(01, 02, 2020);
	UUDate date26(01, 03, 2020);
	cout << "\nExpected: 29";
	cout << "\nActual: " << date25.Between(date26) << endl << endl;

	std::cout << "\Testing Between Functions";
	UUDate date27(01, 03, 2010);
	UUDate date28(01, 03, 2020);
	cout << "\nExpected: 3653";
	cout << "\nActual: " << date27.Between(date28) << endl << endl;

	std::cout << "\nTesting Between Functions(UNIT TEST)";
	UUDate startDate{ 01,05,2007 };
	UUDate endDate{ 27,05,2007 };
	cout << "\nExpected: 26";
	cout << "\nActual: " << startDate.Between(endDate) << endl << endl;

	std::cout << "\nTesting Between Functions(UNIT TEST)";
	UUDate startDate2{ 15,7,2007 };
	UUDate endDate2{ 16,9,2007 };
	cout << "\nExpected: 63";
	cout << "\nActual: " << startDate2.Between(endDate2) << endl << endl;

	std::cout << "\nTesting Between Functions(UNIT TEST)";
	UUDate startDate3{ 4,12,1998 };
	UUDate endDate3{ 6,10,2018 };
	cout << "\nExpected: 7246";
	cout << "\nActual: " << startDate3.Between(endDate3) << endl << endl;

	cout << "\nTesting String Constructions";
	UUDate date3("1/4/1996");
	cout << "\nExpected: 01/04/1996";
	cout << "\nActual: " << date3.GetDate() << endl << endl;

	cout << "\nTesting String Constructions";
	UUDate date4("21/12/1998");
	cout << "\nExpected: 21/12/1998";
	cout << "\nActual: " << date4.GetDate() << endl << endl;

	cout << "\nTesting Validation Formula";
	UUDate date5("0/4/1996");
	cout << "\nExpected: 01/01/2000";
	cout << "\nActual: " << date5.GetDate() << endl << endl;

	cout << "\nTesting Validation Formula";
	UUDate date6("2/13/1996");
	cout << "\nExpected: 01/01/2000";
	cout << "\nActual: " << date6.GetDate() << endl << endl;

	cout << "\nTesting Validation Formula";
	UUDate date7("2/12/0");
	cout << "\nExpected: 01/01/2000";
	cout << "\nActual: " << date7.GetDate() << endl << endl;

	cout << "\nTesting Validation Formula";
	UUDate date8("29/2/1996");
	cout << "\nExpected: 29/02/1996";
	cout << "\nActual: " << date8.GetDate() << endl << endl;

	cout << "\nTesting Validation Formula";
	UUDate date9("29/2/1997");
	cout << "\nExpected: 01/01/2000";
	cout << "\nActual: " << date9.GetDate() << endl << endl;
	//TODO - Add your test code here

	//Remember to test your code thoroughly before running it against the tests in github.

	return 0;
}