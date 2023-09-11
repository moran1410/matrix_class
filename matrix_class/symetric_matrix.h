#pragma once



#include "matrix.h"
// needs rework, specialization inheritance not correct. new [] and () operators for inherited class needed 
template <typename T, int Rows, int Cols>
class SymetricMatrix : public Matrix< T, Rows, Cols> {};

//inheritace specialization
template <typename T, int rowCol>
class SymetricMatrix< T, rowCol, rowCol > : public Matrix< T, rowCol, rowCol> {

private:
    T* dataPointer[rowCol][rowCol];

public:
    //virtual base class function to allow access to private member, returns reference to member
    void accessData(int row, int col) { return &Matrix<T, rowCol, rowCol>::data_[row][col]; }

    SymetricMatrix(T value) {
        //loop through the upper triagle half and diagnol line of the matrix and assign the value 
        for (int i = 0; i < rowCol; ++i) {
            for (int j = i; j < rowCol; ++j) {

                if (i == j) accessData(i, j) = value;
                else {
                    //assign value to base class data_ 
                    accessData(i, j) = value;

                    //assign pointers to the upper triangle half of the matrix
                    dataPointer[j][i] = *accessData(i, j);
                }



            }
        }
    }


};

