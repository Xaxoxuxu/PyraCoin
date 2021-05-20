#pragma once
#include <vector>
#include <chrono>
#include "Transaction.h"
#include "Block.h"

/**
 * \brief TODO: Pass by ref when possibles
 */
class BlockChain
{
private:
	std::vector<Block> chain;
    const uint32_t difficulty;
    std::vector<Transaction> pendingTransactions;
    const double miningReward;

	static Block CreateGenesisBlock();
    time_t GetCurrentTimeStamp() const;
public:
	BlockChain(const uint32_t difficulty = 1, const double miningReward = 100.0);
	Block GetLastBlock() const;
    string GetLastBlockHash() const;
    void CreateTransaction(const Transaction transaction);
    double GetBalanceOfAddress(const string address);
    bool IsChainValid();
    void MinePendingTransactions(string miningRewardAddress);

    friend std::ostream& operator<< (std::ostream& out, const BlockChain& blockChain);
};