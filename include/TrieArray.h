#include "Trie.h"

class TrieArray : public Trie
{
private:
public:
    TrieArray();
    ~TrieArray();

    void insert(const string &);
    bool search(const string &);
    bool remove(const string &);
    vector<string> getAll();
    vector<string> getKTopMatches(const string &);
};