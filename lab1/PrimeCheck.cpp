#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

bool isPrime(unsigned long int n){
    for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return false;
    return true;
}

void solve(){
    int n; cin >> n;
    if(isPrime(n)) cout << "prime";
    else cout << "composite";
}


int main(){
    solve();
}