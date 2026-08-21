#include <stdio.h>

void display(int a[20][3])
{
    int i;

    for(i = 0; i <= a[0][2]; i++)
    {
        printf("%d\t%d\t%d\n",
               a[i][0], a[i][1], a[i][2]);
    }
}

// Simple Transpose
void transpose(int a[20][3], int b[20][3])
{
    int i, j, k = 1;

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    for(i = 0; i < a[0][1]; i++)
    {
        for(j = 1; j <= a[0][2]; j++)
        {
            if(a[j][1] == i)
            {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}

// Fast Transpose
void fastTranspose(int a[20][3], int b[20][3])
{
    int count[20] = {0};
    int start[20];
    int i, j;

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    for(i = 1; i <= a[0][2]; i++)
    {
        count[a[i][1]]++;
    }

    start[0] = 1;

    for(i = 1; i < a[0][1]; i++)
    {
        start[i] = start[i-1] + count[i-1];
    }

    for(i = 1; i <= a[0][2]; i++)
    {
        j = start[a[i][1]];

        b[j][0] = a[i][1];
        b[j][1] = a[i][0];
        b[j][2] = a[i][2];

        start[a[i][1]]++;
    }
}

int main()
{
    int a[20][3], b[20][3];
    int i, choice;

    printf("Enter rows, columns and number of non-zero elements: ");
    scanf("%d%d%d", &a[0][0], &a[0][1], &a[0][2]);

    printf("Enter row column and value of non-zero elements:\n");

    for(i = 1; i <= a[0][2]; i++)
    {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }

    do
    {
        printf("\n1. Display Sparse Matrix");
        printf("\n2. Simple Transpose");
        printf("\n3. Fast Transpose");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display(a);
                break;

            case 2:
                transpose(a, b);
                printf("\nTranspose Matrix:\n");
                display(b);
                break;

            case 3:
                fastTranspose(a, b);
                printf("\nFast Transpose Matrix:\n");
                display(b);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice");
        }

    } while(choice != 4);

    return 0;
}