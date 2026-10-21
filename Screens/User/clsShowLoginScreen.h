#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankUsers.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

class clsShowLoginScreen : clsScreen
{
private:

	static void _Login() {
		bool loginFaild = false;
		int count = 0;

		do {
			if (loginFaild) {
				cout << "\nInvlaid UserName/Password!" << endl;
				count++;
				cout << "You Have " << 3 - count << " Trials(s) to login. \n" << endl;

				if (count == 3) {
					cout << "Your are Locked after 3 faild trails." << endl;
					return exit(0);
				}
			}

			cout << "Enter Username? ";
			string Username = clsInputValidate::ReadString();

			cout << "Enter Password? ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsBankUsers::Find(Username, Password);

			loginFaild = CurrentUser.isEmptyMode();

		} while (loginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainScreen();
	}

public :

	static void ShowLoginScreen() {
		system("cls");
		string Header = "\t\t     Login Screen";

		_DrawScreenHeader(Header);
		_Login();
	}

};

