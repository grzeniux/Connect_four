#ifndef Connect4WIN_H
#define	Connect4WIN_H
#include "Connect4GAME.h"

namespace connect4
{

    class Connect4WIN : public Connect4GAME
    {

    public:
        Connect4WIN();
        Connect4WIN(int newWidth, int newHeight, char newGameSelect);
    protected:
        virtual void user1Win();                 // User 1 winning state
        virtual void user2OrComputerWin();       // User 2 and Computer winning state 

    };

}
#endif	/* Connect4WIN_H */








