#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int tower[100001][3];
int minDp[3];
int maxDp[3];

int buf[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> tower[i][0] >> tower[i][1] >> tower[i][2];
    }

    for(int i = 1; i <= N; i++){
        copy(begin(minDp), end(minDp), begin(buf));
        minDp[0] = tower[i][0] + min(buf[0], buf[1]);
        minDp[1] = tower[i][1] + min(buf[0], min(buf[1], buf[2]));
        minDp[2] = tower[i][2] + min(buf[1], buf[2]);

        copy(begin(maxDp), end(maxDp), begin(buf));
        maxDp[0] = tower[i][0] + max(buf[0], buf[1]);
        maxDp[1] = tower[i][1] + max(buf[0], max(buf[1], buf[2]));
        maxDp[2] = tower[i][2] + max(buf[1], buf[2]);
    }
    cout << max(maxDp[0], max(maxDp[1], maxDp[2])) << " " << min(minDp[0], min(minDp[1], minDp[2]));
}