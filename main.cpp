#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Base class: Person
class Person {
protected:
    int id;
    string name;
    int age;
    string gender;

public:
    void getData() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }

    void showData() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }

    int getID() { return id; }
    string getName() { return name; }
    int getAge() { return age; }
    string getGender() { return gender; }
};

// Derived class: Doctor
class Doctor : public Person {
    string specialization;

public:
    void getDoctorData() {
        getData();
        cout << "Enter Specialization: ";
        cin.ignore();
        getline(cin, specialization);
    }

    void showDoctorData() {
        showData();
        cout << "Specialization: " << specialization << endl;
    }

    string getSpecialization() { return specialization; }
};

// Derived class: Patient
class Patient : public Person {
    string disease;

public:
    void getPatientData() {
        getData();
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, disease);
    }

    void showPatientData() {
        showData();
        cout << "Disease: " << disease << endl;
    }

    string getDisease() { return disease; }
};

// Appointment class
class Appointment {
    int doctorID, patientID;
    string date;

public:
    void bookAppointment() {
        cout << "Enter Doctor ID: ";
        cin >> doctorID;
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Appointment Date (DD-MM-YYYY): ";
        cin >> date;
    }

    void showAppointment() {
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Date: " << date << endl;
    }

    int getDoctorID() { return doctorID; }
    int getPatientID() { return patientID; }
    string getDate() { return date; }
};

// Hospital class
class Hospital {
public:
    void addDoctor() {
        Doctor d;
        d.getDoctorData();

        ofstream file("doctor.txt", ios::app);
        file << d.getID() << " " << d.getName() << " " << d.getAge() << " " 
             << d.getGender() << " " << d.getSpecialization() << "\n";
        file.close();

        cout << "\nDoctor record added successfully!\n";
    }

    void showDoctors() {
        ifstream file("doctor.txt");
        if (!file) {
            cout << "No doctor records found.\n";
            return;
        }

        int id, age;
        string name, gender, specialization;
        bool found = false;

        while (file >> id >> name >> age >> gender >> specialization) {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Gender: " << gender << endl;
            cout << "Specialization: " << specialization << endl;
            cout << "------------------------\n";
            found = true;
        }

        if (!found)
            cout << "No doctor records found.\n";

        file.close();
    }

    void addPatient() {
        Patient p;
        p.getPatientData();

        ofstream file("patient.txt", ios::app);
        file << p.getID() << " " << p.getName() << " " << p.getAge() << " " 
             << p.getGender() << " " << p.getDisease() << "\n";
        file.close();

        cout << "\nPatient record added successfully!\n";
    }

    void showPatients() {
        ifstream file("patient.txt");
        if (!file) {
            cout << "No patient records found.\n";
            return;
        }

        int id, age;
        string name, gender, disease;
        bool found = false;

        while (file >> id >> name >> age >> gender >> disease) {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Gender: " << gender << endl;
            cout << "Disease: " << disease << endl;
            cout << "------------------------\n";
            found = true;
        }

        if (!found)
            cout << "No patient records found.\n";

        file.close();
    }

    void bookAppointment() {
        Appointment a;
        a.bookAppointment();

        ofstream file("appointment.txt", ios::app);
        file << a.getDoctorID() << " " << a.getPatientID() << " " << a.getDate() << "\n";
        file.close();

        cout << "\nAppointment booked successfully!\n";
    }

    void showAppointments() {
        ifstream file("appointment.txt");
        if (!file) {
            cout << "No appointments found.\n";
            return;
        }

        int docID, patID;
        string date;
        bool found = false;

        while (file >> docID >> patID >> date) {
            cout << "Doctor ID: " << docID << endl;
            cout << "Patient ID: " << patID << endl;
            cout << "Date: " << date << endl;
            cout << "------------------------\n";
            found = true;
        }

        if (!found)
            cout << "No appointments found.\n";

        file.close();
    }
};

// Main function
int main() {
    Hospital h;
    int choice;

    do {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Doctor\n";
        cout << "2. Show Doctors\n";
        cout << "3. Add Patient\n";
        cout << "4. Show Patients\n";
        cout << "5. Book Appointment\n";
        cout << "6. Show Appointments\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: h.addDoctor(); break;
            case 2: h.showDoctors(); break;
            case 3: h.addPatient(); break;
            case 4: h.showPatients(); break;
            case 5: h.bookAppointment(); break;
            case 6: h.showAppointments(); break;
            case 7: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}


