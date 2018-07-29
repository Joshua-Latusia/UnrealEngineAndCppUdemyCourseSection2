#pragma once
#include <string>

using FText = std::string;
using int32 = int;

struct FGameScore
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

/// <summary>
/// Instace of the game
/// </summary>
class FBullCowGame
{

public:
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWordLength() const;
	FGameScore GetFGameScore(const FText&);
	void PrintIntro() const;
	bool IsGuessValid(const FText&) const;
	bool IsGameWon() const;
	bool WantToPlayAgain() const;
	void GetGuess();
	void Reset();
	void PlayGame();


private:
	int32 CurrentTry = 1;
	int32 MaxTries = 5;
	int32 WordLength = 5;
	FText Word = "worst";
};
