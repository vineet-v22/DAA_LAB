#include <bits/stdc++.h>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int max_subarray_crossing(vector<int> &A, int s, int mid, int e)
{
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= s; i--)
    {
        sum += A[i];
        left_sum = max(left_sum, sum);
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= e; i++)
    {
        sum += A[i];
        right_sum = max(right_sum, sum);
    }

    return left_sum + right_sum;
}

int max_subarray(vector<int> &A, int s, int e)
{
    if (s == e)
    {
        return A[s];
    }

    int mid = (s + e) / 2;

    int lss = max_subarray(A, s, mid);
    int rss = max_subarray(A, mid + 1, e);
    int css = max_subarray_crossing(A, s, mid, e);

    return max({lss, rss, css});
}

int main()
{
    auto start_time = high_resolution_clock::now();

    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    int n;
    input_file >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        input_file >> A[i];
    }
    int ans = max_subarray(A, 0, n - 1);

    output_file << " Maximum sum of subarray is: " << ans << endl;

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    output_file << "Time taken: " << duration.count() << " milliseconds" << endl;

    output_file << endl;

    return 0;
}
