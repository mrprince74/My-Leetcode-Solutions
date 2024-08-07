//Problem Link: https://leetcode.com/problems/search-suggestions-system/

// Sol 1: Without trie (Better Time Complexity)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& words, string searchWord) {
        sort(words.begin(), words.end());
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(const string &word: words){   
        string s = "";
        for(char c: word){
            s += c;
            if (mp[s].size() >= 3)
                continue;
            mp[s].push_back(word);
        }
        }
        string s = "";
        for(char c: searchWord){
            s += c;
            ans.push_back(mp[s]);
        }
        return ans;
    }
};

// Sol 2: With Trie (Worse Time Complexity)
class Trie{
    map<char, Trie*> children;
    bool isLeaf;
    int count;

    public:
    Trie(){
        this->isLeaf = false;
        count = 0;
    }
    Trie(const vector<string>& words) :Trie(){
        for(auto word: words){
            insert(word);
        }

    }

    void insert(const string &s){
        int n = s.size();
        Trie* cur = this;
        for(int i = 0;i<n; i++){
            int c = s[i];
            if (cur->children.count(c) == 0)
                cur->children[c] = new Trie();
            cur = cur->children[c];
            cur->count++;
        }
        cur->isLeaf = 1;
    }

    bool exist(const string& s){
        Trie* cur = this;
        int n = s.size();

        for(int i = 0; i<n; i++){
            int c = s[i];
            if (cur->children.count(c) == 0 || cur->children[c]->count == 0) {
                return false;
            }
            cur = cur->children[c];
        }
        
        return cur->isLeaf;
    }

    void remove(const string& s){
        if (!exist(s)){
            return;
        }

        int n = s.size();

        Trie* cur = this;
        for(int i = 0; i<n; i++){
                int c = s[i];
                cur = cur->children[c];
                cur->count--;
        }
        cur->isLeaf = false;
    }

    bool isPrefix(const string& s){
    Trie* cur = this;
    int n = s.size();
    for(int i = 0; i<n; i++){
        int c = s[i];
        if (cur->children.count(c) == 0 || cur->children[c]->count == 0) {
            return false;
        }
        cur = cur->children[c];
    }
    return cur->count > 1;
    }

    void do_work(Trie* cur, string so_far, vector<string>& ret){
        if (ret.size() >= 3)
            return;
        
        if (cur->isLeaf){
            ret.push_back(so_far);
        }

        for(auto [chr, node]: cur->children){
            if (node->count > 0){
                do_work(node, so_far + (char) chr, ret);
            }
        }
    }

    vector<string> find_all_prefixes(string word){
        vector<string> ret;
        
        Trie* cur = this;
        for(int i = 0; i<word.size();i++){
            if (cur->children.count(word[i]) == 0)
                return ret;
            cur = cur->children[word[i]];
        }
        do_work(cur, word, ret);
        return ret;
    }


};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& words, string searchWord) {
        Trie t;
        vector<vector<string>> ans;
        for(string word: words){
            t.insert(word);
        }
        string s = "";
        for(char c: searchWord){
            s += c;
            auto p = t.find_all_prefixes(s);
            sort(p.begin(), p.end());
            ans.push_back(p);
        }
        
        
        return ans;
    }
};