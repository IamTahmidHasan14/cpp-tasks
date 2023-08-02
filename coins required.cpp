#include <bits/stdc++.h>
using namespace std;

void min_change(int V, int *d, int n){
    int m[V+1], s[V+1];
    m[0] = 0;
    s[0] = -1;
    for (int v=1; v<=V; ++v){
        int q = INT_MAX;
        for (int i=0; i<n; ++i){
            if(d[i]<=v){
                if (q>m[v-d[i]]+1){
                    q=m[v-d[i]]+1;
                    s[v]=i;
                }
            }
        }
        m[v]=q;
    }
    printf("Optimal number of coins required is %d\n",m[V]);
    while(V>0){
        printf("%d ", d[s[V]]);
        V-= d[s[V]];
    }
}

int main() {
    int d[] = {1,5};
    int V = 10;
    min_change(V, d, 2);
    return 0;
}
