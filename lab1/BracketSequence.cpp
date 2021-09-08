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
    string s; cin >> s;
    stack<char> st;
    bool ok = true;
    for(long unsigned int i = 0; i < s.size(); i++){
        if(s[i] == '(') st.push(s[i]);
        else if(s[i] == '{') st.push(s[i]);
        else if(s[i] == '[') st.push(s[i]);
        else{
            if(st.empty()){
                cout << "no";
                return;
            }
            if(s[i] == ')' and st.top() == '(') st.pop();  
            else if(s[i] == '}' and st.top() == '{') st.pop(); 
            else if(s[i] == ']' and st.top() == '[') st.pop();
            else{
                cout << "no";
                return;
            }
        }
    }
    if(st.size() == 0) cout << "yes"; 
    else cout << "no";
}


int main(){
    solve();
}