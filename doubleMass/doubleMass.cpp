#include <iostream>
#include <fstream>

//Вариант 13
//Ч1 - Количество столбцов, элементы которых упорядочены по возрастанию элементов
//Ч2 - Минимум среди сумм элементов диагоналей параллельных главной диагонали матрицы (матр квадратная)

const int SIZE1 = 4;
const int SIZE2 = 4;

bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
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

	for (int j = 0; j < N; j++)
	{
		bool sequence = 1;
		for (int i = 0; i < M - 1; i++)
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
		count1 = 0,
		count2 = 0;

	min = arr[0][N - 1];
	for (int i = 1; i < N; i++)
	{
		count1 = count2 = 0;
		for (int j = 0; j < N - i; j++)
		{
			count1 += arr[i + j][j];
			count2 += arr[j][i + j];
		}
		if (count1 < min) min = count1;
		if (count2 < min) min = count2;
	}
	return min;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Часть 1:" << std::endl << "СТАТИЧЕСКИЙ" << std::endl;
	try
	{
		std::ifstream massfile;
		massfile.open("mass.txt");

		if (!massfile)
		{
			throw std::exception("Файл не открыт!");
			return 1;
		}
		if (isEmpty(massfile))// файл пуст
		{
			throw std::exception("Файл пуст!");
			return 1;
		}

		int mass[SIZE1][SIZE2];
		for (int i = 0; i < SIZE1; i++)
		{
			for (int j = 0; j < SIZE2; j++)//заполнение массива
			{
				massfile >> mass[i][j];
			}
		}

		print_array(mass, SIZE1, SIZE2);
		std::cout << "Количество столбцов, где элементы упорядочены по возрастанию = " << columns(mass, SIZE1, SIZE2) << std::endl;

		std::cout << "Часть 2:" << std::endl << "ДИНАМИЧЕСКИЙ" << std::endl;

		int num;
		massfile >> num;
		if (num <= 0)
		{
			throw std::exception("Память не может быть выделена!");
			return 1;
		}
		if (std::cin.fail())
		{
			throw std::exception("Некорректный данные в файле!");
		}
		std::cout << "Размерность динамического массива = " << num << std::endl;

		int** matrix = new int* [num];
		for (int i = 0; i < num; i++)
		{
			matrix[i] = new int[num]; //выделение памяти

			for (int j = 0; j < num; j++)//заполнение массива
			{
				massfile >> matrix[i][j];
			}
		}

		//вывод результата второй части в файл
		std::ofstream fout("output.txt");
		if (!fout)
		{
			throw std::exception("Файл не открыт!");
			return 1;
		}

		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				fout << matrix[i][j] << " ";
			}
			fout << std::endl;
		}
		fout << "Минимум среди сумм элементов диагоналей параллельных главной диагонали матрицы = " << minSumm(matrix, num) << std::endl;

		//очистка памяти
		for (int i = 0; i < num; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;

		massfile.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
