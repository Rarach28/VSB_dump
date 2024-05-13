#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <iostream>


using namespace std;


const string RED("\033[0;31m");
const string YELLOW("\033[0;33m");
const string GREEN("\033[0;32m");
const string RESET("\033[0m");


class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y);
    string getDate();
};

class Position
{
private:
    string name;
    string description;

public:
    Position(string n, string d);
};

class Person
{
protected:
    Date* birthDate;
    string fullName;

public:
    Person(int bd, int bm, int by, string fullName);
    Person(Date* bd, string fullName);
    string getName();
    virtual vector<Person*> getWorkers();
    virtual string printInfo();
};

class Worker : public Person
{
protected:
    Position* position;
    int salary;
    Date* hireDate;

public:
    Worker(int bd, int bm, int by, string fullName, Position* p, int s, int hd, int hm, int hy);
    Worker(Date* bd, string fullName, Position* p, int s, Date* hd);
    virtual string printInfo();
};

class Boss : public Worker
{
private:
    vector<Person*> workers;

public:
    Boss(int bd, int bm, int by, string fullName, Position* p, int s, int hd, int hm, int hy, vector<Person*>& workers);
    Boss(Date bd, string fullName, Position* p, int s, Date hd, vector<Person*>& workers);
    ~Boss();
    vector<Person*> getWorkers();
    string printInfo();
};

class Department
{
private:
    string description;
    Person* boss;

public:
    Department(string d, Person* w);
    ~Department();
    string getDescription();
    vector<Person*> getWorkers();
};

class CompanyPrinter
{
    public:
        virtual void print() = 0;
};

class Company: public CompanyPrinter
{
private:
    string name;
    string description;
    vector<Department*> Departments;

public:
    + static int companyCount;
    + Company(string n, string d, vector<Department*>& dep);
    + ~Company();
    + void print() override;
};

#endif
