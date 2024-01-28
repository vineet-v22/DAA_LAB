#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Open the output file
    ofstream outputFile("input.txt");

    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int n = 100000; // Number of elements
    outputFile << n << endl; // Write the number of elements to the file

    // Generate and write the array elements to the file
    for (int i = 0; i < n; ++i) {
        int num = rand() % 201 - 100; // Generate random numbers from -100 to 100
        outputFile << num << endl;
    }

    // Close the file
    outputFile.close();

    cout << "Array generated and saved to input.txt" << endl;

    return 0;
}
