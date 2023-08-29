#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display(char table[3][3])
{
    printf("\n    %c  |   %c   |  %c  \n  _____|_______|_____\n       |       |     \n    %c  |   %c   |  %c  \n  _____|_______|_____\n       |       |     \n    %c  |   %c   |  %c  \n", table[0][0], table[0][1], table[0][2], table[1][0], table[1][1], table[1][2], table[2][0], table[2][1], table[2][2]);
    return;
}

int judge(char table[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("First column %c\n", table[i][0]);
        if (table[i][0] == table[i][1] == table[i][2] || table[0][i] == table[1][i] == table[2][i])
        {
            printf("Checking...");
            return 1;
        }
    }
    if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0]!=' ' && table[2][2]!=' ')
    {
        return 1;
    }
    else if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2]!=' ' && table[2][0]!=' ')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    bool run = true;
    int activeUser = 1;
    char table[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    char howTo[3][3] = {{'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'}};
    printf("+-------------+\n|             |\n| Tic-Tac-Toe |\n|             |\n+-------------+\n");
    display(howTo);

    while (run)
    {
        char inputChar[10];
        // taking input form user in the form of string
        printf("\nEnter your position : ");
        fgets(inputChar, sizeof(inputChar), stdin);

        // converting the input to integer
        int userInp = strtol(inputChar, NULL, 10);

        if (userInp != 0)
        {
            // converting the userinput to row and column
            int row = 2 - (int)(userInp / 3);
            int col;

            if (userInp % 3 == 0)
            {
                col = 2;
                row++;
            }
            else
            {
                col = (userInp % 3) - 1;
            }

            // updating the matrix
            if (activeUser == 1)
            {
                table[row][col] = 'X';
            }
            else
            {
                table[row][col] = 'O';
            }

            display(table);
            // checking for winner
            if (judge(table) == 1)
            {
                if (activeUser == 1)
                {
                    printf("User 1 win 🥳");
                }
                else
                {
                    printf("User 2 win 🥳");
                }
                return 0;
            }

            activeUser *= -1;

            printf("row : %d and col : %d", row, col);
        }
    }

    return 0;
}