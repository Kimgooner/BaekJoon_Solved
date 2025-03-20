#include <string>
#include <vector>

using namespace std;

int in_count[1000001];
int out_count[1000001];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    for(vector<int> v : edges){
        in_count[v[1]]++;
        out_count[v[0]]++;
    }
    
    int count_sum, center;
    int count_stick = 0, count_donut = 0, count_e = 0;
    
    for(int i = 1; i<= 1000000; i++){
        if(in_count[i] == 0 && out_count[i] >= 2){
            center = i;
            count_sum = out_count[i];
        }
        
        if(in_count[i] >= 2 && out_count[i] == 2){
            count_e++;
        }

        if(in_count[i] >= 1 && out_count[i] == 0){
            count_stick++;
        }
        
        count_donut = count_sum - (count_stick + count_e);
    }
    
    answer.push_back(center);
    answer.push_back(count_donut);
    answer.push_back(count_stick);
    answer.push_back(count_e);
    
    return answer;
}