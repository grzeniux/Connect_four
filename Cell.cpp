#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "Cell.h"

using namespace std;

namespace connect4
{
  // No parameter constructor
  Cell::Cell()
  {
    cellPosition = ' ';
    rowPosition  =  0;
    cellState = 0;   
  }

  // Constructor that take cell position
  Cell::Cell(const char& newCellPosition)
  {
    cellPosition = newCellPosition;
    rowPosition = 0;
    cellState = 0;
  }

  // Constructor that take row position
  Cell::Cell(const int& newRowPosition)
  {
    cellPosition = ' ';
    rowPosition = newRowPosition;
    cellState = 0;
  }

  // Constructor that take cell position and row position
  Cell::Cell(const char& newCellPosition, const int& newRowPosition)
  {
    cellPosition = newCellPosition;
    rowPosition  =  newRowPosition;  
    cellState = 0;
  }

  // Constructor that take cell state,cell position and row position
  Cell::Cell(const int& newCellState,const char& newCellPosition, const int& newRowPosition)
  {
    cellState = newCellState;
    cellPosition = newCellPosition;
    rowPosition =  newRowPosition;  
  }

  // Set the cell position
  // If the cell position is out of range,it will warn the players
  void Cell::setCellPosition(const char& newCellPosition)
  {
    if(newCellPosition > 'Z')
    {
        cout << "Invalid position of the cell " << endl;
        exit(1);
    }
    else {
        cellPosition = newCellPosition;   
    }    
  }

  // Set the row position
  // If the row number is illegal,it will warn the players 
  void Cell::setRowPosition(const int& newRowPosition)
  {
    if(newRowPosition < 0)
    {
        cout << "Invalid Row Position " << endl;
        exit(1);
    }
    else
        rowPosition = newRowPosition;
  }

  void Cell::setCellState(const int& newCellState)
  {   
    cellState = newCellState;   
  }

  int  Cell::getCellState() const
  {
    return cellState;    
  }

  void Cell::setAllPosition(const char& newCellPosition,const int& newRowPosition)
  {
    cellPosition =  newCellPosition;
    rowPosition  =  newRowPosition;  
  }

  char  Cell::getCellPosition() const
  {
    return cellPosition;      
  }

  int Cell::getRowPosition() const
  {
    return rowPosition;
  }

} 