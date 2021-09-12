#include <iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int table[4][4];
int i=1;
bool isEmpty (int c,int  n){
	return table[c][n]==0;
}

void print()

{
	cout<<" _______________________"<<endl;
	for(int c=0;c<4;c++)
		{cout<<"|";
			for (int n=0;n<4;n++)
			{
				if (table[c][n]==0) cout<<"     |";

				else if (table[c][n]<=9)
					cout<<table[c][n]<<"    |";
				else if (table[c][n]<=99)
					cout<<table[c][n]<<"   |";
				else if (table[c][n]<=999)
					cout<<table[c][n]<<"  |";
				else cout <<table[c][n]<<" |";
			}
			cout<<'\n';
		}
	cout<<" -----------------------"<<endl;
}

void insertRandom()//adds a random number at a free place
{
	int c,n;
	do
	{
	c= rand() % 4;
	n= rand() % 4;
	}
	while(table[c][n]!=0);
	int k=rand()% 2;
	switch(k)
	{
		case 0 : table[c][n]=2 ;break;
		case 1 : table[c][n]=4 ;break;
	}
}
void shiftUp()
{

	int k, moves=0;
	do
	{
		k=0;
		for(int c=0;c<3;c++)
		{
			for(int n=0;n<4;n++)
			{
				if(table[c][n]==0)
				{
					if(table[c+1][n]!=0)
					{
						table[c][n]=table[c+1][n];
						table[c+1][n]=0;
						k++;
						i++;
					}
				}
				if(table[c][n]!=0)
				{
					if(table[c][n]==table[c+1][n]&&moves==0)
					{
						table[c][n]=2*table[c][n];
						table[c+1][n]=0;
						k++;
						i++;
						moves++;
					}
				}
			}
			moves=0;
		}
	}while (k!=0);
}
void shiftDown()
{
	int k, moves=0;
	do
	{
		k=0;
		for(int c=3;c>0;c--)
		{
			for(int n=0;n<4;n++)
			{
				if(table[c][n]==0)
				{
                    if(table[c-1][n]!=0)
					{
						table[c][n]=table[c-1][n];
						table[c-1][n]=0;
						k++;
						i++;
					}
				}
				if(table[c][n]!=0)
				{
					if(table[c][n]==table[c-1][n]&&moves==0)
					{
						table[c][n]=2*table[c][n];
						table[c-1][n]=0;
						k++;
						i++;
						moves++;
					}
				}
			}
			moves=0;
		}
	}while(k!=0);
}
void shiftLeft()
{
	int k, moves=0;
	do
	{
		k=0;
		for(int n=0;n<3;n++)
		{
			for(int c=0;c<4;c++)
			{
				if(table[c][n]==0)
				{
					if(table[c][n+1]!=0)
					{
						table[c][n]=table[c][n+1];
						table[c][n+1]=0;
						k++;
						i++;
					}
				}
				if(table[c][n]!=0)
				{
					if(table[c][n]==table[c][n+1]&&moves==0)
					{
						table[c][n]=2*table[c][n];
						table[c][n+1]=0;
						k++;
						i++;
						moves++;
					}
				}
			}
			moves=0;
		}
	}while(k!=0);
}
void shiftRight()
{
	int k, moves=0;
	do
	{
		k=0;
		for(int n=3;n>0;n--)
		{
			for(int c=0;c<4;c++)
			{
				if(table[c][n]==0)
				{
					if(table[c][n-1]!=0)
					{
						table[c][n]=table[c][n-1];
						table[c][n-1]=0;
						k++;
						i++;
					}
				}
				if(table[c][n]!=0&&moves==0)
				{
					if(table[c][n]==table[c][n-1]&&moves==0)
					{
						table[c][n]=2*table[c][n];
						table[c][n-1]=0;
						k++;
						i++;
						moves++;
					}
				}
			}
			moves=0;
		}
	}while(k!=0);
}
bool gameOver()
{
	int k=0;
	for(int c=0;c<4;c++)
	{
		for(int n=0;n<4;n++)
		{
			if(table[c][n]==0) return false;
			if(c!=3&&n!=3)
			{
                if(table[c][n]==table[c+1][n]||table[c][n]==table[c][n+1])return false;
            }
		}
	}
    return true;
}
int main()

{
    int highest_num=0;
	srand(time(NULL));
	insertRandom();
	while(!gameOver())
	{
		if(i>0) insertRandom();
		print();
			i=0;
			char a;
			cin>>a;
			if(a=='k') return 0;
			if(a=='w') shiftUp();
			else if(a=='a') shiftLeft();
			else if(a=='s') shiftDown();
			else if(a=='d') shiftRight();
		for(int c=0;c<4;c++)
		{
			for(int n=0;n<4;n++)
			{
				if(table[c][n]==2048)
				{
					cout<<"                       ---Congratulations!!!!!You win.---\n";
				}
			}
		}

		for(int c=0;c<4;c++)
		{
			for(int n=0;n<4;n++)
			{
				if(table[c][n]>highest_num) highest_num=table[c][n];
			}
		}
		cout<<"-------------------------------\n";
	}
	cout<<"----------------------------------------------------------------------------------------\n------------------------------The game is over my friend------------------------------------\n----------------------------------------------------------------------------------------";
	int score;
	ifstream openscore;
		openscore.open("2048score.txt",ios::in);
		openscore>>score;
		if(highest_num>score)
		{
			openscore.close();
			ofstream scoreopen;
			scoreopen.open("2048score.txt",ios::out);
			scoreopen<<highest_num;
			scoreopen.close();
			cout<<"HIGHSCORE!!!!!!!!!!!"<<endl;
		}

		return 0;
}
