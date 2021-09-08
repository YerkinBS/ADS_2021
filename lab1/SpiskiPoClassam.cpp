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
    queue<pair<int, str>> q9, q10, q11;
    int grade; str fam;
    while(cin >> grade >> fam){
        if(grade == 9) q9.push(pair<int, str>(grade, fam));
        if(grade == 10) q10.push(pair<int, str>(grade, fam));
        if(grade == 11) q11.push(pair<int, str>(grade, fam));
    }
    while(!q9.empty()){
        cout << q9.front().first << " " << q9.front().second << "\n";
        q9.pop();
    }
    while(!q10.empty()){
        cout << q10.front().first << " " << q10.front().second << "\n";
        q10.pop();
    }
    while(!q11.empty()){
        cout << q11.front().first << " " << q11.front().second << "\n";
        q11.pop();
    }
}


int main(){
    solve();
}