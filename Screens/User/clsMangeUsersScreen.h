#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsMangeUsersScreen : protected clsScreen
{
private:

    enum _ChoiseScreenManageUsersMenue {
        eListUsers = 1, eAddNewUser = 2,
        eDeleteUser = 3, eUpdateUser = 4,
        eFindUser = 5 , eMainMenue = 6
    };

    static int _ReadMangeUsersMenue() {
        cout << setw(37) << "" << "Choose What do you want to do? [1 to 6]? ";
        int ChooseNumber = clsInputValidate::ReadIntNumberBetween(1, 6, "Invalid Number, Enter again : ");
        return ChooseNumber;
    }

    static void _GoBackToMangeUsersMenue() {
        system("pause");
        ShowMangeUsersMenue();
    }

    static void _ShowListUsersScreen() {
        clsListUsersScreen::ShowAllUsersData();
    }

    static void _ShowAddNewUserScreen() {
        clsAddNewUserScreen::AddUser();
    }

    static void _ShowDeleteUserScreen() {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen() {
        clsUpdateUserScreen::ShowUpdateUser();
    }

    static void _ShowFindUserScreen() {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerfromMangeUsersMenueOption(_ChoiseScreenManageUsersMenue PerfromMangeUsers) {
        switch (PerfromMangeUsers) {
        case _ChoiseScreenManageUsersMenue::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToMangeUsersMenue();
            break;
        case _ChoiseScreenManageUsersMenue::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        case _ChoiseScreenManageUsersMenue::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        case _ChoiseScreenManageUsersMenue::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        case _ChoiseScreenManageUsersMenue::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToMangeUsersMenue();
            break;
        case _ChoiseScreenManageUsersMenue::eMainMenue:
            break;

        }
    }

public :

    static void ShowMangeUsersMenue() {

        if (!CheckAccessRights(clsBankUsers::enPermissions::pManageUsers)) {
            return;
        }

        system("cls");
        string Header = "\t\tTransactions Screen";
        _DrawScreenHeader(Header);
        cout << setw(37) << "" << "==========================================" << endl;
        cout << setw(37) << "" << "\t\t Mange Users Menue" << endl;
        cout << setw(37) << "" << "==========================================" << endl;
        cout << setw(37) << "" << "  [1]: List Users.                           " << endl;
        cout << setw(37) << "" << "  [2]: Add New User.                          " << endl;
        cout << setw(37) << "" << "  [3]: Delete User.                    " << endl;
        cout << setw(37) << "" << "  [4]: Update User.                    " << endl;
        cout << setw(37) << "" << "  [5]: Find User.                    " << endl;
        cout << setw(37) << "" << "  [6]: Main Menue.                        " << endl;
        cout << setw(37) << "" << "==========================================" << endl;


        _PerfromMangeUsersMenueOption((_ChoiseScreenManageUsersMenue)_ReadMangeUsersMenue());
    }

};

