#define N 9 

void init_puzzle();

bool insert_value(int position, int value);

void reset_value(int position);

void print_sets();

void print_puzzle();

bool can_insert(int position);

int get_box_set_index(int index);

bool recursive_solve_puzzle();

bool solve_puzzle(int position);
