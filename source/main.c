#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int wDeck[][13]);//�~�P
void deal(const int wDeck[][13], const int *wFace[],
		  const char *wSuit[]);//�o�P

int main(void)
{
	const char *suit[4] = { "Hearts","Diamonds","Clubs","Spades" };//���//���ߡA�p�ۡA����A�®�

	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
							 "Eight", "Nine", "Ten", "Jack", "Queen", "King" };//�P��
	
	int deck[4][13] = { 0 };//�N�P����ȳ]�w��0
	srand(time(0));//���ü�

	shuffle(deck);
	deal(deck, face, suit);

	system("pause");
	return 0;
}
/////////////////////////////�N�P�g�JŪ��//�o�P
void shuffle(int wDeck[][13])
{
	int row, column, card;//�C�A��A�P
	
	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand()% 13;
		} while (wDeck[row][column] != 0);

		wDeck[row][column] = card;
	}
}
/////////////////////////////�N�P�̷�Ū�ȼg�J�j�p�Ϊ��
void deal(const int wDeck[][13], const int *wFace[], const char *wSuit[])
{
	int row, column, card;
	for (card = 1; card <= 52; card++)
	{
		for (row = 0; row <= 3; row++)
		{
			for (column = 0; column <= 12; column++)
			{
				if (wDeck[row][column] == card)
				{
					printf("%5s of %-8s%c", wFace[column], wSuit[row], 
											card % 2 == 0 ? '\n' : '\t');
				}
			}
		}
	}
}