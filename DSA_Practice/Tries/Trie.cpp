#include <iostream>
#include <map>

using namespace std;

class TrieNode {
    public:
        map<char, TrieNode*> children;
        bool isWord;
        TrieNode(){
            this->isWord = false;
        }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        this->root = new TrieNode();
    }

    void Insert(string word){
        TrieNode* node = new TrieNode();

        for(auto& c : word){
            if(node->children.find(c) == node->children.end()){
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    bool Search(string word){
        TrieNode* node = this->root;

        for(char& c : word){
            if(node->children.find(c) == node->children.end()){
                return false;
            }
            node = node->children[c];
        }
        return node->isWord;
    }

    bool SearchPrefix(string prefix){
        TrieNode* node = this->root;

        for(char& c : prefix){
            if(node->children.find(c) == node->children.end()){
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

int main() {
     std::vector< std::string> keys = {"the", "a", "there", "answer"};
     Trie d;
     int num = 1;

     for(int i = 0; i < keys.size(); i++){
          std::cout << i+1 << ".\tInserting key: '" << keys[i] << "'" << std::endl;
          d.Insert(keys[i]);
          num += 1;
          std::cout << std::string(100,'-') << std::endl;
          }

     std::vector< std::string> Search =  {"a", "answer", "xyz", "an"};

     for(int i = 0; i < Search.size(); i++){
          std::cout << num << ".\tSearching key: '" << Search[i] <<  "'" << std::endl;
          bool res = d.Search(Search[i]);
          std::cout << "\tKey found? " << std::boolalpha << res << std::endl;
          num += 1;
          std::cout << std::string(100,'-') << std::endl;
     }

     std::vector< std::string> SearchP =  {"b", "an"};

     for(int i = 0; i < SearchP.size(); i++){
          std::cout << num << ".\tSearching prefix: '" << SearchP[i] << "'" << std::endl;
          bool res = d.SearchPrefix(SearchP[i]);
          std::cout << "\tPrefix found? " << std::boolalpha << res << std::endl;
          num += 1;
          std::cout << std::string(100,'-') << std::endl;
     }
}