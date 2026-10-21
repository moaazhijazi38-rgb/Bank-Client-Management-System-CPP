
#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;

class clsShowTotalBalancesScreen : protected clsScreen
{ 
private:

	static void _ClientBalance(clsBankClient Client) {
		cout << setw(25) << "" << "|" << left << setw(20) << Client.FullName()
						<< "|" << left << setw(20) << Client.getAccountNumber()
						<< "|" << left << setw(20) << Client.getAccountBalance() << endl;
	}

public :
	

	static void ShowAllClientsBalances() {

		system("cls");	
		string Header = "\t\tTotal Balances Screen";
		_DrawScreenHeader(Header);

		vector<clsBankClient> vClients = clsBankClient::GetClientList();
		cout << setw(23) << "" << "_________________________________________________________________________________\n" << endl;
		cout << setw(25) << "" << "\t\t\tBalnces List (" << vClients.size() << ") Client(s).                               \n";
		cout << setw(23) << "" << "_________________________________________________________________________________\n" << endl;
		cout << setw(25) << "" << "|" << left << setw(20) << "Full Name"
						 << "|" << left << setw(20) << "Account Number"
						 << "|" << left << setw(20) << "Account Balance" << endl;
		cout << setw(23) << "" << "_________________________________________________________________________________\n" << endl;

		if (vClients.size() == 0) {
			cout << setw(25) << "\t\tNo Clients Available In The System!\n";

		}
		else {
			for (clsBankClient& Client : vClients) {
				_ClientBalance(Client);
			}
		}
		cout << setw(23) << "" << "_________________________________________________________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalnces();
		cout << setw(25) << "" << "|Total Balances : " << TotalBalances;
		cout << " ( " << clsUtil::NumberToText(TotalBalances) << "). \n" << endl;
	}

};

