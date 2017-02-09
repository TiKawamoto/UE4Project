#pragma once
#include <string>

class FBullCowGame 
{
public:
	FBullCowGame(); // the constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	
	void Reset(); // TODO make a more rich return value
	bool CheckGuessValidity(std::string); //TODO Make more rich return value
	// provide a method for counting bulls and cows, increase try number

private:
	//see constructor for initialization
	int MyMaxTries;
	int MyCurrentTry;

};