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

// 1 Way BFS Algorithm
vector<string> shortest_path(array<int, 24> ini, array<int, 24> fin, bool debug_mode){
	int L=1;
	bool found = false;
	vector<string> solution = {};

	if(ini == fin){
		solution.push_back("SOLVED_STATE");
		 return solution;
	}

	if (debug_mode)
		cout<<"Debuging Mode\n";

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
		if(debug_mode)
			cout<<"Level="<<L<<"	Frontier Nodes="<<frontier.size()<<endl;
		frontier = next;
		L++;
	}

	if(found){
		parent_node tmp = parent[fin];

		while (true){
			if(tmp.move == "NULL") break;
			solution.insert(solution.begin(), tmp.move);
			tmp = parent[tmp.pos];
		}

	}	

	return solution;
}

vector<string> shortest_path_2way(array<int, 24> ini, array<int, 24> fin, bool debug_mode){
	vector<string> solution = {};

	if(ini == fin){
		solution.push_back("SOLVED_STATE");
		 return solution;
	}

	if (debug_mode)
		cout<<"Debuging Mode\n";

	struct parent_node{
		array<int, 24> pos;
		string move;
	};

	map<array<int, 24>, int> forward_level;
	forward_level[ini] = 0;
	map<array<int, 24>, int> backward_forward;
	backward_forward[ini] = 0;


	map<array<int, 24>, parent_node > forward_parent;
	forward_parent[ini].pos = {};
	forward_parent[ini].move = "NULL";
	map<array<int, 24>, parent_node > backward_parent;
	backward_parent[ini].pos = {};
	backward_parent[ini].move = "NULL";


	vector< array<int, 24> > forward_frontier = {ini};
	vector< array<int, 24> > backward_frontier = {fin};


	return solution;
}

int main(){

	// Test Case #1 [TESTED]
	// God's Number: 14
	// Solution : 
		// Front Clockwise
		// Front Clockwise
		// Upper Anticlockwise
		// Left Clockwise
		// Upper Anticlockwise
		// Front Clockwise
		// Left Anticlockwise
		// Upper Clockwise
		// Left Anticlockwise
		// Front Anticlockwise
		// Left Anticlockwise
		// Upper Clockwise
		// Left Anticlockwise
		// Front Anticlockwise
	// array<int, 24> ini = {6, 7, 8, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};

	// Test Case #2 [TESTED]
	// God's Number: 2
	// Solution: 
		// Left Anticlockwise
		// Front Anticlockwise

	// Test Case #3 [ ]
	// God's Number: 
	// Solution: 
	// array<int, 24> ini = {7, 8, 6, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};

	array<int, 24> ini = rubiks.perm_apply("F", rubiks.get_final_position());
	ini = rubiks.perm_apply("L", ini);

	array<int, 24> fin = rubiks.get_final_position();

	bool debug_mode = false;
	vector<string> solution = shortest_path(ini, fin, debug_mode);

	if(solution.size() == 0 )
		cout<<"\nSorry you have entered wrong combination...";
	else if(solution[0] == "SOLVED_STATE"){
		cout<<"\nSolved State...";
	}else{
		cout<<"\nSolution: \n";
		for (int i = 0; i < solution.size(); ++i){
			cout<<rubiks.get_move_name(rubiks.get_move(solution[i]))<<endl;
		}
	}
	return 0;
}