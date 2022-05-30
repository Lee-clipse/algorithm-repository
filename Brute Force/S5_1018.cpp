#include <iostream>

using namespace std;

int N, M;
char chessboard[8][8];
char bigboard[50][50];

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

void input () {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> bigboard[i][j];
		}
	}
}

void cutBoard (int x, int y) {
	for (int i = x; i < x+8; i++) {
		for (int j = y; j < y+8; j++) {
			chessboard[i-x][j-y] = bigboard[i][j];
		}
	}
} // SUCCESS

int paintBoard () {
	int result = 64;
	
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			
			if ((i+j) % 2 == 0) {
				if (chessboard[i][j] != 'W') cnt++;
			}
			
			else {
				if (chessboard[i][j] != 'B') cnt++;
			}
		}
	} // W start
	result = min(result, cnt);
	
	cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			
			if ((i+j) % 2 == 0) {
				if (chessboard[i][j] != 'B') cnt++;
			}
			
			else {
				if (chessboard[i][j] != 'W') cnt++;
			}
		}
	} // B start
	result = min(result, cnt);
	
	return result;
}

int main () {
	input();
	
	int count = 64;
	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M-8; j++) {
			cutBoard(i, j);
			count = min(count, paintBoard());
		}
	}
	
	/*
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << chessboard[i][j];
		} cout << "\n";
	}
	*/
	
	cout << count;
	
	a();
	return 0;
}
