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

class clsLoginRegisterScreen : protected clsScreen
{
private :

	static void _PrintUserRegisterRecord(clsBankUsers::stLoginRegisterRecord UserRegister) {
		cout << "\t|" << left << setw(30) << UserRegister.Date
			<< "\t|" << left << setw(20) << UserRegister.UserNameRegister
			<< "\t|" << left << setw(20) << UserRegister.PasswordRegister
			<< "\t|" << left << setw(20) << UserRegister.PermissisonRegister << endl;
	}


public :

	static void ShowAllUserRegistersData() {

		if (!CheckAccessRights(clsBankUsers::enPermissions::pUserRegister)) {
			return;
		}

		vector<clsBankUsers::stLoginRegisterRecord> vUsersRegister = clsBankUsers::GetLoginRegisterList();

		string Part1 = "\t      Login Register List Screen ";
		string Part2 = "\t\t(" + to_string(vUsersRegister.size()) + ") Record(s). ";

		_DrawScreenHeader(Part1, Part2);
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;
		cout << "\t|" << left << setw(30) << "Date/Time"
			<< "\t|" << left << setw(20) << "User Name"
			<< "\t|" << left << setw(20) << "Password"
			<< "\t|" << left << setw(20) << "Permission" << endl;
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		if (vUsersRegister.size() == 0) {
			cout << "\t\t\t\tNo User Register Available In The System!\n";

		}
		else {
			for (clsBankUsers::stLoginRegisterRecord& Register : vUsersRegister) {
				_PrintUserRegisterRecord(Register);
			}
		}
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		system("pause>0");
	}

};

