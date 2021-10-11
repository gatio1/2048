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

void insertRandom()//adds a random number at a free place, ne bacha ama hich
{
    srand (time(NULL));
	int c, n, k=0;
	int **emptycells;
	emptycells=(int**)malloc(2*sizeof(int*));
	//(*emptycells)[0]=(int*)malloc(sizeof(int));
	//(*emptycells)[1]=(int*)malloc(sizeof(int));
	emptycells[0]=(int*)malloc(sizeof(int));//ednakvi adresi na dwata masiva
	emptycells[1]=(int*)malloc(sizeof(int));//ednakvi adresi na dvata masiva
	if((long)emptycells[0]==(long)emptycells[1]) cout<<"\nRavni sa kvo da napravq\n";
	for(c=0; c<4; c++)
	{
        for(n=0;n<4;n++)
        {
            if(table[c][n]==0)
            {
                if(k==0)
                {
                    emptycells[0][k]=c;
                    emptycells[1][k]=n;
                    k++;
                }
                else
                {
                    emptycells[0]=(int*)realloc(emptycells[0], (k+1)*sizeof(int));
                    emptycells[1]=(int*)realloc(emptycells[1], (k+1)*sizeof(int));
                    if((long)emptycells[0]==(long)emptycells[1]) cout<<endl<<"!!c="<<c<<", "<<n<<"=n!!"<<endl;
                    emptycells[0][k]=c;
                    emptycells[1][k]=n;
                    k++;
                }
            }
        }
	}
	cout<<endl;
	for(int i=0; i!=k; i++)
	{
        cout<<"["<<emptycells[0][i]<<"],["<<emptycells[1][i]<<"] ; ";
	}
	cout<<endl;
	if(k==0) exit(EXIT_FAILURE);
	srand (time(NULL));
	int pos = rand()%k;
	srand (time(NULL));
	int num=rand()% 2;
	switch(num)
	{
		case 0 : table[emptycells[0][pos]][emptycells[1][pos]]=2 ;break;
		case 1 : table[emptycells[0][pos]][emptycells[1][pos]]=4 ;break;
	}


    free(emptycells[1]);
	free(emptycells);
	/*for(int i=0; i!=k; i++)
	{
        cout<<"["<<emptycells[0][i]<<"],["<<emptycells[0][i]<<"] ; ";
	}*/
}
void shiftUp(int *score)
{

	int k, additions=0;
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
					}
				}
				if(table[c][n]!=0)
				{
					if(table[c][n]==table[c+1][n]&&additions==0)
					{
						table[c][n]=2*table[c][n];
						*score+=table[c][n];
						table[c+1][n]=0;
						k++;
						additions++;
					}
				}
			}
			additions=0;
		}
	}while (k!=0);
}
void shiftDown(int *score)
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
						*score+=table[c][n];
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
void shiftLeft(int *score)
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
						*score+=table[c][n];
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
void shiftRight(int *score)
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
						*score+=table[c][n];
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
	int score=0;
	while(!gameOver())
	{
		if(i>0) insertRandom();
		print();
		printf("\n %d \n", score);
			i=0;
			char a;
			cin>>a;
			if(a=='k') return 0;
			if(a=='w') shiftUp(&score);
			else if(a=='a') shiftLeft(&score);
			else if(a=='s') shiftDown(&score);
			else if(a=='d') shiftRight(&score);
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
//kolega problem izchezbat chisla
//columns and rows arent the same when shifting. column counter doesn't work.
//when moving up and down new numbers don't appear
//New numbers appear in the place of old ones
//Dynamic array in insertRandom is retarded.
