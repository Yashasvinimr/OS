#include <stdio.h>
#include <stdlib.h>
#define max 25

void readInput(int *nb, int *nf, int b[], int f[]);
void bestFit(int nb, int nf, int b[], int f[], int bf[], int ff[]);
void worstFit(int nb, int nf, int b[], int f[], int bf[], int ff[]);
void firstFit(int nb, int nf, int b[], int f[], int bf[], int ff[]);
void displayResults(int nf, int f[], int ff[], int b[]);

int main()
{
    int nb, nf, ch;
    int b[max], f[max], bf[max] = {0}, ff[max] = {0};
    readInput(&nb, &nf, b, f);
    printf("1.Best Fit 2.Worst Fit 3.First Fit 4. Exit\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        bestFit(nb, nf, b, f, bf, ff);
        break;
    case 2:
        worstFit(nb, nf, b, f, bf, ff);
        break;
    case 3:
        firstFit(nb, nf, b, f, bf, ff);
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    displayResults(nf, f, ff, b);
    return 0;
}

void readInput(int *nb, int *nf, int b[], int f[])
{
    int i;
    printf("Enter the number of Holes:");
    scanf("%d", nb);

    printf("Enter the number of requests:");
    scanf("%d", nf);

    printf("\nEnter the size of the holes:\n");
    for (i = 1; i <= *nb; i++)
    {
        printf("Hole %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the size of the requests:\n");
    for (i = 1; i <= *nf; i++)
    {
        printf("Request %d:", i);
        scanf("%d", &f[i]);
    }
}

void bestFit(int nb, int nf, int b[], int f[], int bf[], int ff[])
{
    int i, j, temp, lowest = 10000;

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1) //if bf[j] is not allocated
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    if (lowest > temp)
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        bf[ff[i]] = 1;
        lowest = 10000;
    }
}

void worstFit(int nb, int nf, int b[], int f[], int bf[], int ff[])
{
    int i, j, temp, lowest = 10000;

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    if (lowest == 10000 || temp > lowest)
                    {
                        ff[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        bf[ff[i]] = 1;
        lowest = 10000;
    }
}

void firstFit(int nb, int nf, int b[], int f[], int bf[], int ff[])
{
    int i, j, temp;

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (bf[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        bf[ff[i]] = 1;
    }
}

void displayResults(int nf, int f[], int ff[], int b[])
{
    int i;

    printf("\nFile_no\t\tFile_size\tBlock_no\tBlock_size");
    for (i = 1; i <= nf; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]]);
    }
}
