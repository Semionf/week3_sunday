#include <stdio.h>

#pragma warning (disable:4996)

int main3()
{
	int numbers[10],sum=0;
	FILE* f = fopen("file2.bin", "w");
	if (!f)
	{
		printf("Cannot open file");
		exit(1);
	}
	for (int i = 0; i < 10; i++)
	{
		printf("Please enter %d number: ", i+1);
		scanf("%d", &numbers[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		fwrite(&numbers[i], sizeof(int), 1, f);
	}
	fclose(f);
	f = fopen("amir.bin", "r");
	for (int i = 0; i < 10; i++)
	{
		fread(&numbers[i], sizeof(int), 1, f);
		sum += numbers[i];
	}
	printf("The sum is: %d", sum);
	fclose(f);
}