#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int wDeck[][13]);//洗牌
void deal(const int wDeck[][13], const int *wFace[],
		  const char *wSuit[]);//發牌

int main(void)
{
	const char *suit[4] = { "Hearts","Diamonds","Clubs","Spades" };//花色//紅心，鑽石，梅花，黑桃

	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
							 "Eight", "Nine", "Ten", "Jack", "Queen", "King" };//牌面
	
	int deck[4][13] = { 0 };//將牌的初值設定為0
	srand(time(0));//取亂數

	shuffle(deck);
	deal(deck, face, suit);

	system("pause");
	return 0;
}
/////////////////////////////將牌寫入讀值//發牌
void shuffle(int wDeck[][13])
{
	int row, column, card;//列，行，牌
	
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
/////////////////////////////將牌依照讀值寫入大小及花色
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