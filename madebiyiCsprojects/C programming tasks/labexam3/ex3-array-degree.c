/*
Author: Michael Adebiyi
Date: Wednesday 30th November 2022
*/

/*Description: This code reads in an array (list) of numbers.
Using the sortnums function the array is sorted into ascending order.
There is a initialised counter for each integer, if the count for an integer surpasses 3 it is printed as output the amount of times it tis counted*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Num Num;

struct Num {
  int number;
  Num *next;
  Num *prev;
};

Num *linked_list(int argc, char *argv[]);
int highest_freq(Num *first);

int main(int argc, char *argv[]) {
  Num *start = NULL;
  int highest = 0;
  start = linked_list(argc, argv);
  highest = highest_freq(start);
  printf("%d\n", highest);
  return 0;
}
Num *linked_list(int argc, char *argv[]) {
  Num *current, *first, *prev;
  first = (Num *)calloc(1, sizeof(Num));
  first->number = atoi(argv[1]);
  current = first;
  int count = 0;
  for (int i = 2; count < argc - 2; i++) {
    current->next = (Num *)calloc(1, sizeof(Num));
    current = current->next;
    current->number = atoi(argv[i]);
    count++;
  }
  current->next = NULL;
  return first;
}

int highest_freq(Num *first) {
  Num *p = NULL;
  Num *j = NULL;
  int count;
  int highest_freq = 0;
  for (p = first; p != NULL; p = p->next) {
    count = 0;
    for (j = p; j != NULL; j = j->next) {
      if (j->number == p->number) {
        count++;
      }
    }
    if (count > highest_freq) {
      highest_freq = count;
    }
  }
  return highest_freq;
}