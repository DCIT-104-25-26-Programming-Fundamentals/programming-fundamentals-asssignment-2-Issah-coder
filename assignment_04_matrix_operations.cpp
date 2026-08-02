// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<int>> create_matrix(int row_number, int column_number)
{
    vector<vector<int>> matrix;

    for (int i = 0; i < row_number; i++)
    {
        vector<int> row;
        cout << "Enter row " << i + 1 << ": ";

        for (int j = 0; j < column_number; j++)
        {
            int value;
            cin >> value;
            row.push_back(value);
        }

        matrix.push_back(row);
    }

    return matrix;
}

void print_matrix(vector<vector<int>> matrix)
{
    if (!matrix.empty())
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "-------------" << endl;
    }
}

vector<vector<int>> transpose(vector<vector<int>> matrix)
{
    vector<vector<int>> transpose_matrix;

    for (int i = 0; i < matrix[0].size(); i++)
    {
        transpose_matrix.push_back(vector<int>());
    }

    for (int i = 0; i < matrix[0].size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            transpose_matrix[i].push_back(matrix[j][i]);
        }
    }

    return transpose_matrix;
}

vector<vector<int>> add_matrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    vector<vector<int>> added_matrix;

    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size())
    {
        cout << "Matrix Size do not match. Must be of equal size (MxN)" << endl;
        return added_matrix;
    }

    for (int i = 0; i < matrix1.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            row.push_back(matrix1[i][j] + matrix2[i][j]);
        }
        added_matrix.push_back(row);
    }

    return added_matrix;
}

vector<vector<int>> multiply_matrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    vector<vector<int>> multiplied_matrix;

    if (matrix1[0].size() != matrix2.size())
    {
        cout << "Both matrices cannot multiply." << endl;
        return multiplied_matrix;
    }

    for (int i = 0; i < matrix1.size(); i++)
    {
        vector<int> row;

        for (int j = 0; j < matrix2[0].size(); j++)
        {
            int sum = 0;

            for (int k = 0; k < matrix1[0].size(); k++)
            {
                sum += matrix1[i][k] * matrix2[k][j];
            }

            row.push_back(sum);
        }

        multiplied_matrix.push_back(row);
    }

    return multiplied_matrix;
}

int main()
{
    int row_number, column_number;

    cout << "Enter number of rows: ";
    cin >> row_number;

    cout << "Enter number of columns: ";
    cin >> column_number;

    vector<vector<int>> matrix = create_matrix(row_number, column_number);

    vector<vector<int>> transpose_matrix = transpose(matrix);

    vector<vector<int>> added_matrix = add_matrix(matrix, transpose_matrix);

    vector<vector<int>> multiplied_matrix = multiply_matrix(matrix, transpose_matrix);

    print_matrix(matrix);
    print_matrix(transpose_matrix);
    print_matrix(added_matrix);
    print_matrix(multiplied_matrix);

    return 0;
}
