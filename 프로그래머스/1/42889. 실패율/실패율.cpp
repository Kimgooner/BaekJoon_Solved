#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int player_reach[502];
int player_clear[502];
int fail_rate[502];

bool cmp(pair<int, double> p1, pair<int, double> p2){
    if(p1.second > p2.second) return true;
    else if(p1.second == p2.second){
        if(p1.first < p2.first) return true;
        else return false;
    }
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> result;
    
    for(int s : stages){
        for(int i = 1; i < s; i++){
            player_clear[i]++;
            player_reach[i]++;
        }
        player_reach[s]++;
    }
    
    for(int i = 1; i <= N; i++){
        if(player_reach[i] == 0) result.push_back({i, 0});
        else{
            result.push_back({i, ((double)(player_reach[i]-player_clear[i]) / (double)player_reach[i])});
        }
    }
    sort(result.begin(), result.end(), cmp);
    
    for(pair<int, double> p : result){
        answer.push_back(p.first);
        // cout << p.second << " ";
    }
    // cout << "\n";
    
    // for(int i : answer){
    //     cout << i << " ";
    // }
    
    return answer;
}