#ifndef	_KING_H
#define _KING_H
#define N 6
//�������� �� ��������������� �����
void check_int(int x);

//�������, ���������� ������� ���������� �������
void space(int x);

//������ ����. ����� - a, ������ - b. �������� ���������� �������� - N
void size_of_field(int* cells, int* cells_in_row, int* rows);

//����� �� ������ ����
void field(int A[], int cells, int cells_in_row, int rows);

//��������� ���� ��� ������, ����������� ����� ������
void left_top(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� ����� �����
void left_lower(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� �����, �� �� �����
void left(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� �����
void left_border(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� ������ ������
void right_top(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� ������ �����
void right_lower(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� ������, �� �� �����
void right(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� ������
void right_border(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� ������
void top(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� �����
void lower(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� ����� ������
void centre(int n, int cells, int cells_in_row, int B[]);

//��������� ���� ��� ������, ����������� �� �� ����� � �� �� ������ �������
void mid(int n, int cells, int cells_in_row, int B[]);

//���
void step(int n, int cells, int cells_in_row, int B[]);

//���� ������, ������� ���������� ���� ������
void check_inside_field(int* n, int cells);

//������ ��������� ����� ��� ����
void print_steps(int B[]);

//���� ������, �������� �� �������������� �������, � ������� ����� �����
void possible_moves(int* n, int B[]);

#endif//_KING_H