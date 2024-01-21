#include <bits/stdc++.h>
using namespace std;

int merge(int A[], int B[], int m, int n, int C[])
{
    int i = 0, j = 0, k = 0;
    map<int, int> mp;
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            if (mp[A[i]] == 0)
            {
                mp[A[i]] = 1;
                C[k] = A[i];
                k++;
            }
            i++;
        }
        else
        {
            if (mp[B[j]] == 0)
            {
                mp[B[j]] = 1;
                C[k] = B[j];
                k++;
            }
            j++;
        }
    }
    while (i < m)
    {
        if (mp[A[i]] == 0)
        {
            mp[A[i]] = 1;
            C[k] = A[i];
            k++;
        }
        i++;
    }
    while (j < n)
    {
        if (mp[B[j]] == 0)
        {
            mp[B[j]] = 1;
            C[k] = B[j];
            k++;
        }
        j++;
    }
    return k;
}

int A[10000000], B[10000000], C[10000000];
int main()
{
    ifstream inputFile("inputb.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening the input file" << endl;
    }
    ofstream outputFile("outputb.txt");
    if (!outputFile.is_open())
    {
        cerr << "Error opening the output file" << endl;
    }
    int m, n;
    inputFile >> m >> n;
    for (int i = 0; i < m; i++)
    {
        inputFile >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        inputFile >> B[i];
    }
    clock_t start, end;
    start = clock();
    merge(A, B, m, n, C);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    outputFile << "The time taken to run the program is: " << time_taken << " sec for " << n << " elements" << endl;
    for (int i = 0; i < n + m; i++)
    {
        outputFile << C[i] << " ";
    }
    outputFile << endl;
    return 0;
}