#include<iostream>
#include<string>
using namespace std;


#define MAX 100  

void LCS_Length(string X, string Y) {
    int m = X.length();  
    int n = Y.length();
    
    int c[MAX][MAX] = {0};
    char b[MAX][MAX] = {0};

    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '\\';  
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = '^';   
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = '<';   
            }
        }
    }

    
    cout << "Length of LCS: " << c[m][n] << endl;

   
    string LCS = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (b[i][j] == '\\') {
            LCS = X[i-1] + LCS; 
            i--;j--; 
        } else if (b[i][j] == '^') {
            i--;  
        } else {
            j--;  
        }
    }

   if(LCS.length()>0)
    cout << "LCS: " << LCS << endl;
    else
    cout<<"No common subsequence found"<<endl;
}

int main() {
    string X, Y;

    
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    
    LCS_Length(X, Y);

    return 0;
}
