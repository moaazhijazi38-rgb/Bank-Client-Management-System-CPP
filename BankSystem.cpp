#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib> 

using namespace std;

enum ChoiseScreenClient{ShowClientsList=1, AddNewClient=2, DeleteClient=3, UdapteClientInfo=4, FindClient=5, Exit=6};

const string File = "MyFile.text";

struct stData {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    string AccountBalance;
    bool MarkForDelete = false;
};

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

void ReadClientData(vector<stData>& vClients, stData& Client) {
    Client.AccountNumber = ReadString("Enter Account Number? ");

    while (FindClientByAccountNumber(Client.AccountNumber, vClients)) {
        cout << "Client With [" << Client.AccountNumber << "] Already exists, ";
        Client.AccountNumber = ReadString("Enter Account Number? ");
    }

    Client.PinCode = ReadString("Enter the PinCode? ");
    Client.Name = ReadString("Enter your Name? ");
    Client.Phone = ReadString("Enter your Phone? ");
    Client.AccountBalance = ReadString("Enter the Account Balance? ");
}

string ConvertRecordToLine(stData Client, string separator) {
    return Client.AccountNumber + separator +
        Client.PinCode + separator +
        Client.Name + separator +
        Client.Phone + separator +
        Client.AccountBalance;
}

stData ConvertLineToRecord(string Line, string separator) {
    stData Client;
    vector<string> vClientData = SplitString(Line, separator);

    if (vClientData.size() >= 5) {
        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = vClientData[4];
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

vector<stData> LoadClientsDataFromFile( string separator) {
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

void AddNewClientToFile( string separator) {
    stData Client;
    vector<stData> vClients = LoadClientsDataFromFile("#//#");
    ReadClientData(vClients,Client);

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

void PrintAllClientsData(vector<stData> vClients) {
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

void PrintClient(stData C) {
       cout << "\n------------------------------------------------" << endl;
       cout << setw(20) << left << " Account Number " << ": " << C.AccountNumber << endl;
       cout << setw(20) << left << " Pin Code " << ": " << C.PinCode << endl;
       cout << setw(20) << left << " Name " << ": " << C.Name << endl;
       cout << setw(20) << left << " Phone " << ": " << C.Phone << endl;
       cout << setw(20) << left << " Account Balance " << ": " << C.AccountBalance << endl;
       cout << "------------------------------------------------" << endl;
       
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stData>& vClients) {
    for (stData& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true; // وضع علامة الحذف
            return true;
        }
    }
    return false;
}

vector<stData> SaveCleintsDataToFile(string FileName, vector<stData>& vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out); // وضع الكتابة (يمسح القديم ويكتب من جديد)
    string DataLine;

    if (MyFile.is_open()) {
        for (stData C : vClients) {
            // الشرط الذكي: اكتب العميل فقط إذا لم يكن معلماً للحذف
            if (C.MarkForDelete == false) {
                DataLine = ConvertRecordToLine(C, "#//#");
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

void QuestionToDeleteClient(vector<stData> vClients) {
    char Question;

    cout << "\nAre you sure want delete this client? [y/n]? ";
    cin >> Question;

    if (Question == 'y' || Question == 'Y') {
        SaveCleintsDataToFile(File, vClients);
        cout << "Client Delete Successfully" << endl;
    }
    else if (Question == 'n' || Question == 'N') {
        cout << "OK. " << endl;
        system("pause");
    }
    else {
        cout << "please enter the true char, ";
        QuestionToDeleteClient(vClients);
    }
}

void DeleteClientScreen(vector<stData>& vClients) {
    system("cls");
    string AccountNumber;

    cout << "------------------------------------------------" << endl;
    cout << "              Delete Client Screen              " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "\nplease enter Account Number? ";
    cin >> AccountNumber;

    if (MarkClientForDeleteByAccountNumber(AccountNumber, vClients)) {
        PrintClient(AccountNumber, vClients);
        QuestionToDeleteClient(vClients);
    }
    else
        cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;


    system("pause");
}

void InputDataUdapteClient(stData& S) {
    cout << endl;
    S.PinCode = ReadString("Enter the pinCode? ");
    S.Name = ReadString("Enter your name? ");
    S.Phone = ReadString("Enter your phone? ");
    S.AccountBalance = ReadString("Enter the Account Balance? ");
}

void UdapteDataClient(string AccountVumber, vector<stData>& For) {
    for (stData& S : For) {
        if (AccountVumber == S.AccountNumber) {
            InputDataUdapteClient(S);
        }
    }
}

void RefreachDataInFile(string message, vector<stData>& For) {
    fstream MyFile;
    string str = "";

    MyFile.open(message, ios::out);
    if (MyFile.is_open()) {
        for (stData& S : For) {
            str = ConvertRecordToLine(S, "#//#");
            MyFile << str << endl;
        }
        MyFile.close();
    }
}

void QuestionUdapteClient(string AccountNumber, vector<stData> vClients) {
    char Question;

    cout << "\nAre you sure want Udapte this client? [y/n]? ";
    cin >> Question;

    if (Question == 'y' || Question == 'Y') {
        UdapteDataClient(AccountNumber, vClients);
        RefreachDataInFile(File, vClients);
        cout << "\nClient Udapted Successfully" << endl;
    }
    else if (Question == 'n' || Question == 'N') {
        cout << "OK. " << endl;
        system("pause");
    }
    else {
        cout << "please enter the true char, ";
        QuestionUdapteClient(AccountNumber,vClients);
    }
}

void UdapteClientInfoScreen(vector<stData>& vClients) {
    system("cls");
    string AccountNumber;

    cout << "------------------------------------------------" << endl;
    cout << "               Udapte Client Info               " << endl;
    cout << "------------------------------------------------" << endl;
    cout << "\nplease enter Account Number? ";
    cin >> AccountNumber;

    if (FindClientByAccountNumber(AccountNumber, vClients)) {
        PrintClient(AccountNumber, vClients);
        QuestionUdapteClient(AccountNumber,vClients);
    }
    else
        cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;


    system("pause");
}

void SearchClient(string AccountNumber, vector<stData>& For) {
    for (stData& S : For) {
        if (S.AccountNumber == AccountNumber) {
            PrintClient(S);
            return;
        }
    }
    cout << "Client With Account Number (" << AccountNumber << ") is not Found" << endl;
}

void FindClientSceern(vector<stData> For) {
        system("cls");
        string AccountNumber;

        cout << "------------------------------------------------" << endl;
        cout << "               Find Client Screen               " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "\nplease enter Account Number? ";
        cin >> AccountNumber;

        SearchClient(AccountNumber, For);

        system("pause");
}

void ChoiseClientScreen(ChoiseScreenClient Choose, vector<stData>& vClients) {
    switch (Choose) {
    case ChoiseScreenClient::ShowClientsList:
        vClients = LoadClientsDataFromFile("#//#");
        PrintAllClientsData(vClients);
        break;
    case ChoiseScreenClient::AddNewClient:
        AddNewClientScreen();
        break;
    case ChoiseScreenClient::DeleteClient:
        vClients = LoadClientsDataFromFile("#//#");
        DeleteClientScreen(vClients);
        break;
    case ChoiseScreenClient::UdapteClientInfo:
        vClients = LoadClientsDataFromFile("#//#");
        UdapteClientInfoScreen(vClients);
        break;
    case ChoiseScreenClient::FindClient:
        vClients = LoadClientsDataFromFile("#//#");
        FindClientSceern(vClients);
        break;
    }
}

void MainMenu() {
    int ChioseScreen;
    vector<stData> vClients;
    do {
        system("cls");
        cout << "================================================" << endl;
        cout << "                Main Menu Screen                " << endl;
        cout << "================================================" << endl;
        cout << "           [1]: Show Clients List.              " << endl;
        cout << "           [2]: Add New Client.                 " << endl;
        cout << "           [3]: Delete Client.                  " << endl;
        cout << "           [4]: Udapte Clien Info.              " << endl;
        cout << "           [5]: Find Client.                    " << endl;
        cout << "           [6]: Exit.                           " << endl;
        cout << "================================================" << endl;
        cout << "\nChoose What do you want to do? [1 to 6]? ";
        cin >> ChioseScreen;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid Input! Enter a number [1 to 6]: ";
            cin >> ChioseScreen;
        }

        if (ChioseScreen == 6) {
            break;
        }

        ChoiseClientScreen((ChoiseScreenClient)ChioseScreen, vClients);

    } while (true);
}

int main() {

    MainMenu();

    return 0;
}
