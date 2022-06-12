#include "Trie.h"
#include <map>


struct TrieNodeMap {
    map<char, TrieNodeMap *> children;
    bool isEndOfWord;
    int frecuencia;
};

class TrieMap : public Trie {
private:
    struct TrieNodeMap *root;
public:
    TrieMap();

    ~TrieMap();

    void insert(const string &, int);

    bool search(const string &);

    bool remove(const string &);

    vector<string> getAll();

    vector<string> getKTopMatches(const string &, int);

    void destroyRecursive(TrieNodeMap *node);
};