#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Function to allocate memory for a matrix
Matrix createMatrix(int size) {
    return Matrix(size, vector<int>(size, 0));
}

// Function to add two matrices
Matrix addMatrix(const Matrix &A, const Matrix &B) {
    int size = A.size();
    Matrix result = createMatrix(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Function to subtract two matrices
Matrix subtractMatrix(const Matrix &A, const Matrix &B) {
    int size = A.size();
    Matrix result = createMatrix(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Strassen's multiplication function
Matrix strassen(const Matrix &A, const Matrix &B) {
    int size = A.size();
    
    // Base case: If the matrix is 1x1, multiply directly
    if (size == 1) {
        Matrix C(1, vector<int>(1, A[0][0] * B[0][0]));
        return C;
    }

    int newSize = size / 2;
    
    // Splitting matrices into 4 submatrices
    Matrix A11(newSize, vector<int>(newSize));
    Matrix A12(newSize, vector<int>(newSize));
    Matrix A21(newSize, vector<int>(newSize));
    Matrix A22(newSize, vector<int>(newSize));
    Matrix B11(newSize, vector<int>(newSize));
    Matrix B12(newSize, vector<int>(newSize));
    Matrix B21(newSize, vector<int>(newSize));
    Matrix B22(newSize, vector<int>(newSize));

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Computing 7 products using Strassen’s formula
    Matrix P1 = strassen(A11, subtractMatrix(B12, B22)); // P1 = A11 * (B12 - B22)
    Matrix P2 = strassen(addMatrix(A11, A12), B22);      // P2 = (A11 + A12) * B22
    Matrix P3 = strassen(addMatrix(A21, A22), B11);      // P3 = (A21 + A22) * B11
    Matrix P4 = strassen(A22, subtractMatrix(B21, B11)); // P4 = A22 * (B21 - B11)
    Matrix P5 = strassen(addMatrix(A11, A22), addMatrix(B11, B22)); // P5 = (A11 + A22) * (B11 + B22)
    Matrix P6 = strassen(subtractMatrix(A12, A22), addMatrix(B21, B22)); // P6 = (A12 - A22) * (B21 + B22)
    Matrix P7 = strassen(subtractMatrix(A11, A21), addMatrix(B11, B12)); // P7 = (A11 - A21) * (B11 + B12)

    // Computing final quadrants
    Matrix C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    Matrix C12 = addMatrix(P1, P2);
    Matrix C21 = addMatrix(P3, P4);
    Matrix C22 = subtractMatrix(subtractMatrix(addMatrix(P5, P1), P3), P7);

    // Combining the result quadrants into the final matrix C
    Matrix C(size, vector<int>(size));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const Matrix &matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// Main function
int main() {
    int size = 4; // Matrix size (must be a power of 2)

    // Initialize matrices
    Matrix A(size, vector<int>(size));
    Matrix B(size, vector<int>(size));

    cout << "Matrix A:" << endl;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            A[i][j] = i + j;
            B[i][j] = (i + 1) * (j + 1);
        }

    printMatrix(A);
    
    cout << "\nMatrix B:" << endl;
    printMatrix(B);

    // Perform Strassen's multiplication
    Matrix C = strassen(A, B);

    // Display the result
    cout << "\nResultant Matrix C (A * B):" << endl;
    printMatrix(C);

    return 0;
}
