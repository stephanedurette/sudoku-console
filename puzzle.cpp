#include "puzzle.h"
#include <stdio.h>

int startingPuzzle[N][N];
int puzzle[N][N];
bool row_set[N][N + 1];
bool col_set[N][N + 1];
bool box_set[N][N + 1];

void init_puzzle(int _startingPuzzle[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			startingPuzzle[i][j] = _startingPuzzle[i][j];
			row_set[i][j + 1] = false;
			col_set[i][j + 1] = false;
			box_set[i][j + 1] = false;
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			int pos = col + row * N;
			if (!can_insert(pos)) {			//insert the starting values
				insert_value(pos, startingPuzzle[row][col]);
			}
		}
	}
}
bool can_insert(int position) {
	int row = position / N;
	int col = position % N;
	return (startingPuzzle[row][col] == 0);
}

bool insert_value(int position, int value) {
	int row = position / N;
	int col = position % N;
	int box_index = get_box_set_index(position);
	//is the insert valid
	if (row_set[row][value] || col_set[col][value] || box_set[box_index][value]) return false;
	//insert the number
	row_set[row][value] = true;
	col_set[col][value] = true;
	box_set[box_index][value] = true;
	puzzle[row][col] = value;

	return true;
}

void reset_value(int position) {
	int row = position / N;
	int col = position % N;
	int value = puzzle[row][col];
	int box_index = get_box_set_index(position);

	row_set[row][value] = false;
	col_set[col][value] = false;
	box_set[box_index][value] = false;
	puzzle[row][col] = 0;
}

void print_puzzle() {
	printf("\n");
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			printf("%d ", puzzle[row][col]);
		}
		printf("\n");
	}
}

void print_sets() {
	for (int i = 0; i < N; i++) {
		printf("Section %d:\n", i);
		printf("\tRow:\t");
		for (int j = 1; j <= N; j++) {
			printf("%d ", row_set[i][j]);
		}
		printf("\n");
		printf("\tCol:\t");
		for (int j = 1; j <= N; j++) {
			printf("%d ", col_set[i][j]);
		}
		printf("\n");
		printf("\tBox:\t");
		for (int j = 1; j <= N; j++) {
			printf("%d ", box_set[i][j]);
		}
		printf("\n");
	}
}

int get_box_set_index(int index) {
	int col = index % N;
	int row = index / N;
	return col / 3 + 3 * (row / 3);
}

bool recursive_solve_puzzle() {
	return solve_puzzle(0);
}

bool solve_puzzle(int position) {
	if (position == N * N) {
		return true;
	}
	if (!can_insert(position)) {
		return solve_puzzle(position + 1);
	}
	for (int i = 1; i <= N; i++) {
		if (insert_value(position, i)) {
			if (solve_puzzle(position + 1)) {
				return true;
			}
			else {
				reset_value(position);
			}
		}
	}
	return false;
}