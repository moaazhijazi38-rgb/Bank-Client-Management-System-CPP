#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib> 

using namespace std;


const string File = "MyFile.text";

enum enChoiseScreenClientMainMenue {
    eQuickWithdraw = 1, eNormalWithdraw = 2,
    eDeposit = 3, eCheckBalance = 4, eLogout = 5
};

struct stData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0;
};

string AccountNumberStr;
stData ConstData;

string ReadString(string message) {
    string text;
    cout << message;

    getline(cin >> ws, text);
    return text;
}

vector<string> SplitString(string text, string delimiter) {
    vector <string> vSplit;
    int pos = 0;
    string sWord;
    while ((pos = text.find(delimiter)) != std::string::npos) {
        sWord = text.substr(0, pos);
        if (sWord != "") vSplit.push_back(sWord);
        text = text.erase(0, pos + delimiter.length());
    }
    if (text != "") vSplit.push_back(text);
    return vSplit;
}

string ConvertRecordToLine(stData Client, string separator) {
    return Client.AccountNumber + separator +
        Client.PinCode + separator +
        Client.Name + separator +
        Client.Phone + separator +
        to_string(Client.AccountBalance);
}

stData ConvertLineToRecord(string Line, string separator) {
    stData Client;
    vector<string> vClientData = SplitString(Line, separator);

    if (vClientData.size() >= 5) {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]);
    }
    return Client;
}

vector<stData> LoadClientsDataFromFile(string FileName, string separator) {
    vector<stData> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            if (!Line.empty()) {
                stData Client = ConvertLineToRecord(Line, separator);
                vClients.push_back(Client);
            }
        }
        MyFile.close();
    }
    return vClients;
}

int ChoiseQuickWithdraw() {

    int ChioseScreen;
    cout << "Choose What to Withdraw from [1] to [9] ? ";
    cin >> ChioseScreen;

    while (cin.fail() || ChioseScreen > 9 || ChioseScreen < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Enter a number [1 to 9]: ";
        cin >> ChioseScreen;
    }
    return ChioseScreen;
}

bool CheckBalance(int chooseScreen) {
    return(chooseScreen <= ConstData.AccountBalance);
}

int ValueToMinesFromConstData(int& chooseScreen) {

    switch (chooseScreen) {
    case 1:
        chooseScreen = 20;
        break;
    case 2:
        chooseScreen = 50;
        break;
    case 3:
        chooseScreen = 100;
        break;
    case 4:
        chooseScreen = 200;
        break;
    case 5:
        chooseScreen = 400;
        break;
    case 6:
        chooseScreen = 600;
        break;
    case 7:
        chooseScreen = 800;
        break;
    case 8:
        chooseScreen = 1000;
        break;
    }
    return chooseScreen;
}

void SaveFile() {
    vector<stData> Data;
    Data = LoadClientsDataFromFile(File, "#//#");

    for (stData& U : Data) {
        if (U.AccountNumber == AccountNumberStr) {
            U = ConstData;
        }
    }

    fstream MyFile;
    MyFile.open(File, ios::out);
    if (MyFile.is_open()) {
        for (stData& U : Data)
            MyFile << ConvertRecordToLine(U, "#//#") << endl;
        MyFile.close();
    }


}

void ProsseccesQuickWithdraw(int& chooseScreen) {
    if (!CheckBalance(ValueToMinesFromConstData(chooseScreen))) {
        cout << "You cannot withdraw money; please enter a number less than " << ConstData.AccountBalance << " . " << endl;
        return;
    }
    else
        ConstData.AccountBalance -= chooseScreen;
    SaveFile();
    cout << "\nWithdraw Successfully. \n" << endl;
}

void CheckWithDrawFormClient(int chooseScreen) {
    char Question;
    bool Questionfalse;

    while (true)
    {

        cout << "Are you Sure you want perform this transaction? [y/n] ? ";
        cin >> Question;

        if (Question == 'y' || Question == 'Y') {
            Questionfalse = true;
            ProsseccesQuickWithdraw(chooseScreen);
            break;
        }

        else if (Question == 'n' || Question == 'N') {
            Questionfalse = true;
            cout << "Ok. " << endl;
            break;
        }


        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input!";
    }

    system("pause");
}

void QuickWithdrawScreen() {
    int chooseScreen;

    do {
        system("cls");
        cout << "=====================================" << endl;
        cout << "         Quick Withdraw Screen       " << endl;
        cout << "=====================================" << endl;
        cout << "      [1]: 20        [2]: 50         " << endl;
        cout << "      [3]: 100       [4]: 200        " << endl;
        cout << "      [5]: 400       [6]: 600        " << endl;
        cout << "      [7]: 800       [8]: 1000       " << endl;
        cout << "      [9]: Exit.                     " << endl;
        cout << "=====================================" << endl;
        cout << "Your Balance is " << ConstData.AccountBalance << endl;

        chooseScreen = ChoiseQuickWithdraw();

        if (chooseScreen == 9) {
            break;
        }

        CheckWithDrawFormClient(chooseScreen);

    } while (true);

    system("pause");
}

void CheckBalanceScreen() {

    system("cls");
    cout << "=====================================" << endl;
    cout << "       Check Balance Screen          " << endl;
    cout << "=====================================" << endl;

    cout << "Your Balance is " << ConstData.AccountBalance << endl;

    system("pause");
}

bool CheckBalancePositive(int AccountBalance) {
    return (AccountBalance > 0);
}

int ChoiseNormalWithdraw() {

    int ChioseScreen;
    cin >> ChioseScreen;

    while (cin.fail() || ChioseScreen % 5 != 0 || !CheckBalancePositive(ChioseScreen)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Please enter a number that is a multiple of 5 : ";
        cin >> ChioseScreen;
    }
    return ChioseScreen;
}

void ProccessNormalWithdraw() {
    int AccountBalance;

    while (true) {
        cout << "Your Account Balance is " << ConstData.AccountBalance << ", Please enter a number that is a multiple of 5 : ";
        AccountBalance = ChoiseNormalWithdraw();

        if (CheckBalance(AccountBalance)) {
            ConstData.AccountBalance -= AccountBalance;
            SaveFile();
            break;
        }
    }
    cout << "\nWithdraw Successfully, Your Balance Now " << ConstData.AccountBalance << endl;
}

void NormalWithdrawScreen() {
    system("cls");
    cout << "===================================================" << endl;
    cout << "            Normal Withdraw Screen                " << endl;
    cout << "===================================================" << endl;
    ProccessNormalWithdraw();

    system("pause");
}

int ChoiseDeposit() {

    int ChioseScreen;
    cin >> ChioseScreen;

    while (cin.fail() || !CheckBalancePositive(ChioseScreen)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Please Try Again : ";
        cin >> ChioseScreen;
    }
    return ChioseScreen;
}

void ProccessDeposit() {
    int AccountBalance;

    while (true) {
        cout << "Your Account Balance is " << ConstData.AccountBalance << ", please enter the Deposit : ";
        AccountBalance = ChoiseDeposit();

        if (CheckBalancePositive(AccountBalance)) {
            ConstData.AccountBalance += AccountBalance;
            SaveFile();
            break;
        }
    }
    cout << "\nDeposit Successfully, Your Balance Now " << ConstData.AccountBalance << endl;
}

void DepositScreen() {
    system("cls");
    cout << "===================================================" << endl;
    cout << "                   Deposit Screen                 " << endl;
    cout << "===================================================" << endl;
    ProccessDeposit();

    system("pause");

}

void ChoiseTransactionsClientScreen(enChoiseScreenClientMainMenue choise) {
    switch (choise) {
    case enChoiseScreenClientMainMenue::eQuickWithdraw:
        QuickWithdrawScreen();
        break;
    case enChoiseScreenClientMainMenue::eCheckBalance:
        CheckBalanceScreen();
        break;
    case enChoiseScreenClientMainMenue::eNormalWithdraw:
        NormalWithdrawScreen();
        break;
    case enChoiseScreenClientMainMenue::eDeposit:
        DepositScreen();
        break;
    }
}

int ChoiseATMMainMenu() {

    int ChioseScreen;
    cout << "Choose What do you want to do [1] to [5] ? ";
    cin >> ChioseScreen;

    while (cin.fail() || ChioseScreen > 5 || ChioseScreen < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Enter a number [1 to 5]: ";
        cin >> ChioseScreen;
    }
    return ChioseScreen;
}

void ATMMainMenueScreen() {

    int ChioseScreen;

    do {
        system("cls");
        cout << "===================================================" << endl;
        cout << "              ATM Main Menu Screen             " << endl;
        cout << "      Hello " << ConstData.Name << " Welcome to our ATM. " << endl;
        cout << "===================================================" << endl;
        cout << "            [1]: Quick Withdraw.                " << endl;
        cout << "            [2]: Normal Withdraw.               " << endl;
        cout << "            [3]: Deposit.                      " << endl;
        cout << "            [4]: Check Balance.                 " << endl;
        cout << "            [5]: Logout.                        " << endl;
        cout << "===================================================" << endl;

        ChioseScreen = ChoiseATMMainMenu();

        if (ChioseScreen == 5) {
            break;
        }

        ChoiseTransactionsClientScreen((enChoiseScreenClientMainMenue)ChioseScreen);

    } while (true);
}

bool CheckLogin(string AccountNumber, string PinCode) {
    vector<stData> Data;
    Data = LoadClientsDataFromFile(File, "#//#");

    for (stData& U : Data) {
        if (U.AccountNumber == AccountNumber && U.PinCode == PinCode) {
            ConstData = U;
            return true;
        }
    }
    return false;
}

void LoginScreen() {

    string PinCode, AccountNumber;
    bool loginFailed = false;

    do {
        system("cls");

        cout << "================================================" << endl;
        cout << "                  Login Screen                  " << endl;
        cout << "================================================" << endl;

        if (loginFailed) {
            cout << "The password / Account is incorrect. " << endl;
        }

        AccountNumber = ReadString("Enter Account Number ? ");
        PinCode = ReadString("Enter Pincode? ");

        loginFailed = !CheckLogin(AccountNumber, PinCode);


    } while (loginFailed);

    AccountNumberStr = AccountNumber;
    ATMMainMenueScreen();

}

int main() {
    while (true)
        LoginScreen();

    return 0;
}
