#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>


extern void imgCvtGrayIntToDouble(int numOfElements, uint8_t* intArr, double* doubleArr);

void generateRandomInput(int height, int width, uint8_t intArr[height][width]) {
    int i, j;
	char print='n';
    srand(time(NULL)); // Seed the random number generator
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            intArr[i][j] = rand() % 256; // Random number between 0 and 255
        }
    }

	printf("Print randomized results?: ('y' to confirm): ");
	scanf(" %c", &print);
	if (print == 'y'){
		for (i = 0; i < height; i++) {
			for (j = 0; j < width; j++) {
				printf("%d ", intArr[i][j]);
			}
        printf("\n");
    	}
	}
}

void assignValue(char row[], int width, uint8_t intArr[]) {
    char* nums;
    nums = strtok(row, " ");
    int i = 0;

    while (nums != NULL && i < width) {
        intArr[i] = (uint8_t)atoi(nums);
        nums = strtok(NULL, " ");
        i++;
    }
}

void getInput(int height, int width, uint8_t intArr[height][width]) {
    int i;
    printf("Input %d integers per Row: {example: 3 4 5 ... 7}\n\n", width);
    for (i = 0; i < height; i++) {
        char row[1024];
        printf("> ");
        fgets(row, sizeof(row), stdin);
        assignValue(row, width, intArr[i]);
    }
}

void printArray(int height, int width, double doubleArr[height][width]) {
    int i, j;
    printf("\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%.2f ", doubleArr[i][j]);
        }
        printf("\n");
    }
}

void check(int height, int width, uint8_t intArr[height][width]) {
    int i, j;

    printf("\nCheck answer (Result below executed in C): \n\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            double ans = intArr[i][j] / 255.0;
            printf("%.2f ", ans);
        }
        printf("\n");
    }
}

void getAveTime(int totalElements, uint8_t* intArr, double* doubleArr) {
    double total_time = 0.0;
    int i;

    for (i = 0; i < 30; i++) {
        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        imgCvtGrayIntToDouble(totalElements, intArr, doubleArr);
        clock_gettime(CLOCK_MONOTONIC, &end);

        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        double elapsed = seconds + nanoseconds * 1e-9;

        total_time += elapsed;
    }

    double average_time = total_time / 30.0;
    printf("Average Time taken for ASM function: %f x 10^6 ns\n", average_time*1000000);
}

int main() {
    int height = 2;
    int width = 2;
    char choice = 'n',print = 'y', inChoice = 'n';
    do {
        printf("Input Height and Width (H W): > ");
        scanf("%d %d", &height, &width);

        uint8_t intArr[height][width];
        double doubleArr[height][width];

        fflush(stdin);

        printf("Enter [y] if you want to enter an input. Randomize if otherwise: ");
        scanf(" %c", &inChoice);

        if (inChoice == 'y')
            getInput(height, width, intArr);
        else
            generateRandomInput(height, width, intArr);

        struct timespec start, end;
        clock_gettime(CLOCK_MONOTONIC, &start);
        imgCvtGrayIntToDouble(height * width, (uint8_t *)intArr, (double *)doubleArr);
        clock_gettime(CLOCK_MONOTONIC, &end);

        long seconds = end.tv_sec - start.tv_sec;
        long nanoseconds = end.tv_nsec - start.tv_nsec;
        double time_taken = seconds + nanoseconds * 1e-9;

		printf("Print results? ('y' to confirm): ");
		scanf(" %c", &print);
		if(print=='y'){
			printArray(height, width, doubleArr);
			check(height, width, intArr);
		}
		printf("\n\n=====================================================================\n\n");
        printf("Time taken for ASM function: %f x 10^6 ns\n", time_taken * 1000000);

        getAveTime(height * width, (uint8_t *)intArr, (double *)doubleArr);

        printf("Leave? ('y' to exit.):");
        scanf(" %c", &choice);
		printf("\n\n=====================================================================\n\n");
    } while (choice != 'y');
    return 0;
}
