//	Trevor Dang
//	CECS 325-02
//	Prog 2 - Fibo Solitaire (Single File)
//	02/21/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

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
