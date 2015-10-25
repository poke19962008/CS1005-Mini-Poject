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
	int L_forward = 1;
	int L_backward  = 1;
	bool found  = false;

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
	map<array<int, 24>, int> backward_level;
	backward_level[fin] = 0;


	map<array<int, 24>, parent_node > forward_parent;
	forward_parent[ini].pos = {};
	forward_parent[ini].move = "NULL";
	map<array<int, 24>, parent_node > backward_parent;
	backward_parent[ini].pos = {};
	backward_parent[ini].move = "NULL";


	vector< array<int, 24> > forward_frontier = {ini};
	vector< array<int, 24> > backward_frontier = {fin};

	while(!found){
		vector <array<int, 24> > forward_next = {};
		vector <array<int, 24> > backward_next = {};

		// Calculate forward frontiers
		for(int i=0; i<forward_frontier.size(); i++){
			vector<string> moves = {"F", "Fi", "L", "Li", "U", "Ui"};

			for (int j = 0; j < moves.size(); ++j){
				array <int, 24> next_move = rubiks.perm_apply(moves[j], forward_frontier[i]);

				if(backward_level.find(next_move) != backward_level.end()){
					found = true;
					break;
				}

				if(forward_level.find(next_move) == forward_level.end()){
					forward_level[next_move] = L_forward;
					forward_parent[next_move].pos = forward_frontier[i];
					forward_parent[next_move].move = moves[j];
					forward_next.push_back(next_move);
				} 

			}
		}
		forward_frontier = forward_next;
		L_forward++;

		if(debug_mode){
			cout<<"Forwawrd Level: "<<L_forward<<endl;
			cout<<"Forward frontier size: "<<forward_frontier.size()<<endl;
		}

		// Calculate backward frontiers
		for(int i=0; i<backward_frontier.size() && !found; i++){
			vector<string> moves = {"F", "Fi", "L", "Li", "U", "Ui"};

			for (int j = 0; j < moves.size(); ++j){
				array <int, 24> next_move= rubiks.perm_apply(moves[j], backward_frontier[i]);

				// if(forward_level.find(next_move) != forward_level.end()){
				// 	found = true;
					
				// 	break;
				// }
				
				if(backward_level.find(next_move) == backward_level.end()){
					backward_level[next_move] = L_backward;
					backward_parent[next_move].pos = backward_frontier[i];
					backward_parent[next_move].move = moves[j];
					backward_next.push_back(next_move);
				}
			}
		}
		backward_frontier = backward_next;
		L_backward++;

		if(debug_mode){
			cout<<"Backward Level: "<<L_backward<<endl;
			cout<<"Backward frontier size: "<<backward_frontier.size()<<endl;
		}

	}

	cout<<backward_parent[rubiks.perm_apply("F", ini)].move;

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
	vector<string> solution = shortest_path_2way(ini, fin, debug_mode);

	// if(solution.size() == 0 )
	// 	cout<<"\nSorry you have entered wrong combination...";
	// else if(solution[0] == "SOLVED_STATE"){
	// 	cout<<"\nSolved State...";
	// }else{
	// 	cout<<"\nSolution: \n";
	// 	for (int i = 0; i < solution.size(); ++i){
	// 		cout<<rubiks.get_move_name(rubiks.get_move(solution[i]))<<endl;
	// 	}
	// }
	return 0;
}