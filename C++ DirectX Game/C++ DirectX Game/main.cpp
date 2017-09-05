#include<stdio.h>
#include<stdlib.h>
#include<string.h>//string �� ���ӽ����̽��� �������־���Ѵ�

//1:40:47
class ScoreBoard
{
private:

	class Score
	{

	public:
		Score(int score, const char *time)
	{
		this->score = score;
		this->time = (char*)malloc(strlen(time) + 1);
		strcpy(this->time, time);
		nextScore = NULL;
	}

	Score(FILE *file);
	void Serialize(FILE *file);

	bool Insert(Score* inScore)
	{
		if (inScore->score <= score)
		{
			if (nextScore != NULL)
			{
				if (nextScore->Insert(inScore) == true)
				{

					/*inScore->nextScore = nextScore;*/
					nextScore = inScore;
					return false;
				}

				else
				{
					return false;
				}
			}
			else
			{
				nextScore = inScore;
				return false;
			}

		}
		else
		{
			inScore->nextScore = this;
			return true;//����Ʈ���� �ٸ� ���������� ���ٴ°��� �ǹ�

		}
	}
	Score* Next();

	~Score()
	{
		free(time);
		if (nextScore != NULL)
		{
			delete nextScore;
			nextScore = NULL;
		}
	}

private:
	int score;
	char * time;
	Score*nextScore;

};

public:
	ScoreBoard():
		firstScore(NULL)
	{}

	~ScoreBoard()
	{
		if (firstScore != NULL)
		{
			delete firstScore;
			firstScore = NULL;
		}
	
	}

	void AddScore(int score, const char* time)
	{
		if (firstScore == NULL)
		{
			firstScore = new Score(score, time);
		}
		else
		{
			Score* newScore = new Score(score, time);
			if (firstScore->Insert(newScore) == true)
			{
				firstScore = newScore;
			}
		}
	}


	/*void Test()
	{
		firstScore = new Score(100, "hammertime");
		firstScore->Insert(new Score(50, "miller time"));
		firstScore->Insert(new Score(20,"time to go bed"));
		firstScore->Insert(new Score(70,"foo"));
	}*/
	private:
		Score* firstScore;
		};

void main()		
{		
	ScoreBoard board;
	//board.Test();
}

