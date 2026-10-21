#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "clsString.h"
#include "clsCurrencies.h"
#include "clsScreen.h"
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _CurrencyRecord(clsCurrencies Currency) {
		cout << "\t|" << left << setw(30) << Currency.Country()
			<< "\t|" << left << setw(10) << Currency.CurrencyCode()
			<< "\t|" << left << setw(40) << Currency.CurrencyName()
			<< "\t|" << left << setw(10) << Currency.Rate() << endl;;
	}

public:

	static void ShowAllClientsData() {

		vector<clsCurrencies> vCurrency = clsCurrencies::GetCurrenciesList();

		string Part1 = "\t\t Currencies List Screen ";
		string Part2 = "\t\t(" + to_string(vCurrency.size()) + ") Currency(s) ";

		_DrawScreenHeader(Part1, Part2);
		cout << "\n\t_________________________________________________________________________________________________________________________\n" << endl;
		cout << "\t|" << left << setw(30) << "Country"
			<< "\t|" << left << setw(10) << "Code"
			<< "\t|" << left << setw(40) << "Name"
			<< "\t|" << left << setw(10) << "Rate / ( 1$ )" << endl;
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		if (vCurrency.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In The System!\n";

		}
		else {
			for (clsCurrencies& Currency : vCurrency) {
				_CurrencyRecord(Currency);
			}
		}
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		system("pause>0");
	}

};

