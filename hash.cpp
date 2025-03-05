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
int HashTable::hash_function(const string &text) {
    // Implement your own hash function here
    return 1;
}

/*contructor, each table has to have nodes that are the start of their chains; initializes these to null*/
HashTable::HashTable(int slots)
{
numSlots = slots;
table = new Node*[numSlots]; //array of pointers to each node in table
for (int i = 0; i < numSlots; i++)
{
    table[i] = nullptr;
}


}
/*destructor since using new and pointers*/
//1->2->null becomes null->2->null after one iteration, then null->null->null
HashTable::~HashTable()
{
for(int i = 0; i < numSlots; i++)
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

void HashTable::printfirstfive()
{
for(int i = 0; i < 5; i++)
{
 cout << "Slot " << i << ": ";
 Node* current = table[i];
 while (current)
 {
    cout << current->key << " ";
    current = current->next;
 }
 cout << endl;
}
}
void HashTable::insert(const string &key)
{
 int index = hash_function(key) % numSlots;
 Node* newNode = createNode(key);
 newNode->next = table[index];
 table[index] = newNode;

}



/* to do
print first five
print lengths
standard variance
hash function*/