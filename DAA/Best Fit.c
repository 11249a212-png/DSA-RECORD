#include <stdio.h>

// Function to implement Best Fit Algorithm
void bestFit(int items[], int n, int capacity) 
{
    printf("\nBest Fit Algorithm\n");

    int bin[n];        // Array to store remaining space in bins
    int binCount = 0;  // Number of bins used

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++) 
    {
        bin[i] = capacity;
    }

    // Loop through each item
    for (int i = 0; i < n; i++) 
    {
        int bestIndex = -1;        // Stores best bin index
        int minSpace = capacity + 1; // To find minimum leftover space

        // Check all existing bins
        for (int j = 0; j < binCount; j++) 
        {
            // If item fits and leaves minimum space, choose that bin
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace) 
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If suitable bin is found
        if (bestIndex != -1) 
        {
            bin[bestIndex] -= items[i];   // Reduce remaining space
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], bestIndex + 1);
        } 
        else 
        {
            // Create new bin if no suitable bin found
            bin[binCount] = capacity - items[i];
            printf("Item %d (Weight: %d) placed in Bin %d\n", i + 1, items[i], binCount + 1);
            binCount++;
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

    // Taking bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // Taking item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++) 
    {
        int itemSize;

        printf("Item %d: ", i + 1);
        scanf("%d", &itemSize);

        // Validate input (item size should not exceed capacity)
        if (itemSize <= capacity)
        {
            items[i] = itemSize;
        } 
        else 
        {
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--;   // Repeat same index
        }
    }

    // Call Best Fit function
    bestFit(items, n, capacity);

    return 0;
}
