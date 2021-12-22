#include<iostream>
#include<string>
#include<random>
#include<ctime>

using namespace std;

// int main()
// {
	// // default_random_engine randomGenerator;
	// // default_random_engine randomGenerator(6543);
	// default_random_engine randomGenerator(time(0));

	
	
	// uniform_int_distribution<int> diceRoll(1,6);
	
	// cout<<"I am rolling a"<<diceRoll(randomGenerator)<<endl;
	// cout<<"I am rolling a"<<diceRoll(randomGenerator)<<endl;
	// cout<<"I am rolling a"<<diceRoll(randomGenerator)<<endl;
	// cout<<"I am rolling a"<<diceRoll(randomGenerator)<<endl;
	// cout<<"I am rolling a"<<diceRoll(randomGenerator)<<endl;
	// cout<<"I am rolling a"<<diceRoll(randomGenerator)<<endl;
	
	
	// system("PAUSE");
	// return 0;
// }

////////////////////////////////////////////////////////////////////////

int main()
{
	// default_random_engine randomGenerator;
	// default_random_engine randomGenerator(6543);
	default_random_engine randomGenerator(time(0));
	
	uniform_int_distribution<float> attackRoll(0.0f,1.0f);
	
	cout<<"I am attacking snake! ";
	
	float attack =attackRoll(randomGenerator);
	
	if(attack<=0.3f)
	{
		cout<<"I hit the snake! yay! \n";
	}
	else
	{
		cout<<"I missed the snake oh nooo!\n";
		
	}	
	
	system("PAUSE");
	return 0;
}





