#include "network.h"
#include <fstream>
#include <iomanip>

network::network(){
  root = nullptr;
  
  count = 0;
}

data* network::search(data* root, char person[21]){
  if(strcmp(root->name, person) == 0){
    return root;
  }else if(strcmp(root->name, person) > 0){
    if(root->left){
      return search(root->left, person);
    }else{
      return nullptr;
    }
  }else{
    if(root->right){
      return search(root->right, person);
    }else{
      return nullptr;
    }
  }
}

data* network::insertBST(data* node, char person[21]){
  if(strcmp(person, node->name) < 0){
    if(node->left){
      return insertBST(node->left, person);
    }else{
      data* temp = new data;
      temp->color = "red";
      strcpy(temp->name, person);
      temp->location = this->count;
      temp->parent = node;
      temp->left = nullptr;
      temp->right = nullptr;
      node->left = temp;
      this->count++;
      return node->left;
    }
  }else{
    if(node->right){
      return insertBST(node->right, person);
    }else{
      data* temp = new data;
      temp->color = "red";
      strcpy(temp->name, person);
      temp->location = this->count;
      temp->parent = node;
      temp->left = nullptr;
      temp->right = nullptr;
      node->right = temp;
      this->count++;
      return node->right;
    }
  }
}

void network::insertRBTree(char person[21]){
  if(this->count == 0){
    data* temp = new data;
    temp->color = "black";
    strcpy(temp->name, person);
    temp->location = this->count;
    temp->parent = nullptr;
    temp->left = nullptr;
    temp->right = nullptr;
    this->root = temp;
    this->count++;
    return;
  }else{
    data* a = insertBST(this->root, person);
    while(a->parent->color == "red"){
      if(a->parent == a->parent->parent->right){
        if(a->parent->parent->left && a->parent->parent->left->color == "red"){//recolor
          data* u = a->parent->parent->left;
          u->color = "black";
          a->parent->color = "black";
          if(a->parent->parent != this->root){
            a->parent->parent->color = "red";
          }
          a = a->parent->parent;
          if(a->parent == nullptr){
            break;
          }
        }else{
          if(a == a->parent->left){//right-left rotation
            data* g = a->parent->parent;
            char t1[21];
            strcpy(t1, g->name);
            int t2 = g->location;
            strcpy(g->name, a->name);
            g->location = a->location;
            strcpy(a->name, t1);
            a->location = t2;
            g->right->left = a->right;
            if(a->right != nullptr){
              a->right->parent = g->right;
            }
            a->right = a->left;
            a->left = g->left;
            if(g->left != nullptr){
              g->left->parent = a;
            }
            g->left = a;
            a->parent = g;
            break;
          }else if(a == a->parent->right){//right-right rotation
            data* g = a->parent->parent;
            char t1[21];
            strcpy(t1, g->name);
            int t2 = g->location;
            strcpy(g->name, a->parent->name);
            g->location = a->parent->location;
            strcpy(a->parent->name, t1);
            a->parent->location = t2;
            g->right->right = g->right->left;
            g->right->left = g->left;
            if(g->left != nullptr){
              g->left->parent = g->right;
            }
            g->left = g->right;
            g->right = a;
            a->parent = g;
            break;
          }
        } 
      }else if(a->parent == a->parent->parent->left){
        if(a->parent->parent->right && a->parent->parent->right->color == "red"){//recolor
          data* u = a->parent->parent->right;
          u->color = "black";
          a->parent->color = "black";
          if(a->parent->parent != this->root){
            a->parent->parent->color = "red";
          }
          a = a->parent->parent;
          if(a->parent == nullptr){
            break;
          }
        }else{
          if(a == a->parent->right){//left-right rotation
            data* g = a->parent->parent;
            char t1[21];
            strcpy(t1, g->name);
            int t2 = g->location;
            strcpy(g->name, a->name);
            g->location = a->location;
            strcpy(a->name, t1);
            a->location = t2;
            g->left->right = a->left;
            if(a->left != nullptr){
              a->left->parent = g->left;
            }
            a->left = a->right;
            a->right = g->right;
            if(g->right != nullptr){
              g->right->parent = a;
            }
            g->right = a;
            a->parent = g;
            break;
          }else if(a == a->parent->left){//left-left rotation
            data* g = a->parent->parent;
            char t1[21];
            strcpy(t1, g->name);
            int t2 = g->location;
            strcpy(g->name, a->parent->name);
            g->location = a->parent->location;
            strcpy(a->parent->name, t1);
            a->parent->location = t2;
            g->left->left = g->left->right;
            g->left->right = g->right;
            if(g->right != nullptr){
              g->right->parent = g->left;
            }
            g->right = g->left;
            g->left = a;
            a->parent = g;
            break;
          }
        } 
      }
    }
  }

}

void network::insertGraph(string friends){
  vector<string> temp;
  temp.push_back(friends);
  table.push_back(temp);
}

void network::insertGraph(int index, string friends){
  this->table[index].push_back(friends);
}


void network::insertNewUser(char person[21], char age[3], char occupation[30]){
  insertRBTree(person);
  ofstream myfile;
  myfile.open("network.txt", ios::app);
  myfile<<setfill(' ')<<std::left<<setw(20)<<person<<setw(3)<<age<<setw(30)<<occupation;
  myfile.close();
  
}


void network::insertFriendship(char person1[21], char person2[21]){
  data* node1 = search(this->root, person1);
  data* node2 = search(this->root, person2);
  if(node1 == nullptr || node2 == nullptr){
    cout<<"Invalid user name.\n";
    return;
  }
  this->table[node1->location].push_back(person2);
  this->table[node2->location].push_back(person1);
}


void network::printALL(){
  ifstream myfile;
  myfile.open("network.txt");
  for(int i = 0; i < this->count; i++){
    char* buffer = new char[54];
    for(int j =0; j < 54; j++){
      buffer[j] = '\0';
    }
    
    myfile.seekg(i*53);
    myfile.read(buffer, 53);
    
    cout<<buffer;
    cout<<",";
    
    delete[] buffer;

    int size = table[i].size();
    for(int j = 1; j < size; j++){
      cout<<table[i].at(j)<<",";
    }
    cout<<endl;
  }
  myfile.close();
}


void network::ListFriends(char person[21]){
  data* node = search(this->root, person);
  if(node == nullptr){
    cout<<"Invalid user name.\n";
    return;
  }
  int size = table[node->location].size();
  for(int i = 1; i < size; i++){
    char person[21];
    string temp = table[node->location].at(i);
    strcpy(person, temp.c_str());
    data* node2 = search(this->root, person);
    int index = node2->location;
    char* buffer = new char[54];
    ifstream myfile;
    myfile.open("network.txt");
    myfile.seekg(53*index);
    myfile.read(buffer, 53);
    cout<<buffer<<endl;
    myfile.close();
    delete[] buffer;
    
    
    
  }
}

void network::print(data* node){
  int i = node->location;
  char* buffer = new char[54];
  ifstream myfile;
  myfile.open("network.txt");
  myfile.seekg(i*53);
  myfile.read(buffer, 53);
  cout<<buffer;
  myfile.close();
  delete[] buffer;
  vector<string>::iterator ptr;
  for(ptr = table[i].begin() + 1; ptr < table[i].end(); ptr++){
    cout<<","<<*ptr;
  }
  cout<<endl;
}

void network::printInOrder(data* node, char person1[21], char person2[21]){
  if(node){
    printInOrder(node->left, person1, person2);
    if((strcmp(node->name, person1) >= 0) && (strcmp(node->name, person2) <= 0)){
      print(node);
    }
    printInOrder(node->right, person1, person2);
  }
}

void network::ListRange(char person1[21], char person2[21]){
  printInOrder(this->root, person1, person2);
}

int network::getCount(){
  return this->count;
}

data* network::getRoot(){
  return this->root;
}

void network::printRBTree(data* node){
  if(node){
    printRBTree(node->left);
    cout<<node->name<<",";
    printRBTree(node->right);
  }
}