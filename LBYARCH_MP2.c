
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

extern int imgCvtGrayIntToDouble(uint8_t *arr, double *convArr, int height, int weight);


void assignValue(char row[], int width, uint8_t arr[])
{
	char* nums;
	nums = strtok(row, ", ");
	int i = 0;
	
	while(nums != NULL && i < width)
	{
		arr[i] = atoi(nums);
		nums = strtok(NULL, ", ");
		i++;
	}
}

void getInput(int height, int width, uint8_t arr[height][width]) 
{
	int i;
	for(i = 0; i < height; i++) 
	{
		char row[1024];
		printf("Input %d integers for Line %d: {comma-separated: 3, 4, 5, ...}\n", width, i);
		fgets (row, sizeof(row), stdin);
		assignValue(row, width, arr[i]);
	}
}

void printArray(int height, int width, uint8_t arr[height][width]) 
{
	int i;
	int j;
	for(i = 0; i < height; i++) 
	{
		for(j = 0; j < width; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() 
{
	int height = 2;
	int width = 2;
	uint8_t arr[height][width];
	double convArr[height][width];
	
	printf("Input Height and Width: ");
	scanf("%d %d", &height, &width);
	
	fflush(stdin);
	
	getInput(height, width, arr);
	imgCvtGrayIntToDouble((uint8_t *)arr, *convArr, height, width);
	printArray(height, width, arr);
}



