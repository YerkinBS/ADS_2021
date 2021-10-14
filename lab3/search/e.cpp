#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()


void solve(){
    int n, x; cin >> n;
    int mx = -99999, sec_mx;
    while(n--){
        cin >> x;
        if(x > mx){
            sec_mx = mx;
            mx = x;
        }
        else if(x > sec_mx && x < mx) sec_mx = x;
    }
    cout << sec_mx;
}


int main(){
    solve();
}