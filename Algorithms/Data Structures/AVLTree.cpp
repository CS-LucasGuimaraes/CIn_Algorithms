template <typename keyType, typename valueType>
class AVLNode {
   public:
    AVLNode(const keyType setkey, const valueType& setValue) {
        this->key = setkey;
        this->value = setValue;
        this->height = 1;
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

    void preorderhelp(AVLNode<keyType, valueType>* rt, vector<valueType>* v) {
        if (rt != nullptr) {
            v->push_back(rt->value);

            preorderhelp(rt->left, v);
            preorderhelp(rt->right, v);
        }
    }

    void inorderhelp(AVLNode<keyType, valueType>* rt, vector<valueType>* v) {
        if (rt != nullptr) {
            inorderhelp(rt->left, v);

            v->push_back(rt->value);

            inorderhelp(rt->right, v);
        }
    }

    void posorderhelp(AVLNode<keyType, valueType>* rt, vector<valueType>* v) {
        if (rt != nullptr) {
            posorderhelp(rt->left, v);
            posorderhelp(rt->right, v);

            v->push_back(rt->value);
        }
    }

    valueType findhelp(AVLNode<keyType, valueType>* rt, keyType key) {
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

    int h(AVLNode<keyType, valueType>* node) {
        if (node == nullptr) {
            return -1;
        }
        return node->height;
    }

    int getBalace(AVLNode<keyType, valueType>* node) {
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

        rt.height = 1 + max(h(rt.left), h(rt.right));
        int balance = getBalace(rt);

        if (balance < -1 && key >= rt.right.key) {
            return leftRotate(rt);
        }
        if (balance > 1 && key < rt.left.key) {
            return rightRotate(rt);
        }
        if (balance > 1 && key >= rt.left.key) {
            rt.left = leftRotate(rt.left);
            return rightRotate(rt);
        }
        if (balace < -1 && key < rt.right.key) {
            rt.right = rightRotate(rt.right);
            return leftRotate(rt);
        }

        return rt;
    }

    AVLNode<keyType, valueType>* leftRotate(BSTNode<keyType, valueType>* rt) {
        BSTNode<keyType, valueType>* r = rt.right;
        BSTNode<keyType, valueType>* rl = r.left;
        r.left = rt;
        rt.right = rl;
        rt.height = max(h(rt.left), h(rt.height))) + 1;
        r.height = max(h(r.left), h(r.right)) + 1;

        return r;
    }

    AVLNode<keyType, valueType>* rightRotate() {
        BSTNode<keyType, valueType>* l = rt.left;
        BSTNode<keyType, valueType>* lr = l.right;
        l.right = rt;
        rt.left = lr;
        rt.height = max(h(rt.left), h(rt.height))) + 1;
        l.height = max(h(l.left), h(l.right)) + 1;

        return l;
    }
};