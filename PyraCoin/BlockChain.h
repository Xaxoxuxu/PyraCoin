#pragma once
#include <vector>
#include <chrono>
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
    uint64_t GetNextIndex() const;
    void CraftNewBlock(const BlockData& newBlockData);
    bool IsChainValid();

    friend std::ostream& operator<< (std::ostream& out, const BlockChain& blockChain);
};