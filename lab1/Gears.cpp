#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

unsigned long int gcd(unsigned long int n, unsigned long int k){
    if(k == 0) return n;
    else return gcd(k, n % k);
}

unsigned long int lcm(unsigned long int n, unsigned long int k){
    return((n * k) / gcd(n, k));
}

void solve(){
    unsigned long int n, k; cin >> n >> k;
    cout << lcm(n, k);
}


int main(){
    solve();
}