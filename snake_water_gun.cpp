#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;

class Game
{
private:
    int user, bot;
    int user_points = 0, bot_points = 0;
    int num = 3;
    string gameVar, gameVar2;

public:
    void mainMenu();
    void playGame();
    void help();
    void setHighScore(int points);
    void highScore();
    void loadingBar();
};

void Game ::mainMenu()
{
    int input;
    system("cls");
    cout << "\n\t\t\t\t\tPlease Choose An Options" << endl;
    cout << "\t\t\t\t\t1. Play Game\n";
    cout << "\t\t\t\t\t2. Help\n";
    cout << "\t\t\t\t\t3. High Score\n";
    cout << "\t\t\t\t\t0. Exit\n";
    cout << "\t\t\t\t\t";

    cin >> input;
    switch (input)
    {
    case 1:
        playGame();
        system("pause");
        mainMenu();
        break;
    case 2:
        help();
        break;
    case 3:
        highScore();
        break;
    case 0:
        exit(0);
    default:
        break;
    }
}

void Game ::playGame()
{

    system("cls");
    srand(time(0));

    cout << "\t\t\t\t\tWelcome to Snake Water and Gun Game Let's play it...\n"
         << endl;
    int exit = 1;
    while (exit)
    {
        cout << "\t\t\t\t\tPlease select an option\n\t\t\t\t\t1.Snake\n\t\t\t\t\t2.Water\n\t\t\t\t\t3.Gun\n\t\t\t\t\t0.Quit\n\t\t\t\t\t_____ ";
        cin >> user;
        bot = 1 + (rand() % num);
        // cout << user << " " << bot;
        if (bot == 1)
        {
            gameVar = "Snake";
        }
        else if (bot == 2)
        {
            gameVar = "Water";
        }
        else
        {
            gameVar = "Gun";
        }

        if (user == 1)
        {
            gameVar2 = "Snake";
        }
        else if (user == 2)
        {
            gameVar2 = "Water";
        }
        else
        {
            gameVar2 = "Gun";
        }

        if (user == bot)
        {
            cout << "\t\t\t\t\tOh Sorry Match is draw!!!"
                 << endl;
        }
        else if (user == 1 && bot == 2 || user == 2 && bot == 3 || user == 3 && bot == 1)
        {
            cout << "\t\t\t\t\tWon"<< endl;
            user_points += 10;
        }
        else if (user == 0)
        {
            setHighScore(user_points);
            cout << "\t\t\t\t\tYour points : " << user_points << " Bot points : " << bot_points << endl
                 << endl;
            exit = 0;
        }

        else
        {
            cout << "\t\t\t\t\tDefeat"
                 << endl;
            bot_points += 10;
        }
        if (user != 0)
        {
            cout << "\t\t\t\t\tUser : " << gameVar2 << "\t Bot : " << gameVar << endl;
        }
    }
}

void Game ::help()
{
    string line;
    ifstream read;
    read.open("help.txt");
    if (!read)
    {
        cout << "File not open!!!";
    }
    while (getline(read, line))
    {
        cout << line << endl;
    }
    cout << "\n\n";
    system("pause");
    mainMenu();
}

void Game ::highScore()
{
    string line;
    ifstream read;
    read.open("high_score.txt");
    if (!read)
    {
        cout << "File not open!!!";
    }

    getline(read, line);
    cout << "\n\n\n\t\t\t\t\tUsers High Score : ";
    cout << line << endl;
    read.close();
    cout << "\n\n";
    system("pause");
    mainMenu();
}

void Game ::setHighScore(int score)
{
    int high_score = 0;
    ifstream read;
    read.open("high_score.txt");
    if (!read)
    {
        cout << "File not open!!!";
    }
    read >> high_score;
    if (high_score < score)
    {
        high_score = score;
    }
    else if (high_score > score)
    {
        high_score = high_score;
    }
    read.close();

    ofstream write;
    write.open("high_score.txt");
    write << high_score;
    write.close();
}

void Game ::loadingBar()
{
    system("cls");
    char a = 177, b = 219;
    cout << "\n\n\n\n";
    cout << "\n\t\t\t\t\t| Welcome to Snake Water And Gun Game |" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tCreated By @HACKER X";
    cout << "\n\n\t\t\t\t\t\tLoading...";
    cout << "\n\n\t\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << a;
    }
    cout << "\r";
    cout << "\t\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << b;
        Sleep(100);
    }
}

int main()
{
    Game user;
    user.loadingBar();
    user.mainMenu();
    return 0;
}