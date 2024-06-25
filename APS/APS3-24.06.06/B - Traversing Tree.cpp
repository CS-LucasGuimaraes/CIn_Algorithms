#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename keyType, typename valueType>
class BSTNode {
   public:
    BSTNode(const keyType setkey, const valueType& setValue) {
        this->key = setkey;
        this->value = setValue;
        this->left = nullptr;
        this->right = nullptr;
    }

    keyType key;
    valueType value;
    BSTNode* left;
    BSTNode* right;
};

template <typename keyType, typename valueType>
class BST {
   public:
    BST() {
        this->root = nullptr;
        this->__size = 0;
    }

    valueType find(keyType key) {
        return findhelp(this->root, key);
    }

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

    BSTNode<keyType, valueType>* root;

   private:
    int __size;

    void preorderhelp(BSTNode<keyType, valueType>* rt, vector<valueType>* v) {
        if (rt != nullptr) {
            v->push_back(rt->value);

            preorderhelp(rt->left, v);
            preorderhelp(rt->right, v);
        }
    }

    void inorderhelp(BSTNode<keyType, valueType>* rt, vector<valueType>* v) {
        if (rt != nullptr) {
            inorderhelp(rt->left, v);

            v->push_back(rt->value);

            inorderhelp(rt->right, v);
        }
    }

    void posorderhelp(BSTNode<keyType, valueType>* rt, vector<valueType>* v) {
        if (rt != nullptr) {
            posorderhelp(rt->left, v);
            posorderhelp(rt->right, v);

            v->push_back(rt->value);
        }
    }

    valueType findhelp(BSTNode<keyType, valueType>* rt, keyType key) {
        if (rt == nullptr) {
            return NULL;
        }

        if (rt->key > key) {
            return findhelp(rt->left, key);
        }

        else if (rt->key == key) {
            return rt->element;
        }

        else {
            return findhelp(rt->right, key);
        }
    }

    BSTNode<keyType, valueType>* inserthelp(BSTNode<keyType, valueType>* rt, keyType key, valueType value) {
        if (rt == nullptr) {
            return new BSTNode<keyType, valueType>(key, value);
        }

        if (rt->key > key) {
            rt->left = inserthelp(rt->left, key, value);
        } else {
            rt->right = inserthelp(rt->right, key, value);
        }

        return rt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    BST<int, int> BSTree;

    int x;

    for (int i = 0; i < n; i++) {
        cin >> x;

        BSTree.insert(x, x);
    }

    cout << "Pre order :";

    for (auto e : BSTree.preorder()) {
        cout << ' ' << e;
    }
    cout << '\n';

    cout << "In order  :";

    for (auto e : BSTree.inorder()) {
        cout << ' ' << e;
    }
    cout << '\n';

    cout << "Post order:";

    for (auto e : BSTree.posorder()) {
        cout << ' ' << e;
    }
    cout << '\n';

    return 0;
}