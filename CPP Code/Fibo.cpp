#include <iostream>
#include <vector>
using namespace std;

// Iterative function to calculate Fibonacci sequence up to n terms and count steps
vector<int> fibonacciIterative(int n, int &stepCount) {
    vector<int> sequence; 
    if (n >= 1) sequence.push_back(0);
    if (n >= 2) sequence.push_back(1);

    int a = 0, b = 1, fib = 0;
    for (int i = 2; i < n; i++) {
        fib = a + b;
        sequence.push_back(fib);
        a = b;
        b = fib;
        stepCount++;  // Count each iteration as a step
    }

    stepCount += (n >= 1 ? 1 : 0);  // Count the initial steps for 0 and 1
    return sequence;
}

// Recursive function to calculate Fibonacci numbers up to n terms and count steps
int fibonacciRecursive(int n, vector<int> &sequence, int &stepCount) {
    stepCount++;  // Count each function call as a step
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursive(n - 1, sequence, stepCount) + fibonacciRecursive(n - 2, sequence, stepCount);
}

// Wrapper function to get the recursive Fibonacci sequence up to n terms
void generateFibonacciRecursive(int n, vector<int> &sequence, int &stepCount) {
    for (int i = 0; i < n; i++) {
        sequence.push_back(fibonacciRecursive(i, sequence, stepCount));
    }
}

int main() {
    int n;
    cout << "Enter the number of terms for the Fibonacci sequence: ";
    cin >> n;

    // Iterative approach
    int stepCountIter = 0;
    vector<int> fibIterSequence = fibonacciIterative(n, stepCountIter);
    cout << "\nIterative approach:\n";
    cout << "Fibonacci sequence: ";
    for (int num : fibIterSequence) {
        cout << num << " ";
    }
    cout << "\nStep count: " << stepCountIter << "\n";

    // Recursive approach
    int stepCountRec = 0;
    vector<int> fibRecSequence;
    generateFibonacciRecursive(n, fibRecSequence, stepCountRec);
    cout << "\nRecursive approach:\n";
    cout << "Fibonacci sequence: ";
    for (int num : fibRecSequence) {
        cout << num << " ";
    }
    cout << "\nStep count: " << stepCountRec << "\n";

    return 0;
}