#include <iostream>
#include <time.h>//для рандома
#include <vector>

using namespace std;

int main()
{
	int n = 5;

	vector <double> a(n+1);
	vector <double> b(n+1);
	vector <double> c(n+1);
	vector <double> f(n+1);

	vector <double> alpha(n+1);
	vector <double> beta(n+1);
	vector <double> x(n+1);

	srand(time(0));//для рандома

	for (int i = 0; i <= n; i++)
	{
		a[i] = rand() % 10 + 1;
		b[i] = rand() % 10 + 1;
		c[i] = rand() % 10 + 1;
		f[i] = rand() % 10 + 1;
	}

	//вывод векторов
	cout << "vector a: ";
	for (int i = 0; i <= n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
	cout << "vector b: ";
	for (int i = 0; i <= n; i++)
	{
		cout << b[i] << "\t";
	}
	cout << endl;
	cout << "vector c: ";
	for (int i = 0; i <= n; i++)
	{
		cout << c[i] << "\t";
	}
	cout << endl;
	cout << "vector f: ";
	for (int i = 0; i <= n; i++)
	{
		cout << f[i] << "\t";
	}
	cout << endl << endl;

	//вывод на экран
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n+1; j++) {
			if (i == j) {
				cout << c[i] << "\t";
			}
			else if (j == n + 1) {
				cout << "=" << "\t" << f[i] << "\n";
			}
			else if (i == j + 1) {
				cout << a[i] << "\t";
			} 
			else if (i == j - 1) {
				cout << b[i] << "\t";
			}
			else cout << 0 << "\t";
		}


	//вычисление коэффициентов
	for (int i = 0; i <= n-1; i++)
	{
		if (i == 0)
		{
			alpha[i] = (-1) * b[0] / c[0];
			beta[i] = f[0] / c[0];
			continue;
		}
		else
		{
			alpha[i] = (-1) * b[i-1] / (c[i-1] + alpha[i-1] * a[i-1]);
			beta[i] = (-1) * (f[i-1] - a[i-1] * beta[i-1]) / (c[i-1] + alpha[i-1] * a[i-1]);
		}
	}

	//вычисление решения системы
	for (int i = n; i >= 0; i--)
	{
		if (i == n)
		{
			x[i] = (f[i] - a[i]*beta[i])/(c[i] + a[i]*alpha[i]);
			continue;
		}
		else
		x[i] = alpha[i+1] * x[i + 1] + beta[i+1];
	}

	cout << endl << endl; 
	for (int i = 0; i <= n; i++)
	{
		cout <<  "x[" << i+1 << "] = " << x[i] << endl;
	}

}