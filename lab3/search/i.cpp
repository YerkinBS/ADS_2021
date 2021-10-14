#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

int bs_f(int arr[], int l, int r, int x, int res){
    if(l > r) return res + 1;
    int m = (l + r) / 2;
    if(arr[m] == x) return bs_f(arr, l, m - 1, x, m);
    if(arr[m] < x) return bs_f(arr, m + 1, r, x, res);
    return bs_f(arr, l, m - 1, x, res);
}

int bs_l(int arr[], int l, int r, int x, int res){
    if(l > r) return res + 1;
    int m = (l + r) / 2;
    if(arr[m] == x) return bs_l(arr, m + 1, r, x, m);
    if(arr[m] < x) return bs_l(arr, m + 1, r, x, res);
    return bs_l(arr, l, m - 1, x, res);
}

void solve(){
    int n, m; cin >> n >> m;
    int a[n], x = 0;
    fr(i, n) cin >> a[i];
    fr(i, m){
        cin >> x;
        if(bs_f(a, 0, n - 1, x, -1) != 0){
            cout << bs_f(a, 0, n - 1, x, -1) << " " << bs_l(a, 0, n - 1, x, -1) << "\n";
        }
        else cout << 0 << "\n";
    }
}


int main(){
    solve();
}