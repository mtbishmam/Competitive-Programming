class Trie {
public:
    int n;
    struct node {
        int end;      // how many words end here
        int prefix;   // how many words pass through this node
        vector<node*> child;
        node(int _n) {
            end = 0;
            prefix = 0;
            child = vector<node*>(_n, nullptr);
        }
    };

    node* root;

    Trie() { n = 26; root = new node(n); }
    Trie(int _n) { n = _n; root = new node(n); }

    void insert(const string& s) {
        node* cur = root;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!cur->child[idx])
                cur->child[idx] = new node(n);
            cur = cur->child[idx];
            cur->prefix++;
        }
        cur->end++;
    }

    int count(const string& s) {
        node* cur = root;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!cur->child[idx]) return 0;
            cur = cur->child[idx];
        }
        return cur->end;
    }

    // Count words with given prefix
    int count_prefix(const string& s) {
        node* cur = root;
        for (auto& c : s) {
            int idx = c - 'a';
            if (!cur->child[idx]) return 0;
            cur = cur->child[idx];
        }
        return cur->prefix;
    }

    // Check existence
    bool search(const string& s) {
        return count(s) > 0;
    }

    // Check prefix existence
    bool search_prefix(const string& s) {
        return count_prefix(s) > 0;
    }

    // Erase one occurrence of a word
    bool erase(const string& s) {
        if (!search(s)) return false; // word not present
        node* cur = root;
        for (auto& c : s) {
            int idx = c - 'a';
            cur = cur->child[idx];
            cur->prefix--;
        }
        cur->end--;
        return true;
    }

    // Longest prefix of given word present in trie
    string longest_prefix(const string& s) {
        node* cur = root;
        string res = "";
        for (auto& c : s) {
            int idx = c - 'a';
            if (!cur->child[idx]) break;
            cur = cur->child[idx];
            res.push_back(c);
        }
        return res;
    }

    // DFS to collect all words
    void all_words(node* cur, string& path, vector<string>& res) {
        if (cur->end > 0) res.push_back(path);
        for (int i = 0; i < n; i++) {
            if (cur->child[i]) {
                path.push_back('a' + i);
                all_words(cur->child[i], path, res);
                path.pop_back();
            }
        }
    }

    vector<string> get_all_words() {
        vector<string> res;
        string path;
        all_words(root, path, res);
        return res;
    }

    // Destructor to free memory
    void clear(node* cur) {
        for (int i = 0; i < n; i++) {
            if (cur->child[i]) clear(cur->child[i]);
        }
        delete cur;
    }

    ~Trie() { clear(root); }
};