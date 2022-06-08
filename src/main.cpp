#include "TrieArray.h"
#include "TrieMap.h"

int main(int argc, char const *argv[]) {
    TrieArray *trieArray = new TrieArray();
    // Keys to be inserted in Trie
    char keys[][8] = {"the", "a", "there", "answer",
                      "any", "by", "bye", "their", "these"};

    // Inserting keys in Trie
    for (auto &key: keys)
        trieArray->insert(key);

    // Search for different keys
    trieArray->search("by") ? cout << "Yes\n" : cout << "No\n";
    trieArray->remove("bye");
    trieArray->search("by") ? cout << "Yes\n" : cout << "No\n";
    trieArray->search("bye") ? cout << "Yes\n" : cout << "No\n";

    // Displaying content of Trie
    cout << "Content of Trie: " << endl;
    vector<string> list = trieArray->getAll();
    for (auto &word: list) {
        cout << word << endl;
    }

    delete trieArray;
    return 0;
}
