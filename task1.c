#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Wombat {
  char *name;
  double weight;
  struct Wombat *next;
};
void WombatOutput(struct Wombat *p) {
  while (p != 0) {
    printf("Name: %s; Weight: %f\n", p -> name, p -> weight);
    p = p -> next;
    }
}
int main(void) {
  struct Wombat Oleg;
  struct Wombat Sergey;
  struct Wombat mob[10];
  Oleg.name = "Oleg";
  Oleg.weight = 20.4;
  struct Wombat *third = malloc(sizeof(struct Wombat));
  third -> name = "Alice";
  third -> weight = 21.7;
  third -> next = NULL;
  third -> name = "Kevin";
  struct Wombat *second = malloc(sizeof(struct Wombat));
second -> name = "David";
second -> weight = 22.0;
  second -> next = third;
  struct Wombat *first = malloc(sizeof(struct Wombat));
  first -> name = "Bob";
  first -> weight = 24.6;
  first -> next = second;
  WombatOutput(first);
}