#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack problem using dynamic programming
int knapsackDP(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP array with (n+1) rows and (capacity+1) columns
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Include the item or exclude it, choose the maximum value
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // Exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is in the bottom-right cell
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> weights(n), values(n);
    cout << "Enter weights and values of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " (Weight Value): ";
        cin >> weights[i] >> values[i];
    }

    int maxProfit = knapsackDP(capacity, weights, values, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
