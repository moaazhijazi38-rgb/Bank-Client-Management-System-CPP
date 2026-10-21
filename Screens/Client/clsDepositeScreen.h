#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsDepositeScreen : protected clsScreen
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

	static string _ReadAccuntNumber() {

		string AccountNumber = "";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:

	static void ShowDepositeScreen() {

		system("cls");
		string Header = "\t\t  Deposite Screen";
		_DrawScreenHeader(Header);

		string AccountNumber = "";
		cout << "Enter a Account Number : ";
		AccountNumber = _ReadAccuntNumber();

		while (!(clsBankClient::IsClientExist(AccountNumber))) {
			cout << "\nClient with [" << AccountNumber << "] does not found, Enter Account Number again : ";
			AccountNumber = _ReadAccuntNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_print(Client);

		double Amount = 0;
		cout << "\nplease enter depostie amount? ";
		Amount = clsInputValidate::ReadDbNumberBetween(0, 1000000000000, "Invalid Input, Enter again : ");

		cout << "\nAre you sure you want to Perform this Transactions [y/n] ? ";
		char Qu = 'n';
		cin >> Qu;

		if (Qu == 'y' || Qu == 'Y') {
			Client.Deposite(Amount);
			cout << "\nAmount Deposit Successfully :-)\n";
			cout << "New Balance is : " << Client.AccountBalance << "\n" << endl;
		}
		else 
			cout << "\nError Client Was not Deposit\n";
		}

};

