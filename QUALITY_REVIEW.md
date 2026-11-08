# Quality Review and Testing Plan

## Assigned Contributor

- Member: Danny Rey Cruz
- Branch: feature/update-delete-books
- Main tasks: update books, delete books, testing, and quality review

## Planned Update Tests

| Test case | Expected result | Actual result | Status |
|---|---|---|---|
| Update an existing book ID | The selected book details are changed | To be recorded | Not yet tested |
| Update a nonexistent book ID | The program displays a not-found message | To be recorded | Not yet tested |
| Update with an empty title | The program rejects the empty input | To be recorded | Not yet tested |
| Update with an invalid year | The program displays an input error | To be recorded | Not yet tested |

## Planned Delete Tests

| Test case | Expected result | Actual result | Status |
|---|---|---|---|
| Delete an existing book ID | The selected book is removed | To be recorded | Not yet tested |
| Delete a nonexistent book ID | The program displays a not-found message | To be recorded | Not yet tested |
| Cancel a deletion | The selected book remains in the records | To be recorded | Not yet tested |
| Delete when no books exist | The program handles the situation safely | To be recorded | Not yet tested |

## Quality Evidence to Collect

- Formatter before-and-after evidence
- Static-analysis output
- Debugger breakpoint and variable values
- Test-case screenshots or terminal output
- Pull-request review comments
- Final update and delete demonstration

## Current Status

The update and delete functions are waiting for the shared `Book` structure and integrated project files. The test results will be completed after the feature branches are merged and the program can compile.