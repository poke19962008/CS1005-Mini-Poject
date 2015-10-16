#include <iostream>
#include <array>
using namespace std;

int main(){
	array<int, 3> v1 = {1,2,3};
	array<int, 3> v2 = {1,2,3};

	cout<<(v1 == v2);

	return 0;
}