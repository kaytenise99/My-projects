#include <iostream>
#include <ctime>

//Prints information to the user about game

void PrintIntroduction(int Difficulty)
{
    std::cout<<"\n\nYou are a secret agent breaking into a level "<< Difficulty;
    std::cout<<" bank vault....\nYou need the correct combination to open the vault\n\n";
}
 
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    //Declare 3 number combination
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //prints Codesum and Codeproduct the to the terminal
    std::cout <<"+ There are 3 numbers in the combination";
    std::cout << "\n+ The combination adds up to :"<< CodeSum;
    std::cout << "\n+ The combination multiplied equals:" << CodeProduct<< std::endl;
    
    //Stores Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //The verdict is..
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout<<"Congrats Your getting Rich! On To the next Vault! ";
        return true;
    } 
    else
    {
        std::cout<<"\nYou Entered the wrong combination try again before the alarms go off!\n";
        return false;
    }

}

int main()
{
    srand(time(NULL)); //create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while(LevelDifficulty <= MaxLevel) //loop the game until all levels are completed
    {
    
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();// Clears any errors
        std::cin.ignore();//Discards the buffer

        //increase level difficulty
        if (bLevelComplete)
        {
        ++LevelDifficulty;
        }
     
    }
    std::cout <<"\nCongrats you got all the money, Now escape before the cops show up :)!";
    return 0;
} 