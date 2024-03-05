#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int N;

int main(){
    cin >> N;
    vector<int> scores;
    int num;
    while (N--){
        cin >> num;
        scores.push_back(num);
    }
    sort(scores.begin(), scores.end());

    int idx = floor((scores.size() * 0.15) + 0.5);

    int size = scores.size() - (2 * idx);
    float sum = 0;
    for(int i = idx; i < scores.size() - idx; i++){
        sum += scores[i];
    }
    if(scores.size() == 0) cout << 0;
    else cout << floor((sum / size) + 0.5);
}