#include<stdio.h>
#include<stdlib.h>
#include<string.h>//string 은 네임스페이스를 선언해주어야한다


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
		Score(FILE *file)
		{
			char buffer[128];
			fscanf(file, "%d %s",&score,buffer);
			time = (char*)malloc(strlen(buffer) + 1);
			strcpy(time, buffer);

			fseek(file,4,SEEK_CUR);
			fgetc(file);			//need to set EOF indicator for feof() call

			if (!feof(file))
			{
				nextScore = new Score(file);
			}
			else
			{
				nextScore = NULL;
			}
		}

	void Serialize(FILE *file,int index)
	{
		fprintf(file, "%d.\t%d\t%s\n", (index + 1), score,time);
		if (nextScore)
		{
			nextScore-> Serialize(file, (index + 1));
		}
	}

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
			return true;//리스트에서 바른 포지션으로 간다는것을 의미

		}
	}
	Score* Next();

	void Test()
	{
		printf("%d:%s\n", score, time);
		if (nextScore)
		{
			nextScore->Test();
		}
	}
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
	ScoreBoard(const char *fileName)
		:
		firstScore(NULL)
	{
		this->fileName = (char*)malloc(strlen(fileName) + 1);
		strcpy(this->fileName, fileName);

		FILE*pFile = fopen("hiscore.txt", "r");
		if (pFile)
		{
			fseek(pFile, 2, SEEK_CUR);
			fgetc(pFile);
			if (!feof(pFile))
			{
				firstScore = new Score(pFile);
			}
			else
			{
				firstScore = NULL;
			}
			fclose(pFile);
		}

	}
	~ScoreBoard()
	{
		 Serialize();

		if (firstScore != NULL)
		{
			delete firstScore;
			firstScore = NULL;
		}
		if (fileName != NULL)
		{
			free(fileName);
			fileName = NULL;
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
	//void Test()
	//{
	//	if (firstScore)
	//	{
	//		firstScore->Test();
	//	}
	//}

	//private:
	/*void Test()
	{
		firstScore = new Score(100, "hammertime");
		firstScore->Insert(new Score(50, "miller time"));
		firstScore->Insert(new Score(20,"time to go bed"));
		firstScore->Insert(new Score(70,"foo"));
	}*/

	void Serialize()
	{
		FILE *pFile = fopen(fileName, "w");
		if (firstScore)
		{
			firstScore->Serialize(pFile,0 );
		}
		fclose(pFile);
	}

	private:
		Score* firstScore;
		char *fileName;

};

void main()		
{		
	ScoreBoard board("highscore.txt");
	board.AddScore(100, "hammertime");
	board.AddScore(50, "miller time");
	board.AddScore(70, "vader time");
	board.AddScore(20, "what??");
	board.AddScore(150, "foo");
	//board.Test();
	board.Serialize();
}

