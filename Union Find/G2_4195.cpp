#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;

const int maxN = 200002;

int parent[maxN];
int sizes[maxN];

int find(int u) {
	if (parent[u] == u) {
        return u;
    }
    else {
        return parent[u] = find(parent[u]);
    }
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
    
    if (u != v) {
        if (sizes[u] < sizes[v]) swap(u, v);
        sizes[u] += sizes[v];
        parent[v] = u;
    }
}

int main() {
    fastio;

	int T;
	cin >> T;

    map<string, int> name_map;
	while (T--) {
        int F;
		cin >> F;

		// 초기화
		for (int i = 0; i < maxN; i++) {
			sizes[i] = 1;
			parent[i] = i;
		}
		name_map.clear();

		int idx = 1;
		for (int i = 0; i < F; i++) {
			string name1, name2;
			cin >> name1 >> name2;

            if (name_map[name1] == 0) {
                name_map[name1] = idx++;
            }		
			if (name_map[name2] == 0) {
                name_map[name2] = idx++;
            }
            merge(name_map[name1], name_map[name2]);
            
            int p1 = find(name_map[name1]);
            int p2 = find(name_map[name2]);
            
			cout << max(sizes[p1], sizes[p2]) << "\n";	
		}
	}
    
    return 0;
}