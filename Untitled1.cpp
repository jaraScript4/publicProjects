#include "txLib.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
int Information(int y, const char* name, const char* surname, const char* number, const char* games, const char* goals, const char* transfer, const char* yellow_card, const char* red_card)
{
    txSetColour(TX_BLACK, 5);
    txSetFillColour(RGB(0, 189, 255));
    //txSelectFont("HoloLens MDL2 Assets обычный", 0);
    txTextOut(20, y * 20, name);
    txTextOut(70, y * 20, surname);
    txTextOut(160, y * 20, number);
    txTextOut(180, y * 20, games);
    txTextOut(200, y * 20, goals);
    txTextOut(220, y * 20, transfer);
    txTextOut(240, y * 20, yellow_card);
    txTextOut(260, y * 20, red_card);
    return 1;
}
int Numbers_Of_Players()
{
    if(GetAsyncKeyState('0'))
    return 9;
    if(GetAsyncKeyState('1'))
    return 0;
    if(GetAsyncKeyState('2'))
    return 1;
    if(GetAsyncKeyState('3'))
    return 2;
    if(GetAsyncKeyState('4'))
    return 3;
    if(GetAsyncKeyState('5'))
    return 4;
    if(GetAsyncKeyState('6'))
    return 5;
    if(GetAsyncKeyState('7'))
    return 6;
    if(GetAsyncKeyState('8'))
    return 7;
    if(GetAsyncKeyState('9'))
    return 8;
    return -1;
}
struct list_name
{
    const char *text;
    int gol;
    int y;
};
struct footballman
{
    string name;
    string surname;
    string num;
    string goals;
    bool on_fild =true;
};
struct group
{
    string name;
    footballman player[22];
    int amount = 0;

};
struct footballmans
{
    int x;
    int y;
    int num;
    string surname="игроки";
};
footballmans player[11];
group team1;
int moving(int k)
{
    if(txMouseX() >= player[k].x &&
    txMouseX() <= player[k].x + 50 &&
    txMouseY() >= player[k].y &&
    txMouseY() <= player[k].y + 50 &&
    txMouseButtons() & 1)
    {
    player[k].x = txMouseX() - 25;
    player[k].y = txMouseY() - 25;
    int l=Numbers_Of_Players();
        if(l>-1)
            if (team1.player[l].on_fild)
            {
            player[k].surname=team1.player[l].surname;
            team1.player[l].on_fild=false;
            }
    }

    return 0;
}

int readfile(string file)
{
    ifstream f(file);

    f >> team1.name;

    int i = 0;
    while(!f.eof())
    {
        f >> team1.player[i].name;
        f >> team1.player[i].surname;
        f >> team1.player[i].num;
        f >> team1.player[i].goals;
        i++;
        //cout << team1.player[i].name << i << endl;

    }
    team1.amount = i;

}

int main()
{
    setlocale(LC_ALL, "russian");
    txCreateWindow(800, 800);
    int xf = 0;
    int yf = 0;
    int x = 30;
    int y = 30;
    int commands = 1;
    int xPlayer1 = 300;
    int yPlayer1 = 50;
    int a;
    a < 11;
    a++;

    HDC fild = txLoadImage("футбольное поле.bmp");

    HDC player1 = txLoadImage("игрок.bmp");

    while(true)
    {
        txClear();
        txBegin();
        if(commands > 2) commands = 1;
        if(commands < 1) commands = 2;

        if(commands==1) readfile("command_1.txt");
        else readfile("command_2.txt");

        player[10].x = 530;
        player[10].y = 700;

        player[0].x != player[1].x != player[2].x != player[3].x != player[4].x != player[5].x != player[6].x != player[7].x !=player[8].x != player[9].x != player[10].x;
        player[0].y != player[1].y != player[2].y != player[3].y != player[4].y != player[5].y != player[6].y != player[7].y !=player[8].y != player[9].y != player[10].y;

        txSetColour(TX_WHITE, 5);
        txSetFillColour(RGB(0, 150, 255));
        txRectangle(0, 0, 800, 800);
        txLine(0, 50, 800, 50);
        txLine(300, 50, 300, 800);//>300  >50

        txLine(200, 750, 300, 750);
        txLine(200, 700, 300, 700);
        txLine(200, 700, 200, 800);
        txTextOut(210, 770, "4-4-2");
        txTextOut(210, 720, "4-3-2-1");

        if(txMouseX() >= 200 &&
        txMouseX() <= 300 &&
        txMouseY() >= 750 &&
        txMouseY() <= 800 &&
        txMouseButtons() & 1)
        {
           player[0].x = 405;
           player[0].y = 160;
           player[1].x = 660;
           player[1].y = 160;

           player[2].x = 350;
           player[2].y = 405;
           player[3].x = 600;
           player[3].y = 405;
           player[4].x = 710;
           player[4].y = 405;
           player[5].x = 460;
           player[5].y = 405;

           player[6].x = 350;
           player[6].y = 605;
           player[7].x = 600;
           player[7].y = 605;
           player[8].x = 710;
           player[8].y = 605;
           player[9].x = 460;
           player[9].y = 605;
        }

        if(txMouseX() >= 200 &&
        txMouseX() <= 300 &&
        txMouseY() >= 700 &&
        txMouseY() <= 750 &&
        txMouseButtons() & 1)
        {
           player[0].x = 530;
           player[0].y = 200;

           player[1].x = 530;
           player[1].y = 340;
           player[2].x = 690;
           player[2].y = 340;
           player[3].x = 370;
           player[3].y = 340;

           player[4].x = 450;
           player[4].y = 480;
           player[5].x = 610;
           player[5].y = 480;

           player[6].x = 350;
           player[6].y = 605;
           player[7].x = 600;
           player[7].y = 625;
           player[8].x = 710;
           player[8].y = 605;
           player[9].x = 460;
           player[9].y = 625;
        }

        txTextOut(x, y, team1.name.c_str());

        if(txMouseX() >= 0 &&
        txMouseX() <= 800 &&
        txMouseY() >= 0 &&
        txMouseY() <= 45)
        {
            if(GetAsyncKeyState(VK_LEFT))
                {commands = commands + 1;txSleep(100);}
            if(GetAsyncKeyState(VK_RIGHT))
                {commands = commands - 1;txSleep(100);}
        }

        for (int i = 0; i < team1.amount; i++)
        {
            if(GetAsyncKeyState(VK_LEFT))
            txTextOut(x-20, y + 30 + i * 20, "i ");
            txTextOut(x, y + 30 + i * 20, team1.player[i].surname.c_str());
            txTextOut(x + 100, y + 30 + i * 20, team1.player[i].name.c_str());
        }

        txBitBlt(txDC(), 303, 53, 500, 750, fild);

        for(int i = 0; i < 11; i++)
        {
            txBitBlt(txDC(), player[i].x, player[i].y, 50, 50, player1);
            txTextOut(player[i].x - 10, player[i].y + 70, player[i].surname.c_str());
        }

        for(int i = 0; i < 10; i++)
        {
        moving(i);
        }

        //Information(3, "Петя", "Петров", "2", "5", "6", "7", "5", "10");
        //Information(4, "Вася", "Петров", "2", "5", "6", "7", "5", "10");
        //Information(5, "Петя", "Вася", "2", "5", "6", "7", "5", "10");

        /*for(int i = 0; i < 2; i++)
        {
            txDrawText(5, 225, 235, 495, Name[i]);
        }*/

        txSleep(0);
        txEnd();
    }

    return 0;
}
