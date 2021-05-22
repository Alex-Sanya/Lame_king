#ifndef	_KING_H
#define _KING_H
#define N 6
//Проверка на целочисленность ввода
void check_int(int x);

//Функция, помогающая красиво расставить пробелы
void space(int x);

//Размер поля. Длина - a, ширина - b. Конечное количество клеточек - N
void size_of_field(int* cells, int* cells_in_row, int* rows);

//Вывод на печать поля
void field(int A[], int cells, int cells_in_row, int rows);

//Возможные ходы для клетки, находящейся слева сверху
void left_top(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся слева снизу
void left_lower(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся слева, не по краям
void left(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся слева
void left_border(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся справа сверху
void right_top(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся справа снизу
void right_lower(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся справа, не по краям
void right(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся справа
void right_border(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся сверху
void top(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся снизу
void lower(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся около центра
void centre(int n, int cells, int cells_in_row, int B[]);

//Возможные ходы для клетки, находящейся не по левой и не по правой стороне
void mid(int n, int cells, int cells_in_row, int B[]);

//Шаг
void step(int n, int cells, int cells_in_row, int B[]);

//Ввод клетки, меньшей количества всех клеток
void check_inside_field(int* n, int cells);

//Печать возможных ходов для шага
void print_steps(int B[]);

//Ввод клетки, проверка на принадлежность клеткам, в которые можно пойти
void possible_moves(int* n, int B[]);

#endif//_KING_H