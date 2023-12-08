#include <iostream>
#include <string>
using namespace std;

struct College {
  string name;
  int resident_tuition; // in-state tuition   
  int nonresident_tuition; // out-of-state tuition 
  int living_expenses; // for room, board, trasnportation... 
  int resident_cost;   // total cost of attendance for in-state
  int nonresident_cost;  // total cost of attendance for out-of-state
};

void display(const College a[], unsigned n);

int search(const College a[], unsigned n, string name, string category);

void sort_by_name(College a[], unsigned n);
void sort_by_cost(College a[], unsigned n);
void sort_by_living(College a[], unsigned n);