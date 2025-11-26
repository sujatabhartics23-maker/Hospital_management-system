# 🏥 Hospital Management System (C Programming)

A simple and efficient *Hospital Management System* built using *C language* with complete CRUD operations, login system, and file handling.  
This project helps in managing patient records such as adding, viewing, searching, updating, and deleting patient information.

---

## 📌 Features

### ✅ 1. Admin Login
- Secure login system  
- Default Username: admin  
- Default Password: 123

### ✅ 2. Add Patient
- Add patient ID, name, age, and disease  
- Stores data using file handling

### ✅ 3. View All Patients
- Display all stored patient records  
- Fetch data directly from file

### ✅ 4. Search Patient
- Search patients by their unique ID

### ✅ 5. Update Patient Details
- Modify stored patient information  
- Uses a temporary file for data replacement

### ✅ 6. Delete Patient Record
- Remove patient entry from database  
- Ensures safe deletion

### 📁 File Handling
All patient data is stored in:

patients.txt

---

## 🛠 Technologies Used
- *C Programming*
- *File Handling*
- *Structures*
- *Functions / Modular Code*
- *Basic Authentication Logic*

---

## 🚀 How to Run this Project

### *1️⃣ Compile the Program*
```bash
gcc main.c -o hospital

2️⃣ Run the Program

Windows:

hospital.exe

Linux/Mac:

./hospital


---

📂 Project Structure

Hospital-Management-System/
│
├── main.c
├── patients.txt        (auto created after adding first patient)
└── README.md


---

📸 Output (Flow Overview)

===== LOGIN =====

Username: admin
Password: 123

===== HOSPITAL MANAGEMENT SYSTEM =====
1. Add Patient
2. View All Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Exit
---------------------------------------
Enter your choice:


---

🎯 Learning Outcomes

File handling in C

CRUD operations

Use of structures

Menu-driven program

Real-world system logic

Working with temporary files for update/delete



---

🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to improve.


---
