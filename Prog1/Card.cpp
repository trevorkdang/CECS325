#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

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

void Card::show()
{
	cout << rank << suit << ", ";
}
