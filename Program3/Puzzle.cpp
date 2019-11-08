/**
 Puzzle.cpp
 Program3
 Created by Melinda Stannah Stanley Jothiraj on 11/13/19.
 Student number- 1978413
 */
//#include <cctype>
#include <iostream>
#include <cstring>
#include "Puzzle.h"


Puzzle::Square::Square()
{
   value = 0;
   flag = false;
}

Puzzle::Square::~Square()
{
   
}

int Puzzle::Square::getValue() const
{
   return value;
}

void Puzzle::Square::setValue(const int& newValue)
{
   value = newValue;
}

bool Puzzle::Square::getFlag() const
{
   return flag;
}

void Puzzle::Square::setFlag(const bool& newFlag) // true if value is fixed; false if value is variable;
{
   flag = newFlag;
}

int Puzzle::get(int x, int y) const  //Returns the value at the location (x,y)
{
   
   return 1;
}

int Puzzle::size()//Returns the number of variable entries in the puzzle.
{
   return validValueCount;
}
int Puzzle::numEmpty()//Returns the current number of empty squares (those without any value).
{
   return numberEmpty ;
}

Puzzle::Puzzle(){
   for(int i = 0; i< row; i++){
      for(int j=0; j<column; j++){
         Sudoku[i][j].setValue(0);
         Sudoku[i][j].setFlag(false);
      }
   }
}
bool Puzzle::set(const int x,const int y,const int value)
{
   bool checksPassed = true;
   
   if(value==0){
      Sudoku[x][y].setValue(value);
      numberEmpty++;
      Sudoku[x][y].setFlag(false);
      return true;
   }
   else
   {
         //If any one of the methods return true, then the value cannot be set and checksPassed is set to false
      if(checkRow(x, value) || checkColumn(y, value) || checkBlock(x, y, value)){
         checksPassed = false;
         return false;
      }
   }
      //If all  checks are passed, then the value is set to its corresponding square
   if(checksPassed)
   {
      Sudoku[x][y].setValue(value);
      validValueCount++;
      Sudoku[x][y].setFlag(true);
      return true;
   }
   return false;
}



std::istream& operator>>(std::istream &in,  Puzzle &p)
{
   int count= 0;
   bool validInput = false;
      for(int i = 0; i< Puzzle::row; i++){
         for(int j=0; j<Puzzle::column; j++){
            char input;
             while(!validInput && count<=81){
               in.get(input);
               if(isdigit(input)){
                  if(p.set(i,j,input-'0')){
                  count++;
                  validInput=true;
                  }
                  else
                  {
                     in.clear();
                     std::cout<<"\nError in input\nSudoku rules broken!! ";
                     return in;
                  }
               }else if(input =='\n'){
                  in.clear();
                  std::cout<<"\nError in input\nWhite space should not seperate inputs!! ";
                  return in;
               }
            }
            validInput=false;
         }
      }
   validInput=true;
   return in;
}





   //std::ostream& operator<<(std::ostream &out, const Puzzle &p)
   //{
   //   For(starting row index 0 to ending row index 8){
   //      If(row index == 3 || row index == 6){
   //         Ostream <<”------+-----+------“
   //      }
   //      For(starting column index 0 to ending column index 8){
   //         if(column index == 0){
   //            Ostream << p.get(row index, column index)
   //         }else If(column index == 3 || column index == 6){
   //            Ostream << “|”<<p.get(row index, column index)
   //         }else{
   //            Ostream <<” “<<p.get( row index, column index)
   //         }
   //      }
   //
   //}

bool Puzzle::checkRow(const int x,const int value) const // return true if the same value is found in the same row
{
   for(int i=0; i<column; i++)
   {
      if(Sudoku[x][i].getValue()==value){
         return true;
      }
   }
   return false;
}

bool Puzzle::checkColumn(const int y, const int value) const // return true if the same value is found in the same column
{
   for(int i=0; i<row; i++)
   {
      if(Sudoku[1][y].getValue()==value){
         return true;
      }
   }
   return false;
}

bool Puzzle::checkBlock(const int x,const int y,const int value) const // return true if the same value is found in the same block
{
   int blockStartIndexX = x/3 * 3;
   int blockStartIndexY = y/3 * 3;
   int blockEndIndexX = blockStartIndexX + 2;
   int blockEndIndexY = blockStartIndexY + 2;
   for(int i = blockStartIndexX; i<blockEndIndexX ;i++ ){
      for(int j = blockStartIndexY; j<blockEndIndexY ;j++ ){
         if(Sudoku[i][j].getValue()==value){
            return true;
         }
      }
   }
   return false;
}

bool Puzzle::Solver(int x, int y)
{
      //   bool solver(int x, int y){
      //      If x ==9, return true // Base case
      //      Int emptyX = -1;
      //      Int emptyY = -1;
      //      For(starting row index x to ending row index 8){
      //         For(starting column index y to ending column index 8){
      //            If(Sudoku[x][y].get() == 0){
      //               emptyY = j;
      //               break;
      //            }
      //         }
      //         If(empty != -1)
      //         emptyX = i ;
      //         break;
      //      }
      //      Foreach values from 1 through 9 – newValue
      //      If(set(emptyX, emptyY, newValue){
      //         Int nextX, nextY
      //         If(emptyX < 8){
      //            nextY = emptyY    + 1
      //         }
      //         else if(emptyY == 8){
      //            nextX = emptyX + 1
      //            nextY = 0
      //         }
      //         If(Solver(nextX, nextY)){
      //            Return true
      //         }
      //         set(emptyX, emptyY, 0)
      //      }
      //         Return false
      //      }
      //      }
   return true;
}

Puzzle:: ~Puzzle()
{
   
}
