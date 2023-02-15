#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card
{
	private:
		string rank;
		char suit;

	public:
		Card();
		Card(string, char);
		void setCard(string, char);
		int getValue();
		void show();
};

#endif
