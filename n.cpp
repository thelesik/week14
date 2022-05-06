
#include <iostream> 
#include <vector> 
#include <istream> 
#include <string> 
#include <vector>
#include <sstream>
#include <fstream>
//#include <iterator>
#include <cstring>
//#include <map>
#include <time.h>
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
    void Out(ofstream n) {
        n << businessPercentage << endl;
        n << ownerDate << endl;
        n << category() << endl;

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
    void Out(ofstream n) {
        n << department << endl;
        n << empId << endl;
        n << salary << endl;
        n << category() << endl;

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
    void Out(ofstream n) {
        n << job << endl;
        n << empId << endl;
        n << hourlySalary << endl;
        n << hoursWorked << endl;
        n << category() << endl;

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
    int rah = 0;
    // map<int, double> gquiz1;
    vector< vector<double> > db;
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
            summ3 = summ3 + own->getBusinessPercentage();
            counto++;
            //for (int i = DifferenceinTime(own->getOwnerDate(), "old"); i <= DifferenceinTime(currentDateTime(), "new"); i++) {
            //    //vector<double> temp;
            //    //temp.push_back(i);
            //    //temp.push_back(own->getBusinessPercentage());
            //    //db.push_back(temp);
            //    //rah++;
            //}

        }
        cout << endl << endl;
    }
    cout << "Laborer average salary is " << suml / countl << endl;
    cout << "Manager average salary is " << summ / countm << endl;
    cout << "Owner average salary is " << summ3 / counto << endl << endl;

}
// need to short this list 
//vector< vector<double> > newdb;

//for (int i = 0; i < rah; i++) {
//    double temp1 = db[0][1];
//    for (int j = 0; j < rah; j++) {
//        if (db[i][0] == db[j][0]) {
//                newdb[i][0] = db[i][0];
//                newdb[i][1] = newdb[i][1] + db[i][0] + db[j][0];
//        }
//    }
//}

//for (int i = 0; i < newdb.size(); i++) {
//    for (int j = 0; j < 2; j++) {
//        cout << newdb[i][j] << " ";
//    }
//    cout << endl;




//for (int i = 0; i < rah; i++) {
//    for (int j = 0; j < 2; j++) {
//        cout << db[i][j] << " ";
//    }
//    cout << endl;
//}
//for (int i = 0; i < rah; i++) {

//    double tempc = 0;
//    double percentage = 0;
//    for (int j = 0; j < rah; j++) {
//        if (db[i][0] == db[j][0]) {
//            // cout << db[i][0];
//            tempc = db[i][1] + db[j][1];
//        }
//        
//    }cout << db[i][0] << " " << tempc << endl;
//}        
//
//cout << endl << endl;




//    if (db[i][0] == db[j][0]) {
//        percentage = db[i][1];
//    }
//    if (db[i][0] == db[j][0]) {
//       // percentage = ;
//        percentage = percentage + db[j][1];
//        tempc++;
//    }



// cout << rah << "   " << db[i][0] << "  " << percentage << endl;




 /*    for (int i = DifferenceinTime(currentDateTime(), "old"); i <= DifferenceinTime(currentDateTime(), "new"); i++) {
     }
 */

int Arrayofdata(vector<Person*>& l)
{
    vector<string> text_file;
    int numberofplanets;
    ifstream ifs("file.txt");
    string temp;
    if (ifs.is_open()) {
        while (getline(ifs, temp))
            text_file.push_back(temp);
        numberofplanets = stoi(text_file[0]);

        ifs.close();

    }

    else {
        cout << "Error \n";
    }

    return 0;
}


//for (int i = 0; i < text_file.size(); i += 3) {
//    val.SetName(text_file[i]);
//    char* c = const_cast<char*>(text_file[i + 1].c_str());
//    val.SetMass(atof(c));
//    char* b = const_cast<char*>(text_file[i + 2].c_str());
//    val.SetDiament(atof(b));
//    l.push_back(val);
//    // val.Display();
//     // cout << endl;


//}

void MainPart()
{
    vector<Person*> persons;
    int p = 0;
    cout << "1. You want to use previous data? \n 2. You want to start from beginning?";
    cin >> p;

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
                        persons.erase(persons.begin() + i);
                    }
                }
            }


        }
        else if (choice == 7) {
            //3. Calculate and display the average amount earned for each of the 3 categories of people
            Calculatesallary(persons);


        }
        else if (choice == 8) {

            ofstream outfile;
            outfile.open("file.txt", std::ofstream::out | std::ofstream::trunc);
            outfile.close();
            outfile.open("file.txt");
            if (outfile.is_open()) {

                long len = persons.size();
                for (long i = 0; i < len; i++) {
                    //  persons[i]->Out(outfile);
                 //     std::cout << std::endl;
                    outfile << persons.at(i)->getName() << endl;
                    outfile << persons.at(i)->getSsn() << endl;
                    outfile << persons.at(i)->getBirthDate() << endl;

                    if (persons.at(i)->category() == "Laborer") {
                        Laborer* lab = dynamic_cast<Laborer*>(persons.at(i));
                        outfile << lab->getJob() << endl;
                        outfile << lab->getEmpId() << endl;
                        outfile << lab->getHourlySalary() << endl;
                        outfile << lab->getHoursWorked() << endl;

                    }
                    else if (persons.at(i)->category() == "Manager") {
                        Manager* man = dynamic_cast<Manager*>(persons.at(i));
                        outfile << man->getDepartment() << endl;
                        outfile << man->getEmpId() << endl;
                        outfile << man->getSalary() << endl;

                    }
                    else if (persons.at(i)->category() == "Owner") {
                        Owner* own = dynamic_cast<Owner*>(persons.at(i));
                        outfile << own->getBusinessPercentage() << endl;
                        outfile << own->getOwnerDate() << endl;

                    }
                    outfile << endl;
                    cout << endl << endl;
                }


                //outfile << k << endl;
                //for (auto& planet : planetList)
                //{
                //    outfile << planet.getName() << endl;
                //    outfile << planet.getDiametr() << endl;
                //    outfile << planet.getMass() << endl;
                //}
                outfile.close();
            }
            else {
                cout << "Error \n";
            }
            goto Check1; // goto


            return;
            goto Check1;

        }
    }
Check1:
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
