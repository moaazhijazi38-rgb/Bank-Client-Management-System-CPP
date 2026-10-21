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

class clsUpdateUserScreen : protected clsScreen
{
private:

	static int _ReadPermissionsInfo() {

		int Permissions = 0;

		char Question = clsInputValidate::ReadChar("\nDo You want to give full access? [y/n] ?  ");

		if (Question == 'y' || Question == 'Y') {
			Permissions = -1;
			return Permissions;
		}
		else if (Question == 'n' || Question == 'N') {


			cout << "\nOk, Do you want to give access to : " << endl;

			Question = clsInputValidate::ReadChar("Show Clients List? [y/n]? ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pListClients;

			Question = clsInputValidate::ReadChar("Add New Client? [y/n]? ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pAddNewClient;

			Question = clsInputValidate::ReadChar("Delete Client? [y/n]? ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pDeleteClient;

			Question = clsInputValidate::ReadChar("Update Client Info ? [y / n] ? ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pUpdateClients;

			Question = clsInputValidate::ReadChar("Find Client? [y/n]? ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pFindClient;

			Question = clsInputValidate::ReadChar("Transactions? [y/n]? ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pTranactions;

			Question = clsInputValidate::ReadChar("Mangae Users? [y/n]?  ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pManageUsers;

			Question = clsInputValidate::ReadChar("Show Login Register? [y/n]?  ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pUserRegister;

			Question = clsInputValidate::ReadChar("Show Currency Exchange? [y/n]?  ");
			if (Question == 'y' || Question == 'Y')
				Permissions += clsBankUsers::enPermissions::pCurrency;
		}
		return Permissions;
	}

	static void _ReadUserInfo(clsBankUsers& User) {

		cout << "Enter a First Name : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter a Last Name  : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter a Email      : ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter a Phone      : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter a Password   : ";
		User.Password = clsInputValidate::ReadString();

		User.Permissions = _ReadPermissionsInfo();
	}

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

	static void ShowUpdateUser() {

		string Header = "\t\tUpdated User Screen";

		_DrawScreenHeader(Header);

		string UserName = "";

		cout << "Please Enter the User Name : ";
		UserName = clsInputValidate::ReadString();

		while (!(clsBankUsers::IsUserExist(UserName))) {
			cout << "User Name is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsBankUsers User = clsBankUsers::Find(UserName);


		if (UserName == "Admin") {
			cout << "\nYou can't delete Admin user . " << endl;
		}

		else {

			_print(User);

			cout << "Are you sure you want to Update this User [y/n] ? ";

			char Qu = 'n';
			cin >> Qu;

			if (Qu == 'y' || Qu == 'Y') {

				_ReadUserInfo(User);

				clsBankUsers::enSaveResults SaveResults;
				SaveResults = User.Save();

				switch (SaveResults) {
				case clsBankUsers::enSaveResults::svSucceeded:
					cout << "\nAccount User Updated Successfully :-)\n";
					break;
				case clsBankUsers::enSaveResults::svFaildEmptyObject:
					cout << "\nError Account User was not saved because it's Empyt :-(\n";
					break;
				}
			}
			else
				cout << "\nError User Was not Updated\n";
		}

	}
};

