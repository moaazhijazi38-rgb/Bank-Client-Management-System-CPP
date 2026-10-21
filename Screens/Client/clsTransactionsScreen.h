#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsShowTotalBalancesScreen.h"
#include "clsShowTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
    enum _ChoiseScreenClientTransactios { eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eTransferLog = 5, eMainMenue = 6 };

    static int _ReadTransactiosMenue() {
        cout << setw(37) << "" << "Choose What do you want to do? [1 to 6]? ";
        int ChooseNumber = clsInputValidate::ReadIntNumberBetween(1, 6, "Invalid Number, Enter again : ");
        return ChooseNumber;
    }

    static void _GoBackToTransactiosenue() {
        system("pause");
        ShowTransactionsMenue();
    }

    static void _ShowDepositScreen() {
        clsDepositeScreen::ShowDepositeScreen();
    }

    static void _ShowWithdrawScreen() {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen() {
        clsShowTotalBalancesScreen::ShowAllClientsBalances();
    }

    static void _ShowTransferScreen() {
        clsShowTransferScreen::ShowTransferScreen();
    }

    static void _ShowRtansferLogScreen() {
        clsTransferLogScreen::ShowAllTransferLogData();
    }

    static void _PerfromTransactiosMenueOption(_ChoiseScreenClientTransactios PerfromTransactios) {
        switch (PerfromTransactios) {
        case _ChoiseScreenClientTransactios::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactiosenue();
            break;
        case _ChoiseScreenClientTransactios::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactiosenue();
            break;
        case _ChoiseScreenClientTransactios::eTotalBalances:
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactiosenue();
            break;
        case _ChoiseScreenClientTransactios::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactiosenue();
            break;
        case _ChoiseScreenClientTransactios::eTransferLog:
            system("cls");
            _ShowRtansferLogScreen();
            _GoBackToTransactiosenue();
            break;
        case _ChoiseScreenClientTransactios::eMainMenue:
            break;
        }
    }

public:

	static void ShowTransactionsMenue() {

        if (!CheckAccessRights(clsBankUsers::enPermissions::pTranactions)) {
            return;
        }

        system("cls");
		string Header = "\t\tTransactions Screen";
        _DrawScreenHeader(Header);
        cout << setw(37) << "" << "==========================================" << endl;
        cout << setw(37) << "" << "\t\t Transactions Menue" << endl;
        cout << setw(37) << "" << "==========================================" << endl;
        cout << setw(37) << "" << "  [1]: Deposit.                           " << endl;
        cout << setw(37) << "" << "  [2]: Withdraw.                          " << endl;
        cout << setw(37) << "" << "  [3]: Total Balances.                    " << endl;
        cout << setw(37) << "" << "  [4]: Transfer.                          " << endl;
        cout << setw(37) << "" << "  [5]: Transfer Log.                        " << endl;
        cout << setw(37) << "" << "  [6]: Main Menue.                        " << endl;
        cout << setw(37) << "" << "==========================================" << endl;


        _PerfromTransactiosMenueOption((_ChoiseScreenClientTransactios)_ReadTransactiosMenue());
	}
};

