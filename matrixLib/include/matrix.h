
#include <iostream>

using namespace std;

void showmenu();

void check_arg();

void size_of_matrixes(int *, int *, int *, int *);

void size_of_matrix(int *, int *);

int **fill_matrix(int **, int, int);

double **fill_matrix(double **, int, int);

int **allocate_array(int, int);

double **allocate_double_array(int, int);

void printMatrix(int **, int, int);

void printMatrix(double **, int, int);

int **addMatrix(int **, int **, int, int);

double **addMatrix(double **, double **, int, int);

int **subtractMatrix(int **, int **, int, int);

double **subtractMatrix(double **, double **, int, int);

int **multiplyMatrix(int **, int **, int, int, int);

double **multiplyMatrix(double **, double **, int, int, int);

int **multiplyByScalar(int **, int, int, int *);

double **multiplyByScalar(double **, int, int, double *);

int **transpozeMatrix(int **, int, int);

double **transpozeMatrix(double **, int, int);

int **powerMatrix(int **, unsigned, int, int);

double **powerMatrix(double **, unsigned, int, int);

int determinantMatrix(int **matrix, int x, int y);

double determinantMatrix(double **matrix, int x, int y);

bool matrixIsDiagonal(int **, int, int);

bool matrixIsDiagonal(double **, int, int);

void sortRow(int *, int);

void sortRow(double *, int);

void sortRowsInMatrix(int **, int, int);

void sortRowsInMatrix(double **, int, int);

void swap(int *, int *);

void swap(double *, double *);

void delete_matrix(int **, int);

void delete_matrix(double **, int);

void help();

