#include <iostream>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include <cctype>
#include "../header/Animation.hpp"

using namespace std;

void drawBoard(char *spaces)
{
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
    do
    {
        Sleep(1000);
        cout << "Enter where you want to put your mark at: ";
        cin >> number;
        number--;

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
    [0] | [1] | [2]
    [3] | [4] | [5]
    [6] | [7] | [8]
*/

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

bool checkTie(char *spaces){
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
    bool running = true;
    system("cls");

    Animation animate;

    for (;;)
    {
      cout << "Enter Your Mark: ";
      cin >> player;

    if (player == 'X' || player == 'x')
    {
      player = 'X';
      computer = 'O';
      break;
    } else if (player == 'O' || player == 'o')
    {
      player = 'O';
      computer = 'X';
      break;
    } else {
      cout << "Invalid Input! Please Enter X or O." << endl;
    }
    }
    
    drawBoard(spaces);

    while (running)
    {
        PlayerMove(spaces, player);
        drawBoard(spaces);
        if (checkWinner(spaces, player, computer))
        {
            running = false;
            break;
        } else if(checkTie(spaces)){
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
    do
    {
        cout << "Wanna Try Again?" << endl;
        cout << "Enter [Yes/no]" << endl;
        cin >> yn;
    } while (yn != "yes" && yn != "y" && yn != "Yes" && yn != "Y" && yn != "n" && yn != "N" && yn != "No" && yn != "no");
     std::transform(yn.begin(), yn.end(), yn.begin(), ::tolower);
    if (yn == "yes" || yn == "y")
    {
        main();
    } else if (yn == "no" || yn == "n")
    {
        cout << "Bye Bye.." << endl;
        Sleep(2000);
        exit(0);
    }

    return 0;
}