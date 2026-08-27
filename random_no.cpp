#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int generate_random_no();
int main() {

    srand(time(NULL));

//    for (int i = 0; i < 10; i++) {
//        int num = (rand() % 100) + 1;
//        printf("%d ", num);
//    }
	printf("%d ", generate_random_no());
    return 0;
}
int generate_random_no(){
	int num = (rand() % 100) + 1;
	return num;
}
