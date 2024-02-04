#include<bits/stdc++.h>
#include<fstream>
#include<chrono>
using namespace std;
using namespace std::chrono;

long long merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;     
    int right = mid + 1;   

    long long cnt = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); 
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }


    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }


    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; 
}

long long mergeSort(vector<int> &arr, int low, int high) {
    long long cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  
    cnt += mergeSort(arr, mid + 1, high); 
    cnt += merge(arr, low, mid, high);  
    return cnt;
}

long long numberOfInversions(vector<int>&a, int n) {

    return mergeSort(a, 0, n - 1);
}

int main() {
    auto start_time = high_resolution_clock::now();

    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    int n;
    input_file >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        input_file >> v[i];
    }
    long long cnt = numberOfInversions(v, n);
    output_file<<"The number of inversions are: "
         << cnt << endl;
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    output_file << "Time taken: " << duration.count() << " milliseconds" << endl;

    output_file << endl;

    return 0;
}
