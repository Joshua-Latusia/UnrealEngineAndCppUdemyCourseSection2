#pragma once
#include <string>
#include <vector>

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
	void PrintIntro();
	EWordStatus GetWordStatus(const FText&) const;
	static bool IsIsoGram(const FText& str);
	static void ToLower(FText& str);
	bool IsGameWon() const;
	bool WantToPlayAgain() const;
	int32 GetWordLengthInput() const;
	FGameScore GetGuess();
	void Reset();
	void PlayGame();
	void SetHiddenWord(int32);


private:
	int32 CurrentTry = 1;
	int32 MaxTries = 5;
	const int32 MinWordtLength = 3;
	const int32 MaxWordLength = 5;
	FText Word;
	FGameScore Score = { 0, 0 };
	std::vector<FText> IsoGramList = { "mac", "mad", "man", "rule", "raid", "haze", "heart", "haste", "bread" };
};
