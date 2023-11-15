#include <iostream>

std::string str;
char alpha;
int q, l, r;
int dp[30][200005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> str;
    std::cin >> q;

    for(int i = 0; i <= 'z'-'a'; i++){
        for(int j = 0; j < str.size(); j++){
            if(str[j] == 'a' + i){
                dp[i][j] =  dp[i][j-1] + 1;
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    for(int i = 0; i < q; i++){
        std::cin >> alpha >> l >> r;
        if(l == 0) std::cout << dp[alpha-'a'][r] << "\n";
        else std::cout << dp[alpha-'a'][r] - dp[alpha-'a'][l-1] << "\n";
    }
}
