#include <stdio.h>

#pragma warning (disable:4996)

int main2()
{
	short num,num2 = 0;
	int read;
	FILE* f = fopen("file.bin", "w");
	if (!f)
	{
		printf("Cannot open file");
		exit(1);
	}
	scanf("%hi", &num);
	fwrite(&num, sizeof(short), 1, f);
	fclose(f);

	f = fopen("file.bin", "r");
	if (!f)
	{
		printf("Cannot open file");
		exit(1);
	}
	read = fread(&num2, sizeof(short), 1, f);
	printf("%d", num2*num2);
	fclose(f);
}