#include <stdio.h>

// Function to find nth Fibonacci number using recursion
int fib(int n) 
{ 
    // Base condition: if n is 0 or 1, return n itself
    if (n <= 1) 
    { 
        return n; 
    } 

    // Recursive case: sum of previous two numbers
    return fib(n - 1) + fib(n - 2); 
} 

int main() 
{ 
    int n;

    // Taking input from user
    printf("Enter the value of n: "); 
    scanf("%d", &n); 

    // Check if input is valid (non-negative)
    if (n < 0) 
    { 
        printf("Invalid input\n"); 
        return 1; 
    } 

    // Print nth Fibonacci number
    printf("\nNth Fibonacci term = %d\n", fib(n)); 

    return 0; 
}
