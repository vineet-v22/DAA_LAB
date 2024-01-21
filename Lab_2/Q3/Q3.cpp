#include<bits/stdc++.h>
#include<fstream>
#include<chrono>

using namespace std;
using namespace std::chrono;

void merge(int A[], int start, int end) {
    int n = (end - start + 1);
    int gap = n / 2 + n % 2;

    while (gap > 0) {
        int left = start;
        int right = left + gap;
        while (right <= end) {
            if (A[left] > A[right]) {
                swap(A[left], A[right]);
            }
            left++;
            right++;
        }
        if (gap == 1) {
            break;
        }
        gap = gap / 2 + gap % 2;
    }
}

void mergesort(int A[], int n, int start, int end) {
    if (end <= start) {
        return;
    }
    int mid = start + (end - start) / 2;
    mergesort(A, mid - start + 1, start, mid);
    mergesort(A, end - mid, mid + 1, end);
    merge(A, start, end);
}

int main() {
    auto start_time = high_resolution_clock::now();

    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    int n;
    input_file >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        input_file >> A[i];
    }

    mergesort(A, n, 0, n - 1);

    for (int i = 0; i < n; i++) {
        output_file << A[i] << " ";
    }
    output_file << endl;

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    cout << "Time taken: " << duration.count() << " milliseconds" << endl;

    return 0;
}
