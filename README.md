# Academic Mini Project: Bank Account Management System

**Institution / Bank Name:** Nikita Bank of Loni  
**Course:** Object-Oriented Programming (OOP) in C++  
**Project Title:** Bank Account Management System  
**Student Name:** Nikita  
**Language:** C++ (Standard C++11 / C++14 / C++17)  

---

## Files in this Repository
- `main.cpp`: Complete multi-account C++ source code with ATM Card & PIN verification.
- `index.html`: Interactive Full-Screen Web Simulator UI.
- `PROJECT_REPORT.md`: Comprehensive Project Report & Lab Viva Guide.
- `README.md`: Project summary, setup instructions, sample output, and 10 viva Q&As.

---

## How to Compile and Run

Using **g++** (GCC):
```bash
g++ main.cpp -o bank_system
./bank_system
```

Using **Web Browser (Localhost)**:
```bash
python -m http.server 8000
# Open http://localhost:8000/ in Chrome / Edge / Firefox
```

---

## 1. Short Project Description

The **Bank Account Management System** for **Nikita Bank of Loni** is a console and web-assisted academic mini project written in standard C++. It simulates core commercial banking operations including multi-account creation, existing account access, deposit, withdrawal with 4-digit ATM PIN verification and C++ exception handling (`try-catch-throw`), balance checking, demo ATM Card generation, and Passbook statement exports.

---

## 2. Key Features

1. **Create Account:** Name, Account Number, Initial Balance, ATM PIN. Auto-generates a 16-digit demo ATM card. Prevents duplicate account numbers.
2. **Access Existing Account:** Search and load any registered account using Account Number.
3. **Deposit Money:** Add funds with positive deposit validation.
4. **Withdraw Money:** PIN verification + C++ exception handling for overdrawing (`throw runtime_error("Insufficient Balance!")`).
5. **Check Balance:** Displays current balance of any account.
6. **Display Account Details:** Shows full account credentials while keeping PIN hidden.
7. **ATM Card Feature:** Displays formatted demo ATM Debit Card layout.
8. **Passbook & Download Statement:** Real-time transaction history table + text statement download (`Nikita_Bank_Statement_1001.txt`).

---

## 3. C++ Concepts Used

- **Class & Object:** `BankAccount` class; objects stored inside `std::vector<BankAccount>`.
- **Encapsulation & Data Hiding:** Data members (`accountNumber`, `accountHolder`, `balance`, `atmCardNumber`, `atmPin`) declared `private`.
- **Constructors:** Default & Parameterized constructors.
- **Member Functions & Abstraction:** `deposit()`, `withdraw()`, `checkBalance()`, `displayDetails()`, `verifyPin()`, `displayATMCard()`.
- **Data Structure (`std::vector`):** Dynamic multi-account storage in memory.
- **Exception Handling:** `try`, `throw`, and `catch` used for insufficient balance.

---

## 4. 10 Viva Voce Questions & Answers

1. **What is Encapsulation?** Data hiding inside a class using `private` access specifiers.
2. **Why use `std::vector`?** Dynamic container that expands as new accounts are created.
3. **How is the ATM PIN secured?** Stored as `private` and verified via `verifyPin()`, never displayed openly.
4. **How does Exception Handling work in `withdraw()`?** Throws `runtime_error` if `amount > balance`, caught cleanly in `main()`.
5. **How are duplicate accounts prevented?** Vector is searched by `getAccountNumber()` before creating a new account.
6. **What is a Constructor?** Special member function executed automatically on object creation to initialize attributes.
7. **Why are getter methods marked `const`?** Guarantees that the function will only read data without modifying object state.
8. **What happens on invalid non-numeric inputs?** Handled using `cin.clear()` and `cin.ignore()` to prevent infinite loops.
9. **How is the demo ATM Card generated?** Auto-generated using 16-digit academic formatting during account creation.
10. **How can this project be extended?** By using C++ file streams (`fstream`) for data persistence.
