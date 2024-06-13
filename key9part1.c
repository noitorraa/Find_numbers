#include <stdio.h>
#define NMAX 10
void input(int *buffer, int *length, int *check);
void output(int *buffer, int length, int *sum);
int sum_numbers(int *buffer, int length, int *sum);
int find_numbers(int *buffer, int length, int *sum, int *numNewArray,
                 int *newArray);

int main() {
  int data[NMAX], newArray[NMAX];
  int num, check = 0, sum = 0, numNewArray = 0;
  input(data, &num, &check);
  if (check == 0) {
    sum_numbers(data, num, &sum);
    find_numbers(data, num, &sum, &numNewArray, newArray);
    output(newArray, num, &sum);
  }
  return 0;
}

void input(int *buffer, int *length, int *check) {
  printf("Напиши сколько элементов будешь вводить: ");
  if (scanf("%d", length) == 1 && getchar() == '\n' && *length >= 1 &&
      *length <= 10) {
    for (int i = 0; i < *length; i++) {
      printf("Введи число %d: ", i + 1);
      if (scanf("%d", &buffer[i]) != 1 || getchar() != '\n' || buffer[i] == 0) {
        printf("n/a\n");
        *check = 1;
        break;
      }
    }
  } else {
    printf("n/a\n");
    *check = 1;
  }
}

int sum_numbers(int *buffer, int length, int *sum) {
  *sum = 0;
  for (int i = 0; i < length; i++) {
    if (buffer[i] % 2 == 0) {
      *sum += buffer[i];
    }
  }
  return 0;
}

int find_numbers(int *buffer, int length, int *sum, int *numNewArray,
                 int *newArray) {
  *numNewArray = 0;
  for (int i = 0; i < length; i++) {
    if (*sum % buffer[i] == 0) {
      newArray[*numNewArray] = buffer[i];
      *numNewArray += 1;
    }
  }
  return 0;
}

void output(int *buffer, int length, int *sum) {
  printf("%d\n", *sum);
  for (int i = 0; i < length; i++) {
    if (buffer[i] == 0) {
      break;
    }
    printf("%d ", buffer[i]);
  }
  printf("\n");
}
