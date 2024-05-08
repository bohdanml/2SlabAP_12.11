#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Book {
    int udcNumber;
    string authorName;
    string title;
    int year;
    int copies;
};


void addBook(vector<Book>& library) {
    Book newBook;
    cout << "Enter UDC number: ";
    cin >> newBook.udcNumber;
    cout << "Enter author's name: ";
    cin >> ws; 
    getline(cin, newBook.authorName);
    cout << "Enter title: ";
    getline(cin, newBook.title);
    cout << "Enter year of publication: ";
    cin >> newBook.year;
    cout << "Enter number of copies: ";
    cin >> newBook.copies;

    library.push_back(newBook);
}


void removeBook(vector<Book>& library, int udcNumber) {
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->udcNumber == udcNumber) {
            library.erase(it);
            break;
        }
    }
}


void readBooksFromFile(vector<Book>& library, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        Book book;
        while (file >> book.udcNumber >> ws && getline(file, book.authorName) && getline(file, book.title) && file >> book.year >> book.copies) {
            library.push_back(book);
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}


void writeBooksToFile(const vector<Book>& library, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& book : library) {
            file << book.udcNumber << endl;
            file << book.authorName << endl;
            file << book.title << endl;
            file << book.year << endl;
            file << book.copies << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}


void displayLibrary(const vector<Book>& library) {
    
    vector<Book> sortedLibrary = library;
    //сортування
    sort(sortedLibrary.begin(), sortedLibrary.end(), [](const Book& a, const Book& b) {
        return a.year < b.year;
        });

    for (const auto& book : sortedLibrary) {
        cout << "UDC number: " << book.udcNumber << endl;
        cout << "Author: " << book.authorName << endl;
        cout << "Title: " << book.title << endl;
        cout << "Year of publication: " << book.year << endl;
        cout << "Copies available: " << book.copies << endl;
        cout << "---------------------------" << endl;
    }
}

int main() {
    vector<Book> library;
    string filename;

    cout << "Enter filename: ";
    cin >> filename;

    readBooksFromFile(library, filename);

    int choice;
    do {
        cout << "1. Add book\n2. Remove book\n3. Display library\n4. Save library to file\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(library);
            break;
        case 2:
            int udc;
            cout << "Enter UDC number of the book to remove: ";
            cin >> udc;
            removeBook(library, udc);
            break;
        case 3:
            displayLibrary(library);
            break;
        case 4:
            writeBooksToFile(library, filename);
            cout << "Library saved to file." << endl;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
