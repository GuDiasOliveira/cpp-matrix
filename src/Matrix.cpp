#include "Matrix.hpp"


Matrix::Matrix() : m_mat(nullptr), m_rows(0), m_cols(0)
{
}


Matrix::Matrix(int rows, int cols, double** matrix) : m_rows(rows), m_cols(cols), m_mat(new double[rows*cols])
{
    int size = rows * cols;
    for (int i = 0; i < size; i++)
        m_mat[i] = matrix == nullptr ? 0 : matrix[i/cols][i%cols];
}


Matrix::Matrix(int rows, int cols) : Matrix(rows, cols, nullptr)
{
}


Matrix::Matrix(const Matrix &obj) : m_rows(obj.m_rows), m_cols(obj.m_cols), m_mat(new double[obj.m_rows * obj.m_cols])
{
    int size = m_rows * m_cols;
    for (int i = 0; i < size; i++)
        m_mat[i] = obj.m_mat[i];
}


double* Matrix::operator[](int row) const
{
    return m_mat + (row * m_cols);
}


double** Matrix::getMatrix() const
{
    double** matrix = new double*[m_rows];
    int size = m_rows * m_cols;
    for (int i = 0; i < size; i++)
    {
        if (i % m_cols == 0)
            matrix[i/m_cols] = new double[m_cols];
        matrix[i/m_cols][i%m_cols] = m_mat[i];
    }
    return matrix;
}


Matrix::~Matrix()
{
    delete[] m_mat;
}
