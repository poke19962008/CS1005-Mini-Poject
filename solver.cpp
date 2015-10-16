#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "rubik.h"
using namespace std;

// 2 Way BFS Algorithm 
// TODO: change return type to vector<string>
void shortest_path(array<int, 24> init, array<int, 24> fin){
	// Return list of moves to solve from init to fin
	// Ex. <"F", "Li", "U", "Li" ....... >
}

int main(){
	rubik obj;

	array<int, 24> init = {6, 7, 8, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};
	array<int, 24> fin = obj.get_final_position();

	shortest_path(init, fin);

	return 0;
}