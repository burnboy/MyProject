#include<iostream>
#include<cstdlib>
#include<string>
#include<conio.h>
#include"GameSystem.h"
#include"Player.h"

using namespace std;
//1:40:02
int main()
{
	//char input;


	//while(true){
	//	input = _getch();
	//	string clearScreenString(100, '\n');
	//	cout << clearScreenString;
	//	cout << "you entered: " << input << endl;
	//}

	GameSystem gameSystem("Level1.txt");

	gameSystem.playGame();



	return 0;
}