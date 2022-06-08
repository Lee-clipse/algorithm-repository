#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 2187;

int N;
string star[maxN];

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void printStar (int line, int size, int space = 0) {
	if (space == 1) {
		for (int i = line; i < line+size; i++) {
			for (int j = 0; j < size; j++) star[i] += " ";
		}
		return ;
	}
	
	if (size == 1) {
		star[line] += "*";
		return ;
	}
	
	for (int i = line; i < line+size; i+=size/3) {
		for (int j = 0; j < 3; j++) {
			if (i == line+(size/3) && j == 1) printStar(i, size/3, 1);
			else printStar(i, size/3);
		}
	}
}

int main () {
	cin >> N;
	
	printStar(0, N);
	
	for (int i = 0; i < N; i++) {
		cout << star[i] << "\n";
	}
	
	a();
	return 0;
}
