#include <iostream>
#include <ctime> 


//Ч1 - 13В - Количество столбцов, элементы которых упорядочены по возрастанию элементов
//Ч2 - В13 - Минимум среди сумм элементов диагоналей параллельных главной диагонали матрицы(матр квадратная)

void randomFillMass(int** arr, const int N, const int M)//указательная переменная, будущая массивом, и число ячеек массива
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = 1 + rand() % 20;
		}
	}
}

void print_array(int** arr, const int N, const int M)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << arr[i][j] << '\t';
		}   std::cout << '\n';
	}
}

int columns(int** arr, const int N, const int M)
{
	int counter = 0;


	for (int j = 0; j < M; j++)
	{
		bool sequence = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (arr[i][j] >= arr[i + 1][j])
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

	int row = 0, col = 0;
	std::cout << "Введите количество строк: ";
	std::cin >> row;
	std::cout << "Введите количество колонок для каждой строки: ";
	std::cin >> col;

	//память
	int** doubMass = new int* [row];   //Создание строк
	for (int i = 0; i < row; i++)
	{
		doubMass[i] = new int[col];  //Создание колонок для каждой строки
	}

	randomFillMass(doubMass, row, col);      //Обращение к функции заполнения двумерного массива
	print_array(doubMass, row, col);     //Обращение к функции вывода двумерного массива
	std::cout << "Количество столбцов, где элементы упорядочены по возрастанию: " << columns(doubMass, row, col) << std::endl;

	int num;
	std::cout << "Введите размерность матрицы: ";
	std::cin >> num;

	int** matrix = new int* [num];
	for (int i = 0; i < num; i++)
	{
		matrix[i] = new int[num];
	}
	randomFillMass(matrix, num, num);      //Обращение к функции заполнения двумерного массива
	print_array(matrix, num, num);      //Обращение к функции вывода двумерного массива
	std::cout << "Минимум среди сумм элементов диагоналей параллельных главной диагонали матрицы: " << std::endl << minSumm(matrix, num);




	for (int i = 0; i < row; i++)
	{
		delete[]doubMass[i];
	}
	delete[]doubMass;
	std::cin.get();
}
