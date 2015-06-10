#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    
}

int main(int argc, char const *argv[])
{
	int length = 0;
	int if_two = 0;
	int last;
	int i;
	while(scanf("%d", &i) == 1){
		// printf("%d", i);
		switch(if_two) {
		case 0:
			last = i;
			++length;
			++if_two;
			break;
		case 1:
			if (last == i) {
				++length;
				++if_two;
			} else {
				++length;
				if_two = 0;
			}
			break;
		default:
			if (last == i) {
				++if_two;
			} else {
				++length;
				if_two = 0;
			}

			break;		
		}
	}
	printf("%d", length);
	return 0;
}