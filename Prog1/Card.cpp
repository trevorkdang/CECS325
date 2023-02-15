#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor for Card class
Card::Card()
{
	rank = "X";
	suit = 'X';
}

Card::Card(string r, char s)
{
	rank = r;
	suit = s;
}

void Card::setCard(string r, char s)
{
	rank = r;
	suit = s;
}

//Gets the value between 1-10 in numbers
int Card::getValue()
{
	if (rank == "A"){
		return 1;
	}
	else if (rank == "J"){
		return 10;
	}
	else if (rank == "Q"){
			return 10;
	}
	else if (rank == "K"){
			return 10;
	}
	else{
		return stoi(rank);
	}
}

//Shows the rank and suit
void Card::show()
{
	cout << rank << suit << ", ";
}
