#include <iostream>
#include "Deck.h"
#include <list>
#include <string>
#include <iterator>
#include <ctime>
using namespace std;

Deck::Deck()
{
	resetDeck();
}

void Deck::resetDeck()
{
	track = 0;
	string ranks[13] =  {"A", "2","3","4","5","6","7","8","9","10","J","Q","K"};
	char suits[4] = {'S', 'H', 'D', 'C'};
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++){
			cards[track].setCard(ranks[j], suits[i]);
			track++;
		}
	}
}

Card Deck::deal()
{
	track--;
	return cards[track];
}

void Deck::shuffle()
{
	Card temp;
	int rando;
	srand(time(0));
	for (int i = 0; i < 52; i++){
		
		
		rando = rand()%52;

		temp = cards[i];
		cards[i] = cards[rando];
		cards[rando] = temp;
		

		
	track = 52;
	}
	
}

bool Deck::isEmpty()
{
	if (track == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Deck::show()
{
	int check;
	check = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cards[check].show();
			check++;
		}
	cout << endl;
	}
}
