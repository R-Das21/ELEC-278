#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


struct Date {
  int day, month, year;
};

bool compare(struct Date *date1,struct Date *date2) {
    
  if (date1->year < date2->year)
    return false;
  if (date1->year == date2->year && date1->month < date2->month)
    return false;
  if (date1->year == date2->year && date1->month == date2->month && date1->day < date2->day)
    return false;

  return true;
}


void arrort(struct Date arr[], int quantity) {
  qsort(arr, quantity, sizeof(arr[0]), compare);
}

int main() {
  struct Date arr[] = {{20, 1, 2014}, {25, 3, 2010}, {3, 12, 1676}, {18, 11, 1982}, {19, 4,
2015},{ 9, 7, 2015}, {12, 8, 2010}, {30, 8, 2010}, {21, 1, 2014}, {20, 7, 2014},
{18, 11, 2020}};
  int quantity = sizeof(arr) / sizeof(arr[0]);
  arrort(arr, quantity);
printf("Date arr[] = {");
  for (int i = 0; i < quantity-1; i++) {
    printf("{%d, %d, %d},", arr[i].day, arr[i].month, arr[i].year);
  }
  printf("{%d, %d, %d}", arr[10].day, arr[10].month, arr[10].year);
    printf("}");
  return 0;
}
