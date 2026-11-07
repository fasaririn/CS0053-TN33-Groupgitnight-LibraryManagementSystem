#ifndef BOOK_FEATURES_H
#define BOOK_FEATURES_H

#include "storage_validation.h"
#include <vector>

// Member 2: add, view, and search book features.
void addBook(std::vector<Book>& books);
void displayBooks(const std::vector<Book>& books);
void searchBooks(const std::vector<Book>& books);

#endif // BOOK_FEATURES_H
