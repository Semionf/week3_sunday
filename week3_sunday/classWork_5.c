#include <stdio.h>

#pragma warning (disable: 4996)
int main()
{
	FILE* f = fopen("file3.bin", "w");
	if (!f)
	{
		printf("Cannot open file");
		exit(1);
	}
	struct Item
	{
		int barcode;
		int price;
		char name[100];
		char color[100];
	};

	struct Item i1 = { 12,15,"Cola","Black" };
	fwrite(&i1, sizeof(struct Item), 1, f);
	fclose(f);

	f = fopen("struct.bin", "r");
	if (!f)
	{
		printf("Cannot open file");
		exit(1);
	}
	fread(&i1, sizeof(struct Item), 1, f);
	printf("%d %d %s %s", i1.barcode, i1.price, i1.name, i1.color);
	fclose(f);
}

