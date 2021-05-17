#include<string>
#include<map>
#include<iostream>
using namespace std;
struct Node {
    map<char, Node*> hash;
    bool isEnd;
    Node(){
        this->isEnd=false;
    }
};

class Trie {

    private:
    Node* head;
    Node* traverseForString(string& word);

    public:
    Trie();
    void add(string s);
    bool exists(string word);
    bool startswith(string p);
};

Trie::Trie() {
    Node* head = new struct Node;
    head->isEnd = false;
    this->head = head;
}

// This function modifies incoming string
Node* Trie::traverseForString(string& word) {
    Node* tmp = this->head;
    int i = 0;
    // While we keep matching / word gets over
    while(tmp->hash.find(word[i])!=tmp->hash.end() && i < word.size()) {
        map<char,Node*>::iterator it=tmp->hash.find(word[i]);
        tmp=it->second;
        i++;    
    }

    // Update modifies string to work upon
    word = word.substr(i);

    if(word.size()==0){
        cout<< "Exact match" << endl;
    }else{
        cout<< "Superflow: " << word << endl;
    }
    return tmp;
}
void Trie::add(string s) {
    string str = s;
    Node* tmp = traverseForString(str);
    while(str.size()){
        Node* n = new struct Node;
        tmp->hash[str[0]]=n;
        tmp = n;
        str = str.substr(1);
    }
    tmp->isEnd=true;
}
bool Trie::exists(string word){
    string str = word;
    Node* tmp = traverseForString(str);
    if(str.size()==0 && tmp->isEnd){
        return true;
    }
    return false;
}

bool Trie::startswith(string p){
    Node*  tmp = traverseForString(p);
    if(p.size()!=0){
        return false;
    }
    return true;
}