#include <iostream>

void plotArray(int* nums, int numsSize, int pa = 0, int pb = 0);

typedef struct _linked_list linked_list;
typedef int fuck;

struct _linked_list {
  int value;
  linked_list* next;
};

//struct fucked_list {
//  int val;
//  struct fucked_list next;
//};

struct _linked_list a;
int b;

struct Person {
  int weight;
  int height;
};

void fuckYulu() {
  struct Person chenyulu;
  chenyulu.weight = 94;
  chenyulu.height = 163;
}

void fuckLinkedList() {
  linked_list fuckee;
  fuckee.value = 10;
  fuckee.next = NULL;

  linked_list* pFuckee;
  pFuckee->value = 50;
  pFuckee->next = NULL;

//  pFuckee->next->next->next->next->next->next->next;

  linked_list a, b;
  a.value = 5;
  b.value = 7;
  a.next = &b;

  a.next->value; // 7

  linked_list* p = (linked_list*)malloc(sizeof(linked_list));

  p->value = 55;
  p->next = NULL;

  free(p);
}


void moveZeroes(int* nums, int numsSize) {
//  for (int i = 0; i < numsSize; ++i) {
//    if (nums[i] == 0) {
//      // Append to the end
//    } else {
//      // Apend normally
//    }
//  }
//  int nonZeroCount = 0;
//  for (int i = 0; i < numsSize; ++i) {
//    if (nums[i] != 0) {
//      nonZeroCount++;
//    }
//  }
  int pointer = 0;
  for (int j = 0; j < numsSize; ++j) {
    plotArray(nums, numsSize, j, pointer);
    if (nums[j] != 0) {
      if (pointer != j) {
        nums[pointer] = nums[j];
        nums[j] = 0;
        plotArray(nums, numsSize, j, pointer);
      }
      pointer++;
    }
  }

//  for (int i = pointer; i < numsSize; ++i) {
//    nums[i] = 0;
//  }
  plotArray(nums, numsSize, numsSize - 1, numsSize - 1);
}

void plotArray(int* nums, int numsSize, int pa, int pb) {
  for (int i = 0; i < numsSize; ++i) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
  for (int i = 0; i < pa; ++i) {
    std::cout << "  ";
  }
  std::cout << "*" << std::endl;
  for (int i = 0; i < pb; ++i) {
    std::cout << "  ";
  }
  std::cout << "&" << std::endl;
  std::cout << std::endl;
}

int main(int argc, char *argv[]) {
  int a[14] = {1,0,5,3,0,0,0,3,0,0,4,5,0,1};
  moveZeroes(a, 14);

  return 0;
}