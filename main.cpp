#include <iostream>
#include <conio.h>   // _getchar()    _keybhit()
#include <windows.h> // sleep()
#include <cstdlib>   // rand()
using std::cout;

const int width = 10;
const int height = 10;

bool gameOver;
int headX, headY;
int tailLenght;
int tailX[100], tailY[100];
int appleX, appleY;
int waitFor = 300;
int score;

enum Directions
{
    STOP,
    UP,
    DOWN,
    RIGHT,
    LEFT
};
enum Directions direction;

void AppleCreator();

void Setup()
{
    gameOver = 0;
    direction = STOP;
    tailLenght = 0;
    headX = rand() % width;
    headY = rand() % height;
    appleX = rand() % width;
    appleY = rand() % height;
    score = 0;
}

void Input()
{
    if (_kbhit())
    {
        char tus;
        tus = _getch();

        switch (tus)
        {
        case 'w':
            if (direction != DOWN)
            {
                direction = UP;
            }
            break;
        case 's':
            if (direction != UP)
            {
                direction = DOWN;
            }
            break;
        case 'a':
            if (direction != RIGHT)
            {
                direction = LEFT;
            }
            break;
        case 'd':
            if (direction != LEFT)
            {
                direction = RIGHT;
            }
            break;

        default:
            break;
        }
    }
}

void Logic()
{

    for (int p = tailLenght - 1; p > 0; p--)
    {
        tailX[p]=tailX[p-1];
        tailY[p]=tailY[p-1];
    }
    /*
    *tail n = tail n-1
    tail0 = bas
    */

    tailX[0] = headX;
    tailY[0] = headY;

    switch (direction)
    {
    case UP:
        headY--;
        break;

    case DOWN:
        headY++;
        break;

    case RIGHT:
        headX++;
        break;

    case LEFT:
        headX--;
        break;

    default:
        break;
    }

    if (headX < 0 || headY < 0 || headX >= width || headY >= height)
    {
        gameOver = 1;
        return;
    }

    else if (headX == appleX && headY == appleY)
    {
        score += 10;
        AppleCreator();
        tailLenght++;
    }
}

void Draw()
{
    system("CLS");

    // ust duvar
    for (int i = 0; i < width + 2; i++)
    {
        cout << "# ";
    }

    cout << std::endl;

    for (int y = 0; y < height; y++)
    {
        cout << "# "; // sol duvar
        for (int x = 0; x < width; x++)
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
                for (int tt = 0; tt < tailLenght; tt++)
                {
                    if (tailX[tt] == x && tailY[tt] == y)
                    {
                        cout << "o ";
                        bos = 0;
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
    for (int i = 0; i < width + 2; i++)
    {
        cout << "# ";
    }
}

void AppleCreator()
{
    appleX = rand() % width;
    appleY = rand() % height;
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

    cout << "\nGame Over!\nYour Score: " << score;

    return 0;
}
