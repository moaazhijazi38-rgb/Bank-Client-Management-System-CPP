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

class clsFindUserScreen : protected clsScreen
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

	static void ShowFindUserScreen() {

		string Header = "\t\tFind User Screen";

		_DrawScreenHeader(Header);

		string UserName = "";
		cout << "Enter a User Name : ";
		UserName = clsInputValidate::ReadString();

		while (!(clsBankUsers::IsUserExist(UserName))) {
			cout << "User Name is not found, choose another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsBankUsers User = clsBankUsers::Find(UserName);

		if (!(User.isEmptyMode())) {
			cout << "\nAccount User Found :-)\n";
		}
		else
			cout << "\nAccount User Was Not Found :-(\n";

		_print(User);

	}

};

