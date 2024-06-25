#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

template <typename keyType, typename valueType>
class ClosedHashTable {
   public:
    ClosedHashTable(size_t n) {
        this->__size = 0;
        this->hash_size = n;

        this->__none = new pair<keyType, valueType>();

        this->table = vector<pair<keyType, valueType>*>(n, nullptr);
    }

    ~ClosedHashTable() {
        for (size_t i = 0; i < hash_size; ++i) {
            if (this->table[i] != nullptr) {
                if (this->table[i] != this->__none) {
                    delete table[i];
                }
                this->table[i] = nullptr;
            }
        }
        delete this->__none;
    }

    valueType& operator[](keyType const& key) {
        return this->insert(key, valueType())->second;
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

        for (size_t p = 0; p < 20; p++) {
            pair<keyType, valueType>* answ = this->table[(i + this->probing(p)) % this->hash_size];
            if (answ == nullptr || answ->first == key) {
                return answ;
            }
        }

        return nullptr;
    }

    pair<keyType, valueType>* insert(keyType const& key, valueType const& value) {
        pair<keyType, valueType>* f = this->find(key);
        if (f != nullptr && f->first == key) return f;

        size_t i = this->hash(key);

        size_t hash;

        for (int p = 0; p < 20; p++) {
            hash = (i + this->probing(p)) % this->hash_size;

            if (this->table[hash] == nullptr || this->table[hash] == this->__none) {
                this->__size++;
                return this->table[hash] = new pair<keyType, valueType>(key, value);
            }
        }

        return nullptr;
    }

    void erase(keyType key) {
        for (size_t i = 0; i < this->hash_size; i++) {
            if (this->table[i] != nullptr && this->table[i]->first == key) {
                delete this->table[i];
                this->table[i] = this->__none;
                this->__size--;
                return;
            }
        }
    }

    pair<keyType, valueType>* none() {
        return this->__none;
    }

   private:
    size_t hash_size;
    size_t __size;
    vector<pair<keyType, valueType>*> table;
    pair<keyType, valueType>* __none;

    size_t hash(keyType k) {
        int sum = 0;
        for (size_t i = 0; i < k.length(); i++) {
            sum += int(k[i]) * (i + 1);
        }

        // return (((sum % this->hash_size) * 19 % this->hash_size) + this->hash_size) % this->hash_size;
        return (sum * 19) % this->hash_size;
    }

    size_t probing(size_t i) {
        return ((i * i) + (23 * i));
    }
};

int solve() {
    ClosedHashTable<string, int> m(101);
    string cmd, key;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        key = cmd.substr(4);

        if (cmd.substr(0, 3) == "ADD") {
            if (key != "") m.insert(key, 0);
        } else

            if (cmd.substr(0, 3) == "DEL") {
            m.erase(key);
        }
    }

    cout << m.size() << '\n';

    int c = 0;
    for (auto e : m) {
        if (e != nullptr && e != m.none()) {
            cout << c << ':' << e->first << '\n';
        }

        c++;
    }

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