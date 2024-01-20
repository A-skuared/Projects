/*You are given an integer array height of length n. There are n vertical lines 
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, 
such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.                                       MEDIUM     */

#include<stdio.h>

void main()
{
    int i,j,n;
    printf("Enter value of n : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter %d elements : \n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max  = 1*arr[0];
    int min;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (arr[i]<arr[j])
            min = arr[i];
            else
            min = arr[j];
            int a = (j-i)*min;
            if (max<a)
            max = a;
        }
    }
    printf("Maximum Volume contained is : %d",max);
}
