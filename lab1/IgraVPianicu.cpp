#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

struct que{
    int a[99999];
    int start = 0, tail = 0;

    void push_back(int x){
        a[tail] = x;
        tail++;
    }

    void pop(){
        start++;
    }

    void clear(){
        start = 0;
        tail = 0;
    }

    int front(){
        return a[start];
    }

    int size(){
        return tail - start;
    }

    bool empty(){
        return start == tail;
    }
};

void solve(){
    que q1, q2;
    int first, second, i = 5;
    while(i--){
        cin >> first;
        q1.push_back(first);
    }
    i = 5;
    while(i--){
        cin >> second;
        q2.push_back(second);
    }
    int n = 0;
    while(!q1.empty() && !q2.empty()){
        n++;
        if(n > 1000000){
            cout << "botva";
            return;
        }
        if(q1.front() == 0 && q2.front() == 9){
            q1.push_back(q1.front());
            q1.push_back(q2.front());
            q1.pop(); q2.pop();
        }
        else if(q1.front() == 9 && q2.front() == 0){
            q2.push_back(q1.front());
            q2.push_back(q2.front());
            q1.pop(); q2.pop();
        }
        else{
            if(q1.front() > q2.front()){
            q1.push_back(q1.front());
            q1.push_back(q2.front());
            q1.pop(); q2.pop();
            }
            else if(q1.front() < q2.front()){
                q2.push_back(q1.front());
                q2.push_back(q2.front());
                q1.pop(); q2.pop();
            }
            else if(q1.front() == q2.front()){
                q1.push_back(q1.front());
                q2.push_back(q2.front());
                q1.pop(); q2.pop();
            }
        }
    }
    if(q1.empty()) cout << "second" << " " << n;
    else cout << "first" << " " << n;
}


int main(){
    solve();
}