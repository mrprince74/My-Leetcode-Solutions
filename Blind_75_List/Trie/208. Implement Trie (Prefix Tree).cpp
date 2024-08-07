//Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
    private:
    #define SIZE 26
    vector<Trie*> children;
    bool is_leaf;
    public:
    Trie() {
        children.resize(SIZE,nullptr);
        is_leaf = false;
    }
    
    void insert(string word) {
        Trie* cur = this;
        for(const char &c : word){
            int i = c - 'a';
            if (cur->children[i] == nullptr) cur->children[i] = new Trie();
            cur = cur->children[i];
        }
        cur->is_leaf = 1;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(const char &c : word){
            int i = c - 'a';
            if (cur->children[i] == nullptr) return false;
            cur = cur->children[i];
        }
        return cur->is_leaf;
        
    }
    
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(const char &c: prefix){
            int i = c - 'a';
            if (cur->children[i] == nullptr) return false;
            cur = cur->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */