#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void design(int, char, string[3][3]);
int win(string[3][3]);

int main(void)
{
    string arr[3][3] = {{"1", "2", "3"}, {"4", "5", "6"}, {"7", "8", "9"}};
    char var;

    // Asking input from user
        for (int k = 1; k < 10; k++)
        {
            if (k % 2 !=0)
            {
                var = get_int("Enter position for x: ");
            }
            else
            {
                var = get_int("Enter position for o: ");
            }
            design(k, var, arr);
        }
        printf("\nTie\n");
}


void design(int k, char var, string arr[3][3])
{
    int match = 1;
    for (int s = 0; s < 3; s++)
    {
        printf("|");
        for (int t = 0; t < 3; t++)
        {
            if (match != var)
            {
                printf("%s ", arr[s][t]);
                printf("|");
            }
            else
            {
                if (k % 2 != 0)
                {
                    printf("x ");
                    arr[s][t] = "x";
                    printf("|");
                }
                else
                {
                    printf("o ");
                    arr[s][t] = "o";
                    printf("|");
                }
            }
            match++;

        }
        printf("\n--- -- ---\n");
    }
    // Winner
    int x = win(arr);
    if (x == 1)
    {
        printf("\n\nWinner is x\n");
        exit(0);
    }
    else if (x == 2)
    {
        printf("\n\nWinner is o\n");
        exit(0);
    }
}


int win(string arr[3][3])
{
    for (int w = 0; w < 3; w++)
    {
        if (strcmp(arr[w][0], "x") == 0 && strcmp(arr[w][1], "x") == 0 && strcmp(arr[w][2], "x") == 0)
        {
            return 1;
        }
        else if (strcmp(arr[w][0], "o") == 0 && strcmp(arr[w][1], "o") == 0 && strcmp(arr[w][2], "o") == 0)
        {
            return 2;
        }
    }
    for (int v = 0; v < 3; v++)
    {
        if (strcmp(arr[0][v], "x") == 0 && strcmp(arr[1][v], "x") == 0 && strcmp(arr[2][v], "x") == 0)
        {
            return 1;
        }
        else if (strcmp(arr[0][v], "o") == 0 && strcmp(arr[1][v], "o") == 0 && strcmp(arr[2][v], "o") == 0)
        {
            return 2;
        }
    }

    // For diagonals
    if (strcmp(arr[0][0], "x") == 0 && strcmp(arr[1][1], "x") == 0 && strcmp(arr[2][2], "x") == 0)
        return 1;

    if (strcmp(arr[0][0], "o") == 0 && strcmp(arr[1][1], "o") == 0 && strcmp(arr[2][2], "o") == 0)
        return 2;

    return 3;
}
