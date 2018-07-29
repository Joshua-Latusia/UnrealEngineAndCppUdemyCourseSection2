#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

/**
 * Made by Joshua Latusia during the unreal engine developers course on Udemy
 */

// Function prototypes
void PlayGame();
bool WantToPlayAgain();

FBullCowGame BCGame;

/// <summary>
/// Starting point of this application
/// </summary>
/// <returns></returns>
int main()
{
	bool wantToPlay = true;

	BCGame.PrintIntro();
	while(wantToPlay)
	{
		BCGame.PlayGame();
		wantToPlay = BCGame.WantToPlayAgain();
		BCGame.Reset();
	}
	return 0;
}