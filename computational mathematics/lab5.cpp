#include <iostream>
using namespace std;

#include <iomanip> // кол-во знаков после запятой

int main()
{
    const int r = 5, c = 6;

    double A[5][6] = { {-0.08 , -0.78 , -0.74 , -0.6  , -0.66 , -0.71 },
                      { 0.52 ,  0.12 ,  0.38 , -0.41 ,  0.42 ,  0.39 },
                      { 0.67 ,  0.57 ,  0.49 ,  0.7  ,  0.04 , -0.44 },
                      { 0.11 , -0.58 , -0.91 ,  0.44 ,  0.23 ,  0.6  },
                      {-0.33 , -0.13 ,  0.79 , -0.19 ,  0.2  ,  0.69 } };

    double B[r][c-1];
    double T[r][c-1];

    //сначала обнуляем матрицы В и Т
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c-1; j++) 
        {
            B[i][j] = 0;
            T[i][j] = 0;
        }
    }
    cout << "Matrix A" << endl;
    //выводим матрицу на экран
    for (int i = 0; i < r; i++) 
    {
        for (int j = 0; j < c; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }

    cout << endl;

    //коэффициенты первого столбца матрицы В
    for (int i = 0; i < r; i++) 
    {
        B[i][0] = A[i][0];
    }

    //единицы на главной диагонали Т
    for (int i = 0; i < r; i++)
        for (int k = 1; k < c-1; k++)
            if (i == k) T[i][k] = 1;

    //коэффициенты первой строки матрицы Т
    for (int i = 1; i < r; i++) 
    {
        T[0][i] = A[0][i] / B[0][0];
    }

    //вычисляем остальные коэффициенты
    for (int k = 1; k < r; k++) 
    {

        for (int i = 1; i < r; i++) 
        {
            double sum = 0;
            for (int m = 0; m < k; m++) 
            {
                sum = sum + B[i][m] * T[m][k];
            }
            B[i][k] = A[i][k] - sum;
        }
        if (k <= r - 2) {
            for (int j = k + 1; j < r; j++) 
            {
                double sum = 0;
                for (int m = 0; m < k; m++) 
                {
                    sum = sum + B[k][m] * T[m][j];
                }
                T[k][j] = (A[k][j] - sum) / B[k][k];
            }
        }
    }

    //ВY = C
    double y[r];

    y[0] = A[0][c - 1] / B[0][0];
    for (int i = 1; i < r; i++) 
    {
        double sum = 0;
        for (int m = 0; m < i; m++)
        {
            sum = sum + B[i][m] * y[m];
        }
        y[i] = (A[i][c - 1] - sum) / B[i][i];
    }

    //TX = Y
    double x[r];

    x[r - 1] = y[r - 1];
    for (int i = r - 2; i >= 0; i--) 
    {
        double sum = 0;
        for (int m = i + 1; m < r; m++)
        {
            sum = sum + T[i][m] * x[m];
        }
        x[i] = y[i] - sum;
    }

    //выводим решения

    cout << fixed << setprecision(3);

    cout << "Matrix B: " << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c-1; j++)
            cout << B[i][j] << "\t";
        cout << endl;
    }

    cout << endl;
    cout << "Matrix T: " << endl;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c-1; j++)
            cout << T[i][j] << "\t";
        cout << endl;
    }

    cout << endl;
    cout << "Vector x: " << endl;

    for (int i = 0; i < r; i++)
    {
        cout << x[i] << "  ";
    }
    cout << endl;
    cout << endl;
    cout << "Vector y: " << endl;

    for (int i = 0; i < r; i++) 
    {
        cout << y[i] << "  ";
    }
    cout << endl;
}