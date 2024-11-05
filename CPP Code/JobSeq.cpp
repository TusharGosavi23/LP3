#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a job with id, deadline, and profit
struct Job {
    int id;         // Job ID
    int deadline;   // Deadline of the job
    int profit;     // Profit if job is completed before or on deadline
};

// Comparator function to sort jobs in descending order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs to maximize total profit
int jobSequencing(vector<Job> &jobs, int &maxProfit) {
    // Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    int maxDeadline = 0;

    // Find the maximum deadline among all jobs
    for (const auto &job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    // Array to keep track of free time slots
    vector<int> slot(maxDeadline + 1, -1);  // -1 indicates the slot is free

    int jobCount = 0;  // Number of jobs scheduled
    maxProfit = 0;     // Initialize max profit

    // Iterate over each job in sorted order
    for (const auto &job : jobs) {
        // Find a free slot for this job (starting from its deadline)
        for (int j = job.deadline; j > 0; j--) {
            // If slot is free, schedule the job
            if (slot[j] == -1) {
                slot[j] = job.id;   // Assign job to the slot
                jobCount++;         // Increment count of jobs scheduled
                maxProfit += job.profit; // Add profit
                break;
            }
        }
    }

    return jobCount;  // Return the number of jobs scheduled
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job ID, deadline, and profit for each job:\n";
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << " (ID Deadline Profit): ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    int maxProfit;
    int jobCount = jobSequencing(jobs, maxProfit);

    cout << "Number of jobs scheduled: " << jobCount << endl;
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
