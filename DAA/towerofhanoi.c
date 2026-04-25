#include<stdio.h>

// Function for Tower of Hanoi
void TOH(int n, char s, char t, char d)
{
    // Base condition: if only 1 disk, move directly
    if(n==1)
    {
        printf("move %d from %c to %c :\n", n, s, d);
        return;
    }

    // Step 1: move n-1 disks from source to temporary using destination
    TOH(n-1, s, d, t);

    // Step 2: move nth (largest) disk from source to destination
    printf("move %d from %c to %c:\n", n, s, d);

    // Step 3: move n-1 disks from temporary to destination using source
    TOH(n-1, t, s, d);
}

int main()
{
    int n;

    // Taking input from user
    printf("enter number of disks:");
    scanf("%d", &n);

    // Calling function with s=source, t=temporary, d=destination
    TOH(n, 's', 't', 'd');

    return 0;
}
