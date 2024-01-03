#include <iostream>
#include <conio.h>   // _getchar()    _keybhit()
#include <windows.h> // sleep()
#include <cstdlib>   // rand()
using std::cout;

const int wide = 10;
const int height = 10;

bool gameOver;
int headX, headY;
int tailLenght;
int tailX[100], tailY[100];
int appleX, appleY;
int waitFor = 100;

enum Directions
{
    STOP,
    UP,
    DOWN,
    RIGHT,
    LEFT
};
enum Directions direction;

void Setup()
{
    gameOver = 0;
    direction = STOP;
    tailLenght = 0;
    headX = rand() % wide;
    headY = rand() % height;
    appleX = rand() % wide;
    appleY = rand() % height;
}

void Input()
{
}

void Logic()
{
}

void Draw()
{
    system("CLS");

    // ust duvar
    for (int i = 0; i < wide + 2; i++)
    {
        cout << "# ";
    }

    cout << std::endl;

    for (int y = 0; y < height; y++)
    {
        cout << "# "; // sol duvar
        for (int x = 0; x < wide; x++)
        {

            if (headX == x && headY == y)
            {
                cout << "O ";
            }

            else if (appleX == x && appleY == y)
            {
                cout << "* ";
            }

            else
            {
                bool bos = 1;
                for (int tx = 0; tx < tailLenght; tx++)
                {
                    for (int ty = 0; ty < tailLenght; ty++)
                    {
                        if (tx == x && ty == y)
                        {
                            cout << "o ";
                            bos = 0;
                        }
                    }
                }

                if (bos)
                {
                    cout << "  ";
                }
            }
        }
        cout << "#\n"; // sag duvar
    }

    // alt duvar
    for (int i = 0; i < wide + 2; i++)
    {
        cout << "# ";
    }
}

int main()
{
    Setup();

    while (!gameOver)
    {
        Draw();
        Input();
        Logic();

        Sleep(waitFor);
    }

    return 0;
}
