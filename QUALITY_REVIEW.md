# Quality Review and Testing Plan

## Assigned Contributor

- Member: Danny Rey Cruz
- Branch: feature/update-delete-testing
- Main tasks: update books, delete books, testing, and quality review

## Completed Update Tests

| Test case | Expected result | Actual result | Status |
|---|---|---|---|
| Update an existing book ID | The selected book details are changed | Book ID 1 was updated from “Harry Potter” to “Harry Potter Updated” and the year changed from 2001 to 2002. The updated record appeared when viewing books. | Passed |

## Completed Delete Tests

| Test case | Expected result | Actual result | Status |
|---|---|---|---|
| Delete an existing book ID | The selected book is removed | Book ID 1 was deleted after confirmation. Viewing the books afterward displayed “No books found.” | Passed |

## Additional Functional Tests

| Test case | Expected result | Actual result | Status |
|---|---|---|---|
| Add a book | The book is saved successfully | Book ID 1, Harry Potter, was added successfully. | Passed |
| View books | Saved books are displayed | The saved book details were displayed correctly. | Passed |
| Search by title | Matching books are displayed | Searching for “Harry” displayed the correct book. | Passed |
| Save and reload records | Records remain after restarting the program | Book ID 2, Dune, was saved. After restarting, the program displayed “Book records loaded” and showed the saved record. | Passed |
| Invalid menu number | The program rejects numbers outside the valid range | Entering 9 displayed “Please enter a number between 1 and 6.” | Passed |
| Non-numeric menu input | The program displays an input error and continues running | Entering “abc” displayed “Invalid input. Please enter a whole number.” | Passed |

## Tests Still To Be Completed

- Update a nonexistent book ID
- Update with an empty title
- Update with an invalid year
- Delete a nonexistent book ID
- Cancel a deletion
- Delete when no books exist

## Quality Evidence to Collect

- Formatter before-and-after evidence
- Static-analysis output
- Debugger breakpoint and variable values
- Test-case screenshots or terminal output
- Pull-request review comments
- Final update and delete demonstration

## Current Status

The shared `Book` structure and integrated project files are now available in the `feature/update-delete-testing` branch. The program compiled successfully using MinGW g++ and the completed functional tests passed. Additional edge-case tests and quality evidence still need to be documented.