// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV140YnqAIECFAYD
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n;
char t[105];
vector<char> ans;

void inorder(int idx){
  if(idx > n) return;
  inorder(2*idx);
  cout << t[idx];
  inorder(2*idx+1);
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int T = 1; T <= 10; T++){
    cin >> n;
    for(int i = 1; i <= n; i++){
      int a;
      char c;
      cin >> a;
      cin >> c;
      while(cin.get() != '\n'){
        int b;
        cin >> b;
      }
      t[i] = c;
    }

    cout << "#" << T << " ";
    inorder(1); cout << '\n';
  }
}
