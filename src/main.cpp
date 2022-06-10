#include "TrieArray.h"
#include "TrieMap.h"

int main(int argc, char const *argv[]) {
    TrieArray *trieArray = new TrieArray();
    TrieMap *trieMap = new TrieMap();
    // Keys to be inserted in Trie
    char keys[][12] = {"the", "a", "there", "answer",
                       "any", "by", "bye", "their", "these", "zoological"};

    // Inserting keys in Trie Map
    for (auto &key: keys) {
        trieMap->insert(key);
    }
    trieMap->remove("the");
    trieMap->remove("zoological");
    // Displaying content of Trie
    cout << "Content of TrieMap: " << endl;
    vector<string> list = trieMap->getAll();
    for (auto &word: list) {
        cout << word << endl;
    }

//    // Inserting keys in Trie
//    for (auto &key: keys)
//        trieArray->insert(key);
//
//    // Search for different keys
//    trieArray->search("by") ? cout << "Yes\n" : cout << "No\n";
//    trieArray->remove("bye");
//    trieArray->search("by") ? cout << "Yes\n" : cout << "No\n";
//    trieArray->search("bye") ? cout << "Yes\n" : cout << "No\n";
//
//    // Displaying content of Trie
//    cout << "Content of Trie: " << endl;
//    vector<string> list = trieArray->getAll();
//    for (auto &word: list) {
//        cout << word << endl;
//    }

    delete trieMap;
    delete trieArray;
    return 0;
}
