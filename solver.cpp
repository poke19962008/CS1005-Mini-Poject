#include <iostream>
#include <array>
#include "rubik.h"

using namespace std;

int main(){
	rubik obj;

	// TODO: @saurabh Test for all 6 moves on this set
	array<int, 24> position = {6, 7, 8, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};
	array<int, 24> newPosition = obj.perm_apply("F", position);

	for(int i=0;i<24;i++) cout<<newPosition[i]<<" ";
	cout<<endl;

	//Testing get_move and get_move_name
	array<int, 24> L_move = obj.get_move("L");
	cout<<"Left Move: ";
	for (int i = 0; i < 24; ++i) cout<<L_move[i];
	cout<<endl;
	cout<<"Left Move Name: "<<obj.get_move_name(L_move)<<endl;
	
	return 0;
}