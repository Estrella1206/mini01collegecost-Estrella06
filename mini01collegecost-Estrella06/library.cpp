#include "library.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// You shall implement the display, search, sort_by_name, sort_by_cost,
// sort_by_living functions here

void display(const College a[], unsigned n) {
  int count = 0;
  double avg = 0;
  double final_avg = 0;
  cout << "College " << setw(40) << " In-State " << setw(20) << "Out-Of-State"
       << setw(15) << "Other" << setw(10) << " | "
       << " In-State " << setw(15) << "Out-Of-State" << endl;

  cout << setw(46) << "Tuition" << setw(18) << "Tuition" << setw(21)
       << "Expenses" << setw(8) << " | " << setw(8) << "Total" << setw(14)
       << "Total" << endl;
  cout << "===================================================================="
          "=================================================="
       << endl;
  for (int i = 0; i < n; i++) {
    cout << fixed << left;
    cout << setw(37) << a[i].name << right << setw(4) << "$"
         << a[i].resident_tuition << setw(14) << "$" << a[i].nonresident_tuition
         << setw(15) << "$" << a[i].living_expenses << setw(9) << " | "
         << setw(4) << "$" << a[i].resident_cost << setw(9) << "$"
         << a[i].nonresident_cost;
    avg = avg + a[i].resident_cost;
    count = count + 1;
  }

  cout << "\n=================================================================="
          "===================================================="
       << endl;

  int max_tot = 0;
  int min_tot ;
  string max;
  string min;

  for (int i = 0; i < n; i++) {
    int total = a[i].resident_cost;
    if (total > max_tot) {
      max_tot = total;
      max = a[i].name;
    }
  }
  for (int i = 0; i < n; i++) {
    int total = a[i].resident_cost;
    if (total < min_tot) {
      min_tot = total;
      min = a[i].name;
    }
  }

  cout << left << fixed << setprecision(2);
  final_avg = avg / count;
  
  cout << "The most expensive university is:" << max;
  cout << "\nThe least expensive university is: " << min << endl;
  cout << "The average in-state cost in california is: " << final_avg << endl;
}

int search(const College a[], unsigned n, string name, string category) {
  for (int i = 0; i < n; i++) {
    if (a[i].name == name) {
      if (category == "In-state tuition") {
        return a[i].resident_tuition;
      } else if (category == "Out-of-state tuition") {
        return a[i].nonresident_tuition;
      }  else if(category == "living expenses"){
        return a[i].living_expenses;
      } else {
        return -1;
      }
   }
    
  }
}

void sort_by_name(College a[], unsigned n) { // using bubble sort to sort by name
  cout << "\nSorting College" << endl;
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < n - 1; i++) {
      if (a[i].name > a[i + 1].name) {
        swap(a[i], a[i + 1]);
      }
    }
  }
}

void sort_by_cost(College a[], unsigned n) { // using selection sort
  cout << "\nSorting by cost" << endl;
  int max_num;
  for (int i = 0; i < n; i++) {
    max_num = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j].resident_cost > a[max_num].resident_cost) {
        max_num = j;
      }
    }
    if (max_num != 0) {
      swap(a[max_num], a[i]);
    }
  }
}

void sort_by_living(College a[], unsigned n) { // using insertion sort
  cout << "\nSorting by living expenses" << endl;
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (a[j - 1].living_expenses > a[j].living_expenses) {
        swap(a[j - 1], a[j]);
      } else {
        break;
      }
    }
  }
}