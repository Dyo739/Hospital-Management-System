#include <iostream>
#include "Hospital.h"

int main(){
    Hospital h("patients.txt","doctors.txt");
    int choice = -1;
    while (choice != 0) {
        cout << "======= HOSPITAL SYSTEM =======" << endl;
        cout << "1.  Find oldest patient" << endl;
        cout << "2.  Count critical patients" << endl;
        cout << "3.  Count in-patients" << endl;
        cout << "4.  Show patient by ID" << endl;
        cout << "5.  Show doctor by ID" << endl;
        cout << "6.  List doctors by specialty" << endl;
        cout << "7.  Show assigned doctor for a patient" << endl;
        cout << "8.  Show patients assigned to a doctor" << endl;
        cout << "9.  Append new patient to file" << endl;
        cout << "10. Append new doctor to file" << endl;
        cout << "11. Test patients and doctors functions" << endl;
        cout << "0.  Exit" << endl;
        cout << "Select option: ";
        cin >> choice;

        long id;
        string input;

        switch (choice) {
            case 1:
                h.Find_Oldest_Patient();
                break;

            case 2:
                cout << "Number of critical patients: "
                     << h.Count_Critical_Patients() << endl;
                break;

            case 3:
                cout << "Number of in-patients: "
                     << h.Count_In_Patients() << endl;
                break;

            case 4:
                cout << "Enter patient ID: ";
                cin >> input;

                try {
                    // Varify each character is an integer
                    for (char c : input) {
                        if (!isdigit(c)) {
                            throw "Invalid ID format. ID must contain only digits.";
                        }
                    }
                    // if valid ID, then execute function
                    id = stol(input);
                    h.Show_Patient_by_ID(id);
                }
                catch (const char* err) {
                    cout << "Error: " << err << endl;
                }
                break;

            case 5:
                cout << "Enter doctor ID: ";
                cin >> input;

                try {
                    // Varify each character is an integer
                    for (char c : input) {
                        if (!isdigit(c)) {
                            throw "Invalid ID format. ID must contain only digits.";
                        }
                    }
                    // if valid ID, then execute function
                    id = stol(input);
                    h.Show_Doctor_by_ID(id);
                }
                catch (const char* err) {
                    cout << "Error: " << err << endl;
                }
                break;

            case 6:
                h.Doctors_By_Speciality();
                break;

            case 7:
                cout << "Enter patient ID: ";
                cin >> input;
                try {
                    // Varify each character is an integer
                    for (char c : input) {
                        if (!isdigit(c)) {
                            throw "Invalid ID format. ID must contain only digits.";
                        }
                    }
                    // if valid ID, then execute function
                    id = stol(input);
                    h.Show_Assigned_Doctor(id);
                }
                catch (const char* err) {
                    cout << "Error: " << err << endl;
                }
                break;


            case 8:
                cout << "Enter doctor ID: ";
                cin >> input;
                try {
                    // Varify each character is an integer
                    for (char c : input) {
                        if (!isdigit(c)) {
                            throw "Invalid ID format. ID must contain only digits.";
                        }
                    }
                    // if valid ID, then execute function
                    id = stol(input);
                    h.Show_Assigned_Patient(id);
                }
                catch (const char* err) {
                    cout << "Error: " << err << endl;
                }
                break;


            case 9:
                h.Append_Patient_To_File("patients.txt");
                break;

            case 10:
                h.Append_Doctor_To_File("doctors.txt");
                break;

            case 11: {
                Patients p("Bob", "Farget", 12345678, 40343255, "19950325", "A", "Critical", "20241121", "-1");
                cout << "\n--- Testing Patient Object ---\n";
                cout << "First Name: " << p.getFirst_Name() << endl;
                cout << "Last Name: " << p.getLast_Name() << endl;
                cout << "ID: " << p.getID() << endl;
                cout << "Assigned Doctor: " << p.getAssigned_Doctor() << endl;
                cout << "Date of Birth: " << p.getDate_of_Birth() << endl;
                cout << "Blood Type: " << p.getBlood_Type() << endl;
                cout << "Diagnosis: " << p.getDiagnosis() << endl;
                cout << "Admission Date: " << p.getDate_of_Admission() << endl;
                cout << "Discharge Date: " << p.getDischarge_Date() << endl;

                cout << "Is Discharged? "
                    << (p.IsDischarged() ? "Yes" : "No") << endl;

                cout << "Patient Status: " << p.Patient_Status() << endl;

                cout << "\n-- Print Patient Info --\n";
                p.Print_Patient_Info();

                Doctors d("Perry", "Dylan", 40343255, "Dermatology", 7, 100000, 0.67);
                cout << "\n--- Testing Doctor Object ---\n";
                cout << "First Name: " << d.getFirst_Name() << endl;
                cout << "Last Name: " << d.getLast_Name() << endl;
                cout << "ID: " << d.getID() << endl;
                cout << "Specialty: " << d.getSpecialty() << endl;
                cout << "Years of Experience: " << d.getYears_of_Experience() << endl;
                cout << "Base Salary: " << d.getBase_Salary() << endl;
                cout << "Bonus Percentage: " << d.getBonus() << endl;

                cout << "Salary with Bonus: " << d.Calculate_Compensation() << endl;

                cout << "\n-- Print Doctor Info --\n";
                d.Print_Doctor_info();

                cout << "\n=== END OF PART 3 TESTS ===\n";
            }

            case 0:
                cout << "Exiting" << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }

    return 0;
}