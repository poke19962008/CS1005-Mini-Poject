/***
** AUTHOR: poke19962008
*/

#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <map>
#include "rubik.h"
using namespace std;

rubik rubiks;

// TODO: 2 Way BFS Algorithm 
// TODO: change return type to vector<string>
// 1 Way BFS Algorithm
vector<string> shortest_path(array<int, 24> ini, array<int, 24> fin){
	rubik rubiks;
	int L=1;
	bool found = false;

	struct parent_node{
		array<int, 24> pos;
		string move;
	};

	map<array<int, 24>, int> level;
	level[ini] = 0;

	map<array<int, 24>, parent_node > parent;
	parent[ini].pos = {};
	parent[ini].move = "NULL";

	vector< array<int, 24> > frontier = {ini};
	
	while(frontier.size() && !found){
		vector< array<int, 24> > next = {};

		for (int i = 0; i < frontier.size() && !found; ++i){
			vector<string> moves = {"F", "Fi", "L", "Li", "U", "Ui"};

			for (int j = 0; j < moves.size(); ++j){
				array<int, 24> next_move = rubiks.perm_apply(moves[j], frontier[i]);

				if(next_move == fin){
					found = true;
					parent[next_move].pos = frontier[i];
					parent[next_move].move = moves[j];
					break;
				}

				if(level.find(next_move) == level.end()){
					level[next_move] = L;
					parent[next_move].pos = frontier[i];
					parent[next_move].move = moves[j];
					next.push_back(next_move);
				}
			}
		}
		// For Debuging
		// cout<<"L="<<L<<"	frontier="<<frontier.size()<<endl;
		frontier = next;
		L++;
	}

	vector<string> solution = {};
	if(found){
		parent_node tmp = parent[fin];

		while (true){
			if(tmp.move == "NULL") break;
			solution.insert(solution.begin(), tmp.move);
			tmp = parent[tmp.pos];
		}

	}else{
		cout<<"Sorry you have entered wrong combination...";
	}	

	return solution;
}

int main(){
	// array<int, 24> ini = {6, 7, 8, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};
	array<int, 24> fin = rubiks.get_final_position();
	array<int, 24> ini = rubiks.perm_apply("F", rubiks.get_final_position());
	ini = rubiks.perm_apply("L", ini);

	
	vector<string> solution = shortest_path(ini, fin);

	return 0;
}