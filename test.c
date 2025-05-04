#include <stdio.h>

#define N 1000
#define ll long long

// xは長さ6の配列
// 返り値は81~91の間
// %を使って余りを求めた方がかっこいいが、1桁目の正確な仕様がわからず、どこに%をつければいいかがわからないので、whileを使っている。
ll check_digit(ll *x) {
	ll y;
	y = 80 + 4 * x[0] + 5 * x[1] + 6 * x[2] + 7 * x[3] + 8 * x[4] + 9 * x[5];
	while(y > 91) {
		y -= 11;
	}
	return y;
}

int main(void) {
	ll X[N][8];
	ll i, j, res, n;
	char s[100];
	// 入力する学籍番号の数
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		// 学籍番号を入力
		scanf("%s", s);
		for (j = 0; j < 8; j++) {
			X[i][j] = s[j] - '0';
		}
	}

	printf("input finish\n");
	for (i = 0; i < n; i++) {
		if (check_digit(X[i]) != 10 * X[i][6] + X[i][7]) {
			printf("[ERROR] input = %lld%lld%lld%lld%lld%lld%lld%lld, check_digit = %lld\n", X[i][0], X[i][1], X[i][2], X[i][3], X[i][4], X[i][5], X[i][6], X[i][7], check_digit(X[i]));
		}	
	}
	printf("calculation finish\n");
	return 0;
	
}
