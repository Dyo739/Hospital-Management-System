#include "Patients.h"
#include <iostream>
using namespace std;

// DEFAULT CONSTRUCTOR
Patients::Patients()
{
    First_Name = "";
    Last_Name = "";
    ID = 0;
    Assigned_Doctor = 0;
    Date_of_Birth = "";
    Blood_Type = "";
    Diagnosis = "";
    Date_of_Admission = "";
    Discharge_Date = "";
}

// FULL CONSTRUCTOR
Patients::Patients(string f, string l, long int i, long int a, string dob,
    string bt, string dg, string doa, string dd)
{
    First_Name = f;
    Last_Name = l;
    ID = i;
    Assigned_Doctor = a;
    Date_of_Birth = dob;
    Blood_Type = bt;
    Diagnosis = dg;
    Date_of_Admission = doa;
    Discharge_Date = dd;
}

// GETTERS
string Patients::getFirst_Name() const {
    return First_Name;
}
string Patients::getLast_Name() const {
    return Last_Name;
}
long int Patients::getID() const {
    return ID;
}
long int Patients::getAssigned_Doctor() const {
    return Assigned_Doctor;
}
string Patients::getDate_of_Birth() const {
    return Date_of_Birth;
}
string Patients::getBlood_Type() const {
    return Blood_Type;
}
string Patients::getDiagnosis() const {
    return Diagnosis;
}
string Patients::getDate_of_Admission() const {
    return Date_of_Admission;
}
string Patients::getDischarge_Date() const {
    return Discharge_Date;
}


bool Patients::IsDischarged() const{
    return (Discharge_Date != "-1");
}

string Patients::Patient_Status() const {
    string lowerDiagnosis = Diagnosis;

    // convert to lowercase
    for (int i = 0; i < lowerDiagnosis.size(); i++) {
        if (lowerDiagnosis[i] >= 'A' && lowerDiagnosis[i] <= 'Z') {
            lowerDiagnosis[i] = lowerDiagnosis[i] + 32;
        }
    }

    if (lowerDiagnosis.find("critical") != string::npos)
        return "Critical";

    if (lowerDiagnosis.find("moderate") != string::npos)
        return "Moderate";

    if (lowerDiagnosis.find("stable") != string::npos)
        return "Stable";

    return "Unknown";
}


void Patients::Print_Patient_Info() const
{
    cout << "First Name: " << First_Name << endl;
    cout << "Last Name: " << Last_Name << endl;
    cout << "ID: " << ID << endl;
    cout << "Assigned Doctor: " << Assigned_Doctor << endl;
    cout << "Date of Birth: " << Date_of_Birth << endl;
    cout << "Blood Type: " << Blood_Type << endl;
    cout << "Diagnosis: " << Diagnosis << endl;
    cout << "Date of Admission: " << Date_of_Admission << endl;
    cout << "Discharge Date: " << Discharge_Date << endl;
}
