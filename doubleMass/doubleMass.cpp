#include <iostream>
#include <ctime> 
#include <fstream>


//Ч1 - 13В - Количество столбцов, элементы которых упорядочены по возрастанию элементов
//Ч2 - В13 - Минимум среди сумм элементов диагоналей параллельных главной диагонали матрицы(матр квадратная)

const int SIZE1 = 4;
const int SIZE2 = 4;

//void randomFillMass(int mass[][SIZE2], int N, int M)
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			mass[i][j] = 1 + rand() % 100;
//		}
//	}
//}

//void randomFillMass(int** arr, const int N)
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			arr[i][j] = 1 + rand() % 100;
//		}
//	}
//}

void print_array(int** arr, const int N, const int M)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << arr[i][j] << '\t';
		}   std::cout << '\n';
	}
}

void print_array(int mass[][SIZE2], int N, int M)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << mass[i][j] << '\t';
		}   std::cout << '\n';
	}
}

int columns(int mass[][SIZE2], int N, int M)
{
	int counter = 0;


	for (int j = 0; j < M; j++)
	{
		bool sequence = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (mass[i][j] >= mass[i + 1][j])
			{
				sequence = 0;
			}
		}
		if (sequence)counter++;
	}

	return counter;
}

int minSumm(int** arr, const int N)
{
	int min = 0,
		te1 = 0,
		te2 = 0;

	min = arr[0][N - 1];
	for (int i = 1; i < N; i++)
	{
		te1 = te2 = 0;
		for (int j = 0; j < N - i; j++)
		{
			te1 += arr[i + j][j];
			te2 += arr[j][i + j];
		}
		if (te1 < min) min = te1;
		if (te2 < min) min = te2;
	}
	return min;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	//установка генератора случайных чисел; функция time(0) объявлена в <ctime>
	srand(time(0));

	std::cout << "Часть 1:" << std::endl << "СТАТИЧЕСКИЙ" << std::endl;
	int mass[SIZE1][SIZE2] =
	{
		{0, 19, -2, 3},
		{1, 1, 2, 3},
		{2, 1, 22, 3},
		{6, -1, 222, 3}
	};

	//randomFillMass(mass, SIZE1, SIZE2);
	print_array(mass, SIZE1, SIZE2);
	std::cout << "Количество столбцов, где элементы упорядочены по возрастанию = " << columns(mass, SIZE1, SIZE2) << std::endl;

	std::cout << "Часть 2:" << std::endl << "ДИНАМИЧЕСКИЙ" << std::endl;
	int num;
	std::cout << "Введите размерность матрицы: ";
	std::cin >> num;

	int** matrix = new int* [num];
	for (int i = 0; i < num; i++)
	{
		matrix[i] = new int[num];
	}

	//print_array(matrix, num);
	std::cout << "Минимум среди сумм элементов диагоналей параллельных главной диагонали матрицы: " << std::endl << minSumm(matrix, num);

}
