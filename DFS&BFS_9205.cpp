#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

struct LOC {
	int x;
	int y;
	bool visited;
};

const int maxLoc = 1000;
const int maxN 	 = 100;

int N;
int endX, endY;

vector <LOC> map;

void setting () {
	cin >> N;
	for (int i = 0; i < N+2; i++) {
		int x, y;
		cin >> x >> y;
		map.push_back({x, y, false});
	}
	endX = map.back().x;
	endY = map.back().y;
}

void BFS () {
	queue <LOC> q;
	map[0].visited = true;
	q.push(map[0]);
	
	while (!q.empty()) {
		int xx = q.front().x;
		int yy = q.front().y;
		q.pop();
		
		if (xx == endX && yy == endY) {
			cout << "happy\n";
			return ;			
		}
		
		for (int i = 1; i < map.size(); i++) {
			int nx = map[i].x;
			int ny = map[i].y;
			
			if (abs(nx-xx) + abs(ny-yy) <= maxLoc && map[i].visited != true) {
				map[i].visited = true;
				q.push(map[i]);
			}
		}
	}
	
	cout << "sad\n";
	return ;
}

int main () {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		setting();
		BFS();
	}
	
	a();
	return 0;
}
