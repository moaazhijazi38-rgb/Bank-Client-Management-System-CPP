#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:

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

	static void ShowDeleteClientScreen() {

		if (!CheckAccessRights(clsBankUsers::enPermissions::pDeleteClient)) {
			return;
		}

		_DrawScreenHeader("\t\tDelete Client Screen");

		string AccountNumber = "";
		cout << "Enter a Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber))) {
			cout << "Account number is Not Found,, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_print(Client);

		cout << "Are you sure you want to delete this client [y/n] ? ";
		char Qu = 'n';
		cin >> Qu;

		if (Qu == 'y' || Qu == 'Y') {
			if (Client.Delete()) {
				cout << "\nAccount Deleted Successfully :-)\n";
			}
			else
				cout << "\nError Client Was not Deleted\n";
		}
	}

};

