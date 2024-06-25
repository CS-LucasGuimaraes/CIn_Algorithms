#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename keyType, typename valueType>
class ClosedHashTable {
public:
    ClosedHashTable(size_t n) {
        this->__size = 0;
        this->hash_size = n;

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

    pair<keyType, valueType>* insert(keyType const& key, valueType const& value) {
        pair<keyType, valueType>* f = this->find(key);
        if (f != nullptr) {
            return f;
        }

        size_t i = this->hash(key);
        size_t prob = 0;
        while (this->table[(i + this->probing(prob))%this->hash_size] != nullptr && this->table[(i + this->probing(prob))%this->hash_size] != this->__none) {
            prob++;
        }
        this->table[(i + this->probing(prob))%this->hash_size] = new pair<keyType, valueType>(key, value);
        this->key_list.emplace(key);
        this->__size++;
        return this->table[(i + this->probing(prob))%this->hash_size];
    }

    size_t size() {
        return __size;
    }

    typename vector<pair<keyType, valueType>*>::iterator begin() {
        return this->table.begin();
    }

    typename vector<pair<keyType, valueType>*>::iterator end() {
        return this->table.end();
    }

    pair<keyType, valueType>* find(keyType key) {
        size_t i = this->hash(key);

        for (size_t p = 0; p < this->hash_size; p++) {
            pair<keyType, valueType>* answ = this->table[(i + this->probing(p))%this->hash_size];
            if (answ != nullptr && answ->first == key) {
                return answ;
            }
        }

        return nullptr;
    }

    void erase(keyType key) {
        pair<keyType, valueType>* e = this->find(key);
        if (e != nullptr) {
            e = this->__none;
        }
    }

    set<keyType> getKeys() {
        return key_list;
    }

private:
    size_t hash_size;
    size_t __size;
    vector<pair<keyType, valueType>*> table;
    set<keyType> key_list;
    pair<keyType, valueType>* __none = new pair<keyType, valueType>;

    size_t hash(keyType k) {
        int sum = 0;
        for (int i = 0; i < int(k.size()); i++) {
            sum += k[i];
        }

        return abs(sum) % this->hash_size;
    }

    size_t probing(size_t it) {
        return it;
    }
};

int main() {

    ClosedHashTable<string, int> m(10);

    m["10"] = 1;
    cout << m["10"] << endl;

    m["10"] = 14;

    cout << m["10"] << endl;

    return 0;
}