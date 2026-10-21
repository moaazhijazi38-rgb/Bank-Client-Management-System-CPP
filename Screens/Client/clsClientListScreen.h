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
using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

	static void _ClientRecord(clsBankClient Client) {
		cout << "\t|" << left << setw(17) << Client.FullName()
			<< "\t|" << left << setw(17) << Client.getEmail()
			<< "\t|" << left << setw(9) << Client.getPhone()
			<< "\t|" << left << setw(17) << Client.getAccountNumber()
			<< "\t|" << left << setw(7) << Client.getPinCode()
			<< "\t|" << left << setw(9) << Client.getAccountBalance() << endl;
	}

public:

	static void ShowAllClientsData() {

		if (!CheckAccessRights(clsBankUsers::enPermissions::pListClients)) {
			return;
		}

		vector<clsBankClient> vClients = clsBankClient::GetClientList();

		string Part1 = "\t\t Client List Screen ";
		string Part2 = "\t\t(" + to_string(vClients.size()) + ") Client(s) ";

		_DrawScreenHeader(Part1, Part2);
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;
		cout << "\t|" << left << setw(17) << "Full Name"
			<< "\t|" << left << setw(17) << "Email"
			<< "\t|" << left << setw(9) << "Phone"
			<< "\t|" << left << setw(17) << "Account Number"
			<< "\t|" << left << setw(7) << "Pin Code"
			<< "\t|" << left << setw(9) << "Account Balance" << endl;
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		if (vClients.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In The System!\n";

		}
		else {
			for (clsBankClient& Client : vClients) {
				_ClientRecord(Client);
			}
		}
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		system("pause>0");
	}

};

