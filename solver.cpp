#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
#include "rubik.h"
using namespace std;

// 2 Way BFS Algorithm 
// TODO: change return type to vector<string>
void shortest_path(array<int, 24> ini, array<int, 24> fin){
	rubik obj;
	int L=1;
	bool found = false;

	map<array<int, 24>, int> level;
	level[ini] = 0;

	map<array<int, 24>, map<string, array<int, 24>> > parent;
	parent[ini] = {};

	vector< array<int, 24> > frontier = {ini};
	
	while(frontier.size() && !found){
		vector< array<int, 24> > next = {};

		for (int i = 0; i < frontier.size() && !found; ++i){
			vector<string> moves = {"F", "Fi", "L", "Li", "U", "Ui"};

			for (int j = 0; j < moves.size(); ++j){
				array<int, 24> next_move = obj.perm_apply(moves[j], frontier[i]);

				if(next_move == fin){
					found = true;
					parent[next_move][moves[j]] = frontier[i];
					break;
				}

				if(level.find(next_move) == level.end()){
					level[next_move] = L;
					parent[next_move][moves[j]] = frontier[i];
					next.push_back(next_move);
				}
			}
		}
		cout<<"L="<<L<<"	frontier="<<frontier.size()<<endl;
		frontier = next;
		L++;
	}

	if(found){
		// vector<string> solution;
		// array<int, 24> tmp = {fin};

		// for (int i = 0; i < count; ++i){
		// 	tmp = parent[tmp];

		// }
	}else{
		cout<<"Sorry you have entered wrong combination...";
	}

	// Return list of moves to solve from init to fin
	// Ex. <"F", "Li", "U", "Li" ....... >
}

int main(){
	rubik obj;

	// array<int, 24> ini = {6, 7, 8, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};
	array<int, 24> fin = obj.get_final_position();
	array<int, 24> ini = obj.perm_apply("F", obj.get_final_position());

	shortest_path(ini, fin);

	return 0;
}