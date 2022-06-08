#include "TrieArray.h"

// Returns true if node has no children, else false
bool isEmpty(TrieNode *node) {
    for (auto &child: node->children) { if (child) return false; }
    return true;
}

struct TrieNode *createNode() {
    struct TrieNode *newNode = new TrieNode;
    for (auto &child: newNode->children) {
        child = nullptr;
    }
    newNode->isEndOfWord = false;
    return newNode;
}

// Recursive function to delete a key from given Trie
struct TrieNode *removeNode(TrieNode *node, string key, int depth) {
    // If tree is empty
    if (!node)
        return nullptr;

    // If last character of key is being processed
    if (depth == key.size()) {

        // This node is no more end of word after
        // removal of given key
        if (node->isEndOfWord)
            node->isEndOfWord = false;

        // If given is not prefix of any other word
        if (isEmpty(node)) {
            delete (node);
            node = nullptr;
        }

        return node;
    }

    // If not last character, recur for the child
    // obtained using ASCII value
    int index = key[depth] - 'a';
    node->children[index] =
            removeNode(node->children[index], key, depth + 1);

    // If node does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(node) && !node->isEndOfWord) {
        delete (node);
        node = nullptr;
    }

    return node;
}

TrieArray::TrieArray() {
    root = createNode();
}

TrieArray::~TrieArray() {
    delete[] root;
}

void TrieArray::insert(const string &word) {
    struct TrieNode *tmp = root;
    for (char c: word) {
        int index = c - 'a';
        if (tmp->children[index] == nullptr) {
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
bool TrieArray::search(const string &word) {
    struct TrieNode *tmp = root;
    for (char c: word) {
        int index = c - 'a';
        if (!tmp->children[index]) {
            return false;
        }
        tmp = tmp->children[index];
    }

    return tmp->isEndOfWord;
}

bool TrieArray::remove(const string &word) {
    removeNode(root, word, 0);
    return true;
}

vector<string> TrieArray::getAll() {
    return {};
}

vector<string> TrieArray::getKTopMatches(const string &, int) {
    return {};
}


