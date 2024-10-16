#include<iostream>
using namespace std;


int Coincollection(int n, int m, int C[100][100]) {
    int F[100][100];
    
    F[1][1] = C[1][1];
    
    for (int j = 2; j <= m; j++) {
        F[1][j] = F[1][j - 1] + C[1][j];
    }

    for (int i = 2; i <= n; i++) {
        F[i][1] = F[i - 1][1] + C[i][1];
        for (int j = 2; j <= m; j++) {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
        }
    }

    return F[n][m];
}

int main() {
    int n, m;
    cout << "Enter the number of rows : ";
    cin >> n;
    cout << "Enter the number of columns : ";
    cin >> m;

    int C[100][100];
    cout << "Enter the coin matrix (1 for coin, 0 for no coin):"<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> C[i][j];
        }
    }

    int result = Coincollection(n, m, C);
    cout << "Maximum coins collected: " << result << endl;

    return 0;
}
