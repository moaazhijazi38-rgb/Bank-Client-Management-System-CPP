#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankUsers.h"
#include "clsDate.h"
#include "Global.h"
using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string ScreenPart1, string ScreenPart2= "") {
		cout << setw(39) << "" << "--------------------------------------" << endl;
		cout << setw(39) << "" << ScreenPart1 << endl;
		if (ScreenPart2 != "") {
			cout << setw(39) << "" << ScreenPart2 << endl;
		}
		cout << setw(39) << "" << "--------------------------------------" << endl;
		cout << setw(39) << "" << "User : " << CurrentUser.UserName << endl;
		cout << setw(39) << "" << clsDate::DateToString(clsDate()) << "\n" << endl;
	}

	static bool CheckAccessRights(clsBankUsers::enPermissions Permission) {
		if (!(CurrentUser.CheckAccessPermissions(Permission))) {
			cout << setw(39) << "" << "--------------------------------------" << endl;
			cout << setw(39) << "" << "  Access Denied! Contact your Admin." << endl;
			cout << setw(39) << "" << "--------------------------------------\n" << endl;

			return false;
		}
		return true;
	}

};

