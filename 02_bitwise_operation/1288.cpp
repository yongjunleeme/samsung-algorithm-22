// https://swexpertacademy.com/main/code/problem/problemDetail.do?problemLevel=2&contestProbId=AV18_yw6I9MCFAZN&categoryId=AV18_yw6I9MCFAZN&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=PYTHON&select-1=2&pageSize=10&pageIndex=3
#include <bits/stdc++.h>
using namespace std;

int t;


int main(void){
  cin >> t;
  for(int T = 1; T <= t; T++){
    int n;
    cin >> n;

    int tmp = 0;
    int idx = 1;
    while(1){
      int num = n*idx;

      while(num){
        tmp |= (1 << num % 10);
        num /= 10;

      }
      if(tmp >= ((1 << 10) - 1)) break;
      idx++;

    }
    cout << '#' << T << ' ' << idx*n << '\n';
  }
}
