#include <iostream>
#include <array>
#include "rubik.h"

using namespace std;

int main(){
	rubik obj;
	array<int, 24> position = {6, 7, 8, 20, 18, 19, 3, 4, 5, 16, 17, 15, 0, 1, 2, 14, 12, 13, 10, 11, 9, 21, 22, 23};
	array<int, 24> newPosition = obj.perm_apply("F", position);

	for(int i=0;i<24;i++) cout<<newPosition[i]<<" ";
	cout<<endl;
	return 0;
}