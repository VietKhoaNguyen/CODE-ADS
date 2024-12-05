#include <limits.h>  // For INT_MAX

int maxProfit(int* prices, int pricesSize) {
    // Initialize the minimum price to a large number and max profit to 0
    int min_price = INT_MAX;
    int max_profit = 0;
    
    // Loop through the prices
    for (int i = 0; i < pricesSize; i++) {
        // Update the minimum price if a new lower price is found
        if (prices[i] < min_price) {
            min_price = prices[i];
        }#include <limits.h>  // For INT_MAX

int maxProfit(int* prices, int pricesSize) {
    // Initialize the minimum price to a large number and max profit to 0
    int min_price = INT_MAX;
    int max_profit = 0;
    
    // Loop through the prices
    for (int i = 0; i < pricesSize; i++) {
        // Update the minimum price if a new lower price is found
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        
        // Calculate the current profit
        int current_profit = prices[i] - min_price;
        
        // Update the maximum profit if the current profit is higher
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }
    
    return max_profit;
}
/*recur O(n)
#include <limits.h>  // For INT_MAX

// Recursive helper function
int maxProfitHelper(int* prices, int pricesSize, int index, int min_price, int max_profit) {
    // Base case: If we have processed all the prices
    if (index == pricesSize) {
        return max_profit;
    }
    
    // Update the minimum price if a new lower price is found
    if (prices[index] < min_price) {
        min_price = prices[index];
    }
    
    // Calculate the current profit
    int current_profit = prices[index] - min_price;
    
    // Update the maximum profit if the current profit is higher
    if (current_profit > max_profit) {
        max_profit = current_profit;
    }

    // Recurse with the next index
    return maxProfitHelper(prices, pricesSize, index + 1, min_price, max_profit);
}

// Main recursive function
int maxProfit(int* prices, int pricesSize) {
    // Initialize the minimum price to a large number and max profit to 0
    return maxProfitHelper(prices, pricesSize, 0, INT_MAX, 0);
}
*/
        
        // Calculate the current profit
        int current_profit = prices[i] - min_price;
        
        // Update the maximum profit if the current profit is higher
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
    }
    
    return max_profit;
}
