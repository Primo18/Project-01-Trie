#include "Trie.h"

class TrieMap
{
private:
public:
    TrieMap();
    ~TrieMap();

    void insert(const string &);
    bool search(const string &);
    bool remove(const string &);
    vector<string> getAll();
    vector<string> getKTopMatches(const string &);
};