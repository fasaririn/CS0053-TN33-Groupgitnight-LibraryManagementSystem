#pragma once
#include <string>
#include <vector>
#include "book.h"

// Validation
std::string trim(const std::string& s);
int readInt(const std::string& prompt, int minVal, int maxVal);
int readMenuChoice();
std::string readRequiredString(const std::string& prompt);
bool idExists(const std::vector<Book>& books, int id);
int readNewId(const std::vector<Book>& books);
int readExistingId(const std::vector<Book>& books);

// Storage
enum class LoadResult { Ok, FileMissing, Unreadable, SomeLinesSkipped };

LoadResult loadBooks(const std::string& filename, std::vector<Book>& books);
bool saveBooks(const std::string& filename, const std::vector<Book>& books);