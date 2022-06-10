#if !defined(TRIE_H)
#define TRIE_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Trie
{
public:
    virtual void insert(const string &) = 0;                        // Insertar una cadena al trie
    virtual bool search(const string &) = 0;                        // Retorna true si y solo si el string consultado está contenido en el trie
    virtual bool remove(const string &) = 0;                        // Elimina del trie la cadena que recibe, en caso de existir. Retorna true si y solo si esta operación es válida (la cadena estaba contenido en el trie)
    virtual vector<string> getAll() = 0;                            // Retorna un vector que contiene todas las cadenas pertenecientes al trie
    virtual vector<string> getKTopMatches(const string &, int) = 0; // Retorna un vector que contiene las k cadenas más frecuentes contenidas en el trie que comienzan con la subcadena str recibida.
};

#endif // TRIE_H
