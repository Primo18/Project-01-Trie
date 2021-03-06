#include "TrieArray.h"

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Returns true if node has no children, else false
bool isEmpty(TrieNode *node)
{
    for (auto &child : node->children)
    {
        if (child)
            return false;
    }
    return true;
}

// function to check if current node is end of word or not
bool isEndOfWord(struct TrieNode *node)
{
    return node->isEndOfWord;
}

// Crea un nuevo nodo y setea a null sus hijos
struct TrieNode *createNode()
{
    struct TrieNode *newNode = new TrieNode;
    for (auto &child : newNode->children)
    {
        child = nullptr;
    }
    newNode->isEndOfWord = false;
    return newNode;
}

// Recursive function to delete a key from given Trie
struct TrieNode *removeNode(TrieNode *node, string key, int depth)
{
    // If tree is empty
    if (!node)
        return nullptr;
    // If last character of key is being processed
    if (depth == key.size())
    {
        // This node is no more end of word after
        // removal of given key
        if (node->isEndOfWord)
            node->isEndOfWord = false;
        // If given is not prefix of any other word
        if (isEmpty(node))
        {
            delete (node);
            node = nullptr;
        }
        return node;
    }
    // If not last character, recur for the child obtained using ASCII value
    int index = key[depth] - 'a';
    node->children[index] = removeNode(node->children[index], key, depth + 1);
    // If node does not have any child (its only child got deleted), and it is not end of another word.
    if (isEmpty(node) && !node->isEndOfWord)
    {
        delete (node);
        node = nullptr;
    }
    return node;
}

// function that stores words from the trie in a vector
void storeKeys(struct TrieNode *root, char str[], int level, vector<string> *list)
{
    // If node is end of word, it indicates end of string, so a null character is added
    if (isEndOfWord(root))
    {
        str[level] = '\0';
        string s;
        s += str;
        list->push_back(s);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        // if NON-NULL child is found add parent key to str and call the storeKeys function recursively for child node
        if (root->children[i])
        {
            str[level] = i + 'a';
            storeKeys(root->children[i], str, level + 1, list);
        }
    }
}

// Recursive function  for given node
void suggestionsRec(struct TrieNode *root,
                    const string currPrefix, vector<string> &list, int frecuencia)
{
    // found a string in Trie with the given prefix
    if (isEmpty(root) && list.size() < frecuencia)
    {
        list.push_back(currPrefix);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
        {
            // child node character value
            char child = 'a' + i;
            suggestionsRec(root->children[i],
                           currPrefix + child, list, frecuencia);
        }
}

TrieArray::TrieArray()
{
    root = createNode();
}

TrieArray::~TrieArray()
{
    // destroyRecursive(root);
}

void TrieArray::destroyRecursive(TrieNode *node)
{
    if (node != nullptr)
    {
        if (isEmpty(node))
        {
            // delete the leaf node
            delete (node);
            return;
        }

        for (auto &child : root->children)
        {
            destroyRecursive(child);
        }
    }
    else
    {
        return;
    }
}

void TrieArray::insert(const string &word, int frecuencia)
{
    struct TrieNode *tmp = root;
    for (char c : word)
    {
        int index = c - 'a';
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
    tmp->frecuencia = frecuencia;
}

// Returns true if word presents in trie, else false
bool TrieArray::search(const string &word)
{
    struct TrieNode *tmp = root;
    for (char c : word)
    {
        int index = c - 'a';
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
    if (!search(word))
        return false;
    removeNode(root, word, 0);
    return true;
}

vector<string> TrieArray::getAll()
{
    vector<string> list;
    int level = 0;
    char str[25];
    storeKeys(root, str, level, &list);
    return list;
}

vector<string> TrieArray::getKTopMatches(const string &s, int frecuencia)
{
    vector<string> list;
    struct TrieNode *tmp = root;
    for (char c : s)
    {
        int ind = CHAR_TO_INDEX(c);

        // no string in the Trie has this prefix
        if (!tmp->children[ind])
            return list;

        tmp = tmp->children[ind];
    }
    // If prefix is present as a word, but there is no subtree below the last matching tmp.
    if (isEmpty(tmp) && list.size() < frecuencia)
    {
        list.push_back(s);
        return list;
    }
    suggestionsRec(tmp, s, list, frecuencia);

    return list;
}
