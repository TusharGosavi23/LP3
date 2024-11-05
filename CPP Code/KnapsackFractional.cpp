#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Function to solve the fractional knapsack problem
double fractionalKnapsack(const vector<double>& weights, const vector<double>& values, double capacity) {
    if (weights.size() != values.size()) {
        throw invalid_argument("Weights and values must be of the same length.");
    }

    // Create a vector of pairs to hold weights and values together
    vector<pair<double, double>> items;
    for (size_t i = 0; i < weights.size(); ++i) {
        items.push_back({weights[i], values[i]});
    }

    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), [](const pair<double, double>& a, const pair<double, double>& b) {
        return (b.second / b.first) < (a.second / a.first);
    });

    double maxProfit = 0.0;

    for (const auto& item : items) {
        if (capacity <= 0) break;

        if (item.first <= capacity) {
            maxProfit += item.second;
            capacity -= item.first;
        } else {
            maxProfit += item.second * (capacity / item.first);
            capacity = 0;
        }
    }

    return maxProfit;
}

int main() {
    int num_items;
    cout << "Enter the number of items: ";
    cin >> num_items;

    vector<double> weights(num_items);
    vector<double> values(num_items);

    cout << "Enter the weights (space-separated): ";
    for (int i = 0; i < num_items; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values (space-separated): ";
    for (int i = 0; i < num_items; ++i) {
        cin >> values[i];
    }

    double capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    try {
        double max_value = fractionalKnapsack(weights, values, capacity);
        cout << "Maximum value in the knapsack: " << max_value << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}