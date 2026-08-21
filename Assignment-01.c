#include <stdio.h>

void accept(int a[10][10], int r, int c)
{
    int i, j;
    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
}

void display(int a[10][10], int r, int c)
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;
    int i, j, k, ch;

    printf("Enter rows and columns of Matrix 1: ");
    scanf("%d%d", &r1, &c1);
    accept(a, r1, c1);

    printf("Enter rows and columns of Matrix 2: ");
    scanf("%d%d", &r2, &c2);
    accept(b, r2, c2);

     printf("\n--- MENU ---\n");
     printf("1. Addition\n");
     printf("2. Subtraction\n");
     printf("3. Multiplication\n");
     printf("4. Transpose of Matrix 1\n");
     printf("5. Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &ch);

     switch(ch)
        {
            case 1:
                if(r1 == r2 && c1 == c2)
                {
                    for(i = 0; i < r1; i++)
                        for(j = 0; j < c1; j++)
                            c[i][j] = a[i][j] + b[i][j];

                    printf("\nAddition:\n");
                    display(c, r1, c1);
                }
                else
                    printf("Addition not possible.\n");
                break;

            case 2:
                if(r1 == r2 && c1 == c2)
                {
                    for(i = 0; i < r1; i++)
                        for(j = 0; j < c1; j++)
                            c[i][j] = a[i][j] - b[i][j];

                    printf("\nSubtraction:\n");
                    display(c, r1, c1);
                }
                else
                    printf("Subtraction not possible.\n");
                break;

            case 3:
                if(c1 == r2)
                {
                    for(i = 0; i < r1; i++)
                    {
                        for(j = 0; j < c2; j++)
                        {
                            c[i][j] = 0;
                            for(k = 0; k < c1; k++)
                                c[i][j] += a[i][k] * b[k][j];
                        }
                    }

                    printf("\nMultiplication:\n");
                    display(c, r1, c2);
                }
                else
                    printf("Multiplication not possible.\n");
                break;

            case 4:
                printf("\nTranspose of Matrix 1:\n");
                for(i = 0; i < c1; i++)
                {
                    for(j = 0; j < r1; j++)
                        printf("%d\t", a[j][i]);
                    printf("\n");
                }
                break;

            case 5:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    return 0;
}
