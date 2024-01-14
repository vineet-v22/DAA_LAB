#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream inputFile("Q1_input.txt");

    ofstream outputFile("Q1_output.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    int size;
    inputFile >> size;

    vector<int> a(size);
    for (int i = 0; i < size; ++i)
    {
        inputFile >> a[i];
    }

    inputFile.close();

    if (size < 2)
    {
        cerr << "Error: Array should have at least two elements." << endl;
        return 1;
    }

    sort(a.begin(),a.end());

    outputFile << "Maximum Sum: " << a[size-1]+a[size-2] << endl;

    outputFile.close();

    return 0;
}
