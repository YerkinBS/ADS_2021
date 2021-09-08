#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

struct st{
    int a[100000];
    int topIndex;
    st(){
        topIndex = -1;
    }

    int top(){
        return a[topIndex];
    }

    void push(int x){
        topIndex++;
        a[topIndex] = x;
    }

    void pop(){
        if(topIndex != -1){
            topIndex--;
        }
    }

    int size(){
        return(topIndex + 1);
    }
};

void solve(){
    str s; getline(cin, s);
    st k; str temp;
    int x1, x2;
    fr(i, s.size()){
        if(s[i] > 47 && s[i] < 58){
            temp += s[i];
            if(i + 1 < s.size() && (s[i+1] > 47 && s[i+1] < 58)) continue;
            else{
                k.push(stoi(temp));
                temp.clear();
            }
        }
        else if(s[i] == '+'){
            x2 = k.top(); k.pop();       
            x1 = k.top(); k.pop();           
            k.push(x1 + x2);
        }
        else if(s[i] == '-'){
            x2 = k.top(); k.pop();
            x1 = k.top(); k.pop();
            k.push(x1 - x2);
        }
        else if(s[i] == '*'){
            x2 = k.top(); k.pop();      
            x1 = k.top(); k.pop();
            k.push(x1 * x2);
        }
    }
    cout << k.top();
}


int main(){
    solve();
}