#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename keyType, typename valueType> class OpenHashTable {
public:
    OpenHashTable<keyType, valueType>(size_t n) {
        this->__size = 0;
        this->hash_size = n;

        this->table = new list<pair<keyType, valueType>>*[n];
        for (size_t i = 0; i < this->hash_size; i++) {
            this->table[i] = new list<pair<keyType, valueType>>;
        }
        
    }

    ~OpenHashTable<keyType, valueType>() {
        delete this->table;
    }

    pair<keyType, valueType>* find(keyType key) {
        for (auto& k: *this->table[this->hash(key)]) {
            if (k.first == key) {
                return &k;
            }
        }

        return nullptr;
    }

    valueType& operator[](keyType const& key) {
        return this->insert({key, *new valueType()}).second;
    }

    size_t size() {
        return __size;
    }

    pair<keyType, valueType>& insert(pair<keyType, valueType> key_value) {
        size_t i = this->hash(key_value.first);
        
        for (auto& k: *this->table[i]) {
            if (k.first == key_value.first) {
                return k;
            }
        }

        __size++;

        key_list.emplace(key_value.first);
        this->table[i]->push_back(key_value);
        return this->table[i]->back();
    }

    void erase(keyType key) {
        for (auto i=this->table[this->hash(key)]->begin(); i!=this->table[this->hash(key)]->end(); i++) {
            if (i->first == key) {
                this->table[this->hash(key)]->erase(i);
                key_list.erase(key);
                return;
            }
        }
    }

    list<pair<keyType, valueType>> access_by_index(size_t k) {
        return *this->table[k];
    }

    set<keyType> getKeys() {
        return key_list;
    }
    
private:
    size_t hash_size;
    size_t __size;
    list<pair<keyType, valueType>>** table;
    set<keyType> key_list;

    size_t hash(keyType k) {
        return ((k % this->hash_size) + this->hash_size) % this->hash_size;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    OpenHashTable<int, int> m(10);

    int n; cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;

        m[x] = x;
    }

    for (int i = 0; i < 10; i++) {
        cout << i << ' ';

        for (auto [k, v]: m.access_by_index(i)) {
            cout << v << ' ';
        } cout << '\n';
    }    

    return 0;
}