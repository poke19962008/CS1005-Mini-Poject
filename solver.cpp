#include <iostream>
#include <array>
#include <vector>
#include <string>
#include "rubik.h"
using namespace std;

// 2 Way BFS Algorithm
vector<string> shortest_path(array<int, 24> init, array<int, 24> fin){
	// Return list of moves to solve from init to fin
	// Ex. <"F", "Li", "U", "Li" ....... >
}

int main(){
	rubik obj;

	// TODO: @saurabh Test for all 6 moves on this set
	array<int, 24> position = {6, 7, 8, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};
	array<int, 24> newPosition = obj.perm_apply("Fi", position);

	for(int i=0;i<24;i++) cout<<newPosition[i]<<" ";
	cout<<endl;

	

	return 0;
}