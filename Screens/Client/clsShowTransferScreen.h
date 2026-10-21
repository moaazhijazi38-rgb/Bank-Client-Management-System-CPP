#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsShowTransferScreen : protected clsScreen
{
private :

	static void _Print(clsBankClient Client) {
		cout << "\n-------------------------" << endl;
		cout << "         Client Card       " << endl;
		cout << "---------------------------" << endl;
		cout << "Full Name   : " << Client.FullName() << endl;
		cout << "Acc. Numebr : " << Client.getAccountNumber() << endl;
		cout << "Balance     : " << Client.AccountBalance << endl;
		cout << "---------------------------\n" << endl;
	}

public :


	static void ShowTransferScreen() {

		_DrawScreenHeader("\t\tTransfer Screen");

		string AccNumber1;
		cout << "\nPlease Enter Account Number to Transfer From : ";
		AccNumber1 = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccNumber1))) {
			cout << "Account number is Not Found, choose another one : ";
			AccNumber1 = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccNumber1);
		_Print(Client1);

		string AccNumber2;
		cout << "\nPlease Enter Account Number to Transfer To : ";
		AccNumber2 = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccNumber2))) {
			cout << "Account number is Not Found, choose another one : ";
			AccNumber2 = clsInputValidate::ReadString();
		}
		clsBankClient Client2 = clsBankClient::Find(AccNumber2);
		_Print(Client2);

		double BalanceTransfer;

		cout << "Enter Transfer Amount? ";
		cin >> BalanceTransfer;

		cout << "\nAre You sure you want to perform this Transaction? [y/n]? ";
		char Answer;
		cin >> Answer;


		if (Answer == 'y' || Answer == 'Y') {
			while (!Client1.Transfer(BalanceTransfer, Client2)) {
				cout << "Amount Exceeds the available Balance, Enter Transfer Amount? ";
				cin >> BalanceTransfer;
			}
			cout << "\nTransfer done Successfully . " << endl;
			_Print(Client1);
			_Print(Client2);

		}
		else
			cout << "Thank You." << endl;

	}

};

