#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

struct Date {
    int day, month, year;
};

Date getTodayDate() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    Date d;
    d.day = now->tm_mday;
    d.month = now->tm_mon + 1;
    d.year = now->tm_year + 1900;

    return d;
}

Date addDays(Date d, int days) {
    tm t = {};
    t.tm_mday = d.day + days;
    t.tm_mon = d.month - 1;
    t.tm_year = d.year - 1900;

    mktime(&t);

    Date newDate;
    newDate.day = t.tm_mday;
    newDate.month = t.tm_mon + 1;
    newDate.year = t.tm_year + 1900;

    return newDate;
}

int dateDiff(Date d1, Date d2) {
    tm a;
    memset(&a, 0, sizeof(tm));
    a.tm_mday = d1.day;
    a.tm_mon = d1.month - 1;
    a.tm_year = d1.year - 1900;

    tm b;
    memset(&b, 0, sizeof(tm));
    b.tm_mday = d2.day;
    b.tm_mon = d2.month - 1;
    b.tm_year = d2.year - 1900;

    time_t x = mktime(&a);
    time_t y = mktime(&b);

    double diff = difftime(y, x) / (60 * 60 * 24);
    return (int)diff;
}

class book {
public:
    int id;
    int price;
    bool availability;
    book* nextbook;

    book(int x, int y) {
        id = x;
        price = y;
        availability = true;
        nextbook = nullptr;
    }
};

class student {
public:
    string name;
    int regno;
    int noofissue;
    student* nextstudent;

    student(string x, int y) {
        name = x;
        regno = y;
        noofissue = 0;
        nextstudent = nullptr;
    }
};

class issue {
public:
    int regno;
    int bookid;
    Date issuedate;
    Date duedate;
    issue* nextissue;

    issue(int r, int b, Date i, Date d) {
        regno = r;
        bookid = b;
        issuedate = i;
        duedate = d;
        nextissue = nullptr;
    }
};

class library {
public:
    book* bookheadptr;
    student* studentheadptr;
    issue* issueheadptr;

    library() {
        bookheadptr = nullptr;
        studentheadptr = nullptr;
        issueheadptr = nullptr;
        loadData();
    }

    void saveData() {
        ofstream bf("books.txt");
        book* b = bookheadptr;
        while (b) {
            bf << b->id << " " << b->price << " " << b->availability << endl;
            b = b->nextbook;
        }
        bf.close();

        ofstream sf("students.txt");
        student* s = studentheadptr;
        while (s) {
            sf << s->name << " " << s->regno << " " << s->noofissue << endl;
            s = s->nextstudent;
        }
        sf.close();

        ofstream iff("issues.txt");
        issue* i = issueheadptr;
        while (i) {
            iff << i->regno << " " << i->bookid << " "
                << i->issuedate.day << " " << i->issuedate.month << " " << i->issuedate.year << " "
                << i->duedate.day << " " << i->duedate.month << " " << i->duedate.year << endl;

            i = i->nextissue;
        }
        iff.close();
    }

    void loadData() {
        ifstream bf("books.txt");
        int id, price;
        bool avail;
        while (bf >> id >> price >> avail) {
            book* temp = bookheadptr;
            bookheadptr = new book(id, price);
            bookheadptr->availability = avail;
            bookheadptr->nextbook = temp;
        }
        bf.close();

        ifstream sf("students.txt");
        string name;
        int reg, noi;
        while (sf >> name >> reg >> noi) {
            student* temp = studentheadptr;
            studentheadptr = new student(name, reg);
            studentheadptr->noofissue = noi;
            studentheadptr->nextstudent = temp;
        }
        sf.close();

        ifstream iff("issues.txt");
        int bid;
        int iday, imonth, iyear;
        int dday, dmonth, dyear;

        while (iff >> reg >> bid >> iday >> imonth >> iyear >> dday >> dmonth >> dyear) {
            Date issueDate = {iday, imonth, iyear};
            Date dueDate = {dday, dmonth, dyear};

            issue* temp = issueheadptr;
            issueheadptr = new issue(reg, bid, issueDate, dueDate);
            issueheadptr->nextissue = temp;

            book* b = bookheadptr;
            while (b && b->id != bid) b = b->nextbook;
            if (b) b->availability = false;

            student* s = studentheadptr;
            while (s && s->regno != reg) s = s->nextstudent;
            if (s) s->noofissue++;
        }
        iff.close();
    }

    void addnewbook() {
        int a, b;
        cout << "Enter book id: ";
        cin >> a;
        cout << "Enter book price: ";
        cin >> b;

        book* temp = bookheadptr;
        bookheadptr = new book(a, b);
        bookheadptr->nextbook = temp;

        cout << "Book added successfully!" << endl;
    }

    void addnewstudent() {
        string a;
        int b;
        cout << "Enter student name: ";
        cin >> a;
        cout << "Enter reg no: ";
        cin >> b;

        student* temp = studentheadptr;
        studentheadptr = new student(a, b);
        studentheadptr->nextstudent = temp;

        cout << "Student added!" << endl;
    }

    void deleteBook() {
        int bid;
        cout << "Enter Book ID to delete: ";
        cin >> bid;

        book* curr = bookheadptr;
        book* prev = nullptr;

        while (curr && curr->id != bid) {
            prev = curr;
            curr = curr->nextbook;
        }

        if (!curr) {
            cout << "Book not found!" << endl;
            return;
        }

        if (!curr->availability) {
            cout << "Book currently issued, can't delete!" << endl;
            return;
        }

        if (!prev)
            bookheadptr = curr->nextbook;
        else
            prev->nextbook = curr->nextbook;

        delete curr;

        cout << "Book deleted!" << endl;
    }

    void deleteStudent() {
        int reg;
        cout << "Enter student reg no: ";
        cin >> reg;

        student* curr = studentheadptr;
        student* prev = nullptr;

        while (curr && curr->regno != reg) {
            prev = curr;
            curr = curr->nextstudent;
        }

        if (!curr) {
            cout << "Student not found!" << endl;
            return;
        }

        if (curr->noofissue > 0) {
            cout << "Student has issued books. Can't delete!" << endl;
            return;
        }

        if (!prev)
            studentheadptr = curr->nextstudent;
        else
            prev->nextstudent = curr->nextstudent;

        delete curr;

        cout << "Student deleted!" << endl;
    }

    void issuebook() {
        int reg, bid;
        cout << "Enter student reg no: ";
        cin >> reg;
        cout << "Enter book id: ";
        cin >> bid;

        student* s = studentheadptr;
        while (s && s->regno != reg) s = s->nextstudent;
        if (!s) {
            cout << "Student not found!" << endl;
            return;
        }

        book* bptr = bookheadptr;
        while (bptr && bptr->id != bid) bptr = bptr->nextbook;
        if (!bptr) {
            cout << "Book not found!" << endl;
            return;
        }

        if (!bptr->availability) {
            cout << "Book unavailable!" << endl;
            return;
        }

        if (s->noofissue >= 3) {
            cout << "Student issued max limit!" << endl;
            return;
        }

        Date today = getTodayDate();
        Date due = addDays(today, 14);

        issue* temp = issueheadptr;
        issueheadptr = new issue(reg, bid, today, due);
        issueheadptr->nextissue = temp;

        bptr->availability = false;
        s->noofissue++;

        cout << "Book issued!" << endl;
        cout << "Due date: " << due.day << "/" << due.month << "/" << due.year << endl;
    }

    void returnbook() {
        int reg, bid;
        cout << "Enter reg no: ";
        cin >> reg;
        cout << "Enter book id: ";
        cin >> bid;

        issue* curr = issueheadptr;
        issue* prev = nullptr;

        while (curr && !(curr->regno == reg && curr->bookid == bid)) {
            prev = curr;
            curr = curr->nextissue;
        }

        if (!curr) {
            cout << "Issue record not found!" << endl;
            return;
        }

        Date today = getTodayDate();
        int late = dateDiff(curr->duedate, today);

        if (late > 0) {
            cout << "Late by " << late << " days!" << endl;
            cout << "Fine = Rs. " << late * 5 << endl;
        }

        student* s = studentheadptr;
        while (s && s->regno != reg) s = s->nextstudent;

        book* bptr = bookheadptr;
        while (bptr && bptr->id != bid) bptr = bptr->nextbook;

        if (s) s->noofissue--;
        if (bptr) bptr->availability = true;

        if (!prev)
            issueheadptr = curr->nextissue;
        else
            prev->nextissue = curr->nextissue;

        delete curr;

        cout << "Book returned!" << endl;
    }

    void showallbooks() {
        book* temp = bookheadptr;
        if (!temp) {
            cout << "No books found!" << endl;
            return;
        }

        cout << "\n--- BOOK LIST ---\n";
        while (temp) {
            cout << "ID: " << temp->id 
                 << " | Price: " << temp->price
                 << " | Available: " << (temp->availability ? "Yes" : "No") 
                 << endl;
            temp = temp->nextbook;
        }
    }

    void showallstudents() {
        student* temp = studentheadptr;
        if (!temp) {
            cout << "No students!" << endl;
            return;
        }

        cout << "\n--- STUDENT LIST ---\n";
        while (temp) {
            cout << "Name: " << temp->name
                 << " | Reg: " << temp->regno
                 << " | Issued: " << temp->noofissue
                 << endl;
            temp = temp->nextstudent;
        }
    }

    void showallissued() {
        issue* temp = issueheadptr;
        if (!temp) {
            cout << "No issued books!" << endl;
            return;
        }

        cout << "\n--- ISSUED BOOKS ---\n";
        while (temp) {
            cout << "Student Reg: " << temp->regno
                 << " | Book ID: " << temp->bookid
                 << " | Issue Date: " << temp->issuedate.day << "/" 
                                       << temp->issuedate.month << "/" 
                                       << temp->issuedate.year
                 << " | Due Date: " << temp->duedate.day << "/"
                                     << temp->duedate.month << "/"
                                     << temp->duedate.year << endl;

            temp = temp->nextissue;
        }
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;

        book* temp = bookheadptr;
        while (temp && temp->id != id)
            temp = temp->nextbook;

        if (!temp) {
            cout << "Book not found!" << endl;
            return;
        }

        cout << "Book found!\n";
        cout << "ID: " << temp->id 
             << " | Price: " << temp->price
             << " | Available: " << (temp->availability ? "Yes" : "No") 
             << endl;
    }

    void searchStudent() {
        int reg;
        cout << "Enter Reg No: ";
        cin >> reg;

        student* temp = studentheadptr;
        while (temp && temp->regno != reg)
            temp = temp->nextstudent;

        if (!temp) {
            cout << "Student not found!" << endl;
            return;
        }

        cout << "Student found!\n";
        cout << "Name: " << temp->name
             << " | Regno: " << temp->regno
             << " | Issued: " << temp->noofissue << endl;
    }

    void sortBooks() {
        if (!bookheadptr) return;

        for (book* i = bookheadptr; i->nextbook; i = i->nextbook) {
            for (book* j = i->nextbook; j; j = j->nextbook) {
                if (i->id > j->id) {
                    swap(i->id, j->id);
                    swap(i->price, j->price);
                    swap(i->availability, j->availability);
                }
            }
        }
        cout << "Books sorted by ID!" << endl;
    }

    void sortStudents() {
        if (!studentheadptr) return;

        for (student* i = studentheadptr; i->nextstudent; i = i->nextstudent) {
            for (student* j = i->nextstudent; j; j = j->nextstudent) {
                if (i->regno > j->regno) {
                    swap(i->regno, j->regno);
                    swap(i->name, j->name);
                    swap(i->noofissue, j->noofissue);
                }
            }
        }
        cout << "Students sorted by Reg No!" << endl;
    }

    ~library() {
        saveData();
    }
};

bool login() {
    string user, pass;

    cout << "Enter username: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    if (user == "admin" && pass == "admin123") {
        cout << "\nAdmin login successful!\n";
        return true;
    }

    cout << "Invalid credentials!\n";
    return false;
}

int main() {
    if (!login()) return 0;

    library mylib;
    int option;

    while (true) {
        cout << "\n----- LIBRARY MENU -----\n";
        cout << "0. Add Book\n";
        cout << "1. Add Student\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Delete Student\n";
        cout << "6. Show Books\n";
        cout << "7. Show Students\n";
        cout << "8. Show Issued Books\n";
        cout << "9. Search Book\n";
        cout << "10. Search Student\n";
        cout << "11. Sort Books\n";
        cout << "12. Sort Students\n";
        cout << "13. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch(option){
        case 0: mylib.addnewbook(); 
        break;
        case 1: mylib.addnewstudent(); 
        break;
        case 2: mylib.issuebook(); 
        break;
        case 3: mylib.returnbook(); 
        break;
        case 4: mylib.deleteBook(); 
        break;
        case 5: mylib.deleteStudent(); 
        break;
        case 6: mylib.showallbooks(); 
        break;
        case 7: mylib.showallstudents(); 
        break;
        case 8: mylib.showallissued(); 
        break;
        case 9: mylib.searchBook(); 
        break;
        case 10: mylib.searchStudent(); 
        break;
        case 11: mylib.sortBooks(); 
        break;
        case 12: mylib.sortStudents(); 
        break;
        case 13: 
            return 0;
        default:
            cout << "Invalid option!";
        }
    }

    return 0;
}
