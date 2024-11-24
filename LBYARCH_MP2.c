
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

extern void imgCvtGrayIntToDouble(int numOfElements, uint8_t* intArr, double* doubleArr);


void assignValue(char row[], int width, uint8_t intArr[])
{
	char* nums;
	nums = strtok(row, " ");
	int i = 0;
	
	while(nums != NULL && i < width)
	{
		intArr[i] = (uint8_t)atoi(nums);
		nums = strtok(NULL, " ");
		i++;
	}
}

void getInput(int height, int width, uint8_t intArr[height][width]) 
{
	int i;
	printf("Input %d integers per Row: {example: 3 4 5 ... 7}\n\n", width);
	for(i = 0; i < height; i++) 
	{
		char row[1024];
		printf("> ");
		fgets (row, sizeof(row), stdin);
		assignValue(row, width, intArr[i]);
	}
}

void printArray(int height, int width, double doubleArr[height][width]) 
{
	int i;
	int j;
	printf("\n");
	for(i = 0; i < height; i++) 
	{
		for(j = 0; j < width; j++)
		{
			printf("%.2f ", doubleArr[i][j]);
		}
		printf("\n");
	}
}

void check(int height, int width, uint8_t intArr[height][width]) 
{
	int i, j;
	
	printf("\nCheck answer: \n\n");
	for(i = 0; i < height; i++) 
	{
		for(j = 0; j < width; j++)
		{
			double ans = intArr[i][j] / 255.0;
			printf("%.2f ", ans);
		}
		printf("\n");
	}
}

//void getAveTime(int totalElements, uint8_t* intArr, double* doubleArr) 
//{
//	double time_taken;
//	int i;
//	
//	for(i = 0; i < 30; i++ ) {
//		clock_t start = clock();
//		imgCvtGrayIntToDouble(totalElements, intArr, doubleArr);
//		clock_t end = clock();
//		
//		time_taken += (double)(end - start) / CLOCKS_PER_SEC;
//	}
//	
//	time_taken = time_taken / 30.0;
//	
//	printf("\nAverage Time taken for ASM function: %.20lf\n", time_taken);
//}

int main() 
{
	int height = 2;
	int width = 2;
	
	printf("Input Height and Width (H W): > ");
	scanf("%d %d", &height, &width);
	
	uint8_t intArr[height][width];
	double doubleArr[height][width];
	
	fflush(stdin);
	
	getInput(height, width, intArr);
	
	clock_t start = clock();
	imgCvtGrayIntToDouble(height * width, (uint8_t *)intArr, (double *)doubleArr);
	clock_t end = clock();
	
   	double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nTime taken for ASM function: %f\n", time_taken);
	
	printArray(height, width, doubleArr);
	check(height, width, intArr);
	
	return 0;
}



