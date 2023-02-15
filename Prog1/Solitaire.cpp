//	Trevor Dang
//	CECS 325-02
//	Prog 1 - Fibo Solitaire
//	02/14/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.



#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

int isFibo(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return isFibo(n-1) + isFibo(n-2) ;
}

bool play(Deck newDeck)
{
	bool win = false;
	int sum = 0;
	int count = 0;
	newDeck.shuffle();
	while (newDeck.isEmpty() != true)
	{
		Card myCard = newDeck.deal();
		myCard.show();
		sum += myCard.getValue();
		for (int i=0;i < 15; i++)
		{
			if (sum == isFibo(i))
			{
				count++;
				cout << "Fibo: "<< sum << endl;
				sum = 0;
				if (newDeck.isEmpty() == true){
					win = true;
				}
				break;
			}
		}
	}
	if (win == true){
		cout << "\nWinner in " << count <<" piles!\n" << endl;
	}else
	{
		cout << "Last Pile not Fibo: " << sum << endl;
		cout << "\nLoser in " << count <<" piles \n" << endl;
	}
	return win;
}




int main()
{
	int choice;
	Deck myDeck;
	while (choice != 6)
	{
		
		cout << "Playing Fibonacci Solitaire!\n" << endl;

		cout << "1) Create New Deck\n2) Shuffle Deck\n3) Display Deck\n4) Play Fibo Solitaire\n5) Win Fibo Solitaire\n6) Exit\nEnter Choice:" << endl;
		cin >> choice;
		if (choice == 1)
		{
				myDeck.resetDeck();
				cout << "New Deck has been created!\n"<<endl;
		}
		else if(choice == 2)
		{
			cout << "Deck is shuffled!\n"<<endl;
			myDeck.shuffle();
		}
		else if (choice ==3)
		{
			myDeck.show();
		}
		else if(choice == 4)
		{
			play(myDeck);
		
		}
		else if (choice == 5)
		{	
			int games = 0;
			while (play(myDeck) == false)
			{
				myDeck.shuffle();
				games++;
				
			}
			myDeck.shuffle();
			cout << "Games played: " << games << endl;
		}else{
			cout << "Invalid input, try again!\n" << endl;
		}
	}
	cout << "Thanks for playing!\n"<< endl;
	
}
