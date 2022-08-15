// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXRSXf_a9qsDFAXS&categoryId=AXRSXf_a9qsDFAXS&categoryType=CODE&problemTitle=10726&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1
#include <bits/stdc++.h>
using namespace std;

int t;

int main(void){
  cin >> t;
  for(int T = 1; T <= t; T++){
    int n, m;
    cin >> n >> m;
    int tmp = (1 << n) - 1;

    cout << '#' << T << ' ';
    if((tmp & m) == tmp) cout << "ON" << '\n';
    else cout << "OFF" << '\n';
  }
}
