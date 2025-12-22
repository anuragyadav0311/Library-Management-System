C++ Library Management System

A robust, console-based Library Management System built from scratch using C++. This project demonstrates the implementation of **Data Structures (Linked Lists)** for dynamic memory management and **File Handling** for data persistence.

Overview :
This application allows library administrators to manage books, students, and issue records efficiently. Unlike simple array-based projects, this system uses custom Linked List classes to handle data, ensuring efficient insertion and deletion operations. It also simulates real-world dates for calculating fines on overdue books.

Key Features:
* **Admin Authentication:** Secure login system to prevent unauthorized access.
* **Book Management:** Add, delete, search, and sort books by ID.
* **Student Management:** Register and manage student details.
* **Issue & Return Logic:** * Tracks issue dates and calculates due dates (14 days).
    * **Fine Calculation:** Automatically calculates fines (Rs. 5 per day) for late returns.
* **Data Persistence:** All data (books, students, issues) is saved to `.txt` files (`books.txt`, `students.txt`, `issues.txt`) and loaded automatically upon startup.
* **Inventory Control:** Prevents issuing books that are already unavailable.

Tech Stack :
* **Language:** C++
* **Data Structures:** Singly Linked Lists (Custom implementation for Books, Students, and Issues)
* **Storage:** File I/O (Text files)
* **Time Management:** `<ctime>` library for date arithmetic.

Login Credentials :
To access the system, use the following default admin credentials:
* **Username:** `admin`
* **Password:** `admin123`
> **Note:** You can modify the `login()` function in the source code to change these credentials.

How to Run :
1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/your-username/library-management-system.git](https://github.com/your-username/library-management-system.git)
    ```
2.  **Compile the code:**
    ```bash
    g++ main.cpp -o library_app
    ```
3.  **Run the application:**
    * **Windows:** `library_app.exe`
    * **Linux/Mac:** `./library_app`

Future Roadmap (To-Do) :
I am actively working on improving this project. Here are the upcoming goals:
* [ ] **GUI Integration:** Migrating from Console to a Graphical User Interface (using Qt or wxWidgets) for a better user experience.
* [ ] **Database Support:** Replacing text files with SQLite or MySQL for better data handling.
* [ ] **User Accounts:** creating a separate interface for students to view their own status.
* [ ] **Code Refactoring:** Splitting the monolithic file into header (`.h`) and implementation (`.cpp`) files.

Contributing :
Contributions are welcome! This is an open-source project intended for learning and improvement.
**How you can help:**
1.  **Fork** this repository.
2.  **Debug:** Find and fix edge cases in the logic.
3.  **Optimize:** Improve the sorting algorithms or memory management.
4.  Create a **Pull Request** with your changes.

If you find a bug, please open an issue!

License :
This project is open-source and available for use and modification.
