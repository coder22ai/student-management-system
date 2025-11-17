# student-management-system


 📘 Student Record Manager (C++ OOP Project)

A complete Student Record Management System built using Object-Oriented Programming (OOP) in C++.
This project demonstrates real-world application of **classes, objects, inheritance, polymorphism, file handling, templates, dynamic memory allocation, and abstract classes.

The system allows users to **create, search, update, delete, and save student records**, as well as generate class results with percentage and grade evaluation.

---

## 🚀 Features

### ✔ Create Student Record

* Adds a new student with roll number, name, address, contact, and marks
* Prevents duplicate roll numbers
* Automatically calculates percentage and grade

### ✔ Search Student by Roll Number

* Locates and displays a student's full information

### ✔ Display All Student Records

* Neatly prints all saved student records in a structured format

### ✔ Modify Student Record

* Update personal info or marks
* Recalculates percentage & grade

### ✔ Delete Student Record

* Remove a student using roll number
* Confirmation before deletion

### ✔ Display Class Result

* Shows a summarized result sheet
* Includes roll number, percentage, and grade
* Can be extended to ranking or sorting

### ✔ File Handling

Records are automatically saved in:

```
students.dat
```

Loaded again when the program starts.

---

## 🧠 Concepts Used (Full Syllabus Coverage)

This project includes **all major C++ OOP and advanced concepts**, such as:

### 🔹 Object-Oriented Concepts

* Classes & Objects
* Encapsulation
* Constructors & Destructors
* Access Specifiers
* Member Functions
* Array of Objects

### 🔹 Intermediate Concepts

* Function Overloading
* Friend Function (`compareStudent`)
* Templates (`showMessage<T>()`)
* Dynamic Memory Allocation (`new` & `delete`)
* this Pointer *(optional, easy to add)*

### 🔹 Advanced OOP

* Abstract Class (`BaseRecord`)
* Pure Virtual Function (`display()`)
* Inheritance
* Function Overriding
* Polymorphism & Dynamic Binding

### 🔹 File Handling

* fstream (read/write/update/delete)
* Persistent storage


## 📂 Project Structure


📁 Student Record Manager
│
├── student_manager.cpp       # Main source code
├── students.dat              # Auto-generated persistent data file
└── README.md                 # Documentation


## ▶️ How to Run

### Compile:

```bash
g++ student_manager.cpp -o manager


## 🖥️ Example Menu

```
===== STUDENT RECORD MANAGER =====
1. Create Student Record
2. Search Student Record
3. Display All Records
4. Modify Student Record
5. Delete Student Record
6. Display Class Result
7. Exit
Enter your choice:

