#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"
#include "clsBankUsers.h"
#include "clsScreen.h"
using namespace std;

class clsListUsersScreen : protected clsScreen
{
private:

	static void _UserRecord(clsBankUsers Client) {
		cout << "\t|" << left << setw(12) << Client.getUserName()
			<< "\t|" << left << setw(12) << Client.FullName()
			<< "\t|" << left << setw(9) << Client.getPhone()
			<< "\t|" << left << setw(30) << Client.Email
			<< "\t|" << left << setw(12) << Client.Password
			<< "\t|" << left << setw(9) << Client.Permissions << endl;
	}

public :

	static void ShowAllUsersData() {
		system("cls");
		vector<clsBankUsers> vUsers = clsBankUsers::GetUserList();

		string Part1 = "\t\t    Users List Screen ";
		string Part2 = "\t\t(" + to_string(vUsers.size()) + ") User(s) ";

		_DrawScreenHeader(Part1, Part2);
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;
		cout << "\t|" << left << setw(12) << "User Name"
			<< "\t|" << left << setw(12) << "Full Name"
			<< "\t|" << left << setw(9) << "Phone"
			<< "\t|" << left << setw(30) << "Email"
			<< "\t|" << left << setw(12) << "Password"
			<< "\t|" << left << setw(9) << "Permissions" << endl;
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		if (vUsers.size() == 0) {
			cout << "\t\t\t\t\t   No Users Available In The System!\n";

		}
		else {
			for (clsBankUsers& User : vUsers) {
				_UserRecord(User);
			}
		}
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		system("pause>0");
	}

};


