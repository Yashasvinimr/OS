#include<stdio.h>
#include<conio.h>
void addition(int a[20][20], int b[20][20], int m, int n)
{
    int i,j;
    int c[20][20];
    for(i=0; i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
             printf("%d \t", c[i][j]);
             if(n==j-1)
             printf("\n");
        }
        }
    }
void subtraction(int a[20][20],  int b[20][20], int m, int n) 
{int i,j;
    int c[20][20];
    for(i=0;i<m; i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t", c[i][j]);
            if(n==j-1)
             printf("\n");
        }
    }
} 
void multiplication(int a[20][20], int b[20][20], int m, int n)
{int i,j,k;
    int c[20][20];
    for(i=0;i<m-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            for(k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
        

    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t", c[i][j]);
            if(n==j-1)
            printf("\n");
        }
    }
}
void transpose(int a[20][20], int b[20][20], int m, int n)
{
    int i,j;
    for(i=0;i<m; i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=a[j][i];
        }
    }
    for(i=0;i<m; i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=b[j][i];
        }
    }
    
}
void main()
{
    int a[20][20], b[20][20], c[20][20], i, j, k,m, n, choice;
    printf("Enter the rows");
    scanf("%d", &m);
    printf("Enter the columns");
    scanf("%d", &n);
    printf("Enter elements to first matrix");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter elements to second matrix ");
    for(i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("1.Addition 2.Subtraction 3. Multiplication 4.Transposition");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: addition(a,b,m, n);
                break;
        case 2: subtraction(a,b, m, n);
                break;
        case 3: multiplication(a,b, m ,n);
                break;
        case 4: transpose(a,b, m, n);
                break;
        
        default:printf("Invalid choice");
                break;

    }
    getch();
}
