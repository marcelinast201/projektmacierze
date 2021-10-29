#include "matrix.h"
#include <cstring>

void showmenu() {
    cout << "1.addMatrix" << endl << "2.subtractMatrix" << endl << "3.multiplyMatrix" << endl << "4.multiplyByScalar"
         << endl <<
         "5.transpozeMatrix" << endl << "6.powerMatrix" << endl << "7.determinantMatrix" << endl << "8.matrixIsDiagonal"
         << endl <<
         "9.sortRowsInMatrix" << endl << "10.help" << endl;
}

void check_arg() {
    if (!cin) {
        cout << "podales zly znak";
        exit(1);
    }
}

void size_of_matrix(int *rows, int *columns) {

    cout << "podaj ilosc wierszy i kolumn macierzy" << endl;
    cin >> *rows >> *columns;
    check_arg();
}

void size_of_matrixes(int *rows1, int *columns1, int *rows2, int *columns2) {

    cout << "podaj ilosc wierszy i kolumn pierwszej macierzy" << endl;
    cin >> *rows1 >> *columns1;
    check_arg();

    cout << "podaj ilosc wierszy i kolumn drugiej macierzy" << endl;
    cin >> *rows2 >> *columns2;
    check_arg();
}

int **fill_matrix(int **matrix, int rows, int columns) {
    int number;

    cout << "podaj liczby dla macierzy\nZatwierdz liczbe enterem " << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> number;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            check_arg();
            matrix[i][j] = number;
        }
    }
    return matrix;
}

double **fill_matrix(double **matrix, int rows, int columns) {
    double number;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "podaj liczbe" << endl;
            cin >> number;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            check_arg();
            matrix[i][j] = number;
        }
    }
    return matrix;
}

int **allocate_array(int rows, int columns) {
    int **arr = new int *[rows];
    for (int i = 0; i < columns; i++) {
        arr[i] = new int[columns];
    }
    return arr;
}

double **allocate_double_array(int rows, int columns) {
    double **arr = new double *[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[columns];
    }
    return arr;
}

void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j];
            cout << "  ";
        }
        cout << endl;
    }
}

void printMatrix(double **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j];
            cout << "  ";
        }
        cout << endl;
    }
}

int **addMatrix(int **mat1, int **mat2, int rows, int columns) {
    int **wyn = allocate_array(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return wyn;
}

double **addMatrix(double **mat1, double **mat2, int rows, int columns) {
    double **wyn = allocate_double_array(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return wyn;
}

int **subtractMatrix(int **mat1, int **mat2, int rows, int columns) {
    int **wyn = allocate_array(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return wyn;
}

double **subtractMatrix(double **mat1, double **mat2, int rows, int columns) {
    double **wyn = allocate_double_array(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return wyn;
}

int **multiplyByScalar(int **mat1, int rows, int columns, int *numb) {
    int **wyn = allocate_array(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[i][j] = mat1[i][j] * *numb;
        }
    }
    return wyn;
}

double **multiplyByScalar(double **mat1, int rows, int columns, double *numb) {
    double **wyn = allocate_double_array(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[i][j] = mat1[i][j] * *numb;
        }
    }
    return wyn;
}

int **multiplyMatrix(int **mat1, int **mat2, int rows, int columns, int columns2) {
    int **wyn = allocate_array(rows, columns2);
    for (int i = 0; i < rows; i++) {
        for (int z = 0; z < columns2; z++) {
            wyn[i][z] = 0;
            for (int j = 0; j < columns; j++) {
                wyn[i][z] += (mat1[i][j] * mat2[j][z]);
            }
        }
    }
    return wyn;
}

double **multiplyMatrix(double **mat1, double **mat2, int rows, int columns, int columns2) {
    double **wyn = allocate_double_array(rows, columns2);
    for (int i = 0; i < rows; i++) {
        for (int z = 0; z < columns2; z++) {
            wyn[i][z] = 0;
            for (int j = 0; j < columns; j++) {
                wyn[i][z] += (mat1[i][j] * mat2[j][z]);
            }
        }
    }
    return wyn;
}

int **transpozeMatrix(int **matrix, int rows, int columns) {
    int **wyn = allocate_array(columns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[j][i] = matrix[i][j];
        }
    }
    return wyn;
}

double **transpozeMatrix(double **matrix, int rows, int columns) {
    double **wyn = allocate_double_array(columns, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            wyn[j][i] = matrix[i][j];
        }
    }
    return wyn;
}

int **powerMatrix(int **matrix, unsigned p, int rows, int columns) {
    int **wyn = allocate_array(rows, columns);
    wyn = matrix;
    for (int i = 1; i < p; i++) {
        wyn = multiplyMatrix(matrix, wyn, rows, columns, columns);
    }
    return wyn;
}

double **powerMatrix(double **matrix, unsigned p, int rows, int columns) {
    double **wyn = allocate_double_array(rows, columns);
    wyn = matrix;
    for (int i = 1; i < p; i++) {
        wyn = multiplyMatrix(matrix, wyn, rows, columns, columns);
    }
    return wyn;
}

//Redukuje macierz poprzez wykreslenie nr_wiersza i nr_kolumny do wielkosci rozmiar-1
//Indeksy liczymy od 0 !
int **reduce_matrix(int **matrix, int rows, int row_nr, int col_nr) {
    int **reduced_matrix = allocate_array(rows - 1, rows - 1);
    //i,k - beda przesuwac po macierzy pierwotnej
    //j,l - po macierzy zredukowanej
    for (int i = 0, j = 0; i < rows; i++) {
        if (i == row_nr)continue;
        for (int k = 0, l = 0; k < rows; k++) {
            if (k == col_nr)continue;
            else {
                reduced_matrix[j][l] = matrix[i][k];
                l++;
            }
        }
        j++;
    }
    return reduced_matrix;
}


int determinantMatrix(int **matrix, int rows, int columns) {
    int det = 0, row_nr;
    //Dla macierzy stopnia 1x1 badz 2x2 wyznacznik obliczany z definicji
    if (rows == 1) {
        return matrix[0][0];
    }
    if (rows == 2)
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    //W innym przypadku rozwiniecie LaPlace'a
    int **reduced_matrix;
    //Szukam wiersza w ktorym jest najwiecej zer
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            row_nr = i;
        }
    }
    //Wybrany wiersz bedzie uzyty do wykreslania macierzy
    //Teraz wykreslam odpowiednio macierz, licze wyznacznik dopelnienia i dodaje do wyniku
    for (int i = 0; i < rows; i++) {
        reduced_matrix = reduce_matrix(matrix, rows, row_nr, i);
        // >:*
        det += matrix[row_nr][i] * pow((-1), (row_nr + i)) * (determinantMatrix(reduced_matrix, rows - 1, rows - 1));
    }
    return det;
}

double **reduce_matrix(double **matrix, int rows, int row_nr, int col_nr) {
    double **reduced_matrix = allocate_double_array(rows - 1, rows - 1);
    //i,k - beda przesuwac po macierzy pierwotnej
    //j,l - po macierzy zredukowanej
    for (int i = 0, j = 0; i < rows; i++) {
        if (i == row_nr)continue;
        for (int k = 0, l = 0; k < rows; k++) {
            if (k == col_nr)continue;
            else {
                reduced_matrix[j][l] = matrix[i][k];
                l++;
            }
        }
        j++;
    }
    return reduced_matrix;
}


double determinantMatrix(double **matrix, int rows, int columns) {
    double det = 0;
    int row_nr;
    //Dla macierzy stopnia 1x1 badz 2x2 wyznacznik obliczany z definicji
    if (rows == 1) {
        return matrix[0][0];
    }
    if (rows == 2)
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    //W innym przypadku rozwiniecie LaPlace'a
    double **reduced_matrix;
    //Szukam wiersza w ktorym jest najwiecej zer
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            row_nr = i;
        }
    }
    //Wybrany wiersz bedzie uzyty do wykreslania macierzy
    //Teraz wykreslam odpowiednio macierz, licze wyznacznik dopelnienia i dodaje do wyniku
    for (int i = 0; i < rows; i++) {
        reduced_matrix = reduce_matrix(matrix, rows, row_nr, i);
        // >:*
        det += matrix[row_nr][i] * pow((-1), (row_nr + i)) * (determinantMatrix(reduced_matrix, rows - 1, rows - 1));
    }
    return det;
}

bool matrixIsDiagonal(int **matrix, int rows, int columns) {
    bool result;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((matrix[i][j] == 0) && (i != j))
                result = 0;
            else {
                result = 1;
            }
        }
    }
    return result;
}

bool matrixIsDiagonal(double **matrix, int rows, int columns) {
    bool result;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((matrix[i][j] == 0) && (i != j))
                result = 0;
            else {
                result = 1;
            }
        }
    }
    return result;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double *a, double *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortRow(int *arr, int columns) {
    int i, j;
    for (i = 0; i < columns - 1; i++)
        for (j = 0; j < columns - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void sortRow(double *arr, int columns) {
    int i, j;
    for (i = 0; i < columns - 1; i++)
        for (j = 0; j < columns - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void sortRowsInMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        sortRow(matrix[i], columns);
    }
}


void sortRowsInMatrix(double **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        sortRow(matrix[i], columns);
    }
}

void delete_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void delete_matrix(double **matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void help() {
    cout << "Program wykonuje dzialania na macierzach: " << endl;
    cout << "Na wstepie nalezy wybrac typ macierzy w tym celu wybierz\n"
            " * 1 jesli jest to int\n "
            " * 2 jesli jest to double\n"
            "Nastepnie wybierz numerek dzialania ktore chcesz wykonac\n" << endl;
    cout << "1.addMatrix\n"
            " * Dodaje dwie macierze \n"
            " * Macierze musza byc tych samych rozmiarow\n"
            " * @param mat1 pierwsza macierz\n"
            " * @param mat2 druga macierz\n"
            " * @param rows liczba wierszy w macierzach\n"
            " * @param columns liczba kolumn w macierzach\n" << endl;
    cout << "2.subtractMatrix\n"
            " * Odejmuje od macierzy pierwszej macierz druga:\n"
            " * Macierze musza byc tego samego rozmiaru\n"
            " * @param mat1 pierwsza macierz\n"
            " * @param mat2 druga macierz\n"
            " * @param rows liczba wierszy w macierzach\n"
            " * @param columns  liczba kolumn w macierzach\n" << endl;
    cout << "3.multiplyMatrix\n"
            " * Mnozy dwie macierze\n"
            " * Wiersze pierwszej macierzy musza byc rowne kolumnom drugiej\n"
            " * @param mat1 pierwsza macierz\n"
            " * @param mat2 druga macierz\n"
            " * @param rows liczba wierszy pierwszej macierzy\n"
            " * @param columns liczba kolumn pierwszej macierzy\n"
            " * @param columns2 liczba kolumn drugiej macierzy\n" << endl;
    cout << "4.multiplyByScalar\n"
            " * Mnozenie macierzy przez skalar \n"
            " * @param matrix macierz\n"
            " * @param rows liczba wierszy macierzy\n"
            " * @param columns liczba kolumn macierzy\n"
            " * @param numb podany przez uzytkownika skalar \n"
         << endl;
    cout << "5.transpozeMatrix\n"
            " * Transponowanie macierzy\n"
            " * @param matrix macierz\n"
            " * @param rows liczba wierszy macierzy\n"
            " * @param columns liczba kolumn macierzy\n" << endl;
    cout << "6.powerMatrix\n"
            " * Powtegowanie macierzy\n"
            " * @param matrix macierz\n"
            " * @param rows liczba wierszy macierzy\n"
            " * @param columns liczba kolumn macierzy\n"
            " * @param p wartosc potegi\n" << endl;
    cout << "7.determinantMatrix\n"
            " * Oblicza wyznacznik macierzy\n"
            " * @param matrix macierz\n"
            " * @param rows liczba wierszy macierzy\n"
            " * @param columns liczba kolumn macierzy\n" << endl;
    cout << "8.matrixIsDiagonal\n"
            " * Sprawdza czy macierz jest diagonalna\n"
            " * @param matrix macierz\n"
            " * @param rows liczba wierszy macierzy\n"
            " * @param columns liczba kolumn macierzy\n" << endl;
    cout << "9.sortRowsInMatrix\n"
            " * Sortuje kazdy wiersz macierzy za pomoca sortowania bombelkowego\n"
            " * @param matrix macierz \n"
            " * @param rows liczba wierszy macierzy\n"
            " * @param columns liczba kolumn macierzy\n" << endl;
    cout << "10.help"
            " * Wypisuje dokumentacje programu" << endl;
    cout << "Po wybraniu dzialania wybierasz ilosc kolumn i wiersz macierzy\n"
            "Nastepnie wypelniasz macierz lub macierze liczbami w zaleznosci od wybranego typu macierzy\n"
            "Oczekujesz na wynik" << endl;
}
