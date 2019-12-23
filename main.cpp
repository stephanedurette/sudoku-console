#include <stdio.h>
#include "main.h"
#include "puzzle.h"

void main() {
	init_puzzle();
	print_puzzle();
	recursive_solve_puzzle();
	print_puzzle();
}