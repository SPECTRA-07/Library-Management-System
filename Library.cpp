#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store book details
struct Book {
    int id;
    string title;
    string author;
    string genre;
    int availableCopies;
};

// Library class to manage operations
class Library {
private:
    vector<Book> books;

public:
    // Add a new book
    void addBook(int id, string title, string author, string genre, int copies) {
        books.push_back({id, title, author, genre, copies});
        cout << "Book added successfully!\n";
    }

    // Search for a book by title
    void searchBookByTitle(string title) {
        bool found = false;
        for (const auto &book : books) {
            if (book.title == title) {
                displayBookDetails(book);
                found = true;
                break;
            }
        }
        if (!found) cout << "Book with title \"" << title << "\" not found.\n";
    }

    // Borrow a book
    void borrowBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                if (book.availableCopies > 0) {
                    book.availableCopies--;
                    cout << "You borrowed the book: " << book.title << "\n";
                } else {
                    cout << "Sorry, no copies available for this book.\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    // Return a book
    void returnBook(int id) {
        for (auto &book : books) {
            if (book.id == id) {
                book.availableCopies++;
                cout << "You returned the book: " << book.title << "\n";
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "List of Books in the Library:\n";
        for (const auto &book : books) {
            displayBookDetails(book);
        }
    }

private:
    // Helper function to display book details
    void displayBookDetails(const Book &book) {
        cout << "ID: " << book.id
             << ", Title: " << book.title
             << ", Author: " << book.author
             << ", Genre: " << book.genre
             << ", Available Copies: " << book.availableCopies << "\n";
    }
};

// Main function
int main() {
    Library library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book by Title\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, copies;
                string title, author, genre;
                cout << "Enter book ID: ";
                cin >> id;
                cin.ignore(); // Clear input buffer
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter number of copies: ";
                cin >> copies;
                library.addBook(id, title, author, genre, copies);
                break;
            }
            case 2: {
                string title;
                cin.ignore();
                cout << "Enter the title of the book: ";
                getline(cin, title);
                library.searchBookByTitle(title);
                break;
            }
            case 3: {
                int id;
                cout << "Enter the ID of the book to borrow: ";
                cin >> id;
                library.borrowBook(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter the ID of the book to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            }
            case 5:
                library.displayBooks();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
