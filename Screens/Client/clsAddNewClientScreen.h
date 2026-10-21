#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private :

	static void _ReadClientInfo(clsBankClient& Client) {

		cout << "Enter a First Name : ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter a Last Name  : ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "Enter a Email      : ";
		Client.Email = clsInputValidate::ReadString();

		cout << "Enter a Phone      : ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter a Password   : ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter a Balance    : ";
		Client.AccountBalance = clsInputValidate::ReadDbNumber();

	}

	static void _print(clsBankClient& Client) {
		cout << "\n----------------------" << endl;
		cout << "\tClient Card" << endl;
		cout << "----------------------" << endl;
		cout << "First Name  : " << Client.FirstName << endl;
		cout << "Last Name   : " << Client.LastName << endl;
		cout << "Full Name   : " << Client.FullName() << endl;
		cout << "Email       : " << Client.Email << endl;
		cout << "Phone       : " << Client.Phone << endl;
		cout << "Acc. Number : " << Client.getAccountNumber() << endl;
		cout << "Pin Code    : " << Client.PinCode << endl;
		cout << "Balance     : " << Client.AccountBalance << endl;
		cout << "----------------------" << endl;
	}

public :

	static void AddClient() {

		if (!CheckAccessRights(clsBankUsers::enPermissions::pAddNewClient)) {
			return;
		}

		_DrawScreenHeader("\t\tAdd New Client Screen");

		string AccountNumber = "";
		cout << "Enter a Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while ((clsBankClient::IsClientExist(AccountNumber))) {
			cout << "Account number is Already Used, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResults;
		SaveResults = Client.Save();

		switch (SaveResults) {
		case clsBankClient::enSaveResults::svSucceeded:
			_print(Client);
			cout << "\nAccount Added Successfully :-)\n";
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\nError account was not saved because it's Empyt :-(\n";
			break;
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "Account number is Already Used. ";
		}

	}

};

