/**
 Puzzle.h
 Program3
 Created by Melinda Stannah Stanley Jothiraj on 11/13/19.
 Student number- 1978413
 */
#ifndef Puzzle_hpp
#define Puzzle_hpp
#include <iostream>
#include <stdio.h>
using namespace std;
class Puzzle
{
public:
   
   class Square;        // forward declaration
   //friend class Square; // friend declaration
   
   /*!
    @class Square
    This is a nested class. Note that it is in the public section of Puzzle class
    */
   class Square
   {
   private:
      int value; //number associated with one location in the puzzle
      bool flag;  //indicating if the value is fixed (one of the values given at the start of the puzzle)
                  //or variable (the values written in as parts of a possible solution).
   public:
      Square();
         // Square(const Square& aSquare); // Copy constructor
      virtual ~Square();  // Destructor
      int getValue() const ; //Returns the current value (-1 if no value set).
      void setValue(const int& newValue); // Takes a single integer argument; sets the value to the given argument.
      bool getFlag() const ;
      void setFlag(const bool& newFlag);
   };
   
   Puzzle();
   virtual ~Puzzle(); // destructor
   int get(int x, int y) const ; //Returns the value at the location (x,y)
   int size();//Returns the number of variable entries in the puzzle.
   int numEmpty(); //Returns the current number of empty squares (those without any value).
   bool set(const int x,const int y,const int val); //set the value at its corresponding square location
   //It will succeed if the value proposed is legal for that square and will set the value(i.e., does not duplicate a value in the same row, column, or block).
   bool Solver(int x, int y); //Recursive method that uses backtracking to solve the puzzle
   friend std::istream & operator >> (std::istream &in,  Puzzle &p);
   friend std::ostream & operator << (std::ostream &out, const Puzzle &p);
   
   
private:
   
   int numberEmpty;
   int validValueCount;
   static const unsigned row = 9;
   static const unsigned column = 9;
   Square Sudoku[row][column];
   bool checkRow(const int x,const int value) const; // Checks if the same value is found in the row x
   bool checkColumn(const int y,const int value) const; // Checks if the same value is found in the column y
   bool checkBlock(const int x,const int y,const int value) const; //Checks if the same value is found in the 3 by 3 block
   
};
#endif /* Puzzle_hpp */
