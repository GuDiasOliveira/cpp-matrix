#ifndef MATRIX_H
#define MATRIX_H


class Matrix
{
    private:
        double* const m_mat;
        const int m_rows, m_cols;

    public:
        Matrix();
        Matrix(int rows, int cols, double** matrix);
        Matrix(int rows, int cols);
        Matrix(const Matrix &obj); // copy constructor
        double* operator[](int row) const;
        double** getMatrix() const;
        virtual ~Matrix();
};


#endif // MATRIX_H
