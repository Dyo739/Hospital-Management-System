#ifndef FINAL_PROJECT_HOSPITAL_H
#define FINAL_PROJECT_HOSPITAL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Doctors.h"
#include "Patients.h"
using namespace std;


class Hospital {
private:
    vector<Patients>* patients;
    vector<Doctors>* doctors;

public:
    // Constructor
    Hospital(string patientFile, string doctorFile);

    // Destructor
    ~Hospital();

    // Member Functions
    void Find_Oldest_Patient();
    int Count_Critical_Patients();
    int Count_In_Patients();
    void Doctors_By_Speciality()   ;
    void Show_Patient_by_ID(long id);
    void Show_Doctor_by_ID(long id);
    void Show_Assigned_Doctor(long id)  const ;
    void Show_Assigned_Patient(long id)  const ;
    void Append_Patient_To_File(string file);
    void Append_Doctor_To_File(string file);
};


#endif //FINAL_PROJECT_HOSPITAL_H