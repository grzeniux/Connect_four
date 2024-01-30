#ifndef CELL_H
#define	CELL_H

namespace connect4 
{
    
    class Cell 
    {

        public:
            //Constructors to Cell Class
            Cell();
            Cell(const char& newCellPosition);
            Cell(const int& newRowPosition);
            Cell(const char& newCellPosition,const int& newRowPosition);
            Cell(const int& newCellState,const char& newCellPosition,const int& newRowPosition);

       
            //  Setters
            void  setAllPosition(const char& newCellPosition,const int& newRowPosition);
            void  setCellPosition(const char& newCellPosition);
            void  setRowPosition(const int& newRowPosition);
            void  setCellState(const int& newCellState);

            //  Getters
            char  getCellPosition() const;
            int   getRowPosition() const;
            int   getCellState() const;
            
        protected:
            char cellPosition;
            int  rowPosition;
            int  cellState; 
      };

} 



#endif	/* CELL_H */

