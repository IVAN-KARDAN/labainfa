#include"pch.h"
#include<iostream>
#include<ctime>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<limits>
#include<sstream>
using namespace std;



int main() {
	setlocale(LC_ALL, "RUS");
	int i, j, u, m, k;
	char s, M, K;

	
	cout << "Введите размер матрицы(от 2 до 5): ";
	cin >> M;
	while ((M < '2') || (M > '5')) {
		cout << "Вы ввели недопустимое значение, повторите ввод: ";
		cin >> M;
		cin.clear();
	}
	m = M - '0';
	cout << "Введите 0, если вы хотите заполнить матрицу самостоятельно.Введите 1, если вы хотите заполнить матрицу случайными числами:  ";
	cin >> K;
	cin.clear();
	while ((K != '0') && (K != '1')) {
		cout << "Вы ввели недопустимое значение, повторите ввод: ";
		cin >> K;
		cin.clear();
	}


	string **a = new string*[m];
	for (int i = 0; i < m; i++) {
		a[i] = new string[m];
	}
	if (K == '0') {
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) {
				cout << "Введите четырехзначный элемент матрицы (" << (i + 1) << (j + 1) << "): ";
				cin >> a[i][j];
				cin.clear();
				while (a[i][j].length() != 4) {
					cout << "Вы ввели недопустимое значение элеменита матрицы, повторите ввод: ";
					cin >> a[i][j];
					cin.clear();
				}
			}
		}

	}

	else {
		srand(time(0));
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) {
				for (int f = 0; f < 4; f++) {
					s = (65 + rand() % 25);
					a[i][j] = s + a[i][j];

				}

			}
		}
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	int *b = new int;
	*b = (m*m);
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			u = 0;
			for (int f = 0; f < 4; f++) {
				if ((a[i][j][f] != 'A') && (a[i][j][f] != 'E') && (a[i][j][f] != 'U') && (a[i][j][f] != 'O') && (a[i][j][f] != 'Y') && (a[i][j][f] != 'I')) {
					u++;
				}
			}
			cout << u << "  ";
			b[i*m + j] = u;
		}
		cout << endl;
	}
	for (i = 0; i < (m*m); i++) {
		cout << b[i];
	}
	cout << endl;
	for (int i = 0; i < (m*m) - 1; i++) {
		for (int j = i + 1; j < (m*m); j++) {
			if (b[i] > b[j])
			{
				int x = b[j];
				b[j] = b[i];
				b[i] = x;
			}
		}
	}

	for (i = (m*m-1); i >= 0; i--) {
		cout << b[i];
	}
	delete[]
		a;
	delete[]
		b;
	return 0;



}
