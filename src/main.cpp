#include<iostream>

#include "Matrix.hpp"

using namespace std;


int main()
{
    // The user will input the quantity of rows and of columns of the matrix
    int rows, cols;
    cout << "Rows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;

    // The user will fill the matrix
    Matrix mat(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << i << " x " << j << " = ";
            cin >> mat[i][j];
        }
    }

    // Printing the matrix
    cout << "Matrix" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << "\t" << mat[i][j];
        cout << endl;
    }

    // Testing matrix copy and getMatrix method
    Matrix matCp = mat;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matCp[i][j]++;
            if (mat[i][j] != mat.getMatrix()[i][j] || mat[i][j] != (matCp[i][j] - 1))
                cerr << "Assertion failed!!" << endl;
        }
    }

    return 0;
}
