# C Program for Student Marks Management

This project represents my first dive into C programming, where I created a basic student marks management system. The program allows a user to manage marks for three coursework assignments across multiple students. It also includes supervisor features such as correcting marks and managing student records. Below, I'll go through the key features of the program, providing an overview of its functionality.

### Key Features and Structure

1. **Main Program Flow**
    - The main program begins by calling `numOfStudents()` to determine how many students will be managed.
    - It then asks the user to input names for the students and stores them in the `students` array.
    - The program operates in a loop where it displays a menu, allowing the user to:
        - Enter marks for coursework.
        - Display students' marks.
        - Access supervisor mode for advanced features.
        - Exit the program.
2. **Menu System (`printMenu()` and `enterMarks()`)**
    - The menu is displayed using the `printMenu()` function, which offers different options to enter marks, view them, or access the supervisor mode.
    - `enterMarks()` allows the user to enter marks for any of the three coursework assignments. Depending on the option chosen, it will call functions such as `coursework1mark()`, `coursework2mark()`, and `coursework3mark()` to handle the data entry for each assignment.
3. **Supervisor Mode**
    - The program includes a supervisor mode protected by a PIN (`supervisor()` function).
    - In supervisor mode, a user can:
        - Change the supervisor PIN.
        - Correct a student's marks.
        - Add new students.
        - Edit a student's name.
    - The user is given three attempts to enter the correct PIN before being locked out.
4. **Marks Entry and Correction**
    - The program ensures that marks entered are valid (between 0 and 100). If an invalid input is provided, the user is prompted to enter a correct value.
    - Once marks are entered for a particular coursework, the user can optionally correct individual students' marks using the `correctionsC1()`, `correctionsC2()`, and `correctionsC3()` functions for coursework 1, 2, and 3, respectively.
5. **Displaying Marks (`displaymarks()`)**
    - The `displaymarks()` function allows the user to select a student and view their marks for each coursework, along with the overall grade calculated as an average of the three coursework marks.
6. **Adding New Students**
    - In supervisor mode, additional students can be added dynamically using the feature embedded in `supervisor()`. The program asks how many new students should be added and allows input of their names.
7. **Buffer Management (`emptyBuffer()` and `space()` functions)**
    - `emptyBuffer()` clears the input buffer to handle newline characters and prevent unwanted behavior from previous inputs.
    - `space()` is a helper function used to create visual spacing in the output, improving readability.

### Example Walkthrough

- **Initial Setup**: The user first defines the number of students and enters their names.
- **Entering Marks**: After selecting the option to enter marks, the user chooses which coursework to input marks for. The program then validates each entry to ensure the marks are within the valid range.
- **Supervisor Mode**: By entering the correct PIN, the supervisor can correct marks, add students, or change a student's name.

This project helped me solidify basic programming concepts such as arrays, input/output handling, loops, and function modularity in C.
