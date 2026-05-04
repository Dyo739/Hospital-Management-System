#include "Doctors.h"
// Constructor
Doctors:: Doctors(){
    First_Name = "";
    Last_Name = "";
    ID = 0;
    Specialty = "";
    Years_of_Experience = 0;
    Base_Salary = 0;
    Bonus = 0;
}

// Setter Functions
Doctors:: Doctors(string f, string l, long int i, string sp, int y, double bs, double b){
    First_Name = f;
    Last_Name = l;
    ID = i;
    Specialty = sp;
    Years_of_Experience = y;
    Base_Salary = bs;
    Bonus = b;
}

// Getter Functions
string Doctors::getFirst_Name() const {
    return First_Name;
}
string Doctors::getLast_Name() const {
    return Last_Name;
}
int Doctors::getID() const {
    return ID;
}
string Doctors::getSpecialty() const {
    return Specialty;
}
int Doctors::getYears_of_Experience() const {
    return Years_of_Experience;
}
double Doctors::getBase_Salary() const {
    return Base_Salary;
}
double Doctors::getBonus() const {
    return Bonus;
}

// Member Functions
double Doctors::Calculate_Compensation() {
    double new_salary = Base_Salary * (1 + Bonus);
    return new_salary;
}

void Doctors::Print_Doctor_info() const {
    cout << "First Name: " << First_Name << endl;
    cout << "Last Name: " << Last_Name << endl;
    cout << "ID: " << ID << endl;
    cout << "Specialty: " << Specialty << endl;
    cout << "Years of Experience: " << Years_of_Experience << endl;
    cout << "Base_Salary: " << Base_Salary << endl;
    cout << "Bonus: " << Bonus << endl;
}