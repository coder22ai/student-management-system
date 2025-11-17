#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// ----------------------------------------------------
// Abstract Base Class
// ----------------------------------------------------
class BaseRecord {
public:
    virtual void display() const = 0;  // pure virtual function
};

// ----------------------------------------------------
// Student Class (Inheritance + OOP features)
// ----------------------------------------------------
class Student : public BaseRecord {
protected:
    int rollNo;
    string name;
    string address;
    string contact;
    int marks[5];
    float percentage;
    char grade;

public:
    Student() {
        rollNo = 0;
        name = address = contact = "N/A";
        for (int i = 0; i < 5; i++) marks[i] = 0;
        percentage = 0;
        grade = 'F';
    }

    Student(int r, string n, string add, string con, int m[5]) {
        rollNo = r;
        name = n;
        address = add;
        contact = con;
        for (int i = 0; i < 5; i++) marks[i] = m[i];
        calculatePercentage();
        calculateGrade();
    }

    // Calculate percentage
    void calculatePercentage() {
        int total = 0;
        for (int i = 0; i < 5; i++) total += marks[i];
        percentage = total / 5.0;
    }

    // Calculate grade based on percentage
    void calculateGrade() {
        if (percentage >= 90) grade = 'A';
        else if (percentage >= 75) grade = 'B';
        else if (percentage >= 50) grade = 'C';
        else grade = 'F';
    }

    int getRoll() const { return rollNo; }
    float getPercentage() const { return percentage; }
    char getGrade() const { return grade; }

    // Display Student Record (Virtual Override)
    void display() const override {
        cout << "\n----- Student Record -----\n";
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) cout << marks[i] << " ";
        cout << "\nPercentage: " << percentage;
        cout << "\nGrade: " << grade << endl;
    }

    // Write to file
    void writeToFile(ofstream &out) {
        out << rollNo << endl << name << endl << address << endl
            << contact << endl;
        for (int i = 0; i < 5; i++) out << marks[i] << " ";
        out << endl;
    }

    // Read from file
    void readFromFile(ifstream &in) {
        in >> rollNo;
        in.ignore();
        getline(in, name);
        getline(in, address);
        getline(in, contact);
        for (int i = 0; i < 5; i++) in >> marks[i];
        calculatePercentage();
        calculateGrade();
    }

    friend void compareStudent(const Student &s1, const Student &s2);
};

// Friend function to compare two students
void compareStudent(const Student &s1, const Student &s2) {
    cout << "\nComparing Result:";
    if (s1.percentage > s2.percentage)
        cout << "\n" << s1.name << " has better result.";
    else if (s1.percentage < s2.percentage)
        cout << "\n" << s2.name << " has better result.";
    else
        cout << "\nBoth have same percentage!";
}

// ----------------------------------------------------
// Student Manager Class (Handles all records)
// ----------------------------------------------------
class StudentManager {
private:
    Student *students;
    int count;
    int capacity;

public:
    StudentManager() {
        count = 0;
        capacity = 50;
        students = new Student[capacity];
        loadFromFile();
    }

    ~StudentManager() {
        saveToFile();
        delete[] students;
    }

    // Resize array
    void resize() {
        capacity *= 2;
        Student *newArr = new Student[capacity];
        for (int i = 0; i < count; i++) newArr[i] = students[i];
        delete[] students;
        students = newArr;
    }

    // Add student
    void addStudent() {
        if (count >= capacity) resize();

        int roll;
        cout << "\nEnter Roll Number: ";
        cin >> roll;

        // Check duplicate roll number
        for (int i = 0; i < count; i++) {
            if (students[i].getRoll() == roll) {
                cout << "\n❌ Roll Number already exists!";
                return;
            }
        }

        cin.ignore();
        string name, address, contact;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Address: ";
        getline(cin, address);
        cout << "Enter Contact: ";
        getline(cin, contact);

        int marks[5];
        cout << "Enter marks of 5 subjects: ";
        for (int i = 0; i < 5; i++) cin >> marks[i];

        students[count++] = Student(roll, name, address, contact, marks);

        cout << "\n✅ Student Record Added Successfully!\n";
    }

    // Search student
    void searchStudent() {
        int roll;
        cout << "\nEnter Roll Number: ";
        cin >> roll;

        for (int i = 0; i < count; i++) {
            if (students[i].getRoll() == roll) {
                students[i].display();
                return;
            }
        }
        cout << "\n❌ Student Not Found!";
    }

    // Display all
    void displayAll() {
        if (count == 0) {
            cout << "\nNo records found!";
            return;
        }
        for (int i = 0; i < count; i++) {
            students[i].display();
        }
    }

    // Modify student
    void modifyStudent() {
        int roll;
        cout << "\nEnter Roll Number to Modify: ";
        cin >> roll;

        for (int i = 0; i < count; i++) {
            if (students[i].getRoll() == roll) {
                cout << "\nRecord Found!";
                students[i].display();

                cout << "\nEnter new details...\n";

                cin.ignore();
                string name, address, contact;
                cout << "Name: ";
                getline(cin, name);
                cout << "Address: ";
                getline(cin, address);
                cout << "Contact: ";
                getline(cin, contact);

                int marks[5];
                cout << "Marks: ";
                for (int j = 0; j < 5; j++) cin >> marks[j];

                students[i] = Student(roll, name, address, contact, marks);

                cout << "\n✅ Record Updated!";
                return;
            }
        }

        cout << "\n❌ Record Not Found!";
    }

    // Delete student
    void deleteStudent() {
        int roll;
        cout << "\nEnter Roll Number to Delete: ";
        cin >> roll;

        for (int i = 0; i < count; i++) {
            if (students[i].getRoll() == roll) {

                char choice;
                cout << "\nAre you sure? (Y/N): ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y') {
                    for (int j = i; j < count - 1; j++)
                        students[j] = students[j + 1];
                    count--;
                    cout << "\n✅ Record Deleted!";
                }
                return;
            }
        }
        cout << "\n❌ Record Not Found!";
    }

    // Display class result summary
    void displayClassResult() {
        cout << "\n---- Class Result ----\n";
        cout << left << setw(10) << "Roll"
             << setw(20) << "Name"
             << setw(12) << "Percent"
             << setw(10) << "Grade" << endl;
        cout << "----------------------------------------\n";

        for (int i = 0; i < count; i++) {
            cout << left << setw(10) << students[i].getRoll()
                 << setw(20) << students[i].getRoll()
                 << setw(12) << students[i].getPercentage()
                 << setw(10) << students[i].getGrade()
                 << endl;
        }
    }

    // Save to file
    void saveToFile() {
        ofstream out("students.dat");
        out << count << endl;

        for (int i = 0; i < count; i++)
            students[i].writeToFile(out);
    }

    // Load from file
    void loadFromFile() {
        ifstream in("students.dat");
        if (!in) return;

        in >> count;
        for (int i = 0; i < count; i++)
            students[i].readFromFile(in);
    }
};

// ----------------------------------------------------
// Template Function (Like your Finance tracker)
// ----------------------------------------------------
template<class T>
void showMessage(T msg) {
    cout << "\n[Message]: " << msg << endl;
}

// ----------------------------------------------------
// MAIN MENU
// ----------------------------------------------------
int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n===== STUDENT RECORD MANAGER =====\n";
        cout << "1. Create Student Record\n";
        cout << "2. Search Student Record\n";
        cout << "3. Display All Records\n";
        cout << "4. Modify Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Display Class Result\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.searchStudent(); break;
            case 3: manager.displayAll(); break;
            case 4: manager.modifyStudent(); break;
            case 5: manager.deleteStudent(); break;
            case 6: manager.displayClassResult(); break;
            case 7: showMessage("Thank you for using Student Manager!"); break;
            default: cout << "\nInvalid Choice!";
        }

    } while (choice != 7);

    return 0;
}
