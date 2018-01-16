#include<stdio.h>
//2:20:10

#define HERP 0x01
#define SYPH 0x02
#define GON 0x04
#define CLAP 0x08

//struct TestResults
//{
//	bool hasHerpes;
//	bool hasSyphillis;
//	bool hasGhonorrea;
//	bool hasClymidia;
//
//};

void PrintResults(/*TestResults*/ char results)
{
	if (HERP&results)
	{
		printf("You have Herpes!\n");
	}

	if (SYPH&results)
	{
		printf("You have Syphillis!\n");
	}

	if (GON&results)
	{
		printf("You have Ghonorrea!\n");
	}

	if (CLAP&results)
	{
		printf("You have Clymidia!\n");
	}


	//if (results.hasHerpes)
	//{
	//	printf("You have Herpes!\n");
	//}

	//if (results.hasSyphillis)
	//{
	//	printf("You have Syphillis!\n");
	//}	
	//
	//if (results.hasGhonorrea)
	//{
	//	printf("You have Ghonorrea!\n");
	//}

	//if (results.hasClymidia)
	//{
	//	printf("You have Clymidia!\n");
	//}

}

void main()
{

	//TestResults results;
	//results.hasClymidia = true;
	//results.hasHerpes = true;
	//results.hasSyphillis = false;
	//results.hasGhonorrea = false;
	char results = HERP | SYPH | CLAP;


	PrintResults(results);
	printf("Results char occupies %d bytes in memory.\n", sizeof(char));

	//char a = 7;
	//char b = 8;

	//printf("%d\n", (a&b));
	//printf("%d\n", (a | b));

	//printf("%d\n", (a&&b));
	//printf("%d\n", (a||b));
	//printf("%d\n", (a << 2));
	//printf("%d\n", (char)(a << 5));


}