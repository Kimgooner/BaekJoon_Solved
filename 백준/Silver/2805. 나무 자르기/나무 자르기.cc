#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
long long N, M;
long long res;
vector<long long> trees;

bool compare(long long i1, long long i2){
    return i1 > i2;
}

void binary_search(long long start, long long end, long long find){
    if(start > end) {
        cout << res;
        return;
    }
    long long pivot = (start + end)/2;
    long long sum = 0;
    for(long long v : trees){
        if(v <= pivot) break;
        sum += (v - pivot);
    }
    if(sum >= M) {
        res = pivot;
        binary_search(pivot+1, end, find);
    }
    else {
        binary_search(start, pivot-1, find);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    long long cnt = N, input;
    while (cnt--){
        cin >> input;
        trees.push_back(input);
    }

    sort(trees.begin(), trees.end(), compare);
    binary_search(0l, 1000000000, M);
}