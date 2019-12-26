#ifndef PuzzleLoader_HEADER
#define PuzzleLoader_HEADER_HEADER

#define MAX_INDEX 51
#include "puzzle.h"

class PuzzleLoader {
	public:
		PuzzleLoader();

		int puzzle[N][N];

		bool loadPuzzle(int index);
		bool loadRandomPuzzle();
	private:
};

#endif
