#include "TrieMap.h"

// Returns true if node has no children, else false
//bool isEmpty(TrieNodeMap *node) {
//    for (auto &child: node->children) {
//        if (child) return false;
//    }
//    return true;
//}

// function to check if current node is end of word or not
bool isEndOfWord(struct TrieNodeMap *node) {
    return node->isEndOfWord;
}

struct TrieNodeMap *createNodeMap() {
    struct TrieNodeMap *newNode = new TrieNodeMap;
    newNode->isEndOfWord = false;
    return newNode;
}

// Recursive function to delete a key from given Trie
//struct TrieNode *removeNodeMap(TrieNode *node, string key, int depth) {
//    // If tree is empty
//    if (!node)
//        return nullptr;
//    // If last character of key is being processed
//    if (depth == key.size()) {
//        // This node is no more end of word after
//        // removal of given key
//        if (node->isEndOfWord)
//            node->isEndOfWord = false;
//        // If given is not prefix of any other word
//        if (isEmpty(node)) {
//            delete (node);
//            node = nullptr;
//        }
//        return node;
//    }
//    // If not last character, recur for the child obtained using ASCII value
//    int index = key[depth] - 'a';
//    node->children[index] = removeNodeMap(node->children[index], key, depth + 1);
//    // If node does not have any child (its only child got deleted), and it is not end of another word.
//    if (isEmpty(node) && !node->isEndOfWord) {
//        delete (node);
//        node = nullptr;
//    }
//    return node;
//}

// function that stores words from the trie in a vector
void storeKeys(struct TrieNodeMap *root, char str[], int level, vector<string> *list) {
    // If node is end of word, it indicates end of string, so a null character is added
    if (isEndOfWord(root)) {
        str[level] = '\0';
        string s;
        s += str;
        list->push_back(s);
    }
    for (auto &it: root->children) {
        if (it.second != nullptr) {
            str[level] = it.first;
            storeKeys(it.second, str, level + 1, list);
        }
    }
}

TrieMap::TrieMap() {
    root = createNodeMap();
}

TrieMap::~TrieMap() {
}

void TrieMap::insert(const string &word) {
    struct TrieNodeMap *tmp = root;
    for (char c: word) {
        //if char not in map
        if (tmp->children.find(c) == tmp->children.end()) {
            // create a new node if the path doesn't exist
            tmp->children[c] = createNodeMap();
        }
        // go to the next node
        tmp = tmp->children[c];
    }
    // mark last node as leaf
    tmp->isEndOfWord = true;
}

// Returns true if word presents in trie, else false
bool TrieMap::search(const string &word) {
    struct TrieNodeMap *tmp = root;
    for (char c: word) {
        if (tmp->children.find(c) == tmp->children.end()) {
            return false;
        }
        tmp = tmp->children[c];
    }

    return tmp->isEndOfWord;
}

//bool TrieMap::remove(const string &word) {
//    if (!search(word)) return false;
//    removeNodeMap(root, word, 0);
//    return true;
//}

vector<string> TrieMap::getAll() {
    vector<string> list;
    int level = 0;
    char str[25];
    storeKeys(root, str, level, &list);
    return list;
}

vector<string> TrieMap::getKTopMatches(const string &, int) {
    return {};
}