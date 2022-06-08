#include "TrieArray.h"
#include "TrieMap.h"

int main(int argc, char const *argv[])
{
    TrieArray *trieArray = new TrieArray();
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

    // Construct trie
    for (int i = 0; i < n; i++)
        trieArray->insert(keys[i]);

    // Search for different keys
    trieArray->search("the") ? cout << "Yes\n" : cout << "No\n";
    trieArray->search("these") ? cout << "Yes\n" : cout << "No\n";
    trieArray->search("their") ? cout << "Yes\n" : cout << "No\n";
    trieArray->search("thaw") ? cout << "Yes\n" : cout << "No\n";
    trieArray->search("bye") ? cout << "Yes\n" : cout << "No\n";

    delete trieArray;
    return 0;
}
