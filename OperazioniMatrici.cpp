#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(std::vector<std::vector<int>>(r, std::vector<int>(c, 0))) {}

    void setValue(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            std::cout << "Indice fuori dai limiti." << std::endl;
        }
    }

    int getValue(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            std::cout << "Indice fuori dai limiti." << std::endl;
            return -1; // Valore di default per indicare un errore o un valore non valido
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "Le dimensioni delle matrici non corrispondono." << std::endl;
            return Matrix(rows, cols);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            std::cout << "Impossibile moltiplicare le matrici. Numero di colonne della prima diverso dal numero di righe della seconda." << std::endl;
            return Matrix(rows, cols);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Matrix mat1(2, 2);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(1, 0, 3);
    mat1.setValue(1, 1, 4);

    Matrix mat2(2, 2);
    mat2.setValue(0, 0, 5);
    mat2.setValue(0, 1, 6);
    mat2.setValue(1, 0, 7);
    mat2.setValue(1, 1, 8);

    std::cout << "Matrice 1:" << std::endl;
    mat1.printMatrix();

    std::cout << "Matrice 2:" << std::endl;
    mat2.printMatrix();

    Matrix sum = mat1 + mat2;
    std::cout << "Somma:" << std::endl;
    sum.printMatrix();

    Matrix product = mat1 * mat2;
    std::cout << "Prodotto:" << std::endl;
    product.printMatrix();

    return 0;
}
