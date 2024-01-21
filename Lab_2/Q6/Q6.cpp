#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int median(int a, int b, int c){
    if ((a <= b && b <= c) || (c <= b && b <= a)){
        return b;
    }
    else if ((b <= a && a <= c) || (c <= a && a <= b)){
        return a;
    }
    else{
        return c;
    }
}

int partition(int A[], int low, int high){
    int pivot = median(A[low], A[(low + high) / 2], A[high]);
    while (true) {
        while (A[low] < pivot) {
            low++;
        }
        while (A[high] > pivot) {
            high--;
        }
        if (low >= high) {
            return high;
        }
        swap(A[low], A[high]);
        low++;
        high--;
    }
}

void quickSort(int A[], int low, int high){
    if (low < high) {
        int pi = partition(A, low, high);
        quickSort(A, low, pi);
        quickSort(A, pi + 1, high);
    }
}

int main(){
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    int n;
    infile >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        infile >> A[i];
    }

    auto start = high_resolution_clock::now();
    quickSort(A, 0, n - 1);
    auto stop = high_resolution_clock::now();

    // Write the sorted array to output.txt
    for (int i = 0; i < n; i++) {
        outfile << A[i] << " ";
    }

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
