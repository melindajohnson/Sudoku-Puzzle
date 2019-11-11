/**
 Puzzle.cpp
 Program3
 Created by Melinda Stannah Stanley Jothiraj on 11/13/19.
 Student number- 1978413
 */
//#include <cctype>
#include "Puzzle.h"
#include <cstring>
#include <iostream>

Puzzle::Square::Square() {
  value = 0;
  flag = false;
}

Puzzle::Square::~Square() {}

int Puzzle::Square::getValue() const { return value; }

void Puzzle::Square::setValue(const int &newValue) { value = newValue; }

bool Puzzle::Square::getFlag() const { return flag; }

void Puzzle::Square::setFlag(
    const bool &newFlag) // true if value is fixed; false if value is variable;
{
  flag = newFlag;
}

int Puzzle::get(int x, int y) const // Returns the value at the location (x,y)
{

  return Sudoku[x][y].getValue();
}

int Puzzle::size() // Returns the number of variable entries in the puzzle.
{
  return validValueCount;
}
int Puzzle::numEmpty() // Returns the current number of empty squares (those
                       // without any value).
{
  return numberEmpty;
}

Puzzle::Puzzle() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      Sudoku[i][j].setValue(0);
      Sudoku[i][j].setFlag(false);
    }
  }
}
bool Puzzle::set(const int x, const int y, const int value) {
  bool checksPassed = true;

  if (value == 0) {
    Sudoku[x][y].setValue(value);
    numberEmpty++;
    Sudoku[x][y].setFlag(false);
    return true;
  } else {
    // If any one of the methods return true, then the value cannot be set and
    // checksPassed is set to false
    if (checkRow(x, value) || checkColumn(y, value) ||
        checkBlock(x, y, value)) {
      checksPassed = false;
      return false;
    }
  }
  // If all  checks are passed, then the value is set to its corresponding
  // square
  if (checksPassed) {
    Sudoku[x][y].setValue(value);
    validValueCount++;
    Sudoku[x][y].setFlag(true);
    return true;
  }
  return false;
}

std::istream &operator>>(std::istream &in, Puzzle &p) {
  int count = 0;
  bool validInput = false;
  for (int i = 0; i < p.row; i++) {
    for (int j = 0; j < p.column; j++) {
      char input;
      while (!validInput && count <= 81) {
        in.get(input);
        if (isdigit(input)) {
          if (p.set(i, j, input - '0')) {
            count++;
            validInput = true;
          } else {
            in.clear();
            std::cout << "\nError in input\nSudoku rules broken!! ";
            return in;
          }
        } else if (input == '\n') {
          in.clear();
          std::cout
              << "\nError in input\nWhite space should not seperate inputs!! ";
          return in;
        }
      }
      validInput = false;
    }
  }
  validInput = true;
  if (p.size() == 81) {
    std::cout << "\nPuzzle is already solved";
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const Puzzle &p) {
  out << "\n";
  for (int i = 0; i < p.row; i++) {
    if (i == 3 || i == 6) {
      out << "-----+-----+-----\n";
    }
    for (int j = 0; j < p.column; j++) {
      if (j == 0) {
        out << p.get(i, j);
      } else if (j == 3 || j == 6) {
        out << "|" << p.get(i, j);
      } else {
        out << " " << p.get(i, j);
      }
    }
    out << "\n";
  }
  out << "\n";
  return out;
}

bool Puzzle::checkRow(const int x, const int value)
    const // return true if the same value is found in the same row
{
  for (int i = 0; i < column; i++) {
    if (get(x,i) == value) {
      return true;
    }
  }
  return false;
}

bool Puzzle::checkColumn(const int y, const int value)
    const // return true if the same value is found in the same column
{
  for (int i = 0; i < row; i++) {
    if (get(i,y) == value) {
      return true;
    }
  }
  return false;
}

bool Puzzle::checkBlock(const int x, const int y, const int value)
    const // return true if the same value is found in the same block
{
  int blockStartIndexX = x / 3 * 3;
  int blockStartIndexY = y / 3 * 3;
  int blockEndIndexX = blockStartIndexX + 2;
  int blockEndIndexY = blockStartIndexY + 2;
  for (int i = blockStartIndexX; i < blockEndIndexX; i++) {
    for (int j = blockStartIndexY; j < blockEndIndexY; j++) {
      if (Sudoku[i][j].getValue() == value) {
        return true;
      }
    }
  }
  return false;
}

bool Puzzle::solver(int x, int y) {
   bool foundEmptySpot = false;
   if(x == 9) return true; // Base case
   int emptyX = -1;
   int emptyY = -1;
      for (int i = x; i < row; i++) {
         for (int j = y; j < column ; j++) {
            if(get(i,j) == 0){
             foundEmptySpot = true;
               emptyY = j;
               break;
            }
         }
         if(emptyY != -1){
            emptyX = i ;
             break;
         }
      }
    if(foundEmptySpot){
    for (int k = 1; k <= 9; k++){
       if(set(emptyX, emptyY, k)){
             int nextX = 0;
             int nextY = 0;
           if(emptyX < 8){
              nextY = emptyY + 1;
             }
           else if(emptyY == 8){
              nextX = emptyX + 1;
              nextY = 0;
           }
           if(solver(nextX, nextY)){
              return true;
             }
          
        }
    }
             set(emptyX, emptyY, 0);
             return false;
             
     }
  return true;
}

Puzzle::~Puzzle() {}
