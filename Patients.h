// Carina Salunke
// 40315116

#include <iostream>
#include <string>
using namespace std;

#ifndef FINAL_PROJECT_PATIENTS_H
#define FINAL_PROJECT_PATIENTS_H

class Patients {
private:
    string First_Name;
    string Last_Name;
    long int ID;
    long int Assigned_Doctor;
    string Date_of_Birth;
    string Blood_Type;
    string Diagnosis;
    string Date_of_Admission;
    string Discharge_Date;

public:
    // Constructors
    Patients();
    Patients(string f, string l, long int i, long int a, string dob,
        string bt, string dg, string doa, string dd);

    // Getters
    string getFirst_Name() const;
    string getLast_Name() const;
    long int getID() const;
    long int getAssigned_Doctor() const;
    string getDate_of_Birth() const;
    string getBlood_Type() const;
    string getDiagnosis() const;
    string getDate_of_Admission() const;
    string getDischarge_Date() const;

    // Member Functions
    bool IsDischarged() const;
    string Patient_Status() const;
    void Print_Patient_Info() const;
};

#endif //FINAL_PROJECT_PATIENTS_H
