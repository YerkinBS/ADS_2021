#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef vector<int> vi;
typedef vector<bool> vb;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fr(i, n) for(int i = 0; i < n; i++)
#define rall(x) (x).rbegin(), (x).rend()

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    private:
        node * _root;

        node * add(node * current, int x){
            if(current == NULL) return new node(x);
                
            if(current->val < x){
                current->right = add(current->right, x);
            }

            if(current->val > x){
                current->left = add(current->left, x);
            }
            return current;
        }

        bool find(node * current, int x){
            if(current == NULL) return false;
            if(current->val == x) return true;
            if(current->val > x) return find(current->left, x);
            return find(current->right, x);
        }

        void print(node * current, int level){
            if(current != NULL){
                print(current->left, level + 1);
                cout << current->val << " " << level << "\n";
                print(current->right, level + 1);
            }
        }

        int rightmost(node * current){
            if(current == NULL) return -1;

            if(current->right == NULL) return current->val;
            return rightmost(current->right);         
        }

        int leftmost(node * current){
            if(current == NULL) return -1;

            if(current->left == NULL) return current->val;
            return leftmost(current->left);
        }

        node * del(node * current, int x){
            if(current == NULL) return NULL;
            if(current->val == x){
                if(current->right == NULL and current->left == NULL){
                    delete current;
                    return NULL;
                }
                else if(current->left != NULL and current->right == NULL){
                    node * temp = current->left;
                    delete current;
                    return temp;
                }
                else if(current->right != NULL and current->left == NULL){
                    node * temp = current->right;
                    delete current;
                    return temp;
                }
                else if(current->left != NULL and current->right != NULL){
                    current->val = rightmost(current->left);
                    current->left = del(current->left, current->val);
                }
            }
            else if(current->val < x){
                current->right = del(current->right, x);
                return current;
            }
            else if(current->val > x){
                current->left = del(current->left, x);
                return current;
            }
            return current;
        }

        int size(node * current){
            if(current == NULL) return 0;
            return size(current->left) + 1 + size(current->right);
        }

        int height(node * current){
            if(current == NULL) return 0;

            int left_height = height(current->left);
            int right_height = height(current->right);

            return max(left_height, right_height) + 1;
        }

        bool check_heights(node * current){
            if(current == NULL) return true;
            int x = abs(height(current->right) - height(current->left));
            if(x <= 1 and check_heights(current->left) and check_heights(current->right)){
                return true;
            }
            return false;
        }

    public:
        bst(){
            _root = NULL; 
        }

        void add(int x){
            node * res = add(_root, x);
            if(_root == NULL) _root = res;
        }

        void del(int x){
            del(_root, x);
        }

        bool find(int x){
            return find(_root, x);
        }

        void print(){
            print(_root, 1);
            cout << "\n";
        }

        int size(){
            return size(_root);
        }

        int rightmost(){
            return rightmost(_root);
        }

        int leftmost(){
            return leftmost(_root);
        }

        int height(){
            return height(_root);
        }

        bool check_balance(){
            return check_heights(_root);
        }
};

void solve(){
    bst * tree = new bst();
    int x;
    while(true){
        cin >> x;
        if(x != 0) tree->add(x);
        else break;
    }
    cout << ((tree->check_balance()) ? "YES" : "NO");
}

int main(){
    solve();
}