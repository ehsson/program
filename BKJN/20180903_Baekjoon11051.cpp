#include <stdio.h>

int dp[1001][1001];
int N, K;

int main(void)
{
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (i == 0 || i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] % 10007 + dp[i][j - 1] % 10007) % 10007;
		}
	}

	scanf_s("%d %d", &N, &K);
	printf("%d\n", dp[K][N]);

	return 0;
}