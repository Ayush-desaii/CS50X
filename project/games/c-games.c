#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>

// SNAKE VERIABLES
int width = 100, height = 25, x, y, fruitx, fruity, flag, gameover, p = 1;
int tailx[100], taily[100];
int score = 0;

//TIC TAC VARIABLES
char board[3][3];
const char player = 'O';
const char com = 'X';




// TIC TAC TOE

void demo()
{
    printf(" 1 | 2 | 3 ");
    printf("\n---|---|---\n");
    printf(" 4 | 5 | 6 ");
    printf("\n---|---|---\n");
    printf(" 7 | 8 | 9 ");
    printf("\n---|---|---\n");
    printf("\n \n Enter potion according to above pic. \n\n");
}

void resetb()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printb()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n---|---|---\n");
    printf("\n");
}

int checkem()
{
    int fs = 9;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                fs--;
            }
        }
    }
    return fs;
}

void playerm()
{
    int n, v, a;

    do
    {
        printf("Enter position : ");
        scanf("%d",&a);
        printf("\n");

        if(a == 1)
        {
            n = 0;
            v = 0;
        }

        else if(a == 2)
        {
            n = 0;
            v = 1;
        }

        else if(a == 3)
        {
            n = 0;
            v = 2;
        }

        else if(a == 4)
        {
            n = 1;
            v = 0;
        }

        else if(a == 5)
        {
            n = 1;
            v = 1;
        }

        else if(a == 6)
        {
            n = 1;
            v = 2;
        }

        else if(a == 7)
        {
            n = 2;
            v = 0;
        }

        else if(a == 8)
        {
            n = 2;
            v = 1;
        }

        else if(a == 9)
        {
            n = 2;
            v = 2;
        }

        if(board[n][v] != ' ')
        {
            printf("Invalid move!\n");
        }

        else
        {
            board[n][v] = player;
            break;
        }
    }while(board[n][v] != ' ');

}

void printw(char w)
{
    if(w == player)
    {
        printf("YOU WIN!!!");

    }

    else if(w == com)
    {
        printf("YOU LOSE ");

    }

    else
    {
        printf("GAME TIE !!");
    }
}

void comm()
{
    srand(time(0));
    int a;
    int d;

    if(checkem() > 0)
    {
        do
        {
            a = rand() % 3;
            d = rand() % 3;
        }while(board[a][d] != ' ');

        board[a][d] = com;

    }
    else
    {
        printw(' ');
    }
}

char checkw()
{
    int i;

    for( i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    for( i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][0] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            return board[0][0];
        }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])
        {
            return board[0][2];
        }
    return ' ';
}



// SNAKE

void imp()
{
    int prevx, prevy, prev2x, prev2y;
    int i;

    prevx = tailx[0];
    prevy= taily[0];

    tailx[0] = x;
    taily[0] = y;

    for(i = 0; i <= p; i++)
    {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch(flag)
        {
            case 1 :
                {
                    x--;
                    break;
                }

            case 2 :
                {
                    x++;
                    break;
                }

            case 3 :
                {
                    y--;
                    break;
                }

            case 4 :
                {
                    y++;
                    break;
                }

        }

        if(x == 0 || x == height || y == 0 || y == width)
        {
            gameover = 1;
            printf("GAME OVER!!!\n");
        }

        if(x == fruitx && y == fruity)
        {
            label3:

                fruitx = rand() % 25;
                if (fruitx == 0)
                goto label3;

            label4:

                 fruity = rand() % 100;
                 if (fruity == 0)
                 goto label4;

            score = score + 10;
            p++;
        }
}


void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'w' :
                {
                    flag = 1;
                    break;
                }

            case 's' :
                {
                    flag = 2;
                    break;
                }

            case 'a' :
                {
                    flag = 3;
                    break;
                }

            case 'd' :
                {
                    flag = 4;
                    break;
                }

        }
    }
}

void setup()

{
    x = height / 2;
    y = width / 2;

    label1:

        fruitx = rand() % 25;
        if (fruitx == 0)
        goto label1;

    label2:

        fruity = rand() % 100;
        if (fruity == 0)
        goto label2;

    gameover = 0;
    //score = 0;

}

void boundry()
{
    system("cls");
    int i, j, k, ch;
    for(i = 0; i <= height; i++)
    {
        for(j = 0; j <= width; j++)
        {
            if(i == 0 || j == 0 || i == height || j == width)
            {
                printf("#");
            }
            else{
                if(i == x && j == y)
                {
                    printf("O");
                }
                else if(i == fruitx && j == fruity)
                {
                    printf("Q");
                }
                else{
                    ch =0;
                    for(k = 0; k < p; k++)
                    {
                        if(i == tailx[k] && j == taily[k])
                        {
                            printf("o");
                            ch = 1;
                        }
                    }
                    if(ch == 0)
                    {
                        printf(" ");
                    }

                }
            }
        }
        printf("\n");
    }
    printf("your score is : %d \n",score);
}

int main(void)
{
    int c = 0;


    char w = ' ';


    printf("choose a game \n enter \n 1 for snake game \n 2 for tic tac toe \n");
    scanf("%d",&c);

    if(c == 1)
    {
        setup();
        while(gameover != 1)
        {
            boundry();
            input();
            imp();
        }
    }

    else if(c == 2)
    {
        demo();
        resetb();
        while(w == ' ' && checkem() != 0)
        {
            printb();

            playerm();

            w = checkw();
            if(w != ' ' || checkem() == 0)
            {
                break;
            }

            comm();

            w = checkw();
            if(w != ' ' || checkem() == 0)
            {
                break;
            }

        }

        printb();
        printw(w);

    }




    return 0;
}
