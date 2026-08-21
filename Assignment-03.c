#include <stdio.h>
#include <string.h>

#define MAX 100

struct student
{
    int roll;
    char name[20];
    float marks;
};

void display(struct student s[], int n)
{
    int i;
    printf("\nRoll No\tName\tMarks\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%.2f\n",
               s[i].roll, s[i].name, s[i].marks);
    }
}

void linear_search(struct student s[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (s[i].roll == key)
        {
            printf("\nRecord found:\n");
            printf("Roll No: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            return;
        }
    }

    printf("\nRecord not found.\n");
}

void binary_search(struct student s[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s[mid].roll == key)
        {
            printf("\nStudent found:\n");
            printf("Roll No: %d\n", s[mid].roll);
            printf("Name: %s\n", s[mid].name);
            printf("Marks: %.2f\n", s[mid].marks);
            return;
        }
        else if (s[mid].roll < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("\nStudent not found.\n");
}

void insertion_sort(struct student s[], int n)
{
    int i, j;
    struct student temp;

    for (i = 1; i < n; i++)
    {
        temp = s[i];
        j = i - 1;

        while (j >= 0 && s[j].roll > temp.roll)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = temp;
    }
}

void selection_sort(struct student s[], int n)
{
    int i, j, min;
    struct student temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (s[j].roll < s[min].roll)
                min = j;
        }

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

void shell_sort(struct student s[], int n)
{
    int gap, i, j;
    struct student temp;

    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = s[i];

            for (j = i; j >= gap && s[j - gap].roll > temp.roll; j -= gap)
            {
                s[j] = s[j - gap];
            }

            s[j] = temp;
        }
    }
}

int main()
{
    struct student s[MAX];
    int n, i, choice, key;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }
        printf("\n1. Display");
        printf("\n2. Linear Search");
        printf("\n3. Binary Search");
        printf("\n4. Insertion Sort");
        printf("\n5. Selection Sort");
        printf("\n6. Shell Sort");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display(s, n);
                break;

            case 2:
                printf("Enter Roll No to search: ");
                scanf("%d", &key);
                linear_search(s, n, key);
                break;

            case 3:
                insertion_sort(s, n);

                printf("Enter Roll No to search: ");
                scanf("%d", &key);

                binary_search(s, n, key);
                break;

            case 4:
                insertion_sort(s, n);
                display(s, n);
                break;

            case 5:
                selection_sort(s, n);
                display(s, n);
                break;

            case 6:
                shell_sort(s, n);
                display(s, n);
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    return 0;
}