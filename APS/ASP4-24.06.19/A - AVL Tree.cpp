#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename keyType, typename valueType>
class AVLNode {
   public:
    AVLNode(const keyType setkey, const valueType& setValue) {
        this->key = setkey;
        this->value = setValue;
        count = 1;
        this->height = -1;
        this->left = nullptr;
        this->right = nullptr;
    }

    int count;
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

    int getIndex(keyType key) { return getIndexHelp(this->root, key); }

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

    vector<valueType> inorder() {
        vector<valueType> tmp;
        inorderhelp(this->root, &tmp);

        return tmp;
    }

    vector<valueType> posorder() {
        vector<valueType> tmp;
        posorderhelp(this->root, &tmp);

        return tmp;
    }

    AVLNode<keyType, valueType>* root;

   private:
    int __size;

    int getIndexHelp(AVLNode<keyType, valueType>* rt, keyType key) {
        if (rt == nullptr) {
            return INT_MIN;
        }
        if (key == rt->key) {
            return 1 + getCount(rt->left);
        } else if (key < rt->key) {
            return getIndexHelp(rt->left, key);
        } else {  // if (key > rt->key)
            return 1 + getCount(rt->left) + getIndexHelp(rt->right, key);
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

    int getCount(AVLNode<keyType, valueType>* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->count;
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

        rt->count = 1 + getCount(rt->left) + getCount(rt->right);
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

        rt->count = 1 + getCount(rt->left) + getCount(rt->right);
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;
        r->count = 1 + getCount(r->left) + getCount(r->right);

        return r;
    }

    AVLNode<keyType, valueType>* rightRotate(AVLNode<keyType, valueType>* rt) {
        AVLNode<keyType, valueType>* l = rt->left;
        AVLNode<keyType, valueType>* lr = l->right;
        l->right = rt;
        rt->left = lr;

        rt->count = 1 + getCount(rt->left) + getCount(rt->right);
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;
        l->count = 1 + getCount(l->left) + getCount(l->right);

        return l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    AVL<int, int> t;

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        if (a == 1) {
            t.insert(b, b);
        } else if (a == 2) {
            int i = t.getIndex(b);
            if (i > 0)
                cout << i << '\n';
            else
                cout << "Data tidak ada" << '\n';
        }
    }

    return 0;
}