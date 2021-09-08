#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

unsigned long int gcd(unsigned long int m, unsigned long int n){
    if(n == 0) return m;
    else return gcd(n, m % n);
}

void solve(){
    unsigned long int m, n; cin >> m >> n;
    cout << gcd(m, n);
}


int main(){
    solve();
}