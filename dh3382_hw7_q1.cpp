#include <iostream>
using namespace std;

const int THIRTY_DAYS = 30, THIRTY_ONE_DAYS = 31, TWENTY_EIGHT_DAYS = 28, TWENTY_NINE_DAYS = 29;

int printMonthCalendar(int numOfDays, int startingDay);
bool isItALeapYear(int year);
void printYearCalendar(int year, int startingDay);
int main() {
    int year, dayOfWeek;

    cout<<"Please input a calendar year (format: YYYY):"<<endl;
    cin>>year;
    cout<<"Please input a number 1-7 representing the day of the week on which\n"
    <<"your chosen year begins (e.g. 1 = Monday, 2 = Tuesday, etc.):"<<endl;
    cin>>dayOfWeek;
    cout<<"Here's a pretty calendar:"<<endl<<endl;
    printYearCalendar(year, dayOfWeek);
}

int printMonthCalendar(int numOfDays, int startingDay) {
    int dayCount, currDay, tabCount;

    cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;

    if(startingDay > 7)         //avoid starting on day '8' when calling printYearCalendar, will also run if user input > 7
        startingDay %= 7;

    if(startingDay != 0) {
        for(tabCount = startingDay; tabCount > 1; tabCount--){
            cout<<"\t";
        }
    }

    dayCount = 1;
    currDay = startingDay;
    while(dayCount <= numOfDays) {
        cout<<dayCount<<"\t";

        if(currDay == 7) {
            cout << endl;
            currDay = 0;
        }

        dayCount++;

        if(dayCount != numOfDays)   //avoid incrementing currDay on last iteration
        currDay++;
    }
    cout<<endl<<endl;

    return currDay;
}

bool isItALeapYear(int year){
    bool itsALeapYear;

    itsALeapYear = false;
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        itsALeapYear = true;

    return itsALeapYear;
}

void printYearCalendar(int year, int startingDay){
    int currStartingDay;
    currStartingDay = startingDay;

    cout<<"January "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_ONE_DAYS, currStartingDay) + 1;

    cout<<"February "<<year<<endl;
    if(!isItALeapYear(year))
        currStartingDay = printMonthCalendar(TWENTY_EIGHT_DAYS, currStartingDay) + 1;
    else
        currStartingDay = printMonthCalendar(TWENTY_NINE_DAYS, currStartingDay) + 1;

    cout<<"March "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_ONE_DAYS, currStartingDay) + 1;

    cout<<"April "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_DAYS, currStartingDay) + 1;

    cout<<"May "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_ONE_DAYS, currStartingDay) + 1;

    cout<<"June "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_DAYS, currStartingDay) + 1;

    cout<<"July "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_ONE_DAYS, currStartingDay) + 1;

    cout<<"August "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_ONE_DAYS, currStartingDay) + 1;

    cout<<"September "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_DAYS, currStartingDay) + 1;

    cout<<"October "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_ONE_DAYS, currStartingDay) + 1;

    cout<<"November "<<year<<endl;
    currStartingDay = printMonthCalendar(THIRTY_DAYS, currStartingDay) + 1;

    cout<<"December "<<year<<endl;
   printMonthCalendar(THIRTY_ONE_DAYS, currStartingDay);
}
