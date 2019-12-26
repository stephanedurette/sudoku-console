#include <stdio.h>
#include "puzzle.h"
#include "puzzleLoader.h"

void main() {

	PuzzleLoader puzzleLoader;
	puzzleLoader.loadRandomPuzzle();
	Sudoku newSudoku(puzzleLoader.puzzle);

	newSudoku.printPuzzle();
	newSudoku.solvePuzzle();
	newSudoku.printPuzzle();

}