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
int HashTable::hash_function(const string &s) 
{
    unsigned int hash_value=0;
for(int i = 0; i < s.size(); i++)
{
    int ascii = static_cast<int>(s[i]);
    int product = ascii * 331; //83 other lucky number, large input is 1.055 small is .63 ish with 83
    int shifted = product >> 8; //dont change this variance cracked w 8
    int mixymix = product ^ shifted;
    hash_value = hash_value ^ mixymix;
    
}
return hash_value % numSlots;
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
//prints first five
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
//calculate variance
double HashTable::standardVariance()
{
    double sum = 0.0;
    int* lengths = new int[numSlots];
    for(int i = 0; i<numSlots; i++)
    {
        int length = 0;
        Node* current = table[i];
        while(current)
        {
            length++;
            current = current->next;
        }
        lengths[i] = length;
        sum+= length;
    }
    double mean = sum / numSlots;
    double variance_sum = 0.0;
    for(int i = 0; i < numSlots; i++)
    {
        double dif = lengths[i]-mean;
        variance_sum += dif*dif;
    }
    delete[]lengths;
    double variance = variance_sum / numSlots;
    return sqrt(variance);
}
//slot lengths
void HashTable::printSlotLengths()
{
    for(int i = 0; i<numSlots; i++)
    {
        int length = 0;
        Node* current = table[i];
        while (current)
        {
            length++;
            current = current->next;
        }
        cout << "slot "<<i<< " length:" << length << endl;
    }
}



/* to do
test with different prime numbers and bit shift amounts*/