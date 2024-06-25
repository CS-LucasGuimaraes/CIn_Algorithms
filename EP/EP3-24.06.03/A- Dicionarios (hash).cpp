#include <bits/stdc++.h>

// #define endl '\n'

using namespace std;

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename keyType, typename valueType>
class ClosedHashTable {
public:
    ClosedHashTable(size_t n, vector<int> perm) {
        this->__size = 0;
        this->hash_size = n;
        this->perm = perm;

        this->table = vector<pair<keyType, valueType>*>(n, nullptr);
    }

    ~ClosedHashTable() {
        for (size_t i = 0; i < hash_size; ++i) {
            if (table[i] != nullptr) {
                delete table[i];
                table[i] = nullptr;
            }
        }
    }

    valueType& operator[](keyType const& key) {
        return this->insert(key, valueType())->second;
    }

    const pair<keyType, valueType>* begin_ptr() {
        return this->table[0];
    }

    pair<keyType, valueType>* insert(keyType const& key, valueType const& value) {
        pair<keyType, valueType>* f = this->find(key);
        if (f != nullptr) {
            return f;
        }

        if (this->__size >= this->hash_size) return nullptr;

        size_t i = this->hash(key);
        size_t prob = 0;
        while (this->table[(i + this->probing(prob))%this->hash_size] != nullptr) {
            prob++;
        }
        this->table[(i + this->probing(prob))%this->hash_size] = new pair<keyType, valueType>(key, value);
        this->__size++;
        return this->table[(i + this->probing(prob))%this->hash_size];
    }

    size_t size() {
        return __size;
    }

    pair<keyType, valueType>* find(keyType key) {
        size_t i = this->hash(key);

        for (size_t p = 0; p < this->hash_size; p++) {
            size_t idx = (i + probing(p))%this->hash_size;
            if (this->table[idx] == nullptr || this->table[idx]->first == key) {
                return this->table[idx];
            }
        }

        return nullptr;
    }

    pair<keyType, valueType>* find_idx(keyType key) {
        size_t i = this->hash(key);

        for (size_t p = 0; p < this->hash_size; p++) {
            pair<keyType, valueType>* answ = this->table[(i + this->probing(p))%this->hash_size];
            if (answ == nullptr) return nullptr;
            if (answ->first == key) {
                return new pair<keyType, valueType>((i+this->probing(p))%this->hash_size, this->table[(i + this->probing(p))%this->hash_size]->second);
            }
        }

        return nullptr;
    }


private:
    size_t hash_size;
    size_t __size;
    vector<pair<keyType, valueType>*> table;
    vector<int> perm;

    size_t hash(keyType k) {
        return (k - (this->hash_size * (int) floor((((double) k) / ((double) this->hash_size))))); 
    }

    size_t probing(size_t i) {
        return perm[i];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    int m; cin >> m; 
    while(m != 0) {

        vector<int> perm(m); for (int i = 1; i < m; i++) {
            cin >> perm[i];
        } perm[0] = 0;

        ClosedHashTable<int, int> d(m, perm);
        
        string s;
        int a, b;
        int n; cin >> n; for (int i = 0; i < n; i++) {
            cin >> s;
            if (s == "find") {
                cin >> a;
                auto f = d.find_idx(a);
                auto l = d.find(a);
                if (f != nullptr) {
                    cout << f->first << ' ' << f->second << endl;
                    cout << "    " << l - d.begin_ptr() << ' ' << l->second << endl;
                } else cout << -1 << endl;
            } else

            if (s == "add") {
                cin >> a >> b;
                d.insert(a, b);
            }
        }

        cin >> m;
    }
    
    return 0;
}