#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

vector<pair<int, int>> mp;
stack<int> st[501];
int n, k, x;

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> k;
        while(k--){
            cin >> x;
            st[i].push(x);
        }
        if(i != 1){
            while(!st[i].empty()){
                st[1].push(st[i].top());
                mp.push_back(make_pair(i, 1));
                st[i].pop();
            }
        }
    }
    if(n == 1) return;
    else if(n == 2){
        while(!st[1].empty() && st[1].top() == 2){
            st[2].push(st[1].top());
            mp.push_back(make_pair(1, 2));
            st[1].pop();
        }
        while(!st[1].empty()){
            if(st[1].top() == 2){
                cout << 0;
                return;
            }
            st[1].pop();
        }
    }
    else{
        while(!st[1].empty()){
            if(st[1].top() == 1 || st[1].top() == 2){
                st[2].push(st[1].top());
                mp.push_back(make_pair(1, 2));
            }
            else{
                st[st[1].top()].push(st[1].top());
                mp.push_back(make_pair(1, st[1].top()));
            }
            st[1].pop();
        }
        while(!st[2].empty()){
            if(st[2].top() == 1){
                st[1].push(st[2].top());
                mp.push_back(make_pair(2, 1));
            }
            else{
                st[3].push(st[2].top());
                mp.push_back(make_pair(2, 3));
            }
            st[2].pop();
        }
        while(!st[3].empty() && st[3].top() == 2){
            st[2].push(st[3].top());
            mp.push_back(make_pair(3, 2));
            st[3].pop();
        }
    }
    for(auto i : mp) cout << i.first << " " << i.second << "\n";
}


int main(){
    solve();
}