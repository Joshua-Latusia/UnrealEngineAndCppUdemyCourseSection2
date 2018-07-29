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
/// State of a word
/// </summary>
enum EWordStatus
{
	OK,
	NOT_ISOGRAM,
	INVALID_LENGTH
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
	EWordStatus GetWordStatus(const FText&) const;
	bool IsIsoGram(FText str) const;
	static void ToLower(FText& str);
	bool IsGameWon() const;
	bool WantToPlayAgain() const;
	void GetGuess();
	void Reset();
	void PlayGame();


private:
	int32 CurrentTry = 1;
	int32 MaxTries = 5;
	FText Word = "worst";
};
