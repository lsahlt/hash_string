#include <iostream>
#include <string>
#include <cmath>
#include "hash.h"

using namespace std;
//given a string key create a node for it
Node* HashTable::createNode(const string &key)
{
Node* newNode = new Node;
newNode->key = key;
newNode->next = nullptr;
return newNode;
}


/*hash function that multiplies each characters ascii value by a prime and then mixes the bits up using a right shift and xor*/
int HashTable::hash_function(const string text) {
    // Implement your own hash function here
    return 1;
}

/*contructor, each table has to have nodes that are the start of their chains; initializes these to null*/
HashTable::HashTable(int slots)
{
numslots = slots;
table = new Node*[numslots]; //array of pointers to each node in table
for (int i = 0; i < numslots; i++)
{
    table[i] = nullptr;
}


}
/*destructor since using new and pointers*/
//1->2->null becomes null->2->null after one iteration, then null->null->null
Hashtable::~HasTable()
{
for(int i = 0; i < numslots; i++)
{
    Node* current = table[i];
    while(current)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
delete[] table;

}

/* to do
print first five
print lengths
standard variance
hash function*/