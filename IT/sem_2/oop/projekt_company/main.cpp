#include <iostream>
#include <vector> // Include the vector header
#include "Company.h"


using namespace std;



int main()
{
    // Positions
    Position* managerPosition = new Position("Manager", "Manages a team or department");
    Position* developerPosition = new Position("Developer", "Codes software applications");

    // Workers
    Worker* worker1 = new Worker(1990, 5, 15, "Jirka M.", managerPosition, 55000, 2020, 3, 10);
    Worker* worker2 = new Worker(1995, 8, 20, "Karel D.", developerPosition, 4000, 2021, 6, 25);
    Worker* worker3 = new Worker(1998, 9, 12, "Mirek D.", developerPosition, 6000, 2021, 6, 25);
    Worker* worker4 = new Worker(2005, 5, 5, "Johny D.", developerPosition, 1000, 2021, 6, 25);

    Worker* worker5 = new Worker(1990, 5, 15, "Lucie M.", managerPosition, 55000, 2020, 3, 10);
    Worker* worker6 = new Worker(1995, 8, 20, "Jarmila D.", developerPosition, 4000, 2021, 6, 25);
    Worker* worker7 = new Worker(1998, 9, 12, "Jitka D.", developerPosition, 6000, 2021, 6, 25);
    Worker* worker8 = new Worker(2005, 5, 5, "Katka D.", developerPosition, 1000, 2021, 6, 25);


    // Department 1
    vector<Person*> workers1;
    workers1.push_back(worker1);
    workers1.push_back(worker2);
    workers1.push_back(worker3);
    workers1.push_back(worker4);
    Boss* boss_dep1 = new Boss(1975, 3, 8, "Robert VEDE", managerPosition, 10000, 2020, 1, 1, workers1);
    Department* department1 = new Department("Engineering", boss_dep1);

    // Department 2
    vector<Person*> workers2;
    workers2.push_back(worker5);
    workers2.push_back(worker6);
    workers2.push_back(worker7);
    workers2.push_back(worker8);
    Boss* boss_dep2 = new Boss(1975, 3, 8, "Zuzana", managerPosition, 10000, 2020, 1, 1, workers2);
    Department* department2 = new Department("Marketing", boss_dep2);



    // Companies
    vector<Department*> departments1;
    departments1.push_back(department1);
    departments1.push_back(department2);
    Company* company1 = new Company("Firma Vyplnena", "Software Development", departments1);

    vector<Department*> departments2;
    Company* company2 = new Company("Firma Prazdna", "Consulting", departments2);

    // Display company information
    company1->print();
    company2->print();

    // Clean up memory
    delete company1;
    delete company2;

    return 0;
}
