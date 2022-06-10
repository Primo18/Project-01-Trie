#include "TrieArray.h"
#include "TrieMap.h"

int main(int argc, char const *argv[])
{
    TrieArray *trieArray = new TrieArray();
    TrieMap *trieMap = new TrieMap();
    // Keys to be inserted in Trie
    char keys[][25] = {"the", "a", "there", "answer",
                       "any", "by", "bye", "their", "these"};

    // Inserting keys in Trie Map
    for (auto &key : keys)
    {
        trieMap->insert(key);
    }

    trieMap->remove("a");
    cout << trieMap->search("a") << endl;
    trieMap->insert("a");

    // Displaying content of Trie
    cout << "Content of TrieMap: " << endl;
    vector<string> list = trieMap->getAll();
    for (auto &word : list)
    {
        cout << word << endl;
    }

    // Leer archivo
    ifstream ifile;
    ifile.open("dic/words.txt"); // Abrir dic
    if (ifile.is_open())
    {
        string s;
        ifile >> s;
        cout << "de archivo:" << s << endl;
    }
    else
    {
        cout << "No se pudo abrir el diccionario" << endl;
    }

    delete trieMap;
    delete trieArray;
    return 0;
}
