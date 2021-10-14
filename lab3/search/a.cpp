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
    int arr[n];
    fr(i, n) cin >> arr[i];
    int x; cin >> x;
    fr(i, n){
        if(arr[i] == x) cout << i + 1 << " ";
    }
}


int main(){
    solve();
}