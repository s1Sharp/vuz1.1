#include "pch.h"
#include  <iostream>
using namespace std;




int main() {
	int a, b, h, d, k = 0;           //a-строки, b-столбцы, h,d-для возврата на исходную точку в поиске зданий
	char c;                         //переменная для ввода
	const char *z = "#";           //константа для понятного сравнения в заполнении массива
	cin >> a >> b;                //ввожу кол-во строк а и длинна стоkбцов b
	cout << endl;
	int **x = new int*[a + 1];          //создаю двумерный массив х[a][b]
	for (int i = 0; i <= b + 1; i++) {

		x[i] = new int[b + 1];



	}
	for (int i = 0; i < a; ++i)             //заполняю массив меняя значения ("."->0)("#"->1) для удобной работы с числами
		for (int j = 0; j < b; j++) {
			cin >> c;
			if (c == *z)
				x[i][j] = 1;
			else
				x[i][j] = 0;
		}
	

	for (int i = 0; i < a; ++i)             //прохожу по массиву для последовательного нахождения каждого здания
		for (int j = 0; j < b; j++)
			if (x[i][j] == 1) {             //при нахождении 1(#) начинается удаление прямоугольника состоящего 
				                           //из 1 до последней точки(нижняя правая в массиве)

			


				h = i; d = j;
				do {
					do {

						if ((x[h + 1][d] != 1 && x[h][d + 1] != 1) || (h + 1 >= a && d + 1 >= b)) //условие последней точки 
						{
							k++; x[h][d] = 0; break;        //если условие выполнилось, следовательно здание засчитано
						}
						x[h][d] = 0;
						d++;
					} while (x[h][d ] == 1);
					d = j;
					if ((x[h + 1][d] != 1 && x[h][d + 1] != 1) || (h + 1 >= a && d + 1 >= b))   //условие последней точки
						break; 
					 h++;
				} while (x[h ][d] == 1);
			}
     




	cout << k << endl; 
	
	return 0;
}