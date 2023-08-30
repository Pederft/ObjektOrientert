#pragma once
#include <iostream>
#include <cassert>


class Matrix{
    private:
        int rows;
        int col;
        double** m_data;

    public:
        Matrix(int nRows, int nCol) : rows{nRows}, col{nCol} {
            //Sjekker om input er gyldige:
            assert(nRows > 0 && nCol > 0);

            // Alloker minne for matrisen og sett alle elementer til 0
            m_data = new double*[rows];
            for (int i = 0; i < rows; ++i) {
                m_data[i] = new double[col];
                for (int j = 0; j < col; ++j) {
                    m_data[i][j] = 0.0;
                }
            }
        }

        Matrix(const Matrix & rhs){
            //this->m_data = new double*{nullptr};
            //int nRows = rhs.getRows();
            //int nCol  = rhs.getColumns();

            this->rows = rhs.getRows();
            this->col  = rhs.getColumns();

            //*m_data = *rhs.m_data;    
            //this->m_data* =
            this->m_data = new double*[rows];
            for(int i = 0; i < rhs.getRows(); i++){
                this->m_data[i] = new double[col];
                for(int j = 0; j < rhs.getColumns(); j++){
                    m_data[i][j] = rhs.get(i, j);
                }
            }

            /*this->m_data = new double*;
            *m_data = *rhs.m_data;*/
        }

        Matrix& operator=(Matrix rhs){
            std::swap(m_data, rhs.m_data);
            return *this;
        }

        Matrix& operator+=(const Matrix rhs);

        Matrix operator+(const Matrix& rhs){
            *this += rhs;
            return *this;
        }        

        explicit Matrix(int nRows) : Matrix(nRows, nRows){
            //Nå trenger vi kun å endre på diagonal-verdiene til null-matrisen:
            for(int i = 0; i<nRows; i++){
                m_data[i][i] = 1.0;
            }
        }

        double get(int row, int col) const;
        void set(int row, int col, double value);
        int getRows() const;
        int getColumns() const;

        //Lager destruktør for å frigjøre minne
        ~Matrix(){
            for(int i =0; i< rows; i++){
                delete[] m_data[i];
            }
            delete[] m_data;
        }   
};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

/*Matrix& operator+(Matrix rhs){
    //this->m_data = new double*[rows];
    Matrix temp(rows, col);
    if(col != rhs.col || rows!=rhs.col){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j<col; j++){
                temp.m_data[i][j] = m_data[i][j];
            }
        }
    } else{
        for(int i = 0; i < rows; i++){
            for(int j = 0; j<col; j++){
                temp.m_data[i][j] += rhs.m_data[i][j] + m_data[i][j];
            }            
        }
    }
}*/

void testMatrise();
void testMatrise2();
