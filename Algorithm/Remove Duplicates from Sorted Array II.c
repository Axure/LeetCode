#include <stdio.h>

int removeDuplicates(int *nums, int numsSize) {
  int length = 0;
  int if_two = 0;
  int last;
  int i, j;
  for (j = 0; j < numsSize; ++j) {
    i = nums[j];
    // printf("Fucking %d\n", i);
    switch (if_two) {
      case 0:
        last = i;
        nums[length] = i;
        ++length;
        ++if_two;
        // printf("%d ", i);
        break;
      case 1:
        if (last == i) {
          nums[length] = i;
          ++length;
          ++if_two;
          // printf("%d ", i);
        } else {
          nums[length] = i;
          last = i;
          ++length;
          if_two = 1;
          // printf("%d ", i);
        }
        break;
      default:
        if (last == i) {
          ++if_two;
        } else {
          nums[length] = i;
          last = i;
          ++length;
          if_two = 1;
          // printf("%d ", i);
        }

        break;
    }
  }
  // if (length != 0) {
  // 	printf("%d", length);
  // }
  return length;

}

int main(int argc, char const *argv[]) {
  int a[12] = {1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 6};
  removeDuplicates(a, 12);
  return 0;
}