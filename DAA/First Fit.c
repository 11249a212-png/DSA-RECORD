#include <stdio.h>

// Function to implement First Fit Algorithm
void firstFit(int items[], int n, int capacity) 
{
    int bin[n];        // Array to store remaining space in bins
    int binCount = 0;  // Number of bins used

    printf("\nExecuting First Fit Algorithm\n");

    // Initialize all bins to 0 (not necessary but good practice)
    for (int i = 0; i < n; i++) 
    {
        bin[i] = 0;
    }

    // Loop through each item
    for (int i = 0; i < n; i++) 
    {
        // If item size is greater than bin capacity, cannot place
        if (items[i] > capacity) 
        {
            printf("Item %d with size %d cannot be placed in any bin\n", i + 1, items[i]);
            continue;
        }

        int placed = 0;  // Flag to check if item is placed

        // Check all existing bins
        for (int j = 0; j < binCount; j++) 
        {
            // If item fits in current bin
            if (bin[j] >= items[i]) 
            {
                bin[j] -= items[i];   // Reduce remaining space
                printf("Item %d placed in Bin %d\n", items[i], j + 1);
                placed = 1;
                break;
            }
        }

        // If item not placed in any bin, create new bin
        if (!placed) 
        {
            bin[binCount] = capacity;      // Initialize new bin
            bin[binCount] -= items[i];     // Place item
            printf("Item %d placed in Bin %d\n", items[i], binCount + 1);
            binCount++;   // Increase bin count
        }
    }

    // Print total bins used
    printf("Total bins used = %d\n", binCount);
}

int main() 
{
    int n, capacity;

    // Taking number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];   // Array to store item sizes

    // Taking item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    // Taking bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // Call First Fit function
    firstFit(items, n, capacity);

    return 0;
}
