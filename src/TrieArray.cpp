#include "TrieArray.h"

struct TrieNode *createNode(void)
{
    struct TrieNode *newNode = new TrieNode;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        newNode->children[i] = nullptr;
    }
    newNode->isEndOfWord = false;
    return newNode;
}

TrieArray::TrieArray()
{
    root = createNode();
}

TrieArray::~TrieArray()
{
    delete[] root;
}

void TrieArray::insert(const string &word)
{
    struct TrieNode *tmp = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (tmp->children[index] == nullptr)
        {
            // create a new node if the path doesn't exist
            tmp->children[index] = createNode();
        }
        // go to the next node
        tmp = tmp->children[index];
    }
    // mark last node as leaf
    tmp->isEndOfWord = true;
}

// Returns true if word presents in trie, else false
bool TrieArray::search(const string &word)
{
    struct TrieNode *tmp = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (!tmp->children[index])
        {
            return false;
        }
        tmp = tmp->children[index];
    }

    return tmp->isEndOfWord;
}

bool TrieArray::remove(const string &word)
{
    return false;
}

vector<string> TrieArray::getAll()
{
    return {};
}

vector<string> TrieArray::getKTopMatches(const string &, int)
{
    return {};
}
