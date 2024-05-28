#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
int T, N;
int cnt;

int main(){
    cin >> T;
    while (T--){
        cin >> N;
        multiset<int> pq;
        while (N--){
            char c; int n;
            cin >> c >> n;
            if(c=='I'){
                pq.insert(n);
            }
            else{
                if(!pq.empty()) {
                    if (n == 1) pq.erase(--pq.end());
                    else pq.erase(pq.begin());
                }
            }
        }
        if(pq.empty()) cout << "EMPTY\n";
        else{
            cout << *--pq.end() << " " << *pq.begin() << "\n";
        }
    }
}