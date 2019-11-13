/**
 main.cpp
 Program3
 Created by Melinda Stannah Stanley Jothiraj on 11/13/19.
 Student number- 1978413
 
 In this problem we design and implement a set of classes to represent Sudoku puzzles. The classes would be used to implement a basic backtracking solver. Sudoku is a type of logic-based puzzle. The puzzle has a 9-by-9 arrangement of squares, subdivided into 3-by-3 blocks. Some of these squares are filled in with numbers from 1 through 9. To solve the puzzle, the blank squares must be filled with numbers from 1 through 9 so that no row, column, or 3-by-3 block in the puzzle has the same number twice.
 
 The problem consists of two classes,
 A Square class which holds all of the information associated with one location in the puzzle. This includes the square's numerical value and a flag  indicating if the value is fixed (if a value is given at the start of the puzzle) or variable (the values written in as parts of a possible solution).
 The Puzzle class which holds the representation of a puzzle. It does this by holding Square objects.
 
 A Puzzle object must read a Sudoku puzzle from cin.
 The Square objects are filled with value from 0 – 9 where 0 represents an empty location where a new value must be set when solving the Puzzle.
 It should then display the original puzzle.
 A backtracking algorithm must be used to solve the puzzle, using the puzzle's get and set methods.
 It should then display the solved puzzle or, if it couldn't be solved, output a message to indicate so.
 
 
 Input Data
 ----------------
 The input consists of a sequence of 81 numerical digits which correspond to the value in a Square object.
 ●   Blank squares in the Puzzle are represented with zeros.
 ●   All non-digit characters are ignored, and the next character is checked.
 ●   White spaces should not separate the input
 An example of the input data consisting of 81 numbers
 423751968759683124168249357945362871872915436316478295537194682691827543284536019
 
 Output Data
 ----------------
 The output must be displayed in the following format
 1. 11 lines of text, with each line containing the numbers in a row of the puzzle separated by single spaces.
 2. Use the '|', '+', and '-' characters to separate 3-by-3 blocks
 3. So each line of output would be 19 printing characters long:
 9 digits, 8 spaces, and 2 '|' for "non-divider" lines and 17 '-' and 2 '+' for "divider" lines).
 
 An example output would look like:
 4 2 3|7 5 1|9 6 8  
 7 5 9|6 8 3|1 2 4  
 1 6 8|2 4 9|3 5 7  
 ------+-----+------ 
 9 4 5|3 6 2|8 7 1  
 8 7 2|9 1 5|4 3 6  
 3 1 6|4 7 8|2 9 5  
 ------+-----+------ 
 5 3 7|1 9 4|6 8 2  
 6 9 1|8 2 7|5 4 3  
 2 8 4|5 3 6|7 1 9
 
 Assumptions
 ----------------
 •   The input consists of a sequence of 81 numerical digits
 •   All non-digit characters are ignored, and the next character is checked.
 •   White spaces are not found in the input data
 •   A valid input would have only one valid solution
 
 Error Handling
 -------------------
 •   The program must handle errors if the input data is invalid.
 •   The program must verify that input data is valid, i.e. exactly 81 digits in the range 0-9
 •   The program must verify that the values are set at the right position in the Square objects
 •   The solved puzzle should contain the valid values without any zero i.e. no unsolved square
 •   The program must display the solution as a human-friendly display of the Sudoku puzzle without changing the values that were obtained after solving the puzzle.
 
 **/

#include <iostream>
#include "Puzzle.h"

using namespace std;

int main(int argc, const char * argv[]) {
   
   Puzzle p1;
  // cout << "Enter input";
   if(cin >> p1){
      cout << "\ninput problem\n";
      cout << p1;
      if(p1.solver(0,0)){
           cout << "output solution\n";
         cout << p1;
      }
      else{
         cout << "Sudoku cannot be solved";
      }
   }
   
   
   
}



