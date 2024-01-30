#ifndef Connect4GAME_H
#define Connect4GAME_H

#include <string>
#include "Cell.h"

using namespace std;

namespace connect4
{

    class Connect4GAME {

    public:
        // Constructors
        Connect4GAME();
        Connect4GAME(int newCurrentWidth, int newCurrentHeight, char newgameSelection);
        virtual ~Connect4GAME();

        // Getters
        int  getCurrentWidth()  const;  // Return the current width
        int  getCurrentHeight() const;  // Return the current height
        char getGameSelection() const;  // Return game selection P or C

        // Setters
        void setCurrentWidth(int newCurrentWidth);      // Set the current width
        void setCurrentHeight(int newCurrentHeight);    // Set the current height
        void setGameSelection(char newGameSelection);   // Set the game selection P or C

        void load(string  inputFileName); // Load the new game 
        void save(string outputFileName, char* userInputs, int& numberOfUserInputs); // Save the current game    
        void play();                    // Does not take a parameter and it plays the computer
        void play(char& cellPosition);  // Takes a cell position and it plays the user
        void playGame();

    protected:
        // Game Data          
        int  currentWidth;   // Game Width
        int  currentHeight;  // Game Height
        char gameSelection;  // Game Selection - P or C
        Cell** gameBoard;    // Game Board

        // Static members           
        static int order;
        static int livingCellAll;
        static int livingCellUser1;
        static int livingCellUser2;
        static int livingCellInFile;
        static bool winner, winner2;

        // Pure virtual functions
        virtual void user1Win() = 0;                 // User 1 game winning state
        virtual void user2OrComputerWin() = 0;       // User 2 and Computer game winning state

        void getData();                                // Get board features
        void initialBoard();                           // Board Initialization
        void display() const;           // Display the current board on the screen 
        void computerSmartMove();       // Smart computer move
        int  letterToBoardPosition(char& inputData);    // Convert the characters to board positions
        void printBoardStepRange() const;            // Prompt the user to input range
        void resizeNewBoard(int rowNumber, int columnNumber); // Resize the new board
        void resizeBoard(string gameFile, int& rowNumber, int& columnNumber); // Resize the board and return row and column number
        string partition(string userInput, int& index); // Parse user input to load and save command   
        bool movement(int yPosition);   // Put the steps to board
        bool gameEnded();               // Returns if the game ended
        bool isLivingUser1Cells(Cell cell);
        bool isLivingUser2Cells(Cell cell);
        static int getOrder() { return order; }
        static int  getLivingCellInFile() { return livingCellInFile; }
        static int  getLivingCellUser1() { return  livingCellUser1; }
        static int  getLivingCellUser2() { return  livingCellUser2; }
        static int  getNumberOfLivingCell() { return livingCellAll; }
        static bool getWinner() { return winner; }
        static bool getWinner2() { return winner2; }

    };

}

#endif	/* Connect4GAME_H */

