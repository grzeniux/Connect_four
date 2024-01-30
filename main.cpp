#include <iostream>
#include "Connect4WIN.h"
#include <windows.h>

using namespace connect4;

int main(int argc, char** argv)
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char objectType = '\0';
	cout << "###############################################################################################" << endl;
	cout << "###############################################################################################" << endl;
	cout << "################################";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
	cout << "  C O N N E C T   F O U R  ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);		// default colour
	cout << "####################################" << endl;

	cout << "###############################################################################################" << endl;
	cout << "#####################";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "	A R R A N G E   T H E   F O U R   S I G N S  ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);		// default colour
	cout << "##########################" << endl;

	cout << "###############################################################################################" << endl;
	cout << "#############";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "  C O L U M N  ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);		// default colour
	cout << "#############";

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "  R O W  ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);		// default colour
	cout << "#############";

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "  D I A G O N A L  ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);		// default colour
	cout << "#############" << endl;
	cout << "###############################################################################################" << endl;
	cout << "#########################";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "  E N J O Y   T H E   G A M E !!!  ";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);		// default colour
	cout << "###################################" << endl;
	cout << "###############################################################################################" << endl;
	cout << "###############################################################################################" << endl;

	SetConsoleTextAttribute(hOut, BACKGROUND_RED);
	cout << endl << "Select the board size";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);		// default colour

	Connect4WIN cfPlusObject;
	cfPlusObject.playGame();
	cout << "Press enter to exit...";
	cin.get();


	return 0;
}