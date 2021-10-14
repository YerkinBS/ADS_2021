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
    int n; cin >> n;
    int mx = -99999, ind;
    fr(i, n){
        int x; cin >> x;
        if(x > mx){
            mx = x;
            ind = i + 1;
        }
    }
    cout << ind;
}

int main(){
    solve();
}