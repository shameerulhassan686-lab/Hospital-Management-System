//Hospital-Management-System-
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;

string intToStr(int n) {
    ostringstream oss;
    oss << n;
    return oss.str();
}


class Person {
protected:
    char name[50];
    int  age;
    char gender[20];

public:
    Person() {
        name[0] = '\0';
        gender[0] = '\0';
        age = 0;
    }

    // Virtual so derived classes can extend it
    virtual void showInfo() {
        cout << "\tNAME   : " << name   << endl;
        cout << "\tAGE    : " << age    << endl;
        cout << "\tGENDER : " << gender << endl;
    }

    const char* getName()   const { return name;   }
    int         getAge()    const { return age;     }
    const char* getGender() const { return gender;  }

    void setName  (const char* n) { strncpy(name,   n, 49);  name[49]   = '\0'; }
    void setAge   (int a)         { age = a; }
    void setGender(const char* g) { strncpy(gender, g, 19);  gender[19] = '\0'; }

    virtual ~Person() {}
};


class HospitalService {
public:
    
	    virtual void showMenu() = 0;

    virtual void displayServiceName() {
        cout << "\n\t[HOSPITAL SERVICE]\n";
    }

    virtual ~HospitalService() {}
};


class Patient : public Person {
public:
    int reg;
    int pin;

    Patient() : Person() {
        reg = pin = 0;
    }

    void registerPatient(int id) {
        cout << "\n\tENTER PATIENT'S NAME: ";
        cin  >> name;
        cout << "\tENTER YOUR AGE: ";
        cin  >> age;
        cout << "\tENTER YOUR GENDER: ";
        cin  >> gender;
        cout << "\tCREATE YOUR 4 DIGIT PIN: ";
        cin  >> pin;
        reg = id;
        cout << "\tREGISTRATION NUMBER: " << reg << endl;

        ofstream file("patients.txt", ios::app);
        if(file.is_open()) {
            file << "-------------------------------\n";
            file << "Reg No : " << reg    << "\n";
            file << "Name   : " << name   << "\n";
            file << "Age    : " << age    << "\n";
            file << "Gender : " << gender << "\n";
            file << "-------------------------------\n";
            file.close();
            cout << "\tRecord saved to patients.txt\n";
        }
    }

    // Override Person::showInfo() to also display reg number
    void showInfo() override {
        Person::showInfo();              // reuse base class output
        cout << "\tREGISTRATION # : " << reg << endl;
    }
};


class Lab : public HospitalService {
public:
    void displayServiceName() override {
        cout << "\n\t[SERVICE: LABORATORY]\n";
    }

    void showMenu() override {
        labTests();
    }

    void labTests() {
        int a;
        displayServiceName();
        cout << "\n\tENTER YOUR CHOICE FOR THE LAB TESTS\n";
        cout << "\t1.CT SCAN\n";
        cout << "\t2.X-RAY\n";
        cout << "\t3.BLOOD TEST\n";
        cout << "\t4.MRI\n";
        cout << "\t5.COVID TEST\n";
        cout << "\t6.EXIT\n";
        cout << "\tYour Choice: ";
        cin  >> a;
        switch(a) {
            case 1: cout << "\n\tCT SCAN\n\tRS 1000\n\tYOUR TEST RESULT WILL BE SENT IN AN HOUR\n"; break;
            case 2: cout << "\n\tX-RAY\n\tRS 800\n\tYOUR TEST RESULT WILL BE SENT IN AN HOUR\n";   break;
            case 3: cout << "\n\tBLOOD TEST\n\tRS 1000\n\tYOUR TEST RESULT WILL BE SENT IN AN HOUR\n"; break;
            case 4: cout << "\n\tMRI\n\tRS 1100\n\tYOUR TEST RESULT WILL BE SENT IN AN HOUR\n";    break;
            case 5: cout << "\n\tCOVID TEST\n\tRS 1000\n\tYOUR TEST RESULT WILL BE SENT IN AN HOUR\n"; break;
            case 6: break;
            default: cout << "\n\t***PLEASE ENTER A VALID CHOICE***\n";
        }
    }
};


class Pharmacy : public HospitalService {
public:
    void displayServiceName() override {
        cout << "\n\t[SERVICE: PHARMACY]\n";
    }

    void showMenu() override {
        medicines();
    }

    void medicines() {
        int b, c;
        displayServiceName();
        cout << "\n\tENTER YOUR CHOICE FOR THE MEDICINES\n";
        cout << "\t1.HEART MEDICINES\n";
        cout << "\t2.LUNG MEDICINES\n";
        cout << "\t3.KIDNEY MEDICINE\n";
        cout << "\t4.LIVER MEDICINE\n";
        cout << "\t5.COLD AND FEVER MEDICINES\n";
        cout << "\t6.EXIT\n";
        cout << "\tYour Choice: ";
        cin  >> b;
        switch(b) {
            case 1:
                cout << "\n\t1.STATIN\n\t2.ASPIRIN\n\t3.CLOPIDOGREL\n\t4.WARFARIN\n";
                cout << "\tYour Choice: "; cin >> c;
                if     (c==1) cout << "\n\t\tSTATIN\n\t\tRS 690\n";
                else if(c==2) cout << "\n\t\tASPIRIN\n\t\tRS 450\n";
                else if(c==3) cout << "\n\t\tCLOPIDOGREL\n\t\tRS 980\n";
                else if(c==4) cout << "\n\t\tWARFARIN\n\t\tRS 730\n";
                else          cout << "\n\t\t***INVALID CHOICE***\n";
                break;
            case 2:
                cout << "\n\t1.ALBUTEROL\n\t2.IPRATROPIUM\n\t3.LEVALBUTEROL\n";
                cout << "\tYour Choice: "; cin >> c;
                if     (c==1) cout << "\n\t\tALBUTEROL\n\t\tRS 190\n";
                else if(c==2) cout << "\n\t\tIPRATROPIUM\n\t\tRS 150\n";
                else if(c==3) cout << "\n\t\tLEVALBUTEROL\n\t\tRS 280\n";
                else          cout << "\n\t\t***INVALID CHOICE***\n";
                break;
            case 3:
                cout << "\n\t1.CAPTOPRIL\n\t2.ENALAPRIL\n\t3.FOSINOPRIL\n\t4.LISINOPRIL\n\t5.RAMIPRIL\n";
                cout << "\tYour Choice: "; cin >> c;
                if     (c==1) cout << "\n\t\tCAPTOPRIL\n\t\tRS 890\n";
                else if(c==2) cout << "\n\t\tENALAPRIL\n\t\tRS 650\n";
                else if(c==3) cout << "\n\t\tFOSINOPRIL\n\t\tRS 880\n";
                else if(c==4) cout << "\n\t\tLISINOPRIL\n\t\tRS 730\n";
                else if(c==5) cout << "\n\t\tRAMIPRIL\n\t\tRS 560\n";
                else          cout << "\n\t\t***INVALID CHOICE***\n";
                break;
            case 4:
                cout << "\n\t1.NEOMYCIN\n\t2.FLOXURIDINE\n\t3.ACTIGALL\n\t4.AVANDIA\n";
                cout << "\tYour Choice: "; cin >> c;
                if     (c==1) cout << "\n\t\tNEOMYCIN\n\t\tRS 990\n";
                else if(c==2) cout << "\n\t\tFLOXURIDINE\n\t\tRS 850\n";
                else if(c==3) cout << "\n\t\tACTIGALL\n\t\tRS 980\n";
                else if(c==4) cout << "\n\t\tAVANDIA\n\t\tRS 730\n";
                else          cout << "\n\t\t***INVALID CHOICE***\n";
                break;
            case 5:
                cout << "\n\t1.PANADOL\n\t2.ARINAC\n\t3.DISPIRIN\n";
                cout << "\tYour Choice: "; cin >> c;
                if     (c==1) cout << "\n\t\tPANADOL\n\t\tRS 90\n";
                else if(c==2) cout << "\n\t\tARINAC\n\t\tRS 50\n";
                else if(c==3) cout << "\n\t\tDISPIRIN\n\t\tRS 80\n";
                else          cout << "\n\t\t***INVALID CHOICE***\n";
                break;
            case 6:
                break;
            default:
                cout << "\n\t***ENTER A VALID CHOICE***\n";
        }
    }
};


class Emergency : public HospitalService {
public:
    void displayServiceName() override {
        cout << "\n\t[SERVICE: EMERGENCY]\n";
    }

    void showMenu() override {
        emergencyService();
    }

    bool emergencyService() {
        int a;
        displayServiceName();
        cout << "\n\tENTER YOUR CHOICE\n";
        cout << "\t1.MAJOR ACCIDENT\n";
        cout << "\t2.MINOR ACCIDENT\n";
        cout << "\t3.HEART ATTACK\n";
        cout << "\t4.ANY OTHER EMERGENCIES\n";
        cout << "\t5.EXIT\n";
        cout << "\tYour Choice: ";
        cin  >> a;
        switch(a) {
            case 1: case 2: case 3: case 4:
                cout << "\n\tREQUEST SENT. APPROVED. TREATMENT WITHIN 5 MINS.\n";
                return true;
            case 5:
                return false;
            default:
                cout << "\n\t***ENTER A VALID CHOICE***\n";
                return false;
        }
    }
};


class Appointment : public HospitalService {
private:
    const char* docName[6];
    const char* docSpec[6];
    const char* slots[5];

public:
    Appointment() {
        docName[0] = "Ali Hassan";    docName[1] = "Sara Ahmed";
        docName[2] = "Kamran Malik";  docName[3] = "Nadia Iqbal";
        docName[4] = "Usman Tariq";   docName[5] = "Hira Baig";

        docSpec[0] = "Cardiologist";      docSpec[1] = "Pulmonologist";
        docSpec[2] = "Nephrologist";      docSpec[3] = "Hepatologist";
        docSpec[4] = "General Physician"; docSpec[5] = "Emergency Medicine";

        slots[0] = "09:00 AM - 10:00 AM"; slots[1] = "10:00 AM - 11:00 AM";
        slots[2] = "11:00 AM - 12:00 PM"; slots[3] = "02:00 PM - 03:00 PM";
        slots[4] = "03:00 PM - 04:00 PM";
    }

    void displayServiceName() override {
        cout << "\n\t[SERVICE: APPOINTMENTS]\n";
    }

  
    void showMenu() override {
        displayServiceName();
        cout << "\t1. BOOK APPOINTMENT\n";
        cout << "\t2. VIEW MY APPOINTMENTS\n";
        cout << "\tThis option is available from the main menu.\n";
    }

    void bookAppointment(Patient* p) {
        int docChoice, slotChoice;
        char date[20];

        displayServiceName();
        cout << "\n\t========== APPOINTMENT BOOKING ==========\n";
        cout << "\tPatient: " << p->getName() << "  (Reg# " << p->reg << ")\n\n";

        cout << "\tSELECT DOCTOR:\n";
        for(int i = 0; i < 6; i++)
            cout << "\t" << i+1 << ". Dr. " << docName[i] << "  [" << docSpec[i] << "]\n";
        cout << "\t7. EXIT\n";
        cout << "\tYour Choice: ";
        cin  >> docChoice;

        if(docChoice == 7) return;
        if(docChoice < 1 || docChoice > 6) {
            cout << "\n\t***INVALID DOCTOR CHOICE***\n";
            return;
        }

        cout << "\n\tENTER APPOINTMENT DATE (DD/MM/YYYY): ";
        cin  >> date;

        cout << "\n\tSELECT TIME SLOT:\n";
        for(int i = 0; i < 5; i++)
            cout << "\t" << i+1 << ". " << slots[i] << "\n";
        cout << "\tYour Choice: ";
        cin  >> slotChoice;

        if(slotChoice < 1 || slotChoice > 5) {
            cout << "\n\t***INVALID SLOT CHOICE***\n";
            return;
        }

        cout << "\n\t========== APPOINTMENT CONFIRMED ==========\n";
        cout << "\tPatient   : " << p->getName()           << "\n";
        cout << "\tReg No    : " << p->reg                 << "\n";
        cout << "\tDoctor    : Dr. " << docName[docChoice-1] << "\n";
        cout << "\tSpecialty : " << docSpec[docChoice-1]   << "\n";
        cout << "\tDate      : " << date                   << "\n";
        cout << "\tTime Slot : " << slots[slotChoice-1]    << "\n";
        cout << "\t==========================================\n";

        ofstream file("appointments.txt", ios::app);
        if(file.is_open()) {
            file << "===============================\n";
            file << "Patient Reg No : " << p->reg               << "\n";
            file << "Patient Name   : " << p->getName()         << "\n";
            file << "Doctor         : " << docName[docChoice-1] << "\n";
            file << "Specialty      : " << docSpec[docChoice-1] << "\n";
            file << "Date           : " << date                 << "\n";
            file << "Time Slot      : " << slots[slotChoice-1]  << "\n";
            file << "===============================\n";
            file.close();
            cout << "\tAppointment saved to appointments.txt\n";
        }
    }

    void viewAppointments(int patientReg) {
        ifstream file("appointments.txt");
        if(!file.is_open()) {
            cout << "\n\t***NO APPOINTMENTS FOUND***\n";
            return;
        }
        cout << "\n\t========== APPOINTMENTS ==========\n";
        string line;
        bool show = (patientReg <= 0);
        bool inBlock = false;
        string block = "";

        while(getline(file, line)) {
            if(line.find("===============================") != string::npos) {
                if(show && inBlock)
                    cout << block << "\t===============================\n";
                inBlock = !inBlock;
                block = "";
                show = (patientReg <= 0);
            } else {
                block += "\t" + line + "\n";
                if(patientReg > 0) {
                    string search = "Patient Reg No : " + intToStr(patientReg);
                    if(line.find(search) != string::npos)
                        show = true;
                }
            }
        }
        file.close();
        cout << "\t==================================\n";
    }
};


class Hospital {
private:
    Patient     patients[30];
    int         patientCount;
    int         beds;

   
    Lab         lab;
    Pharmacy    pharmacy;
    Emergency   emergency;
    Appointment appointment;

    
    HospitalService* services[4];

   
    void loadPatientsFromFile() {
        ifstream file("patients.txt");
        if(!file.is_open()) return;

        string line;
        int  tempReg = 0, tempAge = 0;
        char tempName[50] = "", tempGender[20] = "";
        bool inBlock = false;

        while(getline(file, line)) {
            if(line.find("-------------------------------") != string::npos) {
                if(inBlock && tempReg > 0 && patientCount < 30) {
                    patients[patientCount].reg = tempReg;
                    patients[patientCount].setAge(tempAge);
                    patients[patientCount].setName(tempName);
                    patients[patientCount].setGender(tempGender);
                    patientCount++;
                    tempReg = tempAge = 0;
                    tempName[0] = tempGender[0] = '\0';
                }
                inBlock = !inBlock;
            } else if(inBlock) {
                size_t pos = line.find(':');
                if(pos == string::npos) continue;
                string key   = line.substr(0, pos);
                string value = line.substr(pos + 2);
                if     (key.find("Reg No")  != string::npos) tempReg = atoi(value.c_str());
                else if(key.find("Name")    != string::npos) strncpy(tempName,   value.c_str(), 49);
                else if(key.find("Age")     != string::npos) tempAge = atoi(value.c_str());
                else if(key.find("Gender")  != string::npos) strncpy(tempGender, value.c_str(), 19);
            }
        }
        file.close();
    }

public:
    Hospital() {
        patientCount = 0;
        beds = 80;
        loadPatientsFromFile();

        
        services[0] = &lab;
        services[1] = &pharmacy;
        services[2] = &emergency;
        services[3] = &appointment;
    }

    void menu() {
        int a, e, d, f;

        cout << "\t\t\tWELCOME TO CIVIL HOSPITAL\n";
        if(patientCount > 0)
            cout << "\t(" << patientCount << " existing patient(s) loaded from records)\n";

        do {
            cout << "\n\n-------------------------------------------------------------------\n\n";
            cout << "\t1.  NEW REGISTRATION\n";
            cout << "\t2.  LAB TESTS\n";
            cout << "\t3.  PHARMACY\n";
            cout << "\t4.  EMERGENCY\n";
            cout << "\t5.  PATIENT'S INFO\n";
            cout << "\t6.  NO OF BEDS\n";
            cout << "\t7.  BOOK APPOINTMENT\n";
            cout << "\t8.  VIEW APPOINTMENTS\n";
            cout << "\t9.  DISCHARGE PATIENT\n";
            cout << "\t10. EXIT\n";
            cout << "\n\tENTER YOUR CHOICE: ";
            cin  >> a;

            switch(a) {
                case 1:
                    if(patientCount >= 30) {
                        cout << "\n\t***REGISTRATION LIMIT REACHED***\n";
                        break;
                    }
                    patients[patientCount].registerPatient(patientCount + 1);
                    patientCount++;
                    break;

                case 2:
                   
                    services[0]->showMenu();   // Lab
                    cout << "\n\tNEED MEDICATIONS? PRESS 1, OTHERWISE ANY NUMBER: ";
                    cin  >> f;
                    if(f == 1) services[1]->showMenu();  // Pharmacy
                    break;

                case 3:
                    services[1]->showMenu();   // Pharmacy
                    cout << "\n\tNEED LAB TESTS? PRESS 1, OTHERWISE ANY NUMBER: ";
                    cin  >> f;
                    if(f == 1) services[0]->showMenu();  // Lab
                    break;

                case 4:
                    if(emergency.emergencyService()) {
                        if(beds > 0) {
                            beds--;
                            cout << "\tBED ASSIGNED. REMAINING BEDS: " << beds << "\n";
                        } else {
                            cout << "\t***NO BEDS AVAILABLE***\n";
                        }
                    }
                    cout << "\n\tPRESS 1 FOR PHARMACY, 2 FOR LAB TESTS, ANY OTHER TO SKIP: ";
                    cin  >> f;
                    if(f == 1)      services[1]->showMenu();
                    else if(f == 2) services[0]->showMenu();
                    break;

                case 5:
                    cout << "\tENTER YOUR REG NUMBER: ";
                    cin  >> e;
                    if(e >= 1 && e <= patientCount && patients[e-1].reg == e) {
                        cout << "\tENTER YOUR PIN CODE: ";
                        cin  >> d;
                        if(patients[e-1].pin == 0) {
                            cout << "\n\t***PIN NOT AVAILABLE (registered in a previous session)."
                                 << " Please re-register to set a PIN.***\n";
                        } else if(d == patients[e-1].pin) {
                            patients[e-1].showInfo();   
                        } else {
                            cout << "\n\t***INVALID PIN***\n";
                        }
                    } else {
                        cout << "\n\t***NO RECORD FOUND***\n";
                    }
                    break;

                case 6:
                    if(beds > 0)
                        cout << "\n\tNUMBER OF AVAILABLE BEDS: " << beds << endl;
                    else
                        cout << "\n\tNO BEDS AVAILABLE\n";
                    break;

                case 7:
                    cout << "\tENTER YOUR REG NUMBER: ";
                    cin  >> e;
                    if(e >= 1 && e <= patientCount && patients[e-1].reg == e) {
                        cout << "\tENTER YOUR PIN CODE: ";
                        cin  >> d;
                        if(patients[e-1].pin == 0) {
                            cout << "\n\t***PIN NOT AVAILABLE (registered in a previous session)."
                                 << " Please re-register to set a PIN.***\n";
                        } else if(d == patients[e-1].pin) {
                            appointment.bookAppointment(&patients[e-1]);
                        } else {
                            cout << "\n\t***INVALID PIN***\n";
                        }
                    } else {
                        cout << "\n\t***NO RECORD FOUND. REGISTER FIRST.***\n";
                    }
                    break;

                case 8:
                    cout << "\n\tVIEW MODE:\n";
                    cout << "\t1. MY APPOINTMENTS\n";
                    cout << "\t2. ALL APPOINTMENTS (ADMIN)\n";
                    cout << "\tChoice: ";
                    cin  >> f;
                    if(f == 1) {
                        cout << "\tENTER YOUR REG NUMBER: ";
                        cin  >> e;
                        if(e >= 1 && e <= patientCount && patients[e-1].reg == e) {
                            cout << "\tENTER YOUR PIN CODE: ";
                            cin  >> d;
                            if(patients[e-1].pin == 0) {
                                cout << "\n\t***PIN NOT AVAILABLE (registered in a previous session)."
                                     << " Please re-register to set a PIN.***\n";
                            } else if(d == patients[e-1].pin) {
                                appointment.viewAppointments(e);
                            } else {
                                cout << "\n\t***INVALID PIN***\n";
                            }
                        } else {
                            cout << "\n\t***NO RECORD FOUND***\n";
                        }
                    } else if(f == 2) {
                        cout << "\tENTER ADMIN PIN: ";
                        cin  >> d;
                        if(d == 0)
                            appointment.viewAppointments(-1);
                        else
                            cout << "\n\t***ACCESS DENIED***\n";
                    } else {
                        cout << "\n\t***INVALID CHOICE***\n";
                    }
                    break;

                case 9:
                    cout << "\tENTER PATIENT REG TO DISCHARGE: ";
                    cin  >> e;
                    if(e >= 1 && e <= patientCount && patients[e-1].reg == e) {
                        cout << "\tENTER ADMIN PIN: ";
                        cin  >> d;
                        if(d == 0) {
                            if(beds < 80) {
                                beds++;
                                cout << "\tPATIENT DISCHARGED. AVAILABLE BEDS: " << beds << "\n";
                            } else {
                                cout << "\t***ALL BEDS ALREADY FREE***\n";
                            }
                        } else {
                            cout << "\n\t***ACCESS DENIED***\n";
                        }
                    } else {
                        cout << "\n\t***NO RECORD FOUND***\n";
                    }
                    break;

                case 10:
                    cout << "\n\tTHANK YOU FOR VISITING CIVIL HOSPITAL. STAY HEALTHY!\n";
                    break;

                default:
                    cout << "\n\t***ENTER A VALID CHOICE***\n";
            }
        } while(a != 10);
    }
};


int main() {
    Hospital h;
    h.menu();
    return 0;
}