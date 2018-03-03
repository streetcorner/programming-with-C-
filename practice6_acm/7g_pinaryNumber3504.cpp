#include <stdio.h>
#include <string.h>
#include<iostream>


using namespace std;

const int MAX = 50;
long long dp[MAX];

void solve (long long n) {
    bool flag = false;

    for (int i = 40; i; i--) {
        if (n >= dp[i]) {
            printf("1");
            n -= dp[i];
            flag = true;
        } else if (flag)
            printf("0");
    }
    printf("\n");
}

void init () {
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= 40; i++)
        dp[i] = dp[i-1] + dp[i-2];
}

int main () {
    init();
    int ca;
    long long n;
    scanf("%d", &ca);
    for (int i = 0; i < ca; i++) {
        scanf("%lld", &n);
        solve(n);
    }
    return 0;
}
