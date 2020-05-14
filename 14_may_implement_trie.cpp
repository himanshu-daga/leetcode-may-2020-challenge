class Trie {
public:
    /** Initialize your data structure here. */
    Trie *alpha[26];
    bool isEnd;
    
    Trie() {
        this->isEnd = false;
        for(int i=0;i<26;i++)
            this->alpha[i] = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.length()<1) 
            return;
        Trie* node = this;
        for(auto i = 0;i<word.length();i++){
            int idx = word[i] - 'a';
            if(node->alpha[idx]==nullptr)
                node->alpha[idx] = new Trie();
            node = node->alpha[idx];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * node = this;
        for(int i=0;i<word.length();i++){
            int idx = word[i]-'a';
            node = node->alpha[idx];
            if(node==nullptr)
                return false;
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * node = this;
        for(int i=0;i<prefix.length();i++){
            int idx = prefix[i]-'a';
            node = node->alpha[idx];
            if(node==nullptr)
                return false;
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
