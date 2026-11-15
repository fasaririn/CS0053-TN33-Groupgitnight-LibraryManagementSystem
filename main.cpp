#include <iostream>
#include <vector>


#include "book.h"
#include "book_features.h"
#include "storage_validation.h"
#include "update_delete.h"

using namespace std;

int main() {
    vector<Book> books;
    const string filename = "books.txt";

    LoadResult loadResult = loadBooks(filename, books);

     switch (loadResult) {
        case LoadResult::Ok:
            cout << "Book records loaded.\n";
            break;

        case LoadResult::FileMissing:
            cout << "No saved books found. Starting with an empty list.\n";
            break;

        case LoadResult::Unreadable:
            cerr << "Could not read the books file.\n";
            return 1;

        case LoadResult::SomeLinesSkipped:
            cout << "Some invalid records were skipped. Valid records were loaded.\n";
            break;
    }

    int choice = 0;

    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Books\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";

        choice = readMenuChoice();

        switch (choice) {
            case 1:
                addBook(books);
                break;
            case 2:
                displayBooks(books);
                break;
            case 3:
                searchBooks(books);
                break;
            case 4:
                updateBook(books);
                break;
            case 5:
                deleteBook(books);
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
        }
    } while (choice != 6);

    return 0;
}