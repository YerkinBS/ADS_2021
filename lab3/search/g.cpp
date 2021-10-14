#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

int bs(int arr[], int l, int r, int x){
    if(l > r) return -1;
    int m = (l + r) / 2;
    if(arr[m] == x) return m;
    if(arr[m] < x) return bs(arr, m + 1, r, x);
    return bs(arr, l, m - 1, x);
}

void solve(){
    int n, k; cin >> n >> k;
    int a[n], x, ans;
    fr(i, n) cin >> a[i];
    fr(i, k){
        cin >> x;
        ans = bs(a, 0, n - 1, x);
        cout << ((ans != -1) ? "YES\n" : "NO\n");
    }
}


int main(){
    solve();
}