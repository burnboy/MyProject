#include<stdio.h>
#include<string.h>
//40:20

///////////////////////////////////////////////////////////////
//int PhunkyOne(int a, int b)
//{
//	return a + b;
//}
//
//int PhunkyTwo(int a, int b)
//{
//	return a - b;
//}
//
//int MyFunc(int myA, int myB, int(*pFunc)(int, int))
//{
//	printf("A: %d\n B: %d\n result:%d\n", myA, myB, pFunc(myA, myB));
//}
//
//void Swap(int* a, int *b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//
//}
//
//void Swap2(int& a, int &b)
//{
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//
//}
//
//
//
//int main()
//{
//	/*int myA = 2;
//	int myB = 3;
//
//	int(*pFunc)(int, int);
//
//	pFunc = PhunkyOne;
//	printf("A:%d\n B: %d\n result:%d\n", myA, myB, pFunc(myA, myB));
//	
//	pFunc = PhunkyTwo;
//	printf("A:%d\n B: %d\n result:%d\n", myA, myB, pFunc(myA, myB));*/
//	///////////////////////////////////////////////////
//	MyFunc(5, 3, PhunkyOne);
//	MyFunc(5, 3, PhunkyTwo);
//
//	int myInt = 5;
//	int temp = 411;
//	//int* pInt = &myInt;
//	//pInt = &temp;
//	//int &intRef = myInt;
//
//	//printf("myInt: %d", myInt);
//	//pInt = 69;
//	//intRef = 69;
//	//printf("myInt: %d", myInt);
/////////////////////////////////////////////////////////
//	printf("nyInt: %d\ temp:%d\n", myInt, temp);
//
//	int &intRef = myInt;
//	intRef = 42;
//	printf("nyInt: %d\ temp:%d\n", myInt, temp);
//
//	intRef = temp;
//	intRef = 99;
//	printf("nyInt: %d\ temp:%d\n", myInt, temp);
/////////////////////////////////////////////////////////
//
//
//}
/////////////////////////////////////////////////////////////////

class Thing
{


};

int func(const int &, const int &b)
{
	return a + b;
}

void main()
{
	int a = 5;
	int b = -2;
	printf("%d\n", func(a, b));

	//const int answer = 42;
	//answer = 5;

}