#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include "clsString.h"

using namespace std;

class clsDate {
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;

public:
    // ==================== Constructors ====================
    clsDate() {
        time_t t = time(0);
        tm* now = localtime(&t);
        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;
    }

    clsDate(string sDate) {
        vector<string> vDate = clsString::Split(sDate, "/");
        _Day = stoi(vDate[0]);
        _Month = stoi(vDate[1]);
        _Year = stoi(vDate[2]);
    }

    clsDate(short Day, short Month, short Year) {
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short DateOrderInYear, short Year) {
        clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Date1.Year;
    }

    // ==================== Properties (Setters & Getters) ====================
    void SetDay(short Day) { _Day = Day; }
    short GetDay() { return _Day; }
    __declspec(property(get = GetDay, put = SetDay)) short Day;

    void SetMonth(short Month) { _Month = Month; }
    short GetMonth() { return _Month; }
    __declspec(property(get = GetMonth, put = SetMonth)) short Month;

    void SetYear(short Year) { _Year = Year; }
    short GetYear() { return _Year; }
    __declspec(property(get = GetYear, put = SetYear)) short Year;

    // ==================== Basic & Validation Functions ====================
    static clsDate GetSystemDate() {
        time_t t = time(0);
        tm* now = localtime(&t);
        return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
    }

    static bool isLeapYear(short Year) {
        return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
    }

    bool isLeapYear() {
        return isLeapYear(_Year);
    }

    static short MonthToDay(short Month, short Year) {
        if (Month < 1 || Month > 12) return 0;
        int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
    }

    static short MonthToDay(clsDate Date) {
        return MonthToDay(Date.Month, Date.Year);
    }

    short MonthToDay() {
        return MonthToDay(_Month, _Year);
    }

    static bool IsValidDate(clsDate Date) {
        return (Date.Month >= 1 && Date.Month <= 12 && Date.Day >= 1 && Date.Day <= MonthToDay(Date));
    }

    bool IsValid() {
        return IsValidDate(*this);
    }

    static string DateToString(clsDate Date) {
        return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
    }

    string DateToString() {
        return DateToString(*this);
    }

    void Print() {
        cout << DateToString() << endl;
    }

    static string GetSystemDateString(clsDate Date) {

        int Day = 1, Month = 1, Year = 1, Hour = 1, Minute = 1, Seconds = 1;

        time_t t = time(0);
        tm* now = localtime(&t);

        Day = now->tm_mday;
        Month = now->tm_mon + 1;
        Year = now->tm_year + 1900;
        Hour = now->tm_hour;
        Minute = now->tm_min;
        Seconds = now->tm_sec;

        string str = "";

        return DateToString(Date) + " - " + to_string(Hour) + ':' + to_string(Minute) + ':' + to_string(Seconds);

    }

    string GetSystemDateString() {
        return GetSystemDateString(*this);
    }

    // ==================== Year & Month Calculations ====================
    static short NumberOfDaysInAYear(short Year) {
        return isLeapYear(Year) ? 366 : 365; // تم إصلاح الخطأ (كان 365 : 364)
    }

    short NumberOfDaysInAYear() {
        return NumberOfDaysInAYear(_Year);
    }

    static short NumberOfHoursInAYear(short Year) {
        return NumberOfDaysInAYear(Year) * 24;
    }

    short NumberOfHoursInAYear() {
        return NumberOfHoursInAYear(_Year);
    }

    static int NumberOfMinutesInAYear(short Year) {
        return NumberOfHoursInAYear(Year) * 60;
    }

    int NumberOfMinutesInAYear() {
        return NumberOfMinutesInAYear(_Year);
    }

    static int NumberOfSecondsInAYear(short Year) {
        return NumberOfMinutesInAYear(Year) * 60;
    }

    int NumberOfSecondsInAYear() {
        return NumberOfSecondsInAYear(_Year); // تم إصلاح الاستدعاء الذاتي اللانهائي
    }

    // ==================== Day of Week & Calendar ====================
    static short DayOfWeekOrder(short Day, short Month, short Year) {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + (12 * a) - 2;
        return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
    }

    static short DayOfWeekOrder(clsDate Date) {
        return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    }

    short DayOfWeekOrder() {
        return DayOfWeekOrder(*this);
    }

    static string DayShortName(short DayOfWeekOrder) {
        string arrDayNames[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        return arrDayNames[DayOfWeekOrder];
    }

    static string DayShortName(clsDate Date) {
        return DayShortName(DayOfWeekOrder(Date));
    }

    string DayShortName() {
        return DayShortName(*this);
    }

    static string MonthShortName(short MonthNumber) {
        string Months[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        return Months[MonthNumber - 1];
    }

    string MonthShortName() {
        return MonthShortName(_Month);
    }

    static void PrintMonthCalendar(short Month, short Year) {
        int current = DayOfWeekOrder(1, Month, Year);
        int NumberOfDays = MonthToDay(Month, Year);

        printf("\n  _______________%s_______________\n\n", MonthShortName(Month).c_str());
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        int i;
        for (i = 0; i < current; i++)
            printf("     ");

        for (int j = 1; j <= NumberOfDays; j++) {
            printf("%5d", j);
            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }
        printf("\n  _________________________________\n");
    }

    void PrintMonthCalendar() {
        PrintMonthCalendar(_Month, _Year);
    }

    static void PrintYearCalendar(int Year) {
        printf("\n  _________________________________\n\n");
        printf("           Calendar - %d\n", Year);
        printf("  _________________________________\n");

        for (int i = 1; i <= 12; i++) {
            PrintMonthCalendar(i, Year);
        }
    }

    void PrintYearCalendar() {
        PrintYearCalendar(_Year);
    }

    // ==================== Days Order in Year ====================
    static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
        short TotalDays = 0;
        for (int i = 1; i <= Month - 1; i++) {
            TotalDays += MonthToDay(i, Year);
        }
        return TotalDays + Day;
    }

    short DaysFromTheBeginingOfTheYear() {
        return DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
    }

    static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year) {
        clsDate Date;
        short RemainingDays = DateOrderInYear;
        short MonthDays = 0;

        Date.Year = Year;
        Date.Month = 1;

        while (true) {
            MonthDays = MonthToDay(Date.Month, Date.Year);

            if (RemainingDays > MonthDays) {
                RemainingDays -= MonthDays;
                Date.Month++;

                if (Date.Month > 12) {
                    Date.Month = 1;
                    Date.Year++;
                }
            }
            else {
                Date.Day = RemainingDays;
                break;
            }
        }
        return Date;
    }

    void AddDays(short Days) {
        short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
        *this = GetDateFromDayOrderInYear(RemainingDays, _Year);
    }

    // ==================== Date Comparisons ====================
    static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2) {
        return (Date1.Year < Date2.Year) ? true :
            ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
                (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
    }

    bool isDate1BeforeDate2(clsDate Date2) {
        return isDate1BeforeDate2(*this, Date2);
    }

    static bool isDateEquelDate2(clsDate Date1, clsDate Date2) {
        return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
    }

    bool isDateEquelDate2(clsDate Date2) {
        return isDateEquelDate2(*this, Date2);
    }

    static bool isDate1AfterDate2(clsDate Date1, clsDate Date2) {
        return (!isDate1BeforeDate2(Date1, Date2) && !isDateEquelDate2(Date1, Date2));
    }

    bool isDate1AfterDate2(clsDate Date2) {
        return isDate1AfterDate2(*this, Date2);
    }

    enum enDateCompare { Before = -1, Equal = 0, After = 1 };

    static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {
        if (isDate1BeforeDate2(Date1, Date2)) return enDateCompare::Before;
        if (isDateEquelDate2(Date1, Date2)) return enDateCompare::Equal;
        return enDateCompare::After;
    }

    enDateCompare CompareDates(clsDate Date2) {
        return CompareDates(*this, Date2);
    }

    // ==================== Increase Date Functions ====================
    static bool isDayIsLastInMonth(clsDate Date) {
        return (Date.Day == MonthToDay(Date));
    }

    bool isDayIsLastInMonth() {
        return isDayIsLastInMonth(*this);
    }

    static bool isMonthIsLAstInYear(short Month) {
        return (Month == 12);
    }

    bool isMonthIsLAstInYear() {
        return isMonthIsLAstInYear(_Month);
    }

    static clsDate IncreaseDateByOneDay(clsDate& Date) {
        if (isDayIsLastInMonth(Date)) {
            if (isMonthIsLAstInYear(Date.Month)) {
                Date.Month = 1;
                Date.Day = 1;
                Date.Year++;
            }
            else {
                Date.Day = 1;
                Date.Month++;
            }
        }
        else {
            Date.Day++;
        }
        return Date;
    }

    void IncreaseDateByOneDay() {
        IncreaseDateByOneDay(*this);
    }

    static clsDate IncreaseDateByXDay(clsDate& Date, int Days) {
        for (int i = 0; i < Days; i++) {
            IncreaseDateByOneDay(Date);
        }
        return Date;
    }

    void IncreaseDateByXDay(int Days) {
        IncreaseDateByXDay(*this, Days);
    }

    static clsDate IncreaseDateByOneWeek(clsDate& Date) {
        return IncreaseDateByXDay(Date, 7);
    }

    void IncreaseDateByOneWeek() {
        IncreaseDateByOneWeek(*this);
    }

    static clsDate IncreaseDateByXWeeks(clsDate& Date, short Weeks) {
        for (short i = 0; i < Weeks; i++) {
            IncreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseDateByXWeeks(short Weeks) {
        IncreaseDateByXWeeks(*this, Weeks);
    }

    static clsDate IncreaseDateByOneMonth(clsDate& Date) {
        if (Date.Month == 12) {
            Date.Month = 1;
            Date.Year++;
        }
        else {
            Date.Month++;
        }

        short NumberOfDaysInCurrentMonth = MonthToDay(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth) {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    void IncreaseDateByOneMonth() {
        IncreaseDateByOneMonth(*this);
    }

    static clsDate IncreaseDateByXMonths(clsDate& Date, short Months) {
        for (short i = 0; i < Months; i++) {
            IncreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void IncreaseDateByXMonths(short Months) {
        IncreaseDateByXMonths(*this, Months);
    }

    static clsDate IncreaseDateByOneYear(clsDate& Date) {
        Date.Year++;
        return Date;
    }

    void IncreaseDateByOneYear() {
        IncreaseDateByOneYear(*this);
    }

    static clsDate IncreaseDateByXYears(clsDate& Date, short Years) {
        Date.Year += Years;
        return Date;
    }

    void IncreaseDateByXYears(short Years) {
        IncreaseDateByXYears(*this, Years); // تم إصلاح تمرير *this
    }

    static clsDate IncreaseDateByOneDecade(clsDate& Date) {
        Date.Year += 10;
        return Date;
    }

    void IncreaseDateByOneDecade() {
        IncreaseDateByOneDecade(*this);
    }

    static clsDate IncreaseDateByXDecades(clsDate& Date, short Decades) {
        Date.Year += Decades * 10;
        return Date;
    }

    void IncreaseDateByXDecades(short Decades) {
        IncreaseDateByXDecades(*this, Decades);
    }

    static clsDate IncreaseDateByOneCentury(clsDate& Date) {
        Date.Year += 100;
        return Date;
    }

    void IncreaseDateByOneCentury() {
        IncreaseDateByOneCentury(*this);
    }

    static clsDate IncreaseDateByOneMillennium(clsDate& Date) {
        Date.Year += 1000;
        return Date;
    }

    void IncreaseDateByOneMillennium() {
        IncreaseDateByOneMillennium(*this);
    }

    // ==================== Decrease Date Functions ====================
    static bool isDayIsFirstInMonth(clsDate Date) {
        return (Date.Day == 1);
    }

    bool isDayIsFirstInMonth() {
        return isDayIsFirstInMonth(*this);
    }

    static bool isMonthIsFirstInYear(short Month) {
        return (Month == 1);
    }

    bool isMonthIsFirstInYear() {
        return isMonthIsFirstInYear(_Month);
    }

    static clsDate DecreaseDateByOneDay(clsDate& Date) { // تم إضافة & لتعديل الكائن فعلياً
        if (isDayIsFirstInMonth(Date)) {
            if (isMonthIsFirstInYear(Date.Month)) {
                Date.Month = 12;
                Date.Day = 31;
                Date.Year--;
            }
            else {
                Date.Month--;
                Date.Day = MonthToDay(Date.Month, Date.Year);
            }
        }
        else {
            Date.Day--;
        }
        return Date;
    }

    void DecreaseDateByOneDay() {
        DecreaseDateByOneDay(*this);
    }

    static clsDate DecreaseDateByXDay(clsDate& Date, int Days) {
        for (int i = 0; i < Days; i++) {
            DecreaseDateByOneDay(Date);
        }
        return Date;
    }

    void DecreaseDateByXDay(int Days) {
        DecreaseDateByXDay(*this, Days);
    }

    static clsDate DecreaseDateByOneWeek(clsDate& Date) {
        return DecreaseDateByXDay(Date, 7);
    }

    void DecreaseDateByOneWeek() {
        DecreaseDateByOneWeek(*this);
    }

    static clsDate DecreaseDateByXWeeks(clsDate& Date, short Weeks) {
        for (short i = 0; i < Weeks; i++) {
            DecreaseDateByOneWeek(Date);
        }
        return Date;
    }

    void DecreaseDateByXWeeks(short Weeks) {
        DecreaseDateByXWeeks(*this, Weeks);
    }

    static clsDate DecreaseDateByOneMonth(clsDate& Date) {
        if (Date.Month == 1) {
            Date.Month = 12;
            Date.Year--;
        }
        else {
            Date.Month--;
        }

        short NumberOfDaysInCurrentMonth = MonthToDay(Date.Month, Date.Year);
        if (Date.Day > NumberOfDaysInCurrentMonth) {
            Date.Day = NumberOfDaysInCurrentMonth;
        }
        return Date;
    }

    void DecreaseDateByOneMonth() {
        DecreaseDateByOneMonth(*this);
    }

    static clsDate DecreaseDateByXMonths(clsDate& Date, short Months) {
        for (short i = 0; i < Months; i++) {
            DecreaseDateByOneMonth(Date);
        }
        return Date;
    }

    void DecreaseDateByXMonths(short Months) {
        DecreaseDateByXMonths(*this, Months);
    }

    static clsDate DecreaseDateByOneYear(clsDate& Date) {
        Date.Year--;
        return Date;
    }

    void DecreaseDateByOneYear() {
        DecreaseDateByOneYear(*this);
    }

    static clsDate DecreaseDateByXYears(clsDate& Date, short Years) {
        Date.Year -= Years;
        return Date;
    }

    void DecreaseDateByXYears(short Years) {
        DecreaseDateByXYears(*this, Years);
    }

    static clsDate DecreaseDateByOneDecade(clsDate& Date) {
        Date.Year -= 10;
        return Date;
    }

    void DecreaseDateByOneDecade() {
        DecreaseDateByOneDecade(*this);
    }

    static clsDate DecreaseDateByXDecades(clsDate& Date, short Decades) {
        Date.Year -= Decades * 10;
        return Date;
    }

    void DecreaseDateByXDecades(short Decades) {
        DecreaseDateByXDecades(*this, Decades);
    }

    static clsDate DecreaseDateByOneCentury(clsDate& Date) {
        Date.Year -= 100;
        return Date;
    }

    void DecreaseDateByOneCentury() {
        DecreaseDateByOneCentury(*this);
    }

    static clsDate DecreaseDateByOneMillennium(clsDate& Date) {
        Date.Year -= 1000;
        return Date;
    }

    void DecreaseDateByOneMillennium() {
        DecreaseDateByOneMillennium(*this);
    }

    // ==================== Difference & Age Functions ====================
    static void SwapDates(clsDate& Date1, clsDate& Date2) {
        clsDate TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    static int CalcuteTheDaysBetwenTowDate(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
        int Days = 0;
        short SwapFlagValue = 1;

        if (!isDate1BeforeDate2(Date1, Date2)) {
            SwapDates(Date1, Date2);
            SwapFlagValue = -1;
        }

        while (isDate1BeforeDate2(Date1, Date2)) {
            Days++;
            IncreaseDateByOneDay(Date1);
        }

        return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
    }

    int CalcuteTheDaysBetwenTowDate(clsDate Date2, bool IncludeEndDay = false) {
        return CalcuteTheDaysBetwenTowDate(*this, Date2, IncludeEndDay);
    }

    static int CalculateMyAgeInDays(clsDate DateOfBirth) {
        return CalcuteTheDaysBetwenTowDate(DateOfBirth, clsDate::GetSystemDate(), true);
    }

    // ==================== Weekends, Vacations & Business Days ====================
    static bool isEndOfWeek(clsDate Date) {
        return DayOfWeekOrder(Date) == 6;
    }

    bool isEndOfWeek() {
        return isEndOfWeek(*this);
    }

    static bool isWeekEnd(clsDate Date) {
        short DayIndex = DayOfWeekOrder(Date);
        return (DayIndex == 5 || DayIndex == 6);
    }

    bool isWeekEnd() {
        return isWeekEnd(*this);
    }

    static bool isBusiness(clsDate Date) {
        return !isWeekEnd(Date);
    }

    bool isBusiness() {
        return isBusiness(*this);
    }

    static short UntilEndOfWeek(clsDate Date) {
        return 6 - DayOfWeekOrder(Date);
    }

    short UntilEndOfWeek() {
        return UntilEndOfWeek(*this);
    }

    static short UntilEndOfMonth(clsDate Date) {
        clsDate EndOfMonthDate(MonthToDay(Date), Date.Month, Date.Year);
        return CalcuteTheDaysBetwenTowDate(Date, EndOfMonthDate, true);
    }

    short UntilEndOfMonth() {
        return UntilEndOfMonth(*this);
    }

    static short UntilEndOfYear(clsDate Date) {
        clsDate EndOfYearDate(31, 12, Date.Year);
        return CalcuteTheDaysBetwenTowDate(Date, EndOfYearDate, true);
    }

    short UntilEndOfYear() {
        return UntilEndOfYear(*this);
    }

    static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo) {
        short Days = 0;
        while (isDate1BeforeDate2(DateFrom, DateTo)) {
            if (isBusiness(DateFrom))
                Days++;
            IncreaseDateByOneDay(DateFrom);
        }
        return Days;
    }

    static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo) {
        return CalculateBusinessDays(DateFrom, DateTo);
    }

    static void DateAfterTheAddDayWithoutWeekend(clsDate& Data, int numberOfDay) {
        int WeekendCounter = 0;
        while (isWeekEnd(Data)) { // تم إصلاح تمرير Data مباشرة بدلاً من النص
            IncreaseDateByOneDay(Data);
        }

        for (int i = 1; i <= numberOfDay + WeekendCounter; i++) {
            if (isWeekEnd(Data)) {
                WeekendCounter++;
            }
            IncreaseDateByOneDay(Data);
        }

        while (isWeekEnd(Data)) {
            IncreaseDateByOneDay(Data);
        }
    }

    void DateAfterTheAddDayWithoutWeekend(int numberOfDay) {
        DateAfterTheAddDayWithoutWeekend(*this, numberOfDay);
    }
};