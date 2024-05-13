#include <iostream>
#include <vector> // Add this line for vector usage
#include "Company.h"
using namespace std;

Date::Date(int d, int m, int y)
{
    this->day = d;

    this->month = m;
    this->year = y;
}

string Date::getDate()
{
    return to_string(day) + "." + to_string(month) + ". " + to_string(year);
}

Position::Position(string n, string d)
{
    this->name = n;
    this->description = d;
}

Person::Person(int bd, int bm, int by, string fullName)
{
    this->birthDate = new Date(bd, bm, by);
    this->fullName = fullName;
}

Person::Person(Date *bd, string fullName)
{
    this->birthDate = bd;
    this->fullName = fullName;
}

string Person::getName()
{
    return this->fullName;
}

vector<Person*> Person::getWorkers(){
    vector<Person*> V;
    return V;
}
string Person::printInfo()
{
    return "Ja jsem clovek";
}

Worker::Worker(int bd, int bm, int by, string fullName, Position *p, int s, int hd, int hm, int hy) : Person(bd, bm, by, fullName)
{
    this->position = p;
    this->salary = s;
    this->hireDate = new Date(hd, hm, hy);
}

Worker::Worker(Date *bd, string fullName, Position *p, int s, Date *hd) : Person(bd, fullName)
{
    this->position = p;
    this->salary = s;
    this->hireDate = hd;
}

string Worker::printInfo()
{
    return "Ja tady makam";
}



Boss::Boss(int bd, int bm, int by, string fullName, Position *p, int s, int hd, int hm, int hy, vector<Person *> &workers) : Worker(bd, bm, by, fullName, p, s, hd, hm, hy)
{
    this->workers = workers;
}

Boss::Boss(Date bd, string fullName, Position *p, int s, Date hd, vector<Person *> &workers) : Worker(&bd, fullName, p, s, &hd)
{
    this->workers = workers;
}

vector<Person *> Boss::getWorkers()
{
    return this->workers;
}

string Boss::printInfo()
{
    return "Ja to tady vedu";
}

Boss::~Boss()
{
    for (Person* worker : this->workers)
    {
        delete worker;
    }
}



Department::Department(string d, Person* b)
{
    this->description = d;
    this->boss = b;
}

Department::~Department()
{
    delete this->boss;
}

string Department::getDescription()
{
    return this->description;
}

vector<Person *> Department::getWorkers()
{
    vector<Person*> V;
    V.push_back(this->boss);
    for(Person* user: this->boss->getWorkers()){
        V.push_back(user);
    }

    return V;
}

int Company::companyCount = 0;

Company::Company(string n, string d, vector<Department *> &dep)
{
    this->name = n;
    this->description = d;
    this->Departments = dep;
    this->companyCount++;
}

void Company::print()
{
    cout << GREEN << "Company name: " << RESET << this->name << YELLOW << " >> " << RESET << this->description << endl;
    for (Department* department : this->Departments)
    {
        cout << GREEN << "\tDepartment name: " << RESET << department->getDescription() << endl;


        for (Person* worker : department->getWorkers())
        {
            string role = worker->printInfo()=="Ja to tady vedu"?"Vedouci":"Pracovnik";
            cout << "\t\t" << worker->getName() << "("<< RED << role << RESET << ") \t>> "<< YELLOW << worker->printInfo() << RESET << endl;
        }
    }
    cout << endl;
}

Company::~Company()
{
    for (Department* department : this->Departments)
    {
        delete department;
    }
}
