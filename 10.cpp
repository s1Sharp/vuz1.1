// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {

	const int n = 30;

	int m[n];
	srand(time(NULL));
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		{
			m[i] = rand() % 100;
			printf("%d ", m[i]);
		}
		if (k == 4)
		{
			printf("\n"); k = 0;
		}
		else
			k++;
	}

	
		int count = 0;
#pragma omp parallel for shared(count) 
		for (int i = 0; i < n; ++i)
		{
			if (m[i] % 9 == 0)
#pragma omp atomic
				count++;
		}
		printf("count is %d\n", count);
}