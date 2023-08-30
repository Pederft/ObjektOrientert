#include "matriseKlasse.h"

double Matrix::get(int row, int col) const {
    assert(row >= 0 && col >= 0);
    return m_data[row][col];
}

void Matrix::set(int row, int col, double value){
    assert(row >= 0 && col >= 0);
    m_data[row][col] = value;
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return col;
}

//Overlaster << operatoren:
std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
    for(int i = 0; i < matrix.getRows(); i++){
        for(int k = 0; k < matrix.getColumns(); k++){
            os << matrix.get(i, k) << "\t";
        }
        os << std::endl;
    }
    return os;
}

//+= operator
Matrix& Matrix::operator+=(const Matrix rhs){
    assert(rhs.rows == rows && rhs.col == col);

    for(int i=0; i<rows; i++){
        for(int j=0; j<col; j++){
            m_data[i][j] += rhs.m_data[i][j];
        }
    }
    return *this;
}

//+ operator
/*Matrix& Matrix::operator+(Matrix rhs) const {
    assert(rhs.rows == rows && rhs.col == col);

    Matrix res(rows,col);

    res.m_data += rhs.m_data;

}*/


void testMatrise(){
    Matrix mat(4,4);
    mat.set(2,2, 8);
    mat.set(1,1, 4);
    mat.set(0,0,8);

    Matrix A{4};
    Matrix B{A}; //Tester kopikonstruktøren
    Matrix C{4};

    C = mat; //Tester operatoren

    A+=B;

    Matrix D = A+B;

    //std::cout << mat;
    //std::cout << "\n\n" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << A    << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << B    << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << C    << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << D    << std::endl;
    std::cout << "-----------------------" << std::endl;

}

void testMatrise2(){
    Matrix A(2,2);
    A.set(0,0, 1);
    A.set(0,1, 2);
    A.set(1,0, 3);
    A.set(1,1, 4);

    Matrix B(2,2);
    B.set(0,0, 4);
    B.set(0,1, 3);
    B.set(1,0, 2);
    B.set(1,1, 1);

    Matrix C(2,2);
    C.set(0,0, 1);
    C.set(0,1, 3);
    C.set(1,0, 1.5);
    C.set(1,1, 2);

    A += B + C;


    std::cout << "-----------------------" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << A    << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << B    << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << C    << std::endl;
    std::cout << "\n" << std::endl;
    std::cout << "-----------------------" << std::endl;
    
}







