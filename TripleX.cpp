#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int GameDifficulty){
    cout << endl << endl;
    cout << "       .-\"\"-." << endl;
    cout << "      / .--. \\" << endl;
    cout << "     / /    \\ \\" << endl;
    cout << "     | |    | |" << endl;
    cout << "     | |.-\"\"-.|" << endl;
    cout << "    ///`.::::.`\\" << endl;
    cout << "   ||| ::/  \\:: ;" << endl;
    cout << "   ||; ::\\__/:: ;" << endl;
    cout << "    \\\\  '::::' /" << endl;
    cout << "     `=':-..-'`" << endl;
    cout << "Jason hides his cake behind a series of 3-combination code locks..." << endl;
    cout << "Enter the correct code combination to continue..." << endl;
    cout << "This lock\'s difficulty is at LEVEL: " << GameDifficulty << endl << endl;
}

bool PlayTheGame(int GameDifficulty){
    PrintIntroduction(GameDifficulty);

    const int CodeA = rand() % GameDifficulty + GameDifficulty;
    const int CodeB = rand() % GameDifficulty + GameDifficulty;
    const int CodeC = rand() % GameDifficulty + GameDifficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "- There are 3 different numbers in the combination..." << endl;
    cout << "- The codes adds up to: " << CodeSum << endl;
    cout << "- The codes multiplies to give: " << CodeProduct << endl << endl;

    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;

    cout << "Please input your numbers, separated by spaces, here: ";
    cin >> GuessA >> GuessB >> GuessC;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    cout << "You\'ve entered: " << GuessA << GuessB << GuessC << endl;
    cout << "Your total sum was: " << GuessSum << endl;
    cout << "Your total product was: " << GuessProduct << endl;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        if(GameDifficulty == 10){
            cout << "** You beat the game! Now you have Jason\'s Cake! **" << endl;
        } else {
            cout << "** You cracked the code! **" << endl;
        }
        return true;
    } else {
        cout << "** That was not the right code. Which caused you to get caught and thrown out. **" << endl;
        return false;
    }

}

int main(){
    bool GameContinue = true;
    int GameDifficulty = 1;
    const int MaxGameDifficulty = 10;

    srand(time(NULL));

    while (GameContinue && GameDifficulty <= MaxGameDifficulty){
        GameContinue = PlayTheGame(GameDifficulty);
        cin.clear();
        cin.ignore();
        ++GameDifficulty;
    }
        
    return 0;
}