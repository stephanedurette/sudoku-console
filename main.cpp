#include <stdio.h>
#include "main.h"
#include "puzzle.h"
#include "puzzleLoader.h"

void main() {
	int f[N][N] = {
	{0, 2, 6, 0, 0, 7, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 3, 6},
	{0, 0, 0, 6, 9, 8, 0, 0, 7},
	{0, 0, 0, 0, 5, 0, 2, 0, 8},
	{0, 0, 7, 9, 0, 2, 1, 0, 0},
	{4, 0, 2, 0, 8, 0, 0, 0, 0},
	{2, 0, 0, 1, 4, 9, 0, 0, 0},
	{8, 4, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 8, 0, 0, 4, 5, 0}
	};
	//init_puzzle(startingPuzzle);
	//print_puzzle();
	//recursive_solve_puzzle();
	//print_puzzle();*/
	//int f[N][N];
	//loadPuzzle(f, 1);
	init_puzzle(f);
	print_puzzle();
	recursive_solve_puzzle();
	print_puzzle();

}