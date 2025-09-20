# Project 3 - Linked Sequence Data Structure

## Learning Objectives

- Apply object-oriented programming concepts in C++
- Design and implement a data structure for a specified abstract data type
- Use pointers and appropriate memory management methods in C++

## Overview

Many programming languages include "enhanced" array classes that include features of both arrays and linked-lists. The
Java `ArrayList` class and the `vector` class from the C++ standard template library are examples. For this project, you
will construct a `Sequence` class that supports random access like an array, but also allows dynamic insertion and
removal of new elements.

# The `Sequence` Class

Your `Sequence` class should be implemented as a doubly-linked list. Here are a few examples of hor your sequence class
will be used:

```
Sequence mySequence(5); // create a Sequence of length 5 (indexes 0 thorugh 4)
mySequence[0] = 1;
mySequence[1] = 2;
mySequence[4] = 3;
```

After executing this code block, your `Sequence` would appear as follows:

| Index   | 0 | 1 | 2   | 3   | 4 |
|---------|---|---|-----|-----|---|
| Content | 1 | 2 | ??? | ??? | 3 |

_Note: `Sequence` locations with a content of `???` can contain any value, mimicing uninitalized memory_

The `push_back()` member function grows the `Sequence` by adding values to the end. The call `mySequence.push_back(20)`
produces:

| Index   | 0 | 1 | 2   | 3   | 4 | 5  |
|---------|---|---|-----|-----|---|----|
| Content | 1 | 2 | ??? | ??? | 3 | 20 |

We can also grow the `Sequence` using the `insert(index, data)` member function. The first argument to `insert()` is the
index (position) at which to insert the new data. The second argument is the data to insert. The data is inserted at the
designated position, and the remaining items in the sequence are shifted to the right. Starting with the previous
`Sequence`, `mySequence.insert(1, 30)` would produce:

| Index   | 0 | 1  | 2 | 3   | 4   | 5 | 6  |
|---------|---|----|---|-----|-----|---|----|
| Content | 1 | 30 | 2 | ??? | ??? | 3 | 20 |

We can reduce the size of the `Sequence` using `pop_back()`, which removes the last element of the sequence, or
`erase(index, count)`. The call `mySequence.erase(3, 2)` removes 2 itesm starting at position 3. Calling
`mySequence.pop_back()` and  `mySequence.erase(3, 2)` produces:

| Index   | 0 | 1  | 2 | 3   | 4 | 
|---------|---|----|---|-----|---|
| Content | 1 | 30 | 2 | ??? | 3 | 

## Required Member Functions

You will be provided a starting template for your sequence, implemented in the files `Sequence.h` and `Sequence.cpp`.
You must implement each of the functions defined in these files. A full desciption of each method is given in the header
file (`Sequence.h`).

## Error Handling

You solution should throw an exception if a user attempts to access an item outside the bounds of the sequence in **any
** member function. For example, each of the following calls after the sequence of length three is created should throw
an exception:

```
Sequence mySequence(3);             // mySequence has elements 0 through 2
mySequence[3] = 100;                // Error: there is no elemnt 3
cout << mySequence[-1] << endl;     // Another Error
mySequence.erase(2, 5);             // Error: Tries to erase non-existent elements
```

You can throw a C++ exception using the following syntax:

```
#include <exception>

int& Sequence::operator[](size_t position) {
    if ( index position is invalid ) {
        throw exception();
    }
    ...
}
```

## The Test Harness

For this project (but not necessarily others), you will be provided with the entire test harness that I will use to test
your code. The number of points allocated for each test is given in the grading rubric at the end of this assignment.

## Documentation and Style

CS 3100 is the capstone programming course of your academic career. You should employ professional best practices in
your coding and documentation. You can view all the requirements for coding standards in Pilot under Content |
Projects | CS 3100 Coding Standards. Among others, these practices include:

- **Descriptive variable names** - avoid variable names like `p` and `temp`. Use name that describe the purpose of the
  variable. Use either under_scores or camelCase for multiple-word names. Examples of appropriate variables names
  include: `currentNode`, `toBeDeleted`, and `studentList`. _Exception: It is generally acceptable to use single-letter
  variables, such as `i`, as loop indexes in `for` loops.
- **Method header comments** - At a minimum should include the name of the function, its purpose, a list of input
  parameters, return values, and any side effects. In CLion, if you type `/**` and then press `Enter` above a method, a
  template is generated for you that has the parameters and return labeled for you, you just need to fill it in.
- **Whitespace and inline comments** - Code should be broken into blocks of roughly 5 to 20 lines of code, separated by
  whitespace, and annotated with inline comments. Any particularly hard to understand lines of code should have an
  explanatory inline comment.

## Turn in and Grading

Your `Sequence` class should be implemented as a separate header (`Sequence.h`) and source (`Sequence.cpp`) file.

If you define other classes, (such as `SequenceNode`), you may use a separate class, as well as a separate file if
desired. Or, you could define a class entirely within class `Sequence`.

Make regular commits to your GitHub Classroom repository. You can also push as you work. Whatever the most recent commit
to the repository that appears in the remote branch, so you will need to push your commits.

Code that will not compile will receive a grade of zero. If you have code that does not compile, you can comment out
what doesn't work, and put a comment stating the code you commented does not compile. You can still get partial credit
for code that doesn't compile as long as the program you submit does compile.

This project is worth 50 points, distributed as follows:

| Test                                                                                                                              | 	Points  |
|:----------------------------------------------------------------------------------------------------------------------------------|:---------|
| Can correctly create a Sequence, modify items with the [] operator, and print the contents of the sequence with the << operator	  | 5        |
| Can create multiple, independent Sequence objects and print them	                                                                 | 3        |
| push_back() correctly adds to the end of an existing Sequence	                                                                    | 3        |
| push_back() can add elements to an empty Sequence	                                                                                | 3        |
| pop_back() correctly removes the last element of a Sequence	                                                                      | 3        |
| pop_back() on an empty Sequence throws an exception	                                                                              | 1        |
| insert() correctly adds an element in the correct position of an existing Sequence	                                               | 3        |
| insert() throws an exception when called with an invalid index	                                                                   | 1        |
| front() correctly returns the first element of a Sequence	                                                                        | 2        |
| front() throws an exception when called on an empty Sequence	                                                                     | 1        |
| back() correctly returns the last element of a Sequence	                                                                          | 2        |
| back() throws an exception when called on an empty Sequence	                                                                      | 1        |                                                                   
| empty() returns 1 if the Sequence is empty, 0 otherwise	                                                                          | 1        |                                                                       
| size() correctly returns the size of a Sequence	                                                                                  | 1        |                                                                               
| clear() correctly removes all elements of a Sequence	                                                                             | 2        |                                                                          
| erase() correctly removes specified elements of a Sequence	                                                                       | 3        |                                                                 
| erase() throws an exception when called with invalid parameters	                                                                  | 1        |                                                            
| The assignment operator (=) correctly produces an independent copy of a Sequence	                                                 | 3        |                                              
| The copy constructor correctly produces an independent copy of a Sequence	                                                        | 3        |                                                     
| Code has no memory leaks	                                                                                                         | 3        |                                                                                                  
| Your code is well organized, clearly written, and well-documented	                                                                | 5        |                                                        
| Total	| 50       |                                                                                                                          
