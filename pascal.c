/*                1                   
                 1 1
                1 2 1
               1 3 3 1
              1 4 6 4 1
             1 5 10 10 5 1     
             
PASCAL  TRIANGLE                 */

#include<stdio.h>

int factorial(int x)
{
    int p=1,i;
    for (i=2;i<=x;i++)
    {
        p = p*i;
    }
    return p;
}

int combination(int n , int r)
{
    int c = factorial(n) / (factorial(r) * factorial(n-r));
    return c;
}

int main()
{
    int i,j,k,n,no;
    printf("Enter no. of rows : ");
    scanf("%d",&no);
    n = no-1;
    for (i=0;i<=n;i++)
    {
        for (j=n-1;j>=i;j--)
        {
            printf(" ");
        }
        for (k=0;k<=i;k++)
        {
            int p = combination(i,k);
            printf("%d ",p);
        }
        printf("\n");
    }
    return 0;
}