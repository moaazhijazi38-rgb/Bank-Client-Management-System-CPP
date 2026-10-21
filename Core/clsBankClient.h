#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum _eMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2 };

	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	_eMode _Mode;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToRecord(string Line, string separator = "#//#") {

		vector<string> vClientData;
		vClientData = clsString::Split(Line, separator);

		return clsBankClient(_eMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
		
	}

	static string _ConvertRecordToLine(clsBankClient Client, string separator = "#//#") {
		string str = "";
		str += Client.getFirstName() + separator;
		str += Client.getLastName() + separator;
		str += Client.getEmail() + separator;
		str += Client.getPhone() + separator;
		str += Client._AccountNumber + separator;
		str += Client._PinCode + separator;
		str += to_string(Client._AccountBalance);

		return str;
	}

	static clsBankClient _GetEmptyClientObject() {
		 return clsBankClient(_eMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile(string FileName, string separator) {
		vector<clsBankClient> vClients;
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsBankClient Client = _ConvertLineToRecord(Line, separator);
					vClients.push_back(Client);
				}
			}
			MyFile.close();
		}
		return vClients;
	}

	void _SaveClientsDataToFile(vector<clsBankClient>& Client) {
		fstream MyFile;
		string str = "";

		MyFile.open("MyFile.text", ios::out);
		if (MyFile.is_open()) {
			for (clsBankClient& S : Client) {
				if (S._MarkForDelete == false) {
					str = _ConvertRecordToLine(S, "#//#");
					MyFile << str << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector<clsBankClient> _Client = _LoadClientsDataFromFile("MyFile.text", "#//#");

		for (clsBankClient& C : _Client) {
			if (C._AccountNumber == _AccountNumber) {
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_Client);
	}

	void _AddDataLineToFile(string LineData) {
		fstream MyFile;
		MyFile.open("MyFile.text", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << LineData << endl;
			MyFile.close();
		}
	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertRecordToLine(*this));
	}

	string _PreparTransferLogRecord(clsBankClient Client, double BalanceTransfer, string seprator = "#//#") {

		string str = "";

		str += clsDate::GetSystemDateString(clsDate()) + seprator;
		str += _AccountNumber + seprator;
		str += Client.getAccountNumber() + seprator;
		str += to_string(BalanceTransfer) + seprator;
		str += to_string(_AccountBalance) + seprator;
		str += to_string(Client.AccountBalance) + seprator;
		str += CurrentUser.UserName;

		return str;
	}

	void _RegisterTransferLog(double BalanceTransfer, clsBankClient& Client) {

		string LineData = _PreparTransferLogRecord(Client, BalanceTransfer);

		fstream MyFile;
		MyFile.open("Transfer.text", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << LineData << endl;

			MyFile.close();

		}
	}

	struct stCreatTransderLog;
	static stCreatTransderLog _ConvertLineTransferLogToRecord(string Line, string separator = "#//#") {

		vector<string> vTransferLogData;
		vTransferLogData = clsString::Split(Line, separator);
		stCreatTransderLog Transfer;

		Transfer.Date = vTransferLogData[0];
		Transfer.AccNumberFrom = vTransferLogData[1];
		Transfer.AccNumberTo = vTransferLogData[2];
		Transfer.TraAmount = stod(vTransferLogData[3]);
		Transfer.AccNumberFromAfterTran = stod(vTransferLogData[4]);
		Transfer.AccNumberToAfterTran = stod(vTransferLogData[5]);
		Transfer.UserTran = vTransferLogData[6];

		return Transfer;
	}

	static vector<stCreatTransderLog> _LoadTransferLofFromFile(string separator = "#//#") {
		vector<stCreatTransderLog> vTransferLog;
		fstream MyFile;
		MyFile.open("Transfer.text", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					stCreatTransderLog TransferLog = _ConvertLineTransferLogToRecord(Line, separator);
					vTransferLog.push_back(TransferLog);
				}
			}
			MyFile.close();
		}
		return vTransferLog;
	}

public :

	struct stCreatTransderLog {
		string Date;
		string AccNumberFrom;
		string AccNumberTo;
		double TraAmount;
		double AccNumberFromAfterTran;
		double AccNumberToAfterTran;
		string UserTran;
	};

	clsBankClient(_eMode Mode, string FirstName, string LastName,
		string Email, string Phone,
		string AccountNumber, string PinCode, double AccountBalance) :
			clsPerson(FirstName, LastName, Email, Phone) {

		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_Mode = Mode;

	}

	string getAccountNumber() {
		return _AccountNumber;
	}

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string getPinCode() {
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(double AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	double getAccountBalance() {
		return _AccountBalance;
	}

	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double AccountBalance;

    /*
	No UI Related code iside object.
	void Print() {
		cout << "\tClient Card" << endl;
		cout << "----------------------" << endl;
		cout << "First Name  : " << getFirstName() << endl;
		cout << "Last Name   : " << getLastName() << endl;
		cout << "Full Name   : " << FullName() << endl;
		cout << "Email       : " << getEmail() << endl;
		cout << "Phone       : " << getPhone() << endl;
		cout << "Acc. Number : " << _AccountNumber << endl;
		cout << "Passowrd    : " << _PinCode << endl;
		cout << "Balance     : " << _AccountBalance << endl;
		cout << "----------------------" << endl;
	}*/
	
	bool isEmptyMode() {
		return (_Mode == _eMode::EmptyMode);
	}

	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;
		MyFile.open("MyFile.text", ios::in);
			if (MyFile.is_open()) {
				string Line;
				while (getline(MyFile, Line)) {
					if (!Line.empty()) {
							 clsBankClient Client = _ConvertLineToRecord(Line, "#//#");
							 if (Client._AccountNumber == AccountNumber) {
								 MyFile.close();
								 return Client;
							 }
					}
				}
				MyFile.close();
			}
			return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)   {

		fstream MyFile;
		MyFile.open("MyFile.text", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsBankClient Client = _ConvertLineToRecord(Line, "#//#");
					if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode) {
						MyFile.close();
						return Client;
					}
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.isEmptyMode());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(_eMode::AddNewMode, "", "", "", "", AccountNumber, "", 0 );
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save() {
		switch (_Mode) {

		case _eMode::EmptyMode:

			return enSaveResults::svFaildEmptyObject;
			break;

		case _eMode::UpdateMode:

			_Update();
			return enSaveResults::svSucceeded;
			break;

		case _eMode::AddNewMode:
			if (IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildAccountNumberExists;
			}

			_AddNew();
			_Mode = _eMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}
		return enSaveResults::svFaildEmptyObject;
	}

	bool Delete() {

		vector<clsBankClient> Clients = _LoadClientsDataFromFile("MyFile.text", "#//#");
		for (clsBankClient& S : Clients) {
			if (S._AccountNumber == _AccountNumber) {
				S._MarkForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(Clients);
		*this = _GetEmptyClientObject();

		return true;

	}

	static vector<clsBankClient> GetClientList() {
		return _LoadClientsDataFromFile("MyFile.text", "#//#");
	}

	static double GetTotalBalnces() {
		double Total = 0;
		vector<clsBankClient> Clients = _LoadClientsDataFromFile("MyFile.text", "#//#");
		for (clsBankClient& S : Clients) {
			Total += S._AccountBalance;
		}

		return Total;
	}

	void Deposite(double Amount) {
		AccountBalance += Amount;
		Save();
	}
	
	bool  withdraw(double Amount) {
		
		if (Amount > AccountBalance) {
			return false;
		}
		
		else{
			AccountBalance -= Amount;
			Save();

			return true;
		}
	}

	bool Transfer(double BalanceTransfer, clsBankClient& Client) {

		if (BalanceTransfer > AccountBalance) {
			return false;
		}

		withdraw(BalanceTransfer);
		_RegisterTransferLog(BalanceTransfer, Client);
		Client.Deposite(BalanceTransfer);

		return true;
	}

	static vector<stCreatTransderLog> LoadTransferLofFromFile(string separator = "#//#") {
		return _LoadTransferLofFromFile();
	}

};


