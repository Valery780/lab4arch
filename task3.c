#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct full_name {
  char *surname;
  char *name;
  char *patronymic;
};
struct birth_date{
  int day;
  int month;
  int year;
};
struct course_info{
  char *group_letters;
  int group_number;
  int number_of_debts;
};
struct student{
  struct full_name name;
  struct birth_date date;
  struct course_info info;
  char *sex;
  float average_mark;
  struct student *next;
};
void StudentOutput(struct student *p) {
  while (p != NULL) {
    printf(" Full name: %s %s %s\n Date of Birth: %d %d %d\n Group: %s-%d\n Debts: %d\n Sex: %s\n Average mark: %f\n", p->name.surname, p->name.name, p->name.patronymic, p->date.day, p->date.month, p->date.year,p->info.group_letters, p->info.group_number, p->info.number_of_debts, p->sex, p->average_mark );
    p = p -> next;
    }
}
int main(void) {
  struct student *st1 = malloc(sizeof(struct student));
  st1 -> name.surname = "Иванов";
  st1 -> name.name = "Иван";
  st1 -> name.patronymic = "Иванович";
  st1 -> date.day = 5;
  st1 -> date.month = 3;
  st1 -> date.year = 2002;
  st1 -> info.group_letters = "НУП";
  st1 -> info.group_number = 202;
  st1 -> info.number_of_debts = 3;
  st1 -> sex = "М";
  st1 -> average_mark = 65.5;
  StudentOutput(st1);
}