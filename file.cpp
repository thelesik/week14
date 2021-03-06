
#include <iostream> 
#include <vector> 
#include <istream> 
#include <string> 
#include <vector>
#include <sstream>
#include <iterator>
#include <cstring>
#include <map>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"



//const int MaxDataBase = 10000;
using namespace std;



class Person {
private:
    string name;
    string ssn;
    string birthDate;

public:
    string getName() {
        return name;
    }
    string getSsn() {
        return ssn;
    }
    string getBirthDate() {
        return birthDate;
    }
    void setName(string Name) {
        name = Name;
    }
    void setSsn(string Ssn) {
        ssn = Ssn;
    }
    void setBirthDate(string BirthDate) {
        birthDate = BirthDate;
    }
    void Display() {
        cout << "Name: " << name << endl;
        cout << "SSN: " << ssn << endl;
        cout << "birth date" << birthDate;
    }
    virtual string category() = 0;
};



class Owner : public Person {
private:
    double businessPercentage;
    string ownerDate;
public:
    double getBusinessPercentage() {
        return businessPercentage;
    }
    string getOwnerDate() {
        return ownerDate;
    }
    void setBusinessPercentage(double BusinessPercentage) {
        businessPercentage = BusinessPercentage;
    }
    void setOwnerDate(string OwnerDate) {
        ownerDate = OwnerDate;
    }
    void Display() {
        cout << "Business Percentage: " << businessPercentage << endl;
        cout << "Owner Date: " << ownerDate << endl;
    }
    string category() {
        return "Owner";
    }
};


class Manager : public Person {
private:
    string department;
    string empId;
    double salary;
public:
    string getDepartment() {
        return department;
    }
    string getEmpId() {
        return empId;
    }
    double getSalary() {
        return salary;
    }
    void setDepartment(string Department) {
        department = Department;
    }
    void setEmpId(string EmpId) {
        empId = EmpId;
    }
    void setSalary(double Salary) {
        salary = Salary;
    }
    void Display() {
        cout << "department: " << department << endl;
        cout << "empId: " << empId << endl;
        cout << "salary" << salary << endl;
    }
    string category() {
        return "Manager";
    }
};

class Laborer : public Person {
private:
    string job;
    string empId;
    double hourlySalary;
    double hoursWorked;
public:
    string getJob() {
        return job;
    }
    string getEmpId() {
        return empId;
    }
    double getHourlySalary() {
        return hourlySalary;
    }
    double getHoursWorked() {
        return hoursWorked;
    }
    // mutators 
    void setJob(string Job) {
        job = Job;
    }
    void setEmpId(string EmpId) {
        empId = EmpId;
    }
    void setHourlySalary(double HourlySalary) {
        hourlySalary = HourlySalary;
    }
    void setHoursWorked(double HoursWorked) {
        hoursWorked = HoursWorked;
    }
    void Display() {
        cout << "job: " << job << endl;
        cout << "empId: " << empId << endl;
        cout << "hourly Salary: " << hourlySalary << endl;
        cout << "hours Worked: " << hoursWorked << endl;

    }
    string category() {
        return "Laborer";
    }
};

void Display(vector<Person*>& v, string name, int iterator)
{
    if (name == "") {
        if (v.empty()) {
            std::cout << "List is empty\n";
        }
        else {
            cout << "Total Persons in vector: " << v.size() << endl;
            long len = v.size();
            for (long i = 0; i < len; i++) {
                v[i]->Display();
                std::cout << std::endl;
                if (v.at(i)->category() == "Laborer") {
                    Laborer* lab = dynamic_cast<Laborer*>(v.at(i));
                    lab->Display();
                }
                else if (v.at(i)->category() == "Manager") {
                    Manager* man = dynamic_cast<Manager*>(v.at(i));
                    man->Display();
                }
                else if (v.at(i)->category() == "Owner") {
                    Owner* own = dynamic_cast<Owner*>(v.at(i));
                    own->Display();
                }
                cout << endl << endl;
            }
        }
    }
    else {
        v[iterator]->Display();
        std::cout << std::endl;
        if (v.at(iterator)->category() == "Laborer") {
            Laborer* lab = dynamic_cast<Laborer*>(v.at(iterator));
            lab->Display();
        }
        else if (v.at(iterator)->category() == "Manager") {
            Manager* man = dynamic_cast<Manager*>(v.at(iterator));
            man->Display();
        }
        else if (v.at(iterator)->category() == "Owner") {
            Owner* own = dynamic_cast<Owner*>(v.at(iterator));
            own->Display();
        }
        cout << endl << endl;
    }
}
string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);

    return buf;
}


int DifferenceinTime(string origindate, string s) { //used to return year in this version 
    string Old = origindate;
    string New = currentDateTime();
    vector<int> numbersold;
    vector<int> numbersnew;
    int diff = 0;

    if (Old.size() == 10 || New.size() == 10) {

        stringstream text_stream(Old);
        string item;
        while (std::getline(text_stream, item, '-')) {
            numbersold.push_back(stoi(item));
        }
        stringstream text_stream1(New);
        string item1;
        while (std::getline(text_stream1, item1, '-')) {
            numbersnew.push_back(stoi(item1));
        }
    }
    else { cout << "wrong input";  return 0; }

    //diff = numbersnew[0] - numbersold[0];
    if (s == "new") { return numbersnew[0]; }
    else { return numbersold[0]; }
   

}

void Calculatesallary(vector<Person*>& v) {
    long len = v.size();
    int countl = 0;
    double suml = 0;
    int countm = 0;
    double summ = 0;
    double summ3 = 0;
    int counto = 0;
    double years = 0;
    map<int, double> gquiz1;
    for (long i = 0; i < len; i++) {
        //v[i]->Display();
        std::cout << std::endl;
        if (v.at(i)->category() == "Laborer") {
            Laborer* lab = dynamic_cast<Laborer*>(v.at(i));
            double sumt = lab->getHourlySalary() * lab->getHoursWorked();
            //lab->Display();
            suml = suml + sumt;
            countl++;
        }
        else if (v.at(i)->category() == "Manager") {
            Manager* man = dynamic_cast<Manager*>(v.at(i));
            summ = summ + man->getSalary();
            countm++;
        }
        else if (v.at(i)->category() == "Owner") {


            Owner* own = dynamic_cast<Owner*>(v.at(i));
            for (int i = DifferenceinTime(own->getOwnerDate(), "old"); i <= DifferenceinTime(currentDateTime(), "new"); i++) {
                gquiz1.insert(pair<int, int>(i, own->getBusinessPercentage()));
            }

            //  summ3 = summ3 + summ3;
            //  counto++;

        }
        cout << endl << endl;
    }
    map<int, double>::iterator itr;
    cout << "Laborer average salary is " << suml / countl << endl;
    cout << "Manager average salary is " << summ / countm << endl;
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        int c = 0;

        cout << '\t' << itr->first << '\t' << itr->second
            << '\n';

    }
}

/*    for (int i = DifferenceinTime(currentDateTime(), "old"); i <= DifferenceinTime(currentDateTime(), "new"); i++) {

    }
*/


void MainPart()
{
    vector<Person*> persons;

    for (; 1 == 1;) {
        int choice;
        cout << "1. Add Laborer \n 2. Add Manager \n 3. Add Owner \n 4. Display All \n 5. Find Information by name \n 6. Delete person by name \n 7. Average amount earned for category \n 8. To Exit" << endl;
        choice = ReadValue<double>("Enter choice ");
        cin.ignore();
        if (choice == 1) {
            string name, ssn, birthDate, job, empId;
            double hourlySalary, hoursWorked;
            name = ReadValueString<string>("Enter name: ");
            ssn = ReadValueString < string>("Enter social security number: ");
            birthDate = ReadValueString < string>("Enter birth date: ");
            job = ReadValueString<string>("Enter job: ");
            empId = ReadValueString < string>("Enter employee id: ");
            hourlySalary = ReadValue  < double>("Enter hourly salary: ");
            hoursWorked = ReadValue<double>("Enter hours worked : ");
            Laborer* lab = new Laborer();
            lab->setName(name);
            lab->setSsn(ssn);
            lab->setBirthDate(birthDate);
            lab->setJob(job);
            lab->setEmpId(empId);
            lab->setHourlySalary(hourlySalary);
            lab->setHoursWorked(hoursWorked);
            persons.push_back(lab);
        }


        else if (choice == 2) {
            string name, ssn, birthDate, department, empId;
            double salary;
            name = ReadValueString<string>("Enter name: ");
            ssn = ReadValueString < string>("Enter social security number: ");
            birthDate = ReadValueString < string>("Enter birth date: ");
            department = ReadValueString < string>("Enter department: ");
            empId = ReadValueString < string>("Enter employee id: ");
            salary = ReadValue<double>("Enter salary: ");
            Manager* man = new Manager();
            man->setName(name);
            man->setSsn(ssn);
            man->setBirthDate(birthDate);
            man->setDepartment(department);
            man->setEmpId(empId);
            man->setSalary(salary);
            persons.push_back(man);
        }
        else if (choice == 3) {
            string name, ssn, birthDate, ownDate;
            double businessPercentage;
            name = ReadValueString<string>("Enter name: ");
            ssn = ReadValueString <string>("Enter social security number: ");
            birthDate = ReadValueString <string>("Enter birth date: ");
            businessPercentage = ReadValue  < double>("Enter business Percentage: ");
            ownDate = ReadValueString<string>("Enter the date you became an owner in format YYYY-MM-DD:  ");
            ownDate = ReadValueString<string>("");
            cout << endl;
            Owner* owner = new Owner();
            owner->setName(name);
            owner->setSsn(ssn);
            owner->setBirthDate(birthDate);
            owner->setBusinessPercentage(businessPercentage);
            owner->setOwnerDate(ownDate);
            persons.push_back(owner);
        }
        else if (choice == 4) {
            cout << endl;
            if (persons.size() > 0) {
                Display(persons, "", 0);
            }


        }
        else if (choice == 5) {
            //1. Find a person by name then print out all information stored about that person
            string fname = "";
            cout << "Name to search: ";
            cin >> fname;
            if (fname != "") {
                for (int i = 0; i < persons.size(); i++) {
                    if (persons.at(i)->getName() == fname) {
                        Display(persons, fname, i);
                    }
                }
            }

        }
        else if (choice == 6) {
            //2. Find and remove a person by name
            string fname = "";
            cout << "Name to Delete: ";
            cin >> fname;
            if (fname != "") {
                for (int i = 0; i < persons.size(); i++) {
                    if (persons.at(i)->getName() == fname) {
                        persons.erase(persons.begin()+i);
                    }
                }
            }


        }
        else if (choice == 7) {
            //3. Calculate and display the average amount earned for each of the 3 categories of people
            Calculatesallary(persons);


        }
        else if (choice == 8) {
            goto Check1;    //    |                  // I know not a good idea to use goto but it safe
        } //                      |
        //                        |
    }//                           |
    //                            |
Check1://                <---------
    return;
}

int main() {
    MainPart();
    return 0;
}

/*For the final project you will revisit the "Business" assignment from Week 7.

All requirements from that assignment apply to the final project with the exception that you are not required to use a vector. 
You may use a vector or any other container that we've discussed in class.

In addition to the menu option to add a person to the container and display all person information in the list,
you must also provide menu options to do the following:

1. Find a person by name then print out all information stored about that person
2. Find and remove a person by name
3. Calculate and display the average amount earned for each of the 3 categories of people

Finally - when the user chooses the option to quit - all information from the container will be written to a file.
When the program starts, that file will be read and the data preloaded into the container.*/
