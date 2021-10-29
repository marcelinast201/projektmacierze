#include <iostream>
#include "matrix.h"

using namespace std;

int main() {
    int operation, type;
    int **arr1, **arr2, **result;
    double **arra1, **arra2, **results;
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

    cout << "Jakiego typu macierze wybierasz:wpisz 1 jesli int,wpisz 2 jesli  double? " << endl;
    cin >> type;
    showmenu();
    cout << "Jakie dzialanie chcesz wykonac - wybierz numer" << endl;

    cin >> operation;
    switch (operation) {
        case 1:
            if (type == 1) {
                size_of_matrixes(&row1, &col1, &row2, &col2);
                if ((row1 == row2) && (col1 == col2)) {
                    arr1 = allocate_array(row1, col1);
                    arr2 = allocate_array(row2, col2);
                    fill_matrix(arr1, row1, col1);
                    fill_matrix(arr2, row2, col2);
                    result = addMatrix(arr1, arr2, row1, col1);
                    printMatrix(result, row1, col1);
                } else {
                    exit(1);
                }
                delete_matrix(arr1, row1);
                delete_matrix(arr2, row2);
            }
            if (type == 2) {
                size_of_matrixes(&row1, &col1, &row2, &col2);
                if ((row1 == row2) && (col1 == col2)) {
                    arra1 = allocate_double_array(row1, col1);
                    arra2 = allocate_double_array(row2, col2);
                    fill_matrix(arra1, row1, col1);
                    fill_matrix(arra2, row2, col2);
                    results = addMatrix(arra1, arra2, row1, col1);
                    printMatrix(results, row1, col1);
                } else {
                    exit(1);
                }
                delete_matrix(arra1, row1);
                delete_matrix(arra2, row2);
            }
            break;
        case 2:
            if (type == 1) {
                size_of_matrixes(&row1, &col1, &row2, &col2);
                if ((row1 == row2) && (col1 == col2)) {
                    arr1 = allocate_array(row1, col1);
                    arr2 = allocate_array(row2, col2);
                    fill_matrix(arr1, row1, col1);
                    fill_matrix(arr2, row2, col2);
                    result = subtractMatrix(arr1, arr2, row1, col1);
                    printMatrix(result, row1, col1);
                } else {
                    exit(1);
                }
                delete_matrix(arr1, row1);
                delete_matrix(arr2, row2);
            }
            if (type == 2) {
                size_of_matrixes(&row1, &col1, &row2, &col2);
                if ((row1 == row2) && (col1 == col2)) {
                    arra1 = allocate_double_array(row1, col1);
                    arra2 = allocate_double_array(row2, col2);
                    fill_matrix(arra1, row1, col1);
                    fill_matrix(arra2, row2, col2);
                    results = subtractMatrix(arra1, arra2, row1, col1);
                    printMatrix(results, row1, col1);
                } else {
                    exit(1);
                }

                delete_matrix(arra1, row1);
                delete_matrix(arra2, row2);
            }
            break;
        case 3:
            if (type == 1) {
                size_of_matrixes(&row1, &col1, &row2, &col2);
                if (row1 == col2) {
                    arr1 = allocate_array(row1, col1);
                    arr2 = allocate_array(row2, col2);
                    fill_matrix(arr1, row1, col1);
                    fill_matrix(arr2, row2, col2);
                    result = multiplyMatrix(arr1, arr2, row1, col1, col2);
                    printMatrix(result, row1, col2);
                } else {
                    exit(1);
                }
                delete_matrix(arr1, row1);
                delete_matrix(arr2, row2);
            }
            if (type == 2) {
                size_of_matrixes(&row1, &col1, &row2, &col2);
                if (row1 == col2) {
                    arra1 = allocate_double_array(row1, col1);
                    arra2 = allocate_double_array(row2, col2);
                    fill_matrix(arra1, row1, col1);
                    fill_matrix(arra2, row2, col2);
                    results = multiplyMatrix(arra1, arra2, row1, col1, col2);
                    printMatrix(results, row1, col2);
                } else {
                    exit(1);
                }

                delete_matrix(arra1, row1);
                delete_matrix(arra2, row2);
            }
            break;
        case 4:
            int skalar;
            double skalar2;
            if (type == 1) {
                size_of_matrix(&row1, &col1);
                arr1 = allocate_array(row1, col1);
                fill_matrix(arr1, row1, col1);
                cout << "podaj skalar:";
                cin >> skalar;
                result = multiplyByScalar(arr1, row1, col1, &skalar);
                printMatrix(result, row1, col1);
                delete_matrix(arr1, row1);
            }

            if (type == 2) {
                size_of_matrix(&row1, &col1);
                arra1 = allocate_double_array(row1, col1);
                fill_matrix(arra1, row1, col1);
                results = multiplyByScalar(arra1, row1, col1, &skalar2);
                printMatrix(results, row1, col1);
                delete_matrix(arra1, row1);
            }

            break;
        case 5:
            if (type == 1) {
                size_of_matrix(&row1, &col1);
                arr1 = allocate_array(row1, col1);
                fill_matrix(arr1, row1, col1);
                result = transpozeMatrix(arr1, row1, col1);
                printMatrix(result, col1, row1);
                delete_matrix(arr1, row1);
            }
            if (type == 2) {
                size_of_matrix(&row1, &col1);
                arra1 = allocate_double_array(row1, col1);
                fill_matrix(arra1, row1, col1);
                results = transpozeMatrix(arra1, row1, col1);
                printMatrix(results, col1, row1);
                delete_matrix(arra1, row1);
            }
            break;
        case 6:
            unsigned power;
            if (type == 1) {
                size_of_matrix(&row1, &col1);
                arr1 = allocate_array(row1, col1);
                fill_matrix(arr1, row1, col1);
                cout << "podaj potege" << endl;
                cin >> power;
                result = powerMatrix(arr1, power, row1, col1);
                printMatrix(result, row1, col1);
                delete_matrix(arr1, row1);
            }
            if (type == 2) {
                size_of_matrix(&row1, &col1);
                arra1 = allocate_double_array(row1, col1);
                fill_matrix(arra1, row1, col1);
                cout << "podaj potege" << endl;
                cin >> power;
                results = powerMatrix(arra1, power, row1, col1);
                printMatrix(results, row1, col1);
                delete_matrix(arra1, row1);
            }
            break;
        case 7:
            int det;
            double deter;

            if (type == 1) {
                size_of_matrix(&row1, &col1);
                if (row1 == col1) {
                    arr1 = allocate_array(row1, col1);
                    fill_matrix(arr1, row1, col1);
                    det = determinantMatrix(arr1, row1, col1);
                    cout << det;
                } else {
                    exit(1);
                }
                delete_matrix(arr1, row1);
            }
            if (type == 2) {
                size_of_matrix(&row1, &col1);
                if (row1 == col1) {
                    arra1 = allocate_double_array(row1, col1);
                    fill_matrix(arr1, row1, col1);
                    deter = determinantMatrix(arra1, row1, col1);
                    cout << deter;
                } else {
                    exit(1);
                }
                delete_matrix(arra1, row1);
            }
            break;
        case 8:
            bool diagonal;
            if (type == 1) {
                size_of_matrix(&row1, &col1);
                arr1 = allocate_array(row1, col1);
                fill_matrix(arr1, row1, col1);
                diagonal = matrixIsDiagonal(arr1, row1, col1);
                if (diagonal == 0)
                    cout << "Macierz jest diagonalna";
                else {
                    cout << "Macierz nie jest diagonalna";
                }
                delete_matrix(arr1, row1);
            }

            if (type == 2) {
                size_of_matrix(&row1, &col1);

                arra1 = allocate_double_array(row1, col1);
                fill_matrix(arr1, row1, col1);
                diagonal = matrixIsDiagonal(arra1, row1, col1);
                if (diagonal == 0)
                    cout << "Macierz jest diagonalna";
                else {
                    cout << "Macierz nie jest diagonalna";

                }
                delete_matrix(arra1, row1);
            }
            break;
        case 9:
            if (type == 1) {
                size_of_matrix(&row1, &col1);
                arr1 = allocate_array(row1, col1);
                fill_matrix(arr1, row1, col1);
                sortRowsInMatrix(arr1, row1, col1);
                printMatrix(arr1, row1, col1);
                delete_matrix(arr1, row1);
            }
            if (type == 2) {
                size_of_matrix(&row1, &col1);

                arra1 = allocate_double_array(row1, col1);
                fill_matrix(arr1, row1, col1);
                sortRowsInMatrix(arra1, row1, col1);
                printMatrix(arra1, row1, col1);
                delete_matrix(arra1, row1);
            }
            break;
        case 10:
            help();
            break;
        default:
            cout << "Nie ma takiej operacji";
    }
    return 0;
}