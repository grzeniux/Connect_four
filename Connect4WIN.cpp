#include <iostream>
#include "Connect4WIN.h"
#include "Connect4GAME.h"
#include <windows.h>

using std::cout;
using std::endl;


namespace connect4
{
    // No parameter constructor
    Connect4WIN::Connect4WIN() :Connect4GAME()
    {
    }

    // Constructor that take game features and will call base class constructor to creating an object
    Connect4WIN::Connect4WIN(int newWidth, int newHeight, char newGameSelect)
        :Connect4GAME(newWidth, newHeight, newGameSelect)
    {
    }

    // User 1 Winning State
    // Only accept horizontally or vertically connected cells as the goal of the game.
    void Connect4WIN::user1Win()
    {
        HANDLE hOut;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = 0; i < getCurrentHeight(); ++i)
        {
            for (int j = 0; j < getCurrentWidth(); ++j)
            {
                if (gameBoard[i][j].getCellState() == 1)
                {
                    // Check vertically
                    if (i + 3 < getCurrentHeight())
                    {
                        if (gameBoard[i + 1][j].getCellState() == 1 && gameBoard[i + 2][j].getCellState() == 1 && gameBoard[i + 3][j].getCellState() == 1)
                        {
                            winner = true;
                            gameBoard[i][j].setCellState(6);
                            gameBoard[i + 1][j].setCellState(6);
                            gameBoard[i + 2][j].setCellState(6);
                            gameBoard[i + 3][j].setCellState(6);
                            display();
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                            cout << "Winner -->";
                            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                            cout << " User 1 (X)" << endl;
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // default colour restored
                            return; // If a winner is already found, break the loop
                        }
                    }

                    // Check horizontally
                    if (j + 3 < getCurrentWidth())
                    {
                        if (gameBoard[i][j + 1].getCellState() == 1 && gameBoard[i][j + 2].getCellState() == 1 && gameBoard[i][j + 3].getCellState() == 1)
                        {
                            winner = true;
                            gameBoard[i][j].setCellState(6);
                            gameBoard[i][j + 1].setCellState(6);
                            gameBoard[i][j + 2].setCellState(6);
                            gameBoard[i][j + 3].setCellState(6);
                            display();
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                            cout << "Winner -->";
                            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                            cout << " User 1 (X)" << endl;
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // default colour restored
                            return; // If a winner is already found, break the loop
                        }
                    }

                    // Check diagonally left to right
                    if (i < getCurrentHeight() - 3 && j < getCurrentWidth() - 3)
                    {
                        if (gameBoard[i + 1][j + 1].getCellState() == 1 && gameBoard[i + 2][j + 2].getCellState() == 1 && gameBoard[i + 3][j + 3].getCellState() == 1)
                        {
                            winner = true;
                            gameBoard[i][j].setCellState(6);
                            gameBoard[i + 1][j + 1].setCellState(6);
                            gameBoard[i + 2][j + 2].setCellState(6);
                            gameBoard[i + 3][j + 3].setCellState(6);
                            display();
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                            cout << "Winner -->";
                            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                            cout << " User 1 (X)" << endl;
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); //default colour restored
                            return; //If a winner is already found, break the loop
                        }
                    }

                    // Check diagonally right to left
                    if (i < getCurrentHeight() - 3 && j - 3 >= 0)
                    {
                        if (gameBoard[i + 1][j - 1].getCellState() == 1 && gameBoard[i + 2][j - 2].getCellState() == 1 && gameBoard[i + 3][j - 3].getCellState() == 1)
                        {
                            winner = true;
                            gameBoard[i][j].setCellState(6);
                            gameBoard[i + 1][j - 1].setCellState(6);
                            gameBoard[i + 2][j - 2].setCellState(6);
                            gameBoard[i + 3][j - 3].setCellState(6);
                            display();
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                            cout << "Winner -->";
                            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                            cout << " User 1 (X)" << endl;
                            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // default colour restored
                            return; // If a winner is already found, break the loop
                        }
                    }
                }
            }
        }
    }


    // User 2 or Computer Winning State
    // Only accept horizontally or vertically connected cells as the goal of the game.   
    void Connect4WIN::user2OrComputerWin()
    {
        HANDLE hOut;
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);

        for (int i = 0; i < getCurrentHeight(); ++i)
        {
            for (int j = 0; j < getCurrentWidth(); ++j)
            {
                if (gameBoard[i][j].getCellState() == 2)
                {
                    // Check vertically
                    if (i + 3 < getCurrentHeight())
                    {
                        if (gameBoard[i + 1][j].getCellState() == 2 &&
                            gameBoard[i + 2][j].getCellState() == 2 &&
                            gameBoard[i + 3][j].getCellState() == 2)
                        {
                            winner2 = true;
                            for (int k = 0; k < 4; ++k)
                            {
                                gameBoard[i + k][j].setCellState(7);
                            }
                            display();
                            if (getGameSelection() == 'P' || getGameSelection() == 'C')
                            {
                                cout << "Game Over .." << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                                cout << "Winner -->";
                                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                                cout << " User 2 (O)" << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // default colour restored
                            }
                            return;
                        }
                    }

                    // Check horizontally
                    if (j + 3 < getCurrentWidth())
                    {
                        if (gameBoard[i][j + 1].getCellState() == 2 &&
                            gameBoard[i][j + 2].getCellState() == 2 &&
                            gameBoard[i][j + 3].getCellState() == 2)
                        {
                            winner2 = true;
                            for (int k = 0; k < 4; ++k)
                            {
                                gameBoard[i][j + k].setCellState(7);
                            }
                            display();
                            if (getGameSelection() == 'P' || getGameSelection() == 'C')
                            {
                                cout << "Game Over .." << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                                cout << "Winner -->";
                                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                                cout << " User 2 (O)" << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // default colour restored
                            }
                            return;
                        }
                    }

                    // Check diagonally left to right
                    if (i + 3 < getCurrentHeight() && j + 3 < getCurrentWidth())
                    {
                        if (gameBoard[i + 1][j + 1].getCellState() == 2 &&
                            gameBoard[i + 2][j + 2].getCellState() == 2 &&
                            gameBoard[i + 3][j + 3].getCellState() == 2)
                        {
                            winner2 = true;
                            for (int k = 0; k < 4; ++k)
                            {
                                gameBoard[i + k][j + k].setCellState(7);
                            }
                            display();
                            if (getGameSelection() == 'P' || getGameSelection() == 'C')
                            {
                                cout << "Game Over .." << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                                cout << "Winner -->";
                                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                                cout << " User 2 (O)" << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // default colour restored
                            }
                            return;
                        }
                    }

                    // Check diagonally right to left
                    if (i + 3 < getCurrentHeight() && j - 3 >= 0)
                    {
                        if (gameBoard[i + 1][j - 1].getCellState() == 2 &&
                            gameBoard[i + 2][j - 2].getCellState() == 2 &&
                            gameBoard[i + 3][j - 3].getCellState() == 2)
                        {
                            winner2 = true;
                            for (int k = 0; k < 4; ++k)
                            {
                                gameBoard[i + k][j - k].setCellState(7);
                            }
                            display();
                            if (getGameSelection() == 'P' || getGameSelection() == 'C')
                            {
                                cout << "Game Over .." << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED); // GOLD
                                cout << "Winner -->";
                                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); // pink
                                cout << " User 2 (O)" << endl;
                                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED); // default colour restored
                            }
                            return;
                        }
                    }
                }
            }
        }
    }




}
