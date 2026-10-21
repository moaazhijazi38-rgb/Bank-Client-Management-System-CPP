#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
using namespace std;

class clsBankUsers : public clsPerson
{
private:

	enum _eMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };

	_eMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	string _Date;
	bool _MarkForDelete = false;

	string _PreparLogInRecord(string seprator = "#//#") {

		string str = "";

		str += clsDate::GetSystemDateString(clsDate()) + seprator;
		str += _UserName + seprator;
		str += clsUtil::EncryptText(_Password,3) + seprator;
		str += to_string(_Permissions);

		return str;
	}

	static clsBankUsers _ConvertLineToRecord(string Line, string separator = "#//#") {

		vector<string> vUserData;
		vUserData = clsString::Split(Line, separator);

		return clsBankUsers(_eMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5], 3), stoi(vUserData[6]));

	}

	static string _ConvertRecordToLine(clsBankUsers User, string separator = "#//#") {
		string str = "";
		str += User.FirstName + separator;
		str += User.LastName + separator;
		str += User.Email + separator;
		str += User.Phone + separator;
		str += User._UserName + separator;
		str += clsUtil::EncryptText(User._Password, 3) + separator;
		str += to_string(User._Permissions);

		return str;
	}

	static clsBankUsers _GetEmptyUserObject() {
		return clsBankUsers(_eMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankUsers> _LoadUsersDataFromFile(string separator) {
		vector<clsBankUsers> vUsers;
		fstream MyFile;
		MyFile.open("Users.text", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsBankUsers Client = _ConvertLineToRecord(Line, separator);
					vUsers.push_back(Client);
				}
			}
			MyFile.close();
		}
		return vUsers;
	}

	void _SaveUsersDataToFile(vector<clsBankUsers>& vUsers) {
		fstream MyFile;
		string str = "";

		MyFile.open("Users.text", ios::out);
		if (MyFile.is_open()) {
			for (clsBankUsers& S : vUsers) {
				if (S._MarkForDelete == false) {
					str = _ConvertRecordToLine(S, "#//#");
					MyFile << str << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector<clsBankUsers> _Client = _LoadUsersDataFromFile("#//#");

		for (clsBankUsers& C : _Client) {
			if (C._UserName == _UserName) {
				C = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_Client);
	}

	void _AddDataLineToFile(string LineData) {
		fstream MyFile;
		MyFile.open("Users.text", ios::out | ios::app);
		if (MyFile.is_open()) {
			MyFile << LineData << endl;
			MyFile.close();
		}
	}

	void _AddNew() {
		_AddDataLineToFile(_ConvertRecordToLine(*this));
	}

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLineToRecordLoginRegister(string Line, string separator = "#//#") {

		stLoginRegisterRecord UserRegister;
		vector<string> vUserData;
		vUserData = clsString::Split(Line, separator);

		UserRegister.Date = vUserData[0];
		UserRegister.UserNameRegister = vUserData[1];
		UserRegister.PasswordRegister = clsUtil::DecryptText(vUserData[2], 3);
		UserRegister.PermissisonRegister = stoi(vUserData[3]);

		return UserRegister;
	}

	static vector<stLoginRegisterRecord> _GetLoginRegisterList() {
		vector<stLoginRegisterRecord> vUsers;
		fstream MyFile;
		MyFile.open("LoginRegister.text", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					stLoginRegisterRecord UserRegister = _ConvertLineToRecordLoginRegister(Line);
					vUsers.push_back(UserRegister);
				}
			}
			MyFile.close();
		}
		return vUsers;
	}

public:

	struct stLoginRegisterRecord {
		string Date;
		string UserNameRegister;
		string PasswordRegister;
		int PermissisonRegister;
	};

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,
		pUserRegister = 128 , pCurrency = 256
	};

	clsBankUsers(_eMode Mode, string FirstName, string LastName,
		string Email, string Phone,
		string UserName, string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		_Mode = Mode;

	}

	void setUserName(string UserName) {
		_UserName = UserName;
	}

	string getUserName() {
		return _UserName;
	}

	__declspec(property(get = getUserName, put = setUserName)) string UserName;

	void setPassworde(string Password) {
		_Password = Password;
	}

	string getPassword() {
		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassworde)) string Password;

	void setPermissions(int Permissions) {
		_Permissions = Permissions;
	}

	int getPermissions() {
		return _Permissions;
	}

	__declspec(property(get = getPermissions, put = setPermissions)) int Permissions;

	
	/*No UI Related code iside object.
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
	}
	*/

	bool isEmptyMode() {
		return (_Mode == _eMode::EmptyMode);
	}

	static clsBankUsers Find(string UserName) {

		fstream MyFile;
		MyFile.open("Users.text", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsBankUsers User = _ConvertLineToRecord(Line, "#//#");
					if (User._UserName == UserName) {
						MyFile.close();
						return User;
					}
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsBankUsers Find(string UserName, string Password) {

		fstream MyFile;
		MyFile.open("Users.text", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsBankUsers User = _ConvertLineToRecord(Line, "#//#");
					if (User._UserName == UserName && User._Password == Password) {
						MyFile.close();
						return User;
					}
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsBankUsers User1 = clsBankUsers::Find(UserName);
		return (!User1.isEmptyMode());
	}

	static clsBankUsers GetAddNewUserObject(string UserName) {
		return clsBankUsers(_eMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };

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
			if (IsUserExist(_UserName)) {
				return enSaveResults::svFaildUserNameExists;
			}

			_AddNew();
			_Mode = _eMode::UpdateMode;
			return enSaveResults::svSucceeded;
		}
		return enSaveResults::svFaildEmptyObject;
	}

	bool Delete() {

		vector<clsBankUsers> vUsers = _LoadUsersDataFromFile("#//#");
		for (clsBankUsers& S : vUsers) {
			if (S._UserName == _UserName) {
				S._MarkForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyUserObject();

		return true;

	}

	static vector<clsBankUsers> GetUserList() {
		return _LoadUsersDataFromFile("#//#");
	}

	 bool CheckAccessPermissions(enPermissions Permission) {
		if (this->Permissions == Permission) {
			return true;
		}
		if ((this->Permissions & Permission) == Permission) {
			return true;
		}
		else
			return false;
	}

	 void RegisterLogin() {

		 string LineData = _PreparLogInRecord();

		 fstream MyFile;
		 MyFile.open("LoginRegister.text", ios::out | ios::app);
		 if (MyFile.is_open()) {
			 MyFile << LineData << endl;
			 MyFile.close();
		 }
	 }

	 static vector<stLoginRegisterRecord> GetLoginRegisterList() {
		 return _GetLoginRegisterList();
	 }

};


