#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib> 

using namespace std;

const string File = "MyFile.text";
const string File2 = "Users.text";

struct stData;
vector<stData> LoadClientsDataFromFile(string separator);
void WithdrawClient(string AccountNumber, vector<stData>& vClients);
void MainMenu();
void LoginScreen();


enum ChoiseScreenClientMainMenue {
    eShowClientsList = 1, eAddNewClient = 2,
    eDeleteClient = 3, eUdapteClientInfo = 4,
    eFindClient = 5, eTransactions = 6, eManageUsers = 7, eExit = 8
};

enum ChoiseScreenClientTransactionsMenue {
    eDeposite = 1, eWithdraw = 2,
    eTotalBalances = 3, eMainMenue = 4
};

enum ChoiseScreenManageUsersMenue {
    eListUsers = 1, eAddNewUser = 2,
    eDeleteUser = 3, eUpdateUser = 4,
    eFindUser = 5
};

struct stData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance = 0;
    bool MarkForDelete = false;
};

struct stUsers {
    string UserName;
    string Passowrd;
    int Validity;
    bool MarkUserForDelete = false;
};

stUsers CurrentUser;

bool perminisonsCheckForUser(stUsers& User, int perminison) {
    if (User.Validity == -1) {
        return true;
    }
    if ((User.Validity & perminison) == perminison) {
        return true;
    }
    else 
        return false;
}

void MessageToStop() {
    system("cls");
    cout << "----------------------------------" << endl;
    cout << "Access Denied " << endl;
    cout << "You Dont Have perminison to this. " << endl;
    cout << "Please Conact Your Admin ." << endl;
    cout << "----------------------------------" << endl;
    system("pause");
    return;
}

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

bool FindClientByAccountNumber(string AccountNumber, vector<stData>& vClients) {

    for (stData C : vClients) {
        if (C.AccountNumber == AccountNumber)
            return true;
    }
    return false;
}

void ReadClientData(stData& Client, vector<stData>& vClients) {

    Client.AccountNumber = ReadString("Enter Account Number? ");

    while (FindClientByAccountNumber(Client.AccountNumber, vClients)) {
        cout << "Client With [" << Client.AccountNumber << "] Already exists, ";
        Client.AccountNumber = ReadString("Enter Account Number? ");
    }

    Client.PinCode = ReadString("Enter the PinCode? ");
    Client.Name = ReadString("Enter your Name? ");
    Client.Phone = ReadString("Enter your Phone? ");

    cout << "Enter the Account Balance? ";
    cin >> Client.AccountBalance;
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

void SaveLineToFile(string FileName, string LineData) {

    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << LineData << endl;
        MyFile.close();
    }
}

vector<stData> LoadClientsDataFromFile(string separator) {

    vector<stData> vClients;
    fstream MyFile;
    MyFile.open(File, ios::in);

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

void AddNewClientToFile(string separator) {

    stData Client;
    vector<stData> vClients = LoadClientsDataFromFile("#//#");
    ReadClientData(Client, vClients);

    string LineData = ConvertRecordToLine(Client, separator);
    SaveLineToFile(File, LineData);
}

void PrintClientRecord(stData Client) {

    cout << "|" << left << setw(20) << Client.AccountNumber
        << "|" << left << setw(20) << Client.PinCode
        << "|" << left << setw(20) << Client.Name
        << "|" << left << setw(20) << Client.Phone
        << "|" << left << setw(20) << Client.AccountBalance << endl;
}

void PrintAllClientsData() {

    if (!perminisonsCheckForUser(CurrentUser, 1)) {
        MessageToStop();
        return;
    }

        vector<stData> vClients = LoadClientsDataFromFile("#//#");

        system("cls");
        cout << "\n____________________________________________________________________________________________________\n" << endl;
        cout << "                                     Client List (" << vClients.size() << ") Client(s).                                \n";
        cout << "____________________________________________________________________________________________________\n" << endl;
        cout << "|" << left << setw(20) << "Account Number"
            << "|" << left << setw(20) << "PinCode"
            << "|" << left << setw(20) << "Client Name"
            << "|" << left << setw(20) << "Phone"
            << "|" << left << setw(20) << "Balance" << endl;
        cout << "____________________________________________________________________________________________________\n" << endl;

        for (stData& Client : vClients) {
            PrintClientRecord(Client);
        }
        cout << "____________________________________________________________________________________________________\n" << endl;


    
        
    system("pause");
}

void QuestionToAddedNewClients() {

    char Quieston = 'Y';

    do {
        AddNewClientToFile("#//#");
        cout << "\nClient Added Successfully, Do you want to add more Clients? [y/n]? ";
        cin >> Quieston;
        cout << endl;
    } while (Quieston == 'Y' || Quieston == 'y');
}

void AddNewClientScreen() {

    if (!perminisonsCheckForUser(CurrentUser, 2)) {
        MessageToStop();
        return;
    }

    system("cls");
    cout << "------------------------------------------------" << endl;
    cout << "             Add New Client Screen              " << endl;
    cout << "------------------------------------------------" << endl;

    QuestionToAddedNewClients();
    system("pause");
}

void PrintClient(string AccountNumber, vector<stData>& vClients) {

    for (stData& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            cout << "------------------------------------------------" << endl;
            cout << setw(20) << left << " Account Number " << ": " << C.AccountNumber << endl;
            cout << setw(20) << left << " Pin Code " << ": " << C.PinCode << endl;
            cout << setw(20) << left << " Name " << ": " << C.Name << endl;
            cout << setw(20) << left << " Phone " << ": " << C.Phone << endl;
            cout << setw(20) << left << " Account Balance " << ": " << C.AccountBalance << endl;
            cout << "------------------------------------------------" << endl;
            return;
        }
    }
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stData>& vClients) {

    for (stData& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

void SaveCleintsDataToFile(string FileName, vector<stData>& vClients) {

    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;

    if (MyFile.is_open()) {
        for (stData C : vClients) {
            if (C.MarkForDelete == false) {
                DataLine = ConvertRecordToLine(C, "#//#");
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
}

void QuestionToDeleteClient(vector<stData>& vClients) {

    char Question;
    cout << "\nAre you sure want delete this client? [y/n]? ";
    cin >> Question;

    if (Question == 'y' || Question == 'Y') {
        SaveCleintsDataToFile(File, vClients);
        cout << "Client Delete Successfully" << endl;
    }
    else if (Question == 'n' || Question == 'N') {
        cout << "OK. " << endl;
    }
    else {
        cout << "please enter the true char, ";
        QuestionToDeleteClient(vClients);
    }
}

void ProccesDeleteClient(string AccountNumber, vector<stData>& vClients) {
    if (MarkClientForDeleteByAccountNumber(AccountNumber, vClients)) {
        PrintClient(AccountNumber, vClients);
        QuestionToDeleteClient(vClients);
    }
    else
        cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;
}

void DeleteClientScreen() {

    if (!perminisonsCheckForUser(CurrentUser, 4)) {
        MessageToStop();
        return;
    }

    system("cls");
    vector<stData> vClients = LoadClientsDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "              Delete Client Screen              " << endl;
    cout << "------------------------------------------------" << endl;

    string AccountNumber;
    AccountNumber = ReadString("\nplease enter Account Number? ");

    ProccesDeleteClient(AccountNumber, vClients);
    system("pause");
}

void InputDataUdapteClient(stData& S) {

    cout << endl;
    S.PinCode = ReadString("Enter the pinCode? ");
    S.Name = ReadString("Enter your name? ");
    S.Phone = ReadString("Enter your phone? ");

    cout << "Enter the Account Balance? ";
    cin >> S.AccountBalance;
}

void UdapteDataClient(string AccountVumber, vector<stData>& vClients) {

    for (stData& S : vClients) {
        if (AccountVumber == S.AccountNumber) {
            InputDataUdapteClient(S);
            break;
        }
    }
}

void RefreachDataInFile(vector<stData>& vClients) {

    fstream MyFile;
    string str = "";
    MyFile.open(File, ios::out);
    if (MyFile.is_open()) {
        for (stData& S : vClients) {
            str = ConvertRecordToLine(S, "#//#");
            MyFile << str << endl;
        }
        MyFile.close();
    }
}

void QuestionUdapteClient(string AccountNumber, vector<stData>& vClients) {

    char Question;
    cout << "\nAre you sure want Udapte this client? [y/n]? ";
    cin >> Question;

    if (Question == 'y' || Question == 'Y') {
        UdapteDataClient(AccountNumber, vClients);
        RefreachDataInFile(vClients);
        cout << "\nClient Udapted Successfully" << endl;
    }
    else if (Question == 'n' || Question == 'N') {
        cout << "OK. " << endl;
    }
    else {
        cout << "please enter the true char, ";
        QuestionUdapteClient(AccountNumber, vClients);
    }
}

void ProccesUdapteClient(string AccountNumber, vector<stData>& vClients) {

    if (FindClientByAccountNumber(AccountNumber, vClients)) {
        PrintClient(AccountNumber, vClients);
        QuestionUdapteClient(AccountNumber, vClients);
    }
    else
        cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;
}

void UdapteClientInfoScreen() {

    if (!perminisonsCheckForUser(CurrentUser, 8)) {
        MessageToStop();
        return;
    }

    system("cls");
    vector<stData> vClients = LoadClientsDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "               Update Client Info               " << endl;
    cout << "------------------------------------------------" << endl;

    string AccountNumber;
    cout << "\nplease enter Account Number? ";
    cin >> AccountNumber;

    ProccesUdapteClient(AccountNumber, vClients);
    system("pause");
}

void SearchClient(string AccountNumber, vector<stData>& vClients) {

    for (stData& S : vClients) {
        if (S.AccountNumber == AccountNumber) {
            PrintClient(AccountNumber, vClients);
            return;
        }
    }
    cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;
}

void FindClientSceern() {

    if (!perminisonsCheckForUser(CurrentUser, 16)) {
        MessageToStop();
        return;
    }

    system("cls");
    vector<stData> vClients = LoadClientsDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "               Find Client Screen               " << endl;
    cout << "------------------------------------------------" << endl;

    string AccountNumber;
    AccountNumber = ReadString("\nplease enter Account Number? ");

    SearchClient(AccountNumber, vClients);
    system("pause");
}

double InputBalanceToDeposite() {
    double Deposite;
    cout << "Please enter Deposite Amount? ";
    cin >> Deposite;

    while (cin.fail() || Deposite <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! enter positive Deposite Amount? ";
        cin >> Deposite;
    }
    return Deposite;
}

void ProccesThDepositeClient(string AccountNumber, double Deposite, vector<stData>& vClients) {
    for (stData& S : vClients) {
        if (S.AccountNumber == AccountNumber) {
            S.AccountBalance += Deposite;
            RefreachDataInFile(vClients);
            cout << "\nClient Udapted Successfully, your Account Balace is " << S.AccountBalance << endl;
            break;
        }
    }
}

void DepositeClient(string AccountNumber, vector<stData>& vClients) {
    double Deposite = InputBalanceToDeposite();
    ProccesThDepositeClient(AccountNumber, Deposite, vClients);
}

void QuestionToDepositeClient(string AccountNumber, vector<stData>& vClients) {
    char Question;
    cout << "\nAre you sure want perform this transeactions? [y/n]? ";
    cin >> Question;

    if (Question == 'y' || Question == 'Y') {
        DepositeClient(AccountNumber, vClients);
    }
    else if (Question == 'n' || Question == 'N') {
        cout << "OK. " << endl;
    }
    else {
        cout << "please enter the true char, ";
        QuestionToDepositeClient(AccountNumber, vClients);
    }
}

void DepositeScreen() {
    system("cls");
    vector<stData> vClients = LoadClientsDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "               Deposite Screen               " << endl;
    cout << "------------------------------------------------" << endl;

    string AccountNumber;
    AccountNumber = ReadString("\nplease enter Account Number? ");

    if (FindClientByAccountNumber(AccountNumber, vClients)) {
        PrintClient(AccountNumber, vClients);
        QuestionToDepositeClient(AccountNumber, vClients);
    }
    else
        cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;

    system("pause");
}

void ProccesTheWithdrawClient(string AccountNumber, double Withdraw, vector<stData>& vClients) {
    for (stData& S : vClients) {
        if (S.AccountNumber == AccountNumber) {
            if (S.AccountBalance >= Withdraw) {
                S.AccountBalance = S.AccountBalance - Withdraw;
                RefreachDataInFile(vClients);
                cout << "\nClient Udapted Successfully, your Account Balace is " << S.AccountBalance << endl;
                break;
            }
            else {
                cout << "Amount Exceeds the balance, you can Withdraw up to : " << S.AccountBalance << endl;
                WithdrawClient(AccountNumber, vClients);
                break;
            }
        }
    }
}

double InputBalanceToWithdraw() {

    double Withdraw;
    cout << "Please enter Withdraw Amount? ";
    cin >> Withdraw;

    while (cin.fail() || Withdraw <= 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! enter positive Withdraw Amount? ";
        cin >> Withdraw;
    }
    return Withdraw;
}

void WithdrawClient(string AccountNumber, vector<stData>& vClients) {

    double Withdraw = InputBalanceToWithdraw();
    ProccesTheWithdrawClient(AccountNumber, Withdraw, vClients);

}

void QuestionToWithdrawClient(string AccountNumber, vector<stData>& vClients) {

    char Question;
    cout << "\nAre you sure want perform this transeactions? [y/n]? ";
    cin >> Question;

    if (Question == 'y' || Question == 'Y') {
        WithdrawClient(AccountNumber, vClients);
    }
    else if (Question == 'n' || Question == 'N') {
        cout << "OK. " << endl;
    }
    else {
        cout << "please enter the true char, ";
        QuestionToWithdrawClient(AccountNumber, vClients);
    }
}

void IfFindAccountNumberForWithdra(string AccountNumber, vector<stData>& vClients) {
    if (FindClientByAccountNumber(AccountNumber, vClients)) {
        PrintClient(AccountNumber, vClients);
        QuestionToWithdrawClient(AccountNumber, vClients);
    }
    else
        cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;
}

void WithdrawScreen() {
    system("cls");
    vector<stData> vClients = LoadClientsDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "                 Withdraw Screen                " << endl;
    cout << "------------------------------------------------" << endl;

    string AccountNumber;
    AccountNumber = ReadString("\nplease enter Account Number? ");

    IfFindAccountNumberForWithdra(AccountNumber, vClients);
    system("pause");
}

void PrintClientTotalBalance(stData Client) {
    cout << "|" << left << setw(20) << Client.AccountNumber
        << "|" << left << setw(20) << Client.Name
        << "|" << left << setw(20) << Client.AccountBalance << endl;
}

void SumTotalBalnces(vector<stData>& vClients) {
    double sum = 0;
    for (stData& S : vClients) {
        sum += S.AccountBalance;
    }
    cout << "\t\t\ttotal Balance = " << sum << endl;
}

void PrintTotaleBalanceClientsData() {
    vector<stData> vClients = LoadClientsDataFromFile("#//#");

    system("cls");
    cout << "\n____________________________________________________________________________________________________\n" << endl;
    cout << "                                     Balances List (" << vClients.size() << ") Client(s).                                \n";
    cout << "____________________________________________________________________________________________________\n" << endl;
    cout << "|" << left << setw(20) << "Account Number"
        << "|" << left << setw(20) << "Client Name"
        << "|" << left << setw(20) << "Balance" << endl;
    cout << "____________________________________________________________________________________________________\n" << endl;

    for (stData& Client : vClients) {
        PrintClientTotalBalance(Client);
    }

    cout << "____________________________________________________________________________________________________\n" << endl;
    SumTotalBalnces(vClients);
    cout << "____________________________________________________________________________________________________\n" << endl;

    system("pause");
}

void ChoiseTransactionsClientScreen(ChoiseScreenClientTransactionsMenue choise) {
    switch (choise) {
    case ChoiseScreenClientTransactionsMenue::eDeposite:
        DepositeScreen();
        break;
    case ChoiseScreenClientTransactionsMenue::eWithdraw:
        WithdrawScreen();
        break;
    case ChoiseScreenClientTransactionsMenue::eTotalBalances:
        PrintTotaleBalanceClientsData();
        break;
    case ChoiseScreenClientTransactionsMenue::eMainMenue:
        break;
    }
}

int InputChoiseEnumTransactionsScreen() {

    int ChioseScreen;
    cout << "\nChoose What do you want to do? [1 to 4]? ";
    cin >> ChioseScreen;

    while (cin.fail() || ChioseScreen > 4 || ChioseScreen < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Enter a number [1 to 4]: ";
        cin >> ChioseScreen;
    }
    return ChioseScreen;
}

void TransactionsClientScreen() {

    if (!perminisonsCheckForUser(CurrentUser, 32)) {
        MessageToStop();
        return;
    }

    int ChioseScreen;

    do {
        system("cls");
        cout << "================================================" << endl;
        cout << "            Transactions Menu Screen            " << endl;
        cout << "================================================" << endl;
        cout << "            [1]: Deposite.                      " << endl;
        cout << "            [2]: Withdraw.                      " << endl;
        cout << "            [3]: Total Balances.                " << endl;
        cout << "            [4]: Main Menue.                    " << endl;
        cout << "================================================" << endl;

        ChioseScreen = InputChoiseEnumTransactionsScreen();
        ChoiseTransactionsClientScreen((ChoiseScreenClientTransactionsMenue)ChioseScreen);

    } while (ChioseScreen != 4);
}

//==========================================
//   (2) Manage Users Screen :
//==========================================

string ConvertRecordToLineUsers(stUsers Users, string separator) {

    return Users.UserName + separator +
        Users.Passowrd + separator +
        to_string(Users.Validity);
}

stUsers ConvertLineUsersToRecord(string Line, string separator) {

    stUsers Users;
    vector<string> vUsersData = SplitString(Line, separator);

    if (vUsersData.size() >= 3) {
        Users.UserName = vUsersData[0];
        Users.Passowrd = vUsersData[1];
        Users.Validity = stoi(vUsersData[2]);
    }
    return Users;
}

void SaveLineUsersToFile(string LineData) {

    fstream MyFile;
    MyFile.open(File2, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << LineData << endl;
        MyFile.close();
    }
}

vector<stUsers> LoadUsersDataFromFile(string separator) {

    vector<stUsers> vUsers;
    fstream MyFile;
    MyFile.open(File2, ios::in);

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            if (!Line.empty()) {
                stUsers Users = ConvertLineUsersToRecord(Line, separator);
                vUsers.push_back(Users);
            }
        }
        MyFile.close();
    }
    return vUsers;
}

void PrintLiseUsersData(stUsers Users) {
    cout << "|" << left << setw(20) << Users.UserName
        << "|" << left << setw(20) << Users.Passowrd
        << "|" << left << setw(20) << Users.Validity << endl;
}

void ListUsers() {
    vector<stUsers> vUser;
    vUser = LoadUsersDataFromFile("#//#");

    system("cls");
    cout << "\n____________________________________________________________________________________________________\n" << endl;
    cout << "                                    Users List (" << vUser.size() << ") User(s).                                \n";
    cout << "____________________________________________________________________________________________________\n" << endl;
    cout << "|" << left << setw(20) << "User Name"
        << "|" << left << setw(20) << "Password"
        << "|" << left << setw(20) << "Permissions" << endl;
    cout << "____________________________________________________________________________________________________\n" << endl;

    for (stUsers& U : vUser) {
        PrintLiseUsersData(U);
    }

    system("pause");
}

bool FindUserByUserNsme(string UserName, vector<stUsers>& vUsers) {

    for (stUsers C : vUsers) {
        if (C.UserName == UserName)
            return true;
    }
    return false;
}

char QuestionFun(string Message) {
    char cQuestion;

    cout << Message;
    cin >> cQuestion;

    return cQuestion;
}

void GivePermissionsToUser(stUsers& User) {
    
    char Question;
    User.Validity = 0;

    cout << "\nOk, Do you want to give access to : " << endl;

    Question = QuestionFun("Show Clients List? [y/n]? ");
        if (Question == 'y' || Question == 'Y')
            User.Validity += 1;

    Question = QuestionFun("Add New Client? [y/n]? ");
        if (Question == 'y' || Question == 'Y')
            User.Validity += 2;

    Question = QuestionFun("Delete Client? [y/n]? ");
        if (Question == 'y' || Question == 'Y')
            User.Validity += 4;

    Question = QuestionFun("Update Client Info ? [y / n] ? ");
         if (Question == 'y' || Question == 'Y')
            User.Validity += 8;

    Question = QuestionFun("Find Client? [y/n]? ");
         if (Question == 'y' || Question == 'Y')
             User.Validity += 16;

    Question = QuestionFun("Transactions? [y/n]? ");
         if (Question == 'y' || Question == 'Y')
            User.Validity += 32;

     Question = QuestionFun("Mangae Users? [y/n]?  ");
         if (Question == 'y' || Question == 'Y')
             User.Validity += 64;

    cout << "\n==========================" << endl;

}

void QuestionPermissionsFromAdmin(stUsers& User) {
    char Question = QuestionFun("Do You want to give full access? [y/n] ?  ");
    

    if (Question == 'y' || Question == 'Y') {
        User.Validity = -1;
        return;
    }
    else if (Question == 'n' || Question == 'N') {
        GivePermissionsToUser(User);
    }
    
}

stUsers ReadClientData(vector<stUsers>& vUser) {
    stUsers User;
    User.UserName = ReadString("Enter User Name? ");

    while (FindUserByUserNsme(User.UserName, vUser)) {
        cout << "User With [" << User.UserName << "] Already exists, ";
        User.UserName = ReadString("Enter User Name? ");
    }

    cout << "Enter Password? ";
    cin >> User.Passowrd;

    cout << "\n-------Permissions-------" << endl;
    
    QuestionPermissionsFromAdmin(User);
   
    return User;
}

void saveToUserFile() {
    stUsers User;
    vector<stUsers> vUser;
    vUser = LoadUsersDataFromFile("#//#");

    User = ReadClientData(vUser);
    string Line = ConvertRecordToLineUsers(User, "#//#");
    SaveLineUsersToFile(Line);
}

void AddNewUser() {
    
    char Qustion;

    do {
        system("cls");

        cout << "===================================" << endl;
        cout << "        Add New User Screen        " << endl;
        cout << "===================================" << endl;

        saveToUserFile();

        cout << "User Added Successfully, Do you want to add more user ? [y/n]? ";
        cin >> Qustion;

    } while (Qustion == 'y' || Qustion == 'Y');
    

    system("pause");
}

bool MarkUserForDeleteByUserName(string UserName, vector<stUsers>& vUser) {

    for (stUsers& C : vUser) {
        if (C.UserName == UserName) {
            C.MarkUserForDelete = true;
            return true;
        }
    }
    return false;
}

void SaveUsresDataToFile(vector<stUsers>& vUser) {

    fstream MyFile;
    MyFile.open(File2, ios::out);
    string DataLine;

    if (MyFile.is_open()) {
        for (stUsers C : vUser) {
            if (C.MarkUserForDelete == false) {
                DataLine = ConvertRecordToLineUsers(C, "#//#");
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
}

void PrintUser(string UserName, vector<stUsers>& vUser) {
    cout << "the following are the User details : " << endl;
    for (stUsers& C : vUser) {
        if (C.UserName == UserName) {
            cout << "------------------------------------------------" << endl;
            cout << setw(20) << left << " User Name   " << ": " << C.UserName << endl;
            cout << setw(20) << left << " Password    " << ": " << C.Passowrd << endl;
            cout << setw(20) << left << " permissions " << ": " << C.Validity << endl;
            cout << "------------------------------------------------" << endl;
            return;
        }
    }
}

void QuestionToDeleteUsers(vector<stUsers>& vUser) {

    char Question;
    cout << "\nAre you sure want delete this User? [y/n]? ";
    cin >> Question;

    if (Question == 'y' || Question == 'Y') {
        SaveUsresDataToFile(vUser);
        cout << "User Delete Successfully" << endl;
    }
    else if (Question == 'n' || Question == 'N') {
        cout << "OK. " << endl;
    }
    else {
        cout << "please enter the true char, ";
        QuestionToDeleteUsers(vUser);
    }
}

void ProccesDeleteUsers(string UserName, vector<stUsers>& vUser) {
    if (MarkUserForDeleteByUserName(UserName, vUser)) {
        PrintUser(UserName, vUser);
        QuestionToDeleteUsers(vUser);
    }
    else
        cout << "User With User Name (" << UserName << ") is not Found" << endl;
}

void DeleteUserScreen() {

    system("cls");
    vector<stUsers> vUser = LoadUsersDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "              Delete User Screen              " << endl;
    cout << "------------------------------------------------" << endl;

    string UserName;
    UserName = ReadString("please enter User Name? ");

    if (UserName == "Admin") {
		cout << "You can't delete Admin user" << endl;
    }
    else 
        ProccesDeleteUsers(UserName, vUser);

    system("pause");
}

void InputDataUdapteUser(stUsers& User, vector<stUsers>& vUser) {

    char Question = QuestionFun("Are you sure you want update this user? [y/n]?  ");

    if (Question == 'y' || Question == 'Y') {
        cout << endl;
        User.Passowrd = ReadString("Enter Password? ");

        cout << "\n-------Permissions-------" << endl;

        QuestionPermissionsFromAdmin(User);
        SaveUsresDataToFile(vUser);

        cout << "User Updated Successfully. " << endl;
    }

    else
        cout << "Ok." << endl;
}

void UdapteDataUser(string UserName, vector<stUsers>& vUser) {

    for (stUsers& S : vUser) {
        if (UserName == S.UserName) {
            PrintUser(UserName, vUser);
            InputDataUdapteUser(S, vUser);
            return;
        }
    }
	cout << "User With User Name (" << UserName << ") is not Found" << endl;
}
 
void UdapteDataUserScreen() {
    system("cls");
    vector<stUsers> vUser = LoadUsersDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "               Update User Screen               " << endl;
    cout << "------------------------------------------------" << endl;

    string UserName;
    UserName = ReadString("please enter User Name? ");
    cout << "\n";

    if (UserName == "Admin") {
        cout << "You can't update Admin user." << endl;
    }
    else
        UdapteDataUser(UserName, vUser);

    system("pause");
}

void SearchUser(string UserName, vector<stUsers>& vUser) {

    for (stUsers& S : vUser) {
        if (S.UserName == UserName) {
            PrintUser(UserName, vUser);
            return;
        }
    }
    cout << "User With User Name (" << UserName << ") is not Found" << endl;
}

void FindUserSceern() {
    system("cls");
    vector<stUsers> vUser = LoadUsersDataFromFile("#//#");

    cout << "------------------------------------------------" << endl;
    cout << "                Find User Screen                " << endl;
    cout << "------------------------------------------------" << endl;

    string UserName;
    UserName = ReadString("please enter User Name? ");
    cout << "\n";

    SearchUser(UserName, vUser);
    system("pause");
}

void ChoiseManageUsersScreen(ChoiseScreenManageUsersMenue choise) {
    switch (choise) {
    case ChoiseScreenManageUsersMenue::eListUsers:
        ListUsers();
        break;
    case ChoiseScreenManageUsersMenue::eAddNewUser:
        AddNewUser();
        break;
    case ChoiseScreenManageUsersMenue::eDeleteUser:
        DeleteUserScreen();
        break;
    case ChoiseScreenManageUsersMenue::eUpdateUser:
        UdapteDataUserScreen();
        break;
    case ChoiseScreenManageUsersMenue::eFindUser:
        FindUserSceern();
        break;
    }
}

int InputChoiseEnumManageUsersScreen() {

    int ChioseScreen;
    cout << "\nChoose What do you want to do? [1 to 6]? ";
    cin >> ChioseScreen;

    while (cin.fail() || ChioseScreen > 6 || ChioseScreen < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Enter a number [1 to 6]: ";
        cin >> ChioseScreen;
    }
    return ChioseScreen;
}

void ManageUsersScreen() {

    if (!perminisonsCheckForUser(CurrentUser, 64)) {
        MessageToStop();
        return;
    }

    int choise;

    do {
        system("cls");
        cout << "================================================" << endl;
        cout << "            Manage Users Menu Screen            " << endl;
        cout << "================================================" << endl;
        cout << "            [1]: List Users.                    " << endl;
        cout << "            [2]: Add New User.                  " << endl;
        cout << "            [3]: Delete User.                   " << endl;
        cout << "            [4]: Update User.                   " << endl;
        cout << "            [5]: Find User.                     " << endl;
        cout << "            [6]: Main Menue.                    " << endl;
        cout << "================================================" << endl;

        choise = InputChoiseEnumManageUsersScreen();
        ChoiseManageUsersScreen((ChoiseScreenManageUsersMenue)choise);

    } while (choise != 6);
}

void ChoiseClientScreenMainMenue(ChoiseScreenClientMainMenue Choose) {
    switch (Choose) {
    case ChoiseScreenClientMainMenue::eShowClientsList:
        PrintAllClientsData();
        break;
    case ChoiseScreenClientMainMenue::eAddNewClient:
        AddNewClientScreen();
        break;
    case ChoiseScreenClientMainMenue::eDeleteClient:
        DeleteClientScreen();
        break;
    case ChoiseScreenClientMainMenue::eUdapteClientInfo:
        UdapteClientInfoScreen();
        break;
    case ChoiseScreenClientMainMenue::eFindClient:
        FindClientSceern();
        break;
    case ChoiseScreenClientMainMenue::eTransactions:
        TransactionsClientScreen();
        break;
    case ChoiseScreenClientMainMenue::eManageUsers:
        ManageUsersScreen();
        break;
    case ChoiseScreenClientMainMenue::eExit:
        LoginScreen();
        break;
    }
}

int ChoiseClientEnumMainMenue() {
    int ChioseScreen;
    cout << "\nChoose What do you want to do? [1 to 8]? ";
    cin >> ChioseScreen;

    while (cin.fail() || ChioseScreen > 8 || ChioseScreen < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid Input! Enter a number [1 to 8]: ";
        cin >> ChioseScreen;
    }

    return ChioseScreen;
    
}

void MainMenu() {
    int ChioseScreen;
    do {
        system("cls");
        cout << "================================================" << endl;
        cout << "                Main Menu Screen                " << endl;
        cout << "================================================" << endl;
        cout << "           [1]: Show Clients List.              " << endl;
        cout << "           [2]: Add New Client.                 " << endl;
        cout << "           [3]: Delete Client.                  " << endl;
        cout << "           [4]: Update Clien Info.              " << endl;
        cout << "           [5]: Find Client.                    " << endl;
        cout << "           [6]: Transactions.                   " << endl;
        cout << "           [7]: Mangae Users.                   " << endl;
        cout << "           [8]: Logout.                         " << endl;
        cout << "================================================" << endl;

        ChioseScreen = ChoiseClientEnumMainMenue();
        ChoiseClientScreenMainMenue((ChoiseScreenClientMainMenue)ChioseScreen);

    } while (ChioseScreen != 8);
   
}

bool checkPasswordForUser(string UserName, vector<stUsers>& vUser, string Password)   {
    for (stUsers& S : vUser) {
            if (S.UserName == UserName && S.Passowrd == Password) {
               
                    CurrentUser = S;
                    return true;
       
            }
        }
        return false;
}

void LoginScreen() {

    vector<stUsers> vUser = LoadUsersDataFromFile("#//#");
    string UserName;
    string Password;
    bool loginFaild = false;

    do {
        system("cls");

        cout << "================================================" << endl;
        cout << "                  Login Screen                  " << endl;
        cout << "================================================" << endl;

       if (loginFaild) {
            cout << "The password / Account is incorrect. " << endl;
        }

        UserName = ReadString("Enter User Name ? ");
        Password = ReadString("Enter Password? ");

        loginFaild = !checkPasswordForUser(UserName, vUser, Password);
        

    } while (loginFaild);

    MainMenu();
}

int main() {
    LoginScreen();
    return 0;
}
