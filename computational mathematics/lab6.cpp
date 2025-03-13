#include <iostream>
#include <locale>
#include <iomanip> // кол-во знаков после запятой

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	const int r = 5, c = 6;

	double A[r][c] = { {  33,  7 , -5 ,  1 ,  9 , 45  },
					   { -2 ,  36, -9 , -6 , -4 , 30  },
					   {  6 , -1 ,  31,  8 ,  4 , 144 },
					   { -4 , -2 ,  7 ,  20,  3 , 48  },
					   {  6 ,  6 ,  9 ,  3 ,  28, 52  } };

	double eps = 0.001;

	//выводим матрицу на экран
	cout << "Matrix A:" << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}

	bool k1 = 1, k2 = 1;

	cout << fixed << setprecision(3);

	/////////////////////////////////////////////////////////////
	//решение по методу простых итераций

	//шаг 1
	double x1[r] = { 0, 0, 0, 0, 0 };
	double x2[r] = { 0, 0, 0, 0, 0 };

	//шаг 2
	//продолжае до тех пор, р, пока все
	//модули разностей соответствующих координат 
	//векторов X(k) и X(k+1)
	//не станут меньше наперёд заданной точности :
	while (k1)
	{
		for (int i = 0; i < r; i++) {
			double sum = 0;
			for (int j = 0; j < c - 1; j++) {
				if (i != j)
					sum = sum + x1[j] * A[i][j];
			}
			x2[i] = (A[i][c - 1] - sum) / A[i][i];
		}
		int count = 0;
		for (int i = 0; i < r; i++) {
			if (x2[i] - x1[i] < eps)
				count++;
		}
		if (count == 5)
			k1 = 0;
		else
		{
			for (int i = 0; i < r; i++)
				x1[i] = x2[i];
		}

	}
	cout << "\n\n";
	cout << "Решение по методу простых итераций: " << endl;
	for (int i = 0; i < r; i++)
		cout << x2[i] << "  ";

	//////////////////////////////////////////////////////////////////////////
	//решение по методу Зейделя

	//шаг 1
	double x3[r] = { 0, 0, 0, 0, 0 };
	double x4[r] = { 0, 0, 0, 0, 0 };

	//шаг 2
	while (k2)
	{
		int k = 0;
		for (int i = 0; i < r; i++) {
			double sum1 = 0, sum2 = 0;
			for (int j = 0; j < k; j++) {
				if (i != j)
					sum2 = sum2 + x4[j] * A[i][j];
			}
			for (int j = k; j < c - 1; j++) {
				if (i != j)
					sum1 = sum1 + x3[j] * A[i][j];
			}
			x4[i] = (A[i][c - 1] - sum1 - sum2) / A[i][i];
			k++;
		}
		int count = 0;
		for (int i = 0; i < r; i++) {
			if (x4[i] - x3[i] < eps)
				count++;
		}
		if (count == 5)
			k2 = 0;
		else
		{
			for (int i = 0; i < r; i++)
				x3[i] = x4[i];
		}

	}

	cout << endl << "Решение по методу Зейделя:" << endl;
	for (int i = 0; i < r; i++)
		cout << x2[i] << "  ";
	cout << endl;

}