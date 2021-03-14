#include <iostream>
#include <cstring>

using namespace std;

void a(){int a=0;for(int i=0;i<4000000000;i++)a=i*i;}

const int maxN = 1000;

int N, K;
long long cache[maxN][maxN];

// By Bottom-Up
long long choose (int times, int got) {
	long long& ret = cache[times][got];
	
	// End case
	if (times == N) {
		if (got == K) return 1;
		else return 0;
	}
	
	// if visited, return cache value
	if (ret != -1) return ret;
	
	// put value in cahce
	ret = choose(times+1, got+1) + choose(times+1, got);
	
	return ret;
}

long long Bionomial_Coefficient (int N, int K) {
	// Impossible case
	if (K > N) return 0;
	
	// Initialize cache to -1
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			cache[i][j] = -1;
		}
	}
	
	return choose(0, 0);
}

int main () {
	printf("Put N and K: ");
	scanf("%d%d", &N, &K);
	
	printf("%dC%d = %lld", N, K, Bionomial_Coefficient(N, K));
	
	a();
	return 0;
}
