#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

double median(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    if (n > m)
    {
        return median(nums2, nums1);
    }
    int low = 0, high = n;
    int left = (n + m + 1) / 2;
    int t = n + m;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT32_MIN, l2 = INT32_MIN;
        int r1 = INT32_MAX, r2 = INT32_MAX;
        if (mid1 < n)
        {
            r1 = nums1[mid1];
        }
        if (mid2 < m)
        {
            r2 = nums2[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = nums1[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = nums2[mid2 - 1];
        }
        if (l1 <= r2 && l2 <= r1)
        {
            if (t & 1)
            {
                return max(l1, l2);
            }
            return ((double)(max(l1, l2) + min(r1, r2)) / 2.0);
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
}

int main()
{
    auto start_time = high_resolution_clock::now();

    ifstream input_file("input.txt");
    ofstream output_file("output.txt");

    int n, m;
    input_file >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++)
    {
        input_file >> nums1[i];
    }
    for (int i = 0; i < m; i++)
    {
        input_file >> nums2[i];
    }

    output_file <<"Median of the two sorted arrys is :"<< median(nums1, nums2) << endl;
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    output_file << "Time taken: " << duration.count() << " milliseconds" << endl;

    output_file << endl;

    return 0;
}