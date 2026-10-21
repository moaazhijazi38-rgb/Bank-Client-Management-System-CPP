#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsCurrencies.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen {

private:

	static float ReadNumber(string message) {
		float Amount = 0;
		cout << message;
		Amount = clsInputValidate::ReadFlNumber();

		return Amount;
	}

	static void _print(clsCurrencies& Currency, string title) {
		cout << "\n-------------------------" << endl;
		cout << "\t" << title << endl;
		cout << "-------------------------" << endl;
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate    : " << Currency.Rate() << endl;
		cout << "-------------------------" << endl;
	}

	static clsCurrencies _GetCurrency(string message) {

		string CurrencyCode = "";
		cout << message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!(clsCurrencies::IsCurrencyExist(CurrencyCode))) {
			cout << "Currency Code is not found, choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrencies::FindByCode(CurrencyCode);

	}

	static void _PrintCalculationsResults(float Amount, clsCurrencies CurrencyFrom, clsCurrencies CurrencyTo) {

		_print(CurrencyFrom, "  Convert From :");

		float FromCode1ToUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << FromCode1ToUSD << " USD" << endl;

		if (CurrencyTo.CurrencyCode() == "USD") {
			return;
		}

		_print(CurrencyTo, "Converting from USD to : ");

		float FromUSDToCode2 = CurrencyFrom.ConvertToOtherCurrency(CurrencyTo, Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << FromUSDToCode2 << " " << CurrencyTo.CurrencyCode() << endl;
	}

public:

	static void ShowCurrencyCalculatorScreen() {

		char Containue = 'y';

		while (Containue == 'Y' || Containue == 'y') {

			system("cls");

			string Header = "\t  Currency Calculator Screen";
			_DrawScreenHeader(Header);

			clsCurrencies Code1 = _GetCurrency("\nPlease Enter CurrencyCode1 : ");
			clsCurrencies Code2 = _GetCurrency("\nPlease Enter CurrencyCode2 : ");
			float Amount = ReadNumber("\nEnter Amount to Exchange: ");

			_PrintCalculationsResults(Amount, Code1, Code2);

			cout << "\nDo You Want again? [y/n]? ";
			cin >> Containue;
		}
	}
};