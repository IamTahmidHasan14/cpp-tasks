#include <bits/stdc++.h>
using namespace std;

int rod_cutting(int *p, int *r, int n){
    if(r[n] >= 0)
        return r[n];
    int q;
    if(n == 0)
        q = 0;
    else{
        q = INT_MIN;
        for(int i = 1; i <= n; ++i){
            q = max(q, rod_cutting(p, r, n - i) + p[i]);
        }
    }
    r[n] = q;
    return r[n];
}

int main() {
    int n;
    scanf("%d", &n);
    int r[n+1];
    for(int i = 1; i <= n; ++i){
        r[i] = INT_MIN;
    }
    r[0] = 0;
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int q = rod_cutting(p, r, n);
    printf("%d\n", q);
    return 0;
}
