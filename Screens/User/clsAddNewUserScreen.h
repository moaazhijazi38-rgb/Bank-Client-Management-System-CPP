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

class clsAddNewUserScreen : protected clsScreen
{

private:

	static int _ReadPermissionsInfo() {

		int Permissions= 0;

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

	static void _print(clsBankUsers& User)  {
		cout << "\n\n----------------------" << endl;
		cout << "\tUser Card" << endl;
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

	static void AddUser() {

		_DrawScreenHeader("\t\tAdd New User Screen");

		string UserName = "";
		cout << "Enter a User Name : ";
		UserName = clsInputValidate::ReadString();

		while ((clsBankUsers::IsUserExist(UserName))) {
			cout << "Account number is Already Used, choose another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsBankUsers User = clsBankUsers::GetAddNewUserObject(UserName);

		_ReadUserInfo(User);

		clsBankUsers::enSaveResults SaveResults;
		SaveResults = User.Save();

		switch (SaveResults) {
		case clsBankUsers::enSaveResults::svSucceeded:
			_print(User);
			cout << "\nUser Added Successfully :-)\n";
			break;
		case clsBankUsers::enSaveResults::svFaildEmptyObject:
			cout << "\nError User was not saved because it's Empyt :-(\n";
			break;
		case clsBankUsers::enSaveResults::svFaildUserNameExists:
			cout << "User Name is Already Used. ";
		}

	}
};

