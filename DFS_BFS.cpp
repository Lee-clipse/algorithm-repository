void DFS (int start) {
	stack <int> s;
	
	visited[start] = true;
	s.push(start);
	
	printf("%d ", start);
	
	while (!s.empty()) {
		int cur = s.top();
		s.pop();
		
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			
			if (visited[next] != true) {
				visited[next] = true;
				
				s.push(cur);
				s.push(next);
				
				printf("%d ", next);
				break;
			}
		}
	}
	
	memset(visited, 0, sizeof(visited));
	cout << endl;
}








void BFS (int start) {
	queue <int> q;
	
	visited[start] = true;
	q.push(start);
	printf("%d ", start);
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			
			if (visited[next] != true) {
				visited[next] = true;
				q.push(next);
				
				printf("%d ", next);
			}
		}
	}
	
	memset(visited, 0, sizeof(visited));
	cout << endl;
}








