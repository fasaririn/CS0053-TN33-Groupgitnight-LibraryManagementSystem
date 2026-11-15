# Library Management System 
**by Group gitnight** 
**for CS0053 - TN33**

The system is a console-based C++ program for managing book records in a library. Users are able to add, view, search, update, and delete books. The program can save book records in a local file which can be loaded again when it runs. 


## Features 

- Add a book
- View all books  
- Search using ID or Book Title 
- Update information of a book
- Delete a book
- Save and load records from `books.txt`


## Book Record

A book contains the following information:

- **ID** 
- **Title**
- **Author**
- **Publication Year**

Records are stored in `books.txt` in this format:

```text
ID|Title|Author|Year
```


## System requirements 

- G++ or another C++17-compatible compiler
- Git Bash or another terminal


## Compile and Run

Run these commands from the project folder:

```bash
g++ -std=c++17 main.cpp book_features.cpp update_delete.cpp validation.cpp storage.cpp -o library.exe
./library.exe
```


## Project Files
| File | Purpose |
|---|---|
| `main.cpp` | Displays the menu and connects the program features |
| `book.h` | Defines the shared `Book` structure |
| `book_features.cpp` and `book_features.h` | Add, display, and search for books |
| `update_delete.cpp` and `update_delete.h` | Update and delete books |
| `validation.cpp` and `storage_validation.h` | Validate user input and declare storage functions |
| `storage.cpp` | Load and save book records |


## Group Contributions

| Member | Contribution | Branch | Example Commits |
|---|---|---|---|
| **Member 1 — Radoc** | Set up the repository, `.gitignore`, and README; created the menu; added the shared `Book` structure in `book.h`; integrated the team’s features. | `feature/menu`<br>`feature/menu-integration`<br>`feature/book-struct` | `Add main menu`<br>`Add shared book structure`<br>`Connect book actions to menu` |
| **Member 2 — See** | Agreed on the book fields and implemented adding, displaying, and searching for books by title or ID. | `feature/add-search-books` | `Add book record`<br>`Display book list`<br>`Search books by title` |
| **Member 3 — Lovasz** | Implemented file storage and input validation, including loading and saving records and handling invalid input and file errors. | `feature/storage-validation` | `Load books from file`<br>`Save changes to file`<br>`Validate menu and book inputs` |
| **Member 4 — Cruz** | Implemented updating and deleting books, coordinated test cases, and helped gather quality-review evidence. | `feature/update-delete-books` | `Update book details`<br>`Delete book by ID`<br>`Add boundary and invalid-input checks` |


## Group Members 

- Member 1: RADOC (Leader)
- Member 2: SEE
- Member 3: LOVASZ
- Member 4: CRUZ