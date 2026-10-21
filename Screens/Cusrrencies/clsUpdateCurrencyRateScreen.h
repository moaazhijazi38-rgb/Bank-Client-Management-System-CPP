#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsCurrencies.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{

	static void _print(clsCurrencies& Curreny) {
		cout << "\n\n---------------------" << endl;
		cout << "     Currency Card      " << endl;
		cout << "---------------------" << endl;
		cout << "Country : " << Curreny.Country() << endl;
		cout << "Code    : " << Curreny.CurrencyCode() << endl;
		cout << "Name    : " << Curreny.CurrencyName() << endl;
		cout << "Rate    : " << Curreny.Rate() << endl;
		cout << "-------------------------" << endl;
	}

	static bool _ShowResults(clsCurrencies& Curreny) {
		if (!(Curreny.IsEmpty())) {
			_print(Curreny);
			return true;
		}
		else
			cout << "\nCurreny Was Empty :-(\n";

		return false;
	}

public:

	static void ShowUpdateCurrencyRateScreen() {

		string Header = "\t\tUpdate Currency Rate Screen";
		_DrawScreenHeader(Header);

		string CurrencyCode = ""; 
		cout << "Please Enter a Currency Code : ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!(clsCurrencies::IsCurrencyExist(CurrencyCode))) {
			cout << "Currency Code is not found, choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrencies Currency = clsCurrencies::FindByCode(CurrencyCode);

		if(_ShowResults(Currency)) {

			cout << "Are You sure you want to update the rate of this Currency [y/n] ? ";
			char Answer;
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y') {

				cout << "\nEnter New Rate : ";
				float NewRate = clsInputValidate::ReadFlNumber();
				
				cout << "\nCurrency Rate Updated Successfully :-)\n";
				Currency.UpdateRate(NewRate);
				_ShowResults(Currency);
			}
		}



	}
};

