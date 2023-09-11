#include <iostream>
#include <memory>
#include "matrix.h"
#include "symetric_matrix.h"

using namespace std;

int main() {

    const Matrix<int, 3, 2> m1; // Creates 3*2 matrix, with all the default elements set to 0;
    cout << m1 << endl;
    Matrix<int, 3, 3> m2(4); // Creates 3*3 matrix, with the default elements equals to 4;
    cout << m2 << endl;

    const Matrix<int, 3, 3> m3 = m2; // C-py constructor may take O(MN) and not O(1).
    cout << m3 << endl;

    // min() returns the minimal value in the matrix.
    if (min(m1) < min(m3))
        cout << "Min value of m3(" << min(m3) << ") is bigger than min value of m1(" << min(m1) << ")" << endl;

    if (m1.avg() < m3.avg()) // Compares the average of the elements
        cout << "Average value of m3(" << m3.avg() << ") is bigger than average value of m1(" << m1.avg() << ")" << endl;


    m2(0, 0) = 13;
    cout << m2[0][0] << " " << m2[1][0] << endl; // Should print "13 4"


    try {
        cout << m2 + m3 << endl;
        cout << m3 * m1 << endl; // You can choose the format of matrix printing;
        cout << m1 * m2; // This should throw an exception
    }
    catch (const Matrix<int, 3, 2>::IllegalOperation & e) {
        cout << e.what() << endl;

    }

    Matrix<int, 3, 3> m4;
    m4 = m3;
    cout << m4 << endl;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m4(i, j) = i + j;
    cout << m4 << endl;

    cout << "m4[1][1] = " << m4[1][1] << endl;

    cout << "m4[1][1] = " << m4(1, 1) << endl; // m4(1,1) same result as m4[1][1]


    Matrix<int, 3, 3> m5(3);
    m5 = 2 * m4;
    cout << m5 << endl;
    Matrix<int, 3, 3> m6(m4); //parameter passed 'Matrix' doesn't match type 'int'
    cout << m6 << endl;
    m5 += m4;
    cout << m5 << endl;

    if (m6 != m5)
        cout << "m6 != m5" << endl;

    Matrix<Matrix<int, 3, 2>, 4, 4> composite(m1); // Creates matrix, where each element is m1;

    cout << composite;
    /*
        unique_ptr<Matrix<int, 3, 3>> symetric_matrix(new SymetricMatrix<int, 3>(5)); // SymetricMatrix matrix 3*3 with default element equals to 5;

        (*symetric_matrix)(1, 2) = 8;
        cout << (*symetric_matrix)(1, 2) << " " << (*symetric_matrix)(2, 1) << endl; // Should print "8 8"
        cout << (*symetric_matrix)[1][2] << " " << (*symetric_matrix)[2][1] << endl; // Should print "8 8"


        (*symetric_matrix)[1][0] = 18;
        cout << (*symetric_matrix)[1][0] << " " << (*symetric_matrix)[0][1] << endl; // Should print "18 18"
    */
    return 0;
}
