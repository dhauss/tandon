#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class List;

struct EmployeeData{
    string name;
    double amountOwed;
};

class Employee{
    int id;
    double wage;
    string name;
    int hoursWorked;
    double amountOwed;
    Employee* next;
    Employee* prev;
public:
    Employee(int newID = 0, double newWage = 0, string newName = "N/A", int newHoursWorked = 0, double newAmountOwed = 0, Employee* newNext = nullptr, Employee* newPrev = nullptr)
                : id(newID), wage(newWage), name(newName), hoursWorked(newHoursWorked), amountOwed(newAmountOwed), next(newNext), prev(newPrev) {}
    int get_id() const {return id;}
    double get_wage() const {return wage;}
    string get_name() const {return name;}
    double get_amount_owed() const {return amountOwed;}
    void set_hours(int hours) {hoursWorked = hours;}
    void calc_amount_owed() {amountOwed = static_cast<double>(hoursWorked) * wage;}
    friend bool operator <(const Employee& emp1, const Employee& emp2);
    friend class List;
};

class List{
    Employee* head;
    Employee* tail;
public:
    List();
    ~List();
    List(const List& rhs);
    List& operator=(const List& rhs);
    bool isEmpty() {return head->next == tail;}
    void clear() {while(!isEmpty()) pop_front();}
    void push_back(int newID, double newWage, string newName, int newHoursWorked, double newAmountOwed);
    void push_front(int newID, double newWage, string newName, int newHoursWorked, double newAmountOwed);
    void pop_front();
    void pop_back();
    void add_hours(int id, int newHours);
    void calc_amount_owed_employee();
    void fill_payroll_vector(vector<EmployeeData>& employeeVector);
    void mergesort_payroll_vector (vector<EmployeeData>& vector);
    void mergesort_payroll_vector (vector<EmployeeData>& vector, size_t start, size_t end, std::vector<EmployeeData>& temp);
    void merge_payroll_vector (vector<EmployeeData>& vector, size_t lowLeft, size_t highLeft, size_t highRight, std::vector<EmployeeData>& temp);
    void print_payroll();
    void print();
};

void makeEmployeeFile();
void makeHoursFile();
void openInputFile(ifstream& employeeInFile);
int main() {
    List myList;
    vector<EmployeeData> empVec;
    int tempID, tempHours, tempWage;
    string tempName;
    ifstream employeeInFile;
    ifstream hoursInFile;

    makeEmployeeFile();
    cout<<"To open employee file, ";
    openInputFile(employeeInFile);
    while(employeeInFile >> tempID){
        employeeInFile >> tempWage;
        employeeInFile.ignore(9999, ' ');
        getline(employeeInFile, tempName);
        myList.push_back(tempID, tempWage, tempName, 0, 0);
    }

    makeHoursFile();
    cout<<"To open hours file, ";
    openInputFile(hoursInFile);
    while(hoursInFile >> tempID){
        hoursInFile>>tempHours;
        myList.add_hours(tempID, tempHours);
    }
    myList.print_payroll();

    return 0;
}
bool operator <(const Employee& emp1, const Employee& emp2){
    return emp1.amountOwed > emp2.amountOwed;
}

List::List(){
    head = new Employee;
    tail = new Employee;
    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;
}

List::~List(){
    clear();
    delete head;
    delete tail;
}

List::List(const List &rhs) {
    head = new Employee;
    tail = new Employee;
    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;
    *this = rhs;
}

List& List::operator=(const List &rhs) {
    if(this == &rhs)
        return *this;
    clear();
    Employee* temp = rhs.head->next;
    while(temp != rhs.tail) {
        push_back(temp->id, temp->wage, temp->name, temp->hoursWorked, temp->hoursWorked);
        temp = temp->next;
    }
    return *this;
}

void List::push_back(int newID, double newWage, string newName, int newHoursWorked, double newAmountOwed) {
    tail->prev = new Employee(newID, newWage, newName, newHoursWorked, newAmountOwed, tail, tail->prev);
    tail->prev->prev->next = tail->prev;
}

void List::push_front(int newID, double newWage, string newName, int newHoursWorked, double newAmountOwed) {
    head->next = new Employee(newID, newWage, newName, newHoursWorked, newAmountOwed, head->next, head);
    head->next->next->prev = head->next;
}

void List::pop_front() {
    if(head->next == tail)
        return;
    Employee* nodeToDelete = head->next;
    head->next = nodeToDelete->next;
    nodeToDelete->next->prev = nodeToDelete->prev;
    delete nodeToDelete;
}

void List::pop_back() {
    if(head->next == tail)
        return;
    Employee* nodeToDelete = tail->prev;
    tail->prev = nodeToDelete->prev;
    nodeToDelete->prev->next = nodeToDelete->next;
    delete nodeToDelete;
}

void List::add_hours(int id, int newHours){
    Employee* tempEmp = head->next;

    while(tempEmp != tail) {
        if (id == tempEmp->id)
            tempEmp->hoursWorked += newHours;
        tempEmp = tempEmp->next;
    }
}

void List::calc_amount_owed_employee(){
    Employee* tempEmp = head->next;

    while(tempEmp != tail) {
        tempEmp->amountOwed = static_cast<double>(tempEmp->hoursWorked) * tempEmp->wage;
        tempEmp = tempEmp->next;
    }
}

void List::fill_payroll_vector(vector<EmployeeData>& employeeVector){
    EmployeeData tempEmpData;
    Employee* tempEmp = head->next;

    while(tempEmp != tail) {
        tempEmpData.amountOwed = tempEmp->amountOwed;
        tempEmpData.name = tempEmp->name;
        employeeVector.push_back(tempEmpData);
        tempEmp = tempEmp->next;
    }
}

void List::mergesort_payroll_vector (vector<EmployeeData>& vector){
    std::vector<EmployeeData> temp;
    temp.resize(vector.size());
    mergesort_payroll_vector(vector, 0, vector.size() - 1, temp);
}

void List::mergesort_payroll_vector (vector<EmployeeData>& vector, size_t start, size_t end, std::vector<EmployeeData>& temp){
    if(start < end){
        size_t mid = (start + end)/2;
        mergesort_payroll_vector(vector, start, mid, temp);
        mergesort_payroll_vector(vector, mid + 1, end, temp);
        merge_payroll_vector(vector, start, mid, end, temp);
    }
}

void List::merge_payroll_vector (vector<EmployeeData>& vector, size_t lowLeft, size_t highLeft, size_t highRight, std::vector<EmployeeData>& temp){
    size_t originalStart = lowLeft;
    size_t tempPos = lowLeft;
    size_t lowRight = highLeft + 1;

    while(lowLeft <= highLeft && lowRight <= highRight){
        if(vector[lowLeft].amountOwed > vector[lowRight].amountOwed)
            temp[tempPos++] = vector[lowLeft++];
        else
            temp[tempPos++] = vector[lowRight++];
    }

    while(lowLeft <= highLeft)
        temp[tempPos++] = vector[lowLeft++];
    while(lowRight <= highRight)
        temp[tempPos++] = vector[lowRight++];

    for(size_t i = originalStart; i <= highRight; i++)
        vector[i] = temp[i];
}

void List::print_payroll(){
    vector<EmployeeData> empDataVector;
    size_t size;

    calc_amount_owed_employee();
    fill_payroll_vector(empDataVector);
    mergesort_payroll_vector(empDataVector);
    size = empDataVector.size();

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"*********Payroll Information********\n";
    for(int i = 0; i < size; i++)
        cout<<empDataVector[i].name<<", $"<<empDataVector[i].amountOwed<<endl;
    cout<<"*********End Payroll****************\n";
}

void List::print() {
    Employee* empPtr = head->next;
    while(empPtr != tail){
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout<<empPtr->id<<" "<<empPtr->wage<<" "<<empPtr->name<<" "<<empPtr->hoursWorked<<" "<<empPtr->amountOwed<<endl;
        empPtr = empPtr->next;
    }
}

void makeEmployeeFile() {
    ofstream employeeFile("employeeFile.txt");

    employeeFile << "1 7.75 Charles Mingus\n";
    employeeFile << "2 6.51 Dezron Douglas\n";
    employeeFile << "3 6.75 Scott LaFaro\n";
    employeeFile << "4 5.03 Pino Palladino\n";
    employeeFile << "5 5.52 Ron Carter\n";
    employeeFile << "6 6.54 NHOP\n";
    employeeFile.close();
}

void makeHoursFile(){
    ofstream hoursFile("hoursFile.txt");

    hoursFile<<"1 20\n";
    hoursFile<<"2 30\n";
    hoursFile<<"1 20\n";
    hoursFile<<"3 40\n";
    hoursFile<<"4 20\n";
    hoursFile<<"5 30\n";
    hoursFile<<"4 20\n";
    hoursFile<<"6 20\n";
    hoursFile<<"6 20\n";
    hoursFile.close();
}

void openInputFile(ifstream& inFile){
    string filename;

    cout<<"kindly input the filename:\n";
    cin>>filename;
    inFile.clear();
    inFile.open(filename);
    while(!inFile){
        cout<<"Wrong file name.\n";
        cout<<"Kindly input the correct filename:\n";
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}