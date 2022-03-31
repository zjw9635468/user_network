#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "network.h"

using namespace std;



int main(int argv, char** argc){
  if(argv != 2){
    cout << "Please provide one initializing file" << endl;
    return 1;
  }
  
  ifstream myfile;
  ofstream out;
  myfile.open(argc[1]);
  out.open("network.txt", ios::app);
  string str;
  getline(myfile, str);
  network N;
  int index = 0;
  while(getline(myfile, str)){
    istringstream iss(str);
    string temp;
    string friends;
    getline(iss, temp, ',');
    N.insertGraph(temp);
    char person[21];
    strncpy(person, temp.c_str(), 20);
    N.insertRBTree(person);
    getline(iss, temp, ',');
    char age[3];
    strcpy(age, temp.c_str());
    getline(iss, temp, ',');
    char occupation[30];
    strcpy(occupation, temp.c_str());
    out<<setfill(' ')<<std::left<<setw(20)<<person<<setw(3)<<age<<setw(30)<<occupation;
    getline(iss, friends, '"');
    while(getline(iss, friends, ',')){
      int i = friends.at(0);
      if(i == 34){
        break;
      }
      N.insertGraph(index, friends);
    }
    index++;
  }
  myfile.close();
  out.close();
  int exit_number = 0;
  while(exit_number == 0){
    cout<<"Please enter the operation:\n";
    cout<<"1. Insert a new user.\n";
    cout<<"2. Add friendship to two users.\n";
    cout<<"3. Print out all information.\n";
    cout<<"4. List name, age, occupation of all friends of a user.\n";
    cout<<"5. List all users' information between two names.\n";
    cout<<"6. List information an user.\n";
    cout<<"7. Exit.\n";
    int x;
    cin>>x;
    while(x != 1 && x != 2 && x != 3 && x != 4 && x != 5 && x != 6 && x!= 7){
      cout<<"Wrong operation!\n";
      cout<<"Which operation do you want to make? (1,2,3,4,5,6):\n";
      cin >> x;
    }
    if(x == 1){
      cout<<"Please enter the information of the new user.\n";
      string readin;
      cin.ignore();
      getline(cin,readin);
      istringstream info(readin);
      string temp;
      getline(info, temp, ',');
      int index = N.getCount();
      N.insertGraph(temp);
      char person[21];
      strcpy(person, temp.c_str());
      N.insertRBTree(person);
      getline(info, temp, ',');
      char age[3];
      strncpy(age, temp.c_str(),3);
      getline(info, temp, ',');
      char occupation[30];
      strncpy(occupation, temp.c_str(),30);
      out.open("network.txt", ios::app);
      out<<setfill(' ')<<std::left<<setw(20)<<person<<setw(3)<<age<<setw(30)<<occupation;
      out.close();
      char friends[21];
      while(getline(info, temp, ',')){
        strncpy(friends, temp.c_str(), 20);
        cout<<person<<","<<friends<<",\n";
        N.insertFriendship(person, friends);
      }
    }else if(x == 2){
      cout<<"Please enter two users.\n";
      string readin;
      cin.ignore();
      getline(cin, readin);
      istringstream info(readin);
      string temp;
      getline(info, temp, ',');
      char user1[21];
      strcpy(user1, temp.c_str());
      getline(info, temp);
      char user2[21];
      strcpy(user2, temp.c_str());
      N.insertFriendship(user1, user2);
    }else if(x == 3){
      N.printALL();
      N.printRBTree(N.getRoot());
      cout<<endl;
    }else if(x == 4){
      cout<<"Please enter a user.\n";
      string readin;
      cin.ignore();
      getline(cin, readin);
      char person[21];
      strcpy(person, readin.c_str());
      N.ListFriends(person);
    }else if(x == 5){
      cout<<"Please enter two users.\n";
      string readin;
      cin.ignore();
      getline(cin, readin);
      istringstream info(readin);
      string temp;
      getline(info, temp, ',');
      char user1[21];
      strcpy(user1, temp.c_str());
      getline(info, temp);
      char user2[21];
      strcpy(user2, temp.c_str());
      cout<<user1<<","<<user2<<",\n";
      if(strcmp(user1, user2) < 0){
        N.ListRange(user1, user2);
      }else{
        N.ListRange(user2, user1);
      }
    }else if(x == 6){
      cout<<"Please enter an user.\n";
      string readin;
      cin.ignore();
      getline(cin, readin);
      char person[21];
      strcpy(person, readin.c_str());
      data* temp = N.search(N.getRoot(), person);
      if(temp){
        N.print(temp);
      }else{
        cout<<"Invalid user name.\n";
      }
    }else if(x == 7){
      exit_number = 1;
    }

  }

  return 0;
}