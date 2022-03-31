#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct data{
  char name[21];
  int location;
  string color;
  data* left;
  data* right;
  data* parent;
};

struct dataRecord{
  char name[21];
  char age[3];
  char occupation[30];
};

class network{
  public:
    network();
    data* search(data* root, char person[21]);
    data* insertBST(data* node, char person[21]);
    void insertRBTree(char person[21]);
    void insertGraph(int index, string friends);
    void insertGraph(string user);
    void insertNewUser(char person[21], char age[3], char occupation[30]);
    void insertFriendship(char person1[21], char person2[21]);
    void printALL();
    void ListFriends(char person[21]);
    void print(data* node);
    void printInOrder(data* node, char person1[21], char person2[21]);
    void ListRange(char person1[21], char person2[21]);
    void printRBTree(data* node);
    int getCount();
    data* getRoot();

  private:
    data* root;
    int count;
    vector<vector<string> > table;

};




#endif