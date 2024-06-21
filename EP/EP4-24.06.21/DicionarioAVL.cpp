#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename keyType, typename valueType>
class AVLNode {
   public:
    AVLNode(const keyType setkey, const valueType& setValue) {
        this->key = setkey;
        this->value = setValue;
        this->height = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    int height;
    keyType key;
    valueType value;
    AVLNode* left;
    AVLNode* right;
};

template <typename keyType, typename valueType>
class AVL {
   public:
    AVL() {
        this->root = nullptr;
        this->__size = 0;
    }


    valueType find(keyType key) { return findhelp(this->root, key); }

    void insert(keyType key, valueType value) {
        this->root = inserthelp(this->root, key, value);
        this->__size++;
    }

    vector<valueType> preorder() {
        vector<valueType> tmp;
        preorderhelp(this->root, &tmp);

        return tmp;
    }

    AVLNode<keyType, valueType>* root;

   private:
    int __size;

    void preorderhelp(AVLNode<keyType, valueType>* rt, vector<valueType>* v) {
        if (rt != nullptr) {
            v->push_back(rt->value);

            preorderhelp(rt->left, v);
            preorderhelp(rt->right, v);
        }
    }

    int h(AVLNode<keyType, valueType>* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
    }

    int getBalance(AVLNode<keyType, valueType>* node) {
        if (node == nullptr) {
            return 0;
        }
        return h(node->left) - h(node->right);
    }

    AVLNode<keyType, valueType>* inserthelp(AVLNode<keyType, valueType>* rt,
                                            keyType key, valueType value) {
        if (rt == nullptr) {
            return new AVLNode<keyType, valueType>(key, value);
        }

        if (rt->key > key) { 
            rt->left = inserthelp(rt->left, key, value);
        } else {
            rt->right = inserthelp(rt->right, key, value);
        }

        rt->height = 1 + max(h(rt->left), h(rt->right));
        int balance = getBalance(rt);

        if (balance < -1 && key >= rt->right->key) {
            return leftRotate(rt);
        }
        if (balance > 1 && key < rt->left->key) {
            return rightRotate(rt);
        }
        if (balance > 1 && key >= rt->left->key) {
            rt->left = leftRotate(rt->left);
            return rightRotate(rt);
        }
        if (balance < -1 && key < rt->right->key) {
            rt->right = rightRotate(rt->right);
            return leftRotate(rt);
        }

        return rt;
    }

    AVLNode<keyType, valueType>* leftRotate(AVLNode<keyType, valueType>* rt) {
        AVLNode<keyType, valueType>* r = rt->right;
        AVLNode<keyType, valueType>* rl = r->left;
        r->left = rt;
        rt->right = rl;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;

        return r;
    }

    AVLNode<keyType, valueType>* rightRotate(AVLNode<keyType, valueType>* rt) {
        AVLNode<keyType, valueType>* l = rt->left;
        AVLNode<keyType, valueType>* lr = l->right;
        l->right = rt;
        rt->left = lr;

        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;

        return l;
    }
};

int solve() {
    AVL<int, int> a;

    int n;
    cin >> n;

    int x;
    vector<int> k;
    for (int i = 0; i < n; i++) {
        cin >> x;

        a.insert(x, x);
        k = a.preorder();
    }

    for (int e : a.preorder()) {
        cout << e << '\n';
    }
    cout << "END\n";

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
