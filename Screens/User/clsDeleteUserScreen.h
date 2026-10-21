#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsBankUsers.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:

	static void _print(clsBankUsers& User) {
		cout << "\n\n----------------------" << endl;
		cout << "\tClient Card" << endl;
		cout << "----------------------" << endl;
		cout << "First Name  : " << User.FirstName << endl;
		cout << "Last Name   : " << User.LastName << endl;
		cout << "Full Name   : " << User.FullName() << endl;
		cout << "Email       : " << User.Email << endl;
		cout << "Phone       : " << User.Phone << endl;
		cout << "User Name   : " << User.getUserName() << endl;
		cout << "Passowrd    : " << User.Password << endl;
		cout << "Permissions : " << User.Permissions << endl;
		cout << "----------------------" << endl;
	}

public:

	static void ShowDeleteUserScreen() {

		_DrawScreenHeader("\t\tDelete User Screen");

		string UserName = "";
		cout << "Enter a User Name : ";
		UserName = clsInputValidate::ReadString();

		while (!(clsBankUsers::IsUserExist(UserName))) {
			cout << "User Name is Not Found,, choose another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsBankUsers User = clsBankUsers::Find(UserName);

		
		if (UserName == "Admin") {
			cout << "\nYou can't delete Admin user . " << endl;
		}
		
		else {

			_print(User);

			cout << "Are you sure you want to delete this User [y/n] ? ";
			char Qu = 'n';
			cin >> Qu;

			if (Qu == 'y' || Qu == 'Y') {
				if (User.Delete()) {
					cout << "\nUser Deleted Successfully :-)\n";
				}
				else
					cout << "\nError User Was not Deleted\n";
			}
		}
	}
};

