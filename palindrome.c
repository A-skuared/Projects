/*return true if no. is palindrome                         EASY*/
#include<stdio.h>
#include<stdbool.h>
bool palindrome(int n) {
    int t = n;
    int d, rev = 0;
    while (t > 0) {
        d = t % 10;
        rev = rev * 10 + d;
        t = t / 10;
    }
    if (rev == n)
        return true;
    else
        return false;
}

void main() {
    int n;
    printf("Enter a number :");
    scanf("%d", &n);
    int a = palindrome(n);
    if (a == 1)
        printf("Palindrome ");
    else
        printf("Not Palindrome");
}