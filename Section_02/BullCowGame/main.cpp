#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// entry point for application
int main() 
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
	
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0; // exit the application
}


// introduce the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;
}

// main gameplay
void PlayGame()
{
	BCGame.Reset();

	int MaxTries = BCGame.GetMaxTries();

	// loop for num of turns asking for guesses
	// TODO change from FOR to WHILE loop once we're validating tries

	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game
		// print number of bulls and cows

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	// TODO add game summary
}

// get a guess from the player
std::string GetGuess() 
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";

	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	std::cout << std::endl;

	return (Response[0] == 'y') || (Response[0] == 'Y');
}
