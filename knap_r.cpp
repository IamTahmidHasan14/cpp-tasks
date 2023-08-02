#include <bits/stdc++.h>
using namespace std;

struct item{
    int w, v;
    item(int v, int w){
        this->v = v;
        this->w = w;
    }
    void print_item(){
        printf("(value=%d weight=%d)\n", v, w);
    }
};

void knap_r(int W, item *items, int n){
    int v[W+1], s[W+1];
    v[0] = 0;
    s[0] = -1;
    for (int w=1; w<=W; ++w){
        int q = INT_MIN;
        for (int i=0; i<n; ++i){
            if(items[i].w <= w){
                if (v[w-items[i].w] + items[i].v > q){
                    q=v[w-items[i].w] + items[i].v;
                    s[w]=i;
                }
            }
        }
        v[w]=q;
    }
    printf("%d\n",v[W]);
    while(W>0){
        items[s[W]].print_item();
        W -= items[s[W]].w;
    }
}

int main() {
    item items[] = {item(30,6), item(14,3), item(16,4), item(9,2)};
    int n = 4, W= 10;
    knap_r(W, items, n);
    return 0;
}
