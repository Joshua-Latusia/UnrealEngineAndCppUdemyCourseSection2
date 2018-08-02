#include "FBullCowGame.h"
#include <iostream>

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry;  }
int32 FBullCowGame::GetWordLength() const { return Word.length(); }

/// <summary>
/// Resets the game.
/// </summary>
void FBullCowGame::Reset()
{
	CurrentTry = 1;
	Score = { 0,0 };

	std::cout << std::string(3, '\n');
}

/// <summary>
/// Plays the game.
/// </summary>
void FBullCowGame::PlayGame()
{
	while (GetCurrentTry() <= GetMaxTries() && !IsGameWon())
	{
		GetGuess();
	}

	if(IsGameWon())
	{
		std::cout << "You win" << std::endl << std::endl;  // todo print screen method
	}
	else
	{
		std::cout << "You lost" << std::endl << std::endl; // todo print screen method
	}
}

/// <summary>
/// Prints the intro to the console.
/// </summary>
void FBullCowGame::PrintIntro() const
{
	std::cout << "Welcome to my first C++ game: Bulls and Cows\n\n";
	std::cout << "Can you guess the " << GetWordLength() << " letter isogram correct?\n";
}

/// <summary>
/// Gets the guess from the console.
/// </summary>
/// <returns></returns>
FGameScore FBullCowGame::GetGuess()
{
	std::cout << "Guess: " << CurrentTry << std::endl;
	FText guessedWord;

	// If gues is not valid ask again
	std::getline(std::cin, guessedWord);
	ToLower(guessedWord);

	const EWordStatus status = GetWordStatus(guessedWord);
	switch(status)
	{
		case OK:
			return GetFGameScore(guessedWord);
		case NOT_ISOGRAM:
			std::cout << guessedWord << " Is not am isogram, please try again\n" << std::endl;
			GetGuess();
		break;
		case INVALID_LENGTH:
			std::cout << guessedWord << " Has an invalid length, please try again\n" << std::endl;
			GetGuess();
		break;
		default:
			std::cout << "Something went wrong while processing the word: " << guessedWord << std::endl;
			GetGuess();
		break;
	}
	return {};
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
	return Score.Bulls == GetWordLength();
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

	for (auto i = 0; i < guess.length(); i++)
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

	Score = score;
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
EWordStatus FBullCowGame::GetWordStatus(const FText& guess) const
{
	if (guess.length() != GetWordLength())
		return INVALID_LENGTH;
	if (!IsIsoGram(guess))
		return NOT_ISOGRAM;

	return OK;
}

bool FBullCowGame::IsIsoGram(const FText str) const
{
	return true;
}

void FBullCowGame::ToLower(FText& str)
{
	for (auto& i : str)
	{
		i = tolower(i);
	}
}
