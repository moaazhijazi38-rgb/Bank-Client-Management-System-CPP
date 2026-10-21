#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsCurrencies
{
private :

	enum _eMode { EmptyMode = 0, UpdateMode = 1};

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	_eMode _Mode;

	static clsCurrencies _ConvertLineToCurrencies(string Line, string separator = "#//#") {

		vector<string> vClientData;
		vClientData = clsString::Split(Line, separator);

		return clsCurrencies(_eMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], stof(vClientData[3]));

	}

	static string _ConvertCurrenciesToLine(clsCurrencies Currency, string separator = "#//#") {

		string str = "";
		str += Currency._Country + separator;
		str += Currency._CurrencyCode + separator;
		str += Currency._CurrencyName + separator;
		str += to_string(Currency._Rate);
		
		return str;
	}

	static clsCurrencies _GetEmptyCurrenciesObject() {
		return clsCurrencies(_eMode::EmptyMode, "", "", "", 0);
	}

	static vector<clsCurrencies> _LoadCurrenciesDataFromFile(string separator = "#//#") {
		vector<clsCurrencies> vClients;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsCurrencies Client = _ConvertLineToCurrencies(Line, separator);
					vClients.push_back(Client);
				}
			}
			MyFile.close();
		}
		return vClients;
	}

	void _SaveCurrenciesDataToFile(vector<clsCurrencies>& vCurrencies) {
		fstream MyFile;
		string str = "";

		MyFile.open("Currencies.txt", ios::out);
		if (MyFile.is_open()) {
			for (clsCurrencies& S : vCurrencies) {
					str = _ConvertCurrenciesToLine(S, "#//#");
					MyFile << str << endl;
				
			}
			MyFile.close();
		}
	}

	 void _Update() {

		vector<clsCurrencies> vCurrencies = _LoadCurrenciesDataFromFile("#//#");

		for (clsCurrencies& C : vCurrencies) {
			if (C._CurrencyCode == _CurrencyCode) {
				C = *this;
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);
	}

	 static clsCurrencies _GetEmptyCurrencyObject() {
		 return clsCurrencies(_eMode::EmptyMode, "", "", "", 0);
	 }
	 

public :

	clsCurrencies(_eMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}

	float Rate() {
		return _Rate;
	}

	static clsCurrencies FindByCode(string CurrencyCode) {

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsCurrencies Currency = _ConvertLineToCurrencies(Line, "#//#");
					if (Currency._CurrencyCode == clsString::UpperAllString(CurrencyCode)) {
						MyFile.close();
						return Currency;
					}
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrencies FindByCountry(string Country) {

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsCurrencies Currency = _ConvertLineToCurrencies(Line, "#//#");
					if (clsString::LowerAllString(Currency._Country) == clsString::LowerAllString(Country)) {
						MyFile.close();
						return Currency;
					}
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	bool IsEmpty() {
		return (_Mode == _eMode::EmptyMode); 
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrencies Currency = clsCurrencies::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

	static bool IsCountryExist(string CountryCode)
	{
		clsCurrencies Currency = clsCurrencies::FindByCountry(CountryCode);
		return (!Currency.IsEmpty());
	}

	static vector<clsCurrencies> GetCurrenciesList(string separator = "#//#") {
		return _LoadCurrenciesDataFromFile(separator);
	}

	float ConvertToUSD(float Amount){
		return float(Amount / Rate());
	}

	float ConvertToOtherCurrency(clsCurrencies CurrencyCode, float Amount) {
		float AmountInUSD = ConvertToUSD(Amount);

		if (CurrencyCode.CurrencyCode() == "USD") {
			return ConvertToUSD(Amount);
		}
		return float(CurrencyCode.Rate() * AmountInUSD);

	}
};

