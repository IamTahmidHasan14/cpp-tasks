#include <bits/stdc++.h>
using namespace std;

int rod_cutting(int *p, int n){
    int r[n+1], s[n+1], n_temp = n;
    r[0] = 0;
    s[0] = -1;
    for (int j=1; j<=n; ++j){
        int q = INT_MIN;
        for (int i=1; i<=j; ++i){
            if(p[i]+ r[j-1]>q){
                q= p[i]+r[j-1];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    while(n>0){
        printf("%d ", s[n]);
        n-= s[n];
    }
    return r[n_temp];
}

int main() {
    int n;
    scanf("%d", &n);

    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int q = rod_cutting(p, n);
    printf("\nOptimal revenue=%d\n", q);
    return 0;
}
