#include<bits/stdc++.h>
#include<fstream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int kthLargest(int arr[], int N, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    for (int i = 0; i < N; i++) {
        pq.push(arr[i]);

        if (pq.size() > K)
            pq.pop();
    }

    return pq.top();
}

int main() {
    auto start_time = high_resolution_clock::now();

    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    int n,k;
    input_file >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        input_file >> arr[i];
    }
    output_file << "Kth Largest Element is: " << kthLargest(arr, n, k) << endl;
         
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    output_file << "Time taken: " << duration.count() << " milliseconds" << endl;

    output_file << endl;

    return 0;
}
