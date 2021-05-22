#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#include "King.h"
#define N 6
void main()
{
	int cells, n, cells_in_row, rows, * A, B[N];
	cells_in_row = rows = cells = n = 1;
	size_of_field(&cells, &cells_in_row, &rows);
	A = malloc(cells * sizeof(int));
	field(A, cells, cells_in_row, rows);
	check_inside_field(&n, cells);
	step(n, cells, cells_in_row, B);
	print_steps(B);
	possible_moves(&n, B);
	step(n, cells, cells_in_row, B);
	print_steps(B);
}