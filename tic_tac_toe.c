#include <stdio.h>
#include <stdlib.h>
char menu();
void pattern();
int check(char (*)[3]);
int len(char *);
void recreate(char (*)[3]);
void player2(char (*)[3], char *, char *);
void display(char (*)[3]);
int playerModify(char (*)[3], char, char);
void smartComputer(char (*a)[3], char *);
void smartComputerModify(char (*a)[3]);
void evilComputer(char (*a)[3], char *);
void evilComputerModify(char (*a)[3]);
int main()
{
    char a[3][3] = {{49, 50, 51}, {52, 53, 54}, {55, 56, 57}};
    char x;
    char first[40];
    char second[40];
    while (1)
    {
        system("cls");
        pattern();
        x = menu();
        fflush(stdin);
        switch (x)
        {
        case '3':
            player2(a, first, second);
            break;
        case '2':
            evilComputer(a, first);
            break;
        case '1':
            smartComputer(a, first);
            break;
        case '4':
            printf("Thanks for playing :)\n");
            getchar();
            exit(0);
        default:
            x = 0;

            printf("Invalid input , press enter to choose again : ");
            getchar();
            fflush(stdin);
        }
        if (x == 0)
            continue;
        printf("Want to play again ?(y/n) : ");
        x = getchar();
        fflush(stdin);
        if (x == 'y')

            recreate(a);
        else
        {
            printf("Thanks for playing :) \n");
            getchar();
            break;
        }
    }
    return 0;
}
void pattern()
{
    int i;
    for (i = 0; i < 30; i++)
    {
        printf("#");
    }
    printf(" Tic Tac Toe ");
    for (i = 1; i < 30; i++)
    {
        printf("#");
    }
    printf("\n\n");
}
void smartComputer(char (*a)[3], char *b)
{
    printf("Enter players name : ");
    fgets(b, 40, stdin);
    b[len(b)] = '\0';
    system("cls");
    printf("\e[?25l");
    char x;
        while(1)
    {
        printf("Player 1 : X\n");
        printf("Player 2 : O\n\n");
        display(a);
        printf("\n\nEnter the marking place : ");
        x = playerModify(a, 'X', getchar());
        fflush(stdin);
        while (x)
        {
            x = playerModify(a, 'X', getchar());
            fflush(stdin);
        }

        smartComputerModify(a);
        x = check(a);
        if (x == 1)
        {
            system("cls");
            printf("Player 1 : X\n");
            printf("Player 2 : O\n\n");
            display(a);
            printf("\nCongratulations , You Won\n");
            return;
        }
        else if (x == 2)
        {
            system("cls");
            printf("Player 1 : X\n");
            printf("Player 2 : O\n\n");
            display(a);
            printf("\nYou Lose\n");
            return;
        }
        else if (x == 3)
        {
            system("cls");
            printf("Player 1 : X\n");
            printf("Player 2 : O\n\n");
            display(a);
            printf("There's a tie\n");
            return;
        }
        system("cls");
    }
}
void evilComputer(char (*a)[3], char *b)
{  
    printf("Enter players name : ");
    fgets(b, 40, stdin);
    b[len(b)] = '\0';
    system("cls");
    printf("\e[?25l");
    char x;
    while (1)
    {
        printf("Player 1 : X\n");
        printf("Player 2 : O\n\n");
        display(a);
        printf("\n\nEnter the marking place : ");
        x = playerModify(a, 'X', getchar());

        fflush(stdin);
        while (x)
        {
            x = playerModify(a, 'X', getchar());
            fflush(stdin);
        }

        evilComputerModify(a);
        x = check(a);
        if (x == 1)
        {   
             system("cls");
            printf("Player 1 : X\n");
        printf("Player 2 : O\n\n");
            display(a);
            printf("\nCongratulations , You Won\n");
            return;
        }
        else if (x == 2)
        {  
            system("cls");
            printf("Player 1 : X\n");
        printf("Player 2 : O\n\n");
            display(a);
            printf("\nYou Lose\n");
            return;
        }
        else if (x == 3)
        {  
            system("cls");
            printf("Player 1 : X\n");
        printf("Player 2 : O\n\n");
            display(a);
            printf("\nThere's a tie\n");
            return;
        }
        system("cls");
    }
}
void evilComputerModify(char (*a)[3])
{
    int i, j, l, k = 0;
    int s = 0, r = 0, flag = 0;
    // Checking if there any two similar X found row wise, if yes then insert O

    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 'X')
            {
                k++;
            }
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                l = j;
            }
        }
        if (k == 2 && s == 1)
        {
            a[i][l] = 'O';
            flag = 1;
        }
    }
    // Checking if there any two similar X found column wise, if yes then insert O

    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[j][i] == 'X')
            {
                k++;
            }
            else if (a[j][i] >= 49 && a[j][i] <= 57)
            {
                s++;
                r = j;
            }
        }

        if (k == 2 && s == 1)
        {
            a[r][i] = 'O';
            flag = 1;
        }
    }
    s = 0, k = 0;
    // Checking if there is any two X diagonally left to right , if yes then insert O

    for (i = 0; i < 3; i++)
    {

        for (j = i; j <= i; j++)
        {
            if (a[i][j] == 'X')
            {
                k++;
            }
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                r = i;
                l = j;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        flag = 1;
    }
    s = 0, k = 0;
    // Checking if there is any two X diagonally right to left , if yes then insert O

    for (i = 0; i < 3; i++)
    {

        for (j = i; j <= i; j++)
        {
            if (a[i][2 - i] == 'X')
            {
                k++;
            }
            else if (a[i][2 - i] >= 49 && a[i][2 - i] <= 57)
            {
                s++;
                r = i;
                l = 2 - i;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        flag = 1;
    }
    // If none of upper cases executes then randomly putting O
    if (flag == 0)
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (a[i][j] >= 49 && a[i][j] <= 57)
                {
                    a[i][j] = 'O';
                    return;
                }
            }
        }
}

void smartComputerModify(char (*a)[3])
{
    int i, j, l, k = 0;
    int s = 0, r = 0;
    // Checking if there any two similar X found row wise, if yes then insert O
    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] == 'X')
            {
                k++;
            }
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                l = j;
            }
        }
        if (k == 2 && s == 1)
        {
            a[i][l] = 'O';
            return;
        }
    }
    // Checking if there any two similar X found column wise,if yes then insert O

    for (i = 0; i < 3; i++)
    {
        k = 0;
        s = 0;
        for (j = 0; j < 3; j++)
        {
            if (a[j][i] == 'X')
            {
                k++;
            }
            else if (a[j][i] >= 49 && a[j][i] <= 57)
            {
                s++;
                r = j;
            }
        }

        if (k == 2 && s == 1)
        {
            a[r][i] = 'O';
            return;
        }
    }
    s = 0, k = 0;
    // Checking if there is any two X diagonally left to right , if yes then insert O
    for (i = 0; i < 3; i++)
    {

        for (j = i; j <= i; j++)
        {
            if (a[i][j] == 'X')
            {
                k++;
            }
            else if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                s++;
                r = i;
                l = j;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        return;
    }
    s = 0, k = 0;
    // Checking if there is any two X diagonally right to left , if yes then insert O

    for (i = 0; i < 3; i++)
    {

        for (j = i; j <= i; j++)
        {
            if (a[i][2 - i] == 'X')
            {
                k++;
            }
            else if (a[i][2 - i] >= 49 && a[i][2 - i] <= 57)
            {
                s++;
                r = i;
                l = 2 - i;
            }
        }
    }
    if (k == 2 && s == 1)
    {
        a[r][l] = 'O';
        return;
    }
    // Randomly putting value if none of row , column or diagonal consists of two X
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] >= 49 && a[i][j] <= 57)
            {
                a[i][j] = 'O';
                return;
            }
        }
    }
}

int len(char *s)
{
    int i = 0;
    while (s[i] != '\0' && s[i] != '\n')
    {
        i++;
    }
    return i;
}
char menu()
{
    printf("Enter your choice : ");
    printf("\n1. Want to play with Smart computer");
    printf("\n2. Want to play with Evil computer");
    printf("\n3. Want to play with player");
    printf("\n4. Exit\n");
    return getchar();
}
int check(char (*a)[3])
{
    int i, j;
    // Checking row wise for three similar X or O
    for (i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2])
        {
            if (a[i][0] == 'X')
                return 1;
            else if (a[i][0] == 'O')
                return 2;
        }
    }
    // Checking column wise for three similar X or O

    for (i = 0; i < 3; i++)
    {
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i])
            if (a[0][i] == 'X')
            {
                return 1;
            }
            else if (a[0][i] == 'O')
            {
                return 2;
            }
    }
    // Checking diagonally left to right

    if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
    {
        if (a[0][0] == 'X')
            return 1;
        else if (a[0][0] == 'O')
            return 2;
    }
    // Checking diagonally right to left

    if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
    {
        if (a[1][1] == 'X')
            return 1;
        else if (a[1][1] == 'O')
            return 2;
    }
    // If none of three similar X or O found
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (a[i][j] >= 49 && a[i][j] <= 57)
                return -1;
        }
    }
    // If tie
    return 3;
}
void player2(char (*a)[3], char *b, char *c)
{

    printf("Enter first Player name : ");
    fgets(b, 40, stdin);
    b[len(b)] = '\0';
    printf("Enter second player name : ");
    fgets(c, 40, stdin);
    printf("\e[?25l");
    c[len(c)] = '\0';
    char x, k = 1;
    system("cls");
    while (1)
    {
        printf("Player 1 : X\n");
        printf("Player 2 : O\n\n");
        display(a);
        x = check(a);
        if (x == 1)
        {
            printf("\n%s Won\n", b);
            return;
        }
        else if (x == 2)
        {
            printf("\n%s Won\n", c);
            return;
        }
        else if (x == 3)
        {
            printf("\nThere's a tie\n");
            return;
        }
        else if (x == -1)
            switch (k % 2)
            {
            case 1:
                printf("\n%s's turn : ", b);
                x = playerModify(a, 'X', getchar());
                fflush(stdin);
                while (x != 0)
                {
                    x = playerModify(a, 'X', getchar());
                    fflush(stdin);
                }
                system("cls");
                break;
            case 0:
                printf("\n%s's turn : ", c);
                x = playerModify(a, 'O', getchar());
                fflush(stdin);
                while (x != 0)
                {
                    x = playerModify(a, 'X', getchar());
                    fflush(stdin);
                }
                system("cls");

                fflush(stdin);
                break;
            }

        k++;
    }
}
void recreate(char (*a)[3])
{
    int i, j;
    char x = '1';
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a[i][j] = x++;
        }
    }
}
int playerModify(char (*a)[3], char b, char c)
{
    char x = '1';
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (x == c)
            {
                if (a[i][j] >= 49 && a[i][j] <= 57)
                {
                    a[i][j] = b;
                    return 0;
                }
                printf("Invalid input , press enter to choose again : ");
                getchar();
                fflush(stdin);

                return 1;
            }
            x++;
        }
    }
}

void display(char (*a)[3])
{
    int i, j, s;
    printf("\033[1;32m");
    printf("\n");

    printf("|     |     |     |");
    printf("\n");
    for (i = 0; i < 3; i++)
    {
        printf("|  ");
        for (j = 0; j < 3; j++)
        {

            printf("%c  |  ", a[i][j]);
        }

        printf("\n");
        printf("|_____|_____|_____|");
        printf("\n");
        printf("|     |     |     |");
        printf("\n");
    }
    printf("\033[0m");
}
