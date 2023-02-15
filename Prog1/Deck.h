#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <list>
#include "Card.h"
#include <string>

using namespace std;

class Deck
{
	private:
		Card cards[52];
		int track;
		
	
	public:
		Deck();
		void resetDeck();
		Card deal();
		void shuffle();
		bool isEmpty();
		void show();
};

#endif
