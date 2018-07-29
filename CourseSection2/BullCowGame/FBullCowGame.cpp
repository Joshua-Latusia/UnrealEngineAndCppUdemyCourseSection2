#include "FBullCowGame.h"
#include <iostream>

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry;  }
int32 FBullCowGame::GetWordLength() const { return WordLength;  }



/// <summary>
/// Resets the game.
/// </summary>
void FBullCowGame::Reset()
{
	CurrentTry = 1;
}

/// <summary>
/// Plays the game.
/// </summary>
void FBullCowGame::PlayGame()
{
	for (int32 i = 0; i < GetMaxTries(); i++)
	{
		GetGuess();
	}
}

/// <summary>
/// Prints the intro to the console.
/// </summary>
void FBullCowGame::PrintIntro() const
{
	std::cout << "Welcome to my first C++ game: Bulls and Cows\n\n";
	std::cout << "Can you guess the " << WordLength << " letter isogram correct?\n";
}

/// <summary>
/// Gets the guess from the console.
/// </summary>
/// <returns></returns>
void FBullCowGame::GetGuess()
{
	std::cout << "Guess: " << CurrentTry << std::endl;
	FText guessedWord;

	// If gues is not valid ask again
	std::getline(std::cin, guessedWord);

	if(IsGuessValid(guessedWord))
	{
		GetFGameScore(guessedWord);
	}
	else
	{
		std::cout << guessedWord << " Is not a valid word, please try again\n" << std::endl;
		GetGuess();
	}
}

/// <summary>
/// Asks if player wants to play again.
/// </summary>
/// <returns></returns>
bool FBullCowGame::WantToPlayAgain() const
{
	FText answer;
	std::cout << "Do you want to play again?\n";
	std::getline(std::cin, answer);

	return answer[0] == 'y' || answer[0] == 'Y';
}

/// <summary>
/// Determines whether game is won or not
/// </summary>
/// <returns>
///   <c>true</c> if [is game won]; otherwise, <c>false</c>.
/// </returns>
bool FBullCowGame::IsGameWon() const
{
	return false;
}

/// <summary>
/// Gets the game score.
/// </summary>
/// <param name="">The .</param>
/// <returns></returns>
FGameScore FBullCowGame::GetFGameScore(const FText& guess)
{
	FGameScore score;
	std::cout << "You guessed the word " << guess << std::endl;
	CurrentTry++;

	for (int i = 0; i < guess.length(); i++)
	{
		// If letter is in the word but at the wrong place -> add cow
		if(Word.find(guess[i]) != FText::npos && guess[i] != Word[i])
		{
			score.Cows++;
		}
		// If letter is on the correct place -> add bull
		if(guess[i] == Word[i])
		{
			score.Bulls++;
		}
	}

	std::cout << "Your score is Bulls: " << score.Bulls << " Cows: " << score.Cows << std::endl << std::endl;

	return score;
}

/// <summary>
/// Determines whether Guess is valid or not
/// </summary>
/// <param name="">The .</param>
/// <returns>
///   <c>true</c> if [is guess valid] [the specified ]; otherwise, <c>false</c>.
/// </returns>
bool FBullCowGame::IsGuessValid(const FText& guess) const
{
	return guess.length() == GetWordLength();
}
