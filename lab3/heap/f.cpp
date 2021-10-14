#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()
#define N 100001

struct heap{
    int val[N];
    int hs;

    heap(){
        hs = 0;
    }

    int get_max(){ 
        return val[0];
    }

    void add(int x){
        int i = hs++;
        val[i] = x;
        int p = (i - 1) / 2; 
        while(i && val[i] > val[p]){
            swap(val[i], val[p]);
            i = p;
            p = (i - 1) / 2; 
        }
    }

    void del(){
        val[0] = val[--hs];
        int i = 0;
        while(2 * i + 1 < hs){
            int c1 = 2 * i + 1;
            int c2 = 2 * i + 2;
            int mp = c1;
            if(c2 < hs){
                if(val[c2] < val[c1]) mp = c2;
            }
           
            if(val[i] > val[mp]){
                swap(val[i], val[mp]);
                i = mp;
            }
            else break;
        }
    }

    void print(){
        fr(i, hs){
            cout << val[i] << " ";
        }
        cout << "\n";
    }

    void Sift_Up(int ind, int x){
        val[--ind] += x;
        int i = ind;
        int p = (i - 1) / 2; 
        while(i && val[i] > val[p]){
            swap(val[i], val[p]);
            i = p;
            p = (i - 1) / 2; 
        }
        cout << ++i << "\n";
    }

    void Sift_Down(int ind, int x){
        val[--ind] -= x;
        
        while(2 * ind + 1 < hs){
            int c1 = 2 * ind + 1;
            int c2 = 2 * ind + 2;
            
            if(c2 < hs && val[c2] > val[c1] && val[c2] > val[ind]){
                swap(val[c2], val[ind]);
                ind = c2;
            }
            else if(val[c1] > val[ind]){
                swap(val[c1], val[ind]);
                ind = c1;
            }
            else break;
        }
        
        cout << ++ind << "\n";
    }
};


void solve(){
    int n, el; cin >> n;
    heap hp;
    while(n--){
        cin >> el;
        hp.add(el);
    }
    hp.print();
}


int main(){
    solve();
}