#include "storage_validation.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>

using namespace std;

// One record per line: id|title|author|year
LoadResult loadBooks(const string& filename, vector<Book>& books) {
    books.clear();

    error_code ec;
    if (!filesystem::exists(filename, ec)) {
        return LoadResult::FileMissing;           
    }

    ifstream in(filename);
    if (!in) {
        return LoadResult::Unreadable;            
    }

    set<int> seenIds;
    string line;
    int lineNo = 0, skipped = 0;

    while (getline(in, line)) {
        lineNo++;
        if (trim(line).empty()) continue;         
        stringstream ss(line);
        string idStr, title, author, yearStr;

        bool ok = getline(ss, idStr, '|') && getline(ss, title, '|') &&
                  getline(ss, author, '|') && getline(ss, yearStr);

        if (ok) {
            try {
                size_t p1 = 0, p2 = 0;
                int id = stoi(idStr, &p1);
                int year = stoi(yearStr, &p2);
                ok = p1 == idStr.size() && p2 == yearStr.size() &&  
                     id > 0 && !trim(title).empty() && !trim(author).empty() &&
                     !seenIds.count(id);                            
                if (ok) {
                    seenIds.insert(id);
                    books.push_back({id, title, author, year});
                }
            } catch (const exception&) {
                ok = false;                      
            }
        }

        if (!ok) {
            skipped++;
            cerr << "Warning: skipped invalid record on line " << lineNo << ".\n";
        }
    }

    if (in.bad()) return LoadResult::Unreadable;  
    return skipped > 0 ? LoadResult::SomeLinesSkipped : LoadResult::Ok;
}

// Writes to a temp file first so a failed save can't destroy any existing data
bool saveBooks(const string& filename, const vector<Book>& books) {
    string tempName = filename + ".tmp";

    {
        ofstream out(tempName);
        if (!out) return false;

        for (const Book& b : books) {
            out << b.id << '|' << b.title << '|' << b.author << '|' << b.year << '\n';
        }
        out.flush();
        if (!out) return false;                  
    }

    error_code ec;
    filesystem::rename(tempName, filename, ec);
    if (ec) {
        filesystem::remove(tempName, ec);
        return false;
    }
    return true;
}