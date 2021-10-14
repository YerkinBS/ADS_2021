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
    int n, m; cin >> n >> m;
    int k[n][m];
    int row_mn[n], mn;
    fr(i, n){
        mn = 99999;
        fr(j, m){
            cin >> k[i][j];
            if(mn > k[i][j]) mn = k[i][j];
        }
        row_mn[i] = mn;
    }
    
    int cnt = 0, mx;
    int column_mx[m];
    fr(j, m){
        mx = -99999;
        fr(i, n){
            if(k[i][j] > mx) mx = k[i][j];
        }
        column_mx[j] = mx;
    }

    fr(i, n){
        fr(j, m){
            if(k[i][j] == row_mn[i] && k[i][j] == column_mx[j]) cnt++;
        }
    }
    cout << cnt;
}


int main(){
    solve();
}