#include <iostream>
#include<vector>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money{
    long allCents;
    int digitToInt(char digit) {return (int)digit - (int)0;}

public:
    Money(double amount);
    Money() : allCents(0) {}
    long getValue() const {return allCents;}
    void setValue(double newAmount);
    Money operator+(const Money& rhs);
    Money operator-(const Money& rhs);
    Money& operator=(const Money& rhs);
    Money& operator+=(const Money& rhs);
    Money& operator-=(const Money& rhs);
    friend ostream& operator<<(ostream& outs, const Money& rhs);
    friend istream& operator>>(istream& ins, Money& rhs);
};

class Check{
    int checkNumber;
    Money checkAmount;
    bool cashed;

    public:
    Check(int newCheckNumber, double newCheckAmount, int newCashed);
    Check() : checkNumber(0), checkAmount(0), cashed(0) {}
    Money getCheckAmount() const {return checkAmount;}
    int getCheckNumber() const {return checkNumber;}
    bool isCashed() {return cashed;}
    void setCheckAmount(double newAmount) {checkAmount = newAmount;}
    void setCheckNumber(int newNumber) {checkNumber = newNumber;}
    void setCashed(int trueFalse);
    Check operator+(const Check& rhs);
    Check operator-(const Check& rhs);
    Check& operator=(const Check& rhs);
    Check& operator+=(const Check& rhs);
    Check& operator-=(const Check& rhs);
    friend ostream& operator<<(ostream& outs, const Check& rhs);
    friend istream& operator>>(istream& ins, Check& rhs);
    };

void readChecks(vector<Check>& checkVec);
Money sumChecksVector (const vector<Check>& checkVector);
Money sumUncashedChecksVector (const vector<Check>& checkVector);
Money sumCashedChecksVector(const vector<Check>& checkVector);
void readDeposits(vector<Money>& depositVector);
Money sumDeposits(const vector<Money>& depositVector);
void readOldAccountBalance(Money& oldAccountBal);
Money findBankAccountBalance(const Money& oldAccountBal, const vector<Money>& depositVector, const vector<Check>& checkVector);
Money findNewAccountBalance(const Money& oldAccountBal, const vector<Money>& depositVector, const vector<Check>& checkVector);
Money calcAccountsDifference(const Money& bankAccountBalance, const Money& newAccountBalance);
void sortChecks(vector<Check>& checkVector);
void displayCashedChecks(const vector<Check>& checkVector);
void displayUncashedChecks(const vector<Check>& checkVector);
int main() {
    vector<Check> checkVector;
    vector<Money> depositVector;
    Money oldAccountBalance, bankAccountBalance, newAccountBalance;


    readOldAccountBalance(oldAccountBalance);
    readDeposits(depositVector);
    readChecks(checkVector);
    bankAccountBalance = findBankAccountBalance(oldAccountBalance, depositVector, checkVector);
    newAccountBalance = findNewAccountBalance(oldAccountBalance, depositVector, checkVector);
    calcAccountsDifference(bankAccountBalance, newAccountBalance);
    sortChecks(checkVector);
    displayCashedChecks(checkVector);
    displayUncashedChecks(checkVector);

    return 0;
}

Money::Money(double value){

    allCents = value * 100;
}

void Money::setValue(double newValue){

        allCents = newValue * 100;
};

Money Money::operator+(const Money& rhs){
    Money temp;
    temp.allCents = allCents + rhs.allCents;

    return temp;
}

Money Money::operator-(const Money& rhs){
    Money temp;
    temp.allCents = allCents - rhs.allCents;

    return temp;
}

Money& Money::operator=(const Money& rhs){
    allCents = rhs.allCents;

    return *this;
}

Money& Money::operator+=(const Money& rhs){
    allCents += rhs.allCents;

    return *this;
}

Money& Money::operator-=(const Money& rhs){
    allCents -= rhs.allCents;

    return *this;
}

ostream& operator<<(ostream& outs, const Money& rhs){
    long dollars, cents, positiveCents;
    positiveCents = labs(rhs.allCents);
    dollars = positiveCents/100;
    cents = positiveCents%100;

    if(rhs.allCents < 0)
        outs<<"-$"<<dollars<<".";
    else
        outs<<"$"<<dollars<<".";
    if(cents < 10)
        outs<<"0"<<cents;
    else
    outs<<cents;

    return outs;
}

istream& operator>>(istream& ins, Money& rhs){
    double userInput;

    ins>>userInput;
    rhs.allCents = userInput * 100;

    return ins;
}

Check::Check(int newCheckNumber, double newCheckAmount, int newCashed){
    if(newCheckNumber <= 0){
        cout<<"Invalid check number.\n";
        exit(1);
    }
    checkNumber = newCheckNumber;

    if(newCheckAmount <= 0){
        cout<<"Invalid check amount.\n";
        exit(1);
    }

    checkAmount = newCheckAmount;

    if(newCashed == 0)
        cashed = false;
    else if(newCashed == 1)
        cashed = true;
    else {
        cout << "Invalid input for Cashed/Uncashed";
        exit(1);
    }
}

void Check::setCashed(int trueFalse) {
    if(trueFalse == 0)
        cashed = false;
    else if(trueFalse == 1)
        cashed = true;
    else {
        cout << "Invalid input for Cashed/Uncashed";
        exit(1);
    }
}

Check Check::operator+(const Check& rhs){
    Check temp;
    temp.checkAmount = checkAmount + rhs.checkAmount;

    return temp;
}

Check Check::operator-(const Check& rhs){
    Check temp;
    temp.checkAmount = checkAmount - rhs.checkAmount;

    return temp;
}

Check& Check::operator=(const Check& rhs){
    checkAmount = rhs.checkAmount;
    checkNumber = rhs.checkNumber;
    cashed = rhs.cashed;

    return *this;
}

Check& Check::operator+=(const Check& rhs){
    checkAmount += rhs.checkAmount;

    return *this;
}

Check& Check::operator-=(const Check& rhs){
    checkAmount -= rhs.checkAmount;

    return *this;
}

ostream& operator<<(ostream& outs, const Check& rhs){
    outs<<"Check #"<<rhs.checkNumber<<endl;
    outs<<"Check Amount: "<<rhs.checkAmount<<endl;
    if(rhs.cashed)
        outs<<"Cashed\n";
    else
        outs<<"Not Cashed\n";

    return outs;
}

istream& operator>>(istream& ins, Check& rhs){
    Money amount;
    int number, oneTwo;

    ins>>number;
    if(number > 0)
        rhs.checkNumber = number;
    else{
        cout<<"Invalid check number.";
        exit(1);
    }

    ins>>amount;
    if(amount.getValue() >= 1)
        rhs.checkAmount = amount;
    else{
        cout<<"Invalid check amount.";
        exit(1);
    }

    ins>>oneTwo;
    if(oneTwo == 1)
        rhs.cashed = false;
    else if(oneTwo == 0)
        rhs.cashed = true;
    else{
        cout << "Invalid input for Cashed/Uncashed.";
        exit(1);
    }

    return ins;
}

void readChecks(vector<Check>& checkVector){
    vector<Check> newCheckVector;
    int currCheckNumber;
    double currCheckAmount;
    int currCashed;
    bool seenNegative;

    cout<<"Please enter a series of check numbers and check amounts,\n"
        << "and indicate whether or not each check has already been cashed \n"
        <<"by typing 0 for not cashed or 1 for cashed.\n"
        <<"End the series by typing -1 as the check number.\n";

    seenNegative = false;
    while(!seenNegative){
        cout<<"Check Number (-1 to finish): ";
        cin>>currCheckNumber;
        if(currCheckNumber == -1)
            seenNegative = true;
        else{
        cout<<"Check Amount: $";
        cin>>currCheckAmount;
        cout<<"Check Cashed? (1 for Cashed, 0 for Not Cashed): ";
        cin>>currCashed;
        Check currCheck(currCheckNumber, currCheckAmount, currCashed);
        newCheckVector.push_back(currCheck);
        }
    }
    checkVector = newCheckVector;
}

Money sumChecksVector (const vector<Check>& checkVector){
    Check sumChecks;

    for(auto i : checkVector)
        sumChecks += i;

    return sumChecks.getCheckAmount();
}

Money sumUncashedChecksVector (const vector<Check>& checkVector){
    Check sumChecks;

    for(auto i : checkVector) {
        if(!i.isCashed())
        sumChecks += i;
    }

    return sumChecks.getCheckAmount();
}

Money sumCashedChecksVector(const vector<Check>& checkVector){
    Check sumCashedChecks;
    for(auto i: checkVector) {
        if (i.isCashed())
            sumCashedChecks += i;
    }

    return sumCashedChecks.getCheckAmount();
}

void readDeposits(vector<Money>& depositVector){
    Money currDeposit;
    vector<Money> newDepositVector;
    bool seenNegative;

    cout<<"Please enter all deposits. End series by entering -1\n";

    seenNegative = false;
    while(!seenNegative){
        cin>>currDeposit;
        if(currDeposit.getValue() == -100)
            seenNegative = true;
        else
            newDepositVector.push_back(currDeposit);
    }
    depositVector = newDepositVector;
}

Money sumDeposits(const vector<Money>& depositVector){
    Money sumDeposits;

    for(auto i: depositVector)
        sumDeposits += i;

    return sumDeposits;
}

void readOldAccountBalance(Money& oldAccountBal){
    cout<<"Please input old account balance: $";
    cin>>oldAccountBal;
};

Money findBankAccountBalance(const Money& oldAccountBal, const vector<Money>& depositVector, const vector<Check>& checkVector){
    Money newAccountBalance, newSumDeposits, newSumChecks;

    newSumDeposits = sumDeposits(depositVector);
    newSumChecks = sumCashedChecksVector(checkVector);

    newAccountBalance += oldAccountBal;
    newAccountBalance += newSumDeposits;
    newAccountBalance -= newSumChecks;

    cout<<"\nThe bank says your account balance is: "<<newAccountBalance<<endl;

    return newAccountBalance;
}

Money findNewAccountBalance(const Money& oldAccountBal, const vector<Money>& depositVector, const vector<Check>& checkVector){
    Money newAccountBalance, newSumDeposits, newSumChecks;

    newSumDeposits = sumDeposits(depositVector);
    newSumChecks = sumChecksVector(checkVector);

    newAccountBalance += oldAccountBal;
    newAccountBalance += newSumDeposits;
    newAccountBalance -= newSumChecks;

    cout<<"\nYour account balance, including all uncashed checks, is: "<<newAccountBalance<<endl;

    return newAccountBalance;
}

Money calcAccountsDifference(const Money& bankAccountBalance, const Money& newAccountBalance){
    Money accountDifference;

    accountDifference += bankAccountBalance;
    accountDifference -= newAccountBalance;

    cout<<"\nThe difference between what the Bank says your balance is\n";
    cout<<"and what your new balance is comes to: "<<accountDifference<<endl;

    return accountDifference;
}

void sortChecks(vector<Check>& checkVector) {
    int vectorSize;
    int i, j;

    vectorSize = checkVector.size();
    for (i = 0; i < vectorSize; i++) {
        for (j = i + 1; j < vectorSize; j++) {
            if (checkVector[j].getCheckNumber() < checkVector[i].getCheckNumber()) {
                swap(checkVector[i], checkVector[j]);
            }
        }
    }
}

void displayCashedChecks(const vector<Check>& checkVector){
    cout<<"\nCashed checks:\n";
    for(auto i : checkVector){
        if(i.isCashed())
            cout<<i<<endl;
    }
}

void displayUncashedChecks(const vector<Check>& checkVector){
    cout<<"Uncashed checks:\n";
    for(auto i : checkVector){
        if(!i.isCashed())
            cout<<i<<endl;
    }
}