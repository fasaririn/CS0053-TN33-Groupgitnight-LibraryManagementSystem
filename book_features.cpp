#include "book_features.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

namespace {
constexpr const char* DataFile = "books.txt";

std::string toLower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(),
                   [](unsigned char character) {
                       return static_cast<char>(std::tolower(character));
                   });
    return value;
}

void displayBook(const Book& book) {
    std::cout << "ID: " << book.id
              << " | Title: " << book.title
              << " | Author: " << book.author
              << " | Year: " << book.year << '\n';
}
} // namespace

void addBook(std::vector<Book>& books) {
    Book book{};
    book.id = readNewId(books);
    book.title = readRequiredString("Enter title: ");
    book.author = readRequiredString("Enter author: ");
    book.year = readInt("Enter publication year: ", 0, 2100);

    books.push_back(book);

    if (saveBooks(DataFile, books)) {
        std::cout << "Book added and saved successfully.\n";
    } else {
        std::cout << "Book added, but saving failed.\n";
    }
}

void displayBooks(const std::vector<Book>& books) {
    if (books.empty()) {
        std::cout << "No books found.\n";
        return;
    }

    for (const Book& book : books) {
        displayBook(book);
    }
}

void searchBooks(const std::vector<Book>& books) {
    const std::string query = toLower(
        readRequiredString("Enter book ID or title to search: "));

    bool found = false;
    for (const Book& book : books) {
        const std::string id = std::to_string(book.id);
        const std::string title = toLower(book.title);

        if (id == query || title.find(query) != std::string::npos) {
            displayBook(book);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching books found.\n";
    }
}
