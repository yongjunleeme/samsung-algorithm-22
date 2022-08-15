// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWBOHEx66kIDFAWr&categoryId=AWBOHEx66kIDFAWr&categoryType=CODE
#include <bits/stdc++.h>
using namespace std;

int d[1002][1002];
string a,b;
int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cin >> a >> b;

        int len_a = a.length();
        int len_b = b.length();

        for (int i = 1; i <= len_a; i++) {
            for (int j = 1; j <= len_b; j++) {
                if (a[i - 1] == b[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
                else {
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
                }
            }
        }

        cout << "#" << tc << " " << d[len_a][len_b] << "\n";
    }

    return 0;
}
