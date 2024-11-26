#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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

	imgCvtGrayIntToDouble(height * width, (uint8_t *)intArr, (double *)doubleArr);
	
	printArray(height, width, doubleArr);
	check(height, width, intArr);
	
	return 0;
}