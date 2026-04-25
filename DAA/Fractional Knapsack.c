#include <stdio.h>

// Structure to store item details
struct Item 
{
    int Weight;      // Weight of item
    int Value;       // Value (profit) of item
    float PPW;       // Profit per weight (Value/Weight)
};

// Function to sort items based on profit/weight ratio (descending order)
void sort(struct Item items[], int n)
{
    struct Item temp;

    // Bubble sort based on PPW
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            // If current item has less ratio than next, swap
            if (items[j].PPW < items[j + 1].PPW)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Display sorted items
    printf("Items sorted by value/weight ratio:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: Weight = %d, Value = %d, Ratio = %.2f\n", 
                i + 1, items[i].Weight, items[i].Value, items[i].PPW);
    }
}

int main() 
{
    int n;
    float capacity;   // Knapsack capacity

    // Taking number of items
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];   // Array of items

    // Taking weight and value of each item
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].Weight, &items[i].Value);

        // Calculate profit per weight
        items[i].PPW = (float)items[i].Value / items[i].Weight;
    }

    // Taking knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items based on profit/weight ratio
    sort(items, n);

    float totalProfit = 0.0;   // To store maximum profit

    // Apply greedy approach
    for (int i = 0; i < n; i++) 
    {
        // If full item can be taken
        if (capacity >= items[i].Weight)
        {
            totalProfit += items[i].Value;     // Add full value
            capacity -= items[i].Weight;       // Reduce capacity
        }
        else
        {
            // Take fractional part of item
            totalProfit += items[i].PPW * capacity;
            capacity = 0;   // Knapsack becomes full
            break;
        }
    }

    // Display final maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
