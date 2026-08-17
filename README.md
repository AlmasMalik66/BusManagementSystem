# Bus Management System

A console-based Bus Management System built in C++ using Object-Oriented Programming principles and file handling for persistent data storage.

## Features

- **Bus Records**: Add, view (single/all), update, and delete bus records
- **Route Management**: View predefined bus routes with departure/arrival timings
- **Seat Management**: Check total, reserved, and available seats per bus; renew (release) all reserved seats for a bus
- **Booking System**: Book seats on a bus with duplicate-seat validation; search, update, and delete individual booking records
- **Authentication**: Basic login system to secure access to the system

## Tech Stack

- **Language**: C++
- **Concepts Used**: Object-Oriented Programming (Classes & Objects), File I/O (`fstream`), Control Flow
- **Data Storage**: Flat text files (`bus.txt`, `seat.txt`)

## How to Run

> Note: This project uses `conio.h` and `system("cls")`, which are Windows-specific. It is designed to run on Windows using a MinGW (g++) compiler.

1. Clone the repository:
   ```
   git clone https://github.com/<your-username>/Bus-Management-System.git
   cd Bus-Management-System
   ```
2. Compile:
   ```
   g++ Bus_Management_System.cpp -o bus_system
   ```
3. Run:
   ```
   .\bus_system.exe
   ```
4. Demo login credentials:
   ```
   Email: admin@busmanagement.com
   Password: admin1
   ```

## Project Structure

```
Bus-Management-System/
├── Bus_Management_System.cpp   # Main source file
├── README.md
└── .gitignore
```

## Known Limitations

- Data is stored in plain text files rather than a database (academic-scope project)
- Windows-only due to `conio.h` dependency

## Author

Hafiza Almas Sarwar
