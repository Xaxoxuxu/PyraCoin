#pragma once
#include <vector>
#include <chrono>
#include "Transaction.h"
#include "Block.h"

class BlockChain
{
private:
	std::vector<Block> chain;
    const uint32_t difficulty;

	static Block CreateGenesisBlock();
    time_t GetCurrentTimeStamp() const;
public:
	BlockChain(const uint32_t difficulty = 1);
	Block GetLastBlock() const;
    string GetLastBlockHash() const;
    void CraftNewBlock(const Transaction& transaction);
    bool IsChainValid();

    friend std::ostream& operator<< (std::ostream& out, const BlockChain& blockChain);
};