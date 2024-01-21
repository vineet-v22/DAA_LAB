#include<bits/stdc++.h>
using namespace std;

void merge(int A[],  int m, int n)
{

    int gap = n / 2 + n % 2;

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < n)
        {
            if (A[left] > A[right])
            {
                swap(A[left], A[right]);
            }
            left++;
            right++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = gap / 2 + gap % 2;
    }
}

int main(){

    ifstream inputFile("input.txt");
    if(!inputFile.is_open()){
        cerr<<"Error opening the input file"<<endl;
    }
    ofstream outputFile("output.txt");
    if(!outputFile.is_open()){
        cerr<<"Error opening the output file"<<endl;
    }

    int n,m;
    inputFile>>n>>m;

    int *A = new int[n];
    for(int i=0;i<n;i++){inputFile>>A[i];}
    inputFile.close();

    clock_t start,end;
    start=clock();
    merge(A,m,n);
    end=clock();

    outputFile<<"The complete sorted array : "<<endl;
    for(int i=0;i<n;i++){
        outputFile<<A[i]<<" ";
    }
    outputFile<<endl;
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    outputFile<<"The time taken to run the program is: "<<time_taken<<" sec"<<endl;
}