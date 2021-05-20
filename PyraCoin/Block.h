#pragma once
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include "Sha256.h"
#include "BlockData.h"

using std::string;
using std::time_t;
using std::to_string;

class Block
{
private:
    const uint64_t index;
    const time_t timestamp;
    const BlockData data;
    const string previousHash;
    uint64_t nonce;
    string hash;

public:
    Block(uint64_t index, time_t timestamp, BlockData data, string previousHash);

    string GetHash() const { return hash; }
    string GetPreviousHash() const { return previousHash; }
    uint64_t GetIndex() const { return index; }

    string CalculateHash() const;
    void MineBlock(const uint32_t difficulty);
    friend std::ostream& operator<< (std::ostream& out, const Block& block);
};