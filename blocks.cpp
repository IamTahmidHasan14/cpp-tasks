#include<bits/stdc++.h>
using namespace std;
struct block{
    int sum, start, end;
    block(int sum, int start, int end){
        this->sum = sum;
        this->start = start;
        this->end = end;
    }
    void print_block(){
        printf("Sum: %d \n\nStarts at: %d \nEnds at: %d\n", sum, start, end);
    }
};
block max_crossing(int *ara, int l, int m, int h){
    int sum=0;
    int max_left, max_right;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    for(int i=m; i>=l; --i){
        sum+=ara[i];
        if(sum>left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum=0;
    for(int i=m+1; i<=h; ++i){
        sum += ara[i];
        if(sum>right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    return block(right_sum + left_sum, max_left, max_right);
}
block max_subarray(int *ara, int l, int h){
    if(l==h) return block(ara[l], l, h);
    int m = (l+h)/2;
    block left_block = max_subarray(ara, l, m);
    block right_block = max_subarray(ara, m+1, h);
    block cross_block = max_crossing(ara, l, m, h);
    if(left_block.sum > right_block.sum && left_block.sum > cross_block.sum) return left_block;
    else if(right_block.sum > left_block.sum && right_block.sum > cross_block.sum) return right_block;
    else return cross_block;
}
int main()
{
    int ara[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(ara) / sizeof(ara[0]);
    (max_subarray(ara, 0, n-1)).print_block();
    return 0;
}
