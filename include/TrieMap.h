#include "Trie.h"
#include <map>


struct TrieNodeMap {
    map<char, TrieNodeMap *> children;
    bool isEndOfWord;
};

class TrieMap {
private:
    struct TrieNodeMap *root;
public:
    TrieMap();

    ~TrieMap();

    void insert(const string &);

    bool search(const string &);

    bool remove(const string &);

    vector<string> getAll();

    vector<string> getKTopMatches(const string &, int);
};