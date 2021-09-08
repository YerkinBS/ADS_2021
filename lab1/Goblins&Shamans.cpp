#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

struct deq{
    int a[100000];
    int start = 50000, tail = 50000;

    void push_back(int x){
        a[tail] = x;
        tail++;
    }

    void push_front(int x){
        a[start-1] = x;
        start--;
    }

    void pop_front(){
        start++;
    }

    void pop_back(){
        tail--;
    }

    void clear(){
        start = 50000;
        tail = 50000;
    }

    int front(){
        return a[start];
    }

    int back(){
        return a[tail-1];
    }

    int size(){
        return tail - start;
    }

    bool empty(){
        return start == tail;
    }
};

void solve(){
    int n; cin >> n;
    deq dq1, dq2;
    while(n--){
        char c; cin >> c;
        if(c != '-'){
            int g; cin >> g;
            if(c == '+'){
                dq1.push_back(g);
                if(dq1.size() > dq2.size()){
                    dq2.push_back(dq1.front());
                    dq1.pop_front();
                } 
            } 
            if(c == '*'){
                dq1.push_front(g);
                if(dq1.size() > dq2.size()){
                    dq2.push_back(dq1.front());
                    dq1.pop_front();
                } 
            }
        }
        else{
            cout << dq2.front() << "\n";
            dq2.pop_front();
            if(dq1.size() > dq2.size()){
                dq2.push_back(dq1.front());
                dq1.pop_front();
            }
        }
    }
}


int main(){
    solve();
}