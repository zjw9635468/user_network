#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
   
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
   
    return true;
}

void foo(char a[]){
  cout<<a<<endl;
}

struct data{
  char name[20];
  int location;
  string color;
  data* left;
  data* right;
  data* parent;
};

int main(){
  /*
  char person[20] = "apple";
  char t[20] = "abc";
  char name[20];
  vector<string>* a[5];
  for(int i = 0; i < 5; i++){
    a[i] = new vector<string>;
  }
  a[0]->push_back("asd");
  a[0]->push_back("asq");
  a[0]->push_back("asr");
  a[1]->push_back("dqd");
  a[1]->push_back("sad");
  a[2]->push_back("sadqw");
  char q[20];
  string temp = a[0]->at(1);
  strcpy(q, temp.c_str());
  cout<<q<<endl;
  temp = a[0]->at(2);
  strcpy(q, temp.c_str());
  cout<<q<<endl;
  temp = a[1]->at(1);
  strcpy(q, temp.c_str());
  cout<<q<<endl;
  temp = a[2]->at(0);
  strcpy(q, temp.c_str());
  cout<<q<<endl;
  strcpy(name, person);
  strcpy(t, name);
  cout<<name<<endl;
  foo(t);
  
  ifstream myfile;
  myfile.open("users_10.csv");
  string temp;
  getline(myfile, temp);
  getline(myfile, temp);
  istringstream iss(temp);
  getline(iss, temp, ',');

  char person1[20];
  strcpy(person1, temp.c_str());
  myfile.close();
  char person2[20];
  string readin;
  cout<<"Enter a name.\n";
  getline(cin, readin);
  cout<<readin<<endl;
  
  strcpy(person2, readin.c_str());
  cout<<"person1"<<person1<<","<<"person2"<<person2<<","<<endl;
  cout<<strcmp(person2, person1)<<endl;
  
  for(int i = 0; i < 10; i++){
    char* buffer = new char[53];
    ifstream myfile;
    myfile.open("network.txt");
    myfile.seekg(i*53);
    myfile.read(buffer, 53);
    cout<<buffer;
    delete[] buffer;
    myfile.close();
    cout<<",";
    cout<<endl;
  }
  
  ifstream myfile("users_100.csv");
  string str;
  char a[20];
  getline(cin, str);
  strcpy(a, str.c_str());
  for(int i = 0; i < 38; i++){
    getline(myfile, str);
  }
  getline(myfile, str);
  istringstream iss(str);
  string temp;
  getline(iss, temp, ',');
  cout<<temp<<",";
  int n = temp.length();
  cout<<n<<",";
  char b[20];
  strcpy(b, temp.c_str());
  cout<<b<<",";
  cout<<strcmp(a,b)<<endl;
  char c[20];
  strcpy(c, b);
  cout<<c<<","<<strcmp(b,c)<<endl;
  data* u = new data;
  cout<<"1\n";
  strcpy(u->name, b);
  cout<<"2\n";
  cout<<u->name<<",\n";
  */
  vector<vector<string> > table;
  vector<string> f;
  f.push_back("asd");
  f.push_back("qwe");
  table.push_back(f);
  vector<string> d;
  d.push_back("apple");
  d.push_back("banana");
  table.push_back(d);
  table[1].push_back("candy");
  table[0].push_back("awqe");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j <3; j++){
      cout<<table[i][j]<<",";
    }
    cout<<endl;
  }
}