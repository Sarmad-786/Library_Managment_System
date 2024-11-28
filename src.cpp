#include <iostream>
#include <string>

using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    bool isBorrowed;
    Book* left;
    Book* right;

    Book(string t, string a) : title(t), author(a), isBorrowed(false), left(nullptr), right(nullptr) {}
};

// Member structure
struct Member {
    string name;
    string membershipID;
    string mobileNumber;  
    Member* next;

    Member(string n, string id, string mobile) : name(n), membershipID(id), mobileNumber(mobile), next(nullptr) {}
};

// Binary Search Tree for managing books
class BookBST {
private:
    Book* root;

    void insert(Book*& node, const string& title, const string& author) {
        if (node == nullptr) {
            node = new Book(title, author);
        } else if (title < node->title) {
            insert(node->left, title, author);
        } else {
            insert(node->right, title, author);
        }
    }

    Book* search(Book* node, const string& title) {
        if (node == nullptr || node->title == title)
            return node;
        if (title < node->title)
            return search(node->left, title);
        return search(node->right, title);
    }

    void inorder(Book* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << "Title: " << node->title << ", Author: " << node->author 
                 << (node->isBorrowed ? " (Borrowed)" : "") << endl;  // Removed due date
            inorder(node->right);
        }
    }

    void clear(Book* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BookBST() : root(nullptr) {}

    ~BookBST() {
        clear(root);  // Clear all books when the BST is destroyed
    }

    void addBook(const string& title, const string& author) {
        insert(root, title, author);
    }

    Book* findBook(const string& title) {
        return search(root, title);
    }

    void displayBooks() {
        inorder(root);
    }

    bool markAsBorrowed(const string& title) {
        Book* book = findBook(title);
        if (book && !book->isBorrowed) {
            book->isBorrowed = true;
            return true;
        }
        return false;
    }

    void markAsReturned(const string& title) {
        Book* book = findBook(title);
        if (book) {
            book->isBorrowed = false;
        }
    }

    bool isBookBorrowed(const string& title) {
        Book* book = findBook(title);
        return book && book->isBorrowed;
    }
};

// Linked List for managing members
class MemberList {
private:
    Member* head;

public:
    MemberList() : head(nullptr) {}

    void addMember(const string& name, const string& id, const string& mobile) {
        Member* newMember = new Member(name, id, mobile);
        newMember->next = head;
        head = newMember;
    }

    Member* findMember(const string& id) {
        Member* current = head;
        while (current) {
            if (current->membershipID == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void displayMembers() {
        Member* current = head;
        while (current) {
            cout << "Name: " << current->name 
                 << ", ID: " << current->membershipID 
                 << ", Mobile: " << current->mobileNumber << endl;  // Removed dues
            current = current->next;
        }
    }

    // Destructor to free memory
    ~MemberList() {
        while (head) {
            Member* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Library class to integrate all functionalities
class Library {
private:
    BookBST bookCatalog;
    MemberList members;

public:
    void registerMember(const string& name, const string& id, const string& mobile) {
        members.addMember(name, id, mobile);
    }

    void addBook(const string& title, const string& author) {
        bookCatalog.addBook(title, author);
    }

    void borrowBook(const string& title, const string& memberID) {
        if (members .findMember(memberID)) {
            if (bookCatalog.markAsBorrowed(title)) {
                cout << "Book borrowed successfully.\n";
            } else {
                cout << "Book does not exist or is already borrowed.\n";
            }
        } else {
            cout << "Member is not registered.\n";
        }
    }

    void returnBook(const string& title) {
        bookCatalog.markAsReturned(title);
        cout << "Book returned successfully.\n";
    }

    void displayBooks() {
        bookCatalog.displayBooks();
    }

    void displayMembers() {
        members.displayMembers();
    }
};

// Main function for the Library Management System
int main() {
    Library library;
    int choice;

    do {
        cout << "\nLibrary Management System \n";
        cout << "1. Register Member\n";
        cout << "2. Add Book\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Books\n";
        cout << "6. Display Members\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character after the integer input

        if (choice == 1) {
            string name, id, mobile;
            cout << "Enter member name: ";
            getline(cin, name);
            cout << "Enter membership ID: ";
            getline(cin, id);
            cout << "Enter mobile number: ";
            getline(cin, mobile);
            library.registerMember(name, id, mobile);
            cout << "Member registered successfully.\n";
        } else if (choice == 2) {
            string title, author;
            cout << "Enter the title of the book: ";
            getline(cin, title);
            cout << "Enter the author of the book: ";
            getline(cin, author);
            library.addBook(title, author);
            cout << "Book added successfully.\n";
        } else if (choice == 3) {
            string title, memberID;
            cout << "Enter the title of the book to borrow: ";
            getline(cin, title);
            cout << "Enter your membership ID: ";
            getline(cin, memberID);
            library.borrowBook(title, memberID);
        } else if (choice == 4) {
            string title;
            cout << "Enter the title of the book to return: ";
            getline(cin, title);
            library.returnBook(title);
        } else if (choice == 5) {
            cout << "Available Books:\n";
            library.displayBooks();
        } else if (choice == 6) {
            cout << "Registered Members:\n";
            library.displayMembers();
        }
    } while (choice != 0);

    return 0;
}
