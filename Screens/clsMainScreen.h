#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsersScreen.h"
#include "clsBankUsers.h"
#include "clsLoginRegisterScreen.h"
#include "clsShowCurrancyScreen.h"
#include "Global.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum _ChoiseScreenClientMainMenue {
        eShowClientsList = 1, eAddNewClient = 2,
        eDeleteClient = 3, eUdapteClientInfo = 4,
        eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLoginRegister = 8, eShowCurrancy = 9, eLogout = 10
    };

    static int _ReadMainMenue() {
        cout << setw(37) << "" << "Choose What do you want to do? [1 to 10]? ";
        int ChooseNumber = clsInputValidate::ReadIntNumberBetween(1, 10, "Invalid Number, Enter again : ");
        return ChooseNumber;
    } 

    static void _GoBackToMainMenue() {
        system("pause");
        ShowMainScreen();
    }

    static void _ShowAllClientsList() {
        clsClientListScreen::ShowAllClientsData();
    }

    static void _AddNewClient(){
        clsAddNewClientScreen::AddClient();
    }

    static void _DeleteClient() {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _UdapteClientInfo() {
        clsUpdateClientScreen::ShowUpdateClient();
    }

    static void _FindClient() {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _Transactions() {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ManageUsers() {
        clsMangeUsersScreen::ShowMangeUsersMenue();
    }

    static void _LoginRegister() {
        clsLoginRegisterScreen::ShowAllUserRegistersData();
    }

    static void _ShowCurrancyExchange() {
        clsShowCurrancyScreen::ShowCurrancyExchangeScreen();
    }

    static void _Logout() {

        CurrentUser = clsBankUsers::Find("", "");

    }

    static void _PerfromMainMenueOption(_ChoiseScreenClientMainMenue ChoiseScreen) {
        switch (ChoiseScreen) {
        case _ChoiseScreenClientMainMenue::eShowClientsList:
            system("cls");
            _ShowAllClientsList();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eAddNewClient:
            system("cls");
            _AddNewClient();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eDeleteClient:
            system("cls");
            _DeleteClient();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eUdapteClientInfo:
            system("cls");
            _UdapteClientInfo();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eFindClient:
            system("cls");
            _FindClient();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eTransactions:
            system("cls");
            _Transactions();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eManageUsers:
            system("cls");
            _ManageUsers();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eLoginRegister:
            system("cls");
            _LoginRegister();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eShowCurrancy:
            system("cls");
            _ShowCurrancyExchange();
            _GoBackToMainMenue();
            break;
        case _ChoiseScreenClientMainMenue::eLogout:
            system("cls");
            _Logout();
            break;
        }
    }

public :

	static void ShowMainScreen() { 
        system("cls");
		_DrawScreenHeader("\t\t     Main Screen");

		cout << setw(37) << "" << "==========================================" << endl;
		cout << setw(37) << "" << "\t\t     Main Menue" << endl;
		cout << setw(37) << "" << "==========================================" << endl;
        cout << setw(37) << "" << "  [1]: Show Clients List.              " << endl;
        cout << setw(37) << "" << "  [2]: Add New Client.                 " << endl;
        cout << setw(37) << "" << "  [3]: Delete Client.                  " << endl;
        cout << setw(37) << "" << "  [4]: Update Clien Info.              " << endl;
        cout << setw(37) << "" << "  [5]: Find Client.                    " << endl;
        cout << setw(37) << "" << "  [6]: Transactions.                   " << endl;
        cout << setw(37) << "" << "  [7]: Mangae Users.                   " << endl;
        cout << setw(37) << "" << "  [8]: Login Register.                 " << endl;
        cout << setw(37) << "" << "  [9]: Currency Exchange.                 " << endl;
        cout << setw(37) << "" << "  [10]: Logout.                         " << endl;
        cout << setw(37) << "" << "==========================================" << endl;

        _PerfromMainMenueOption((_ChoiseScreenClientMainMenue)_ReadMainMenue());
    }
};


