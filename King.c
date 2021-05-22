#include <stdio.h>
#include "King.h"

//Проверка на целочисленность ввода
void check_int(int *x)
{
	int check;
	while (1)
	{
		check = scanf_s("%d", x);
		if (check < 1)
		{
			while (getchar() != '\n');
			printf("Wrong input!\n");
			continue;
		}
		if (*x <= 0)
		{
			while (getchar() != '\n');
			printf("Enter a positive number!\n");
			continue;
		}
		return;
	}
}

//Функция, помогающая красиво расставить пробелы
void space(int x)
{
	if (x > 0 && x < 10)
		printf("%d  ", x);
	else
		printf("%d ", x);
}

//Размер поля
void size_of_field(int* cells, int* cells_in_row, int* rows)
{
	while (*cells == 1)
	{
		printf("Enter the numbers of cells in one row: ");
		check_int(cells_in_row);
		printf("Enter the numbers of rows: ");
		check_int(rows);
		*cells = (*cells_in_row) * (*rows);
		if (*cells == 1)
			printf("No exit...\n");
	}
}

//Вывод на печать поля
void field(int A[], int cells, int cells_in_row, int rows)
{
	for (int i = 0; i < cells; i++)
		A[i] = i + 1;
	printf("Your field: ");
	for (int i = 0; i < rows; i++)
	{
		printf("\n");
		for (int j = 0; j < i + (i - 2) / 2; j++)
			printf(" ");
		for (int j = 0; j < cells_in_row; j++)
			space(i * cells_in_row + j + 1);
	}
	printf("\n");
	return;
}

//Возможные ходы для клетки, находящейся слева сверху
void left_top(int n, int cells_in_row, int B[])
{
	B[0] = n + 1;
	B[1] = cells_in_row + 1;
}

//Возможные ходы для клетки, находящейся слева снизу
void left_lower(int n, int cells_in_row, int B[])
{
	B[0] = n - cells_in_row;
	B[1] = n - cells_in_row + 1;
	B[2] = n + 1;
}

//Возможные ходы для клетки, находящейся слева, не по краям
void left(int n, int cells_in_row, int B[])
{
	B[0] = n - cells_in_row;
	B[1] = n - cells_in_row + 1;
	B[2] = n + 1;
	B[3] = n + cells_in_row;
}

//Возможные ходы для клетки, находящейся слева
void left_border(int n, int cells, int cells_in_row, int B[])
{
		if (n == 1)
			left_top(n, cells_in_row, B);
		if (n == cells - cells_in_row + 1)
			left_lower(n, cells_in_row, B);
		if (n != 1 && n != cells - cells_in_row + 1)
			left(n, cells_in_row, B);
}

//Возможные ходы для клетки, находящейся справа сверху
void right_top(int n, int cells_in_row, int B[])
{
	B[0] = cells_in_row - 1;
	B[1] = 2 * cells_in_row - 1;
	B[2] = 2 * cells_in_row;
}

//Возможные ходы для клетки, находящейся справа снизу
void right_lower(int n, int cells, int cells_in_row, int B[])
{
	B[0] = cells - cells_in_row;
	B[1] = cells - 1;
}

//Возможные ходы для клетки, находящейся справа, не по краям
void right(int n, int cells_in_row, int B[])
{
	B[0] = n - cells_in_row;
	B[1] = n - 1;
	B[2] = n + cells_in_row - 1;
	B[3] = n + cells_in_row;
}

//Возможные ходы для клетки, находящейся справа
void right_border(int n, int cells, int cells_in_row, int B[])
{
	if (n == cells_in_row)
		right_top(n, cells_in_row, B);
	if (n == cells)
		right_lower(n, cells, cells_in_row, B);
	if (n != cells_in_row && n != cells)
		right(n, cells_in_row, B);
}

//Возможные ходы для клетки, находящейся сверху
void top(int n, int cells_in_row, int B[])
{
	B[0] = n - 1;
	B[1] = n + 1;
	B[2] = n + cells_in_row - 1;
	B[3] = n + cells_in_row;
}

//Возможные ходы для клетки, находящейся снизу
void lower(int n, int cells_in_row, int B[])
{
	B[0] = n - cells_in_row;
	B[1] = n - cells_in_row + 1;
	B[2] = n - 1;
	B[3] = n + 1;
}

//Возможные ходы для клетки, находящейся около центра
void centre(int n, int cells_in_row, int B[])
{
	B[0] = n - cells_in_row;
	B[1] = n - cells_in_row + 1;
	B[2] = n - 1;
	B[3] = n + 1;
	B[4] = n + cells_in_row - 1;
	B[5] = n + cells_in_row;
}

//Возможные ходы для клетки, находящейся не по левой и не по правой стороне
void mid(int n, int cells, int cells_in_row, int B[])
{
	if (n < cells_in_row)
		top(n, cells_in_row, B);
	if (n > cells - cells_in_row + 1)
		lower(n, cells_in_row, B);
	if (n >= cells_in_row && n <= cells - cells_in_row + 1)
		centre(n, cells_in_row, B);
}

//Шаг
void step(int n, int cells, int cells_in_row, int B[])
{
	B[0] = B[1] = B[2] = B[3] = B[4] = B[5] = 0;
	if (cells == 2)//Если поле состоит из двух клеток
	{
		if (n == 1)
			B[0] = 2;
		else
			B[0] = 1;
		return;
	}
	if (n % cells_in_row == 1)
		left_border(n, cells, cells_in_row, B);
	if (n % cells_in_row == 0)
		right_border(n, cells, cells_in_row, B);
	if (n % cells_in_row != 1 && n % cells_in_row != 0)
		mid(n, cells, cells_in_row, B);
}

//Ввод клетки, меньшей количества всех клеток
void check_inside_field(int* n, int cells)
{
	do
	{
		printf("Enter the number of cell less numbers of cells: ");
		check_int(n);
	} while (*n > cells);
}

//Печать возможных ходов для шага
void print_steps(int B[])
{
	printf("Cells where you can move: ");
	for (int i = 0; i < N; i++)
		if (B[i] != 0)
			printf("%d ", B[i]);
	printf("\n");
}

//Ввод клетки, проверка на принадлежность клеткам, в которые можно пойти
void possible_moves(int* n, int B[])
{
	int count;
	do
	{
		count = 0;
		printf("Choose a cell where you can move: ");
		check_int(n);
		for (int i = 0; i < N; i++)
			if (*n != B[i])
				count++;
	} while (count == N);
}