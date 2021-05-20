#include <iostream>
#include <random>
#include "Block.h"
#include "BlockChain.h"
#include <Windows.h>

double GetRandomDouble()
{
    static std::uniform_real_distribution<double> unif(1, 99999);
    static std::default_random_engine re;
    return unif(re);
}

int main()
{
    BlockChain pyraCoin{ 3 };

    const std::string wallet1 = "one";
    const std::string wallet2 = "two";
    const std::string miner = "xaxo";

    std::cout << "xaxo initial money: " << pyraCoin.GetBalanceOfAddress(miner) << '\n';

    pyraCoin.CreateTransaction({ wallet1, wallet2, 100 });
    pyraCoin.CreateTransaction({ wallet2, wallet1, 50 });
    std::cout << "Creating 2 transactions...\n";
    std::cout << "Mining...\n";
    pyraCoin.MinePendingTransactions(miner);

    std::cout << pyraCoin;
    std::cout << "xaxo money after first mine: " << pyraCoin.GetBalanceOfAddress(miner) << '\n';

    std::cout << "Mining...\n";
    pyraCoin.MinePendingTransactions(miner);
    std::cout << "xaxo money after second mine: " << pyraCoin.GetBalanceOfAddress(miner) << '\n';

    std::cout << "Is BlockChain valid: " << (pyraCoin.IsChainValid() ? "Yes" : "No") << '\n';

    return 0;
}