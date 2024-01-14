#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    
    ifstream inputFile("Q2_input.txt");
    ofstream outputFile("Q2_output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1; 
    }

    int W, n;
    inputFile >> W >> n;

    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        inputFile >> weights[i] >> values[i];
    }

    inputFile.close();

    int maxValue = knapsack(W, weights, values, n);

    outputFile << "Maximum Value: " << maxValue << endl;

    outputFile.close();


    return 0; 
}
