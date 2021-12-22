#include<iostream>
#include<random>
#include<ctime>

using namespace std;

int getNumHumans();
int getNumSkeletons();
void printResults(int numHumans,int numSkeletons,int startHumans,int startSkelly);

int main()
{
	default_random_engine randomEngine(time(NULL));
	uniform_real_distribution<float> attack(0.0f,1.0f);
	
	
	//사람정보
	float humanAttack=0.6f;
	float humanHealth=250.0f;
	float humanDamage=200.0f;
	float currentHumanHealth=humanHealth;
	
	//해골 정보
	float skeletonAttack=0.2f;
	float skeletonHealth=50.0f;
	float skeletonDamage=40.0f;
	float currentSkeletonHealth=skeletonHealth;
	
	
	float attackResult;
	
	int startSkeletons;
	int startHumans;
	
	int numSkeletons;
	int numHumans;
	
	char turn ='H';
	
	cout<<"*******skeleton Vs Humans!!********\n"
	numHumans=getNumHumans();		
	startHumans=numHumans;
	
	cout<<"Enter the number of skeletons: ";
	numSkeletons=getNumSkeletons();	
	startSkeletons=numSkeletons;
	
	cout<<"\n Begining combat!!\n\n";
	
	while((numHumans>0)&&(numSkeletons>0)){
	
				attackResult=attack(randomEngine);

	
			if(turn=='H')
			{	
				attackResult=attack(randomEngine);
				
				if(attackResult<=humanAttack)
				{
					currentSkeletonHealth-=humanDamage;
					if(currentSkeletonHealth<0)
					{
						numSkeletons--;
						currentSkeletonHealth=skeletonHealth;
						
					}
				
				}
				
				turn='S';
			}
			else 
			{
				if(attackResult<=skeletonAttack)
				{
					currentHumanHealth-=skeletonDamage;
					if(currentHumanHealth<0){
						numHumans--;
						currentHumanHealth=humanHealth;
					}					
				}
				turn='H';
			}
	}
	// cout<<"\n Battle is over \n\n";
	
	// if(numHumans>0){
		// cout<<"Humans won!\n";
		// cout<<"There are"<<numHumans<<"humans left!";
	// }else{
		
		// cout<<"Skeletons won!\n";
		// cout<<"There are"<<numSkeletons<<"ske left!";
	// }
	
	 printResults( numHumans, numSkeletons,startHumans,startSkelly);

	
	// cout<<startHumans-numHumans<<"humans and"<<startSkeletons-numSkeletons<<"skeletons lost theirt lives\n\n";
	
	
	system("PAUSE");
	return 0;
	
}

int getNumHumans()
{
	int numHumans;
	cout<<"Enter the number of humans: ";
	cin>>numHumans;	
	return numHumans;
}

int getNumSkeletons()
{
	int numSkeletons;
	cout<<"Enter the number of Skeletons: ";
	cin>>numSkeletons;	
	return numSkeletons;
}

void printResults(int numHumans,int numSkeletons,int startHumans,int startSkelly)
{
		cout<<"\n Battle is over \n\n";
	
	int numHumans;
	int numSkeletons;
	
	if(numHumans>0){
		cout<<"Humans won!\n";
		cout<<"There are"<<numHumans<<"humans left!";
	}else{
		
		cout<<"Skeletons won!\n";
		cout<<"There are"<<numSkeletons<<"ske left!";
	}
	
		cout<<startHumans-numHumans<<"humans and"<<startSkelly-numSkeletons<<"skeletons lost theirt lives\n\n";
		cin>>numHumans;
		
}



