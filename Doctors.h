// Carina Salunke
// 40315116

#include <iostream>
#include <string>
using namespace std;

#ifndef FINAL_PROJECT_DOCTOR_H
#define FINAL_PROJECT_DOCTOR_H


class Doctors {
private:
    string First_Name;
    string Last_Name;
    long unsigned int ID;
    string Specialty;
    int Years_of_Experience;
    double Base_Salary;
    double Bonus;

public:
    Doctors();
    Doctors(string f, string l, long int i, string sp, int y, double bs, double b);

    // Getter Functions
    string getFirst_Name() const;
    string getLast_Name() const;
    int getID() const;
    string getSpecialty() const;
    int getYears_of_Experience() const;
    double getBase_Salary() const;
    double getBonus() const;

    // Member Functions
    double Calculate_Compensation();
    void Print_Doctor_info() const;
};


#endif //FINAL_PROJECT_DOCTOR_H