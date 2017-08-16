#include<iostream>
#include<string>
using namespace std;

int main()
{
	int counter = 0;

	while (counter<10){
		counter++;
		cout << "while ha " << counter << endl;
	}

	for (int counter = 1; counter <= 10; counter++) {
		cout << "for ha " << counter << endl;
	}

	counter = 0;
	do {
		counter++;
		cout << "do ha" << counter << endl;
	} while (counter < 10);

	system("PAUSE");
	return 0;

}