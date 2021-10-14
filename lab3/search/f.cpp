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
    int mx = -9999, mn = 9999;
    int arr[n];
    fr(i, n){
        cin >> arr[i];
        if(arr[i] > mx) mx = arr[i];
        if(arr[i] < mn) mn = arr[i];
    }

    fr(i, n){
        if(arr[i] == mx) cout << mn << " ";
        else cout << arr[i] << " ";
    }
}


int main(){
    solve();
}