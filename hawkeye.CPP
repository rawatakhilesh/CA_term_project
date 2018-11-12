#include <iostream>
#include <vector>
using namespace std;

int CACHE_CAPACITY = 2;
vector < int > occupancy_vector;
vector < char > access_sequence;
int ov_size = 0;
int usage_interval = 0;

void add_new_element() {
  occupancy_vector.push_back(0);
  ov_size++;
}

int lookup_last_access(char x) {
  /* can the search be improved? */
  for(int index = 0; index < ov_size; index++) {
    if(access_sequence[index] == x) {
      return index;
    }
  }
  return -1;
}

bool ccapacity_check(int last_access) {
  for(int i = last_access; i < ov_size; i++) {
    if(occupancy_vector[i] == CACHE_CAPACITY) {
      return true;
    }
  }
  return false;
}

void update_occupancy_vector(int last_access) {
  for(int i = last_access; i < ov_size; i++) {
    occupancy_vector[i]++;
  }
}

void show_occupancy_vector() {
  for(int i = 0; i < ov_size; i++) {
    cout<<occupancy_vector[i]<<" ";
  }
  cout<<"\n";
}

void OPTgen(char X) {
  bool roof_hit = true;
  int last_access = lookup_last_access(X);
  /* usage_interval begins from index to ov_size - 1*/
  if(last_access>=0) {
    roof_hit = ccapacity_check(last_access);
  }

  if(!roof_hit) {
    update_occupancy_vector(last_access);
  }
  add_new_element();
  show_occupancy_vector();
}

void show_access_sequence() {
  for(int i = 0; i < ov_size; i++) {
    cout<<access_sequence[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  char access;
  int turn = 12;
  while(turn > 0){
    cout<<"access sequence:";
    cin>>access;
    OPTgen(access);
    access_sequence.push_back(access);
    show_access_sequence();
    turn--;
  }
  return EXIT_SUCCESS;
}
