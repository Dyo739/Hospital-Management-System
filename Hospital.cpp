//
// Created by csalu on 2025-11-19.
//

#include "Hospital.h"

//Constructor
Hospital::Hospital(string patientFile, string doctorFile) {
	patients = new vector<Patients>;
	doctors  = new vector<Doctors>;

	ifstream pFile(patientFile.c_str());
	ifstream dFile(doctorFile.c_str());

	int count;

	if (pFile) {
		pFile >> count;

		string fn, ln, birth, blood;
		long id, ass_doc;
		string diagnosis, admit, disch;
		char ch;

		for (int i = 0; i < count; i++) {
			pFile >> fn >> ln >> id >> ass_doc >> birth >> blood;

			diagnosis = "";
			pFile >> ws;
			pFile.get(ch);

			if (ch == '"') {
				while (pFile.get(ch) && ch != '"') {
					diagnosis += ch;
				}
			}

			pFile >> admit >> disch;

			Patients temp(fn, ln, id, ass_doc, birth, blood, diagnosis, admit, disch);
			patients->push_back(temp);
		}
	}

	if (dFile) {
		dFile >> count;

		string fn, ln, temp_spec;
		unsigned long id;
		int y_exp;
		double b_sal, bonus;

		for (int i = 0; i < count; i++) {
			dFile >> fn >> ln >> id >> temp_spec >> y_exp >> b_sal >> bonus;

			if (!temp_spec.empty() && temp_spec[0] == '"') {
				int q = temp_spec.find('"', 1);
				string spec = temp_spec.substr(1, q - 1);

				Doctors temp(fn, ln, id, spec, y_exp, b_sal, bonus);
				doctors->push_back(temp);
			}
		}
	}

	pFile.close();
	dFile.close();
}

//Destructor
Hospital::~Hospital() {
	delete patients;
	delete doctors;
}


void Hospital :: Find_Oldest_Patient() {
	if (patients->empty()) {
		cout << "No patients in the system." << endl;
		return;
	}

	string oldestperson = patients->at(0).getDate_of_Birth();
	int oldest_index = 0;

	for (int i = 1; i < patients->size(); i++) {
		string dob = patients->at(i).getDate_of_Birth();

		if (dob < oldestperson) {
			oldestperson = dob;
			oldest_index = i;
		}
	}

	patients->at(oldest_index).Print_Patient_Info();
}
int Hospital :: Count_Critical_Patients() {
	int count = 0;

	for (int i = 0; i < patients->size(); i++) {
		if (patients->at(i).Patient_Status() == "Critical"){
			count++;
		}
	}return count;
}

int Hospital :: Count_In_Patients(){
	int count = 0;

	for (int i = 0; i < patients->size(); i++) {
		if (patients->at(i).IsDischarged() == false){
			count++;
		}
	}return count;
}

void Hospital::Doctors_By_Speciality() {
	cout << "What is the doctor's speciality? " << endl;
	string s;
	cin >> s;
	int count = 0;
	for (int i = 0; i < doctors->size(); i++) {
		if ((*doctors)[i].getSpecialty() == s) {
			cout << (*doctors)[i].getFirst_Name() << " " << (*doctors)[i].getLast_Name() << endl;
			count ++;
		}
	}if (count == 0) {
		cout << "No doctors in the system have that speciality. "<< endl;
	}
}

void Hospital :: Show_Patient_by_ID(long int id){
	bool found = false;

	for (int i = 0; i < patients->size(); i++) {
		if (id == patients->at(i).getID()) {
			patients->at(i).Print_Patient_Info();
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "No patient has the provided ID." << endl;
	}
}

void Hospital :: Show_Doctor_by_ID(long int id){
	bool found = false;

	for (int i = 0; i < doctors->size(); i++) {
		if (id == doctors->at(i).getID()) {
			doctors->at(i).Print_Doctor_info();
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "No doctor has the provided ID." << endl;
	}
}

void Hospital::Show_Assigned_Doctor(long id) const {
	for (int i = 0; i < patients->size(); i++) {
		if ((*patients)[i].getID() == id) {
			long docID = (*patients)[i].getAssigned_Doctor();

			for (int j = 0; j < doctors->size(); j++) {

				if ((*doctors)[j].getID() == docID) {
					(*doctors)[j].Print_Doctor_info();
					return;
				}
			}
		}
	}
	cout << "No doctors assigned" << endl;
	return;
}

void Hospital::Show_Assigned_Patient(long id) const {
	int count = 0;
	for (int i = 0; i < doctors->size(); i++) {
		if (id == (*doctors)[i].getID()) {
			for (int j = 0; j < patients->size(); j++) {
				if (id == (*patients)[j].getAssigned_Doctor()) {
					(*patients)[j].Print_Patient_Info();
					count++;
				}
			}
		}
	}
	if (count == 0) {
		cout << "No patients assigned" << endl;
	}return;
}

void Hospital::Append_Patient_To_File(string file) {
	// Editing the number of patients
	ifstream countFile(file.c_str());
	int count;
	countFile >> count;
	countFile.close();

	count++;
	fstream fixFile(file.c_str(), ios::in | ios::out);
	fixFile << count;
	fixFile.close();

	// Appending the patient information to the file
	ofstream outFile(file.c_str(), ios::app);
	if (outFile) {
		string fn;
		string ln;
		long int id;
		long int ass_doc;
		string birth;
		string blood;
		string diag;
		string admit;
		string disch;
		// Exception handling variables
		string string_id;
		string string_ass_doc;
		// do-while
		int count = 0;

		cout << "Enter the patient's first name: ";
		cin >> fn;

		cout << "Enter the patient's last name: ";
		cin >> ln;


		do {
			cout << "Enter patient ID: ";
			cin >> string_id;
			try {
				// Varify each character is an integer
				for (char c : string_id) {
					if (!isdigit(c)) {
						throw "Invalid ID format. ID must contain only digits.";
					}
				}
				// if valid, then execute function
				id = stol(string_id);
				count ++;
			}
			catch (const char* err) {
				cout << "Error: " << err << endl;
			}
		}while(count == 0);

		// restart the count
		count = 0;
		do {
			cout << "Enter assigned doctor ID: ";
			cin >> string_ass_doc;

			try {
				// Varify each character is an integer
				for (char c : string_ass_doc) {
					if (!isdigit(c)) {
						throw "Invalid ID format. ID must contain only digits.";
					}
				}
				// if valid, then execute function
				ass_doc = stol(string_ass_doc);
				count ++;
			}
			catch (const char* err) {
				cout << "Error: " << err << endl;
			}
		}while(count == 0);

		cout << "Enter the patient's date of birth (YYYYMMDD): ";
		cin >> birth;

		cout << "Enter the patient's blood type: ";
		cin >> blood;

		cout << "Enter the patient's diagnosis: ";
		cin.ignore();
		getline(cin,diag);

		cout << "Enter the patient's admission date (YYYYMMDD): ";
		cin >> admit;

		cout << "Enter the patient's discharge date (YYYYMMDD or -1)";
		cin >> disch;

		outFile  << "\n" << fn << " " << ln << " " << id << " " << ass_doc << " " << birth << " " << blood << " \"" << diag << "\" " << admit << " " << disch << endl;

		outFile.close();

		Patients p(fn, ln, id, ass_doc, birth, blood, diag, admit, disch);
		patients->push_back(p);
	}
}

void Hospital::Append_Doctor_To_File(string file) {
	// Editing the number of doctors
	ifstream countFile(file.c_str());
	int count;
	countFile >> count;
	countFile.close();

	count++;
	fstream fixFile(file.c_str(), ios::in | ios::out);
	fixFile << count;
	fixFile.close();

	// Appending the doctor's information to the file.
	ofstream outFile(file.c_str(), ios::app);
	if (outFile) {
		string fn;
		string ln;
		long id;
		string spec;
		int years;
		double salary;
		double bonus;
		// Exception handling variables
		string string_id;
		string string_years;
		string string_salary;
		string string_bonus;
		int count = 0;

		cout << "Enter the doctor's first name: ";
		cin >> fn;

		cout << "Enter the doctor's last name: ";
		cin >> ln;


		do {
			cout << "Enter doctor ID: ";
			cin >> string_id;
			try {
				// Varify each character is an integer
				for (char c : string_id) {
					if (!isdigit(c)) {
						throw "Invalid ID format. ID must contain only digits.";
					}
				}
				// if valid ID, then execute function
				id = stol(string_id);
				count ++;
			}
			catch (const char* err) {
				cout << "Error: " << err << endl;
			}
		}while(count == 0);


		cout << "Enter the doctor's specialty: ";
		cin >> spec;

		count = 0;
		do {
			cout << "Enter the doctor's years of experience: ";
			cin >> string_years;
			try {
				// Varify each character is an integer
				for (char c : string_years) {
					if (!isdigit(c)) {
						throw "Invalid format. The number of years must only contain digits.";
					}
				}
				// if valid, then execute function
				years = stol(string_years);
				count ++;
			}
			catch (const char* err) {
				cout << "Error: " << err << endl;
			}
		}while(count == 0);

		count = 0;
		do {
			cout << "Enter the doctor's base salary: ";
			cin >> string_salary;
			try {
				// Varify each character is an integer
				for (char c : string_salary) {
					if (!isdigit(c)) {
						throw "Invalid format. The salary must only contain digits.";
					}
				}
				// if valid salary, then execute function
				salary = stol(string_salary);
				count ++;
			}
			catch (const char* err) {
				cout << "Error: " << err << endl;
			}
		}while(count == 0);

		count = 0;

		do {
			cout << "Enter the doctor's bonus percentage (0 to 1): ";
			cin >> string_bonus;

			try {
				bool valid = true;
				int dotCount = 0;

				for (char c : string_bonus) {
					if (c == '.') {
						dotCount++;
						if (dotCount > 1) valid = false;
					}
					else if (!isdigit(c)) {
						valid = false;
					}
				}

				if (!valid) {
					throw "Invalid format. Bonus must contain only digits or a single decimal point.";
				}
				bonus = stof(string_bonus);
				if (bonus < 0.0 || bonus > 1.0) {
					throw "Invalid value. Bonus must be between 0 and 1.";
				}
				count++;
			}
			catch (const char* err) {
				cout << "Error: " << err << endl;
			}
		} while (count == 0);

		outFile << "\n" << fn << " " << ln << " " << id << " " << spec << " "
			<< years << " " << salary << " " << bonus << endl;

		outFile.close();

		Doctors d(fn, ln, id, spec, years, salary, bonus);
		doctors->push_back(d);
	}
}