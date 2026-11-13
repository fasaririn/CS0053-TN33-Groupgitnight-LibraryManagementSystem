#include "storage_validation.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

// Reads a whole line and accepts it only if it is a whole number in range
// Rejects letters, empty input and out of range values
int readInt(const string& prompt, int minVal, int maxVal) {
    string line;
    while (true) {
        cout << prompt;
        if (!getline(cin, line)) {
            cout << "\nInput closed. Exiting.\n";
            exit(0);
        }
        line = trim(line);

        int value = 0;
        bool parsed = false;
        try {
            size_t pos = 0;
            value = stoi(line, &pos);
            parsed = (pos == line.size());
        } catch (const exception&) {
            parsed = false;
        }

        if (!parsed) {
            cout << "Invalid input. Please enter a whole number.\n";
            continue;
        }
        if (value >= minVal && value <= maxVal) return value;
        cout << "Please enter a number between " << minVal << " and " << maxVal << ".\n";
    }
}

int readMenuChoice() {
    return readInt("Enter your choice: ", 1, 6);
}

// Required text: Dont leave empty
string readRequiredString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        if (!getline(cin, input)) {
            cout << "\nInput closed. Exiting.\n";
            exit(0);
        }
        input = trim(input);
        if (input.empty()) {
            cout << "This field is required.\n";
        } else if (input.find('|') != string::npos) {
            cout << "The '|' character is not allowed.\n";
        } else {
            return input;
        }
    }
}

bool idExists(const vector<Book>& books, int id) {
    return any_of(books.begin(), books.end(),
                  [id](const Book& b) { return b.id == id; });
}

// For adding: ID must be positive and not already used
int readNewId(const vector<Book>& books) {
    while (true) {
        int id = readInt("Enter book ID: ", 1, 999999);
        if (!idExists(books, id)) return id;
        cout << "That ID already exists. Choose another.\n";
    }
}

// For update/delete/search: ID must already exist
int readExistingId(const vector<Book>& books) {
    while (true) {
        int id = readInt("Enter book ID: ", 1, 999999);
        if (idExists(books, id)) return id;
        cout << "No book with that ID.\n";
    }
}