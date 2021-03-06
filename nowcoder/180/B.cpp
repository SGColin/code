#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct FastIO {
    static const int S = 1e7;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) exit(0);
        return buf[pos++];
    }
    inline int operator () () {
        int c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline ll operator ! () {
        int c = xchar(); ll x = 0;
        while (c <= 32) c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void operator () (ll x) {
        if (x < 0) wchar('-'), x = -x;
        char s[24];
        int n = 0;
        while (x || !n) s[n++] = '0' + x % 10, x /= 10;
        while (n--) wchar(s[n]);
        wchar('\n');
    }
    ~FastIO()
    {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
}; // io;

const int N = 1e5 + 10;

double p[N], f[N][101]; int n, k;

int main() {
	scanf("%d%d", &n, &k);
	double sum = 0;
	for(int i = 1 ; i <= n ; ++ i) scanf("%lf", &p[i]), sum += p[i];
	printf("%.4lf\n", sum);
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; ++ i) {
		f[i][0] = f[i - 1][0] * (1 - p[i]);
		for(int j = 1 ; j <= k ; ++ j) {
			f[i][j] = f[i - 1][j] * (1 - p[i]) + f[i - 1][j - 1] * p[i];
		}
	}
	printf("%.4lf\n", f[n][k]);
}
