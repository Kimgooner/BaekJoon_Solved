#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dp[4005][4005];

int main(){
    string str1, str2;

    cin >> str1 >> str2;

    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = 0;
        }
    }

    int result = 0;
    for(int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            result = max(result, dp[i][j]);
        }
    }
    cout << result;
}
