#include "TrieArray.h"
#include "TrieMap.h"

int main(int argc, char const *argv[])
{
    TrieArray *trieArray = new TrieArray();
    TrieMap *trieMap = new TrieMap();

    int n = 350000; // Cantidad de elementos en el Trie
    // Lee dic
    ifstream ifile;
    ifile.open("dic/dic1.txt"); // Abrir dic
    string s;
    clock_t start;
    clock_t end;
    vector<string> listTrieArray;
    vector<string> listTrieMap;

    // Tiempo total métodos de TrieArray
    double timeInsert_TrieArray = 0; // Tiempo total de insertar n elementos
    double timeSearch_TrieArray = 0; // Tiempo total de buscar n elementos
    double timeRemove_TrieArray = 0; // Tiempo total de remover n elementos
    double timeGetAll_TrieArray = 0; // Tiempo total de obtener n elementos

    // Tiempo total métodos de TrieMap
    double timeInsert_TrieMap = 0; // Tiempo total de insertar n elementos
    double timeSearch_TrieMap = 0; // Tiempo total de buscar n elementos
    double timeRemove_TrieMap = 0; // Tiempo total de remover n elementos
    double timeGetAll_TrieMap = 0; // Tiempo total de obtener n elementos

    if (ifile.is_open())
    {
        /*******************************   Trie Array   *******************************/
        // Inserta n palabras al TrieArray. Usando el método insert()
        start = clock();
        for (int i = 0; i < n; i++)
        {
            ifile >> s;
            trieArray->insert(s, 0);
        }
        end = clock();
        timeInsert_TrieArray += (double)(end - start) / CLOCKS_PER_SEC;

        // Ejemplo
        cout << "Buscar palabras en orden alfabético para autocompletado para : 'guess'" << endl;
        vector<string> list = trieArray->getKTopMatches("guess", 2);
        for (auto &i : list)
        {
            cout << i << endl;
        }
        cout << "" << endl;
        // Salida : guessable, guessed

        // Obtiene todas las palabras del TrieArray y los almacena en un vector. Usando el método getAll()
        start = clock();
        listTrieArray = trieArray->getAll();
        end = clock();
        timeGetAll_TrieArray += (double)(end - start) / CLOCKS_PER_SEC;

        // Busca n palabras en TrieArray. Usando el método search()
        start = clock();
        for (auto &word : listTrieArray)
        {
            trieArray->search(word);
        }
        end = clock();
        timeSearch_TrieArray += (double)(end - start) / CLOCKS_PER_SEC;

        // Remueve n palabras en TrieArray. Usando el método remove()
        start = clock();
        for (auto &word : listTrieArray)
        {
            trieArray->remove(word);
        }
        end = clock();
        timeRemove_TrieArray += (double)(end - start) / CLOCKS_PER_SEC;

        /*******************************   Trie Map   *******************************/
        // Inserta n palabras al TrieMap. Usando el método insert()
        start = clock();
        for (int i = 0; i < n; i++)
        {
            ifile >> s;
            trieMap->insert(s, 0);
        }
        end = clock();
        timeInsert_TrieMap += (double)(end - start) / CLOCKS_PER_SEC;

        // Obtiene todas las palabras del TrieMap y los almacena en un vector. Usando el método getAll()
        start = clock();
        listTrieMap = trieMap->getAll();
        end = clock();
        timeGetAll_TrieMap += (double)(end - start) / CLOCKS_PER_SEC;

        // Busca n palabras en TrieMap. Usando el método search()
        start = clock();
        for (auto &word : listTrieMap)
        {
            trieMap->search(word);
        }
        end = clock();
        timeSearch_TrieMap += (double)(end - start) / CLOCKS_PER_SEC;

        // Remueve n palabras en TrieMap. Usando el método remove()
        start = clock();
        for (auto &word : listTrieMap)
        {
            trieMap->remove(word);
        }
        end = clock();
        timeRemove_TrieMap += (double)(end - start) / CLOCKS_PER_SEC;

        ifile.close();
    }
    else
    {
        cout << "No se pudo abrir el diccionario" << endl;
    }

    printf("***** Tiempo total con %d palabras *****\n\n", n);
    // Trie Array
    printf("TrieArray: Insertar %d palabras = %.10f segundos.\n", n, timeInsert_TrieArray);
    printf("TrieArray: Buscar %d palabras   = %.10f segundos.\n", n, timeSearch_TrieArray);
    printf("TrieArray: Quitar %d palabras   = %.10f segundos.\n", n, timeRemove_TrieArray);
    printf("TrieArray: Obtener %d palabras  = %.10f segundos.\n\n", n, timeGetAll_TrieArray);
    // Trie Map
    printf("TrieMap: Insertar %d palabras = %.10f segundos.\n", n, timeInsert_TrieMap);
    printf("TrieMap: Buscar %d palabras   = %.10f segundos.\n", n, timeSearch_TrieMap);
    printf("TrieMap: Quitar %d palabras   = %.10f segundos.\n", n, timeRemove_TrieMap);
    printf("TrieMap: Obtener %d palabras  = %.10f segundos.\n", n, timeGetAll_TrieMap);

    delete trieMap;
    delete trieArray;
    return 0;
}
