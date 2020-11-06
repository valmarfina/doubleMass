#include <iostream>
#include <ctime> 
#include <fstream>


//Ч1 - 13В - Количество столбцов, элементы которых упорядочены по возрастанию элементов
//Ч2 - В13 - Минимум среди сумм элементов диагоналей параллельных главной диагонали матрицы(матр квадратная)

const int SIZE1 = 10;
const int SIZE2 = 10;
//void randomFillMass(int** arr, const int N, const int M)//указательная переменная, будущая массивом, и число ячеек массива
//{
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			arr[i][j] = 1 + rand() % 2;
//		}
//	}
//}
void randomFillMass(int mass[][SIZE2], int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mass[i][j] = 1 + rand() % 20;
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
	int mass[SIZE1][SIZE2];
	randomFillMass(mass, SIZE1, SIZE2);
	print_array(mass, SIZE1, SIZE2);
	std::cout << "Количество столбцов, где элементы упорядочены по возрастанию = " << columns(mass, SIZE1, SIZE2) << std::endl;



	std::cout << "Часть 2:" << std::endl << "ДИНАМЕЧЕСКИЙ" << std::endl;

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

	print_array(doubMass, row, col);     //Обращение к функции вывода двумерного массива
	

	int num;
	std::cout << "Введите размерность матрицы: ";
	std::cin >> num;

	int** matrix = new int* [num];
	for (int i = 0; i < num; i++)
	{
		matrix[i] = new int[num];
	}

	//Создаем файловый поток и связываем его с файлом
	std::ifstream file("mass.txt");
	if (file.is_open())
	{
		//считаем сколько чисел в файле
		int count = 0;  //число чисел в файле
		int temp;

		while (!file.eof())// пробегаем пока не встретим конец файла eof
		{
			file >> temp;//в пустоту считываем из файла числа
			count++;// увеличиваем счетчик числа чисел
		}

		//Число чисел посчитано, теперь нам нужно понять сколько
		//чисел в одной строке
		//Для этого посчитаем число пробелов до знака перевода на новую строку 

		//Вначале переведем каретку в потоке в начало файла
		file.seekg(0, std::ios::beg);
		file.clear();




		//seekg это функция, которая позволяет искать произвольную позицию в файле


		file.close();
	}
	else
	{
		//Если открытие файла прошло не успешно
		std::cout << "Файл не найден.";
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


//	int row = 0, col = 0;
//	std::cout << "Введите количество строк: ";
//	std::cin >> row;
//	std::cout << "Введите количество колонок для каждой строки: ";
//	std::cin >> col;
//
//	//память
//	int** doubMass = new int* [row];   //Создание строк
//	for (int i = 0; i < row; i++)
//	{
//		doubMass[i] = new int[col];  //Создание колонок для каждой строки
//	}
//	randomFillMass(doubMass, row, col);      //Обращение к функции заполнения двумерного массива
//	print_array(doubMass, row, col);
//
//	// - память
//	for (int i = 0; i < row; i++)
//	{
//		delete[] doubMass[i];
//	}
//	delete[] doubMass;
//
//	return 0;
//}
