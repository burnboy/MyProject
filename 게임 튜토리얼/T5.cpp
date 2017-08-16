#include<iostream>
#include<string>

using namespace std;

int main()
{
	string PlayerName;
	int age;
	cout << "what is your name sir knight?\n";
	cin >> PlayerName;

	cout << "Hello Sir" << PlayerName << endl;
	cout << "How old are you?:";
	cin >> age;

	if (age <= 3) {
		
		cout << "you are lying!";
	}
	
	else if (age < 12)	{
		cout << "you are too young to play!\n";

	}

	else if (age > 90)
	{
		cout << "you are too old to play!\n";
	}

	
	//else if /*(age >= 12 && age <= 90)*/
	else
	{
		cout << "you are enough to play!\n";
	}

	system("pause");
	return 0;
}