#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsUtil.h"
#include <ctime>
#include <string>
using namespace std;

class clsInputValidate
{

public:

	static bool IsNumberBetween(short Number, short FirstNumber, short LastNumber) {
		return (Number >= FirstNumber && Number <= LastNumber);
	}

	static bool IsNumberBetween(int Number, int FirstNumber, int LastNumber) {
		return (Number >= FirstNumber && Number <= LastNumber);
	}

	static bool IsNumberBetween(float Number, float FirstNumber, float LastNumber) {
		return (Number >= FirstNumber && Number <= LastNumber);
	}

	static bool IsNumberBetween(double Number, double FirstNumber, double LastNumber) {
		return (Number >= FirstNumber && Number <= LastNumber);
	}
	 
	static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2) {
		if(clsDate::isDate1AfterDate2(Date2, Date1))
		{
			return ((clsDate::isDate1BeforeDate2(Date, Date2) || clsDate::isDateEquelDate2(Date, Date2)) &&
				(clsDate::isDate1AfterDate2(Date, Date1) || clsDate::isDateEquelDate2(Date, Date1)));
		}
		else
		{
				clsUtil::Swap(Date1, Date2);
				return ((clsDate::isDate1BeforeDate2(Date, Date2) || clsDate::isDateEquelDate2(Date, Date2)) &&
					(clsDate::isDate1AfterDate2(Date, Date1) || clsDate::isDateEquelDate2(Date, Date1)));
		}
	}

	static string ReadString() {
		string Word = "";

		getline(cin >> ws, Word);
		return Word;
	}

	static char ReadChar(string message) {
		char Letter;

		cout << message;
		cin >> Letter;

		return Letter;
	}

	static int ReadIntNumber(string Message = "Invalid Number, Enter again : \n") {

		int number;

		while (!(cin >> number)) {
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << Message;
		}

		return number;
	}

	static int ReadIntNumberBetween(int first, int Last, string Message = "Number is not within range, Enter again : \n") {
		int x = ReadIntNumber();

		while (!(IsNumberBetween(x, first, Last))) {
			cout << Message;
			x = ReadIntNumber();
		}
		return x;
	}
	 
	static double ReadDbNumber(string Message = "Invalid Number, Enter again : \n") {

		double number;

		while (!(cin >> number)) {
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << Message;
		}

		return number;
	}

	static double ReadDbNumberBetween(double first, double Last, string Message = "Number is not within range, Enter again : \n") {
		double x = ReadDbNumber();

		while (!(IsNumberBetween(x, first, Last))) {
			cout << Message;
			x = ReadIntNumber();
		}
		return x;
	}

	static float ReadFlNumber(string Message = "Invalid Number, Enter again : \n") {

		float number;

		while (!(cin >> number)) {
			cin.clear();

			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << Message;
		}

		return number;
	}

	static bool IsValideDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

};

