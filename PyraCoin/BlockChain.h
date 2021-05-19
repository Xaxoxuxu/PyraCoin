#pragma once
#include <vector>
#include <chrono>
#include "Block.h"

class BlockChain
{
private:
	std::vector<Block> chain;

	static Block CreateGenesisBlock();
public:
	BlockChain();
	Block GetLastBlock() const;
    string GetLastBlockHash() const;
    uint64_t GetNextIndex() const;
    time_t GetCurrentTimeStamp() const;
    void CraftNewBlock(const BlockData& newBlockData);

    friend std::ostream& operator<< (std::ostream& out, const BlockChain& blockChain);
};