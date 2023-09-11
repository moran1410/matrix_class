#pragma once
#include "matrix.h"


// constructor
template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>::Matrix(T defaultValue) {
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data_[i][j] = defaultValue;
        }
    }
}

// operators


// == operator
template <typename T, int Rows, int Cols>
bool Matrix<T, Rows, Cols>::operator==(
    const Matrix<T, Rows, Cols>& other) const {

    if (Rows != other.numRows() || Cols != other.numCols())
        return false;

    for (int i = 0; i < Rows; ++i) {

        for (int j = 0; j < Cols; ++j) {
            if (data_[i][j] != other.data_[i][j])
                return false;
        }
    }
    return true;
}

// != operator
template <typename T, int Rows, int Cols>
bool Matrix<T, Rows, Cols>::operator!=(
    const Matrix<T, Rows, Cols>& other) const {

    return !(*this == other);
}

// = operator
template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator=(const Matrix& other) {
    // if (this == &other) return *this;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
    return *this;
}

template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>
Matrix<T, Rows, Cols>::operator+(const Matrix& other) const {
    Matrix result(*this); // make a copy of this matrix
    result += other;      // use the += operator to add the other matrix
    return result;
}

/*
template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator+(const Matrix& other){
  //if (this == &other) return *this;
  for (int i = 0; i <Rows; ++i) {
    for (int j = 0; j < Cols; ++j) {
      data_[i][j] += other.data_[i][j];
    }
  }
  return *this;
}*/

template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols>&
Matrix<T, Rows, Cols>::operator+=(const Matrix<T, Rows, Cols>& other) {
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            data_[i][j] += other.data_[i][j];
        }
    }
    return *this;
}

template <typename T, int Rows, int Cols>
template <int Rows2, int Cols2>
Matrix<T, Cols, Rows2>
Matrix<T, Rows, Cols>::operator*(const Matrix<T, Rows2, Cols2>& other) const {
    //throw an exception condition
    if (Cols != other.numRows()) {
        throw  typename  Matrix<T, Rows2, Cols>::IllegalOperation(
            "Matrices cannot be multiplied");
    }
    Matrix<T, Cols, Rows2> result;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols2; ++j) {
            T sum = T();
            for (int k = 0; k < Cols; ++k) {
                sum += data_[i][k] * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}

// Matrix multiplication with a scalar
template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> Matrix<T, Rows, Cols>::operator*(const T& scalar) const {
    Matrix<T, Rows, Cols> result;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result(i, j) = data_[i][j] * scalar;
        }
    }
    return result;
}

template <typename T, int Rows, int Cols>
Matrix<T, Rows, Cols> operator*(const T& scalar,
    const Matrix<T, Rows, Cols>& matrix) {
    Matrix<T, Rows, Cols> result;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            result(i, j) = matrix(i, j) * scalar;
        }
    }
    return result;
}


// avg() average method 
template <typename T, int Rows, int Cols>
T Matrix<T, Rows, Cols>::avg() const {
    T sum = T();
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            sum += data_[i][j];
        }
    }
    return sum / (Rows * Cols);
}