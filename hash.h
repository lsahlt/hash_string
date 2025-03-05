#include <iostream>
#include <string>
#include <cmath>
#ifndef HASH_H
#define HASH_H
// You are free to use additional libraries as long as it's not PROHIBITED per instruction.

using namespace std;

struct Node 
{
  string key;
  Node* next;
};

class HashTable
{
  private:
  int numSlots; //the k from encoder
  Node** table;
  Node* createNode(const string &key);
  int hash_function(const string &s);
  public:
  HashTable(int slots); //numslots = slots
  ~HashTable();
  void insert(const string &key);
  void printfirstfive();
  double standardVariance();


};

#endif

