#include "Trie.h"

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

class TrieArray : public Trie {
private:
    struct TrieNode *root;
public:
    TrieArray();

    ~TrieArray();

    void insert(const string &);

    bool search(const string &);

    bool remove(const string &);

    vector<string> getAll();

    vector<string> getKTopMatches(const string &, int);
};