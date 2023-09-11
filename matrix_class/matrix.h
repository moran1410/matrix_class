#pragma once

#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include <stdexcept>




template <typename T, int Rows, int Cols>
class Matrix {

public:
    // constructor
    Matrix(T defaultValue = T());

    // Matrix operator+(const Matrix &);

    //virtual function for inherited class to access private members, returns a reference to private member
    virtual void* accessData(int row, int col) { return &data_[row][col]; };

    // operators
    friend std::ostream& operator <<(std::ostream& out, const Matrix<T, Rows, Cols>& m) {
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                out << m.data_[i][j] << " ";
            }
            out << std::endl;

        }

        out << std::endl;

        return out;
    }

    Matrix operator=(const Matrix&);

    Matrix operator+(const Matrix& other) const;

    Matrix& operator+=(const Matrix& other);

    template <int Rows2, int Cols2>
    Matrix<T, Cols, Rows2> operator*(const Matrix<T, Rows2, Cols2>& other) const;

    Matrix<T, Rows, Cols> operator*(const T& scalar) const;

    bool operator==(const Matrix<T, Rows, Cols>& other) const;

    bool operator!=(const Matrix<T, Rows, Cols>& other) const;

    T avg() const;

    int numRows() const { return Rows; }

    int numCols() const { return Cols; }

    T* operator[](int index) { return data_[index]; }

    const T* operator[](int index) const { return data_[index]; }

    // overload () operator
    T& operator()(int row, int col) { return data_[row][col]; }
    const T& operator()(int row, int col) const { return data_[row][col]; }

    // exception class for illegal matrix operation
    class IllegalOperation : public std::exception {

    private:

        const char* errmsg;

    public:
        IllegalOperation(const char* msg = "") : errmsg(msg) {}
        const char* what() const noexcept override { return errmsg; }


    };



private:
    // data members
    T data_[Rows][Cols];



};

//min function
template <typename T, int Rows, int Cols>
T min(const Matrix<T, Rows, Cols>& m) {
    T tMin = m[0][0];
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            if (tMin < m[i][j]) tMin = m[i][j];

        }
    }
    return tMin;

}





#include "matrix_impl.h"
#endif // MATRIX_H_INCLUDED
