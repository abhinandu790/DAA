#include<iostream>
using namespace std;


int ChangeMaking(int coins[], int m, int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = n + 1;
    }
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    return dp[n] > n ? -1 : dp[n];
}

int main() {
    int n, m;
    cout << "Enter the amount : ";
    cin >> n;
    cout << "Enter the number of denominations : ";
    cin >> m;
    
    int coins[m];
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < m; i++) {
        cin >> coins[i];
    }

    int result = ChangeMaking(coins, m, n);
    if (result == -1)
        cout << "Change cannot be made with the given denominations."<<endl;
    else
        cout << "Minimum number of coins required: " << result << endl;
        
    return 0;
}
