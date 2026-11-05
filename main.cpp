#include <iostream>

using namespace std;

int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Books\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // TODO: Call the function to add a book.
                break;
            case 2:
                // TODO: Call the function to view books.
                break;
            case 3:
                // TODO: Call the function to search for a book.
                break;
            case 4:
                // TODO: Call the function to update a book.
                break;
            case 5:
                // TODO: Call the function to delete a book.
                break;
            case 6:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}