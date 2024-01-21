/*   Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target. You may assume that each input would 
have exactly one solution, and you may not use the same element twice. 
You can return the answer in any order.                                                     EASY      */

#include<stdio.h>
void main()
{
    int n,i;
    printf("Enter no. of elements in the array \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of the array \n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int s,j,target;
    int c = 0;
    printf("Enter Target value : ");
    scanf("%d",&target);
    for (i=0;i<n;i++)
    {
        s = 0;
        for (j=0;j<n;j++)
        {
            if (i!=j)
            {
                s = arr[i] + arr[j];
                if (s==target)
                {
                    printf("Elements at index %d and %d add up to become %d\n",i,j,target);
                    c++;
                    break;
                }
            }
        }
        if (c>0)
        break;
    }
    if (c==0)
    printf("No two elements add up to become %d",target);
}