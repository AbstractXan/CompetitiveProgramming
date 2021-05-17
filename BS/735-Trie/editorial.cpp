#include<string>
#include<map>
#include<iostream>
using namespace std;

class Trie {  // Time: O(L) for every operation, where L is the length of the input string
    private:
    bool is_word;
    Trie* children[26];

    public:
    Trie() {  // Constructor
        is_word = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }

    ~Trie() {  // Destructor
        for (int i = 0; i < 26; i++)
            if (children[i]) delete children[i];  // Release children nodes
    }

    Trie* search(string& word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr) return nullptr;

            node = node->children[c - 'a'];
        }

        return node;
    }

    void add(string s) {
        Trie* node = this;
        for (char c : s) {
            if (node->children[c - 'a'] == nullptr) node->children[c - 'a'] = new Trie();

            node = node->children[c - 'a'];
        }

        node->is_word = true;
    }

    bool exists(string word) {
        Trie* node = search(word);
        return (node != nullptr) && (node->is_word);
    }

    bool startswith(string p) {
        Trie* node = search(p);
        return node != nullptr;
    }
};