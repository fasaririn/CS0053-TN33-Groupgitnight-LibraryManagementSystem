#include "update_delete.h"

#include "storage_validation.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

namespace {
constexpr const char* DataFile = "books.txt";

void displayBook(const Book& book) {
    std::cout << "ID: " << book.id
              << " | Title: " << book.title
              << " | Author: " << book.author
              << " | Year: " << book.year << '\n';
}
}  // namespace

void updateBook(std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books available to update.\n";
        return;
    }

    const int id = readExistingId(books);

    auto bookIt = std::find_if(
        books.begin(), books.end(),
        [id](const Book& book) {
            return book.id == id;
        });

    if (bookIt == books.end()) {
        std::cout << "Book not found.\n";
        return;
    }

    std::cout << "Current book details:\n";
    displayBook(*bookIt);

    bookIt->title = readRequiredString("Enter new title: ");
    bookIt->author = readRequiredString("Enter new author: ");
    bookIt->year = readInt("Enter new publication year: ", 0, 2100);

    if (saveBooks(DataFile, books)) {
        std::cout << "Book updated and saved successfully.\n";
    } else {
        std::cout << "Book updated, but saving failed.\n";
    }
}

void deleteBook(std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books available to delete.\n";
        return;
    }

    const int id = readExistingId(books);

    auto bookIt = std::find_if(
        books.begin(), books.end(),
        [id](const Book& book) {
            return book.id == id;
        });

    if (bookIt == books.end()) {
        std::cout << "Book not found.\n";
        return;
    }

    std::cout << "Book selected for deletion:\n";
    displayBook(*bookIt);

    std::string confirmation;

    do {
        confirmation =
            readRequiredString("Delete this book? Enter Y or N: ");

        if (confirmation.size() != 1 ||
            (confirmation[0] != 'Y' && confirmation[0] != 'y' &&
             confirmation[0] != 'N' && confirmation[0] != 'n')) {
            std::cout << "Invalid choice. Please enter Y or N.\n";
        }
    } while (confirmation.size() != 1 ||
             (confirmation[0] != 'Y' && confirmation[0] != 'y' &&
              confirmation[0] != 'N' && confirmation[0] != 'n'));

    if (confirmation[0] == 'N' || confirmation[0] == 'n') {
        std::cout << "Deletion cancelled.\n";
        return;
    }

    books.erase(bookIt);

    if (saveBooks(DataFile, books)) {
        std::cout << "Book deleted and changes saved successfully.\n";
    } else {
        std::cout << "Book deleted, but saving failed.\n";
    }
}