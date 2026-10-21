#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h""
#include "clsScreen.h"
#include "clsCurrencies.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{

	static void _print(clsCurrencies& Curreny) {
		cout << "\n\n---------------------" << endl;
		cout << "     Curreny Card      " << endl;
		cout << "---------------------" << endl;
		cout << "Country : " << Curreny.Country() << endl;
		cout << "Code    : " << Curreny.CurrencyCode() << endl;
		cout << "Name    : " << Curreny.CurrencyName() << endl;
		cout << "Rate    : " << Curreny.Rate() << endl;
		cout << "-------------------------" << endl;
	}

	static void _ShowResults(clsCurrencies& Curreny){
		if (!(Curreny.IsEmpty())) {
			cout << "\Curreny Found :-)\n";
			_print(Curreny);
		}
		else
			cout << "\Curreny Was Empty :-(\n";

		_print(Curreny);
	}

public:

	static void ShowFindCurrencyScreen() {

		string Header = "\t\tFind Currency Screen";
		_DrawScreenHeader(Header);

		cout << "\nFind By: [1] Code or [2] Country? ";
		int ChooseNumber = clsInputValidate::ReadIntNumberBetween(1, 2, "Invalid Number, Enter again : ");

		if (ChooseNumber == 1) {

			string CurrencyCode = "";
			cout << "Enter a Currency Code : ";
			CurrencyCode = clsInputValidate::ReadString();

			while (!(clsCurrencies::IsCurrencyExist(CurrencyCode))) {
				cout << "Currency Code is not found, choose another one : ";
				CurrencyCode = clsInputValidate::ReadString();
			}

			clsCurrencies Curreny = clsCurrencies::FindByCode(CurrencyCode);

			_ShowResults(Curreny);

		}

		else if (ChooseNumber == 2) {

			string CountryName = "";
			cout << "Enter a Country Name : ";
			CountryName = clsInputValidate::ReadString();

			while (!(clsCurrencies::IsCountryExist(CountryName))) {
				cout << "Country Name is not found, choose another one : ";
				CountryName = clsInputValidate::ReadString();
			}

			clsCurrencies Curreny = clsCurrencies::FindByCountry(CountryName);

			_ShowResults(Curreny);

		}


		
		

	}

};

