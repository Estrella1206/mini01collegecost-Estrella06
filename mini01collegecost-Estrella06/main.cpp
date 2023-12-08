// This program shall analyze the cost of attendance of different colleges and universities across California. 
#include <iostream>
#include <string>
#include <iomanip>
#include "library.h"
#include <fstream>
using namespace std;

int main() {

  College c[20];
  unsigned num_colleges = 0;
  ifstream list;

  list.open("california.csv");

  while(!list.eof()) {
    int max = 0; 
    int min = 0;
    for(int i = 0; i < 6; i++){
    getline(list, c[i].name , ',');
      
    list >> c[i].resident_tuition;
      list.ignore();
    list >> c[i].nonresident_tuition;
      list.ignore();
    list >>c[i].living_expenses;

      c[i].resident_cost = c[i].resident_tuition + c[i].living_expenses;
      c[i].nonresident_cost = c[i].nonresident_tuition + c[i].living_expenses;
       num_colleges = num_colleges + 1;

    }
  }
  list.close();

  display(c, num_colleges);

  cout << "\nIn-state tuition for Cerritos College is $";
  cout << search(c,num_colleges,"Cerritos College","In-state tuition") << endl; 

  //outputs the wrong return value
  cout << "\nOut-of-state tuition for University of California Davis is $";
  cout << search(c,num_colleges,"University of California Davis","In-state tuition") << endl;

  //outputs the wrong return value
  cout << "\nIn-state tuition for California State University Chico is $";
  cout << search(c,num_colleges,"California State University Chico","Food") << endl;

  //outputs the wrong return value
  cout << "\nIn-state tuition for California State University Long Beach is $";
  cout << search(c,num_colleges,"California State University Long Beach","In-state-tuition") << endl;
  
  cout << "\nThe total cost for Cerritos College is $";
  cout << search(c,num_colleges,"Cerritos College","resident_cost") << endl;

  cout << "\nThe Health cost for Cerritos College is $";
  cout << search(c,num_colleges,"Cerritos College","Health") << endl;

 

  sort_by_name(c, num_colleges);

  display(c, num_colleges);

  sort_by_cost(c, num_colleges);

  display(c, num_colleges);

  sort_by_living(c, num_colleges);
  
  display(c, num_colleges);
  }