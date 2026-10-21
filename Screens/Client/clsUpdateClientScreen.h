#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
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
		cout << "Passowrd    : " << Client.PinCode << endl;
		cout << "Balance     : " << Client.AccountBalance << endl;
		cout << "----------------------" << endl;
	}

public :

	static void ShowUpdateClient() {

		if (!CheckAccessRights(clsBankUsers::enPermissions::pUpdateClients)) {
			return;
		}

		string Header = "\t\tUpdated Client Screen";

		_DrawScreenHeader(Header);

		string AccountNumber = "";

		cout << "Please Enter the Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber))) {
			cout << "Account number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		_print(Client);

		cout << "Are you sure you want to Update this client [y/n] ? ";

		char Qu = 'n';
		cin >> Qu;

		if (Qu == 'y' || Qu == 'Y') {

			_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResults;
			SaveResults = Client.Save();

			switch (SaveResults) {
			case clsBankClient::enSaveResults::svSucceeded:
				cout << "\nAccount Updated Successfully :-)\n";
				break;
			case clsBankClient::enSaveResults::svFaildEmptyObject:
				cout << "\nError account was not saved because it's Empyt :-(\n";
				break;
			}
		}
		else 
			cout << "\nError Client Was not Updated\n";

	}

};

