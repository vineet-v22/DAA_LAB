#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int B[], int m, int n, int C[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (A[i] <= B[j])
        {
            C[k] = A[i];
            i++;
        }
        else
        {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j < n)
    {
        C[k] = B[j];
        j++;
        k++;
    }
    return;
}

int A[10000000], B[10000000], C[10000000];
int main()
{
    ifstream inputFile("inputa.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening the input file" << endl;
    }
    ofstream outputFile("outputa.txt");
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