#include <bits/stdc++.h>
using namespace std;

// Function to add two matrices
vector<vector<int>> matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case: If the matrices are 1x1, perform a simple multiplication
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // Divide matrices into submatrices
    int half = n / 2;
    vector<vector<int>> A11(half, vector<int>(half, 0));
    vector<vector<int>> A12(half, vector<int>(half, 0));
    vector<vector<int>> A21(half, vector<int>(half, 0));
    vector<vector<int>> A22(half, vector<int>(half, 0));
    vector<vector<int>> B11(half, vector<int>(half, 0));
    vector<vector<int>> B12(half, vector<int>(half, 0));
    vector<vector<int>> B21(half, vector<int>(half, 0));
    vector<vector<int>> B22(half, vector<int>(half, 0));

    // Populate submatrices
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Recursive calls
    vector<vector<int>> C11 = matrixAddition(matrixMultiply(A11, B11), matrixMultiply(A12, B21));
    vector<vector<int>> C12 = matrixAddition(matrixMultiply(A11, B12), matrixMultiply(A12, B22));
    vector<vector<int>> C21 = matrixAddition(matrixMultiply(A21, B11), matrixMultiply(A22, B21));
    vector<vector<int>> C22 = matrixAddition(matrixMultiply(A21, B12), matrixMultiply(A22, B22));

    // Combine result submatrices
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + half] = C12[i][j];
            result[i + half][j] = C21[i][j];
            result[i + half][j + half] = C22[i][j];
        }
    }

    return result;
}



// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix,ofstream &outputFile) {
    for (const auto& row : matrix) {
        for (int value : row) {
            outputFile << value << " ";
        }
        outputFile << "\n";
    }
}

int main() {
    ifstream inputFile("question1Input.txt");
    ofstream outputFile("question1Output.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1; 
    }

    if (!outputFile.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    int n;
    inputFile >> n;



    // Example matrices
    vector<vector<int>> a(n,vector<int> (n));
    vector<vector<int>> b(n,vector<int> (n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inputFile>>a[i][j];
        }
    }

    int check;
    inputFile>>check;
    if(n!=check){
        cout<<"The matrices are of unequal sizes\n";
        inputFile.close();
        outputFile.close();
        return 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            inputFile>>b[i][j];
        }
    }
    inputFile.close();

    clock_t begin=clock();
    // Perform matrix multiplication using simple divide-and-conquer approach
    vector<vector<int>> result = matrixMultiply(a, b);

    // Print the result
    outputFile << "Resultant Matrix: \n";
    printMatrix(result,outputFile);
    outputFile.close();
    clock_t finish=clock();
    cout<<"The time taken (in sec) : "<<double(finish-begin)/CLOCKS_PER_SEC<<"\n";
    return 0;
}
