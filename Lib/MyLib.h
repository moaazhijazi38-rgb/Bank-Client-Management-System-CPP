#pragma once
#pragma warning (disable : 4996);

#include<iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
 

enum random{ SmallLetter =1, CapitalLetter=2 , SpecialCharcater=3 , Digit=4};
enum PrimeNotPrime{ Prime=1 , NotPrime=2};


namespace MyLib {


 //    Function Read.

int Read ( string message ){

    int Hours=0 ;

    do{

        cout << message << endl ;
        cin >> Hours ;

    } while ( Hours < 0 );

    return Hours;
}


//  Function check Prime

PrimeNotPrime CheckPrime(int number){

    int HalfNumber=number/2;

    for(int i=2;i<HalfNumber;i++){
        if(number%i==0){
            return PrimeNotPrime::NotPrime;
        }
    }

    return PrimeNotPrime::Prime;
}


 //  function Perfect

  int checkSumNumber(int number){
      int sum=0;
      int M=number/2;
      for(int i=1;i<=M;i++){
          if(number%i == 0){
                 sum=sum+i;
          }
      }
       return sum;
  }

  void checkPerfectNumber(int number){
      if(checkSumNumber(number)==number){
          cout << number << endl;
      }
  }

  void  PerfectNumbers(int number){
      for(int i=1;i<number;i++){
          checkPerfectNumber(i);
      }
  }


  //  function Opposite Of number

  void  OppositeOfNumber(int number){
      int Reminder=0 , number2=0;
     while(number > 0){
          Reminder=number%10;
          number=number/10;
          number2=number2*10+Reminder;
     }
     cout << number2 << endl ;
  }


  //  function Opposite and Invert Of number

  int RevesNumber(int Number){
      int Reminder=0 , count1=0;
      while(Number > 0){
          Reminder=Number%10;
          Number=Number/10;
          count1=count1*10+Reminder;
      }
          return count1 ;
  }

  void SearchOfNumber(int Number){
      int Reminder=0 , count1=0;
      while(Number > 0){
          Reminder=Number%10;
          Number=Number/10;
          cout << Reminder << endl;//1   2    3       4
      }
  }


  //  Print Decreasing Number Pattern

  void print(int Number){
      for(int i=Number;i>0;i--){
          for(int j=0;j<i;j++){
              cout << i ;
          }
          cout << endl;
      }

  }


  //  Print Increasing Number Pattern

  void printIncreasing(int Number){
      for(int i=1;i<=Number;i++){
          for(int j=1 ; j<=i ; j++){
              cout << i ;
          }
          cout << endl;
      }

  }
  

  //  function Random Number

  int RandomNumber(int From, int To){
      int randum= rand() % (To - From + 1) + From ;
      return randum;

  }


  // function Input element random for array

  void InputOfArray(int Length, int a[100]){
          for(int i=0;i<Length;i++){
              a[i]=RandomNumber(1,100);
          }
      }


  //  function Choice Random

  char Choice(random number){

      switch (number){
      case random::SmallLetter:
          return char(RandomNumber(97, 122));
      case random::CapitalLetter:
          return char(RandomNumber(65, 90));
      case random::SpecialCharcater:
          return char(RandomNumber(33, 47));
      case random::Digit:
          return char(RandomNumber(48, 57));
      }
  }


  //  Odd Numbers

int OddNumbers(int Length, int a[100]){
      int count1=0;
      for(int i=0;i<Length;i++){
          if(a[i] % 2 != 0){
              count1++;
          }
      }
      return count1;
  }

  // Copy Array

  void CopyArray(int Length, int a[100],int &Length2, int a2[100]){
      int count1=0;
      for(int i=0;i<Length;i++){
          a2[count1]=a[i];
          count1++;
      }
      Length2=--count1;
  }


  //  function swap

  void swapOfArray(int &A,int &B){
      int temp=A;
          A=B;
          B=temp;
  }


  //  function Search Number

  int SearchNumber(int Length, int a[100],int number){
      for(int i = 0 ; i < Length ; i++){
          if(a[i] == number){
              return i;
          }

      }
      return -1;
  }

  bool SearchNumberB(int Length, int a[100],int number){
      return SearchNumber(Length , a, number) != -1 ;
  }



  //  Add element for Array

  void AddToArray(int number, int &Length,int a[100]){

      a[Length]=number;
      Length++;

  }
  void InputUserNumbersInArray(int &Length, int a[100]){

      bool Question=true;

      do {

          AddToArray(Read("please enter a number : "), Length,a);
          Question=Read("Do you want to add more numbers ? [0]: No  [1]: Yes");

      } while (Question);
  }


 //  function check number is not char 

 void checkIsNotChar() {
        int number;
        cin >> number;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "the input is Char , Please enter the number." << endl;
            cin >> number;
        }

    }
}



// _________________________________________________________________________________________________




namespace MyFile {

    void ReadfromFile(string message, vector <string>& moaaz) {
        fstream MyFile;
        MyFile.open(message, ios::in);

        string line;
        if (MyFile.is_open()) {
            while (getline(MyFile, line)) {
                moaaz.push_back(line);
            }
            MyFile.close();
        }
    }

    void saveMyfile(string message, vector <string>& moaaz) {
        fstream MyFile;
        MyFile.open(message, ios::out);

        if (MyFile.is_open()) {

            for (string moo : moaaz) {
                if (moo != "")
                    MyFile << moo << "\n";
            }

            MyFile.close();
        }
    }

    void EditfromComp(string message, string nameDelete, string nameEdit, vector <string>& moaaz) {

        for (string& moo : moaaz) {
            if (moo == nameDelete) {
                moo = nameEdit;
            }
        }
        saveMyfile(message, moaaz);

    }

    void printVector(vector <string>& moaaz) {
        for (string& num : moaaz) {
            if (num != "")
                cout << num << endl;
        }
    }

}



// _________________________________________________________________________________________________




namespace Time {

    void DatetimeStructure() {

        time_t t = time(0);
        tm* now = localtime(&t);

        cout << "year : " << now->tm_year + 1900 << endl;
        cout << "month : " << now->tm_mon << endl;
        cout << "day : " << now->tm_wday << endl;
        cout << "hour : " << now->tm_hour << endl;
        cout << "minute : " << now->tm_min << endl;

    }


    void DatetimeLocalUTCTime() {
        time_t t = time(0);
        char* dt = ctime(&t);
        cout << "Local date and time is: " << dt << "\n";
        tm* gmtm = gmtime(&t);
        dt = asctime(gmtm);
        cout << "UTC date and time is: " << dt;
    }



}



// _________________________________________________________________________________________________




namespace Cours7 {

    // Random Number 

    int RandomNumber(int From, int To) {
        int randum = rand() % (To - From + 1) + From;
        return randum;

    }

    // input of 2D Array

    void InputOfArray(int a[3][3], int Rows, int Cols) {
        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 3;j++) {
                a[i][j] = RandomNumber(1, 100);
            }
        }
    }

    // print of 2D Array 

    void print(int a[3][3], int Rows, int Cols) {
        cout << "the element of array : " << endl;
        for (int i = 0;i < Rows;i++) {
            for (int j = 0;j < Cols;j++) {
                cout << setw(3) << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Sum Of Rows

    int SumOfRowsArray(int a[3][3], int NumberRows, int coloms) {
        int sum = 0;
        for (int j = 0;j < coloms; j++) {
            sum += a[NumberRows][j];
        }
        return sum;
    }

    // print Sum Of Rows

    void PrintSumOfRowsArray(int a[3][3], int Rows, int Cols) {
        int sum = 0;
        cout << "\n\n_____ the sum of all row _____ \n\n\n";
        for (int i = 0;i < 3;i++) {
            cout << "the sum Of Row #" << i << " = " << SumOfRowsArray(a, i, Cols) << endl;;
        }
    }


    // function TranSpose
    void printTranSpose(int a[3][3], int b[3][3], int Rows, int Cols) {

        for (int i = 0;i < Rows;i++) {
            for (int j = 0;j < Cols;j++) {
                b[i][j] = a[j][i];
            }
        }
    }


    // functios print a + from array 3×3

    void MatrixColomsFun(int a[3][3], int MatrixColoms[3], int Rows, int Cols) {
        int midleCols = Cols / 2;
        for (int i = 0;i < Rows;i++) {
            MatrixColoms[i] = a[i][midleCols];
        }
    }

    void MatrixRowsFun(int a[3][3], int MatrixRows[3], int Rows, int Cols) {
        int midleRows = Rows / 2;
        for (int j = 0;j < Cols;j++) {
            MatrixRows[j] = a[midleRows][j];
        }
    }

    void print1DArray(int a[3], int length) {
        for (int i = 0;i < length;i++) {
            printf("%0*d ", 2, a[i]);
        }
    }


    // Check Palidrom Array 3×3 

    bool ChecPalidromArray(int a[3][3], int Rows, int Cols) {

        for (int i = 0;i < Rows;i++) {
            for (int j = 0;j < Cols / 2;j++) {

                if (a[i][j] != a[i][Cols - 1 - j]) {

                    return false;

                }
            }

        }

    }


    // min Number In Array 3×3

    int minNumberInArray(int a[3][3], int Rows, int Cols) {
        int min = a[0][0];
        for (int i = 0;i < Rows;i++) {
            for (int j = 0;j < Cols;j++) {

                if (a[i][j] < min) {
                    min = a[i][j];
                }

            }

        }
        return min;
    }


    // max Number In Array 3×3

    int maxNumberInArray(int a[3][3], int Rows, int Cols) {
        int max = a[0][0];
        for (int i = 0;i < Rows;i++) {
            for (int j = 0;j < Cols;j++) {

                if (a[i][j] > max) {
                    max = a[i][j];
                }

            }

        }
        return max;
    }


    // Check Numer In Array 3×3 

    bool CheckNumerInArray(int a[3][3], int number, int Rows, int Cols) {

        for (int i = 0;i < Rows;i++) {
            for (int j = 0;j < Cols;j++) {

                if (a[i][j] == number) {
                    return true;
                }

            }

        }
        return false;
    }

    // print Letter from fisrt any word 

    void PrintFirstLetter(string name) {

        bool isFirstLetter = true;

        for (int i = 0;i < name.length();i++) {

            if (name[i] != ' ' && isFirstLetter) {
                cout << name[i] << endl;
            }
            isFirstLetter = (name[i] == ' ' ? true : false);
        }
    }


    // convert first letter in all words to lower/upper 

    void PrintFirstLetterlower(string name) {

        bool isFirstLetter = true;

        for (int i = 0;i < name.length();i++) {

            if (name[i] != ' ' && isFirstLetter) {
                name[i] = tolower(name[i]);
            }
            isFirstLetter = (name[i] == ' ' ? true : false);
        }
        cout << name << endl;
    }

    //  convert all letter is string to lower/upper

    void AllLetterTolower(string name) {


        for (int i = 0;i < name.length();i++) {

            name[i] = tolower(name[i]);
        }
        cout << name << endl;
    }


    // convert upper <-> lower 

    char invertLetterCase(char name) {

        return (isupper(name) ? tolower(name) : toupper(name));

    }

    // function is a vowel ( a i e u o )

    bool isVowel(char cNum) {

        cNum = tolower(cNum);
        return ((cNum == 'a') || (cNum == 'e') || (cNum == 'i') || (cNum == 'u') || (cNum == 'o'));

    }


    // Count Letter Capital or small Letter

    int CountLetter(string name, char cNum, bool tr = true) {
        int counter = 0;
        for (int i = 0;i < name.length(); i++) {

            if (tr) {
                if (name[i] == cNum)
                    counter++;
            }
            else
                if (tolower(name[i]) == tolower(cNum))
                    counter++;

        }

        return counter;
    }

    // print letter's voewl ( a i e u o )

    void PrintLetterVoewl(string name) {

        cout << "the letter's voewl : ";

        for (int i = 0;i < name.length();i++) {

            if (isVowel(name[i])) {
                cout << name[i] << "  ";
            }
        }
    }


    // return counter the letter's voewl (a i e o u )  

    int checkaVowelNumber(string name) {

        int counter = 0;

        cout << "the letter's voewl : ";

        for (int i = 0;i < name.length();i++) {

            if (isVowel(name[i])) {
                counter++;
            }
        }
        return counter;
    }
    // ==========================================
// 1. تعريف هيكل البيانات (Data Structure)
// ==========================================
    struct stData {
        string AccountNumber;
        string PinCode;
        string Name;
        string Phone;
        string AccountBalance;
        bool MarkForDelete = false;
    };

    // ==========================================
    // 2. دوال مساعدة عامة (General Helpers)
    // ==========================================

    string ReadString(string message) {
        string text;
        cout << message;
        // مسح الـ buffer إذا كان في إدخال سابق لتجنب تخطي القراءة
        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin, text);
        return text;
    }

    int CountWords(string text) {
        string space = " ";
        int pos = 0;
        int counter = 0;
        string sWord;
        while ((pos = text.find(space)) != std::string::npos) {
            sWord = text.substr(0, pos);
            if (sWord != "") counter++;
            text = text.erase(0, pos + space.length());
        }
        if (text != "") counter++;
        return counter;
    }

    string TrimLeft(string text) {
        for (int i = 0; i < text.length(); i++) {
            if (text[i] != ' ') return text.substr(i);
        }
        return "";
    }

    string TrimRight(string text) {
        for (int i = text.length() - 1; i >= 0; i--) {
            if (text[i] != ' ') return text.substr(0, i + 1);
        }
        return "";
    }

    string Trim(string text) {
        return TrimRight(TrimLeft(text));
    }

    string JoinString(vector<string> vWords, string delimiter) {
        string s1 = "";
        for (string& word : vWords) {
            s1 = s1 + word + delimiter;
        }
        return s1.substr(0, s1.length() - delimiter.length());
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

    string ReverseWordsInString(string text) {
        string s1 = "";
        vector<string> vWords = SplitString(text, " ");
        vector <string>::iterator iter = vWords.end();
        while (iter != vWords.begin()) {
            --iter;
            s1 = s1 + *iter + " ";
        }
        return s1.substr(0, s1.length() - 1);
    }

    // ==========================================
    // 3. دوال التعامل مع العملاء والملفات (Client & File Functions)
    // ==========================================

    void ReadClientData(stData& Client) {
        Client.AccountNumber = ReadString("Enter Account Number? ");
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

    void AddNewClientToFile(string FileName, string separator) {
        stData Client;
        ReadClientData(Client);
        string LineData = ConvertRecordToLine(Client, separator);
        SaveLineToFile(FileName, LineData);
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

    // ==========================================
    // 4. دوال الطباعة والعرض (Print & Display Functions)
    // ==========================================

    void PrintClientRecord(stData Client) {
        cout << "|" << left << setw(20) << Client.AccountNumber
            << "|" << left << setw(20) << Client.PinCode
            << "|" << left << setw(20) << Client.Name
            << "|" << left << setw(20) << Client.Phone
            << "|" << left << setw(20) << Client.AccountBalance << endl;
    }

    void PrintAllClientsData(vector<stData> vClients) {
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
    }

    // ==========================================
    // 5. دوال بحث عن عميل وطباعته (ٍSearch Client And Print Functions)
    // ==========================================

    void PrintClient(stData s) {
        cout << "\n\nAccount Number : " << s.AccountNumber << endl;
        cout << "Pin Code : " << s.PinCode << endl;
        cout << "Name : " << s.Name << endl;
        cout << "Phone : " << s.Phone << endl;
        cout << "Account Balance : " << s.AccountBalance << endl;
    }

    void ShearchDataOFClient(string element, vector<stData> For) {
        for (stData& S : For) {
            if (S.AccountNumber == element) {
                PrintClient(S);
                return;
            }
        }
        cout << "Not Found " << endl;;
    }

    // ==========================================
    // 6. دوال الحذف  (Delete Functions)
    // ==========================================

    bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stData>& vClients) {
        for (stData& C : vClients) {
            if (C.AccountNumber == AccountNumber) {
                C.MarkForDelete = true; // وضع علامة الحذف
                return true;
            }
        }
        return false;
    }

    vector<stData> SaveCleintsDataToFile(string FileName, vector<stData> vClients) {
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

    // ==========================================
    // 7. دوال التعديل  (Upteded Functions)
    // ==========================================

    void InputDataUdapteClient(stData& S) {
        S.PinCode = Read("Enter the pinCode? ");
        S.Name = Read("Enter your name? ");
        S.Phone = Read("Enter your phone? ");
        S.AccountBalance = Read("Enter the Account Balance? ");
    }

    void UdapteDataClient(string AccountVumber, vector<stData>& For) {
        for (stData& S : For) {
            if (AccountVumber == S.AccountNumber) {
                InputDataUdapteClient(S);
                cout << "Client Udapted Successfully" << endl;
            }
        }
    }

    void RefreachDataInFile(string message, vector<stData>& For) {
        fstream MyFile;
        string str = "";

        MyFile.open(message, ios::out);
        if (MyFile.is_open()) {
            for (stData& S : For) {
                str = SaveLineOfData(S, "#//#");
                MyFile << str << endl;
            }
            MyFile.close();
        }
    }
}



// _________________________________________________________________________________________________



namespace cours8 {


    // check Leap Year
    bool checkLeapYear(int number) {

        if (number == 400) {
            return true;
        }
        else if (number % 100 == 0) {
            return false;
        }
        else if (number % 4 == 0) {
            return true;
        }
        else
            return false;
    }


    // check Leap Year in Line Of code
    bool CheckLeapYearInLineOfCode(int number) {
        return (number % 400 == 0 || (number % 4 == 0 && number % 100 != 0));
    }

    // Convert Month To Day 
    int MonthToDay(int number, int numberOfMonth) {
        if (numberOfMonth < 1 || numberOfMonth > 12) {
            return 0;
        }

        if (numberOfMonth == 2) {
            return CheckLeapYearInLineOfCode(number) ? 29 : 28;
        }

        string AllMonth31 = { 1,3,5,7,8,10,12 };

        for (int i = 0;i < AllMonth31.length();i++) {
            if (numberOfMonth == AllMonth31[i]) {
                return 31;
            }
        }
            
        return 30;
    }


    // Convert Month To Day  in Tow Line 
    int MonthToDay(int number, int numberOfMonth) {

        if (numberOfMonth < 1 || numberOfMonth > 12) {
            return 0;
        }

        int NumberOfMonth[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

        return (numberOfMonth == 2) ? (CheckLeapYearInLineOfCode(number) ? 29 : 28) : NumberOfMonth[numberOfMonth - 1];
    }


    // Day Of Week Order Function 
    int DayOfWeekOrder(int Year, int Month, int Day) {

        int a = (14 - Month) / 12;
        int y = Year - a;
        int m = Month + 12 * a - 2;

        int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }

    int DayOfWeekOrder(SData Data1) {
        return DayOfWeekOrder(Data1.Year, Data1.Month, Data1.Day);
    }


    string ChoiseDayString(int dayOfWeek) {
        string str[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        return str[dayOfWeek];
    }


    // Print Calnder Functions

    string ChoiseMonth(int month) {
        string str[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return str[month - 1];
    }

    void PrintCalnder(int Year, int Month, int Day) {
        int Add = 0;
        int count1 = DayOfWeekOrder(Year, Month, Day);
        int month = MonthToDay(Year, Month);
        for (int i = 1;i <= count1;i++) {
            cout << "    ";
            Add++;
        }
        for (int i = 1;i <= month;i++) {

            printf("%0*d  ", 2, i);
            Add++;

            if (Add == 7) {
                cout << endl;
                Add = 0;
            }
        }
    }

    void Print(int Year, int Month) {
        cout << "_____________" << ChoiseMonth(Month) << "_____________" << endl;
        cout << "Sun " << "Mon " << "Tue " << "Wed " << "Thu " << "Fri " << "Sat " << endl;
        PrintCalnder(Year, Month);
        cout << "\n_____________________________\n";
        system("pause");
    }


    // Print Date Frme numbers Of Days 
    struct SData {
        int Year;
        int Month;
        int Day;
    };

    void PrintDateFromNumbersOfDays(int NumbersOfDays, int Year, SData& Data) {
        SData Data;

        Data.Month = 1;
        Data.Year = Year;

        int MONTHMOQT;

        while (NumbersOfDays > 0) {

            MONTHMOQT = MonthToDay(Year, Data.Month);
            if (NumbersOfDays > MONTHMOQT) {

                NumbersOfDays = NumbersOfDays - MONTHMOQT;
                Data.Month++;

            }
            else
                break;

        }
        Data.Day = NumbersOfDays;

        cout << "Date is : " << Data.Day << "/" << Data.Month << "/" << Data.Year << endl;
    }


    //Numbers Of Days From Begin Month
    int NumbersOfDaysFromBeginMonth(int Year, int Month, int Day) {
        int TotalDay = 0;
        for (int i = 1;i <= Month - 1;i++) {
            TotalDay = TotalDay + MonthToDay(Year, i);
        }
        TotalDay = TotalDay + Day;
        return TotalDay;
    }


    // Function Date After The Add Day
    void DateAfterTheAddDay(SData& Data, int numberOfDay) {

        int SumAllDay = numberOfDay + NumbersOfDaysFromBeginMonth(Data.Year, Data.Month, Data.Day);
        int DayInMonth;
        Data.Month = 1;

        while (true) {
            DayInMonth = MonthToDay(Data.Year, Data.Month);

            if (SumAllDay > DayInMonth) {
                SumAllDay = SumAllDay - DayInMonth;
                Data.Month++;

                if (Data.Month > 12) {
                    Data.Month = 1;
                    Data.Year++;
                }
            }
            else {
                Data.Day = SumAllDay;
                break;
            }
        }
    }

    // What Date is Less from Date(tow)
    bool IsDate1BeforeDate2(SData Date1, SData Date2){
        return (Date1.Year < Date2.Year) ? true :
        ((Date1.Year == Date2.Year) ?
               (Date1.Month < Date2.Month ? true :
        (Date1.Month == Date2.Month ?
            Date1.Day < Date2.Day : false ))
            : false );
    }

    void PrintCheckTowDate(SData Data1, SData Data2) {
        if (IsDate1BeforeDate2(Data1, Data2)) {
            cout << "Date2 is less then Data1. " << endl;
        }
        else
            cout << "Date1 is less then Data2. " << endl;

    }

    // is Date1 Equel Date2
    bool isDateEquelDate2(SData Data1, SData Data2) {
        return ((Data1.Year == Data2.Year) ? ((Data1.Month == Data2.Month) ? ((Data1.Day == Data2.Day) ? true : false) : false) : false);
    }

    void PrintCheckTowDate(SData Data1, SData Data2) {
        if (isDateEquelDate2(Data1, Data2)) {
            cout << "yes, Date2 is Equel then Data1. " << endl;
        }
        else
            cout << "No, Date1 is Not Equel then Data2. " << endl;

    }


    // is Date1 After Date2
    bool isDate1AfterDate2(SData Date1, SData Date2) {
        return (!IsDate1BeforeDate2(Date1, Date2) && !isDateEquelDate2(Date1, Date2));
    }


    // check Day is Last in Month
    bool isDayIsLastInMonth(SData Data1) {
        return (Data1.Day == MonthToDay(Data1.Year, Data1.Month));
    }

    // check Month is Last in Year
    bool isMonthIsLAstInYear(SData Data1) {
        return ((Data1.Month == 12) ? true : false);
    }

    void PrintCheckTowDate(SData Data1) {
        if (isDayIsLastInMonth(Data1)) {
            cout << "Yes is Last Day in Month " << endl;
        }
        else
            cout << "No, is Not Last Day in Month " << endl;

        if (isMonthIsLAstInYear(Data1)) {
            cout << "Yes is Last Month in Year " << endl;
        }
        else
            cout << "No, is Not Last Month in Year " << endl;
    }

    // Increase Date By One Day
    SData IncreaseDateByOneDay(SData& Data1) {
        if (isDayIsLastInMonth(Data1)) {

            Data1.Day = 1;

            if (isMonthIsLAstInYear(Data1)) {
                Data1.Month = 1;
                Data1.Year++;
            }
            else
                Data1.Month++;

        }
        else
            Data1.Day++;

        return Data1;
    }


    // Calcute The Days Betwen Tow Date
    int CalcuteTheDaysBetwenTowDate(SData Data1, SData Data2, bool EndDay = false) {

        int Days = 0;
        while (!(isDateEquelDate2(Data1, Data2))) {

            Days++;
            Data1 = IncreaseDateByOneDay(Data1);
        }

        return (EndDay) ? ++Days : Days;
    }


    // Get Time Now 
    SData GetSystemDate() {
        SData Data;
        time_t t = time(0);
        tm* now = localtime(&t);

        Data.Year = now->tm_year + 1900;
        Data.Month = now->tm_mon + 1;
        Data.Day = now->tm_mday;

        return Data;
    }



    // Increase Day/Week/Month/Year

    SData IncreaseDateByXDay(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = IncreaseDateByOneDay(Data1);
        }

        return DataXDay;
    }

    SData IncreaseDateByOneWeek(SData& Data1) {

        SData DataXDay;
        for (int i = 0;i < 7;i++) {
            DataXDay = IncreaseDateByOneDay(Data1);
        }

        return DataXDay;
    }

    SData IncreaseDateByXWeek(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = IncreaseDateByOneWeek(Data1);
        }

        return DataXDay;
    }

    SData IncreaseDateByOneMonth(SData& Data1) {
        int DayOfMonth = MonthToDay(Data1.Year, Data1.Month);

        SData DataXDay;
        for (int i = 0;i < DayOfMonth;i++) {
            DataXDay = IncreaseDateByOneDay(Data1);
        }

        return DataXDay;
    }

    SData IncreaseDateByWMonth(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = IncreaseDateByOneMonth(Data1);
        }

        return DataXDay;
    }

    SData IncreaseDateByOneYear(SData& Data1) {

        Data1.Year = Data1.Year + 1;

        return Data1;
    }

    SData IncreaseDateByXYear(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = IncreaseDateByOneYear(Data1);
        }

        return DataXDay;
    }

    SData IncreaseDateByXYearFaster(SData& Data1, int X) {

        Data1.Year = Data1.Year + X;

        return Data1;
    }

    SData IncreaseDateByOneDecade(SData& Data1) {

        Data1.Year = Data1.Year + 10;

        return Data1;
    }

    SData IncreaseDateByXDecade(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = IncreaseDateByOneDecade(Data1);
        }

        return DataXDay;
    }

    SData IncreaseDateByXDecadeFaster(SData& Data1, int X) {

        Data1.Year = Data1.Year + X * 10;

        return Data1;
    }

    SData IncreaseDateByOneCentury(SData& Data1) {

        Data1.Year = Data1.Year + 100;

        return Data1;
    }

    SData IncreaseDateByOneMillennium(SData& Data1) {

        Data1.Year = Data1.Year + 1000;

        return Data1;
    }



    // Decrease Date By One Day Functions
    bool isDayIsFirstInMonth(SData Data1) {
        return (Data1.Day == 1);
    }

    bool isMonthIsFirstInYear(SData Data1) {
        return ((Data1.Month == 1) ? true : false);
    }


    SData DecreaseDateByOneDay(SData& Data1) {
        if (isDayIsFirstInMonth(Data1)) {

            if (isMonthIsFirstInYear(Data1)) {
                Data1.Month = 12;
                Data1.Day = 31;
                --Data1.Year;
            }
            else
                --Data1.Month;
            Data1.Day = MonthToDay(Data1.Year, Data1.Month);

        }
        else
            --Data1.Day;

        return Data1;
    }

    SData DecreaseDateByXDay(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = DecreaseDateByOneDay(Data1);
        }

        return DataXDay;
    }

    SData DecreaseDateByOneWeek(SData& Data1) {

        SData DataXDay;
        for (int i = 0;i < 7;i++) {
            DataXDay = DecreaseDateByOneDay(Data1);
        }

        return DataXDay;
    }

    SData DecreaseDateByXWeek(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = DecreaseDateByOneWeek(Data1);
        }

        return DataXDay;
    }

    SData DecreaseDateByOneMonth(SData& Data1) {

        if (Data1.Month == 1) {
            Data1.Month = 12;
            --Data1.Year;
        }
        else
            --Data1.Month;

        if (Data1.Day > MonthToDay(Data1.Year, Data1.Month)) {
            Data1.Day = MonthToDay(Data1.Year, Data1.Month);
        }

        return Data1;
    }

    SData DecreaseDateByWMonth(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = DecreaseDateByOneMonth(Data1);
        }

        return DataXDay;
    }

    SData DecreaseDateByOneYear(SData& Data1) {

        Data1.Year = Data1.Year - 1;

        return Data1;
    }

    SData DecreaseDateByXYear(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = DecreaseDateByOneYear(Data1);
        }

        return DataXDay;
    }

    SData DecreaseDateByXYearFaster(SData& Data1, int X) {

        Data1.Year = Data1.Year - X;

        return Data1;
    }

    SData DecreaseDateByOneDecade(SData& Data1) {

        Data1.Year = Data1.Year - 10;

        return Data1;
    }

    SData DecreaseDateByXDecade(SData& Data1, int X) {

        SData DataXDay;
        for (int i = 0;i < X;i++) {
            DataXDay = DecreaseDateByOneDecade(Data1);
        }

        return DataXDay;
    }

    SData DecreaseDateByXDecadeFaster(SData& Data1, int X) {

        Data1.Year = Data1.Year - X * 10;

        return Data1;
    }

    SData DecreaseDateByOneCentury(SData& Data1) {

        Data1.Year = Data1.Year - 100;

        return Data1;
    }

    SData DecreaseDateByOneMillennium(SData& Data1) {

        Data1.Year = Data1.Year - 1000;

        return Data1;
    }

    // More Functinos For Date :
    bool isEndOfWeek(int Reminder) {
        return (Reminder == 6);
    }

    bool isWeekEnd(int Reminder) {
        return (Reminder == 6 || Reminder == 5);
    }

    bool isBusiness(int Reminder) {
        return (!isWeekEnd(Reminder));
    }

    int UntilEndOfWeek(int Reminder) {
        return (6 - Reminder);
    }

    int UntilEndOfMonth(SData Data1) {

        SData Data2;
        Data2.Year = Data1.Year;
        Data2.Month = Data1.Month;
        Data2.Day = MonthToDay(Data1.Year, Data1.Month);


        return CalcuteTheDaysBetwenTowDate(Data1, Data2, true);
    }

    int UntilEndOfYear(SData Data1) {

        SData Data2;
        Data2.Year = Data1.Year;
        Data2.Month = 12;
        Data2.Day = 31;


        return CalcuteTheDaysBetwenTowDate(Data1, Data2, true);
    }


    // Date After The Add Day Without Weekend
    void DateAfterTheAddDayWithoutWeekend(SData& Data, int numberOfDay) {
        int WeekendCounter = 0;
        while (isWeekEnd(DayOfWeekOrder(Data))) {
            Data = IncreaseDateByOneDay(Data);
        }

        for (int i = 1;i <= numberOfDay + WeekendCounter;i++) {
            if (isWeekEnd(DayOfWeekOrder(Data))) {
                WeekendCounter++;
            }
            Data = IncreaseDateByOneDay(Data);
        }

        while (isWeekEnd(DayOfWeekOrder(Data))) {
            Data = IncreaseDateByOneDay(Data);
        }

    }

    enum BEA { eBefor = -1, eEquel = 0, eAfter = 1 };

    struct SPeriod {
        SData StartDate;
        SData EndDate;
    };

    SPeriod ReadPeriod() {
        SPeriod period;
        cout << "please enetr the start Date? " << endl;
        period.StartDate = ReadData();
        cout << "\nplease enetr the end Date? " << endl;
        period.EndDate = ReadData();

        return period;
    }

    int ReadNumber(string message) {
        int number;
        cout << message;
        cin >> number;

        return number;
    }


    SData ReadData() {
        SData Data;

        Data.Day = ReadNumber("please enter a Day? ");
        Data.Month = ReadNumber("please enter a Month? ");
        Data.Year = ReadNumber("please enter a year? ");
        cout << "\n";
        return Data;
    }

    SPeriod ReadPeriod() {
        SPeriod period;
        cout << "please enetr the start Date? " << endl;
        period.StartDate = ReadData();
        cout << "\nplease enetr the end Date? " << endl;
        period.EndDate = ReadData();

        return period;
    }

    BEA ReturnValueBEA(SData Data1, SData Data2) {
        if (IsDate1BeforeDate2(Data1, Data2)) {
            return BEA::eBefor;
        }
        else if (isDateEquelDate2(Data1, Data2)) {
            return BEA::eEquel;
        }
        else
            return BEA::eAfter;
    }


    // Is Data Within Period
    bool IsDataWithinPeriod(SPeriod period, SData Data) {
        return !(ReturnValueBEA(period.StartDate, Data) == BEA::eAfter || ReturnValueBEA(period.EndDate, Data) == BEA::eBefor);
    }


    //  Count OverLlap Days
    int CountOverLlapDays(SPeriod period, SPeriod period2) {

        int count1 = 0;
        int OverLlapDays2 = CalcuteTheDaysBetwenTowDate(period2.StartDate, period2.EndDate);
        int OverLlapDays1 = CalcuteTheDaysBetwenTowDate(period.StartDate, period.EndDate);

        if (OverLlapDays2 > OverLlapDays1) {

            while (ReturnValueBEA(period.StartDate, period.EndDate) == BEA::eBefor) {

                if (IsDataWithinPeriod(period2, period.StartDate))
                    count1++;

                period.StartDate = IncreaseDateByOneDay(period.StartDate);

            }
        }
        else {

            while (ReturnValueBEA(period2.StartDate, period2.EndDate) == BEA::eBefor) {

                if (IsDataWithinPeriod(period, period2.StartDate))
                    count1++;

                period2.StartDate = IncreaseDateByOneDay(period2.StartDate);

            }
        }
        return count1;
    }


    // Is Valid Date
    bool IsValidDate(SData Data) {
        return (Data.Month >= 1 && Data.Month <= 12 && Data.Day >= 1 && Data.Day <= MonthToDay(Data.Year, Data.Month));
    }


    // From Cours 7
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

    // string Date To Struct 
    SData StringToDate(SData& Data, string Date) {

        string str;
        vector<string> vStr;

        vStr = SplitString(Date, "/");
        Data.Day = stoi(vStr[0]);
        Data.Month = stoi(vStr[1]);
        Data.Year = stoi(vStr[2]);

        return Data;

    }


    // Struct To String Date 
    string DateToString(SData Data) {
        string str;
        str = to_string(Data.Day) + "/" + to_string(Data.Month) + "/" + to_string(Data.Year);
        return str;
    }



    string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
    {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
            pos = S1.find(StringToReplace);//find next
        }
        return S1;
    }
    

    string printDate(SData Data, string str) {

        str = ReplaceWordInString(str, "dd", to_string(Data.Day));
        str = ReplaceWordInString(str, "mm", to_string(Data.Month));
        str = ReplaceWordInString(str, "yyyy", to_string(Data.Year));

        return str;
    }

} 