#include <iostream>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include "../header/Animation.hpp"

using namespace std;

void drawBoard(char *spaces)
{
    // clears every message before
    system("cls");
    cout << endl;
    cout << "      |      |      " << endl;
    cout << "   " << spaces[0] << "  |   " << spaces[1] << "  |   " << spaces[2] << "   " << endl;
    cout << "      |      |      " << endl;
    cout << "------|------|------" << endl;
    cout << "      |      |      " << endl;
    cout << "   " << spaces[3] << "  |   " << spaces[4] << "  |   " << spaces[5] << "   " << endl;
    cout << "      |      |      " << endl;
    cout << "------|------|------" << endl;
    cout << "      |      |      " << endl;
    cout << "   " << spaces[6] << "  |   " << spaces[7] << "  |   " << spaces[8] << "   " << endl;
    cout << "      |      |      " << endl;
    cout << endl;
}

void PlayerMove(char *spaces, char player)
{
    int number;
    // This do-while will not stop until the user enters a number between 1 and 8
    do
    {
        Sleep(1000);
        cout << "Enter where you want to put your mark at: ";
        cin >> number;
        // this decrements the player input because array starts with zero so input - 1 is necessary.
        number--;
        // this if statement replaces the empty ones with the player mark.
        if (spaces[number] = ' ')
        {
            spaces[number] = player;
            break;
        }
    } while (!number > 0 && !number < 8);
}

void ComputerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));
    cout << "Computers Turn..." << endl;
    // Since we want random nuumber to be generated every time when its computer turn so it wwouuld be palced insdie of the while loop instead outside.
    while (true)
    {
        number = rand() % 9;
        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

/*
This is just for the Check Winner Logic
    [0] | [1] | [2]
    [3] | [4] | [5]
    [6] | [7] | [8]
*/
// checkWinner is a bool because we want it to send either true or false, the reason for this is for the int main()
// This checks the basic rule of Tic-Tac-Toe diagonal and straight.
bool checkWinner(char *spaces, char player, char computer)
{
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[3] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[6] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }

    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[1] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[2] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player ? cout << "YOU WON!" << endl : cout << "YOU LOST NGA!" << endl;
    }
    else
    {
        return false;
    }
    return true;
}
// Tthis function checks if there are any spaces left if they are then continuue the agme if not it means no one hass on so it will display tie.
bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "YOOOO, Its a TIE!!!!!" << endl;
    return true;
}

int main()
{
    string yn;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player;
    char computer;
    // This running boolean will be used to implemet the start and the end of game
    bool running = true;
    system("cls");
    // this will just do the animation which is in the src folder
    Animation animate;
// This for-loop will check if the user's input is x,X,O or o, if not then it will continue
    for (;;)
    {
        cout << "Enter Your Mark: ";
        cin >> player;

        if (player == 'X' || player == 'x')
        {
            player = 'X';
            computer = 'O';
            break;
        }
        else if (player == 'O' || player == 'o')
        {
            player = 'O';
            computer = 'X';
            break;
        }
        else
        {
            cout << "Invalid Input! Please Enter X or O." << endl;
        }
    }

    drawBoard(spaces);

    // this while loop wwill run until the running is true
    while (running)
    {
        PlayerMove(spaces, player);
        drawBoard(spaces);
        // if checkWinner's response is 1 meaning true it means that someone has one thus the game will end.
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
        // This checks for tie
        else if (checkTie(spaces))
        {
            running = false;
            break;
        }

        ComputerMove(spaces, computer);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        }
    }
    Sleep(2000);
    // After the game ends this do while loop asks the user to play again or not. and if the user entered any invalid input it will repeat 
    do
    {
        cout << "Wanna Try Again?" << endl;
        cout << "Enter [Yes/no]" << endl;
        cin >> yn;
    } while (yn != "yes" && yn != "y" && yn != "Yes" && yn != "Y" && yn != "n" && yn != "N" && yn != "No" && yn != "no");
    // this transform will make the user's whole input to be lower case.
    //                                                | the tolower function is imported using the cctype include header file.
    std::transform(yn.begin(), yn.end(), yn.begin(), ::tolower);

    if (yn == "yes" || yn == "y")
    {
        // this is the main() function, basically recursion
        main();
    }
    else if (yn == "no" || yn == "n")
    {
        cout << "Bye Bye.." << endl;
        Sleep(2000);
        exit(0);
    }

    return 0;
}