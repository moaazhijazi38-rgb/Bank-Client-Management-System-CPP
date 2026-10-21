#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;
class clsTransferLogScreen : protected clsScreen
{
private:

	static void _TransferLogRecord(clsBankClient::stCreatTransderLog TransferLog) {
		cout << "\t|" << left << setw(25) << TransferLog.Date
			 << "\t|" << left << setw(13) << TransferLog.AccNumberFrom
			 << "\t|" << left << setw(13) << TransferLog.AccNumberTo
		  	 << "\t|" << left << setw(13) << TransferLog.TraAmount
			 << "\t|" << left << setw(13) << TransferLog.AccNumberFromAfterTran
			 << "\t|" << left << setw(13) << TransferLog.AccNumberToAfterTran
			 << "\t|" << left << setw(13) << TransferLog.UserTran << endl;
	}

public:


	static void ShowAllTransferLogData() {

		vector<clsBankClient::stCreatTransderLog> vTransferLog = clsBankClient::LoadTransferLofFromFile();

		string Part1 = "\t    Transfer Log List Screen ";
		string Part2 = "\t\t(" + to_string(vTransferLog.size()) + ") Record(s) ";

		_DrawScreenHeader(Part1, Part2);
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;
		cout << "\t|" << left << setw(25) << "Date/Time"
			 << "\t|" << left << setw(13) << "s.Acct"
			 << "\t|" << left << setw(13) << "d.Acct"
			 << "\t|" << left << setw(13) << "Amount"
			 << "\t|" << left << setw(13) << "s,Balance"
			 << "\t|" << left << setw(13) << "d.Balance" 
			 << "\t|" << left << setw(13) << "User" << endl;
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		if (vTransferLog.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In The System!\n";

		}
		else {
			for (clsBankClient::stCreatTransderLog& TransferLog : vTransferLog) {
				_TransferLogRecord(TransferLog);
			}
		}
		cout << "\t_________________________________________________________________________________________________________________________\n" << endl;

		system("pause>0");
	}

};

