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
class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientScreen() {

		if (!CheckAccessRights(clsBankUsers::enPermissions::pFindClient)) {
			return;
		}

		string Header = "\t\tFind Client Screen";

		_DrawScreenHeader(Header);

		string AccountNumber = "";
		cout << "Enter a Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber))) {
			cout << "Account number is not found, choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!(Client.isEmptyMode())) {
			cout << "\nClient Found :-)\n";
		}
		else
			cout << "\nClient Was Not Found :-(\n";

		_print(Client);

	}

};

