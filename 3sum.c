/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.                             MEDIUM   */

#include<stdio.h>

void main()
{
    int n;
    printf("Enter value of n (atleast 3) : ");
    scanf("%d",&n);
    int i,j,arr[n],k,sum;
    printf("Enter %d integers : \n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for (k=j+1;k<n;k++)
            {
                sum = arr[i] + arr[j] + arr[k];
                if (sum==0)
                printf("[%d,%d,%d]",arr[i],arr[j],arr[k]);
            }
        }
    }
}