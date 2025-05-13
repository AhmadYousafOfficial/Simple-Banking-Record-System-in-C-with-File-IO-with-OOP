# Bank Records (OOP C++ Program)

A simple banking record management system implemented in C++ using an object-oriented design. This console application allows you to:

* **Add** customer account records
* **Display** all stored records
* **Search** for a specific record by account number

All data is persisted to a plain-text file (`Bank Records.txt`) in the working directory.

---

## Features

* **Account Class**: Encapsulates account number, customer name, and balance.
* **Bank Class**: Manages file I/O, menu-driven user interface, and operations on `Account` objects.
* **Persistent Storage**: Records are saved to and read from a text file using standard C++ streams.
* **Dev-C++ Compatibility**: Uses plain C-style filename initialization and standard headers to ensure broad compiler support.

---

## Requirements

* A C++ compiler supporting C++11 or later (e.g., Dev-C++, g++, clang++)
* No external libraries beyond the C++ Standard Library

---

## Building & Running

1. **Clone or download** this repository to your local machine.

2. **Open** a terminal or Dev-C++ IDE in the project folder.

3. **Compile** the source file:

   ```bash
   g++ -std=c++11 Bank.cpp -o Bank
   ```

   Or, in Dev-C++:

   * Create a new Console Application project
   * Add `Bank.cpp` to the project
   * Build (Ctrl+F9)

4. **Run** the executable:

   ```bash
   ./Bank      # Linux / macOS
   Bank.exe    # Windows
   ```

---

## Usage

Upon launching, the program presents a menu:

```
=== Bank Record System (OOP) ===
1. Add a record
2. Display all records
3. Search for a record
4. Quit
Enter choice:
```

* **Add a record**: Enter account details (number, first/last name, balance).
* **Display**: Lists all records in `Bank Records.txt`.
* **Search**: Find a record by entering its account number.
* **Quit**: Exit the application.

All operations provide feedback on success or failure.

---

## File Structure

```
├── Bank.cpp         # Main source file, contains all classes & main()
├── Bank Records.txt # Data file created at runtime
└── README.md        # Project documentation
```

---

## Contributing

Contributions and suggestions are welcome! Feel free to:

* Open an issue to report bugs or request features
* Submit a pull request with enhancements

---

## License

This project is released under the MIT License. See [LICENSE](LICENSE) for details.
"# Simple-Banking-Record-System-in-C-with-File-IO-with-OOP" 
