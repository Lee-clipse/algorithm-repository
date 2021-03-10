#include <iostream>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

int main () {

	a();
	return 0;
}
