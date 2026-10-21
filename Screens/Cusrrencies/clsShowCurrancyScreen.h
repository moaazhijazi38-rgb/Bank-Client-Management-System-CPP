#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsShowCurrancyScreen : protected clsScreen
{
private :
    enum _ChoiseScreenCurrancyExchange {eList = 1 , eFind = 2 , eUpdate = 3 , eCalculator = 4 , eMainMenue = 5 };

    static int _ReadMainMenue() {
        cout << setw(37) << "" << "Choose What do you want to do? [1 to 5]? ";
        int ChooseNumber = clsInputValidate::ReadIntNumberBetween(1, 5, "Invalid Number, Enter again : ");
        return ChooseNumber;
    }

    static void _GoBackToCurrancyExchangeMenue() {
        system("pause");
        ShowCurrancyExchangeScreen();
    }

    static void _ShowListCurranciesScreen() {
        clsCurrenciesListScreen::ShowAllClientsData();
    }

    static void _ShowFindCurranciesScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurranciesScreen() {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCalculatorCurranciesScreen(){
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerfromCurrancyExchangeMenueOption(_ChoiseScreenCurrancyExchange ChoiseScreen) {
        switch (ChoiseScreen) {
        case _ChoiseScreenCurrancyExchange::eList:
            system("cls");
            _ShowListCurranciesScreen();
            _GoBackToCurrancyExchangeMenue();
            break;
        case _ChoiseScreenCurrancyExchange::eFind :
            system("cls");
            _ShowFindCurranciesScreen();
            _GoBackToCurrancyExchangeMenue();
            break;
        case _ChoiseScreenCurrancyExchange::eUpdate:
            system("cls");
            _ShowUpdateCurranciesScreen();
            _GoBackToCurrancyExchangeMenue();
            break;
        case _ChoiseScreenCurrancyExchange::eCalculator:
            system("cls");
            _ShowCalculatorCurranciesScreen();
            _GoBackToCurrancyExchangeMenue();
            break;
        case _ChoiseScreenCurrancyExchange::eMainMenue:
 
            break;
        }
    }

public:

    static void ShowCurrancyExchangeScreen() {

        if (!CheckAccessRights(clsBankUsers::enPermissions::pCurrency)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tCurrancy Exchange Main Screen");

        cout << setw(37) << "" << "==========================================" << endl;
        cout << setw(37) << "" << "           Currancy Exchange Menue        " << endl;
        cout << setw(37) << "" << "==========================================" << endl;
        cout << setw(37) << "" << "  [1]: List Currancies.              " << endl;
        cout << setw(37) << "" << "  [2]: Find Currancy.                 " << endl;
        cout << setw(37) << "" << "  [3]: Update Rate.                  " << endl;
        cout << setw(37) << "" << "  [4]: Currancy Calculator.              " << endl;
        cout << setw(37) << "" << "  [5]: Main Menue.                    " << endl;
        cout << setw(37) << "" << "==========================================" << endl;

        _PerfromCurrancyExchangeMenueOption((_ChoiseScreenCurrancyExchange)_ReadMainMenue());
    }

};

