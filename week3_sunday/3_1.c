#include <stdio.h>

#pragma warning(disable:4996)

int main1()
{
	FILE* f = fopen("data.bin", "w");
	int a = 190, b = 290, c = 390;
	int read;
	if (!f)
	{
		printf("file cannot open");
		exit(1);
	}
	fwrite(&a, sizeof(int), 1, f);
	fwrite(&b, sizeof(int), 1, f);
	fwrite(&c, sizeof(int), 1, f);
	fclose(f);

	f = fopen("data.bin","r");
	if (!f)
	{
		printf("cannot open file");
		exit(1);
	}
	read = fread(&c, sizeof(int),1,f);
	printf("%d", c);
	fclose(f);
}