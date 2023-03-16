#include "Game.hpp"

Game::Game() : baseCardColor{'M', 'K', 'B', 'H'}, baseAbility{"Re-Roll", "Quadruple", "Quarter", "ReverseDirection", "SwapCard", "Switch", "AbilityLess"}
{
    this->isEndGame = false;
    this->fileConfig = false;
    vector<string> availableCommands = {"NEXT", "RE-ROLL", "DOUBLE", "QUADRUPLE", "HALF", "QUARTER", "REVERSE", "SWAPCARD", "SWITCH", "ABILITYLESS"};
    this->availableCommands = availableCommands;
}

void Game::startGame()
{
    // random seed
    srand(time(NULL));

    while (!this->isEndGame)
    {
        // Player collection + game state instantiation here
        vector<PlayerAction> players;
        // Set up player
        for (int i = 0; i < 7; i++)
        {
            PlayerAction player;
            string nickname;
            do
            {
                cout << "Enter username [" << i + 1 << "]: ";
                cin >> nickname;
                cin.ignore();
            } while (!validateUsername(players, nickname));
            player.setNickName(nickname);
            players.push_back(player);
        }
        GameState gamestate;
        bool foundWinner = false;
        // game loop
        while (!foundWinner)
        {
            // card input configuration
            string choice;
            do
            {
                cout << "Input File ? (y/n): ";
                cin >> choice;
                cin.ignore();
                if (choice == "y")
                    cout << "Enter file name (.txt): ";
                if (choice != "y" && choice != "n")
                    cout << "\nPlease check your input!\n";
            } while (choice != "y" && choice != "n");
            this->fileConfig = choice == "y";

            // Reinstantiate state & deck
            Deck gameDeck;
            if (!this->fileConfig)
            {
                // Refill & Reshuffle deck
                for (int i = 0; i < 4; i++)
                {
                    for (int j = 1; j <= 13; j++)
                    {
                        pair<int, char> card = make_pair(j, getBaseCardColor()[i]);
                        gameDeck + card;
                    }
                }
                gameDeck.shuffleCard();
            }
            else
            {
                // Get card config from txt
                string filename;
                cin >> filename;
                cin.ignore();
                vector<pair<int, char>> deckCards;
                try
                {
                    auto temp = gameDeck.cardFromFile(filename);
                    deckCards = temp.first;
                    setBaseAbility(temp.second);
                }
                catch (exception &e)
                {
                    cout << e.what() << " Exiting Program...\n"
                         << endl;
                    exit(0);
                }
                gameDeck = deckCards;
            }
            for (auto &player : players)
            {
                player.getCard(gameDeck);
            }
            // Round loop
            resetRound();
            restoreAbilityCard();
            gamestate.reset();
            while (currentRound < 7)
            {
                cout << "\n\n--------- ROUND: " << currentRound << " --------\n"
                     << endl;
                // if round 2 then distribute ability card
                if (currentRound == 2)
                {
                    for (int i = 0; i < players.size(); i++)
                    {
                        players[i].getAbilityCard(this->baseAbility);
                    }
                }
                if (currentRound >= 2)
                {
                    gamestate.addTableCard(gameDeck);
                }
                // play loop
                int maxTurn = 0;
                while (maxTurn < 7)
                {
                    cout << "Reward Point: " << gamestate.getRewardPoint();
                    cout << endl;
                    cout << "Player order: ";
                    gamestate.showPlayerOrder();
                    cout << endl;
                    cout << "Table card: \n";
                    gamestate.getTableCard().printCard();
                    players[gamestate.getCurrentTurn() - 1].playerPlay(gameDeck, gamestate, players);
                    gamestate.nextPlayerOrder();
                    maxTurn++;
                }
                if (currentRound == 6)
                {
                    vector<Combination> playersCombination;
                    for (auto player : players)
                    {
                        Combination c(gamestate.getTableCard(), player.getOwnedCard(), player.getNickName());
                        playersCombination.push_back(c);
                    }
                    Comparator<Combination> comparator;
                    pair<string, string> result = comparator.compare(playersCombination);
                    for (auto &player : players)
                    {
                        if (player.getNickName() == result.first)
                        {
                            player.setPlayerPoint(gamestate.getRewardPoint());
                        }
                    }
                    cout << endl;
                    cout << result.first << " win this game with " << result.second << endl;
                }
                nextRound();
            }
            if (endCurrentGame(players))
            {
                foundWinner = true;
            }
        }
        // Found Winner
        cout << "\nGAME SCORES: \n";
        printGameResult(players);
        try
        {
            restartGame();
        }
        catch (exception &e)
        {
            cout << e.what() << " The game will end shortly...";
            endGame();
        }
    }
}

void Game::endGame()
{
    cout << "Bye!" << endl;
    setEndGameStatus(true);
}

void Game::setEndGameStatus(bool status)
{
    this->isEndGame = status;
}

void Game::resetRound()
{
    this->currentRound = 1;
}

void Game::nextRound()
{
    this->currentRound++;
}

void Game::restoreAbilityCard()
{
    vector<string> baseAbility = {"Re-Roll", "Quadruple", "Quarter", "ReverseDirection", "SwapCard", "Switch", "AbilityLess"};
    this->baseAbility = baseAbility;
}

void Game::restartGame()
{
    string input;
    cout << "\nRestart? :\n";
    cout << "\t1. Ya\n";
    cout << "\t2. Tidak\n";
    cout << "Choice: ";
    cin >> input;
    if (input == "1" || input == "2")
    {
        if (input == "2")
        {
            endGame();
        }
    }
    else
    {
        InvalidInput e;
        throw e;
    }
}

vector<char> Game::getBaseCardColor()
{
    return this->baseCardColor;
}

vector<string> Game::getBaseAbility() const
{
    return this->baseAbility;
}

bool Game::validateUsername(vector<PlayerAction> players, string newUsername)
{
    for (auto player : players)
    {
        if (player.getNickName() == newUsername)
        {
            cout << "\nUsername already taken!\n";
            return false;
        }
    }
    return true;
}

bool Game::endCurrentGame(vector<PlayerAction> players)
{
    bool result = false;
    int i = 0;
    while (!result && i < players.size())
    {
        if (players[i].getPlayerPoint() >= pow(2, 32))
        {
            result = true;
        }
        i++;
    }
    return result;
}

void Game::printGameResult(vector<PlayerAction> players)
{
    Comparator<PlayerAction> comparator;
    comparator.sortVector(players, false);
    int index = 0;
    for (auto player : players)
    {
        cout << "\t" << index + 1 << ". " << player.getNickName() << " : " << player.getPlayerPoint() << endl;
        index++;
    }
    cout << "\nWinner: " << players[0].getNickName() << endl;
}

void Game::getCommand(string &command)
{
    int counter = 0;
    bool validCommand = false;
    do
    {
        cout << "Command: ";
        cin >> command;
        cin.ignore();
        auto it = find(this->availableCommands.begin(), this->availableCommands.end(), command);
        if (it != this->availableCommands.end())
        {
            validCommand = true;
        }
        else
        {
            validCommand = false;
        }
        if (!validCommand)
            cout << "Please check your input!" << endl;
    } while (!validCommand);
}

void Game::setBaseAbility(vector<string> baseAbility)
{
    this->baseAbility = baseAbility;
}